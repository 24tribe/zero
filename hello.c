#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <tlhelp32.h>

char evilDLL[] = "D:\\tribenine\\dllinj\\mylib.dll";
unsigned int evilLen = sizeof(evilDLL) + 1;

int main(int argc, char* argv[]) {
    HANDLE ph; // process handle
    HANDLE rt; // remote thread
    LPVOID rb; // remote buffer

    HMODULE hKernel32 = GetModuleHandle("Kernel32");

    if (!hKernel32) {
        fputs("GetModuleHandle failed", stderr);
        return 1;
    }

    VOID *lb = GetProcAddress(hKernel32, "LoadLibraryA");

    if (!lb) {
        fputs("GetProcAddress failed", stderr);
        return 1;
    }

    if (argc != 2) {
        fputs("Usage: hello.exe tribeninepath\n", stdout);
        return 1;
    }

    char *path = argv[1];

    STARTUPINFOA si = {};
    PROCESS_INFORMATION pi = {};
    si.cb = sizeof(si);
    
    BOOL ret = CreateProcessA(NULL, path, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

    if (!ret) {
        fputs("CreateProcessA failed\n", stderr);
        return 1;
    }

    ph = pi.hProcess;
    rb = VirtualAllocEx(ph, NULL, evilLen, (MEM_RESERVE | MEM_COMMIT), PAGE_EXECUTE_READWRITE);

    if (!rb) {
        fputs("VirtualAllocEx failed", stderr);
        return 1;
    }

    if (!WriteProcessMemory(ph, rb, evilDLL, evilLen, NULL)) {
        fputs("WriteProcessMemory failed", stderr);
        return 1;
    }

    rt = CreateRemoteThread(ph, NULL, 0, (LPTHREAD_START_ROUTINE)lb, rb, 0, NULL);

    if (!rt) {
        fputs("CreateRemoteThread failed", stderr);
        return 1;
    }

    CloseHandle(ph);
    return 0;
}

