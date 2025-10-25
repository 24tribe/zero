#include <stdio.h>
#include <windows.h>
#include <MinHook.h>

void DetourPrintMsg(char *msg) {
    printf("YOUR MESSAGE IS: %s\n", msg);
}

typedef void (*PRINTMSG)(char *);

PRINTMSG fpPrintMsg = NULL;

void MyMain() {

    // AllocConsole();
    // freopen("CONOUT$", "w", stdout);
    // freopen("CONIN$", "r", stdin);

    void *base_address = GetModuleHandleA(NULL);

    if (!base_address) {
        fputs("GetModuleHandleA failed\n", stderr);
        return;
    }

    if (MH_Initialize() != MH_OK)
    {
        fputs("MinHook initialization failed", stdout);
        return;
    }

    ptrdiff_t print_msg_offset = 0x13B4;
    void *printMsgOrig = (char *)base_address + print_msg_offset;

    if (MH_CreateHook(printMsgOrig, &DetourPrintMsg, (LPVOID *)&fpPrintMsg) != MH_OK) {
        fputs("MinHook CreateHook failed", stdout);
        return;
    }

    if (MH_EnableHook(printMsgOrig) != MH_OK) {
        fputs("MinHook EnableHook failed", stdout);
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