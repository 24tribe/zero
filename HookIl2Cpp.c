/*
https://katyscode.wordpress.com/2021/01/14/il2cppinspector-tutorial-working-with-code-in-il2cpp-dll-injection-projects/
*/

#include "il2cpp_shared.h"
#include "HookTN.h"

#include <windows.h>

#include <string.h>
#include <stdio.h>

IL2CPPDOMAINGET il2cpp_domain_get = NULL;
IL2CPPTHREADATTACH il2cpp_thread_attach = NULL;
IL2CPPOBJECTNEW il2cpp_object_new = NULL;
IL2CPPSTRINGNEW il2cpp_string_new = NULL;

void HookIl2Cpp(void *GameAssembly, const char *gameName) {
    il2cpp_domain_get = (IL2CPPDOMAINGET)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_domain_get");
    printf("il2cpp_domain_get: 0x%llx\n", (unsigned long long)il2cpp_domain_get);

    il2cpp_thread_attach = (IL2CPPTHREADATTACH)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_thread_attach");
    printf("il2cpp_thread_attach: 0x%llx\n", (unsigned long long)il2cpp_thread_attach);

    il2cpp_object_new = (IL2CPPOBJECTNEW)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_object_new");
    printf("il2cpp_object_new: 0x%llx\n", (unsigned long long)il2cpp_object_new);

    il2cpp_string_new = (IL2CPPSTRINGNEW)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_string_new");
    printf("il2cpp_string_new: 0x%llx\n", (unsigned long long)il2cpp_string_new);

    if (!strcmp(gameName, "Build")) {
        /* do nothing yet */
    } else if (!strcmp(gameName, "TRIBENINE")) {
        HookTN(GameAssembly);
    } else {
        printf("Unknown name '%s', HookIl2Cpp not applied!\n", gameName);
    }
}