#include "HookAddressables.h"

#include "Logger.h"
#include "il2cpp_lean.h"
#include "MinHook.h"
#include "defer.h"
#include "utils.h"
#include "Config.h"

#include <stddef.h>
#include <stdio.h>

typedef UnityEngine_ResourceManagement_AsyncOperations_AsyncOperationHandle_TObject__o
(*UnityEngine_AddressableAssets_AddressablesImpl__LoadAssetAsync_object__FuncPtr)
(UnityEngine_AddressableAssets_AddressablesImpl_o* __this, Il2CppObject* key, const MethodInfo* method);

UnityEngine_AddressableAssets_AddressablesImpl__LoadAssetAsync_object__FuncPtr UnityEngine_AddressableAssets_AddressablesImpl__LoadAssetAsync_object_ = NULL;
UnityEngine_AddressableAssets_AddressablesImpl__LoadAssetAsync_object__FuncPtr fpUnityEngine_AddressableAssets_AddressablesImpl__LoadAssetAsync_object_ = NULL;

UnityEngine_ResourceManagement_AsyncOperations_AsyncOperationHandle_TObject__o
Detour_UnityEngine_AddressableAssets_AddressablesImpl__LoadAssetAsync_object_
(UnityEngine_AddressableAssets_AddressablesImpl_o* __this, Il2CppObject* key, const MethodInfo* method) {
    char *s = System_String_toSds(ConvertObjectToString(key));
    defer { sdsfree(s); }
    printf("LoadAssetAsync(\"%s\")\n", s);
    return fpUnityEngine_AddressableAssets_AddressablesImpl__LoadAssetAsync_object_(__this, key, method);
}

void Hook_UnityEngine_AddressableAssets_AddressablesImpl__LoadAssetAsync_object_(void) {
    printf("Hook_UnityEngine_AddressableAssets_AddressablesImpl__LoadAssetAsync_object_ called!!\n");

    if (MH_CreateHook(
        (void *)(uintptr_t)UnityEngine_AddressableAssets_AddressablesImpl__LoadAssetAsync_object_,
        (LPVOID)(uintptr_t)&Detour_UnityEngine_AddressableAssets_AddressablesImpl__LoadAssetAsync_object_,
        (LPVOID *)&fpUnityEngine_AddressableAssets_AddressablesImpl__LoadAssetAsync_object_
    ) != MH_OK) {
        printf("Failed to create UnityEngine_AddressableAssets_AddressablesImpl__LoadAssetAsync_object_ hook\n");
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)UnityEngine_AddressableAssets_AddressablesImpl__LoadAssetAsync_object_, /* changePermissions = */ FALSE) != MH_OK) {
        printf("Failed to enable UnityEngine_AddressableAssets_AddressablesImpl__LoadAssetAsync_object_ hook\n");
        return;
    }
}

void HookAddressables(uintptr_t GameAssembly) {
    if (ZERO_CONFIG.logAddressables) {
        UnityEngine_AddressableAssets_AddressablesImpl__LoadAssetAsync_object_ = (UnityEngine_AddressableAssets_AddressablesImpl__LoadAssetAsync_object__FuncPtr)(GameAssembly + 13071920ull);
        Hook_UnityEngine_AddressableAssets_AddressablesImpl__LoadAssetAsync_object_();
    }
}