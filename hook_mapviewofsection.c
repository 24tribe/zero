#include "hook_mapviewofsection.h"

#include <ntdef.h>
#include <processthreadsapi.h>

#include <stdio.h>

char tramp_ntmapviewofsection[13] = {
	0x49, 0xBA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         // mov r10, NEW_LOC_@ddress
	0x41, 0xFF, 0xE2                                                    // jmp r10
};
char tramp_old_ntmapviewofsection[13];

enum InheritDisposition {
    ViewShare=1,
    ViewUnmap=2
};

typedef NTSTATUS (WINAPI *NTMAPVIEWOFSECTION)(
  IN HANDLE               SectionHandle,
  IN HANDLE               ProcessHandle,
  IN OUT PVOID            *BaseAddress OPTIONAL,
  IN ULONG                ZeroBits OPTIONAL,
  IN ULONG                CommitSize,
  IN OUT PLARGE_INTEGER   SectionOffset OPTIONAL,
  IN OUT PULONG           ViewSize,
  IN ULONG  InheritDisposition,
  IN ULONG                AllocationType OPTIONAL,
  IN ULONG                Protect
);



#define FUNC_STR "NtMapViewOfSection"

BOOL restore_hook_ntmapviewofsection(
    IN HANDLE               SectionHandle,
    IN HANDLE               ProcessHandle,
    IN OUT PVOID            *BaseAddress OPTIONAL,
    IN ULONG                ZeroBits OPTIONAL,
    IN ULONG                CommitSize,
    IN OUT PLARGE_INTEGER   SectionOffset OPTIONAL,
    IN OUT PULONG           ViewSize,
    IN ULONG InheritDisposition,
    IN ULONG                AllocationType OPTIONAL,
    IN ULONG                Protect
) {
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetCurrentProcessId()); //Open current process
	NTMAPVIEWOFSECTION fpNtMapViewOfSection;
	fpNtMapViewOfSection = (PVOID)GetProcAddress(GetModuleHandle("NTDLL.dll"), FUNC_STR); //Get address of the hooked NtCreateSection
	DWORD written2, written3;


	VirtualProtect(fpNtMapViewOfSection, sizeof fpNtMapViewOfSection, PAGE_EXECUTE_READWRITE, &written2); //Protect it 
	VirtualProtect(tramp_old_ntmapviewofsection, sizeof tramp_old_ntmapviewofsection, PAGE_EXECUTE_READWRITE, &written3);

	if (!WriteProcessMemory(hProc, fpNtMapViewOfSection, &tramp_old_ntmapviewofsection, sizeof tramp_old_ntmapviewofsection, NULL)) //Write the real NtCreateSection in the address of the hook
	{
		return FALSE;
	}
	fpNtMapViewOfSection(
        SectionHandle, ProcessHandle,BaseAddress ,ZeroBits,CommitSize,SectionOffset, ViewSize,
        InheritDisposition,AllocationType, Protect
    ); //Call the real NtCreateSection
	hook_ntmapviewofsection(hProc); //hook it again
	return 1;

}

NTSTATUS DetourNtMapViewOfSection(
    IN HANDLE               SectionHandle,
    IN HANDLE               ProcessHandle,
    IN OUT PVOID            *BaseAddress OPTIONAL,
    IN ULONG                ZeroBits OPTIONAL,
    IN ULONG                CommitSize,
    IN OUT PLARGE_INTEGER   SectionOffset OPTIONAL,
    IN OUT PULONG           ViewSize,
    IN ULONG InheritDisposition,
    IN ULONG                AllocationType OPTIONAL,
    IN ULONG                Protect
) {
    // printf("NtMapViewOfSection(Protect=%lx)\n", Protect);
    Protect = PAGE_WRITECOPY;
    
	restore_hook_ntmapviewofsection(
        SectionHandle, ProcessHandle,BaseAddress ,ZeroBits,CommitSize,SectionOffset, ViewSize,
        InheritDisposition,AllocationType, Protect
    );
	return 1;
}

BOOL hook_ntmapviewofsection(HANDLE hProc)
{
	NTMAPVIEWOFSECTION fpNtMapViewOfSection;
	fpNtMapViewOfSection = (PVOID)GetProcAddress(GetModuleHandle("NTDLL.dll"), FUNC_STR); //GetProcAddress of NtCreateSection
	if (!fpNtMapViewOfSection)
		exit(-1);
	DWORD written3;


	VirtualProtect(fpNtMapViewOfSection, sizeof fpNtMapViewOfSection, PAGE_EXECUTE_READWRITE, &written3); //Protect it 

	void* reference = (void*)DetourNtMapViewOfSection; //pointer to ntCreateSection  (hook) in reference


	memcpy(tramp_old_ntmapviewofsection, fpNtMapViewOfSection, sizeof tramp_old_ntmapviewofsection); //Copy the syscall of NtCreateSection (real) in a global variable
	memcpy(&tramp_ntmapviewofsection[2], &reference, sizeof reference); //Copy  the hook to tramp_ntmapviewofsection

	DWORD old3;

	VirtualProtect(tramp_ntmapviewofsection, sizeof tramp_ntmapviewofsection, PAGE_EXECUTE_READWRITE, &old3);


	if (!WriteProcessMemory(hProc, (LPVOID*)fpNtMapViewOfSection, &tramp_ntmapviewofsection, sizeof tramp_ntmapviewofsection, NULL)) //Write the hook to the address of the NtCreateSection
	{
		return -1;
	}
	return 1;
}