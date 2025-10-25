// https://www.unknowncheats.me/forum/anti-cheat-bypass/450312-call-virtualprotect-mem_mapped-pages.html

#include "stdafx.h"
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <wininet.h>
#include <aclapi.h>
#include "MinHook.h"
#include "Helper.h"

typedef void (__stdcall * HTTPREQ)(
  HINTERNET hConnect,
  LPCWSTR   lpszVerb,
  LPCWSTR   lpszObjectName,
  LPCWSTR   lpszVersion,
  LPCWSTR   lpszReferrer,
  LPCWSTR   *lplpszAcceptTypes,
  DWORD     dwFlags,
  DWORD_PTR dwContext
);
typedef HINTERNET (__stdcall * HTTPREQ2)(
  HINTERNET hConnect,
  LPCWSTR   pwszVerb,
  LPCWSTR   pwszObjectName,
  LPCWSTR   pwszVersion,
  LPCWSTR   pwszReferrer,
  LPCWSTR   *ppwszAcceptTypes,
  DWORD     dwFlags
);
typedef enum _MEMORY_INFORMATION_CLASS {
    MemoryBasicInformation,
    MemoryWorkingSetList,
    MemorySectionName
} MEMORY_INFORMATION_CLASS;
typedef enum _OBJECT_INFORMATION_CLASS {
    ObjectBasicInformation = 0,
    ObjectNameInformation = 1,
    ObjectTypeInformation = 2,
    ObjectAllTypesInformation = 3,
    ObjectHandleInformation = 4
} OBJECT_INFORMATION_CLASS;
typedef struct _PUBLIC_OBJECT_BASIC_INFORMATION {
    ULONG Attributes;
    ACCESS_MASK GrantedAccess;
    ULONG HandleCount;
    ULONG PointerCount;
    ULONG Reserved[10];
 } PUBLIC_OBJECT_BASIC_INFORMATION, *PPUBLIC_OBJECT_BASIC_INFORMATION;
typedef struct _UNICODE_STRING
{
     WORD Length;
     WORD MaximumLength;
     WORD * Buffer;
} UNICODE_STRING, *PUNICODE_STRING;
typedef struct _OBJECT_ATTRIBUTES
{
     ULONG Length;
     PVOID RootDirectory;
     PUNICODE_STRING ObjectName;
     ULONG Attributes;
     PVOID SecurityDescriptor;
     PVOID SecurityQualityOfService;
} OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;
typedef enum _SECTION_INHERIT {
    ViewShare=1,
    ViewUnmap=2
} SECTION_INHERIT, *PSECTION_INHERIT;
typedef ULONG (WINAPI *TNtProtectVirtualMemory)( HANDLE, PVOID, PSIZE_T, ULONG, PULONG);
typedef ULONG (WINAPI *TNtQueryVirtualMemory)(HANDLE, PVOID, MEMORY_INFORMATION_CLASS, PVOID, SIZE_T, PSIZE_T);
typedef ULONG (WINAPI *TNtQueryObject)(HANDLE, OBJECT_INFORMATION_CLASS, PVOID, ULONG, PULONG);
typedef ULONG (WINAPI *TZwCreateSection)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, PLARGE_INTEGER, ULONG, ULONG, HANDLE);
typedef ULONG (WINAPI *TZwUnmapViewOfSection)(HANDLE, PVOID);
typedef ULONG (WINAPI *TZwMapViewOfSection)(HANDLE, HANDLE, PVOID, ULONG_PTR, SIZE_T, PLARGE_INTEGER, PSIZE_T, SECTION_INHERIT, ULONG, ULONG);


TNtProtectVirtualMemory xNtProtectVirtualMemory;
TNtQueryVirtualMemory xNtQueryVirtualMemory;
TZwUnmapViewOfSection xZwUnmapViewOfSection;
TZwMapViewOfSection xZwMapViewOfSection;
TZwCreateSection xZwCreateSection;
TNtQueryObject xNtQueryObject;
HTTPREQ orgHttpOpenRequestW = NULL;
HTTPREQ2 orgWinHttpOpenRequest = NULL;

