#include "utils.h"

#include <MinHook.h>

#include <windows.h>
#include <fileapi.h>

#include <stdio.h>

typedef HANDLE (WINAPI *CREATEFILEA)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
typedef HANDLE (WINAPI *CREATEFILEW)(LPCWSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);

CREATEFILEA fpCreateFileA = NULL;
CREATEFILEW fpCreateFileW = NULL;

HANDLE WINAPI DetourCreateFileA(
    LPCSTR filename,  DWORD access, DWORD shareMode,
    LPSECURITY_ATTRIBUTES attrs, DWORD creationDisp, DWORD flags, HANDLE template) {

    printf("CreateFileA: %s\n", filename);

    return fpCreateFileA(filename, access, shareMode, attrs, creationDisp, flags, template);
}

HANDLE WINAPI DetourCreateFileW(
    LPCWSTR filenameW,  DWORD access, DWORD shareMode,
    LPSECURITY_ATTRIBUTES attrs, DWORD creationDisp, DWORD flags, HANDLE template) {

    char filename[MY_LINE_SIZE];
    WideToUtf8(filename, filenameW);

    printf("CreateFileW: %s\n", filename);

    if (strstr(filename, "global-metadata.dat")) {
        puts("GLOBAL METADATA");
        press_enter_to_continue();
    }

    return fpCreateFileW(filenameW, access, shareMode, attrs, creationDisp, flags, template);
}

void HookCreateFile() {
    if (MH_CreateHook(&CreateFileA, &DetourCreateFileA,
        (LPVOID *)(&fpCreateFileA)) != MH_OK) {
        fputs("Failed to create CreateFileA hook\n", stdout);
        return;
    }

    if (MH_CreateHook(&CreateFileW, &DetourCreateFileW,
        (LPVOID *)(&fpCreateFileW)) != MH_OK) {
        fputs("Failed to create CreateFileW hook\n", stdout);
        return;
    }

    if (MH_EnableHook(&CreateFileA, TRUE) != MH_OK) {
        fputs("failed to enable CreateFileA hook", stdout);
        return;
    }

    if (MH_EnableHook(&CreateFileW, TRUE) != MH_OK) {
        fputs("failed to enable CreateFileW hook", stdout);
        return;
    }
}