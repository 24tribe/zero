#include <stdio.h>
#include <windows.h>
#include <MinHook.h>
#include <libloaderapi.h>

typedef HMODULE (WINAPI *LOADLIBRARYA)(LPCSTR filename);

LOADLIBRARYA fpLoadLibraryA = NULL;

WINAPI HMODULE DetourLoadLibraryA(LPCSTR filename) {
    if (!strcmp(filename, "D:\\SteamLibrary\\steamapps\\common\\TRIBENINE\\GameAssembly.dll")) {
        HMODULE steam_api64 = fpLoadLibraryA(filename);
        DWORD old;
        printf("%s\n", filename);
        if (!VirtualProtect(((char *)steam_api64) + 0x1000, 32, PAGE_EXECUTE_READWRITE, &old)) {
            fputs("VirtualProtect failed\n", stdout);
        }
        return steam_api64;
    }
    return fpLoadLibraryA(filename);
}

void MyMain() {
    if (MH_Initialize() != MH_OK)
    {
        fputs("MinHook initialization failed", stdout);
        return;
    }
    
    if (MH_CreateHook(&LoadLibraryA, &DetourLoadLibraryA, (LPVOID *)&fpLoadLibraryA) != MH_OK) {
        fputs("MH_CreateHook failed!\n", stdout);
        return;
    }

    if (MH_EnableHook(&LoadLibraryA, TRUE) != MH_OK) {
        fputs("MH_EnableHook failed!\n", stdout);
        return;
    }  

    puts("OK");
}

BOOL APIENTRY DllMain(HMODULE hModule,  DWORD  nReason, LPVOID lpReserved) {
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