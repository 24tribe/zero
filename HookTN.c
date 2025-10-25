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
    
    /*
    UniTask_TypeInfo = (Il2CppClass **)((unsigned long long)GameAssembly + 129829232ull);
    UniTask_ctor = (UNITASK_CTOR)((unsigned long long)GameAssembly + 29172256ull);
    */
    
    // HookHTTPRequestCtor(GameAssembly);
    HookApiServiceAuthSteamUser(GameAssembly);
}