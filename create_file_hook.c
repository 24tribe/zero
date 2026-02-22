#include "utils.h"
#include "sds_utf_conv.h"
#include "defer.h"
#include "bundlemod/BundleMod.h"
#include "ModHelper.h"

#include <MinHook.h>
#include <jansson.h>

#include <windows.h>
#include <fileapi.h>

#include <stdio.h>
#include <wchar.h>

typedef HANDLE (WINAPI *CREATEFILEW)(LPCWSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);

CREATEFILEW fpCreateFileW = NULL;

static struct ModManager *gModManager = NULL;

void SetGlobalModManager(struct ModManager *modMgr) {
    gModManager = modMgr;
}

HANDLE createReadHandle(CREATEFILEW createFileW, const wchar_t *path) {
    return createFileW(
        path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
    );
}

HANDLE createWriteHandle(CREATEFILEW createFileW, const wchar_t *path) {
    return createFileW(
        path, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL
    );
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
    char *textureChanges = (gModManager ? ModHelper_GetTextureChanges(gModManager, filename) : NULL);
    defer { free(textureChanges); }

    if (textureChanges) {
        HANDLE inBundle = createReadHandle(fpCreateFileW, filenameW);

        wchar_t *tempPath = ModHelper_GetPathForNewBundle(filename);
        defer { free(tempPath); }

        HANDLE outBundle = createWriteHandle(fpCreateFileW, tempPath);

        BundleMod_ChangeTextures(inBundle, outBundle, textureChanges);

        return fpCreateFileW(tempPath, access, shareMode, attrs, creationDisp, flags, template);
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