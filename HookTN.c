/*
References:
[UniTaskCompletionSource example](https://github.com/Cysharp/UniTask)
[TaskCompletionSource explanation](https://stackoverflow.com/questions/27891253/how-to-create-a-task-i-can-complete-manually)
[Task.ContinueWith example](https://stackoverflow.com/questions/8244428/where-to-define-callback-for-task-based-asynchronous-method)
[Task.ContinueWith docs](https://learn.microsoft.com/en-us/dotnet/api/system.threading.tasks.task.continuewith)
[Delegate type](https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/reference-types#the-delegate-type)
[Task.FromResult](https://stackoverflow.com/questions/19568280/what-is-the-use-for-task-fromresulttresult)
[How Async and Await works](https://www.jacksondunstan.com/articles/4918)
*/

#include "HookTN.h"
#include "il2cpp_lean.h"
#include "utils.h"
#include "Logger.h"
#include "Il2CppHelper.h"
#include "Config.h"
#include "TimeString.h"
#include "NimInit.h"
#include "Patterns.h"

#include <MinHook.h>
#include <sds.h>
#include <semba.h>

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include "funcPtrs.h"

sds neonApiPath = NULL;

#define AUTOHOOK_TN_IMPL
#include "autohookTN.h"

struct ResponseTypeToRequestPtr {
    char *responseType;
    Il2CppObject **requestPtr;
    char *uriPath;
};

struct ResponseTypeToRequestPtr_List {
    int64_t len;
    struct ResponseTypeToRequestPtr *data;
};

#define STATIC_ARRAY_LEN(a) (sizeof a/sizeof *a)

struct ResponseTypeToRequestPtr RES_TYPE_TO_REQ_PTR_LIST_DATA[] = {
    AUTOHOOK_TN_LIST_DATA
};

struct ResponseTypeToRequestPtr_List RES_TYPE_TO_REQ_PTR_LIST = {
    .len = STATIC_ARRAY_LEN(RES_TYPE_TO_REQ_PTR_LIST_DATA),
    .data = RES_TYPE_TO_REQ_PTR_LIST_DATA
};

KBJLHEAOHMD__KPFFCLMEMEG_FuncPtr fpKbjlheaohmd__Kpffclmemeg = NULL;

bool DetourKbjlheaohmd__Kpffclmemeg(System_DateTime_o HKIOCIMKCCP, System_DateTime_o CJKBFINFMNP, const MethodInfo* method) {
    if (HKIOCIMKCCP.fields._dateData == 0) {
        return false;
    }

    return fpKbjlheaohmd__Kpffclmemeg(HKIOCIMKCCP, CJKBFINFMNP, method);
}

void HookKbjlheaohmd__Kpffclmemeg(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)KBJLHEAOHMD__KPFFCLMEMEG,
        (LPVOID)(uintptr_t)&DetourKbjlheaohmd__Kpffclmemeg,
        (LPVOID *)(&fpKbjlheaohmd__Kpffclmemeg)
    ) != MH_OK) {
        fputs("Failed to create Kbjlheaohmd__Kpffclmemeg hook\n", stdout);
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)KBJLHEAOHMD__KPFFCLMEMEG, /* changePermissions = */ FALSE) != MH_OK) {
        fputs("Failed to enable Kbjlheaohmd__Kpffclmemeg hook\n", stdout);
        return;
    }
}

void SaveNeonApiPath(sds url) {
    if (!strstr(url, "https://game.tribenine-game.com")) {
        return;
    }

    int baseUrlSize = 31; // len("https://game.tribenine-game.com") == 31

    neonApiPath = sdsnew(url + baseUrlSize);
}

System_Uri_o *CreateSystemUri(char *s) {
    System_Uri_o *uri = (System_Uri_o *)il2cpp_object_new(*System_Uri_TypeInfo);
    System_Uri___ctor(uri, il2cpp_string_new(s), NULL);
    return uri;
}