//NtProtectVirtualMemory
BYTE code1[] = { 0x4C, 0x8B, 0xD1,				//mov r10, rcx
				0xB8, 0x50, 0x00, 0x00, 0x00,	//mov eax, 50
				0x0F, 0x05,						//syscall
				0xC3};							//ret

//NtQueryVirtualMemory
BYTE code2[] = { 0x4C, 0x8B, 0xD1,				//mov r10, rcx
				0xB8, 0x23, 0x00, 0x00, 0x00,	//mov eax, 23
				0x0F, 0x05,						//syscall
				0xC3};							//ret

void myHttpOpenRequestW(
  HINTERNET hConnect,
  LPCWSTR   lpszVerb,
  LPCWSTR   lpszObjectName,
  LPCWSTR   lpszVersion,
  LPCWSTR   lpszReferrer,
  LPCWSTR   *lplpszAcceptTypes,
  DWORD     dwFlags,
  DWORD_PTR dwContext
)
{
	Log("HORW", "HttpOpenRequestW called: %S %S\n", lpszVerb, lpszObjectName);
	orgHttpOpenRequestW(hConnect, lpszVerb,lpszObjectName, lpszVersion, lpszReferrer, lplpszAcceptTypes, dwFlags, dwContext); 
}

HINTERNET myWinHttpOpenRequest(
  HINTERNET hConnect,
  LPCWSTR   pwszVerb,
  LPCWSTR   pwszObjectName,
  LPCWSTR   pwszVersion,
  LPCWSTR   pwszReferrer,
  LPCWSTR   *ppwszAcceptTypes,
  DWORD     dwFlags
)
{
	Log("WHOR", "WinHttpOpenRequest called: %S %S\n", pwszVerb, pwszObjectName);
	return orgWinHttpOpenRequest(hConnect, pwszVerb, pwszObjectName, pwszVersion, pwszReferrer, ppwszAcceptTypes, dwFlags); 
}

ULONG NtProtectVirtual(PVOID addr, DWORD len, ULONG access, PULONG oldProtect)
{
	if(xNtProtectVirtualMemory != NULL)
	{
		Log("NTPVM", "Using own NtProtectVirtualMemory...\n");
		return xNtProtectVirtualMemory(GetCurrentProcess(), addr, (PSIZE_T)&len, access, oldProtect);
	}
	else
	{
		Log("NTPVM", "Using VirtualProtect...\n");
		return VirtualProtect(addr, len, access, oldProtect);
	}
}

ULONG NtQueryVirtualMemory(LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength)
{
	if(xNtQueryVirtualMemory != NULL)
	{
		Log("NTQVM", "Using own NtQueryVirtualMemory...\n");
		return xNtQueryVirtualMemory(GetCurrentProcess(), (PVOID)lpAddress, MemoryBasicInformation, lpBuffer, dwLength, 0);
	}
	else
	{
		Log("NTQVM", "Using VirtualQuery...\n");
		return (ULONG)VirtualQuery(lpAddress, lpBuffer, dwLength);
	}
}

