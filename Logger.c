#include "il2cpp_lean.h"
#include "utils.h"
#include "TimeString.h"
#include "sds_utf_conv.h"

#include <sds.h>
#include <jansson.h>

#include <wchar.h>
#include <stdio.h>
#include <inttypes.h>

#include "funcPtrs.h"

typedef System_String_o *(*System_Diagnostics_StackTrace_toString)(System_Diagnostics_StackTrace_o *, const MethodInfo *);
typedef System_String_o *(*object_toString)(Il2CppObject *, const MethodInfo *);

System_String_o *GetStackTrace(void) {
    System_Diagnostics_StackTrace_o *stackTrace;
    stackTrace = (System_Diagnostics_StackTrace_o *)il2cpp_object_new(*System_Diagnostics_StackTrace_TypeInfo);
    System_Diagnostics_StackTrace___ctor(stackTrace, NULL);

    VirtualInvokeData *toString = &(stackTrace->klass->vtable._3_ToString);
    System_Diagnostics_StackTrace_toString toStringFunc;
    toStringFunc = (System_Diagnostics_StackTrace_toString)(uintptr_t)(toString->methodPtr);
    System_String_o *stackTraceStr = toStringFunc(stackTrace, toString->method);
    return stackTraceStr;
}

System_String_o *ConvertObjectToString(Il2CppObject *obj) {
    object_toString toString = (object_toString)(uintptr_t)(obj->klass->vtable[3 /* _3_toString*/].methodPtr);
    return toString(obj, obj->klass->vtable[3 /* _3_toString*/].method);
}