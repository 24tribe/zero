#ifndef HAIR_COLOR_HELPER_H_03_03_2026
#define HAIR_COLOR_HELPER_H_03_03_2026

#ifdef __cplusplus
extern "C" {
#endif

struct HairColorHelper;

bool HairColorHelper_IsHairColorEnabled(struct HairColorHelper *hairColorHelper, int charId);
void HairColorHelper_GetHairColor(struct HairColorHelper *hairColorHelper, int charId, float color[3]);
void HairColorHelper_AddChar(
    struct HairColorHelper *hairColorHelper,
    float hairColor[3], const char *charName, int charId, bool enable
);
void *HairColorHelper_GetMaterial(HairColorHelper *hairColorHelper, int charId);
int HairColorHelper_GetCharIdFromMaterialName(const char *materialName);


#ifdef __cplusplus
}
#endif

#endif