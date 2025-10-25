#include "Config.h"

#include <ini.h>
#include <sds.h>

#include <string.h>

#define CONFIG_LOCATION "config.ini"

struct Config ZERO_CONFIG = {
    .offlineMode = false,
    .saveFile = NULL,
    .onlineLogsPath = NULL,
    .goldbergPath = NULL
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
    } else if (!strcmp(name, "saveFile")) {
        ZERO_CONFIG.saveFile = sdsnew(value);
    } else if (!strcmp(name, "onlineLogsPath")) {
        ZERO_CONFIG.onlineLogsPath = sdsnew(value);  
    } else if (!strcmp(name, "goldbergPath")) {
        ZERO_CONFIG.goldbergPath = sdsnew(value);
    } else {
        return 0; /* unknown section/name, error */
    }

    return 1;
}

static char *string_null_escape(char *s) {
    return s ? s : "(null)";
}

void PrintZeroConfig(void) {
    printf("offlineMode=%s\n", ZERO_CONFIG.offlineMode ? "true" : "false");
    printf("saveFile=%s\n", string_null_escape(ZERO_CONFIG.saveFile));
    printf("onlineLogsPath=%s\n", string_null_escape(ZERO_CONFIG.onlineLogsPath));
    printf("goldbergPath=%s\n", string_null_escape(ZERO_CONFIG.goldbergPath));

    if (!ZERO_CONFIG.onlineLogsPath) {
        printf("WARNING: onlineLogsPath not set, api call flows won't be saved!\n");
    }

    if (!ZERO_CONFIG.goldbergPath) {
        printf("WARNING: goldbergPath not set, steam emulation won't work!\n");
    }
}

void InitConfig(void) {
    if (ini_parse(CONFIG_LOCATION, handler, NULL) < 0) {
        printf("Can't load '" CONFIG_LOCATION "'\n");
    }

    PrintZeroConfig();
}