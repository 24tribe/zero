#include "Config.h"

#include <ini.h>

#include <string.h>

#define CONFIG_LOCATION "config.ini"

struct Config ZERO_CONFIG = {
    .offlineMode = false,
};

static int handler(void *user, const char *section, const char *name, const char *value) {
    (void)user;
    (void)section;
    
    if (!strcmp(name, "offlineMode")) {
        if (strstr(value, "true")) {
            ZERO_CONFIG.offlineMode = true;
        } else if (strstr(value, "false")) {
            ZERO_CONFIG.offlineMode = false;
        } else {
            return 0; /* unknown section/name, error */
        }
    } else {
        return 0; /* unknown section/name, error */
    }

    return 1;
}

void InitConfig(void) {
    if (ini_parse(CONFIG_LOCATION, handler, NULL) < 0) {
        printf("Can't load '" CONFIG_LOCATION "'\n");
    }

    printf("offlineMode=%s\n", ZERO_CONFIG.offlineMode ? "true" : "false");
}