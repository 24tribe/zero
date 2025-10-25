/*
https://katyscode.wordpress.com/2021/01/14/il2cppinspector-tutorial-working-with-code-in-il2cpp-dll-injection-projects/
*/

#include "il2cpp_lean.h"

#include <MinHook.h>

#include <stdio.h>
#include <string.h>

Il2CppClass **System_Diagnostics_StackTrace_TypeInfo = NULL;
Il2CppClass **System_Uri_TypeInfo = NULL;

typedef Il2CppDomain *(*IL2CPPDOMAINGET)(void);
IL2CPPDOMAINGET il2cpp_domain_get = NULL;

typedef void (*IL2CPPTHREADATTACH)(Il2CppDomain *);
IL2CPPTHREADATTACH il2cpp_thread_attach = NULL;

typedef Il2CppObject *(*IL2CPPOBJECTNEW)(const Il2CppClass *klass);
IL2CPPOBJECTNEW il2cpp_object_new = NULL;

typedef System_String_o *(*IL2CPPSTRINGNEW)(char *s);
IL2CPPSTRINGNEW il2cpp_string_new = NULL;

typedef void (*HTTPRequestCtor)(Best_HTTP_HTTPRequest_o* __this, System_Uri_o* uri, int32_t methodType, const MethodInfo* method);
HTTPRequestCtor fpHTTPRequestCtor = NULL;

typedef void (*HTTPPROXYCONSTRUCTOR)(Best_HTTP_Proxies_HTTPProxy_o* __this, System_Uri_o* address, const MethodInfo* method);
typedef void (*URICONSTRUCTOR)(System_Uri_o* __this, System_String_o* uriString, const MethodInfo* method);
URICONSTRUCTOR System_Uri_ctor = NULL;

typedef void (*ONFGHC)(
    ONFKFJKNECJ_o* __this,
    System_Byte_array* NNINDKGNJFD,
    System_Byte_array* PHHLEEIDLBN,
    int32_t AIJNMMLONOD,
    const MethodInfo* method
);

ONFGHC fpOnfGhc = NULL;

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

    il2cpp_thread_attach(il2cpp_domain_get());
    
    System_Uri_o *uri = (System_Uri_o *)il2cpp_object_new(*System_Uri_TypeInfo);
    System_String_o *proxy = il2cpp_string_new(new_url);
    System_Uri_ctor(uri, proxy, NULL);

    return uri;
}
#undef NEW_URL_SIZE
#undef BASE_URL_SIZE

void copy_url(char *url, System_String_o *s) {
    int32_t sLen = s->fields._stringLength;
    uint16_t *firstChar = &(s->fields._firstChar);
    for (int32_t i = 0; i < sLen; ++i) {
        url[i] = (uint8_t)(firstChar[i]);
    }
}

void DetourHTTPRequestCtor(Best_HTTP_HTTPRequest_o* __this, System_Uri_o* uri, int32_t methodType, const MethodInfo* method) {
    printf("DetourHTTPRequestCtor called\n");

    System_Diagnostics_StackTrace_o *stackTrace;
    stackTrace = (System_Diagnostics_StackTrace_o *)il2cpp_object_new(*System_Diagnostics_StackTrace_TypeInfo);

    // PutString(uri->fields.m_String);
    char url[4096] = {0};
    copy_url(url, uri->fields.m_String);

    System_Uri_o *newUri = ChangeUrl(url);

    fpHTTPRequestCtor(__this, newUri ? newUri : uri, methodType, method);
    printf("Afetr ChangeProxy\n");
}

void DetourOnfGhc(
    ONFKFJKNECJ_o* __this,
    System_Byte_array* NNINDKGNJFD,
    System_Byte_array* PHHLEEIDLBN,
    int32_t AIJNMMLONOD,
    const MethodInfo* method
) {
    printf("OnfGhc called!\n");
    fpOnfGhc(__this, NNINDKGNJFD, PHHLEEIDLBN, AIJNMMLONOD, method);
}

void HookOnfGhc(void *GameAssembly) {
    void *addr = (char *)GameAssembly + 8877440;

    if (MH_CreateHook(addr, (LPVOID)(uintptr_t)&DetourOnfGhc, (LPVOID *)&fpOnfGhc) != MH_OK) {
        printf("Failed to create OnfGhc hook\n");
        return;
    }

    if (MH_EnableHook(addr, /* RemapSectionPermissions = */ FALSE) != MH_OK) {
        printf("Failed to enable OnfGhc hook\n");
        return;
    }
}

void HookHTTPRequestCtor(void *GameAssembly) {
    void *addr = (char *)GameAssembly + 10655472;
    if (MH_CreateHook(addr, (LPVOID)(uintptr_t)&DetourHTTPRequestCtor, (LPVOID *)(&fpHTTPRequestCtor)) != MH_OK) {
        fputs("Failed to create HTTPRequestCtor hook\n", stdout);
        return;
    }
    if (MH_EnableHook(addr, FALSE) != MH_OK) {
        fputs("Failed to enable HTTPRequestCtor hook\n", stdout);
        return;
    }
}

void HookIl2Cpp(void *GameAssembly) {
    il2cpp_domain_get = (IL2CPPDOMAINGET)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_domain_get");
    printf("il2cpp_domain_get: 0x%llx\n", (unsigned long long)il2cpp_domain_get);

    il2cpp_thread_attach = (IL2CPPTHREADATTACH)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_thread_attach");
    printf("il2cpp_thread_attach: 0x%llx\n", (unsigned long long)il2cpp_thread_attach);

    il2cpp_object_new = (IL2CPPOBJECTNEW)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_object_new");
    printf("il2cpp_object_new: 0x%llx\n", (unsigned long long)il2cpp_object_new);

    il2cpp_string_new = (IL2CPPSTRINGNEW)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_string_new");
    printf("il2cpp_string_new: 0x%llx\n", (unsigned long long)il2cpp_string_new);

    System_Diagnostics_StackTrace_TypeInfo = (Il2CppClass **)((unsigned long long)GameAssembly + 129545976ull);

    System_Uri_TypeInfo = (Il2CppClass **)((unsigned long long)GameAssembly + 129866520ull);
    System_Uri_ctor = (URICONSTRUCTOR)((unsigned long long)GameAssembly + 94439536ull);

    HookHTTPRequestCtor(GameAssembly);
    HookOnfGhc(GameAssembly);
}

void PutString(System_String_o *s) {
    int32_t sLen = s->fields._stringLength;
    uint16_t *firstChar = &(s->fields._firstChar);
    for (int32_t i = 0; i < sLen; ++i) {
        putchar((uint8_t)(firstChar[i]));
    }
    putchar('\n');
}