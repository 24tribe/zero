/*
https://katyscode.wordpress.com/2021/01/14/il2cppinspector-tutorial-working-with-code-in-il2cpp-dll-injection-projects/
https://github.com/jadis0x/il2cpp-reverse-engineering-guide
https://code.apowo.com/opensource/il2cpp_plus
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
IL2CPPRUNTIMECLASSINIT il2cpp_runtime_class_init = NULL;
IL2CPP_DOMAIN_GET_ASSEMBLIES il2cpp_domain_get_assemblies = NULL;
IL2CPP_IMAGE_GET_NAME il2cpp_image_get_name = NULL;
IL2CPP_IMAGE_GET_CLASS_COUNT il2cpp_image_get_class_count = NULL;
IL2CPP_IMAGE_GET_CLASS il2cpp_image_get_class = NULL;
IL2CPP_CLASS_GET_NAMESPACE il2cpp_class_get_namespace = NULL;
IL2CPP_CLASS_GET_NAME il2cpp_class_get_name = NULL;
IL2CPP_METHOD_GET_RETURN_TYPE il2cpp_method_get_return_type = NULL;
IL2CPP_METHOD_GET_NAME il2cpp_method_get_name = NULL;
IL2CPP_CLASS_GET_METHODS il2cpp_class_get_methods = NULL;
IL2CPP_TYPE_GET_NAME il2cpp_type_get_name = NULL;
IL2CPP_FREE il2cpp_free = NULL;
IL2CPP_CLASS_GET_METHOD_FROM_NAME il2cpp_class_get_method_from_name = NULL;
IL2CPP_RUNTIME_INVOKE il2cpp_runtime_invoke = NULL;
IL2CPP_TYPE_GET_OBJECT il2cpp_type_get_object = NULL;
IL2CPP_TYPE_GET_CLASS_OR_ELEMENT_CLASS il2cpp_type_get_class_or_element_class = NULL;
IL2CPP_OBJECT_GET_CLASS il2cpp_object_get_class = NULL;

void HookIl2Cpp(void *GameAssembly) {
    il2cpp_domain_get = (IL2CPPDOMAINGET)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_domain_get");
    printf("il2cpp_domain_get: 0x%llx\n", (unsigned long long)il2cpp_domain_get);

    il2cpp_thread_attach = (IL2CPPTHREADATTACH)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_thread_attach");
    printf("il2cpp_thread_attach: 0x%llx\n", (unsigned long long)il2cpp_thread_attach);

    il2cpp_object_new = (IL2CPPOBJECTNEW)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_object_new");
    printf("il2cpp_object_new: 0x%llx\n", (unsigned long long)il2cpp_object_new);

    il2cpp_string_new = (IL2CPPSTRINGNEW)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_string_new");
    printf("il2cpp_string_new: 0x%llx\n", (unsigned long long)il2cpp_string_new);

    il2cpp_runtime_class_init = (IL2CPPRUNTIMECLASSINIT)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_runtime_class_init");
    printf("il2cpp_runtime_class_init: 0x%llx\n", (unsigned long long)il2cpp_runtime_class_init);

    il2cpp_domain_get_assemblies = (IL2CPP_DOMAIN_GET_ASSEMBLIES)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_domain_get_assemblies");
    printf("il2cpp_domain_get_assemblies: 0x%llx\n", (unsigned long long)il2cpp_domain_get_assemblies);

    il2cpp_image_get_name = (IL2CPP_IMAGE_GET_NAME)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_image_get_name");
    printf("il2cpp_image_get_name: 0x%llx\n", (unsigned long long)il2cpp_image_get_name);

    il2cpp_image_get_class_count = (IL2CPP_IMAGE_GET_CLASS_COUNT)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_image_get_class_count");
    printf("il2cpp_image_get_class_count: 0x%llx\n", (unsigned long long)il2cpp_image_get_class_count);

    il2cpp_image_get_class = (IL2CPP_IMAGE_GET_CLASS)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_image_get_class");
    printf("il2cpp_image_get_class: 0x%llx\n", (unsigned long long)il2cpp_image_get_class);

    il2cpp_class_get_namespace = (IL2CPP_CLASS_GET_NAMESPACE)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_class_get_namespace");
    printf("il2cpp_class_get_namespace: 0x%llx\n", (unsigned long long)il2cpp_class_get_namespace);

    il2cpp_class_get_name = (IL2CPP_CLASS_GET_NAMESPACE)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_class_get_name");
    printf("il2cpp_class_get_name: 0x%llx\n", (unsigned long long)il2cpp_class_get_name);

    il2cpp_class_get_methods = (IL2CPP_CLASS_GET_METHODS)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_class_get_methods");
    printf("il2cpp_class_get_methods: 0x%llx\n", (unsigned long long)il2cpp_class_get_methods);

    il2cpp_method_get_name = (IL2CPP_METHOD_GET_NAME)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_method_get_name");
    printf("il2cpp_method_get_name: 0x%llx\n", (unsigned long long)il2cpp_method_get_name);

    il2cpp_method_get_return_type = (IL2CPP_METHOD_GET_RETURN_TYPE)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_method_get_return_type");
    printf("il2cpp_method_get_return_type: 0x%llx\n", (unsigned long long)il2cpp_method_get_return_type);

    il2cpp_type_get_name = (IL2CPP_TYPE_GET_NAME)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_type_get_name");
    printf("il2cpp_type_get_name: 0x%llx\n", (unsigned long long)il2cpp_type_get_name);

    il2cpp_free = (IL2CPP_FREE)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_free");
    printf("il2cpp_free: 0x%llx\n", (unsigned long long)il2cpp_free);
    
    il2cpp_class_get_method_from_name = (IL2CPP_CLASS_GET_METHOD_FROM_NAME)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_class_get_method_from_name");
    printf("il2cpp_class_get_method_from_name: 0x%llx\n", (unsigned long long)il2cpp_class_get_method_from_name);

    il2cpp_runtime_invoke = (IL2CPP_RUNTIME_INVOKE)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_runtime_invoke");
    printf("il2cpp_runtime_invoke: 0x%llx\n", (unsigned long long)il2cpp_runtime_invoke);

    il2cpp_type_get_object = (IL2CPP_TYPE_GET_OBJECT)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_type_get_object");
    printf("il2cpp_type_get_object: 0x%llx\n", (unsigned long long)il2cpp_type_get_object);

    il2cpp_type_get_class_or_element_class = (IL2CPP_TYPE_GET_CLASS_OR_ELEMENT_CLASS)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_type_get_class_or_element_class");
    printf("il2cpp_type_get_class_or_element_class: 0x%llx\n", (unsigned long long)il2cpp_type_get_class_or_element_class);

    il2cpp_object_get_class = (IL2CPP_OBJECT_GET_CLASS)(uintptr_t)GetProcAddress(GameAssembly, "il2cpp_object_get_class");
    printf("il2cpp_object_get_class: 0x%llx\n", (unsigned long long)il2cpp_object_get_class);

    HookTN(GameAssembly);
}