#ifndef METADATA_DUMP_H_20252806011800
#define METADATA_DUMP_H_20252806011800

#include <windows.h>

#include <stdbool.h>

extern long long GetMetadataSize(char *path);
extern bool SaveMetadata(char *path, BYTE *buf, unsigned long size);
extern bool IsMetadata(BYTE *buf);
extern BYTE *ReadMetadata(const char *filename, unsigned long smallSize) ;

#endif