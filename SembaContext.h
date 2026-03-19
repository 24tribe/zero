#ifndef SEMBA_CONTEXT_H_2026_03_16_11_54
#define SEMBA_CONTEXT_H_2026_03_16_11_54

#ifdef __cplusplus
extern "C" {
#endif

#include "semba.h"
#include "SembaRemote.h"
#include "semba_enum.h"

void SembaContextSet(struct SembaExContext *ctx);
struct SembaExContext *SembaContextGet(void);

void SembaRemoteSet(struct SembaRemote *ctx);
struct SembaRemote *SembaRemoteGet(void);

char *GlobalSembaCall(const char *path, const char *req, enum SembaStatus *status);
void GlobalSembaFreeResponse(char *response);

#endif

#ifdef __cplusplus
}
#endif