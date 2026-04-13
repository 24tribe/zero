#include "version_specific_hooks.h"

#include "../il2cpp_shared.h"
#include "funcPtrs.h"
#include "../utils.h"
#include "../Logger.h"
#include "../defer.h"
#include "../HairColorHelper.h"

#include <MinHook.h>

#include <windows.h>

#include <stdio.h>

typedef struct Neon_Battle_Character_LoadRequest_o Neon_Battle_Character_LoadRequest_o;
typedef struct OJLLOCJDBLM_o OJLLOCJDBLM_o;
typedef struct MNHJNDFAPMD_o MNHJNDFAPMD_o;
typedef struct NMLAKINLNFO_o NMLAKINLNFO_o;

typedef void (*Neon_Battle_Character_LoadRequest___ctor_FuncPtr)(
    Neon_Battle_Character_LoadRequest_o* __this, OJLLOCJDBLM_o* enemy,
    NMLAKINLNFO_o* asset, int32_t aiId, MNHJNDFAPMD_o* masterDataManager,
    const MethodInfo* method
);

Neon_Battle_Character_LoadRequest___ctor_FuncPtr Neon_Battle_Character_LoadRequest___ctor = NULL;
Neon_Battle_Character_LoadRequest___ctor_FuncPtr fpNeon_Battle_Character_LoadRequest___ctor = NULL;

void Detour_Neon_Battle_Character_LoadRequest___ctor(
    Neon_Battle_Character_LoadRequest_o* __this, OJLLOCJDBLM_o* enemy,
    NMLAKINLNFO_o* asset, int32_t aiId, MNHJNDFAPMD_o* masterDataManager,
    const MethodInfo* method
) {
    printf("aiId: %d\n", aiId);
    fpNeon_Battle_Character_LoadRequest___ctor(
        __this, enemy, asset, aiId, masterDataManager, method
    );
}

void Hook_Neon_Battle_Character_LoadRequest___ctor(void) {
    printf("Hook_Neon_Battle_Character_LoadRequest___ctor called\n");
    if (MH_CreateHook(
        (void *)(uintptr_t)Neon_Battle_Character_LoadRequest___ctor,
        (LPVOID)(uintptr_t)&Detour_Neon_Battle_Character_LoadRequest___ctor,
        (LPVOID *)&fpNeon_Battle_Character_LoadRequest___ctor
    ) != MH_OK) {
        printf("Failed to create Neon_Battle_Character_LoadRequest___ctor hook\n");
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)Neon_Battle_Character_LoadRequest___ctor, /* changePermissions = */ FALSE) != MH_OK) {
        printf("Failed to enable Neon_Battle_Character_LoadRequest___ctor hook\n");
        return;
    }
}

Neon_Character_CharacterView__PNMGFMEJMFA_FuncPtr fpNeon_Character_CharacterView__PNMGFMEJMFA = NULL;

void materialSetColor(UnityEngine_Material_o *mat, const char *name, UnityEngine_Color_o color) {
    Il2CppClass *matClass = ((Il2CppObject*)mat)->klass;
    const MethodInfo *SetColor = il2cpp_class_get_method_from_name(
        matClass, "SetColor", 2
    );

    if (!SetColor) {
        printf("Failed to get matClass SetColor!\n");
        return;
    }

    il2cpp_runtime_invoke(
        SetColor, mat, (void *[]){il2cpp_string_new((char*)name), (void*)&color}, NULL
    );
}

void materialSetTexture(UnityEngine_Material_o *mat, const char *name, UnityEngine_Texture_o *tex) {
    Il2CppClass *matClass = ((Il2CppObject*)mat)->klass;
    const MethodInfo *SetTexture = il2cpp_class_get_method_from_name(
        matClass, "SetTexture", 2
    );

    if (!SetTexture) {
        printf("Failed to get matClass SetTexture!\n");
        return;
    }

    il2cpp_runtime_invoke(
        SetTexture, mat, (void *[]){il2cpp_string_new((char*)name), (void*)tex}, NULL
    );
}

