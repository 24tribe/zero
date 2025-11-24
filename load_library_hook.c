#include "utils.h"
#include "RemapMem.h"
#include "HookIl2Cpp.h"
#include "Config.h"
#include "md5sum.h"
#include "sds_utf_conv.h"

#include <MinHook.h>
#include <sds.h>

#include <windows.h>
#include <libloaderapi.h>

#include <stdio.h>
#include <wchar.h>

typedef HMODULE (WINAPI *LOADLIBRARYW)(LPCWSTR);

LOADLIBRARYW fpLoadLibraryW = NULL;
bool alreadyCalledGameAssemblyCallback = false;

bool SaveAddress(const char *outname, void *GameAssembly) {
    FILE *fp = fopen(outname, "w");
    if (!fp) {
        printf("fopen failed\n");
        return false;
    }
    fprintf(fp, "%llu\n", (unsigned long long)GameAssembly);
    fclose(fp);
    return true;
}

void CalculateMd5Sum(sds path) {
    sds GameAssemblyDll = SlurpFile(path);

    if (GameAssemblyDll) {
        uint8_t digest[16];
        md5sum_buffer((const uint8_t*)GameAssemblyDll, sdslen(GameAssemblyDll), digest);
        char *hex = md5_hex(digest);
        if (!strcmp(hex, "bf87cdb761f931b8ff806b2bd7a376af")) {
            printf("Correct md5sum!!!\n");
        } else {
            printf("WARNING! Incorrect md5sum (%s), manually update script.json!\n", hex);
        }
        free(hex);

        sdsfree(GameAssemblyDll);
    }
}

void GameAssemblyCallback(HMODULE GameAssembly) {
    char path[MAX_PATH];

    // E:\TRIBENINE\GameAssembly.dll
    // E:\SteamLibrary\steamapps\common\Ratatan Demo\GameAssembly.dll
    // D:\unity\example\Build\GameAssembly.dll
    // FIXME: should use GetModuleFileNameW
    if (GetModuleFileNameA(GameAssembly, path, MAX_PATH) < MAX_PATH) {
        CalculateMd5Sum(path);
    }

    if (alreadyCalledGameAssemblyCallback) {
        return;
    }

    alreadyCalledGameAssemblyCallback = true;

    unsigned long long GameAssemblySize = CalcDLLSize(GameAssembly);

    printf("GameAssembly: addr: %p, size: 0x%llx\n", (void *)GameAssembly, GameAssemblySize);

    InitRemapMem();

    if (RemapViewOfSection(GetCurrentProcess(), (void*)GameAssembly, GameAssemblySize, PAGE_EXECUTE_READWRITE)) {
        printf("DETOUR: Remap success!\n");
    } else {
        printf("Remap Failed!\n");
        return;
    }

    HookIl2Cpp(GameAssembly);
}

bool loggedGoldberg = false;

HMODULE WINAPI DetourLoadLibraryW(LPCWSTR s) {
    sds libName = sds16to8(s, wcslen(s));

    // printf("LoadLibraryW: %s\n", libName);

    HMODULE res;

    if (strstr(libName, "steam_api64.dll") && ZERO_CONFIG.offlineMode) {
        if (!loggedGoldberg) {
            printf("[DetourLoadLibraryW] Changed steam_api64.dll to Goldberg\n");
            loggedGoldberg = true;
        }

        res = fpLoadLibraryW(ZERO_CONFIG.goldbergPath);
    } else {
        bool isGameAssembly = strstr(libName, "GameAssembly.dll");

        res = fpLoadLibraryW(s);
        if (isGameAssembly) {
            GameAssemblyCallback(res);
        }
    }

    sdsfree(libName);
    
    return res;
}

void HookLoadLibrary() {
    if (MH_CreateHook((void *)(uintptr_t)&LoadLibraryW, (void *)(uintptr_t)&DetourLoadLibraryW, 
        (LPVOID*)(&fpLoadLibraryW)) != MH_OK)
    {
        fputs("Failed to create LoadLibraryW hook", stdout);
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)&LoadLibraryW, TRUE) != MH_OK)
    {
        fputs("Failed to enable LoadLibraryW hook", stdout);
        return;
    }
}