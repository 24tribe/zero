#include "utils.h"
#include "sds_utf_conv.h"
#include "defer.h"
#include "bundlemod/BundleMod.h"

#include <MinHook.h>
#include <jansson.h>

#include <windows.h>
#include <fileapi.h>

#include <stdio.h>
#include <wchar.h>

typedef HANDLE (WINAPI *CREATEFILEW)(LPCWSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);

struct TextureChange {
    char *name;
    float *hsv;
};

CREATEFILEW fpCreateFileW = NULL;

float *hairColorPtr = NULL;
bool *enableHairColorPtr = NULL;

void CreateFileHook_SetHairColorPtr(float *color) {
    hairColorPtr = color;
}

void CreateFileHook_SetEnableHairColorPtr(bool *enableHairColor) {
    enableHairColorPtr = enableHairColor;
}

HANDLE createReadHandle(CREATEFILEW createFileW, const wchar_t *path) {
    return createFileW(
        path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
    );
}

char *EncodeTextureChanges(const struct TextureChange textureChanges[], size_t len) {
    json_t *res = json_object();
    defer { json_decref(res); }

    for (size_t i = 0; i < len; ++i) {
        json_t *tcJson = json_object();
        json_object_set_new(tcJson, "H", json_real(textureChanges[i].hsv[0]));
        json_object_set_new(tcJson, "S", json_real(textureChanges[i].hsv[1]));
        json_object_set_new(tcJson, "V", json_real(textureChanges[i].hsv[2]));

        json_object_set_new(res, textureChanges[i].name, tcJson);
    }

    return json_dumps(res, 0);
}

HANDLE WINAPI DetourCreateFileW(
    LPCWSTR filenameW,  DWORD access, DWORD shareMode,
    LPSECURITY_ATTRIBUTES attrs, DWORD creationDisp, DWORD flags, HANDLE template) {

    sds filename = sds16to8(filenameW, wcslen(filenameW));

    defer { sdsfree(filename); }

#ifdef TRIBE_NINE_DEMO
    // FIXME: change abcache.json contents to {"IgnoreCatalogCache":false,"IgnoreRemoteCatalog":true}
    if (strstr(filename, "abcache.json")) {
        printf("CreateFileW: %s\n", filename);
    }
#else
    bool enable = enableHairColorPtr && *enableHairColorPtr;
    char *bundleName = "8953a3774b75802d47fb9c364093f655.bundle";
    wchar_t *bundleNameW = L"8953a3774b75802d47fb9c364093f655.bundle";
    size_t bundleLen = 39;

    if (enable && strstr(filename, bundleName)) {
        char *textureChanges = EncodeTextureChanges(&(const struct TextureChange){
            .name = "tex_chr030_001_hair01_c",
            .hsv = hairColorPtr
        }, 1);
        defer { free(textureChanges); }

        HANDLE inBundle = createReadHandle(fpCreateFileW, filenameW);

#define TEMP_PATH_SIZE 261

        wchar_t tempPath[TEMP_PATH_SIZE] = {0};

        DWORD size = GetTempPathW(TEMP_PATH_SIZE, tempPath);

        if (size != 0 && size + bundleLen < TEMP_PATH_SIZE) {
            memcpy(tempPath + size, bundleNameW, bundleLen*2);
            HANDLE outBundle = fpCreateFileW(
                tempPath, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL
            );

            BundleMod_ChangeTextures(inBundle, outBundle, textureChanges);
            return fpCreateFileW(tempPath, access, shareMode, attrs, creationDisp, flags, template);
        }
    }
#endif

    return fpCreateFileW(filenameW, access, shareMode, attrs, creationDisp, flags, template);
}

void HookCreateFile() {
    if (MH_CreateHook((void *)(uintptr_t)&CreateFileW, (void *)(uintptr_t)&DetourCreateFileW,
        (LPVOID *)(&fpCreateFileW)) != MH_OK) {
        fputs("Failed to create CreateFileW hook\n", stdout);
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)&CreateFileW, TRUE) != MH_OK) {
        fputs("failed to enable CreateFileW hook", stdout);
        return;
    }
}