bool _RemapViewOfSection(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T RegionSize, DWORD NewProtection, PVOID CopyBuffer)
{
	int error;
    SIZE_T numberOfBytesRead = 0;
    HANDLE hSection = NULL;
    LARGE_INTEGER sectionMaxSize = {};
    sectionMaxSize.QuadPart = RegionSize;
    PVOID viewBase = BaseAddress;
    LARGE_INTEGER sectionOffset = {};
    SIZE_T viewSize = 0;
    if (!ReadProcessMemory(ProcessHandle, BaseAddress, CopyBuffer, RegionSize, &numberOfBytesRead))
	{
		Log("REMAP", "1. ReadProcessMemory failed, returned %x, error %d!!!\n", error, GetLastError());
        return false;
	}
    if((error = xZwCreateSection(&hSection, SECTION_ALL_ACCESS, NULL, &sectionMaxSize, PAGE_EXECUTE_READWRITE, SEC_COMMIT, NULL)) != 0)
	{
		Log("REMAP", "2. ZwCreateSection failed, returned %x, error %d!!!\n", error, GetLastError());
        return false;
	}
    if((error = xZwUnmapViewOfSection(ProcessHandle, BaseAddress)) != 0)
	{
		Log("REMAP", "3. ZwUnmapViewOfSection failed, returned %x, error %d!!!\n", error, GetLastError());
        return false;
	}
    if((error = xZwMapViewOfSection(hSection, ProcessHandle, &viewBase, 0, RegionSize, &sectionOffset, &viewSize, ViewUnmap, 0, PAGE_EXECUTE_READWRITE)) != 0)
	{
		Log("REMAP", "4. ZwMapViewOfSection failed, returned %x, error %d!!!\n", error, GetLastError());
        return false;
	}
    SIZE_T numberOfBytesWritten = 0;
    if (!WriteProcessMemory(ProcessHandle, viewBase, CopyBuffer, viewSize, &numberOfBytesWritten))
	{
		Log("REMAP", "5. WriteProcessMemory failed...\n");
        return false;
	}
    if((error = xZwUnmapViewOfSection(ProcessHandle, BaseAddress)) != 0)
	{
		Log("REMAP", "6. ZwUnmapViewOfSection failed, returned %x, error %d!!!\n", error, GetLastError());
        return false;
	}
    if((error = xZwMapViewOfSection(hSection, ProcessHandle, &viewBase, 0, RegionSize, &sectionOffset, &viewSize, ViewUnmap, 0, NewProtection)) != 0)
	{
		Log("REMAP", "7. ZwMapViewOfSection failed, returned %x, error %d!!!\n", error, GetLastError());
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

BYTE* DetourFunction(BYTE* address, BYTE* detour)
{
	BYTE* result = NULL;
	int error;
	DWORD oldProtect;
	SYSTEM_INFO sSysInfo;
	MEMORY_BASIC_INFORMATION mbi;
    GetSystemInfo(&sSysInfo);
	Log("DETOUR", "Detouring at 0x%p with 0x%p\n", address, detour);
	Log("DETOUR", "Page Size = 0x%x\n", sSysInfo.dwPageSize);
	if((error = NtQueryVirtualMemory((LPVOID)address, &mbi, sizeof(mbi))) != 0)
		Log("DETOUR", "NtQueryVirtualMemory failed, returned %x, error %d!!!\n", error, GetLastError());
	else
	{
		Log("DETOUR", "AllocBaseAddress=0x%p\n", mbi.AllocationBase);
		Log("DETOUR", "BaseAddress=0x%p\n", mbi.BaseAddress);
		Log("DETOUR", "RegionSize=0x%x\n", mbi.RegionSize);
		Log("DETOUR", "State=0x%x\n", mbi.State);
		Log("DETOUR", "Type=0x%x\n", mbi.Type);
		Log("DETOUR", "Protect = 0x%08x\n", mbi.Protect);
		Log("DETOUR", "AllocationProtect = 0x%08x\n", mbi.AllocationProtect);
		if(mbi.Type == 0x40000)
		{
			//MessageBoxA(NULL, "Trying to remap...", "Hello World!", NULL);
			Log("DETOUR", "Trying to remap...\n");
			unsigned long long size = (unsigned long long)mbi.RegionSize + ((unsigned long long)mbi.BaseAddress - (unsigned long long)mbi.AllocationBase);
			Log("DETOUR", "Full Region Size: 0x%llx\n", size);
			if(RemapViewOfSection(GetCurrentProcess(), mbi.AllocationBase, size, PAGE_EXECUTE_READWRITE))
				Log("DETOUR", "Remap success!\n");
			Log("DETOUR", "Trying to undo...\n");
			if(RemapViewOfSection(GetCurrentProcess(), mbi.AllocationBase, size, PAGE_EXECUTE_READ))
				Log("DETOUR", "Remap success!\n");
		}
	}
	return NULL;
	if((error = NtProtectVirtual(address, sSysInfo.dwPageSize, PAGE_EXECUTE_READWRITE, &oldProtect)) != 0)
		Log("DETOUR", "NtProtectVirtual failed, returned %x, error %d!!!\n", error, GetLastError());
	else
		Log("DETOUR", "Old Protect was : 0x%08X\n", oldProtect);
	if((error = MH_CreateHook((LPVOID)address, (LPVOID)detour, (LPVOID*)&result)) != 0)
		Log("DETOUR", "MH_CreateHook failed, error %d!!!\n", error);
	if((error = MH_EnableHook((LPVOID)address)) != 0)
		Log("DETOUR", "MH_EnableHook failed, error %d!!!\n", error);
	if((error = NtProtectVirtual(address, sSysInfo.dwPageSize, oldProtect, &oldProtect)) != 0)
		Log("DETOUR", "NtProtectVirtual failed, returned %x, error %d!!!\n", error, GetLastError());
	else
		Log("DETOUR", "Old Protect was : 0x%08X\n", oldProtect);
	if((error = NtQueryVirtualMemory((LPVOID)address, &mbi, sizeof(mbi))) != 0)
		Log("DETOUR", "NtQueryVirtualMemory failed, returned %x, error %d!!!\n", error, GetLastError());
	else
	{
		Log("DETOUR", "Queried Protect after = 0x%08x\n", mbi.Protect);
		Log("DETOUR", "Queried AllocationProtect after = 0x%08x\n", mbi.AllocationProtect);
	}
	return result;
}

void TestProcessAccess()
{
	int error;
	PUBLIC_OBJECT_BASIC_INFORMATION obi;
	if((error = xNtQueryObject(GetCurrentProcess(), ObjectBasicInformation, &obi, sizeof(obi), 0)) != 0)
		Log("TACCESS", "NtQueryObject failed, returned %x, error %d!!!\n", error, GetLastError());
	else
		Log("TACCESS", "Process Handle Granted Access Mask = 0x%x\n", obi.GrantedAccess);
}

void GrantAccess()
{
	BYTE	abyBuffer[0x200];
	PACL	pACL;
	SID_IDENTIFIER_AUTHORITY stIdentifierAuthority = SECURITY_WORLD_SID_AUTHORITY;
	PSID pSid = NULL;
	BOOL bRet = FALSE;
	DWORD dwSize = 0;
	HANDLE hToken = NULL;
	HANDLE hProcess = GetCurrentProcess();
	PTOKEN_USER pUserInfo = NULL;
	Log("GACCESS", "Trying to get access...\n");
	while(true)
	{
 		if( AllocateAndInitializeSid( &stIdentifierAuthority, 1, SECURITY_WORLD_RID, 0, 0, 0, 0, 0, 0, 0, &pSid ) == FALSE )
			break;
		Log("GACCESS", "Step 1 done.\n");
		if( OpenProcessToken( hProcess, TOKEN_QUERY, &hToken ) == FALSE )
			break;
		Log("GACCESS", "Step 2 done.\n");
		GetTokenInformation( hToken, TokenUser, NULL, NULL, &dwSize );
		if( dwSize > 1024 )
			break;
		Log("GACCESS", "Step 3 done.\n");
		pUserInfo = (PTOKEN_USER)GlobalAlloc( GPTR, dwSize );
		if( pUserInfo == NULL )
			break;
		Log("GACCESS", "Step 4 done.\n");
		if( GetTokenInformation( hToken, TokenUser, pUserInfo, dwSize, &dwSize ) == FALSE )
			break;
		Log("GACCESS", "Step 5 done.\n");
		pACL = (PACL) &abyBuffer;	
		if( InitializeAcl( pACL, 0x200, ACL_REVISION ) == FALSE )
			break;
		Log("GACCESS", "Step 6 done.\n");
		if( AddAccessAllowedAce( pACL, ACL_REVISION, PROCESS_ALL_ACCESS, pUserInfo->User.Sid ) == FALSE )
			break;
		Log("GACCESS", "Step 7 done.\n");
		if( SetSecurityInfo( hProcess, SE_KERNEL_OBJECT, PROTECTED_DACL_SECURITY_INFORMATION | DACL_SECURITY_INFORMATION, 0, 0, pACL, 0 ) != ERROR_SUCCESS )
			break;
		Log("GACCESS", "Success!\n");
		break;
	}
	if (hToken)
		CloseHandle( hToken );
	if (pSid)
		FreeSid( pSid );
}

void DetourFunctions()
{
	HMODULE h = LoadLibraryA("WININET.dll");
	if(!FreeLibrary(h))
		Log("DFS", "Could not free WININET.dll!\n");
	h = LoadLibraryA("WININET.dll");
	if(h != NULL)
	{
		FARPROC proc = GetProcAddress(h, "HttpOpenRequestW");
		if(proc != NULL)
		{
			orgHttpOpenRequestW = (HTTPREQ)DetourFunction((LPBYTE)proc, (LPBYTE)myHttpOpenRequestW);
			Log("DFS", "HttpOpenRequestW detoured\n");
		}
	}
	h = LoadLibraryA("WINHTTP.dll");
	if(!FreeLibrary(h))
		Log("DFS", "Could not free WINHTTP.dll!\n");
	h = LoadLibraryA("WINHTTP.dll");
	if(h != NULL)
	{
		FARPROC proc = GetProcAddress(h, "WinHttpOpenRequest");
		if(proc != NULL)
		{
			orgWinHttpOpenRequest = (HTTPREQ2)DetourFunction((LPBYTE)proc, (LPBYTE)myWinHttpOpenRequest);
			Log("DFS", "WinHttpOpenRequest detoured\n");
		}
	}
}

void Init()
{
	int error;
	if((error = MH_Initialize()) != 0)
		Log("INIT", "MH_Initialize failed, error %d!!!\n", error);
	long long addr = (long long)VirtualAlloc(NULL, 0x1000, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE); 
	if(addr != 0)
	{
		Log("INIT", "New NtProtectVirtualMemory address = %llx\n", addr);
		memcpy((void*)addr, code1, sizeof(code1));
		xNtProtectVirtualMemory = (TNtProtectVirtualMemory)addr;
	}
	else
		Log("INIT", "VirtualAlloc failed\n");
	addr = (long long)VirtualAlloc(NULL, 0x1000, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE); 
	if(addr != 0)
	{
		Log("INIT", "New NtQueryVirtualMemory address = %llx\n", addr);
		memcpy((void*)addr, code2, sizeof(code2));
		xNtQueryVirtualMemory = (TNtQueryVirtualMemory)addr;
	}
	else
		Log("INIT", "VirtualAlloc failed\n");
	xNtQueryObject = (TNtQueryObject)GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtQueryObject");
	xZwCreateSection = (TZwCreateSection)GetProcAddress(GetModuleHandleA("ntdll.dll"), "ZwCreateSection");
	xZwUnmapViewOfSection = (TZwUnmapViewOfSection)GetProcAddress(GetModuleHandleA("ntdll.dll"), "ZwUnmapViewOfSection");
	xZwMapViewOfSection = (TZwMapViewOfSection)GetProcAddress(GetModuleHandleA("ntdll.dll"), "ZwMapViewOfSection");
	Log("INIT", "Test Nt function offsets: %p %p %p %p\n", xNtQueryObject, xZwCreateSection, xZwUnmapViewOfSection, xZwMapViewOfSection);
}

void DoPatching()
{	
	Init();
	TestProcessAccess();
	GrantAccess();
	TestProcessAccess();
	DetourFunctions();
}