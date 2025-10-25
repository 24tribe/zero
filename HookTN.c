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

#include <MinHook.h>
#include <sds.h>
#include <semba.h>

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

Il2CppClass **System_Uri_TypeInfo = NULL;

typedef Cysharp_Threading_Tasks_UniTask_AdventureAreaObjectResponse__o (*NEON_MODEL_API_APISERVICE__ADVENTURE_AREAOBJECT)(Neon_Model_Api_ApiService_o* __this, Neon_Model_Api_Rpc_AdventureAreaObjectRequest_o* data, LPCOHPIGHIN_o* requestHandler, System_Threading_CancellationToken_o cancellationToken, const MethodInfo* method);
NEON_MODEL_API_APISERVICE__ADVENTURE_AREAOBJECT Neon_Model_Api_ApiService__Adventure_AreaObject = NULL;
NEON_MODEL_API_APISERVICE__ADVENTURE_AREAOBJECT fpNeon_Model_Api_ApiService__Adventure_AreaObject = NULL;

typedef void (*URICONSTRUCTOR)(System_Uri_o* __this, System_String_o* uriString, const MethodInfo* method);
URICONSTRUCTOR System_Uri_ctor = NULL;

typedef Il2CppObject *(*SOURCE_CORE_GETRESULT)(Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__o __this, int16_t token, const MethodInfo_20B62E0* method);
SOURCE_CORE_GETRESULT Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object___GetResult = NULL;
SOURCE_CORE_GETRESULT fpSourceCore_GetResult = NULL;

typedef Cysharp_Threading_Tasks_UniTask_TResponse__o (*NEON_API_GET_RESPONSE)(CDGPJELFAMK_o* __this, BJAFDMJIDMJ_o* EFCDPGBOIHC, LPCOHPIGHIN_o* EAGJONBIADJ, System_Threading_CancellationToken_o JLCCEAFOLOE, Google_Protobuf_MessageParser_TResponse__o* PNICKJFPBHH, const MethodInfo_F6CAF0* method);
NEON_API_GET_RESPONSE NeonApiGetResponse = NULL; // CDGPJELFAMK__NOCKJHKDMGF_object_
NEON_API_GET_RESPONSE fpNeonApiGetResponse = NULL;

typedef bool (*KBJLHEAOHMD__KPFFCLMEMEG)(System_DateTime_o HKIOCIMKCCP, System_DateTime_o CJKBFINFMNP, const MethodInfo* method);
KBJLHEAOHMD__KPFFCLMEMEG Kbjlheaohmd__Kpffclmemeg = NULL;
KBJLHEAOHMD__KPFFCLMEMEG fpKbjlheaohmd__Kpffclmemeg = NULL;

typedef Cysharp_Threading_Tasks_UniTask_TipReleaseResponse__o (*NEON_MODEL_API_APISERVICE__TIP_RELEASE)(Neon_Model_Api_ApiService_o* __this, Neon_Model_Api_Rpc_TipReleaseRequest_o* data, LPCOHPIGHIN_o* requestHandler, System_Threading_CancellationToken_o cancellationToken, const MethodInfo* method);
NEON_MODEL_API_APISERVICE__TIP_RELEASE Neon_Model_Api_ApiService__Tip_Release = NULL;
NEON_MODEL_API_APISERVICE__TIP_RELEASE fpNeon_Model_Api_ApiService__Tip_Release = NULL;

typedef Cysharp_Threading_Tasks_UniTask_AdventureMoveToAreaResponse__o (*NEON_MODEL_API_APISERVICE__ADVENTURE_MOVETOAREA)(Neon_Model_Api_ApiService_o* __this, Neon_Model_Api_Rpc_AdventureMoveToAreaRequest_o* data, LPCOHPIGHIN_o* requestHandler, System_Threading_CancellationToken_o cancellationToken, const MethodInfo* method);
NEON_MODEL_API_APISERVICE__ADVENTURE_MOVETOAREA Neon_Model_Api_ApiService__Adventure_MoveToArea = NULL;
NEON_MODEL_API_APISERVICE__ADVENTURE_MOVETOAREA fpNeon_Model_Api_ApiService__Adventure_MoveToArea = NULL;

