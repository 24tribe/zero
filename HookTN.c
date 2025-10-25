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

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#define REASONABLE_STRING_SIZE 4096

Il2CppClass **System_Uri_TypeInfo = NULL;

typedef void (*URICONSTRUCTOR)(System_Uri_o* __this, System_String_o* uriString, const MethodInfo* method);
URICONSTRUCTOR System_Uri_ctor = NULL;

typedef Il2CppObject *(*SOURCE_CORE_GETRESULT)(Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__o __this, int16_t token, const MethodInfo_20B62E0* method);
SOURCE_CORE_GETRESULT Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object___GetResult = NULL;
SOURCE_CORE_GETRESULT fpSourceCore_GetResult = NULL;

Il2CppClass **Neon_Model_Api_Rpc_AuthSteamUserResponse_TypeInfo = NULL;

typedef void (*AUTH_STEAM_USER_RESPONSE_CTOR)(Neon_Model_Api_Rpc_AuthSteamUserResponse_o* __this, const MethodInfo* method);
AUTH_STEAM_USER_RESPONSE_CTOR Neon_Model_Api_Rpc_AuthSteamUserResponse___ctor = NULL;

typedef Cysharp_Threading_Tasks_UniTask_TResponse__o (*NEON_API_GET_RESPONSE)(CDGPJELFAMK_o* __this, BJAFDMJIDMJ_o* EFCDPGBOIHC, LPCOHPIGHIN_o* EAGJONBIADJ, System_Threading_CancellationToken_o JLCCEAFOLOE, Google_Protobuf_MessageParser_TResponse__o* PNICKJFPBHH, const MethodInfo_F6CAF0* method);
NEON_API_GET_RESPONSE NeonApiGetResponse = NULL; // CDGPJELFAMK__NOCKJHKDMGF_object_
NEON_API_GET_RESPONSE fpNeonApiGetResponse = NULL;

typedef bool (*KBJLHEAOHMD__KPFFCLMEMEG)(System_DateTime_o HKIOCIMKCCP, System_DateTime_o CJKBFINFMNP, const MethodInfo* method);
KBJLHEAOHMD__KPFFCLMEMEG Kbjlheaohmd__Kpffclmemeg = NULL;
KBJLHEAOHMD__KPFFCLMEMEG fpKbjlheaohmd__Kpffclmemeg = NULL;

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

typedef Cysharp_Threading_Tasks_UniTask_AuthSteamUserResponse__o (*APISERVICEAUTHSTEAMUSER)(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_AuthSteamUserRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
);
APISERVICEAUTHSTEAMUSER fpApiServiceAuthSteamUser = NULL;

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

void PutString(System_String_o *s) {
    int32_t sLen = s->fields._stringLength;
    uint16_t *firstChar = &(s->fields._firstChar);
    for (int32_t i = 0; i < sLen; ++i) {
        putchar((uint8_t)(firstChar[i]));
    }
    putchar('\n');
}

