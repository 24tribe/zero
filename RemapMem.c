// thanks to WWWC: https://www.unknowncheats.me/forum/3121760-post7.html

#include <stdio.h>
#include <windows.h>
#include <ntdef.h>

#include <stdio.h>
#include <stdbool.h>

#define Log(name, fmt, ...) (printf(name ": " fmt, ##__VA_ARGS__))

typedef enum _SECTION_INHERIT {
    ViewShare=1,
    ViewUnmap=2
} SECTION_INHERIT, *PSECTION_INHERIT;

typedef ULONG (WINAPI *TZwCreateSection)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, PLARGE_INTEGER, ULONG, ULONG, HANDLE);
typedef ULONG (WINAPI *TZwUnmapViewOfSection)(HANDLE, PVOID);
typedef ULONG (WINAPI *TZwMapViewOfSection)(HANDLE, HANDLE, PVOID, ULONG_PTR, SIZE_T, PLARGE_INTEGER, PSIZE_T, SECTION_INHERIT, ULONG, ULONG);


TZwUnmapViewOfSection ZwUnmapViewOfSection = NULL;
TZwMapViewOfSection ZwMapViewOfSection = NULL;
TZwCreateSection ZwCreateSection = NULL;

NTAPI PIMAGE_NT_HEADERS RtlImageNtHeader(PVOID ModuleAddress);

bool _RemapViewOfSection(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T RegionSize, DWORD NewProtection, PVOID CopyBuffer)
{
	int error = 0;
    SIZE_T numberOfBytesRead = 0;
    HANDLE hSection = NULL;
    LARGE_INTEGER sectionMaxSize = {0};
    sectionMaxSize.QuadPart = RegionSize;
    PVOID viewBase = BaseAddress;
    LARGE_INTEGER sectionOffset = {0};
    SIZE_T viewSize = 0;
    if (!ReadProcessMemory(ProcessHandle, BaseAddress, CopyBuffer, RegionSize, &numberOfBytesRead))
	{
		Log("REMAP", "1. ReadProcessMemory failed, returned %x, error %lx!!!\n", error, GetLastError());
        return false;
	}
    if((error = ZwCreateSection(&hSection, SECTION_ALL_ACCESS, NULL, &sectionMaxSize, PAGE_EXECUTE_READWRITE, SEC_COMMIT, NULL)) != 0)
	{
		Log("REMAP", "2. ZwCreateSection failed, returned %x, error %lx!!!\n", error, GetLastError());
        return false;
	}
    if((error = ZwUnmapViewOfSection(ProcessHandle, BaseAddress)) != 0)
	{
		Log("REMAP", "3. ZwUnmapViewOfSection failed, returned %x, error %lx!!!\n", error, GetLastError());
        return false;
	}
    if((error = ZwMapViewOfSection(hSection, ProcessHandle, &viewBase, 0, RegionSize, &sectionOffset, &viewSize, ViewUnmap, 0, PAGE_EXECUTE_READWRITE)) != 0)
	{
		Log("REMAP", "4. ZwMapViewOfSection failed, returned %x, error %lx!!!\n", error, GetLastError());
        return false;
	}
    SIZE_T numberOfBytesWritten = 0;
    if (!WriteProcessMemory(ProcessHandle, viewBase, CopyBuffer, viewSize, &numberOfBytesWritten))
	{
		Log("REMAP", "5. WriteProcessMemory failed...\n");
        return false;
	}
    if((error = ZwUnmapViewOfSection(ProcessHandle, BaseAddress)) != 0)
	{
		Log("REMAP", "6. ZwUnmapViewOfSection failed, returned %x, error %lx!!!\n", error, GetLastError());
        return false;
	}
    if((error = ZwMapViewOfSection(hSection, ProcessHandle, &viewBase, 0, RegionSize, &sectionOffset, &viewSize, ViewUnmap, 0, NewProtection)) != 0)
	{
		Log("REMAP", "7. ZwMapViewOfSection failed, returned %x, error %lx!!!\n", error, GetLastError());
        return false;
	}
    return true;
}

bool RemapViewOfSection(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T RegionSize, DWORD NewProtection)
{
    PVOID copybuf = VirtualAlloc(NULL, RegionSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!copybuf)
	{
		Log("REMAP", "VirtualAlloc failed...\n");
        return false;
	}
    bool result = _RemapViewOfSection(ProcessHandle, BaseAddress, RegionSize, NewProtection, copybuf);
    VirtualFree(copybuf, 0, MEM_RELEASE);
    return result;
}

void InitRemapMem(void) {
    ZwCreateSection = (TZwCreateSection)(uintptr_t)GetProcAddress(GetModuleHandleA("ntdll.dll"), "ZwCreateSection");
	ZwUnmapViewOfSection = (TZwUnmapViewOfSection)(uintptr_t)GetProcAddress(GetModuleHandleA("ntdll.dll"), "ZwUnmapViewOfSection");
	ZwMapViewOfSection = (TZwMapViewOfSection)(uintptr_t)GetProcAddress(GetModuleHandleA("ntdll.dll"), "ZwMapViewOfSection");
	printf("ZwCreateSection: 0x%llx\n", (unsigned long long)ZwCreateSection);
    printf("ZwUnmapViewOfSection: 0x%llx\n", (unsigned long long)ZwUnmapViewOfSection);
    printf("ZwMapViewOfSection: 0x%llx\n", (unsigned long long)ZwMapViewOfSection);
}

unsigned long long calcNext(unsigned long long size) {
    // 0x1000 page size?
    unsigned long long res = 0x1000;
    while (res < size) {
        res += 0x1000;
    }
    return res;
}

unsigned long long CalcDLLSize(void *data) {
    PIMAGE_NT_HEADERS headers = RtlImageNtHeader(data);

    if (!headers) {
        printf("RtlImageNtHeader failed\n");
        return ULLONG_MAX;
    }

    int numberOfSections = headers->FileHeader.NumberOfSections;

    unsigned long long totalSize = 0x1000; // peHeader <= 0x1000

    PIMAGE_SECTION_HEADER sections = IMAGE_FIRST_SECTION(headers);
    for (int i = 0; i < numberOfSections; ++i) {
        PIMAGE_SECTION_HEADER section = sections + i;
        
        unsigned long long inMemSize = calcNext(section->Misc.VirtualSize);

        totalSize += inMemSize;
    }

    return totalSize;
}