#include "il2cpp_lean.h"
#include "utils.h"

#include <sds.h>

#include <sysinfoapi.h>

#include <wchar.h>
#include <stdio.h>

#define STACKTRACES_PATH "stacktraces"

typedef System_String_o *(*System_Diagnostics_StackTrace_toString)(System_Diagnostics_StackTrace_o *, const MethodInfo *);
typedef void (*STACKTRACECONSTRUCTOR)(System_Diagnostics_StackTrace_o* __this, const MethodInfo* method);
STACKTRACECONSTRUCTOR System_Diagnostics_StackTrace_ctor = NULL;
Il2CppClass **System_Diagnostics_StackTrace_TypeInfo = NULL;

void InitStackTraceLogger(void *GameAssembly) {
    System_Diagnostics_StackTrace_TypeInfo = (Il2CppClass **)((unsigned long long)GameAssembly + 129545976ull);
    System_Diagnostics_StackTrace_ctor = (STACKTRACECONSTRUCTOR)((unsigned long long)GameAssembly + 55774032ull);
}

System_String_o *GetStackTrace() {
    System_Diagnostics_StackTrace_o *stackTrace;
    stackTrace = (System_Diagnostics_StackTrace_o *)il2cpp_object_new(*System_Diagnostics_StackTrace_TypeInfo);
    System_Diagnostics_StackTrace_ctor(stackTrace, NULL);

    VirtualInvokeData *toString = &(stackTrace->klass->vtable._3_ToString);
    System_Diagnostics_StackTrace_toString toStringFunc;
    toStringFunc = (System_Diagnostics_StackTrace_toString)(uintptr_t)(toString->methodPtr);
    System_String_o *stackTraceStr = toStringFunc(stackTrace, toString->method);
    return stackTraceStr;
}

void EscapeSymbols(char *s) {
    while (*s) {
        if (!isalpha(*s)) {
            *s++ = '_';
        } else {
            s++;
        }
    }
}

sds GetTime() {
    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);
    return sdscatprintf(
        sdsempty(),
        "%d_%d_%d_%d_%d_%d",
        (int)systemTime.wYear,
        (int)systemTime.wMonth,
        (int)systemTime.wDay,
        (int)systemTime.wHour,
        (int)systemTime.wMinute,
        (int)systemTime.wSecond
    );
}

sds CreateStackTracePath(const char *url) {
    sds myUrl = sdsnew(url);
    EscapeSymbols(myUrl);

    sds res = sdscatprintf(
        sdsempty(),
        "%s/%s.txt",
        STACKTRACES_PATH,
        myUrl
    );

    sdsfree(myUrl);

    return res;
}

void SaveStackTrace(sds url) {
    sds path = CreateStackTracePath(url);

    FILE *fpRead = fopen(path, "rb");
    
    if (fpRead) {
        fclose(fpRead);
        return;
    } 

    System_String_o *stackTrace = GetStackTrace();

    sds stackTraceUtf8 = sds16to8(&(stackTrace->fields._firstChar), stackTrace->fields._stringLength);

    FILE *fp = fopen(path, "wb");
    if (!fp) {
        printf("Failed to open stacktrace file: %s\n", path);
        return;
    }
    fwrite(stackTraceUtf8, 1, sdslen(stackTraceUtf8), fp);
    fflush(fp);
    fclose(fp);
}