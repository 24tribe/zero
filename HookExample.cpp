extern "C" {
    #include "il2cpp_shared.h"
}
#include "il2cpp_example.h"

extern "C" {
    #include <MinHook.h>
    #include "utils.h"
}
#include <stdio.h>

typedef void (*NEW_BEHAVIOUR_SCRIPT_START)(NewBehaviourScript_o* __this, const MethodInfo* method);
NEW_BEHAVIOUR_SCRIPT_START NewBehaviourScript__Start = NULL;
NEW_BEHAVIOUR_SCRIPT_START fpNewBehaviourScript__Start = NULL;

typedef void (*NEW_BEHAVIOUR_SCRIPT_SUDO)(NewBehaviourScript_o* __this, System_Action_string__o* cb, System_String_o* s, const MethodInfo* method);
NEW_BEHAVIOUR_SCRIPT_SUDO NewBehaviourScript__Sudo = NULL;
NEW_BEHAVIOUR_SCRIPT_SUDO fpNewBehaviourScript__Sudo = NULL;

typedef (*SYSTEM_ACTION_OBJECT_CTOR)(System_Action_object__o* __this, Il2CppObject* object, intptr_t met, const MethodInfo_108E1F0* method);
SYSTEM_ACTION_OBJECT_CTOR System_Action_object____ctor;

typedef void (*SET_TEXT)(TMPro_TextMeshProUGUI_o* __this, System_String_o *text, const MethodInfo *method);
Il2CppClass **System_Action_object_TypeInfo;
Il2CppClass **System_Action_string_TypeInfo;

struct MyData {
    int x;
};

void MyAction(void *idk, System_String_o *text, const MethodInfo *method) {
    (void)idk;
    (void)method;
    
    char s[4096] = {0};
    CopyUnicodeToByteArray(s, text);
    printf("text=%s\n", s);
}

void ChangeText(NewBehaviourScript_o *__this) {
    System_String_o *s = il2cpp_string_new((char *)"Mariana Maga\x01ña des\nenmarañará mañana la maraña que enmarañara Mariana Magaña.");
    VirtualInvokeData *vid = &(__this->fields.tmp_pro->klass->vtable._66_set_text);
    ((SET_TEXT)(vid->methodPtr))(__this->fields.tmp_pro, s, vid->method);
}

void DetourNewBehaviourScript__Sudo(
    NewBehaviourScript_o* __this, System_Action_string__o* cb, System_String_o* s, const MethodInfo* method
) {
    il2cpp_thread_attach(il2cpp_domain_get());
    printf("DetourNewBehaviourScript__Sudo called!!\n");

    /*
    press_enter_to_continue();
    ChangeText(__this);
    */

    /*
    System_Action_string__o *myCb = (System_Action_string__o*)il2cpp_object_new(*System_Action_string_TypeInfo);
    printf("Created System_Action_string__o...\n");

    System_Action_object____ctor((System_Action_object__o *)myCb, (Il2CppObject *)s, (intptr_t)MyAction, NULL);
    printf("Called System_Action_object__o constructor...\n");
    */

    return fpNewBehaviourScript__Sudo(__this, cb, s, method);
}

void DetourNewBehaviourScript__Start(NewBehaviourScript_o* __this, const MethodInfo* method) {
    il2cpp_thread_attach(il2cpp_domain_get());
    printf("DetourNewBehaviourScript__Start called!!\n");
    
    fpNewBehaviourScript__Start(__this, method);

    ChangeText(__this);
}

extern "C" void HookExample(void *GameAssembly) {
    

    printf("Hello World!!! GameAssembly=0x%llx\n", (unsigned long long)GameAssembly);

    NewBehaviourScript__Start = (NEW_BEHAVIOUR_SCRIPT_START)((unsigned long long)GameAssembly + 12725488ull);
    NewBehaviourScript__Sudo = (NEW_BEHAVIOUR_SCRIPT_SUDO)((unsigned long long)GameAssembly + 12725632ull);
    System_Action_object____ctor = (SYSTEM_ACTION_OBJECT_CTOR)((unsigned long long)GameAssembly + 17359344ull);
    System_Action_object_TypeInfo = (Il2CppClass **)((unsigned long long)GameAssembly + 86696560ull);
    System_Action_string_TypeInfo = (Il2CppClass **)((unsigned long long)GameAssembly + 86697072ull);

    if (MH_CreateHook(
        (void *)(uintptr_t)NewBehaviourScript__Start,
        (LPVOID)(uintptr_t)&DetourNewBehaviourScript__Start,
        (LPVOID *)&fpNewBehaviourScript__Start
    ) != MH_OK) {
        printf("FAiled to create NewBehaviourScript__Start hook\n");
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)NewBehaviourScript__Start, /* ChangePerms = */ TRUE) != MH_OK) {
        printf("FAiled to enable NewBehaviourScript__Start hook\n");
        return;
    }

    if (MH_CreateHook(
        (void *)(uintptr_t)NewBehaviourScript__Sudo,
        (LPVOID)(uintptr_t)&DetourNewBehaviourScript__Sudo,
        (LPVOID *)&fpNewBehaviourScript__Sudo
    ) != MH_OK) {
        printf("FAiled to create NewBehaviourScript__Sudo hook\n");
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)NewBehaviourScript__Sudo, /* ChangePerms = */ TRUE) != MH_OK) {
        printf("FAiled to enable NewBehaviourScript__Sudo hook\n");
        return;
    }
}