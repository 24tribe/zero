#include "QueryDirectoryData.h"

#include <MinHook.h>

#include <ntdef.h>
#include <windows.h>

#include <stdio.h>
#include <stdbool.h>

typedef struct _IO_STATUS_BLOCK
{
    union
    {
        NTSTATUS Status;
        PVOID Pointer;
    };
    ULONG_PTR Information;
} IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;

typedef VOID (NTAPI *PIO_APC_ROUTINE)(
    _In_ PVOID ApcContext,
    _In_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_ ULONG Reserved
);

typedef enum _FILE_INFORMATION_CLASS
 {
     FileDirectoryInformation = 1,
     FileFullDirectoryInformation,
     FileBothDirectoryInformation,
     FileBasicInformation,
     FileStandardInformation,
     FileInternalInformation,
     FileEaInformation,
     FileAccessInformation,
     FileNameInformation,
     FileRenameInformation, // 10
     FileLinkInformation,
     FileNamesInformation,
     FileDispositionInformation,
     FilePositionInformation,
     FileFullEaInformation,
     FileModeInformation,
     FileAlignmentInformation,
     FileAllInformation,
     FileAllocationInformation,
     FileEndOfFileInformation, // 20
     FileAlternateNameInformation,
     FileStreamInformation,
     FilePipeInformation,
     FilePipeLocalInformation,
     FilePipeRemoteInformation,
     FileMailslotQueryInformation,
     FileMailslotSetInformation,
     FileCompressionInformation,
     FileObjectIdInformation,
     FileCompletionInformation, // 30
     FileMoveClusterInformation,
     FileQuotaInformation,
     FileReparsePointInformation,
     FileNetworkOpenInformation,
     FileAttributeTagInformation,
     FileTrackingInformation,
     FileIdBothDirectoryInformation,
     FileIdFullDirectoryInformation,
     FileValidDataLengthInformation,
     FileShortNameInformation, // 40
     FileIoCompletionNotificationInformation,
     FileIoStatusBlockRangeInformation,
     FileIoPriorityHintInformation,
     FileSfioReserveInformation,
     FileSfioVolumeInformation,
     FileHardLinkInformation,
     FileProcessIdsUsingFileInformation,
     FileNormalizedNameInformation,
     FileNetworkPhysicalNameInformation,
     FileIdGlobalTxDirectoryInformation, // 50
     FileIsRemoteDeviceInformation,
     FileUnusedInformation,
     FileNumaNodeInformation,
     FileStandardLinkInformation,
     FileRemoteProtocolInformation,
     FileRenameInformationBypassAccessCheck, // (kernel-mode only) // since WIN8
     FileLinkInformationBypassAccessCheck, // (kernel-mode only)
     FileIntegrityStreamInformation,
     FileVolumeNameInformation,
     FileIdInformation,
     FileIdExtdDirectoryInformation,
     FileReplaceCompletionInformation, // since WINBLUE
     FileHardLinkFullIdInformation,
     FileIdExtdBothDirectoryInformation, // since THRESHOLD
     FileMaximumInformation
 } FILE_INFORMATION_CLASS, *PFILE_INFORMATION_CLASS;

typedef NTSTATUS (NTAPI *NTQUERYDIRECTORYFILE)(
    HANDLE                 FileHandle,
    HANDLE                 Event,
    PIO_APC_ROUTINE        ApcRoutine,
    PVOID                  ApcContext,
    PIO_STATUS_BLOCK       IoStatusBlock,
    PVOID                  FileInformation,
    ULONG                  Length,
    FILE_INFORMATION_CLASS FileInformationClass,
    BOOLEAN                ReturnSingleEntry,
    PUNICODE_STRING        FileName,
    BOOLEAN                RestartScan
);

NTQUERYDIRECTORYFILE fpNtQueryDirectoryFile = NULL;

#define MY_PATH_SIZE 4096

void ByteToStr(
     DWORD cb, 
     void* pv, 
     LPSTR out)

     
