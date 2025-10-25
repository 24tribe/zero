#include "LoadLibraryHook.h"

#include <MinHook.h>

#include <windows.h>

#include <stdio.h>

void MyMain() {
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    freopen("CONIN$", "r", stdin);

    if (MH_Initialize() != MH_OK) {
        printf("MH_Initialize failed!\n");
        return;
    }

    HookLoadLibrary();

    puts("OK");
}

BOOL APIENTRY DllMain(HMODULE hModule,  DWORD  nReason, LPVOID lpReserved) {
    (void)hModule;
    (void)lpReserved;
    switch (nReason) {
    case DLL_PROCESS_ATTACH:
        MyMain();
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