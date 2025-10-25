#include "utils.h"
#include "RemapMem.h"
#include "MetadataDump.h"

#include <MinHook.h>

#include <windows.h>
#include <libloaderapi.h>

#include <stdio.h>

typedef HMODULE (WINAPI *LOADLIBRARYW)(LPCWSTR);

LOADLIBRARYW fpLoadLibraryW = NULL;
bool alreadyDumped = false;

// editbin /REBASE:BASE=0x180000000 GA.dll
void DumpGameAssembly(HMODULE GameAssembly) {
    unsigned long long GameAssemblySize = CalcDLLSize(GameAssembly);

    printf("GameAssembly: addr: %p, size: 0x%llx\n", (void *)GameAssembly, GameAssemblySize);

    if (SaveMetadata("GA.dump", (void *)GameAssembly, GameAssemblySize)) {
        fputs("Saved GA.dump\n", stdout);
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
    // printf("LoadLibraryW: %s\n", news);

    BOOL isGameAssembly = strstr(news, "GameAssembly.dll") ? TRUE : FALSE;

    HMODULE res = fpLoadLibraryW(s);

    if (isGameAssembly) {
        if (!alreadyDumped) {
            alreadyDumped = true;
            DumpGameAssembly(res);
            // fpLoadLibraryW(L"D:\\tribenine\\version.dll");
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