typedef Cysharp_Threading_Tasks_UniTask_BattleStartResponse__o (*NEON_MODEL_API_APISERVICE__BATTLE_START)(Neon_Model_Api_ApiService_o* __this, Neon_Model_Api_Rpc_BattleStartRequest_o* data, LPCOHPIGHIN_o* requestHandler, System_Threading_CancellationToken_o cancellationToken, const MethodInfo* method);
NEON_MODEL_API_APISERVICE__BATTLE_START Neon_Model_Api_ApiService__Battle_Start = NULL;
NEON_MODEL_API_APISERVICE__BATTLE_START fpNeon_Model_Api_ApiService__Battle_Start = NULL;

typedef Cysharp_Threading_Tasks_UniTask_BattleFinishResponse__o (*NEON_MODEL_API_APISERVICE__BATTLE_FINISH)(Neon_Model_Api_ApiService_o* __this, Neon_Model_Api_Rpc_BattleFinishRequest_o* data, LPCOHPIGHIN_o* requestHandler, System_Threading_CancellationToken_o cancellationToken, const MethodInfo* method);
NEON_MODEL_API_APISERVICE__BATTLE_FINISH Neon_Model_Api_ApiService__Battle_Finish = NULL;
NEON_MODEL_API_APISERVICE__BATTLE_FINISH fpNeon_Model_Api_ApiService__Battle_Finish = NULL;

typedef Cysharp_Threading_Tasks_UniTask_ChangedResourcesResponse__o (*NEON_MODEL_API_APISERVICE__ADVENTURE_UPDATECHARACTERSTATUS)(Neon_Model_Api_ApiService_o* __this, Neon_Model_Api_Rpc_AdventureUpdateCharacterStatusRequest_o* data, LPCOHPIGHIN_o* requestHandler, System_Threading_CancellationToken_o cancellationToken, const MethodInfo* method);
NEON_MODEL_API_APISERVICE__ADVENTURE_UPDATECHARACTERSTATUS Neon_Model_Api_ApiService__Adventure_UpdateCharacterStatus = NULL;
NEON_MODEL_API_APISERVICE__ADVENTURE_UPDATECHARACTERSTATUS fpNeon_Model_Api_ApiService__Adventure_UpdateCharacterStatus = NULL;

typedef Cysharp_Threading_Tasks_UniTask_ChangedResourcesResponse__o (*NEON_MODEL_API_APISERVICE__FORMATION_UPDATE)(Neon_Model_Api_ApiService_o* __this, Neon_Model_Api_Rpc_FormationUpdateRequest_o* data, LPCOHPIGHIN_o* requestHandler, System_Threading_CancellationToken_o cancellationToken, const MethodInfo* method);
NEON_MODEL_API_APISERVICE__FORMATION_UPDATE Neon_Model_Api_ApiService__Formation_Update = NULL;
NEON_MODEL_API_APISERVICE__FORMATION_UPDATE fpNeon_Model_Api_ApiService__Formation_Update = NULL;

Neon_Model_Api_Rpc_FormationUpdateRequest_o *lastFormationUpdateRequest = NULL;

Cysharp_Threading_Tasks_UniTask_ChangedResourcesResponse__o DetourFormationUpdate(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_FormationUpdateRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    lastFormationUpdateRequest = data;
    sds reqJson = System_String_toSds(ConvertObjectToString((Il2CppObject *)data));
    printf("[DetourFormationUpdate] %s\n", reqJson);
    sdsfree(reqJson);
    return fpNeon_Model_Api_ApiService__Formation_Update(
        __this,
        data,
        requestHandler,
        cancellationToken,
        method
    );
}


