// The MIT License (MIT)
//
// Copyright (c) 2019-2024 funap
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "FuzzyMatcher.h"

#include <cwctype>
#include <memory>
#include <algorithm>
#include <cstdint>

namespace {
    struct ScoringConstants {
        static constexpr int CHARACTER_MATCH_BONUS      = 1;
        static constexpr int SAME_CASE_BONUS            = 1;
        static constexpr int FIRST_LETTER_BONUS         = 8;
        static constexpr int CONSECUTIVE_MATCH_BONUS    = 5;
        static constexpr int START_OF_EXTENSION_BONUS   = 3;
        static constexpr int CAMEL_CASE_BONUS           = 4;
        static constexpr int SEPARATOR_BONUS            = 4;
        static constexpr int DIRECTORY_SEPARATOR_BONUS  = 5;
    };

    bool Utf8ToUtf32(std::string_view utf8, std::u32string& utf32, std::vector<size_t>& byteOffsets)
    {
        utf32.clear();
        byteOffsets.clear();
        utf32.reserve(utf8.size());
        byteOffsets.reserve(utf8.size());

        for (size_t i = 0; i < utf8.size(); ) {
            unsigned char c = utf8[i];
            size_t charStart = i;
            char32_t codePoint = 0;
            size_t extraBytes = 0;

            if (c < 0x80) {
                codePoint = c;
                extraBytes = 0;
            } else if ((c & 0xE0) == 0xC0) {
                codePoint = c & 0x1F;
                extraBytes = 1;
            } else if ((c & 0xF0) == 0xE0) {
                codePoint = c & 0x0F;
                extraBytes = 2;
            } else if ((c & 0xF8) == 0xF0) {
                codePoint = c & 0x07;
                extraBytes = 3;
            } else {
                return false;
            }

            if (i + extraBytes >= utf8.size()) {
                return false;
            }

            for (size_t j = 0; j < extraBytes; ++j) {
                unsigned char nextC = utf8[i + 1 + j];
                if ((nextC & 0xC0) != 0x80) {
                    return false;
                }
                codePoint = (codePoint << 6) | (nextC & 0x3F);
            }

            utf32.push_back(codePoint);
            byteOffsets.push_back(charStart);
            i += 1 + extraBytes;
        }
        return true;
    }

    bool WstringToUtf32(std::wstring_view wstr, std::u32string& utf32, std::vector<size_t>& wstrOffsets)
    {
        utf32.clear();
        wstrOffsets.clear();
        utf32.reserve(wstr.size());
        wstrOffsets.reserve(wstr.size());

        for (size_t i = 0; i < wstr.size(); ) {
            wchar_t c = wstr[i];
            size_t charStart = i;
            char32_t codePoint = 0;

            if constexpr (sizeof(wchar_t) == 4) {
                codePoint = static_cast<char32_t>(c);
                utf32.push_back(codePoint);
                wstrOffsets.push_back(charStart);
                i += 1;
            } else {
                uint16_t u = static_cast<uint16_t>(c);
                if (u >= 0xD800 && u <= 0xDBFF) {
                    if (i + 1 < wstr.size()) {
                        uint16_t nextU = static_cast<uint16_t>(wstr[i + 1]);
                        if (nextU >= 0xDC00 && nextU <= 0xDFFF) {
                            codePoint = 0x10000 + ((u - 0xD800) << 10) + (nextU - 0xDC00);
                            utf32.push_back(codePoint);
                            wstrOffsets.push_back(charStart);
                            i += 2;
                            continue;
                        }
                    }
                    return false;
                } else if (u >= 0xDC00 && u <= 0xDFFF) {
                    return false;
                } else {
                    codePoint = u;
                    utf32.push_back(codePoint);
                    wstrOffsets.push_back(charStart);
                    i += 1;
                }
            }
        }
        return true;
    }

