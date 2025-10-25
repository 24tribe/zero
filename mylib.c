#if 0
Cosas para probar
- Ver si VirtualProtect fue hookeado por GameAssembly
- Ver si NtCreateSection o NtMapViewOfSection fue hookeado por GameAssembly
#endif

#include "create_file_hook.h"
#include "load_library_hook.h"
#include "utils.h"

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

    HookLoadLibrary();
    HookCreateFile();

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