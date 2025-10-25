#include "utils.h"

#include <MinHook.h>

#include <windows.h>
#include <fileapi.h>

#include <stdio.h>

typedef HANDLE (WINAPI *CREATEFILEW)(LPCWSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);

CREATEFILEW fpCreateFileW = NULL;

HANDLE WINAPI DetourCreateFileW(
    LPCWSTR filenameW,  DWORD access, DWORD shareMode,
    LPSECURITY_ATTRIBUTES attrs, DWORD creationDisp, DWORD flags, HANDLE template) {

    char filename[MY_LINE_SIZE];
    WideToUtf8(filename, filenameW);

    // printf("CreateFileW: %s\n", filename);

    /*
    if (strstr(filename, "global-metadata.dat")) {
        puts("GLOBAL METADATA");
        press_enter_to_continue();
    }
    */
    
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