void HookFormationUpdate(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)Neon_Model_Api_ApiService__Formation_Update,
        (LPVOID)(uintptr_t)&DetourFormationUpdate,
        (LPVOID *)(&fpNeon_Model_Api_ApiService__Formation_Update)
    ) != MH_OK) {
        fputs("Failed to create Neon_Model_Api_ApiService__Formation_Update hook\n", stdout);
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)Neon_Model_Api_ApiService__Formation_Update, /* changePermissions = */ FALSE) != MH_OK) {
        fputs("Failed to enable Neon_Model_Api_ApiService__Formation_Update hook\n", stdout);
        return;
    }
}

Neon_Model_Api_Rpc_AdventureUpdateCharacterStatusRequest_o *lastUpdateCharacterStatusRequest = NULL;

Cysharp_Threading_Tasks_UniTask_ChangedResourcesResponse__o DetourUpdateCharacterStatus(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_AdventureUpdateCharacterStatusRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    lastUpdateCharacterStatusRequest = data;
    sds reqJson = System_String_toSds(ConvertObjectToString((Il2CppObject *)data));
    printf("[DetourUpdateCharacterStatus] %s\n", reqJson);
    sdsfree(reqJson);
    return fpNeon_Model_Api_ApiService__Adventure_UpdateCharacterStatus(
        __this,
        data,
        requestHandler,
        cancellationToken,
        method
    );
}

void HookUpdateCharacterStatus(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)Neon_Model_Api_ApiService__Adventure_UpdateCharacterStatus,
        (LPVOID)(uintptr_t)&DetourUpdateCharacterStatus,
        (LPVOID *)(&fpNeon_Model_Api_ApiService__Adventure_UpdateCharacterStatus)
    ) != MH_OK) {
        fputs("Failed to create Neon_Model_Api_ApiService__Adventure_UpdateCharacterStatus hook\n", stdout);
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)Neon_Model_Api_ApiService__Adventure_UpdateCharacterStatus, /* changePermissions = */ FALSE) != MH_OK) {
        fputs("Failed to enable Neon_Model_Api_ApiService__Adventure_UpdateCharacterStatus hook\n", stdout);
        return;
    }
}

Neon_Model_Api_Rpc_BattleFinishRequest_o *lastBattleFinishRequest = NULL;

Cysharp_Threading_Tasks_UniTask_BattleFinishResponse__o DetourBattleFinish(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_BattleFinishRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    lastBattleFinishRequest = data;
    sds reqJson = System_String_toSds(ConvertObjectToString((Il2CppObject *)data));
    printf("[DetourBattleFinish] %s\n", reqJson);
    sdsfree(reqJson);
    return fpNeon_Model_Api_ApiService__Battle_Finish(
        __this, data, requestHandler, cancellationToken, method
    );
}

void HookBattleFinish(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)Neon_Model_Api_ApiService__Battle_Finish,
        (LPVOID)(uintptr_t)&DetourBattleFinish,
        (LPVOID *)(&fpNeon_Model_Api_ApiService__Battle_Finish)
    ) != MH_OK) {
        fputs("Failed to create Neon_Model_Api_ApiService__Battle_Finish hook\n", stdout);
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)Neon_Model_Api_ApiService__Battle_Finish, /* changePermissions = */ FALSE) != MH_OK) {
        fputs("Failed to enable Neon_Model_Api_ApiService__Battle_Finish hook\n", stdout);
        return;
    }
}

Neon_Model_Api_Rpc_BattleStartRequest_o *lastBattleStartRequest = NULL;

Cysharp_Threading_Tasks_UniTask_BattleStartResponse__o DetourBattleStart(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_BattleStartRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    lastBattleStartRequest = data;
    sds reqJson = System_String_toSds(ConvertObjectToString((Il2CppObject *)data));
    printf("[DetourBattleStart] %s\n", reqJson);
    sdsfree(reqJson);
    return fpNeon_Model_Api_ApiService__Battle_Start(__this, data, requestHandler, cancellationToken, method);
}

