#ifndef SEMBA_CONTEXT_H_2026_03_16_11_54
#define SEMBA_CONTEXT_H_2026_03_16_11_54

#ifdef __cplusplus
extern "C" {
#endif

#include "semba.h"

void SembaContextSet(struct SembaExContext *ctx);
struct SembaExContext *SembaContextGet(void);

#endif

#ifdef __cplusplus
}
#endif