void DetourHTTPRequestCtor(Best_HTTP_HTTPRequest_o* __this, System_Uri_o* uri, int32_t methodType, const MethodInfo* method) {
    sds url = sds16to8(&(uri->fields.m_String->fields._firstChar), uri->fields.m_String->fields._stringLength);
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

Cysharp_Threading_Tasks_UniTask_AuthSteamUserResponse__o DetourApiServiceAuthSteamUser(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_AuthSteamUserRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    Cysharp_Threading_Tasks_UniTask_AuthSteamUserResponse__o res = fpApiServiceAuthSteamUser(
        __this, data, requestHandler, cancellationToken, method
    );   
    char sessionTicket[REASONABLE_STRING_SIZE] = {0};
    CopyUnicodeToByteArray(sessionTicket, data->fields.sessionTicket_);
    printf("AuthSteamUserRequest(sessionTicket='%s')\n", sessionTicket);    
    return res;
}

void HookApiServiceAuthSteamUser(void *GameAssembly) {
    void *addr = (char *)GameAssembly + 79412560;
    if (MH_CreateHook(addr, (LPVOID)(uintptr_t)&DetourApiServiceAuthSteamUser, (LPVOID *)&fpApiServiceAuthSteamUser) != MH_OK) {
        printf("Failed to create ApiServiceAuthSteamUser hook\n");
        return;
    }
    if (MH_EnableHook(addr, /* changePermissions = */ FALSE) != MH_OK) {
        printf("Failed to enable ApiServiceAuthSteamUser hook\n");
        return;
    }
}

Neon_Model_Api_Rpc_AuthSteamUserResponse_o *CreateAuthSteamUserResponse(int64_t userId) {
    Il2CppImage *neonModelDll = HelperGetImage("Neon.Model.dll");
    const Il2CppClass *AuthSteamUserResponse = HelperGetClass(neonModelDll, "AuthSteamUserResponse", "Neon.Model.Api.Rpc");

    if (!AuthSteamUserResponse) {
        printf("AuthSteamUserResponse class not found!\n");
    } else {
        Neon_Model_Api_Rpc_AuthSteamUserResponse_o *resp;
        resp = (Neon_Model_Api_Rpc_AuthSteamUserResponse_o *)il2cpp_object_new(AuthSteamUserResponse);
        Neon_Model_Api_Rpc_AuthSteamUserResponse___ctor(resp, NULL);
        resp->fields.userId_ = userId;
        printf("AuthSteamUserResponse created!!!!\n");
        return resp;
    }

    return NULL;
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

sds LOGIN_TIME = NULL;
    
Il2CppObject *GetMockResponse(Google_Protobuf_MessageParser_TResponse__o *messageParser) {
    Il2CppObject *res = NULL;
    System_String_o *s = ConvertObjectToString((Il2CppObject *)messageParser);
    sds sUtf8 = sds16to8(&(s->fields._firstChar), s->fields._stringLength);

    printf("[GetMockResponse] %s\n", sUtf8);

    if (strstr(sUtf8, "Neon.Model.Api.Rpc.AuthSteamUserResponse")) {        
        res = CallParseJson(
            messageParser,
            "{\"userId\": \"696969696969\"}"
        );
    } else if (strstr(sUtf8, "Neon.Model.Api.Rpc.AuthNonceResponse")) {
        res = CallParseJson(
            messageParser,
            "{\"nonce\": \"6969696969696969\"}"
        );
    } else if (strstr(sUtf8, "Neon.Model.Api.Rpc.AuthSignInResponse")) {
        res = CallParseJson(
            messageParser,
            "{\"sessionToken\": \"69696969-6969-6969-6969-696969696969\",\"language\": 2}"
        );
    } else if (strstr(sUtf8, "Neon.Model.Api.Rpc.UserLogInResponse")) {
        LOGIN_TIME = GetDateTime();
        sds userLogInResponseText = SlurpFile("responses\\2025_9_14_12_57_55_UserLogInResponse.txt");

        res = CallParseJson(messageParser, userLogInResponseText);

        sdsfree(userLogInResponseText);
    } else if (strstr(sUtf8, "Neon.Model.Api.Rpc.UserCrossDateResponse")) {
        sds userCrossDateResponseText = SlurpFile("responses\\2025_9_14_12_57_57_UserCrossDateResponse.txt");
        char *newResponse = ChangeLoggedInAtStr(userCrossDateResponseText, LOGIN_TIME);

        res = CallParseJson(messageParser, newResponse);

        sdsfree(userCrossDateResponseText);
        free(newResponse);
    } else if (strstr(sUtf8, "Neon.Model.Api.Rpc.AdventureAreaObjectResponse")) {
        sds adventureAreaObjectResponse = SlurpFile("responses\\2025_9_14_12_58_9_AdventureAreaObjectResponse.txt");

        res = CallParseJson(messageParser, adventureAreaObjectResponse);

        sdsfree(adventureAreaObjectResponse);
    } else if (strstr(sUtf8, "Neon.Model.Api.Rpc.AdventureMoveToAreaResponse")) {
        // Should return current login date
        sds adventureMoveToAreaResponse = SlurpFile("responses\\2025_9_14_12_58_12_AdventureMoveToAreaResponse.txt");
        char *newResponse = ChangeLoggedInAtStr(adventureMoveToAreaResponse, LOGIN_TIME);

        res = CallParseJson(messageParser, newResponse);

        sdsfree(adventureMoveToAreaResponse);
        free(newResponse);
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

    Neon_Model_Api_Rpc_AuthSteamUserResponse_TypeInfo = (Il2CppClass **)((unsigned long long)GameAssembly + 129188032ull);
    Neon_Model_Api_Rpc_AuthSteamUserResponse___ctor = (AUTH_STEAM_USER_RESPONSE_CTOR)((unsigned long long)GameAssembly + 7797904ull);

    Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object___GetResult = (SOURCE_CORE_GETRESULT)((unsigned long long)GameAssembly + 34300640ull);

    NeonApiGetResponse = (NEON_API_GET_RESPONSE)((unsigned long long)GameAssembly + 16173808ull);

    Kbjlheaohmd__Kpffclmemeg = (KBJLHEAOHMD__KPFFCLMEMEG)((unsigned long long)GameAssembly + 59260912ull);

    HookHTTPRequestCtor(GameAssembly);
    HookApiServiceAuthSteamUser(GameAssembly);
    HookSourceCore_GetResult(GameAssembly);
    HookNeonApiGetResponse();
    HookKbjlheaohmd__Kpffclmemeg();

    InitLogger(GameAssembly);
}