void HookBattleStart(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)Neon_Model_Api_ApiService__Battle_Start,
        (LPVOID)(uintptr_t)&DetourBattleStart,
        (LPVOID *)(&fpNeon_Model_Api_ApiService__Battle_Start)
    ) != MH_OK) {
        fputs("Failed to create Neon_Model_Api_ApiService__Battle_Start hook\n", stdout);
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)Neon_Model_Api_ApiService__Battle_Start, /* changePermissions = */ FALSE) != MH_OK) {
        fputs("Failed to enable Neon_Model_Api_ApiService__Battle_Start hook\n", stdout);
        return;
    }
}

Neon_Model_Api_Rpc_AdventureMoveToAreaRequest_o *lastAdventureMoveToAreaRequest = NULL;

Cysharp_Threading_Tasks_UniTask_AdventureMoveToAreaResponse__o DetourAdventureMoveToArea(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_AdventureMoveToAreaRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    lastAdventureMoveToAreaRequest = data;
    sds reqJson = System_String_toSds(ConvertObjectToString((Il2CppObject *)data));
    printf("[DetourAdventureMoveToArea] %s\n", reqJson);
    sdsfree(reqJson);
    return fpNeon_Model_Api_ApiService__Adventure_MoveToArea(
        __this, data, requestHandler, cancellationToken, method
    );
}

void HookAdventureMoveToArea(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)Neon_Model_Api_ApiService__Adventure_MoveToArea,
        (LPVOID)(uintptr_t)&DetourAdventureMoveToArea,
        (LPVOID *)(&fpNeon_Model_Api_ApiService__Adventure_MoveToArea)
    ) != MH_OK) {
        fputs("Failed to create Neon_Model_Api_ApiService__Tip_Release hook\n", stdout);
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)Neon_Model_Api_ApiService__Adventure_MoveToArea, /* changePermissions = */ FALSE) != MH_OK) {
        fputs("Failed to enable Neon_Model_Api_ApiService__Tip_Release hook\n", stdout);
        return;
    }
}

Neon_Model_Api_Rpc_TipReleaseRequest_o *lastTipReleaseRequest = NULL;

Cysharp_Threading_Tasks_UniTask_TipReleaseResponse__o DetourTipRelease(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_TipReleaseRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    lastTipReleaseRequest = data;
    sds req = System_String_toSds(ConvertObjectToString((Il2CppObject *)data));
    printf("[DetourTipRelease] %s\n", req);
    sdsfree(req);
    return fpNeon_Model_Api_ApiService__Tip_Release(
        __this, data, requestHandler, cancellationToken, method
    );
}

void HookTipRelease(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)Neon_Model_Api_ApiService__Tip_Release,
        (LPVOID)(uintptr_t)&DetourTipRelease,
        (LPVOID *)(&fpNeon_Model_Api_ApiService__Tip_Release)
    ) != MH_OK) {
        fputs("Failed to create Neon_Model_Api_ApiService__Tip_Release hook\n", stdout);
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)Neon_Model_Api_ApiService__Tip_Release, /* changePermissions = */ FALSE) != MH_OK) {
        fputs("Failed to enable Neon_Model_Api_ApiService__Tip_Release hook\n", stdout);
        return;
    }
}

Neon_Model_Api_Rpc_AdventureAreaObjectRequest_o* lastAdventureAreaObjectRequest = NULL;

Cysharp_Threading_Tasks_UniTask_AdventureAreaObjectResponse__o DetourAdventureAreaObject(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_AdventureAreaObjectRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    lastAdventureAreaObjectRequest = data;
    sds req = System_String_toSds(ConvertObjectToString((Il2CppObject *)data));
    printf("[DetourAdventureAreaObject] %s\n", req);
    sdsfree(req);
    return fpNeon_Model_Api_ApiService__Adventure_AreaObject(
        __this, data, requestHandler, cancellationToken, method
    );
}

