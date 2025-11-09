#include "load_library_hook.h"
#include "NtQueryDirectoryFileHook.h"
#include "Config.h"
#include "Backend.h"

#include <MinHook.h>

#include <windows.h>
#include <synchapi.h>
#include <processthreadsapi.h>

#include <stdio.h>

int MainThread(LPVOID param) {
    (void)param;

    Backend_Load();

	while (1) {
        Sleep(420);
    }

	return 0;
}

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

    // HookNtQueryDirectoryFile();
    HookLoadLibrary();

    HANDLE hMainThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, NULL);

    if (hMainThread) {
        CloseHandle(hMainThread);
    }

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