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
#include "semba/NimInit.h"
#include "Patterns.h"
#include "semba/semba.h"
#include "version.h"
#include "TimeUtil.h"

#include <MinHook.h>
#include <sds.h>

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

int getBaseUrlSize(sds url) {
    if (strstr(url, "https://game.tribenine-game.com")) {
        return 31; // == len("https://game.tribenine-game.com")
    } else if (strstr(url, "https://cbt-game.tribenine-game.com")) {
        return 35; // == len("https://cbt-game.tribenine-game.com")
    }

    return -1;
}

void SaveNeonApiPath(sds url) {
    int baseUrlSize = getBaseUrlSize(url);
    if (baseUrlSize >= 0) {
        neonApiPath = sdsnew(url + baseUrlSize);
    }
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

    uri = CreateSystemUri("https://httpbin.org/status/500");

    SaveNeonApiPath(url);
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
    const GetResultMethodInfo* method
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
        char *resJson;

        if (GetGameVersion() == VERSION_DEMO) {
            resJson = SembaCallDemo(resTypeToReqPtr->uriPath, reqJson);
        } else {
            resJson = SembaCall(resTypeToReqPtr->uriPath, reqJson);
        }

        if (resJson) {
            res = CallParseJson(messageParser, resJson);
            if (!res) {
                printf("WARNING: MessageParser.ParseJson failed to decode SembaCall response\n");
            }
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
    NeonApiGetResponse_ThirdParam* EAGJONBIADJ,
    System_Threading_CancellationToken_o JLCCEAFOLOE,
    Google_Protobuf_MessageParser_TResponse__o* PNICKJFPBHH,
    const NeonApiGetResponse_MethodInfo* method
) {

    Il2CppClass *uniTaskClass = il2cpp_type_get_class_or_element_class(method->return_type);
    Il2CppObject *xResponse = GetMockResponse(PNICKJFPBHH);

    if (xResponse) {
        Cysharp_Threading_Tasks_UniTask_TResponse__o *res;
        res = (Cysharp_Threading_Tasks_UniTask_TResponse__o *)CreateUniTask(uniTaskClass, xResponse);
        return *res;
    }

      
    return fpNeonApiGetResponse(__this, EFCDPGBOIHC, EAGJONBIADJ, JLCCEAFOLOE, PNICKJFPBHH, method);
}

UnityEngine_Transform__set_position_FuncPtr fpUnityEngine_Transform__set_position = NULL;

static float pos[3] = {0};
static float rotation[4] = {0};

static bool pausePosition = false;

float *getPosArray(void) {
    return pos;
}

float *getRotationArray(void) {
    return rotation;
}

bool *getPausePositionPtr(void) {
    return &pausePosition;
}

void Detour_UnityEngine_Transform__set_position (
    UnityEngine_Transform_o* __this, UnityEngine_Vector3_o value, const MethodInfo* method
) {
    if (pausePosition) {
        value.fields.x = pos[0];
        value.fields.y = pos[1];
        value.fields.z = pos[2];
    } else {
        pos[0] = value.fields.x;
        pos[1] = value.fields.y;
        pos[2] = value.fields.z;
    }

    fpUnityEngine_Transform__set_position(__this, value, method);
}

void Hook_UnityEngine_Transform__set_position(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)UnityEngine_Transform__set_position,
        (LPVOID)(uintptr_t)&Detour_UnityEngine_Transform__set_position,
        (LPVOID *)&fpUnityEngine_Transform__set_position
    ) != MH_OK) {
        printf("Failed to create UnityEngine_Transform__set_position hook\n");
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)UnityEngine_Transform__set_position, /* changePermissions = */ FALSE) != MH_OK) {
        printf("Failed to enable UnityEngine_Transform__set_position hook\n");
        return;
    }
}

#ifdef HAVE_LUX_PHANTASM
EMDHIMNBAPC___ctor_FuncPtr fpEMDHIMNBAPC___ctor = NULL;

