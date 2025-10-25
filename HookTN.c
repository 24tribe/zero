#include "HookTN.h"
#include "il2cpp_lean.h"

#include <MinHook.h>

#include <stdio.h>
#include <string.h>

#define REASONABLE_STRING_SIZE 4096

Il2CppClass **System_Diagnostics_StackTrace_TypeInfo = NULL;
Il2CppClass **System_Uri_TypeInfo = NULL;
Il2CppClass **UniTaskCompletionSource_TypeInfo = NULL;
Il2CppClass **UniTask_TypeInfo = NULL;

typedef void (*URICONSTRUCTOR)(System_Uri_o* __this, System_String_o* uriString, const MethodInfo* method);
URICONSTRUCTOR System_Uri_ctor = NULL;

typedef void (*STACKTRACECONSTRUCTOR)(System_Diagnostics_StackTrace_o* __this, const MethodInfo* method);
STACKTRACECONSTRUCTOR System_Diagnostics_StackTrace_ctor = NULL;

typedef Cysharp_Threading_Tasks_UniTask_o (*CONTINUEWITH)(Cysharp_Threading_Tasks_UniTask_T__o task, System_Action_T__o* continuationFunction, const MethodInfo_110C390* method);
CONTINUEWITH Cysharp_Threading_Tasks_UniTaskExtensions__ContinueWith_object_ = NULL;

typedef void (*UCS_OBJECT_CTOR)(Cysharp_Threading_Tasks_UniTaskCompletionSource_o *__this, const MethodInfo *);
UCS_OBJECT_CTOR UniTaskCompletionSource_object_ctor = NULL;

typedef bool (*TRYSETRESULT)(Cysharp_Threading_Tasks_UniTaskCompletionSource_T__o* __this, Il2CppObject* result, const MethodInfo_2352A00* method);
TRYSETRESULT Cysharp_Threading_Tasks_UniTaskCompletionSource_object___TrySetResult = NULL;
TRYSETRESULT fpTrySetResult = NULL;

typedef bool (*SYSTEMTRYSETRESULT)(System_Threading_Tasks_TaskCompletionSource_object__o* __this, Il2CppObject* result, const MethodInfo_223E1D0* method);
SYSTEMTRYSETRESULT System_Threading_Tasks_TaskCompletionSource_object___TrySetResult = NULL;
SYSTEMTRYSETRESULT fpSystemTrySetResult = NULL;

typedef Il2CppObject *(*GETRESULT)(Cysharp_Threading_Tasks_UniTask_Awaiter_object__o __this, const MethodInfo_2ED6660* method);
GETRESULT fpGetResult = NULL;
GETRESULT Cysharp_Threading_Tasks_UniTask_Awaiter_object___GetResult = NULL;

typedef Il2CppObject *(*IUNITASKSOURCE_GETRESULT)(Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__o* __this, int16_t token, const MethodInfo_21C8770* method);
IUNITASKSOURCE_GETRESULT fpIUniTaskSource_GetResult = NULL;
IUNITASKSOURCE_GETRESULT Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_object___Cysharp_Threading_Tasks_IUniTaskSource_T__GetResult = NULL;

typedef Il2CppObject *(*SOURCE_CORE_GETRESULT)(Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__o __this, int16_t token, const MethodInfo_20B62E0* method);
SOURCE_CORE_GETRESULT Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object___GetResult = NULL;
SOURCE_CORE_GETRESULT fpSourceCore_GetResult = NULL;

/*
typedef void (*UNITASK_CTOR)(Cysharp_Threading_Tasks_UniTask_o __this, Cysharp_Threading_Tasks_IUniTaskSource_o* source, int16_t token, const MethodInfo* method);
UNITASK_CTOR UniTask_ctor = NULL;
*/

typedef System_String_o *(*System_Diagnostics_StackTrace_toString)(System_Diagnostics_StackTrace_o *, const MethodInfo *);

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

bool stackTraceDone = false;

