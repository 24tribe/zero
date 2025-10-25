#include "utils.h"
#include "RemapMem.h"
#include "MetadataDump.h"
#include "Recons.h"
#include "HookIl2Cpp.h"
#include "Config.h"
#include "md5sum.h"

#include <MinHook.h>
#include <sds.h>

#include <windows.h>
#include <libloaderapi.h>

#include <stdio.h>
#include <wchar.h>

#define GOLDBERG_STEAM u"D:\\tribenine\\Goldberg_Lan_Steam_Emu\\steam_api64.dll"

typedef HMODULE (WINAPI *LOADLIBRARYW)(LPCWSTR);

LOADLIBRARYW fpLoadLibraryW = NULL;
bool alreadyDumped = false;

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

char *GetParentDir(char *path) {
    const char *delim = "\\";
    char *first = strtok(path, delim);
    char *second = strtok(NULL, delim);
    char *third;
    
    do {
        third = strtok(NULL, delim);
        if (third) {
            first = second;
            second = third;
        }
    } while (third);

    return first;
}

void GameAssemblyCallback(HMODULE GameAssembly) {
    char path[MAX_PATH];

    char *gameName = "unknown";

    // E:\TRIBENINE\GameAssembly.dll
    // E:\SteamLibrary\steamapps\common\Ratatan Demo\GameAssembly.dll
    // D:\unity\example\Build\GameAssembly.dll
    if (GetModuleFileNameA(GameAssembly, path, MAX_PATH) < MAX_PATH) {
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
        }

        gameName = GetParentDir(path);
    }

    

    if (alreadyDumped) {
        return;
    }

    alreadyDumped = true;

    unsigned long long GameAssemblySize = CalcDLLSize(GameAssembly);

    printf("GameAssembly: addr: %p, size: 0x%llx\n", (void *)GameAssembly, GameAssemblySize);

    char dumpPath[MAX_PATH];
    char addressPath[MAX_PATH];

    int perr1 = snprintf(dumpPath, MAX_PATH, "%s.dump", gameName);
    int perr2 = snprintf(addressPath, MAX_PATH, "%s.addr", gameName);
    
    if (perr1 < 0 || perr2 < 0 || perr1 >= MAX_PATH || perr2 >= MAX_PATH) {
        fputs("snprintf dumpPath or addressPath failed\n", stdout);
    } else {
        if (SaveMetadata(dumpPath, (void *)GameAssembly, GameAssemblySize)) {
            printf("Saved %s\n", dumpPath);
        } else {
            printf("Failed to save %s\n", dumpPath);
        }

        if (SaveAddress(addressPath, GameAssembly)) {
            printf("Saved address to %s\n", addressPath);
        }
    }
   
    InitRemapMem();

    if (RemapViewOfSection(GetCurrentProcess(), (void*)GameAssembly, GameAssemblySize, PAGE_EXECUTE_READWRITE)) {
        printf("DETOUR: Remap success!\n");
    } else {
        printf("Remap Failed!\n");
        return;
    }

    HookIl2Cpp(GameAssembly, gameName);
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
        
        res = fpLoadLibraryW(GOLDBERG_STEAM);
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