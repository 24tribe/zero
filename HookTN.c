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
#include "re.h"

#include <MinHook.h>
#include <sds.h>
#include <semba.h>

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include "funcPtrs.h"

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

Neon_Model_Api_Rpc_AdventureAreaObjectRequest_o* lastAdventureAreaObjectRequest = NULL;
Neon_Model_Api_Rpc_AdventureMoveToAreaRequest_o *lastAdventureMoveToAreaRequest = NULL;
Neon_Model_Api_Rpc_AdventureUpdateCharacterStatusRequest_o *lastUpdateCharacterStatusRequest = NULL;
Neon_Model_Api_Rpc_BattleFinishRequest_o *lastBattleFinishRequest = NULL;
Neon_Model_Api_Rpc_BattleStartRequest_o *lastBattleStartRequest = NULL;
Neon_Model_Api_Rpc_CharacterCostumeUpdateRequest_o *lastCharacterCostumeUpdateRequest = NULL;
Neon_Model_Api_Rpc_FormationUpdateRequest_o *lastFormationUpdateRequest = NULL;
Neon_Model_Api_Rpc_TipReleaseRequest_o *lastTipReleaseRequest = NULL;
Neon_Model_Api_Rpc_AdventureReadSequenceRequest_o *lastAdventureReadSequenceRequest = NULL;
Neon_Model_Api_Rpc_AdventureAcquireAreaItemRequest_o* lastAdventureAcquireAreaItemRequest = NULL;

struct ResponseTypeToRequestPtr RES_TYPE_TO_REQ_PTR_LIST_DATA[] = {
    {"Neon.Model.Api.Rpc.AuthSteamUserResponse", NULL, "/auth/steam_user"},
    {"Neon.Model.Api.Rpc.AuthNonceResponse", NULL, "/auth/nonce"},
    {"Neon.Model.Api.Rpc.AuthSignInResponse", NULL, "/auth/sign_in"},
    {"Neon.Model.Api.Rpc.UserLogInResponse", NULL, "/user/log_in"},
    {"Neon.Model.Api.Rpc.UserCrossDateResponse", NULL, "/user/cross_date"},
    {"Neon.Model.Api.Rpc.GachaListResponse", NULL, "/gacha/list"},
    {"Neon.Model.Api.Rpc.AdventureAreaObjectResponse", (Il2CppObject **)&lastAdventureAreaObjectRequest, "/adventure/area_object"},
    {"Neon.Model.Api.Rpc.AdventureMoveToAreaResponse", (Il2CppObject **)&lastAdventureMoveToAreaRequest, "/adventure/move_to_area"},
    {"Neon.Model.Api.Rpc.ChangedResourcesResponse", (Il2CppObject **)&lastUpdateCharacterStatusRequest, "/adventure/update_character_status"},
    {"Neon.Model.Api.Rpc.BattleFinishResponse", (Il2CppObject **)&lastBattleFinishRequest, "/battle/finish"},
    {"Neon.Model.Api.Rpc.BattleStartResponse", (Il2CppObject **)&lastBattleStartRequest, "/battle/start"},
    {"Neon.Model.Api.Rpc.ChangedResourcesResponse", (Il2CppObject **)&lastCharacterCostumeUpdateRequest, "/character/costume_update"},
    {"Neon.Model.Api.Rpc.ChangedResourcesResponse", (Il2CppObject **)&lastFormationUpdateRequest, "/formation/update"},
    {"Neon.Model.Api.Rpc.TipReleaseResponse", (Il2CppObject **)&lastTipReleaseRequest, "/tip/release"},
    {"Neon.Model.Api.Rpc.AdventureReadSequenceResponse", (Il2CppObject **)&lastAdventureReadSequenceRequest, "/adventure/read_sequence"},
    {"Neon.Model.Api.Rpc.AdventureAcquireAreaItemResponse", (Il2CppObject **)&lastAdventureAcquireAreaItemRequest, "/adventure/acquire_area_item"}
};