Best_HTTP_HTTPRequest___ctor_FuncPtr fpHTTPRequestCtor = NULL;

void DetourHTTPRequestCtor(Best_HTTP_HTTPRequest_o* __this, System_Uri_o* uri, int32_t methodType, const MethodInfo* method) {
    sds url = System_String_toSds(uri->fields.m_String);
    printf("[DetourHttpRequestCtor] %s\n", url);
    if (ZERO_CONFIG.offlineMode) {
        uri = CreateSystemUri("https://httpbin.org/status/500");
    }
    SaveNeonApiPath(url);
    SaveStackTrace(url);
    sdsfree(url);
    fpHTTPRequestCtor(__this, uri, methodType, method);
}

void HookHTTPRequestCtor(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)Best_HTTP_HTTPRequest___ctor,
        (LPVOID)(uintptr_t)&DetourHTTPRequestCtor, (LPVOID *)(&fpHTTPRequestCtor)
    ) != MH_OK) {
        fputs("Failed to create HTTPRequestCtor hook\n", stdout);
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)Best_HTTP_HTTPRequest___ctor, /* changePermissions = */ FALSE) != MH_OK) {
        fputs("Failed to enable HTTPRequestCtor hook\n", stdout);
        return;
    }
}

sds GetFqnFromClass(Il2CppClass *klass) {
    sds res = NULL;

    if (klass) {
        const char *name = il2cpp_class_get_name(klass);
        const char *namespaze = il2cpp_class_get_namespace(klass);
        if (name && namespaze) {
            res = sdscatprintf(sdsempty(), "%s.%s", namespaze, name);
        }
    }

    return res;
}

struct ResponseTypeToRequestPtr *findResTypeToReqPtrFromUriFuzzy(char *uri) {
    re_t pat = GetFuzzyApiPattern();

    struct ResponseTypeToRequestPtr *end = RES_TYPE_TO_REQ_PTR_LIST.data + RES_TYPE_TO_REQ_PTR_LIST.len;
    struct ResponseTypeToRequestPtr *it;
    for (it = RES_TYPE_TO_REQ_PTR_LIST.data; it != end; ++it) {
        if (RegexEqualMatches(pat, uri, it->uriPath)) {
            return it;
        }
    }

    return NULL;
}

struct ResponseTypeToRequestPtr *findResTypeToReqPtrFromUri(char *uri) {
    struct ResponseTypeToRequestPtr *end = RES_TYPE_TO_REQ_PTR_LIST.data + RES_TYPE_TO_REQ_PTR_LIST.len;
    struct ResponseTypeToRequestPtr *it;
    for (it = RES_TYPE_TO_REQ_PTR_LIST.data; it != end; ++it) {
        if (!strcmp(uri, it->uriPath)) {
            return it;
        }
    }

    return NULL;
}

Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object___GetResult_FuncPtr fpSourceCore_GetResult = NULL;

Il2CppObject *DetourSourceCore_GetResult(
    Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__o __this,
    int16_t token,
    const MethodInfo_20B62E0* method
) {
    RunNimMainOnce();

    Il2CppClass *klass = il2cpp_type_get_class_or_element_class(method->return_type);

    Il2CppObject *res = fpSourceCore_GetResult(__this, token, method);

    sds fqn = GetFqnFromClass(klass);

    if (neonApiPath && fqn && strstr(fqn, "Neon.Model.Api.Rpc")) {
        printf("[DetourSourceCore_GetResult] %s\n", fqn);

        sds jsonRes;
        if (res) {
            jsonRes = System_String_toSds(ConvertObjectToString((Il2CppObject *)res));
        } else {
            jsonRes = sdsempty();
        }

        struct ResponseTypeToRequestPtr *resTypeToReqPtr = findResTypeToReqPtrFromUriFuzzy(neonApiPath);
        sds jsonReq;
        if (resTypeToReqPtr) {
            if (resTypeToReqPtr->requestPtr) {
                jsonReq = System_String_toSds(ConvertObjectToString(*resTypeToReqPtr->requestPtr));
                *resTypeToReqPtr->requestPtr = NULL;
            } else {
                jsonReq = sdsempty();
            }
        } else {
            printf("WARNING: %s not found in resTypeToReq list!\n", neonApiPath);
            jsonReq = sdsempty();
        }

        SembaLogFlow(neonApiPath, jsonReq, jsonRes);    
        sdsfree(neonApiPath);
        neonApiPath = NULL;
        sdsfree(jsonReq);
        sdsfree(jsonRes);
    }

    return res;
}

