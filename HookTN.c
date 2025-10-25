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

void HookTN(void *GameAssembly) {
    System_Uri_TypeInfo = (Il2CppClass **)((unsigned long long)GameAssembly + 129866520ull);
    System_Uri_ctor = (URICONSTRUCTOR)((unsigned long long)GameAssembly + 94439536ull);
    
    Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object___GetResult = (SOURCE_CORE_GETRESULT)((unsigned long long)GameAssembly + 34300640ull);

    HookHTTPRequestCtor(GameAssembly);
    HookApiServiceAuthSteamUser(GameAssembly);
    HookSourceCore_GetResult(GameAssembly);

    InitLogger(GameAssembly);
}