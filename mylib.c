#include "create_file_hook.h"
#include "load_library_hook.h"
#include "utils.h"
#include "NtQueryDirectoryFileHook.h"

#include <MinHook.h>

#include <windows.h>

#include <stdio.h>

void MyMain() {
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    freopen("CONIN$", "r", stdin);

    if (MH_Initialize() != MH_OK)
    {
        fputs("MinHook initialization failed", stdout);
        return;
    }

    HookNtQueryDirectoryFile();
    HookLoadLibrary();
    // HookCreateFile();

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