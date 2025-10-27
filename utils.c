#include "utils.h"
#include "TimeString.h"
#include "sds_utf_conv.h"

#include <jansson.h>
#include <sds.h>

#include <windows.h>

#include <stdio.h>

sds SlurpFile(const char *path) {    
    HANDLE hFile = CreateFileA(
        path, GENERIC_READ, FILE_SHARE_READ,
        NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        fputs("CreateFileA failed\n", stdout);
        return NULL;
    }

    LARGE_INTEGER size;

    if (!GetFileSizeEx(hFile, &size)) {
        fputs("GetFileSizeEx failed\n", stdout);
        return NULL;
    }

    sds res = sdsnewlen(NULL, size.QuadPart);

    unsigned long numberOfBytesRead;

    if (!ReadFile(hFile, res, size.QuadPart, &numberOfBytesRead, NULL)) {
        printf("ReadFile failed\n");
        sdsfree(res);
        return NULL;
    }

    if (numberOfBytesRead < size.QuadPart) {
        printf("Read less than the size of the file\n");
        sdsfree(res);
        return NULL;
    }
    
    return res;
}

int ChangeLoggedInAt(json_t *root, const char *newValue) {
    json_t *changedResources = json_object_get(root, "changedResources");

    if (!changedResources) {
        printf("Failed to get changedResources\n");
        return -1;
    }

    json_t *status = json_object_get(changedResources, "status");

    if (!status) {
        printf("Failed to get status\n");
        return -1;
    }

    if (json_object_set_new(status, "loggedInAt", json_string(newValue)) < 0) {
        printf("Failed to set new value\n");
        return -1;
    }

    return 0;
}

char *ChangeLoggedInAtStr(sds data, const char *newValue) {
    json_t *json = json_loads(data, 0, NULL);
    if (!data) {
        printf("json_loads failed\n");
        return NULL;
    }

    if (ChangeLoggedInAt(json, newValue) < 0) {
        return NULL;
    }

    char *res = json_dumps(json, JSON_INDENT(2));
    
    if (!res) {
        printf("json_dumps failed\n");
        return NULL;
    }

    return res;
}

void PutString(System_String_o *s) {
    int32_t sLen = s->fields._stringLength;
    uint16_t *firstChar = &(s->fields._firstChar);
    for (int32_t i = 0; i < sLen; ++i) {
        putchar((uint8_t)(firstChar[i]));
    }
    putchar('\n');
}

sds System_String_toSds(System_String_o *s) {
    return sds16to8(&(s->fields._firstChar), s->fields._stringLength);
}