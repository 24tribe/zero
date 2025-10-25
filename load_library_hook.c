#include "utils.h"
#include "RemapMem.h"
#include "MetadataDump.h"
#include "Recons.h"

#include <MinHook.h>

#include <windows.h>
#include <libloaderapi.h>

#include <stdio.h>

typedef HMODULE (WINAPI *LOADLIBRARYW)(LPCWSTR);

LOADLIBRARYW fpLoadLibraryW = NULL;
bool alreadyDumped = false;

bool SaveAddress(const char *outname, void *GameAssembly) {
    FILE *fp = fopen(outname, "w");
    if (!fp) {
        printf("fopen failed\n");
        return false;
    }
    fprintf(fp, "game_assembly_address=%p\n", GameAssembly);
    fclose(fp);
    return true;
}

// editbin /REBASE:BASE=0x180000000 GA.dll
void GameAssemblyCallback(HMODULE GameAssembly) {
    if (alreadyDumped) {
        return;
    }

    alreadyDumped = true;

    unsigned long long GameAssemblySize = CalcDLLSize(GameAssembly);

    printf("GameAssembly: addr: %p, size: 0x%llx\n", (void *)GameAssembly, GameAssemblySize);

    BYTE *buf = malloc(GameAssemblySize);

    if (!buf) {
        printf("Malloc failed\n");
        return;
    }

    memcpy(buf, GameAssembly, GameAssemblySize);

    if (DumpGameAssembly("GA.dll", buf, (unsigned long)GameAssemblySize, (unsigned long long)GameAssembly) < 0) {
        printf("DumpGameAssembly failed\n");
        return;
    }

    printf("Created GA.dll\n");

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
        GameAssemblyCallback(res);
        // fpLoadLibraryW(L"D:\\tribenine\\version.dll");
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