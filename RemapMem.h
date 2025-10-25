#ifndef REMAP_MEM_H_2506280321
#define REMAP_MEM_H_2506280321

#include <windows.h>

#include <stdbool.h>

void InitRemapMem(void);
bool RemapViewOfSection(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T RegionSize, DWORD NewProtection);
unsigned long long CalcDLLSize(void *data);

#endif