void Detour_EMDHIMNBAPC___ctor(
    EMDHIMNBAPC_o* __this, int32_t MJFIGOGDOGF, JDGBHFIBACG_o* KOGMPABNAMA,
    JDGBHFIBACG_o* IKIBKIBBBIL, int32_t AKPAPIBMHKE, System_Nullable_OOJEDNBBGBK__o PIJDPLJBKDK,
    System_Nullable_DateTime__o DLICIPCDJHN, System_Nullable_DateTime__o LKPAJOFHJFB,
    System_Collections_Generic_IReadOnlyList_PDIFPHMPPAG__o* DNHEPOBJNOP,
    System_Nullable_LFJELIPKMBM__o KIOHPMPOKCM, System_Nullable_IKAFHEBKEHP__o AKBPMHCLKCP,
    int32_t FGANDLGCJDH, System_String_o* GAGHHMOBBMN, const MethodInfo* method
) {
    int32_t id = MJFIGOGDOGF;
    System_Nullable_DateTime__o* start = &DLICIPCDJHN;
    System_Nullable_DateTime__o* end = &LKPAJOFHJFB;

    if (id == 101) {
        start->fields.hasValue = false;
        end->fields.hasValue = false;
        printf("Made Lux Phantasma permanent!\n");
    }

    fpEMDHIMNBAPC___ctor(
        __this, MJFIGOGDOGF, KOGMPABNAMA,
        IKIBKIBBBIL, AKPAPIBMHKE, PIJDPLJBKDK,
        DLICIPCDJHN, LKPAJOFHJFB,
        DNHEPOBJNOP,
        KIOHPMPOKCM, AKBPMHCLKCP,
        FGANDLGCJDH, GAGHHMOBBMN, method 
    );
}

void Hook_EMDHIMNBAPC___ctor(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)EMDHIMNBAPC___ctor,
        (LPVOID)(uintptr_t)&Detour_EMDHIMNBAPC___ctor,
        (LPVOID *)&fpEMDHIMNBAPC___ctor
    ) != MH_OK) {
        printf("Failed to create EMDHIMNBAPC___ctor hook\n");
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)EMDHIMNBAPC___ctor, /* changePermissions = */ FALSE) != MH_OK) {
        printf("Failed to enable EMDHIMNBAPC___ctor hook\n");
        return;
    }
}

#endif

UnityEngine_Camera__set_fieldOfView_FuncPtr fpUnityEngine_Camera__set_fieldOfView = NULL;

bool useCustomFov = false;
float fovScale = 1;

bool *getCustomFovFlag(void) {
    return &useCustomFov;
}

float *getFovScale(void) {
    return &fovScale;
}

void Detour_UnityEngine_Camera__set_fieldOfView(
    UnityEngine_Camera_o* __this, float value, const MethodInfo* method
) {
    if (useCustomFov) {
        value *= fovScale;
    }
    fpUnityEngine_Camera__set_fieldOfView(__this, value, method);
}

void Hook_UnityEngine_Camera__set_fieldOfView(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)UnityEngine_Camera__set_fieldOfView,
        (LPVOID)(uintptr_t)&Detour_UnityEngine_Camera__set_fieldOfView,
        (LPVOID *)&fpUnityEngine_Camera__set_fieldOfView
    ) != MH_OK) {
        printf("Failed to create UnityEngine_Camera__set_fieldOfView hook\n");
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)UnityEngine_Camera__set_fieldOfView, /* changePermissions = */ FALSE) != MH_OK) {
        printf("Failed to enable UnityEngine_Camera__set_fieldOfView hook\n");
        return;
    }
}

UnityEngine_Transform__set_rotation_FuncPtr fpUnityEngine_Transform__set_rotation = NULL;

void Detour_UnityEngine_Transform__set_rotation(
    UnityEngine_Transform_o* __this, UnityEngine_Quaternion_o value, const MethodInfo* method
) {
    if (pausePosition) {
        value.fields.x = rotation[0];
        value.fields.y = rotation[1];
        value.fields.z = rotation[2];
        value.fields.w = rotation[3];
    } else {
        rotation[0] = value.fields.x;
        rotation[1] = value.fields.y;
        rotation[2] = value.fields.z;
        rotation[3] = value.fields.w;
    }
    fpUnityEngine_Transform__set_rotation(__this, value, method);
}

void Hook_UnityEngine_Transform__set_rotation(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)UnityEngine_Transform__set_rotation,
        (LPVOID)(uintptr_t)&Detour_UnityEngine_Transform__set_rotation,
        (LPVOID *)&fpUnityEngine_Transform__set_rotation
    ) != MH_OK) {
        printf("Failed to create UnityEngine_Transform__set_rotation hook\n");
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)UnityEngine_Transform__set_rotation, /* changePermissions = */ FALSE) != MH_OK) {
        printf("Failed to enable UnityEngine_Transform__set_rotation hook\n");
        return;
    }
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