    inline char32_t ToLower(char32_t c) {
        if constexpr (sizeof(wchar_t) == 4) {
            return std::towlower(static_cast<wchar_t>(c));
        } else {
            if (c <= 0xFFFF) {
                return std::towlower(static_cast<wchar_t>(c));
            }
            return c;
        }
    }

    inline bool IsLower(char32_t c) {
        if constexpr (sizeof(wchar_t) == 4) {
            return std::iswlower(static_cast<wchar_t>(c)) != 0;
        } else {
            if (c <= 0xFFFF) {
                return std::iswlower(static_cast<wchar_t>(c)) != 0;
            }
            return false;
        }
    }

    inline bool IsUpper(char32_t c) {
        if constexpr (sizeof(wchar_t) == 4) {
            return std::iswupper(static_cast<wchar_t>(c)) != 0;
        } else {
            if (c <= 0xFFFF) {
                return std::iswupper(static_cast<wchar_t>(c)) != 0;
            }
            return false;
        }
    }

    bool ValidateInputs(const std::u32string_view& pattern, const std::u32string_view& target)
    {
        return !(pattern.empty() || target.empty() || pattern.length() > target.length());
    }

    void RestoreMatchPositions(std::vector<size_t>* positions,
                             const int* matchMatrix,
                             size_t patternLength,
                             size_t targetLength)
    {
        if (!positions) return;

        size_t patternIndex = patternLength - 1;
        size_t targetIndex  = targetLength  - 1;

        while ((0 <= patternIndex) && (0 <= targetIndex)) {
            const size_t currentIndex = patternIndex * targetLength + targetIndex;
            const int match = matchMatrix[currentIndex];

            if (0 == match) {
                if (0 < targetIndex) {
                    --targetIndex;
                }
                else {
                    break;
                }
            }
            else {
                positions->emplace_back(targetIndex);
                if ((0 < patternIndex) && (0 < targetIndex)) {
                    --patternIndex;
                    --targetIndex;
                }
                else {
                    break;
                }
            }
        }
        std::reverse(positions->begin(), positions->end());
    }
} // namespace

FuzzyMatcher::FuzzyMatcher(std::u32string_view pattern)
    : pattern_(pattern)
    , scoreMatrix_()
    , matchMatrix_()
{
}

FuzzyMatcher::FuzzyMatcher(std::string_view pattern)
    : scoreMatrix_()
    , matchMatrix_()
{
    std::vector<size_t> offsets;
    Utf8ToUtf32(pattern, pattern_, offsets);
}

FuzzyMatcher::FuzzyMatcher(std::wstring_view pattern)
    : scoreMatrix_()
    , matchMatrix_()
{
    std::vector<size_t> offsets;
    WstringToUtf32(pattern, pattern_, offsets);
}

FuzzyMatcher::~FuzzyMatcher() = default;

int FuzzyMatcher::ScoreMatch(std::u32string_view target, std::vector<size_t>* positions)
{
    return ScoreMatchInternal(target, positions);
}

int FuzzyMatcher::ScoreMatch(std::string_view target, std::vector<size_t>* positions)
{
    std::u32string targetU32;
    std::vector<size_t> byteOffsets;
    if (!Utf8ToUtf32(target, targetU32, byteOffsets)) {
        return 0;
    }

    std::vector<size_t> u32Positions;
    int score = ScoreMatchInternal(targetU32, positions ? &u32Positions : nullptr);

    if (positions && score > 0) {
        positions->clear();
        positions->reserve(u32Positions.size());
        for (size_t pos : u32Positions) {
            positions->push_back(byteOffsets[pos]);
        }
    }
    return score;
}

