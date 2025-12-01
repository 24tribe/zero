#include "version.h"

#include <string.h>
#include <stdio.h>

static enum GameVersion version = VERSION_NONE;

enum GameVersion GetGameVersion(void) {
    if (version == VERSION_NONE) {
        printf("WARNING: couldn't determine version");
    }
    return version;
}

void InitGameVersion(char *hex) {
    if (!strcmp(hex, STABLE_MD5SUM)) {
        version = VERSION_STABLE;
    } else if (!strcmp(hex, DEMO_MD5SUM)) {
        version = VERSION_DEMO;
    } else {
        version = VERSION_NONE;
    }
}