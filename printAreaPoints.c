LICGNCFAOFL__KKHPCPHPBMF_FuncPtr fpLICGNCFAOFL__KKHPCPHPBMF = NULL;
bool first = true;

void printAreaPoint(GCHGCKNHMHC_o *area_point) {
    int32_t id = area_point->fields._ACDJAMAIODN_k__BackingField;
    int32_t area_id = area_point->fields._CFJHCJCCJIF_k__BackingField;
    int32_t index = area_point->fields._DGMECENOBAD_k__BackingField;

    printf("%lld,%lld,%lld\n", (long long int)id, (long long int)area_id, (long long int)index);
}

GCHGCKNHMHC_o* Detour_LICGNCFAOFL__KKHPCPHPBMF (
    LICGNCFAOFL_o* __this, int32_t MHKJPDDEPPM, const MethodInfo* method
) {
    if (first) {
        first = false;

        printf("id,area_id,index\n");

        GCHGCKNHMHC_array* points = __this->fields.AGKIMIDFFAI;

        for (GCHGCKNHMHC_o **it = points->m_Items; it != points->m_Items + points->max_length; ++it) {
            printAreaPoint(*it);
        }
    }
    return fpLICGNCFAOFL__KKHPCPHPBMF(__this, MHKJPDDEPPM, method);
}

void Hook_LICGNCFAOFL__KKHPCPHPBMF(void) {
    if (MH_CreateHook(
        (void *)(uintptr_t)LICGNCFAOFL__KKHPCPHPBMF,
        (LPVOID)(uintptr_t)&Detour_LICGNCFAOFL__KKHPCPHPBMF,
        (LPVOID *)&fpLICGNCFAOFL__KKHPCPHPBMF
    ) != MH_OK) {
        printf("Failed to create LICGNCFAOFL__KKHPCPHPBMF hook\n");
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)LICGNCFAOFL__KKHPCPHPBMF, /* changePermissions = */ FALSE) != MH_OK) {
        printf("Failed to enable LICGNCFAOFL__KKHPCPHPBMF hook\n");
        return;
    }
}