#include "SembaContext.h"

#include <stddef.h>

static struct SembaExContext *gCtx = NULL;

void SembaContextSet(struct SembaExContext *ctx) {
    gCtx = ctx;
}

struct SembaExContext *SembaContextGet(void) {
    return gCtx;
}