#ifndef HOOK_TN_H_7_SEP_2025_10_45
#define HOOK_TN_H_7_SEP_2025_10_45

#include <stdbool.h>

void HookTN(void *GameAssembly);
bool areGamePtrsReady(void);
float *getPosArray(void);
float *getRotationArray(void);
bool *getCustomFovFlag(void);
bool *getPausePositionPtr(void);
float *getFovScale(void);

#endif