typedef JDGBHFIBACG_o MultilangString_o;

sds getEngString(MultilangString_o *s) {
    System_String_o *en_str = s->fields._BMNNLBFHCNI_k__BackingField;
    return System_String_toSds(en_str);
}

JJNFAMALKLM__KKHPCPHPBMF_FuncPtr fpJJNFAMALKLM__KKHPCPHPBMF = NULL;

bool firstCall = true;

void JJNFAMALKLM_o_print_prefabs(JJNFAMALKLM_o* __this) {
    HAMAAANAAKG_array* data = __this->fields.data;
    for (HAMAAANAAKG_o** hama = data->m_Items; hama != data->m_Items + data->max_length; ++hama) {
        printf("id: %d\n", (*hama)->fields._ACDJAMAIODN_k__BackingField);
        System_String_o *s = (*hama)->fields._JDCDGFDJNDF_k__BackingField;
        if (s) {
            sds prefab = System_String_toSds(s);
            printf("prefab: %s\n", prefab);
            sdsfree(prefab);
        } else {
            printf("prefab: (null)\n");
        }
    }
}

HAMAAANAAKG_o* Detour_JJNFAMALKLM__KKHPCPHPBMF(
    JJNFAMALKLM_o* __this, int32_t MHKJPDDEPPM, const MethodInfo* method
) {
    if (firstCall) {
        firstCall = false;
        JJNFAMALKLM_o_print_prefabs(__this);
    }
    return fpJJNFAMALKLM__KKHPCPHPBMF(__this, MHKJPDDEPPM, method);
}

void Hook_JJNFAMALKLM__KKHPCPHPBMF(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)JJNFAMALKLM__KKHPCPHPBMF,
        (LPVOID)(uintptr_t)&Detour_JJNFAMALKLM__KKHPCPHPBMF,
        (LPVOID *)&fpJJNFAMALKLM__KKHPCPHPBMF
    ) != MH_OK) {
        printf("Failed to create JJNFAMALKLM__KKHPCPHPBMF hook\n");
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)JJNFAMALKLM__KKHPCPHPBMF, /* changePermissions = */ FALSE) != MH_OK) {
        printf("Failed to enable JJNFAMALKLM__KKHPCPHPBMF hook\n");
        return;
    }
}