#include <ntdef.h>
#include <processthreadsapi.h>
#include <stdio.h>
#include <windows.h>

char tramp_ntcreatesection[13] = {
	0x49, 0xBA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         // mov r10, NEW_LOC_@ddress
	0x41, 0xFF, 0xE2                                                    // jmp r10
};
char tramp_old_ntcreatesection[13];

// typedef ULONG ACCESS_MASK;

typedef NTSTATUS (WINAPI *myNtCreateSection)(
PHANDLE            SectionHandle,
ACCESS_MASK        DesiredAccess,
POBJECT_ATTRIBUTES ObjectAttributes,
PLARGE_INTEGER     MaximumSize,
ULONG              SectionPageProtection,
ULONG              AllocationAttributes,
HANDLE             FileHandle
);

BOOL hook_ntcreatesection(HANDLE hProc);

BOOL restore_hook_ntcreatesection(OUT PHANDLE SectionHandle, IN ULONG DesiredAccess, IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL, IN PLARGE_INTEGER MaximumSize OPTIONAL, IN ULONG PageAttributess, IN ULONG SectionAttributes, IN HANDLE FileHandle OPTIONAL)
{
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetCurrentProcessId()); //Open current process
	myNtCreateSection NtCreate;
	NtCreate = (PVOID)GetProcAddress(GetModuleHandle("NTDLL.dll"), "NtCreateSection"); //Get address of the hooked NtCreateSection
	DWORD written2, written3;


	VirtualProtect(NtCreate, sizeof NtCreate, PAGE_EXECUTE_READWRITE, &written2); //Protect it 
	VirtualProtect(tramp_old_ntcreatesection, sizeof tramp_old_ntcreatesection, PAGE_EXECUTE_READWRITE, &written3);

	if (!WriteProcessMemory(hProc, NtCreate, &tramp_old_ntcreatesection, sizeof tramp_old_ntcreatesection, NULL)) //Write the real NtCreateSection in the address of the hook
	{
		return FALSE;
	}
	NtCreate(SectionHandle, DesiredAccess, ObjectAttributes, MaximumSize, PageAttributess, SectionAttributes, FileHandle); //Call the real NtCreateSection
	hook_ntcreatesection(hProc); //hook it again
	return 1;

}

NTSTATUS ntCreateMySection(
	PHANDLE            SectionHandle,
	ACCESS_MASK        DesiredAccess,
	POBJECT_ATTRIBUTES ObjectAttributes,
	PLARGE_INTEGER     MaximumSize,
	ULONG              SectionPageProtection,
	ULONG              AllocationAttributes,
	HANDLE             FileHandle
) {
    printf("NtCreateMySection(SectionPageProtection=%lx, AllocationAttributes=%lx)\n", SectionPageProtection, AllocationAttributes);
    if (SectionPageProtection == 0x20) {
        SectionPageProtection = 0x40;
    }
	restore_hook_ntcreatesection(SectionHandle, DesiredAccess, ObjectAttributes,
		 MaximumSize, SectionPageProtection, AllocationAttributes, FileHandle);
	return 1;
}

BOOL hook_ntcreatesection(HANDLE hProc)
{
	myNtCreateSection NtCreate;
	NtCreate = (PVOID)GetProcAddress(GetModuleHandle("NTDLL.dll"), "NtCreateSection"); //GetProcAddress of NtCreateSection
	if (!NtCreate)
		exit(-1);
	DWORD written3;


	VirtualProtect(NtCreate, sizeof NtCreate, PAGE_EXECUTE_READWRITE, &written3); //Protect it 

	void* reference = (void*)ntCreateMySection; //pointer to ntCreateSection  (hook) in reference


	memcpy(tramp_old_ntcreatesection, NtCreate, sizeof tramp_old_ntcreatesection); //Copy the syscall of NtCreateSection (real) in a global variable
	memcpy(&tramp_ntcreatesection[2], &reference, sizeof reference); //Copy  the hook to tramp_ntcreatesection

	DWORD old3;

	VirtualProtect(tramp_ntcreatesection, sizeof tramp_ntcreatesection, PAGE_EXECUTE_READWRITE, &old3);


	if (!WriteProcessMemory(hProc, (LPVOID*)NtCreate, &tramp_ntcreatesection, sizeof tramp_ntcreatesection, NULL)) //Write the hook to the address of the NtCreateSection
	{
		return -1;
	}
	return 1;
}