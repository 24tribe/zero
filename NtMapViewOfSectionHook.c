#include <MinHook.h>

#include <ntdef.h>
#include <windows.h>

typedef NTSTATUS (WINAPI *NTMAPVIEWOFSECTION)(
    IN HANDLE               SectionHandle,
    IN HANDLE               ProcessHandle,
    IN OUT PVOID            *BaseAddress OPTIONAL,
    IN ULONG                ZeroBits OPTIONAL,
    IN ULONG                CommitSize,
    IN OUT PLARGE_INTEGER   SectionOffset OPTIONAL,
    IN OUT PULONG           ViewSize,
    IN ULONG                InheritDisposition,
    IN ULONG                AllocationType OPTIONAL,
    IN ULONG                Protect
);

NTMAPVIEWOFSECTION fpNtMapViewOfSection = NULL;

NTSTATUS WINAPI DetourNtMapViewOfSection(
    IN HANDLE               SectionHandle,
    IN HANDLE               ProcessHandle,
    IN OUT PVOID            *BaseAddress OPTIONAL,
    IN ULONG                ZeroBits OPTIONAL,
    IN ULONG                CommitSize,
    IN OUT PLARGE_INTEGER   SectionOffset OPTIONAL,
    IN OUT PULONG           ViewSize,
    IN ULONG                InheritDisposition,
    IN ULONG                AllocationType OPTIONAL,
    IN ULONG                Protect
) {
    printf("Protect: %lx\n", Protect);
    return fpNtMapViewOfSection(SectionHandle, ProcessHandle, BaseAddress, ZeroBits,
                                CommitSize, SectionOffset, ViewSize,
                                InheritDisposition, AllocationType, Protect);
}

void HookNtMapViewOfSection() {
    NTMAPVIEWOFSECTION original = 
    if (MH_CreateHook(NtMapViewOfSection, ))
}