struct ResponseTypeToRequestPtr_List RES_TYPE_TO_REQ_PTR_LIST = {
    .len = STATIC_ARRAY_LEN(RES_TYPE_TO_REQ_PTR_LIST_DATA),
    .data = RES_TYPE_TO_REQ_PTR_LIST_DATA
};

Neon_Model_Api_ApiService__Adventure_AreaObject_FuncPtr fpNeon_Model_Api_ApiService__Adventure_AreaObject = NULL;

Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object___GetResult_FuncPtr fpSourceCore_GetResult = NULL;

CDGPJELFAMK__NOCKJHKDMGF_object__FuncPtr fpNeonApiGetResponse = NULL;

KBJLHEAOHMD__KPFFCLMEMEG_FuncPtr fpKbjlheaohmd__Kpffclmemeg = NULL;

Neon_Model_Api_ApiService__Tip_Release_FuncPtr fpNeon_Model_Api_ApiService__Tip_Release = NULL;

Neon_Model_Api_ApiService__Adventure_MoveToArea_FuncPtr fpNeon_Model_Api_ApiService__Adventure_MoveToArea = NULL;

Neon_Model_Api_ApiService__Battle_Start_FuncPtr fpNeon_Model_Api_ApiService__Battle_Start = NULL;

Neon_Model_Api_ApiService__Battle_Finish_FuncPtr fpNeon_Model_Api_ApiService__Battle_Finish = NULL;

Neon_Model_Api_ApiService__Adventure_UpdateCharacterStatus_FuncPtr fpNeon_Model_Api_ApiService__Adventure_UpdateCharacterStatus = NULL;

Neon_Model_Api_ApiService__Formation_Update_FuncPtr fpNeon_Model_Api_ApiService__Formation_Update = NULL;

Cysharp_Threading_Tasks_UniTask_ChangedResourcesResponse__o DetourFormationUpdate(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_FormationUpdateRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    lastFormationUpdateRequest = data;
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

Cysharp_Threading_Tasks_UniTask_ChangedResourcesResponse__o DetourUpdateCharacterStatus(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_AdventureUpdateCharacterStatusRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    lastUpdateCharacterStatusRequest = data;
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

Cysharp_Threading_Tasks_UniTask_BattleFinishResponse__o DetourBattleFinish(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_BattleFinishRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    lastBattleFinishRequest = data;
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

Cysharp_Threading_Tasks_UniTask_BattleStartResponse__o DetourBattleStart(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_BattleStartRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    lastBattleStartRequest = data;
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

Cysharp_Threading_Tasks_UniTask_AdventureMoveToAreaResponse__o DetourAdventureMoveToArea(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_AdventureMoveToAreaRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    lastAdventureMoveToAreaRequest = data;
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

Cysharp_Threading_Tasks_UniTask_TipReleaseResponse__o DetourTipRelease(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_TipReleaseRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    lastTipReleaseRequest = data;
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

Cysharp_Threading_Tasks_UniTask_AdventureAreaObjectResponse__o DetourAdventureAreaObject(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_AdventureAreaObjectRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    lastAdventureAreaObjectRequest = data;
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

Neon_Model_Api_ApiService__Adventure_ReadSequence_FuncPtr fpNeon_Model_Api_ApiService__Adventure_ReadSequence = NULL;

Cysharp_Threading_Tasks_UniTask_AdventureReadSequenceResponse__o DetourAdventure_ReadSequence (
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_AdventureReadSequenceRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    lastAdventureReadSequenceRequest = data;
    return fpNeon_Model_Api_ApiService__Adventure_ReadSequence(
        __this, data, requestHandler, cancellationToken, method
    );
}

void HookAdventure_ReadSequence(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)Neon_Model_Api_ApiService__Adventure_ReadSequence,
        (LPVOID)(uintptr_t)&DetourAdventure_ReadSequence,
        (LPVOID *)(&fpNeon_Model_Api_ApiService__Adventure_ReadSequence)
    ) != MH_OK) {
        fputs("Failed to create Neon_Model_Api_ApiService__Adventure_ReadSequence hook\n", stdout);
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)Neon_Model_Api_ApiService__Adventure_ReadSequence, /* changePermissions = */ FALSE) != MH_OK) {
        fputs("Failed to enable Neon_Model_Api_ApiService__Adventure_ReadSequence hook\n", stdout);
        return;
    }
}

Neon_Model_Api_ApiService__Auth_SteamUser_FuncPtr fpNeon_Model_Api_ApiService__Auth_SteamUser = NULL;

Cysharp_Threading_Tasks_UniTask_AuthSteamUserResponse__o DetourAuth_SteamUser(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_AuthSteamUserRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    if (ZERO_CONFIG.saveFile) {
        RunNimMainOnce();
        SembaLoadSave(ZERO_CONFIG.saveFile);
    }
    
    return fpNeon_Model_Api_ApiService__Auth_SteamUser(
        __this, data, requestHandler, cancellationToken, method
    );
}

void HookAuth_SteamUser(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)Neon_Model_Api_ApiService__Auth_SteamUser,
        (LPVOID)(uintptr_t)&DetourAuth_SteamUser,
        (LPVOID *)(&fpNeon_Model_Api_ApiService__Auth_SteamUser)
    ) != MH_OK) {
        fputs("Failed to create Neon_Model_Api_ApiService__Auth_SteamUser hook\n", stdout);
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)Neon_Model_Api_ApiService__Auth_SteamUser, /* changePermissions = */ FALSE) != MH_OK) {
        fputs("Failed to enable Neon_Model_Api_ApiService__Auth_SteamUser hook\n", stdout);
        return;
    }
}