void HookAdventureAreaObject(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)Neon_Model_Api_ApiService__Adventure_AreaObject,
        (LPVOID)(uintptr_t)&DetourAdventureAreaObject,
        (LPVOID *)(&fpNeon_Model_Api_ApiService__Adventure_AreaObject)
    ) != MH_OK) {
        fputs("Failed to create Neon_Model_Api_ApiService__Adventure_AreaObject hook\n", stdout);
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)Neon_Model_Api_ApiService__Adventure_AreaObject, /* changePermissions = */ FALSE) != MH_OK) {
        fputs("Failed to enable Neon_Model_Api_ApiService__Adventure_AreaObject hook\n", stdout);
        return;
    }
}

bool DetourKbjlheaohmd__Kpffclmemeg(System_DateTime_o HKIOCIMKCCP, System_DateTime_o CJKBFINFMNP, const MethodInfo* method) {
    if (HKIOCIMKCCP.fields._dateData == 0) {
        return false;
    }

    return fpKbjlheaohmd__Kpffclmemeg(HKIOCIMKCCP, CJKBFINFMNP, method);
}

void HookKbjlheaohmd__Kpffclmemeg(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)Kbjlheaohmd__Kpffclmemeg,
        (LPVOID)(uintptr_t)&DetourKbjlheaohmd__Kpffclmemeg,
        (LPVOID *)(&fpKbjlheaohmd__Kpffclmemeg)
    ) != MH_OK) {
        fputs("Failed to create Kbjlheaohmd__Kpffclmemeg hook\n", stdout);
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)Kbjlheaohmd__Kpffclmemeg, /* changePermissions = */ FALSE) != MH_OK) {
        fputs("Failed to enable Kbjlheaohmd__Kpffclmemeg hook\n", stdout);
        return;
    }
}

typedef void (*HTTPRequestCtor)(Best_HTTP_HTTPRequest_o* __this, System_Uri_o* uri, int32_t methodType, const MethodInfo* method);
HTTPRequestCtor fpHTTPRequestCtor = NULL;

System_Uri_o *ChangeUrl(char *url) {
    printf("url: %s\n", url);

    if (!strstr(url, "https://game.tribenine-game.com")) {
        return NULL;
    }

    // len("https://game.tribenine-game.com") == 31
#define BASE_URL_SIZE 31 
#define NEW_URL_SIZE 4096
    char new_url[NEW_URL_SIZE] = {0};

    int err = snprintf(new_url, NEW_URL_SIZE, "http://127.0.0.1:8080%s", url + BASE_URL_SIZE);
    
    if (err < 0 || err >= MAX_PATH) {
        fputs("snprintf new_url failed\n", stdout);
        return NULL;
    }

    printf("new_url: %s\n", new_url);
    
    System_Uri_o *uri = (System_Uri_o *)il2cpp_object_new(*System_Uri_TypeInfo);
    System_String_o *proxy = il2cpp_string_new(new_url);
    System_Uri_ctor(uri, proxy, NULL);

    return uri;
}
#undef NEW_URL_SIZE
#undef BASE_URL_SIZE

void DetourHTTPRequestCtor(Best_HTTP_HTTPRequest_o* __this, System_Uri_o* uri, int32_t methodType, const MethodInfo* method) {
    sds url = System_String_toSds(uri->fields.m_String);
    SaveStackTrace(url);
    sdsfree(url);
    fpHTTPRequestCtor(__this, uri, methodType, method);
}

void HookHTTPRequestCtor(void *GameAssembly) {
    void *addr = (char *)GameAssembly + 10655472;
    if (MH_CreateHook(addr, (LPVOID)(uintptr_t)&DetourHTTPRequestCtor, (LPVOID *)(&fpHTTPRequestCtor)) != MH_OK) {
        fputs("Failed to create HTTPRequestCtor hook\n", stdout);
        return;
    }
    if (MH_EnableHook(addr, /* changePermissions = */ FALSE) != MH_OK) {
        fputs("Failed to enable HTTPRequestCtor hook\n", stdout);
        return;
    }
}