void HookSourceCore_GetResult(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object___GetResult,
        (LPVOID)(uintptr_t)&DetourSourceCore_GetResult,
        (LPVOID *)(&fpSourceCore_GetResult)
    ) != MH_OK) {
        fputs("Failed to create SourceCore_GetResult hook\n", stdout);
        return;
    }

    if (MH_EnableHook(
        (void *)(uintptr_t)Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object___GetResult,
        /* changePermissions = */ FALSE
    ) != MH_OK) {
        fputs("Failed to enable SourceCore_GetResult hook\n", stdout);
        return;
    }
}

Il2CppObject *CreateUniTask(Il2CppClass *concreteClass, Il2CppObject *result) {
    Il2CppObject *uniTask = il2cpp_object_new(concreteClass);
    
    const MethodInfo *ctor = il2cpp_class_get_method_from_name(
        concreteClass, ".ctor", 1
    );

    if (!ctor) {
        printf("Failed to get UniTask ctor!\n");
        return NULL;
    }

    il2cpp_runtime_invoke(ctor, uniTask, (void *[]){result}, NULL);

    return uniTask;
}

Il2CppObject *CallParseJson(
    Google_Protobuf_MessageParser_TResponse__o *messageParser,
    const char *s
) {
    const MethodInfo *ParseJson = il2cpp_class_get_method_from_name(
        (Il2CppClass *)(messageParser->klass),
        "ParseJson", 1
    );

    if (!ParseJson) {
        printf("ParseJson not found!!!\n");
        return NULL;
    } else {
        System_String_o *text = il2cpp_string_new((char *)s);
        void *args[] = {text};
        Il2CppObject *another = il2cpp_runtime_invoke(ParseJson, messageParser, args, NULL);
        return another;
    }
}

Il2CppObject *GetMockResponse(Google_Protobuf_MessageParser_TResponse__o *messageParser) {
    RunNimMainOnce();

    System_String_o *s = ConvertObjectToString((Il2CppObject *)messageParser);
    sds sUtf8 = System_String_toSds(s);

    re_t pat = GetNeonModelApiPattern();
    sds resType = MatchNeonModelApi(pat, sUtf8);
    if (!resType) {
        printf("MatchNeonModelApi failed for '%s'!\n", sUtf8);
        return NULL;
    }

    sdsfree(sUtf8);

    printf("[GetMockResponse] '%s'\n", resType);
    
    sds reqJson = sdsempty();

    struct ResponseTypeToRequestPtr *resTypeToReqPtr = NULL;

    if (neonApiPath) {
        resTypeToReqPtr = findResTypeToReqPtrFromUri(neonApiPath);

        if (resTypeToReqPtr) {
            if (resTypeToReqPtr->requestPtr) {
                sdsfree(reqJson);
                reqJson = System_String_toSds(ConvertObjectToString(*resTypeToReqPtr->requestPtr));
                *resTypeToReqPtr->requestPtr = NULL;
            }
        } else {
            printf("WARNING: %s not found in resTypeToReq list!\n", neonApiPath);
        }

        sdsfree(neonApiPath);
        neonApiPath = NULL;
    } else {
        printf("WARNING: neonApiPath not set, so we don't know how to call semba!\n");
    }

    Il2CppObject *res = NULL;

    if (resTypeToReqPtr) {
        char *resJson = SembaCall(resTypeToReqPtr->uriPath, reqJson);
        if (resJson) {
            res = CallParseJson(messageParser, resJson);
            free(resJson);
        }
    }

    sdsfree(reqJson);

    return res;
}