Neon_Model_Api_ApiService__Adventure_AcquireAreaItem_FuncPtr fpNeon_Model_Api_ApiService__Adventure_AcquireAreaItem = NULL;

Cysharp_Threading_Tasks_UniTask_AdventureAcquireAreaItemResponse__o DetourAdventure_AcquireAreaItem(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_AdventureAcquireAreaItemRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    lastAdventureAcquireAreaItemRequest = data;
    return fpNeon_Model_Api_ApiService__Adventure_AcquireAreaItem(
        __this, data, requestHandler, cancellationToken, method
    );
}

void HookAdventure_AcquireAreaItem(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)Neon_Model_Api_ApiService__Adventure_AcquireAreaItem,
        (LPVOID)(uintptr_t)&DetourAdventure_AcquireAreaItem,
        (LPVOID *)(&fpNeon_Model_Api_ApiService__Adventure_AcquireAreaItem)
    ) != MH_OK) {
        fputs("Failed to create Neon_Model_Api_ApiService__Adventure_AcquireAreaItem hook\n", stdout);
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)Neon_Model_Api_ApiService__Adventure_AcquireAreaItem, /* changePermissions = */ FALSE) != MH_OK) {
        fputs("Failed to enable Neon_Model_Api_ApiService__Adventure_AcquireAreaItem hook\n", stdout);
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

typedef void (*HTTPRequestCtor)(Best_HTTP_HTTPRequest_o* __this, System_Uri_o* uri, int32_t methodType, const MethodInfo* method);
HTTPRequestCtor fpHTTPRequestCtor = NULL;

sds neonApiPath = NULL;

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

sds GetFqn(Il2CppObject *obj) {
    Il2CppClass *klass = obj ? obj->klass : NULL;
    sds res = NULL;
    if (klass) {
        res = sdscatprintf(sdsempty(), "%s.%s", klass->_1.namespaze, klass->_1.name);
    }
    return res;
}

struct ResponseTypeToRequestPtr *findResTypeToReqPtrWithReq(char *responseType) {
    struct ResponseTypeToRequestPtr *end = RES_TYPE_TO_REQ_PTR_LIST.data + RES_TYPE_TO_REQ_PTR_LIST.len;
    struct ResponseTypeToRequestPtr *it;
    for (it = RES_TYPE_TO_REQ_PTR_LIST.data; it != end; ++it) {
        if (!strcmp(responseType, it->responseType) && it->requestPtr && *it->requestPtr) {
            return it;
        }
    }

    return NULL;
}

struct ResponseTypeToRequestPtr *findResTypeToReqPtrWithoutReq(char *responseType) {
    struct ResponseTypeToRequestPtr *end = RES_TYPE_TO_REQ_PTR_LIST.data + RES_TYPE_TO_REQ_PTR_LIST.len;
    struct ResponseTypeToRequestPtr *it;
    for (it = RES_TYPE_TO_REQ_PTR_LIST.data; it != end; ++it) {
        if (!strcmp(responseType, it->responseType) && !it->requestPtr) {
            return it;
        }
    }

    return NULL;
}

Il2CppObject *DetourSourceCore_GetResult(
    Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__o __this,
    int16_t token,
    const MethodInfo_20B62E0* method
) {
    RunNimMainOnce();

    Il2CppObject *res = fpSourceCore_GetResult(__this, token, method);

    sds fqn = GetFqn(res);

    if (neonApiPath && fqn && strstr(fqn, "Neon.Model.Api.Rpc")) {
        printf("[DetourSourceCore_GetResult] %s\n", fqn);
        sds jsonRes = System_String_toSds(ConvertObjectToString((Il2CppObject *)res));
        struct ResponseTypeToRequestPtr *resTypeToReqPtr = findResTypeToReqPtrWithReq(fqn);
        sds jsonReq;
        if (resTypeToReqPtr) {
            jsonReq = System_String_toSds(ConvertObjectToString(*resTypeToReqPtr->requestPtr));
            *resTypeToReqPtr->requestPtr = NULL;
        } else {
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

re_t GetNeonModelApiPattern(void) {
    return re_compile("Neon.Model.Api.Rpc.\\w+");
}

sds MatchNeonModelApi(re_t patt, char *s) {
    int match_length;
    int match_idx = re_matchp(patt, s, &match_length);
    if (match_idx != -1) {
        return sdsnewlen(s + match_idx, match_length);
    }

    return NULL;
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

    struct ResponseTypeToRequestPtr *resTypeToReqPtr = findResTypeToReqPtrWithoutReq(resType);

    if (!resTypeToReqPtr) {
        resTypeToReqPtr = findResTypeToReqPtrWithReq(resType);
        if (resTypeToReqPtr) {
            sdsfree(reqJson);
            reqJson = System_String_toSds(ConvertObjectToString(*resTypeToReqPtr->requestPtr));
            *resTypeToReqPtr->requestPtr = NULL;
        }
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

Neon_Model_Api_ApiService__Character_CostumeUpdate_FuncPtr fpCharacter_CostumeUpdate = NULL;

Cysharp_Threading_Tasks_UniTask_ChangedResourcesResponse__o DetourCharacter_CostumeUpdate(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_CharacterCostumeUpdateRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    lastCharacterCostumeUpdateRequest = data;
    return fpCharacter_CostumeUpdate(
        __this, data, requestHandler, cancellationToken, method
    );
}

void HookCharacter_CostumeUpdate(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)Neon_Model_Api_ApiService__Character_CostumeUpdate,
        (LPVOID)(uintptr_t)&DetourCharacter_CostumeUpdate,
        (LPVOID *)&fpCharacter_CostumeUpdate
    ) != MH_OK) {
        printf("Failed to create Neon_Model_Api_ApiService__Character_CostumeUpdate hook\n");
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)Neon_Model_Api_ApiService__Character_CostumeUpdate, /* changePermissions = */ FALSE) != MH_OK) {
        printf("Failed to enable Neon_Model_Api_ApiService__Character_CostumeUpdate hook\n");
        return;
    }
}

void HookTN(void *GameAssembly) {
    InitGamePtrs(GameAssembly);

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
    HookCharacter_CostumeUpdate();
    HookAdventure_ReadSequence();
    HookAdventure_AcquireAreaItem();
    HookAuth_SteamUser();
}