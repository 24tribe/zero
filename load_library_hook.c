#include "utils.h"
#include "hook_mapviewofsection.h"
#include "hook_ntcreatesection.h"
#include "RemapMem.h"
#include "MetadataDump.h"

#include <MinHook.h>

#include <windows.h>
#include <libloaderapi.h>

#include <stdio.h>

struct FileHandle;
typedef void *(*MEMORYMAPPEDFILEMAP)(struct FileHandle *);

typedef void *(*LOADMETADATAFILE)(const char *fileName);

typedef HMODULE (WINAPI *LOADLIBRARYW)(LPCWSTR);

LOADLIBRARYW fpLoadLibraryW = NULL;
MEMORYMAPPEDFILEMAP fpMemoryMappedFileMap = NULL;
LOADMETADATAFILE fpLoadMetadataFile = NULL;


ptrdiff_t MemoryMappedFileMapOffset = 0x670b90;
ptrdiff_t LoadMetadataFileOffset = 0x6b0870;

void SaveMetadataFromMem(BYTE *res) {
    char *path = "D:\\SteamLibrary\\steamapps\\common\\TRIBENINE\\tribenine_Data\\il2cpp_data\\Metadata\\global-metadata.dat";
    long long size = GetMetadataSize(path);

    if (size == LLONG_MAX) {
        printf("GetMetadataSize failed\n");
        return;
    }

    printf("Size: 0x%lld\n", size);
    
    if (size > (long long)LONG_MAX) {
        printf("Size doesnt fit in a long\n");
        return;
    }

    unsigned long smallSize = (unsigned long)size;

    if (SaveMetadata("metadata.dat", (BYTE *)res, smallSize)) {
        printf("SaveMetadata Success\n");
    } else {
        printf("SaveMEtadata Failed\n");
    }
}

void *DetourLoadMetadataFile(const char *filename) {
    printf("LoadMetadataFile(fileName=%s)\n", filename);
    BYTE *res = fpLoadMetadataFile(filename);
    if (IsMetadata(res)) {
        SaveMetadataFromMem(res);
    }
    return res;
}

void *DetourMemoryMappedFileMap(struct FileHandle *fileHandle) {
    printf("MemoryMappedFileMap called\n");
    BYTE *res = fpMemoryMappedFileMap(fileHandle);
    return res;
}

void HookMemoryMappedFileMap(HMODULE GameAssembly) {
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

    MEMORYMAPPEDFILEMAP original = (void *)((char *)GameAssembly + MemoryMappedFileMapOffset);
    LOADMETADATAFILE xLoadMetadataFile = (void *)((char *)GameAssembly + LoadMetadataFileOffset);

    printf("MemoryMappedFileMap address: %p\n", (void *)original);
    printf("LoadMetadataFile address: %p\n", (void *)xLoadMetadataFile);

    int status = 0;
    if ((status = MH_CreateHook(original, &DetourMemoryMappedFileMap,
        (LPVOID *)(&fpMemoryMappedFileMap))) != MH_OK) {
        printf("Failed to create MemoryMappedFileMap hook: %s\n", MH_StatusToString(status));
        return;
    }

    if ((status = MH_EnableHook(original, FALSE)) != MH_OK) {
        printf("failed to enable MemoryMappedFileMap hook: %s\n", MH_StatusToString(status));
        return;
    }

    if ((status = MH_CreateHook(xLoadMetadataFile, &DetourLoadMetadataFile,
        (LPVOID *)(&fpLoadMetadataFile))) != MH_OK) {
        printf("Failed to create LoadMetadataFile hook: %s\n", MH_StatusToString(status));
        return;
    }

    if ((status = MH_EnableHook(xLoadMetadataFile, FALSE)) != MH_OK) {
        printf("failed to enable LoadMetadataFile hook: %s\n", MH_StatusToString(status));
        return;
    }
}

// #define HOOK_STEAMAPI
HMODULE WINAPI DetourLoadLibraryW(LPCWSTR s) {
    char news[MY_LINE_SIZE];
    int len = WideCharToMultiByte(CP_UTF8, 0, s, -1, 0, 0, 0, 0);
    WideCharToMultiByte(CP_UTF8, 0, s, -1, news, len, 0, 0);
    printf("LoadLibraryW: %s\n", news);

    #ifdef HOOK_STEAMAPI
    if (strstr(news, "steam_api64.dll")) {
        puts("hooking steam_api64.dll");
        return fpLoadLibraryW(L"D:\\tribenine\\dllinj\\steam_api64.dll");
    }
    #endif

    BOOL isGameAssembly = strstr(news, "GameAssembly.dll") ? TRUE : FALSE;

    HMODULE res = fpLoadLibraryW(s);

    if (isGameAssembly) {
        printf("GameAssembly location: %p\n", (void *)res);
        if (!fpMemoryMappedFileMap) {
            press_enter_to_continue();
            HookMemoryMappedFileMap(res);
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