CDGPJELFAMK__NOCKJHKDMGF_object__FuncPtr fpNeonApiGetResponse = NULL;

Cysharp_Threading_Tasks_UniTask_TResponse__o DetourNeonApiGetResponse(
    CDGPJELFAMK_o* __this,
    BJAFDMJIDMJ_o* EFCDPGBOIHC,
    LPCOHPIGHIN_o* EAGJONBIADJ,
    System_Threading_CancellationToken_o JLCCEAFOLOE,
    Google_Protobuf_MessageParser_TResponse__o* PNICKJFPBHH,
    const MethodInfo_F6CAF0* method
) {
    if (ZERO_CONFIG.offlineMode) {
        Il2CppClass *uniTaskClass = il2cpp_type_get_class_or_element_class(method->return_type);
        Il2CppObject *xResponse = GetMockResponse(PNICKJFPBHH);
    
        if (xResponse) {
            Cysharp_Threading_Tasks_UniTask_TResponse__o *res;
            res = (Cysharp_Threading_Tasks_UniTask_TResponse__o *)CreateUniTask(uniTaskClass, xResponse);
            return *res;
        }
    }
      
    return fpNeonApiGetResponse(__this, EFCDPGBOIHC, EAGJONBIADJ, JLCCEAFOLOE, PNICKJFPBHH, method);
}

void HookNeonApiGetResponse(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)CDGPJELFAMK__NOCKJHKDMGF_object_,
        (LPVOID)(uintptr_t)&DetourNeonApiGetResponse,
        (LPVOID *)&fpNeonApiGetResponse
    ) != MH_OK) {
        printf("Failed to create NeonApiGetResponse hook\n");
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)CDGPJELFAMK__NOCKJHKDMGF_object_, /* changePermissions = */ FALSE) != MH_OK) {
        printf("Failed to enable NeonApiGetResponse hook\n");
        return;
    }
}

ULONGLONG GetFileTimeDiff(FILETIME tim1, FILETIME tim2) {
    ULARGE_INTEGER res = {
        .LowPart = tim1.dwLowDateTime - tim2.dwLowDateTime,
        .HighPart = tim1.dwHighDateTime - tim2.dwHighDateTime
    };
    return res.QuadPart;
}

static bool gamePtrsReady = false;

bool areGamePtrsReady(void) {
    return gamePtrsReady;
}

void HookTN(void *GameAssembly) {
    InitGamePtrs(GameAssembly);
    gamePtrsReady = true;

    HookHTTPRequestCtor();
    HookSourceCore_GetResult();
    HookNeonApiGetResponse();
    HookKbjlheaohmd__Kpffclmemeg();

    RunNimMainOnce();

    if (ZERO_CONFIG.onlineLogsPath) {
        SembaInitOnlineDb(ZERO_CONFIG.onlineLogsPath);
    }

    if (ZERO_CONFIG.sembaDbPath) {
        SembaInitOfflineDb(ZERO_CONFIG.sembaDbPath);
    }

    if (ZERO_CONFIG.offlineMode && ZERO_CONFIG.remoteUrl) {
        SembaSetRemoteUrl(ZERO_CONFIG.remoteUrl);
    }

    if (ZERO_CONFIG.offlineMode && ZERO_CONFIG.saveFile) {
        SembaLoadSave(ZERO_CONFIG.saveFile);
    }

    printf("Applying autohooks...\n");
    FILETIME start;
    GetSystemTimeAsFileTime(&start);
    AutoHookTN();
    FILETIME end;
    GetSystemTimeAsFileTime(&end);
    ULONGLONG diff = GetFileTimeDiff(end, start);
    printf("Autohooking done in %llu ms!\n", diff / 10000ull);
}