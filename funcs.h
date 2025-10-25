#ifndef FUNCS_H_06152025_MINAMO
#define FUNCS_H_06152025_MINAMO

#include <windows.h>
#include <ntdef.h>

PIMAGE_NT_HEADERS NTAPI RtlImageNtHeader(IN PVOID ModuleAddress);

NTSTATUS NTAPI NtUnmapViewOfSection(HANDLE  ProcessHandle, PVOID   BaseAddress);

NTSTATUS NTAPI NtCreateSection( 
     PHANDLE SectionHandle, 
     ACCESS_MASK DesiredAccess, 
       POBJECT_ATTRIBUTES ObjectAttributes, 
       PLARGE_INTEGER MaximumSize, 
   ULONG SectionPageProtection, 
    ULONG AllocationAttributes, 
  HANDLE FileHandle );


NTSTATUS NTAPI NtMapViewOfSection( 
  HANDLE SectionHandle, 
 HANDLE ProcessHandle, 
    PVOID *BaseAddress, 
    ULONG_PTR ZeroBits, 
   SIZE_T CommitSize, 
  PLARGE_INTEGER SectionOffset, 
  PSIZE_T ViewSize, 
  UINT InheritDisposition, 
 ULONG AllocationType, 
  ULONG Win32Protect );

#define NtCurrentProcess()  ((HANDLE)(LONG_PTR)-1)

#endif