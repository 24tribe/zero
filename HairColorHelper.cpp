#include "HairColorHelper.h"

#include "CharHairColor.h"

#include <iostream>
#include <regex>
#include <cstdlib>

struct HairColorHelper {
    CharHairColorMap hairColorMap;
};

CharHairColor::CharHairColor(
    float *col, std::string charName, int charId, bool enable, void *material
) : hairColor{col[0], col[1], col[2]}, charName(charName), charId(charId), enable(enable), material(material) {

    this->hairColor[0] = hairColor[0];
    this->hairColor[1] = hairColor[1];
    this->hairColor[2] = hairColor[2];
}

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

extern "C" void HairColorHelper_AddChar(
    HairColorHelper *hairColorHelper,
    float hairColor[3], const char *charName, int charId, bool enable
) {
    CharHairColor charHairColor(hairColor, std::string(charName), charId, enable, nullptr);

    hairColorHelper->hairColorMap.insert({charId, charHairColor});
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