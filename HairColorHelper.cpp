#include "HairColorHelper.h"

#include "CharHairColor.h"

#include <iostream>
#include <regex>
#include <cstdlib>

CharHairColor::CharHairColor(int charId, std::string charName)
 : hairColor(), charName(charName), charId(charId),
   enable(false), material(nullptr), texture(nullptr) {}

HairColorHelper::HairColorHelper() : hairColorMap{
    {1, CharHairColor(1, "Yo Kuronaka")},
    {2, CharHairColor(2, "Tsuki Iroha")},
    {3, CharHairColor(3, "Jio Takinogawa")},
    {4, CharHairColor(4, "Miu Jujo")},
    {5, CharHairColor(5, "Koishi Kohinata")},
    {6, CharHairColor(6, "Minami Oi")},
    {7, CharHairColor(7, "Hyakuichitaro Senju")},
    {8, CharHairColor(8, "Tsuruko Semba")},
    {9, CharHairColor(9, "Eiji Todoroki")},
    {10, CharHairColor(10, "Roku Saigo")},
    {11, CharHairColor(11, "Enoki Yukigaya")},
    {12, CharHairColor(12, "Yutaka Gotanda")},
    {13, CharHairColor(13, "Q")},
    {14, CharHairColor(14, "Kazuki Aoyama")},
    {15, CharHairColor(15, "Santaro Mita")},
    {29, CharHairColor(29, "Ichinosuke Akiba")},
    {30, CharHairColor(30, "Hinagiku Akiba")},
    {31, CharHairColor(31, "Saizo Akiba")},
} {}

extern "C" bool HairColorHelper_IsHairColorEnabled(HairColorHelper *hairColorHelper, int charId) {
    auto& hairColorMap = hairColorHelper->hairColorMap;
    if (auto search = hairColorMap.find(charId); search != hairColorMap.end()) {
        return search->second.enable;
    } else {
        std::cout << "Warning: charId=" << charId << " not found is hairColorMap\n";
        return false;
    }
}

extern "C" void HairColorHelper_GetHairColor(HairColorHelper *hairColorHelper, int charId, float color[3]) {
    auto& hairColorMap = hairColorHelper->hairColorMap;
    if (auto search = hairColorMap.find(charId); search != hairColorMap.end()) {
        auto& hairColor = search->second.hairColor;
        color[0] = hairColor[0];
        color[1] = hairColor[1];
        color[2] = hairColor[2];
    } else {
        std::cout << "Warning: charId=" << charId << " not found is hairColorMap\n";
        return;
    }
}

extern "C" void *HairColorHelper_GetMaterial(HairColorHelper *hairColorHelper, int charId) {
    auto& hairColorMap = hairColorHelper->hairColorMap;
    if (auto search = hairColorMap.find(charId); search != hairColorMap.end()) {
        return search->second.material;
    } else {
        std::cout << "Warning: charId=" << charId << " not found is hairColorMap\n";
        return NULL;
    }
}

extern "C" int HairColorHelper_GetCharIdFromMaterialName(const char *materialName) {
    std::string matName = materialName;
    std::smatch m;
    std::regex e("mat_chr(\\d+)_\\d+_hair01");

    if (std::regex_search(matName, m, e)) {
        auto charId = m[1].str();
        return atoi(charId.c_str());
    }

    return -1;
}

extern "C" void HairColorHelper_SetMaterial(
    HairColorHelper *hairColorHelper, int charId, void *material, void *texture
) {
    auto& hairColorMap = hairColorHelper->hairColorMap;
    if (auto search = hairColorMap.find(charId); search != hairColorMap.end()) {
        search->second.material = material;
        search->second.texture = texture;
    } else {
        std::cout << "Warning: charId=" << charId << " not found is hairColorMap\n";
    }
}