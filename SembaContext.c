#include "SembaContext.h"

#include <stddef.h>

static struct SembaExContext *gCtx = NULL;
static struct SembaRemote *gRemote = NULL;

void SembaContextSet(struct SembaExContext *ctx) {
    gCtx = ctx;
}

struct SembaExContext *SembaContextGet(void) {
    return gCtx;
}

void SembaRemoteSet(struct SembaRemote *ctx) {
    gRemote = ctx;
}

struct SembaRemote *SembaRemoteGet(void) {
    return gRemote;
}

char *GlobalSembaCall(const char *path, const char *req, enum SembaStatus *status) {
    if (gCtx) {
        int32_t st;
        char *res = SembaExCall(gCtx, path, req, &st);
        *status = (enum SembaStatus)st;
        return res;
    } else if (gRemote) {
        return SembaRemote_Call(gRemote, path, req, status);
    } else {
        if (status) { *status = SEMBA_STATUS_INVALID_CONTEXT; }
        return NULL;
    }
}

void GlobalSembaFreeResponse(char *response) {
    if (gCtx) {
        SembaExFreeResponse(response);
    } else if (gRemote) {
        SembaRemote_FreeResponse(response);
    } else {
        /* do nothing? */
    }
}