#ifndef HAIR_COLOR_HELPER_H_03_03_2026
#define HAIR_COLOR_HELPER_H_03_03_2026

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

struct HairColorHelper;

bool HairColorHelper_IsHairColorEnabled(struct HairColorHelper *hairColorHelper, int charId);
void HairColorHelper_GetHairColor(struct HairColorHelper *hairColorHelper, int charId, float color[3]);
void *HairColorHelper_GetMaterial(struct HairColorHelper *hairColorHelper, int charId);
void HairColorHelper_SetMaterial(struct HairColorHelper *hairColorHelper, int charId, void *material, void *texture);
int HairColorHelper_GetCharIdFromMaterialName(const char *materialName);

#ifdef __cplusplus
}
#endif

#endif