static bool gamePtrsReady = false;

bool areGamePtrsReady(void) {
    return gamePtrsReady;
}

#ifdef TRIBE_NINE_DEMO

typedef void (*OJLLOCJDBLM___ctor_FuncPtr) (OJLLOCJDBLM_o* __this, MNHJNDFAPMD_o* NFADCMKHEAI, Neon_Model_Api_Model_Enemy_o* PIOECLPHAFK, EJOPFMGFPOA_o* LFLBBLLOAKF, int32_t ODCLDJBPJMJ, const MethodInfo* method);

OJLLOCJDBLM___ctor_FuncPtr OJLLOCJDBLM___ctor = NULL;
OJLLOCJDBLM___ctor_FuncPtr fpOJLLOCJDBLM___ctor = NULL;

void Detour_OJLLOCJDBLM___ctor(
    OJLLOCJDBLM_o* __this, MNHJNDFAPMD_o* NFADCMKHEAI,
    Neon_Model_Api_Model_Enemy_o* PIOECLPHAFK, EJOPFMGFPOA_o* LFLBBLLOAKF,
    int32_t ODCLDJBPJMJ, const MethodInfo* method
) {
    printf(
        "NFADCMKHEAI=%p, PIOECLPHAFK=%p, LFLBBLLOAKF=%p, ODCLDJBPJMJ=%lld\n",
        (void *)NFADCMKHEAI, (void *)PIOECLPHAFK, (void *)LFLBBLLOAKF, (long long)ODCLDJBPJMJ
    );
    fpOJLLOCJDBLM___ctor(__this, NFADCMKHEAI, PIOECLPHAFK, LFLBBLLOAKF, ODCLDJBPJMJ, method);
}

void Hook_OJLLOCJDBLM___ctor(void) {
    printf("Hook_OJLLOCJDBLM___ctor called\n");
    if (MH_CreateHook(
        (void *)(uintptr_t)OJLLOCJDBLM___ctor,
        (LPVOID)(uintptr_t)&Detour_OJLLOCJDBLM___ctor,
        (LPVOID *)&fpOJLLOCJDBLM___ctor
    ) != MH_OK) {
        printf("Failed to create OJLLOCJDBLM___ctor hook\n");
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)OJLLOCJDBLM___ctor, /* changePermissions = */ FALSE) != MH_OK) {
        printf("Failed to enable OJLLOCJDBLM___ctor hook\n");
        return;
    }
}
#endif

void HookTN(void *GameAssembly) {
    InitGamePtrs(GameAssembly);
    gamePtrsReady = true;

    HookHTTPRequestCtor();
    HookSourceCore_GetResult();
    HookNeonApiGetResponse();
    HookKbjlheaohmd__Kpffclmemeg();
    Hook_UnityEngine_Transform__set_position();
    Hook_UnityEngine_Transform__set_rotation();
    Hook_UnityEngine_Camera__set_fieldOfView();

    #ifdef HAVE_LUX_PHANTASM
    Hook_EMDHIMNBAPC___ctor();
#endif

#ifdef TRIBE_NINE_DEMO
    OJLLOCJDBLM___ctor = (OJLLOCJDBLM___ctor_FuncPtr)((uintptr_t)GameAssembly + 60351888ull);
    Hook_OJLLOCJDBLM___ctor();
#endif

    RunNimMainOnce();

    if (ZERO_CONFIG.sembaDbPath) {
        SembaInitOfflineDb(ZERO_CONFIG.sembaDbPath);
    }

    if (ZERO_CONFIG.remoteUrl) {
        SembaSetRemoteUrl(ZERO_CONFIG.remoteUrl);
    }

    printf("Applying autohooks...\n");
    FILETIME start;
    GetSystemTimeAsFileTime(&start);
    AutoHookTN();
    FILETIME end;
    GetSystemTimeAsFileTime(&end);
    ULONGLONG diff = GetFileTimeDiff(end, start);
    printf("Autohooking done in %llu ms!\n", TimeDiffToMs(diff));
}