//--------------------------------------------------------------------
// Parameters passed are:
//    pv is the array of BYTES to be converted.
//    cb is the number of BYTEs in the array.
//    sz is a pointer to the string to be returned.

{
//--------------------------------------------------------------------
//  Declare and initialize local variables.
LPSTR sz = out;
BYTE* pb = (BYTE*) pv; // local pointer to a BYTE in the BYTE array
DWORD i;               // local loop counter
int b;                 // local variable

//--------------------------------------------------------------------
//  Begin processing loop.

for (i = 0; i<cb; i++)
{
   b = (*pb & 0xF0) >> 4;
   *sz++ = (b <= 9) ? b + '0' : (b - 10) + 'A';
   b = *pb & 0x0F;
   *sz++ = (b <= 9) ? b + '0' : (b - 10) + 'A';
   pb++;
}
*sz++ = 0;
}

bool firstTime = true;

#define STATUS_NO_MORE_FILES 0x80000006UL

NTAPI NTSTATUS DetourNtQueryDirectoryFile(
    HANDLE                 FileHandle,
    HANDLE                 Event,
    PIO_APC_ROUTINE        ApcRoutine,
    PVOID                  ApcContext,
    PIO_STATUS_BLOCK       IoStatusBlock,
    PVOID                  FileInformation,
    ULONG                  Length,
    FILE_INFORMATION_CLASS FileInformationClass,
    BOOLEAN                ReturnSingleEntry,
    PUNICODE_STRING        FileName,
    BOOLEAN                RestartScan
) {
    char buf[MY_PATH_SIZE] = {0};
    char *path;
    if (GetFinalPathNameByHandleA(FileHandle, buf, MY_PATH_SIZE, 0)) {
        path = buf;
    } else {
        printf("GetFinalPathByHandleA failed\n");
        path = "?";
    }

    NTSTATUS res = fpNtQueryDirectoryFile(
        FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock,
        FileInformation, Length, FileInformationClass, ReturnSingleEntry,
        FileName, RestartScan
    );

    if (!strcmp(path, "\\\\?\\D:\\SteamLibrary\\steamapps\\common\\TRIBENINE")) {
        if (ApcRoutine || ApcContext || Event || FileName) {
            printf("Weird: ApcRoutine, ApcContext, Event and FileName should be NULL\n");
            return res;
        }
        if (ReturnSingleEntry || RestartScan) {
            printf("Weird: ReturnSingleEntry and RestartScan should be false\n");
            return res;
        }
        if (FileInformationClass != FileFullDirectoryInformation) {
            printf("Weird: FileInfomationClass should be FileFullDirectoryInformation\n");
            return res;
        }

        if (Length != 4096) {
            printf("Weird: Length should be 4096\n");
            return res;
        }
        printf("NQDF Path: %s\n", path);

        if (firstTime) {
            memcpy(FileInformation, QueryDirectoryData, QueryDirectoryDataLength);
            IoStatusBlock->Status = 0;
            IoStatusBlock->Information = 0x58a;
            firstTime = false;
            return 0;
        } else {
            IoStatusBlock->Status = STATUS_NO_MORE_FILES;
            IoStatusBlock->Information = 0;
            return STATUS_NO_MORE_FILES;
        }
    }

    return res;    
}

void HookNtQueryDirectoryFile() {
    NTQUERYDIRECTORYFILE NtQueryDirectoryFile = (void *)GetProcAddress(
        GetModuleHandle("NTDLL.dll"), "NtQueryDirectoryFile"
    );

    printf("NtQueryDirectoryFile: %p\n", (void*)NtQueryDirectoryFile);

    if (MH_CreateHook(
        NtQueryDirectoryFile, &DetourNtQueryDirectoryFile, (PVOID *)&fpNtQueryDirectoryFile
    ) != MH_OK) {
        printf("CreateHook NtQueryDirectoryFile failed\n");
        return;
    }

    if (MH_EnableHook(NtQueryDirectoryFile, TRUE) != MH_OK) {
        printf("MH_EnableHook NtQueryDirectoryFile failed\n");
        return;
    }
}