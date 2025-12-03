#include "utils.h"
#include "sds_utf_conv.h"

#include <MinHook.h>

#include <windows.h>
#include <fileapi.h>

#include <stdio.h>
#include <wchar.h>

typedef HANDLE (WINAPI *CREATEFILEW)(LPCWSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);

CREATEFILEW fpCreateFileW = NULL;

HANDLE WINAPI DetourCreateFileW(
    LPCWSTR filenameW,  DWORD access, DWORD shareMode,
    LPSECURITY_ATTRIBUTES attrs, DWORD creationDisp, DWORD flags, HANDLE template) {

    sds filename = sds16to8(filenameW, wcslen(filenameW));

    // FIXME: change abcache.json contents to {"IgnoreCatalogCache":false,"IgnoreRemoteCatalog":true}
    if (strstr(filename, "abcache.json")) {
        printf("CreateFileW: %s\n", filename);
    }

    sdsfree(filename);

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