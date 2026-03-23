#include "SembaContext.h"

#include <windows.h>

#include <stddef.h>
#include <stdio.h>

static struct SembaExContext *gCtx = NULL;
static struct SembaRemote *gRemote = NULL;
static HANDLE gMutex;

void SembaContextSet(struct SembaExContext *ctx) {
    gMutex = CreateMutex(NULL, FALSE, NULL);
    if (!gMutex) {
        printf("WARNING: failed to create SembaContext mutex!\n");
    }
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
        WaitForSingleObject(gMutex, INFINITE);
        char *res = SembaExCall(gCtx, path, req, &st);
        ReleaseMutex(gMutex);
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