Il2CppObject *DetourSourceCore_GetResult(
    Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__o __this,
    int16_t token,
    const MethodInfo_20B62E0* method
) {
    Il2CppObject *res = fpSourceCore_GetResult(__this, token, method);
    
    LogResponse(res);

    return res;
}

void HookSourceCore_GetResult(void *GameAssembly) {
    (void)GameAssembly;

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
    NimMain();

    Il2CppObject *res = NULL;
    System_String_o *s = ConvertObjectToString((Il2CppObject *)messageParser);
    sds sUtf8 = System_String_toSds(s);

    printf("[GetMockResponse] %s\n", sUtf8);

    if (strstr(sUtf8, "Neon.Model.Api.Rpc.AuthSteamUserResponse")) {    
        res = CallParseJson(
            messageParser,
            SembaCall("/auth/steam_user", "")
        );
    } else if (strstr(sUtf8, "Neon.Model.Api.Rpc.AuthNonceResponse")) {
        res = CallParseJson(
            messageParser,
            SembaCall("/auth/nonce", "")
        );
    } else if (strstr(sUtf8, "Neon.Model.Api.Rpc.AuthSignInResponse")) {
        res = CallParseJson(
            messageParser,
            SembaCall("/auth/sign_in", "")
        );
    } else if (strstr(sUtf8, "Neon.Model.Api.Rpc.UserLogInResponse")) {
        res = CallParseJson(messageParser, SembaCall("/user/log_in", ""));
    } else if (strstr(sUtf8, "Neon.Model.Api.Rpc.UserCrossDateResponse")) {
        res = CallParseJson(messageParser, SembaCall("/user/cross_date", ""));
    } else if (strstr(sUtf8, "Neon.Model.Api.Rpc.AdventureAreaObjectResponse")) {
        sds reqJson = System_String_toSds(ConvertObjectToString((Il2CppObject *)lastAdventureAreaObjectRequest));
        res = CallParseJson(messageParser, SembaCall("/adventure/area_object", reqJson));
        sdsfree(reqJson);
    } else if (strstr(sUtf8, "Neon.Model.Api.Rpc.AdventureMoveToAreaResponse")) {
        sds reqJson = System_String_toSds(ConvertObjectToString((Il2CppObject *)lastAdventureMoveToAreaRequest));
        res = CallParseJson(messageParser, SembaCall("/adventure/move_to_area", reqJson));
        sdsfree(reqJson);
    } else if (strstr(sUtf8, "Neon.Model.Api.Rpc.TipReleaseResponse")) {
        System_String_o *s = ConvertObjectToString((Il2CppObject *)lastTipReleaseRequest);
        sds reqJson = System_String_toSds(s);
        res = CallParseJson(messageParser, SembaCall("/tip/release", reqJson));
        sdsfree(reqJson);
    } else if (strstr(sUtf8, "Neon.Model.Api.Rpc.BattleStartResponse")) {
        System_String_o *s = ConvertObjectToString((Il2CppObject *)lastBattleStartRequest);
        sds reqJson = System_String_toSds(s);
        const char *resJson = SembaCall("/battle/start", reqJson);
        printf("[GetMockResponse] resJson=%s\n", resJson);
        res = CallParseJson(messageParser, resJson);
        sdsfree(reqJson);
    } else if (strstr(sUtf8, "Neon.Model.Api.Rpc.ChangedResourcesResponse")) {
        if (lastUpdateCharacterStatusRequest != NULL) {
            sds reqJson = System_String_toSds(ConvertObjectToString((Il2CppObject *)lastUpdateCharacterStatusRequest));
            res = CallParseJson(messageParser, SembaCall("/adventure/update_character_status", reqJson));
            sdsfree(reqJson);
            lastUpdateCharacterStatusRequest = NULL;
        }
    }

    sdsfree(sUtf8);
    return res;
}

