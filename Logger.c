#include "il2cpp_lean.h"
#include "utils.h"
#include "TimeString.h"

#include <sds.h>
#include <jansson.h>

#include <wchar.h>
#include <stdio.h>
#include <inttypes.h>

#define STACKTRACES_PATH "stacktraces"
#define RESPONSES_PATH "responses"

typedef System_String_o *(*System_Diagnostics_StackTrace_toString)(System_Diagnostics_StackTrace_o *, const MethodInfo *);
typedef void (*STACKTRACECONSTRUCTOR)(System_Diagnostics_StackTrace_o* __this, const MethodInfo* method);
typedef System_String_o *(*object_toString)(Il2CppObject *, const MethodInfo *);

STACKTRACECONSTRUCTOR System_Diagnostics_StackTrace_ctor = NULL;
Il2CppClass **System_Diagnostics_StackTrace_TypeInfo = NULL;

void InitLogger(void *GameAssembly) {
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

sds CreateResponsePath(const char *className) {
    sds myClassName = sdsnew(className);

    sds timeNow = GetTime();
    
    sds res = sdscatprintf(sdsempty(), "%s/%s_%s.txt", RESPONSES_PATH, timeNow, myClassName);

    sdsfree(timeNow);

    sdsfree(myClassName);

    return res;
}

void SaveStackTrace(sds url) {
    printf("[SaveStackTrace] %s\n", url);

    sds path = CreateStackTracePath(url);

    FILE *fpRead = fopen(path, "rb");
    
    if (fpRead) {
        fclose(fpRead);
        return;
    } 

    System_String_o *stackTrace = GetStackTrace();

    sds stackTraceUtf8 = sds16to8(&(stackTrace->fields._firstChar), stackTrace->fields._stringLength);

    FILE *fp = fopen(path, "wb");

    if (fp) {
        fwrite(stackTraceUtf8, 1, sdslen(stackTraceUtf8), fp);
        fflush(fp);
        fclose(fp);
    } else {
        printf("Failed to open stacktrace file: %s\n", path);
    }

    sdsfree(stackTraceUtf8);
}

void GetNameAndNamespaze(Il2CppObject *obj, const char **name, const char **namespaze) {
    *name = "";
    *namespaze = "";

    if (obj) {
        Il2CppClass *klass = obj->klass;
    
        if (klass) {
            *name = klass->_1.name;
            *namespaze = klass->_1.namespaze;
        }
    }
}

System_String_o *ConvertObjectToString(Il2CppObject *obj) {
    object_toString toString = (object_toString)(uintptr_t)(obj->klass->vtable[3 /* _3_toString*/].methodPtr);
    return toString(obj, obj->klass->vtable[3 /* _3_toString*/].method);
}

void LogResponse(Il2CppObject *obj) {
    const char *name;
    const char *namespaze;

    GetNameAndNamespaze(obj, &name, &namespaze);

    if (!strcmp(namespaze, "Neon.Model.Api.Rpc")) {
        printf("[LogResponse] Name='%s', Namespace='%s'\n", name, namespaze);
        
        System_String_o *objStr = ConvertObjectToString(obj);
        sds objJson = sds16to8(&(objStr->fields._firstChar), objStr->fields._stringLength);
        
        json_t *data = json_loads(objJson, 0, NULL);
        
        if (!data) {
            printf("json_loads failed!\n");
            return;
        }

        sdsfree(objJson);

        char *dataPretty = json_dumps(data, JSON_INDENT(2));

        json_decref(data);

        if (!dataPretty) {
            printf("jansson_dumps failed\n");
            return;
        }

        sds responsePath = CreateResponsePath(name);

        FILE *fp = fopen(responsePath, "wb");

        sdsfree(responsePath);

        if (fp) {
            fputs(dataPretty, fp);
            fflush(fp);
            fclose(fp);
        } else {
            printf("fopen failed!\n");
        }

        free(dataPretty);        
    }
}