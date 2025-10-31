#include "Config.h"

#include "utils.h"
#include "sds_utf_conv.h"

#include <ini.h>
#include <sds.h>

#include <shlwapi.h>

#include <string.h>

#define CONFIG_LOCATION "config.ini"

struct Config ZERO_CONFIG = {
    .offlineMode = false,
    .saveFile = NULL,
    .onlineLogsPath = NULL,
    .goldbergPath = NULL,
    .sembaDbPath = NULL,
    .remoteUrl = NULL,
};

static void setGoldbergPath(const char *value) {
    sds goldbergPath = sdsnew(value);
    uint16_t *s = sds_utf8_to_utf16(goldbergPath);
    sdsfree(goldbergPath);

    uint16_t *res = s;
    if (PathIsRelativeW(s)) {
        res = _wfullpath(NULL, s, 0);
        if (!res) {
            printf("setGoldbergPath: _wfullpath failed!\n");
        }
        free(s);
    }

    ZERO_CONFIG.goldbergPath = res;
}

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
        setGoldbergPath(value);
    } else if (!strcmp(name, "sembaDbPath")) {
        ZERO_CONFIG.sembaDbPath = sdsnew(value);
    } else if (!strcmp(name, "remoteUrl")) {
        ZERO_CONFIG.remoteUrl = sdsnew(value);
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
    printf("sembaDbPath=%s\n", string_null_escape(ZERO_CONFIG.sembaDbPath));
    printf("remoteUrl=%s\n", string_null_escape(ZERO_CONFIG.remoteUrl));

    sds goldbergPath;
    if (ZERO_CONFIG.goldbergPath) {
        goldbergPath = sds16to8(ZERO_CONFIG.goldbergPath, wcslen(ZERO_CONFIG.goldbergPath));
    } else {
        goldbergPath = sdsnew("(null)");
    }

    printf("goldbergPath=%s\n", goldbergPath);
    sdsfree(goldbergPath);

    if (!ZERO_CONFIG.onlineLogsPath) {
        printf("WARNING: onlineLogsPath not set, api call flows won't be saved!\n");
    }

    if (!ZERO_CONFIG.goldbergPath) {
        printf("WARNING: goldbergPath not set, steam emulation won't work!\n");
    }

    if (!ZERO_CONFIG.sembaDbPath) {
        printf("WARNING: sembaDbPath not set, offline mode won't work at all!\n");
    }
}

void InitConfig(void) {
    if (ini_parse(CONFIG_LOCATION, handler, NULL) < 0) {
        printf("Can't load '" CONFIG_LOCATION "'\n");
        return;
    }

    PrintZeroConfig();
}