#include <windows.h>
#include <stdio.h>
#include <MinHook.h>
#include <stdbool.h>

struct YahaNativeContext;

typedef void (*YahaClientConfigSkipCertificateVerification)(
    struct YahaNativeContext *ctx, bool val
);

typedef void (*YahaBuildClient)(struct YahaNativeContext *);

static YahaBuildClient yaha_build_client = NULL;
static YahaBuildClient yaha_build_client_orig = NULL;
static YahaClientConfigSkipCertificateVerification yaha_client_config_skip_certificate_verification = NULL;

// yaha_client_config_skip_certificate_verification
// yaha_build_client

void detour_yaha_build_client(struct YahaNativeContext *ctx) {
    fputs("called", stdout);
    yaha_client_config_skip_certificate_verification(ctx, true);
    yaha_build_client_orig(ctx);
}

void HookYaha() {
    HMODULE yaha = GetModuleHandleA("Cysharp.Net.Http.YetAnotherHttpHandler.Native.dll");
    if (!yaha) {
        fputs("failed to get yaha module", stdout);
        return;
    }

    yaha_client_config_skip_certificate_verification = GetProcAddress(yaha, "yaha_client_config_skip_certificate_verification");

    if (!yaha_client_config_skip_certificate_verification) {
        fputs("failed to get yaha_client_config_skip_certificate_verification", stdout);
        return;
    }

    yaha_build_client = GetProcAddress(yaha, "yaha_build_client");

    if (!yaha_build_client) {
        fputs("failed to get yaha_build_client", stdout);
        return;
    }

    if (MH_CreateHook(yaha_build_client, &detour_yaha_build_client, 
        (LPVOID*)(&yaha_build_client_orig)) != MH_OK) {
   
         fputs("Failed to create hook", stdout);
        return;
     }

    if (MH_EnableHook(yaha_build_client) != MH_OK)
    {
        fputs("Failed to enable hook", stdout);
        return;
    }
}

typedef HMODULE (WINAPI *LOADLIBRARYA)(LPCSTR);
typedef HMODULE (WINAPI *LOADLIBRARYEXA)(LPCSTR, HANDLE, DWORD);
typedef HMODULE (WINAPI *LOADLIBRARYW)(LPCWSTR);
typedef HMODULE (WINAPI *LOADLIBRARYEXW)(LPCWSTR, HANDLE, DWORD);

LOADLIBRARYA fpLoadLibraryA = NULL;
LOADLIBRARYEXA fpLoadLibraryExA = NULL;
LOADLIBRARYW fpLoadLibraryW = NULL;
LOADLIBRARYEXW fpLoadLibraryExW = NULL;

HMODULE WINAPI DetourLoadLibraryA(LPCSTR s) {
    printf("LoadLibraryA: %s\n", s);
    return fpLoadLibraryA(s);
}

HMODULE WINAPI DetourLoadLibraryExA(LPCSTR s, HANDLE reserved, DWORD flags) {
    printf("LoadLibraryExA: %s\n", s);
    return fpLoadLibraryExA(s, reserved, flags);
}

#define NEWS_SIZE 4096

HMODULE WINAPI DetourLoadLibraryW(LPCWSTR s) {
    char news[NEWS_SIZE];
    int len = WideCharToMultiByte(CP_UTF8, 0, s, -1, 0, 0, 0, 0);
    WideCharToMultiByte(CP_UTF8, 0, s, -1, news, len, 0, 0);
    printf("LoadLibraryW: %s\n", news);
    return fpLoadLibraryW(s);
}

HMODULE WINAPI DetourLoadLibraryExW(LPCWSTR s, HANDLE reserved, DWORD flags) {
    char news[NEWS_SIZE];
    int len = WideCharToMultiByte(CP_UTF8, 0, s, -1, 0, 0, 0, 0);
    WideCharToMultiByte(CP_UTF8, 0, s, -1, news, len, 0, 0);
    printf("LoadLibraryExW: %s\n", news);
    return fpLoadLibraryExW(s, reserved, flags);
}

void HookLoadLibrary() {
    if (MH_CreateHook(&LoadLibraryA, &DetourLoadLibraryA, 
        (LPVOID*)(&fpLoadLibraryA)) != MH_OK)
    {
        fputs("Failed to create LoadLibraryA hook", stdout);
        return;
    }

    if (MH_CreateHook(&LoadLibraryExA, &DetourLoadLibraryExA, 
        (LPVOID*)(&fpLoadLibraryExA)) != MH_OK)
    {
        fputs("Failed to create LoadLibraryExA hook", stdout);
        return;
    }

    if (MH_CreateHook(&LoadLibraryW, &DetourLoadLibraryW, 
        (LPVOID*)(&fpLoadLibraryW)) != MH_OK)
    {
        fputs("Failed to create LoadLibraryW hook", stdout);
        return;
    }

    if (MH_CreateHook(&LoadLibraryExW, &DetourLoadLibraryExW, 
        (LPVOID*)(&fpLoadLibraryExW)) != MH_OK)
    {
        fputs("Failed to create LoadLibraryExW hook", stdout);
        return;
    }

    if (MH_EnableHook(&LoadLibraryA) != MH_OK)
    {
        fputs("Failed to enable LoadLibraryA hook", stdout);
        return;
    }

    if (MH_EnableHook(&LoadLibraryExA) != MH_OK)
    {
        fputs("Failed to enable LoadLibraryExA hook", stdout);
        return;
    }

    if (MH_EnableHook(&LoadLibraryW) != MH_OK)
    {
        fputs("Failed to enable LoadLibraryW hook", stdout);
        return;
    }

    if (MH_EnableHook(&LoadLibraryExW) != MH_OK)
    {
        fputs("Failed to enable LoadLibraryExW hook", stdout);
        return;
    }
}

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

    // HookYaha();

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