void DetourHTTPRequestCtor(Best_HTTP_HTTPRequest_o* __this, System_Uri_o* uri, int32_t methodType, const MethodInfo* method) {
    il2cpp_thread_attach(il2cpp_domain_get());

    printf("DetourHTTPRequestCtor called\n");

    if (0 && !stackTraceDone) {
        System_Diagnostics_StackTrace_o *stackTrace;
        stackTrace = (System_Diagnostics_StackTrace_o *)il2cpp_object_new(*System_Diagnostics_StackTrace_TypeInfo);
        System_Diagnostics_StackTrace_ctor(stackTrace, NULL);

        VirtualInvokeData *toString = &(stackTrace->klass->vtable._3_ToString);
        System_Diagnostics_StackTrace_toString toStringFunc;
        toStringFunc = (System_Diagnostics_StackTrace_toString)(uintptr_t)(toString->methodPtr);
        System_String_o *stackTraceStr = toStringFunc(stackTrace, toString->method);

        PutString(stackTraceStr);

        stackTraceDone = true;
    }

    // PutString(uri->fields.m_String);
    char url[4096] = {0};
    CopyUnicodeToByteArray(url, uri->fields.m_String);

    System_Uri_o *newUri = ChangeUrl(url);

    fpHTTPRequestCtor(__this, newUri ? newUri : uri, methodType, method);
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

bool DetourSystemTrySetResult(
    System_Threading_Tasks_TaskCompletionSource_object__o* __this,
    Il2CppObject* result,
    const MethodInfo_223E1D0* method
) {
    printf("name: %s\n", result->klass->_1.name);
    printf("DetourSystemTrySetResult called!\n");
    return fpSystemTrySetResult(__this, result, method);
}

void HookSystemTrySetResult(void *GameAssembly) {
    (void)GameAssembly;

    if (MH_CreateHook(
        (void *)(uintptr_t)System_Threading_Tasks_TaskCompletionSource_object___TrySetResult,
        (LPVOID)(uintptr_t)&DetourSystemTrySetResult,
        (LPVOID *)(&fpSystemTrySetResult)
    ) != MH_OK) {
        fputs("Failed to create SystemTrySetResult hook\n", stdout);
        return;
    }

    if (MH_EnableHook(
        (void *)(uintptr_t)System_Threading_Tasks_TaskCompletionSource_object___TrySetResult,
        /* changePermissions = */ FALSE
    ) != MH_OK) {
        fputs("Failed to enable SystemTrySetResult hook\n", stdout);
        return;
    }
}

Il2CppObject *DetourIUniTaskSource_GetResult(
    Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__o* __this,
    int16_t token,
    const MethodInfo_21C8770* method
) {
    printf("DetourIUniTaskSource_GetResult called!!!\n");
    return fpIUniTaskSource_GetResult(__this, token, method);
}

void HookIUniTaskSource_GetResult(void *GameAssembly) {
    (void)GameAssembly;

    if (MH_CreateHook(
        (void *)(uintptr_t)Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_object___Cysharp_Threading_Tasks_IUniTaskSource_T__GetResult,
        (LPVOID)(uintptr_t)&DetourIUniTaskSource_GetResult,
        (LPVOID *)(&fpIUniTaskSource_GetResult)
    ) != MH_OK) {
        fputs("Failed to create SystemTrySetResult hook\n", stdout);
        return;
    }

    if (MH_EnableHook(
        (void *)(uintptr_t)Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_object___Cysharp_Threading_Tasks_IUniTaskSource_T__GetResult,
        /* changePermissions = */ FALSE
    ) != MH_OK) {
        fputs("Failed to enable SystemTrySetResult hook\n", stdout);
        return;
    }
}

Il2CppObject * DetourGetResult(
    Cysharp_Threading_Tasks_UniTask_Awaiter_object__o __this,
    const MethodInfo_2ED6660* method
) {
    Il2CppObject *res = fpGetResult(__this, method);

    printf("DetourGetResult name: %s\n", res->klass->_1.name);
    return res;
}

void HookGetResult(void *GameAssembly) {
    (void)GameAssembly;

    if (MH_CreateHook(
        (void *)(uintptr_t)Cysharp_Threading_Tasks_UniTask_Awaiter_object___GetResult,
        (LPVOID)(uintptr_t)&DetourGetResult,
        (LPVOID *)(&fpGetResult)
    ) != MH_OK) {
        fputs("Failed to create TrySetResult hook\n", stdout);
        return;
    }

    if (MH_EnableHook(
        (void *)(uintptr_t)Cysharp_Threading_Tasks_UniTask_Awaiter_object___GetResult,
        /* changePermissions = */ FALSE
    ) != MH_OK) {
        fputs("Failed to enable TrySetResult hook\n", stdout);
        return;
    }
}

bool DetourTrySetResult(
    Cysharp_Threading_Tasks_UniTaskCompletionSource_T__o* __this,
    Il2CppObject* result,
    const MethodInfo_2352A00* method
) {
    printf("name: %s\n", result->klass->_1.name);
    printf("DetourTrySetResult called!\n");
    return fpTrySetResult(__this, result, method);
}

void HookTrySetResult(void *GameAssembly) {
    (void)GameAssembly;

    if (MH_CreateHook(
        (void *)(uintptr_t)Cysharp_Threading_Tasks_UniTaskCompletionSource_object___TrySetResult,
        (LPVOID)(uintptr_t)&DetourTrySetResult,
        (LPVOID *)(&fpTrySetResult)
    ) != MH_OK) {
        fputs("Failed to create TrySetResult hook\n", stdout);
        return;
    }

    if (MH_EnableHook(
        (void *)(uintptr_t)Cysharp_Threading_Tasks_UniTaskCompletionSource_object___TrySetResult,
        /* changePermissions = */ FALSE
    ) != MH_OK) {
        fputs("Failed to enable TrySetResult hook\n", stdout);
        return;
    }
}

// [How Async and Await Work](https://www.jacksondunstan.com/articles/4918)
Il2CppObject *DetourSourceCore_GetResult(
    Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__o __this,
    int16_t token,
    const MethodInfo_20B62E0* method
) {
    Il2CppObject *res = fpSourceCore_GetResult(__this, token, method);
    const char *name = "unknown";
    if (res) {
        Il2CppClass *klass = res->klass;
    
        if (klass) {
            name = klass->_1.name;
        }
    }
    
    printf("DetourSourceCore_GetResult(%s)\n", name);
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

/*
References:
[UniTaskCompletionSource example](https://github.com/Cysharp/UniTask)
[TaskCompletionSource explanation](https://stackoverflow.com/questions/27891253/how-to-create-a-task-i-can-complete-manually)
[Task.ContinueWith example](https://stackoverflow.com/questions/8244428/where-to-define-callback-for-task-based-asynchronous-method)
[Task.ContinueWith docs](https://learn.microsoft.com/en-us/dotnet/api/system.threading.tasks.task.continuewith)
[Delegate type](https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/reference-types#the-delegate-type)
[Task.FromResult](https://stackoverflow.com/questions/19568280/what-is-the-use-for-task-fromresulttresult)
[How Async and Await works](https://www.jacksondunstan.com/articles/4918)

Pseudocode:
using System;
using System.Threading.Tasks;

namespace AsyncBreakfast
{
    internal class UserResponse {
        public int UserId;
    }

    class Program
    {
        static async Task Main(string[] args)
        {
            Console.WriteLine($"[VICTIM] Waiting for UserResponse...");
            var res = await AttackerGetUserResponse();
            Console.WriteLine($"[VICTIM] Got UserId = {res.UserId}");
        }

        public static Task<UserResponse> AttackerGetUserResponse() {
            Console.WriteLine("[ATTACKER] AttackerGetUserResponse called!");
            var tcs = new TaskCompletionSource<UserResponse>();
            var res = GetUserResponse();
            res.ContinueWith((task) => {
                var userResponse = task.Result;
                Console.WriteLine($"[ATTACKER] Got UserId of {userResponse.UserId} changing to 80085...");
                userResponse.UserId = 80085;
                tcs.SetResult(userResponse);
            });
            return tcs.Task;
        }

        // TARGET METHOD
        public static async Task<UserResponse> GetUserResponse() {
            await Task.Delay(3000); // Simulate work
            return new UserResponse {UserId = 6969};
        }
    }
}
*/

Cysharp_Threading_Tasks_UniTask_AuthSteamUserResponse__o DetourApiServiceAuthSteamUser(
    Neon_Model_Api_ApiService_o* __this,
    Neon_Model_Api_Rpc_AuthSteamUserRequest_o* data,
    LPCOHPIGHIN_o* requestHandler,
    System_Threading_CancellationToken_o cancellationToken,
    const MethodInfo* method
) {
    printf(
        "DetourApiServiceAuthSteamUser(requestHandler=0x%llx, )\n",
        (unsigned long long)requestHandler
    );

    Cysharp_Threading_Tasks_UniTask_AuthSteamUserResponse__o res = fpApiServiceAuthSteamUser(
        __this, data, requestHandler, cancellationToken, method
    );

    char sessionTicket[REASONABLE_STRING_SIZE] = {0};
    CopyUnicodeToByteArray(sessionTicket, data->fields.sessionTicket_);
    printf("SessionTicket: %s\n", sessionTicket);

    /*
    Cysharp_Threading_Tasks_UniTaskCompletionSource_o *ucs;
    ucs = (Cysharp_Threading_Tasks_UniTaskCompletionSource_o *)il2cpp_object_new(*UniTaskCompletionSource_TypeInfo);
    UniTaskCompletionSource_object_ctor(ucs, NULL);

    res.fields.source = (Cysharp_Threading_Tasks_IUniTaskSource_T__o *)ucs;
    res.fields.token = 0;
    */
    
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
    System_Diagnostics_StackTrace_TypeInfo = (Il2CppClass **)((unsigned long long)GameAssembly + 129545976ull);
    System_Diagnostics_StackTrace_ctor = (STACKTRACECONSTRUCTOR)((unsigned long long)GameAssembly + 55774032ull);

    System_Uri_TypeInfo = (Il2CppClass **)((unsigned long long)GameAssembly + 129866520ull);
    System_Uri_ctor = (URICONSTRUCTOR)((unsigned long long)GameAssembly + 94439536ull);

    UniTaskCompletionSource_TypeInfo = (Il2CppClass **)((unsigned long long)GameAssembly + 129829624ull);
    UniTaskCompletionSource_object_ctor = (UCS_OBJECT_CTOR)((unsigned long long)GameAssembly + 7797904ull);
    
    Cysharp_Threading_Tasks_UniTaskExtensions__ContinueWith_object_ = (CONTINUEWITH)((unsigned long long)GameAssembly + 17875856ull);
    
    Cysharp_Threading_Tasks_UniTaskCompletionSource_object___TrySetResult = (TRYSETRESULT)((unsigned long long)GameAssembly + 37038592ull);

    System_Threading_Tasks_TaskCompletionSource_object___TrySetResult = (SYSTEMTRYSETRESULT)((unsigned long long)GameAssembly + 35906000ull);

    Cysharp_Threading_Tasks_UniTask_Awaiter_object___GetResult = (GETRESULT)((unsigned long long)GameAssembly + 49112672ull);

    Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_object___Cysharp_Threading_Tasks_IUniTaskSource_T__GetResult = (IUNITASKSOURCE_GETRESULT)((unsigned long long)GameAssembly + 35424112ull);
    
    
    Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object___GetResult = (SOURCE_CORE_GETRESULT)((unsigned long long)GameAssembly + 34300640ull);
    /*
    UniTask_TypeInfo = (Il2CppClass **)((unsigned long long)GameAssembly + 129829232ull);
    UniTask_ctor = (UNITASK_CTOR)((unsigned long long)GameAssembly + 29172256ull);
    */
    
    // HookHTTPRequestCtor(GameAssembly);
    HookApiServiceAuthSteamUser(GameAssembly);
    HookTrySetResult(GameAssembly);
    HookGetResult(GameAssembly);
    HookSystemTrySetResult(GameAssembly);
    HookIUniTaskSource_GetResult(GameAssembly);
    HookSourceCore_GetResult(GameAssembly);
}