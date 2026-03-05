#ifndef HOOK_TN_H_7_SEP_2025_10_45
#define HOOK_TN_H_7_SEP_2025_10_45

#include "HairColorHelper.h"

#include <stdbool.h>

typedef struct UnityEngine_Material_o UnityEngine_Material_o;
typedef struct UnityEngine_Texture_o UnityEngine_Texture_o;

void HookTN(void *GameAssembly);
bool areGamePtrsReady(void);
float *getPosArray(void);
float *getRotationArray(void);
bool *getCustomFovFlag(void);
bool *getPausePositionPtr(void);
float *getFovScale(void);
void SetMaterialAlbedoColor(UnityEngine_Material_o *material, float color[3]);
void SetMaterialAlbedoTexture(UnityEngine_Material_o *material, UnityEngine_Texture_o *tex);
UnityEngine_Texture_o *GetMaterialAlbedoTexture(UnityEngine_Material_o *material);
void HookTN_SetHairColorHelper(struct HairColorHelper *helper);

#endif