#include "HighlightCharacters.hpp"

#include <algorithm>
#include <sstream>

static bool hasPosition(size_t pos, const std::vector<size_t>& positions) {
  return std::find(positions.begin(), positions.end(), pos) != positions.end();
}

std::string HighlightCharacters(
  std::string_view text, const std::vector<size_t> positions, std::string_view color
) {
  const char *stop = "^[#]";
  bool hasColor = false;
  std::stringstream ss;

  for (size_t i = 0; i < text.length();) {
    if (hasPosition(i, positions) && !hasColor) {
      hasColor = true;
      ss << "^[" << color << "]";
    }

    if (!hasPosition(i, positions) && hasColor) {
      hasColor = false;
      ss << stop;
    }    

    size_t charSize;
    if (!(text[i] & 0x80)) {
      charSize = 1;
    } else if ((text[i] & 0xE0) == 0xC0) {
      charSize = 2;
    } else if ((text[i] & 0xF0) == 0xE0) {
      charSize = 3;
    } else {
      charSize = 4;
    }

    ss << text.substr(i, charSize);

    i += charSize;
  }

  return ss.str();
}