typedef struct UnityEngine_Shader_o UnityEngine_Shader_o;
UnityEngine_Shader_o *materialGetShader(UnityEngine_Material_o* mat) {
    Il2CppClass *matClass = ((Il2CppObject *)mat)->klass;
    const MethodInfo *get_shader = il2cpp_class_get_method_from_name(
            matClass, "get_shader", 0
    );

    if (!get_shader) {
        printf("Failed to get matClass get_shader!\n");
        return NULL;
    }

    return (UnityEngine_Shader_o *)il2cpp_runtime_invoke(get_shader, mat, NULL, NULL);
}

UnityEngine_Texture_o *materialGetTexture(UnityEngine_Material_o* mat, const char *name) {
    Il2CppClass *matClass = ((Il2CppObject *)mat)->klass;
    const MethodInfo *GetTexture = il2cpp_class_get_method_from_name(
            matClass, "GetTexture", 1
    );

    if (!GetTexture) {
        printf("Failed to get matClass GetTexture!\n");
        return NULL;
    }

    return (UnityEngine_Texture_o *)il2cpp_runtime_invoke(
        GetTexture, mat, (void *[]){il2cpp_string_new((char*)name)}, NULL
    );
}

UnityEngine_Texture_o *GetMaterialAlbedoTexture(UnityEngine_Material_o *material) {
    return materialGetTexture(material, "_AlbedoTexture");
}

void SetMaterialAlbedoTexture(UnityEngine_Material_o *material, UnityEngine_Texture_o *tex) {
    materialSetTexture(material, "_AlbedoTexture", tex);
}

void SetMaterialAlbedoColor(UnityEngine_Material_o *material, float color[3]) {
    materialSetColor(material, "_AlbedoColor", (UnityEngine_Color_o){
        .fields = {color[0], color[1], color[2], 1.0f}
    });
}

struct HairColorHelper *gHairColorHelper = NULL;

void HookTN_SetHairColorHelper(struct HairColorHelper *helper) {
    gHairColorHelper = helper;
}

void Detour_Neon_Character_CharacterView__PNMGFMEJMFA(
    UnityEngine_Material_o* material, UnityEngine_Texture2D_o* ditherTexture,
    UnityEngine_Texture2D_o* hologramTexture, const MethodInfo* method
) {
    if (gHairColorHelper && material) {
        char *mat = System_String_toSds(ConvertObjectToString((Il2CppObject *)material));
        defer {
            sdsfree(mat);
        }
        int charId = HairColorHelper_GetCharIdFromMaterialName(mat);
        if (charId != -1) {
            void *texture = GetMaterialAlbedoTexture(material);
            HairColorHelper_SetMaterial(gHairColorHelper, charId, material, texture);
            if (HairColorHelper_IsHairColorEnabled(gHairColorHelper, charId)) {
                float color[3] = {0, 0, 0};
                HairColorHelper_GetHairColor(gHairColorHelper, charId, color);
                SetMaterialAlbedoColor(material, color);
                SetMaterialAlbedoTexture(material, NULL);
            }
        }
    }

    fpNeon_Character_CharacterView__PNMGFMEJMFA(material, ditherTexture, hologramTexture, method);
}

void Hook_Neon_Character_CharacterView__PNMGFMEJMFA(void) {
    printf("Hook_Neon_Character_CharacterView__PNMGFMEJMFA called\n");
    if (MH_CreateHook(
        (void *)(uintptr_t)Neon_Character_CharacterView__PNMGFMEJMFA,
        (LPVOID)(uintptr_t)&Detour_Neon_Character_CharacterView__PNMGFMEJMFA,
        (LPVOID *)&fpNeon_Character_CharacterView__PNMGFMEJMFA
    ) != MH_OK) {
        printf("Failed to create Neon_Character_CharacterView__PNMGFMEJMFA hook\n");
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)Neon_Character_CharacterView__PNMGFMEJMFA, /* changePermissions = */ FALSE) != MH_OK) {
        printf("Failed to enable Neon_Character_CharacterView__PNMGFMEJMFA hook\n");
        return;
    }
}

void ApplyVersionSpecificHooks(uintptr_t GameAssembly) {
    Neon_Battle_Character_LoadRequest___ctor = (Neon_Battle_Character_LoadRequest___ctor_FuncPtr)(GameAssembly + 57544560ull);
    Hook_Neon_Battle_Character_LoadRequest___ctor();
    Hook_Neon_Character_CharacterView__PNMGFMEJMFA();
}