#include "load_library_hook.h"
#include "NtQueryDirectoryFileHook.h"
#include "Config.h"
#include "gui/UserInterface.h"
#include "create_file_hook.h"
#include "ModHelper.h"
#include "semba.h"
#include "NimInit.h"
#include "SembaContext.h"
#include "game_version.h"
#include "semba_enum.h"

#include <MinHook.h>

#include <windows.h>
#include <processthreadsapi.h>

#include <stdio.h>
#include <stdlib.h>

void MyMain(HMODULE hModule) {
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    freopen("CONIN$", "r", stdin);

    if (MH_Initialize() != MH_OK)
    {
        fputs("MinHook initialization failed", stdout);
        return;
    }

    InitConfig();

    RunNimMainOnce();

    if (ZERO_CONFIG.sembaDbPath && !ZERO_CONFIG.sembaStandaloneUrl) {
        int32_t status;
        struct SembaExContext *ctx = SembaExInit(ZERO_CONFIG.sembaDbPath, GAME_VERSION, &status);
        if (status != SEMBA_STATUS_OK) {
            printf("SembaExInit failed: status %d\n!!!\n", (int)status);
        } else {
            SembaContextSet(ctx);
        }
    }

    // HookNtQueryDirectoryFile();
    HookLoadLibrary();
    HookCreateFile();

    HANDLE hMainThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)UIMainThread, hModule, 0, NULL);

    if (hMainThread) {
        CloseHandle(hMainThread);
    }

    SetGlobalModManager(ModHelper_ParseMods(ZERO_CONFIG.modsDir));

    HANDLE zeroHookFinishEvent = CreateEventA(NULL, TRUE, FALSE, "zeroHookFinishEvent");
    SetEvent(zeroHookFinishEvent);
    CloseHandle(zeroHookFinishEvent);

    printf("OK! Reached end of MyMain!\n");
}

BOOL APIENTRY DllMain(HMODULE hModule,  DWORD  nReason, LPVOID lpReserved) {
    (void)lpReserved;
    switch (nReason) {
    case DLL_PROCESS_ATTACH:
        MyMain(hModule);
        break;
    case DLL_PROCESS_DETACH:
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    }
    return TRUE;
}