int FuzzyMatcher::ScoreMatch(std::wstring_view target, std::vector<size_t>* positions)
{
    std::u32string targetU32;
    std::vector<size_t> wstrOffsets;
    if (!WstringToUtf32(target, targetU32, wstrOffsets)) {
        return 0;
    }

    std::vector<size_t> u32Positions;
    int score = ScoreMatchInternal(targetU32, positions ? &u32Positions : nullptr);

    if (positions && score > 0) {
        positions->clear();
        positions->reserve(u32Positions.size());
        for (size_t pos : u32Positions) {
            positions->push_back(wstrOffsets[pos]);
        }
    }
    return score;
}

int FuzzyMatcher::ScoreMatchInternal(std::u32string_view target, std::vector<size_t>* positions)
{
    if (!ValidateInputs(pattern_, target)) {
        return 0;
    }

    scoreMatrix_.resize(pattern_.length() * target.length());
    matchMatrix_.resize(pattern_.length() * target.length());
    for (size_t patternIndex = 0; patternIndex < pattern_.length(); ++patternIndex) {
        const bool patternIsFirstIndex          = (0 == patternIndex);
        const size_t patternIndexOffset         = patternIndex * target.length();
        const size_t patternIndexPreviousOffset = patternIndexOffset - target.length();

        for (size_t targetIndex = 0; targetIndex < target.length(); ++targetIndex) {
            const bool targetIsFirstIndex   = (0 == targetIndex);
            const size_t currentIndex       = patternIndexOffset + targetIndex;
            const size_t leftIndex          = currentIndex - 1;
            const size_t diagIndex          = patternIndexPreviousOffset + (targetIndex - 1);

            const int leftScore = targetIsFirstIndex ? 0 : scoreMatrix_[leftIndex];
            const int diagScore = (patternIsFirstIndex || targetIsFirstIndex) ? 0 : scoreMatrix_[diagIndex];
            const int matchesSequenceLength = (patternIsFirstIndex || targetIsFirstIndex) ? 0 : matchMatrix_[diagIndex];

            const int score = (!diagScore && !patternIsFirstIndex)
                            ? 0
                            : CalculateScore(pattern_[patternIndex], target, targetIndex, matchesSequenceLength);

            if (score && (leftScore <= diagScore + score)) {
                matchMatrix_[currentIndex] = matchesSequenceLength + 1;
                scoreMatrix_[currentIndex] = diagScore + score;
            }
            else {
                matchMatrix_[currentIndex] = 0;
                scoreMatrix_[currentIndex] = leftScore;
            }
        }
    }

    const int result = scoreMatrix_[pattern_.length() * target.length() - 1];
    RestoreMatchPositions(positions, matchMatrix_.data(), pattern_.length(), target.length());
    return result;
}

int FuzzyMatcher::CalculateScore(char32_t patternChar, const std::u32string_view& target, size_t targetIndex, int matchesSequenceLength)
{
    int score = 0;

    const char32_t patternLowerChar = ToLower(patternChar);
    const char32_t targetLowerChar = ToLower(target[targetIndex]);

    if (patternLowerChar != targetLowerChar) {
        return score;
    }

    score += ScoringConstants::CHARACTER_MATCH_BONUS;

    if (0 < matchesSequenceLength) {
        score += (matchesSequenceLength * ScoringConstants::CONSECUTIVE_MATCH_BONUS);
    }

    if (patternChar == target[targetIndex]) {
        score += ScoringConstants::SAME_CASE_BONUS;
    }

    if (0 == targetIndex) {
        score += ScoringConstants::FIRST_LETTER_BONUS;
    }
    else {
        switch (target[targetIndex - 1]) {
        case '\\':
            score += ScoringConstants::DIRECTORY_SEPARATOR_BONUS;
            break;
        case ' ':
        case '_':
            score += ScoringConstants::SEPARATOR_BONUS;
            break;
        case '.':
            score += ScoringConstants::START_OF_EXTENSION_BONUS;
            break;
        default:
            if (IsLower(target[targetIndex - 1]) && IsUpper(target[targetIndex])) {
                score += ScoringConstants::CAMEL_CASE_BONUS;
            }
            break;
        }
    }

    return score;
}