Cysharp_Threading_Tasks_UniTask_TResponse__o DetourNeonApiGetResponse(
    CDGPJELFAMK_o* __this,
    BJAFDMJIDMJ_o* EFCDPGBOIHC,
    LPCOHPIGHIN_o* EAGJONBIADJ,
    System_Threading_CancellationToken_o JLCCEAFOLOE,
    Google_Protobuf_MessageParser_TResponse__o* PNICKJFPBHH,
    const MethodInfo_F6CAF0* method
) {
    printf("DetourNeonApiGetResponse called!!\n");

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
        (void *)(uintptr_t)NeonApiGetResponse,
        (LPVOID)(uintptr_t)&DetourNeonApiGetResponse,
        (LPVOID *)&fpNeonApiGetResponse
    ) != MH_OK) {
        printf("Failed to create NeonApiGetResponse hook\n");
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)NeonApiGetResponse, /* changePermissions = */ FALSE) != MH_OK) {
        printf("Failed to enable NeonApiGetResponse hook\n");
        return;
    }
}

void HookTN(void *GameAssembly) {
    System_Uri_TypeInfo = (Il2CppClass **)((unsigned long long)GameAssembly + 129866520ull);
    System_Uri_ctor = (URICONSTRUCTOR)((unsigned long long)GameAssembly + 94439536ull);

    Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object___GetResult = (SOURCE_CORE_GETRESULT)((unsigned long long)GameAssembly + 34300640ull);

    NeonApiGetResponse = (NEON_API_GET_RESPONSE)((unsigned long long)GameAssembly + 16173808ull);

    Kbjlheaohmd__Kpffclmemeg = (KBJLHEAOHMD__KPFFCLMEMEG)((unsigned long long)GameAssembly + 59260912ull);

    Neon_Model_Api_ApiService__Adventure_AreaObject = (NEON_MODEL_API_APISERVICE__ADVENTURE_AREAOBJECT)((unsigned long long)GameAssembly + 79407520ull);

    Neon_Model_Api_ApiService__Tip_Release = (NEON_MODEL_API_APISERVICE__TIP_RELEASE)((unsigned long long)GameAssembly + 79451120ull);

    Neon_Model_Api_ApiService__Adventure_MoveToArea = (NEON_MODEL_API_APISERVICE__ADVENTURE_MOVETOAREA)((unsigned long long)GameAssembly + 79408528ull);

    Neon_Model_Api_ApiService__Battle_Start = (NEON_MODEL_API_APISERVICE__BATTLE_START)((unsigned long long)GameAssembly + 79413904ull);

    Neon_Model_Api_ApiService__Battle_Finish = (NEON_MODEL_API_APISERVICE__BATTLE_FINISH)((unsigned long long)GameAssembly + 79412896ull);

    Neon_Model_Api_ApiService__Adventure_UpdateCharacterStatus = (NEON_MODEL_API_APISERVICE__ADVENTURE_UPDATECHARACTERSTATUS)((unsigned long long)GameAssembly + 79409872ull);

    Neon_Model_Api_ApiService__Formation_Update = (NEON_MODEL_API_APISERVICE__FORMATION_UPDATE)((unsigned long long)GameAssembly + 79425184ull);

    HookHTTPRequestCtor(GameAssembly);
    HookSourceCore_GetResult(GameAssembly);
    HookNeonApiGetResponse();
    HookKbjlheaohmd__Kpffclmemeg();
    HookAdventureAreaObject();
    HookTipRelease();
    HookAdventureMoveToArea();
    HookBattleStart();
    HookBattleFinish();
    HookUpdateCharacterStatus();
    HookFormationUpdate();

    InitLogger(GameAssembly);
}