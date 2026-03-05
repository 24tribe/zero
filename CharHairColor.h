#ifndef CHAR_HAIR_COLOR_H_03_03_2026
#define CHAR_HAIR_COLOR_H_03_03_2026

#include <map>
#include <string>
#include <array>

struct CharHairColor {
    std::array<float, 3> hairColor;
    std::string charName;
    int charId;
    bool enable;
    void *material;

    std::array<float, 3> originalColor;
    void *texture;

    CharHairColor(int charId, std::string charName);
};

using CharHairColorMap = std::map<int, CharHairColor>;

struct HairColorHelper {
    CharHairColorMap hairColorMap;
    HairColorHelper();
};

#endif