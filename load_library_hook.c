#include "utils.h"
#include "hook_mapviewofsection.h"
#include "hook_ntcreatesection.h"
#include "RemapMem.h"
#include "MetadataDump.h"

#include <MinHook.h>

#include <windows.h>
#include <libloaderapi.h>

#include <stdio.h>

typedef HMODULE (WINAPI *LOADLIBRARYW)(LPCWSTR);

LOADLIBRARYW fpLoadLibraryW = NULL;
bool alreadyDumped = false;

void DumpGameAssembly(HMODULE GameAssembly) {
    unsigned long long GameAssemblySize = CalcDLLSize(GameAssembly);

    if (SaveMetadata("ga.dump", (void *)GameAssembly, GameAssemblySize)) {
        fputs("Saved ga.dump\n", stdout);
    } else {
        fputs("Failed to save ga.dump\n", stdout);
    }
        
    InitRemapMem();

    if (RemapViewOfSection(GetCurrentProcess(), (void*)GameAssembly, GameAssemblySize, PAGE_EXECUTE_READWRITE)) {
        printf("DETOUR: Remap success!\n");
    } else {
        printf("Remap Failed!\n");
        return;
    }
}

HMODULE WINAPI DetourLoadLibraryW(LPCWSTR s) {
    char news[MY_LINE_SIZE];
    int len = WideCharToMultiByte(CP_UTF8, 0, s, -1, 0, 0, 0, 0);
    WideCharToMultiByte(CP_UTF8, 0, s, -1, news, len, 0, 0);
    printf("LoadLibraryW: %s\n", news);

    BOOL isGameAssembly = strstr(news, "GameAssembly.dll") ? TRUE : FALSE;

    HMODULE res = fpLoadLibraryW(s);

    if (isGameAssembly) {
        printf("GameAssembly location: %p\n", (void *)res);
        if (!alreadyDumped) {
            alreadyDumped = true;
            press_enter_to_continue();
            DumpGameAssembly(res);
            press_enter_to_continue();
        }
    }
    
    return res;
}

void HookLoadLibrary() {
    if (MH_CreateHook(&LoadLibraryW, &DetourLoadLibraryW, 
        (LPVOID*)(&fpLoadLibraryW)) != MH_OK)
    {
        fputs("Failed to create LoadLibraryW hook", stdout);
        return;
    }

    if (MH_EnableHook(&LoadLibraryW, TRUE) != MH_OK)
    {
        fputs("Failed to enable LoadLibraryW hook", stdout);
        return;
    }
}