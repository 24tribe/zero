#include "MetadataDump.h"

#include <windows.h>
#include <fileapi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fputs("Usage: metadata_test.exe metadata.dat\n", stderr);
        return 1;
    }

    char *metadata_path = argv[1];

    long long size = GetMetadataSize(metadata_path);

    if (size == LLONG_MAX) {
        printf("GetMetadataSize failed\n");
        return 1;
    }
    
    printf("Size: 0x%lld\n", size);

    if (size > (long long)LONG_MAX) {
        printf("Size doesnt fit in a long\n");
        return 1;
    }

    unsigned long smallSize = (unsigned long)size;

    HANDLE hMetadata = CreateFileA(
        metadata_path, GENERIC_READ, FILE_SHARE_READ, 
        NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
    );

    if (hMetadata == INVALID_HANDLE_VALUE) {
        fputs("Failed to open metadata\n", stdout);
        return 1;
    }

    char *buf = malloc(size);

    if (!buf) {
        fputs("Malloc failed\n", stdout);
        return 1;
    }

    unsigned long numberOfBytesRead;

    if (!ReadFile(hMetadata, buf, smallSize, &numberOfBytesRead, NULL)) {
        printf("ReadFile failed\n");
        return 1;
    }

    if (numberOfBytesRead < smallSize) {
        printf("Read less than the size of the file\n");
        return 1;
    }

    if (IsMetadata((BYTE *)buf)) {
        printf("Got metadata\n");
        if (SaveMetadata("metadata.dat", (BYTE *)buf, size)) {
            printf("SaveMetadata Success\n");
        } else {
            printf("SaveMEtadata Failed\n");
        }
    } else {
        printf("The file is not metadata\n");
    }

    free(buf);
}