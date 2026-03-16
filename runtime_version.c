#include "runtime_version.h"

#include <string.h>

enum SembaGameVersion RuntimeVersionGet(const char *hex) {
    if (!strcmp(hex, MD5SUM_1_1_3_35)) {
        return GAME_VERSION_1_1_3_35;
    } else if (!strcmp(hex, MD5SUM_0_2_1_20)) {
        return GAME_VERSION_0_2_1_20;
    } else {
        return GAME_VERSION_UNKNOWN;
    }
}