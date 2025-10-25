#ifndef LOAD_LIBRARY_HOOK_H_202506121437
#define LOAD_LIBRARY_HOOK_H_202506121437

#include <windows.h>

void HookLoadLibrary();
void HookMemoryMappedFileMap(HMODULE GameAssembly);

#endif