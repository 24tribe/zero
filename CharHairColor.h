#ifndef CHAR_HAIR_COLOR_H_03_03_2026
#define CHAR_HAIR_COLOR_H_03_03_2026

#include <unordered_map>
#include <string>
#include <array>

struct CharHairColor {
    std::array<float, 3> hairColor;
    std::string charName;
    int charId;
    bool enable;
    void *material;

    CharHairColor(float *hairColor, std::string charName, int charId, bool enable, void *material);
};

using CharHairColorMap = std::unordered_map<int, CharHairColor>;

#endif