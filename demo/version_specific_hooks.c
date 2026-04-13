#include "version_specific_hooks.h"

typedef void (*OJLLOCJDBLM___ctor_FuncPtr) (OJLLOCJDBLM_o* __this, MNHJNDFAPMD_o* NFADCMKHEAI, Neon_Model_Api_Model_Enemy_o* PIOECLPHAFK, EJOPFMGFPOA_o* LFLBBLLOAKF, int32_t ODCLDJBPJMJ, const MethodInfo* method);

OJLLOCJDBLM___ctor_FuncPtr OJLLOCJDBLM___ctor = NULL;
OJLLOCJDBLM___ctor_FuncPtr fpOJLLOCJDBLM___ctor = NULL;

void Detour_OJLLOCJDBLM___ctor(
    OJLLOCJDBLM_o* __this, MNHJNDFAPMD_o* NFADCMKHEAI,
    Neon_Model_Api_Model_Enemy_o* PIOECLPHAFK, EJOPFMGFPOA_o* LFLBBLLOAKF,
    int32_t ODCLDJBPJMJ, const MethodInfo* method
) {
    printf(
        "NFADCMKHEAI=%p, PIOECLPHAFK=%p, LFLBBLLOAKF=%p, ODCLDJBPJMJ=%lld\n",
        (void *)NFADCMKHEAI, (void *)PIOECLPHAFK, (void *)LFLBBLLOAKF, (long long)ODCLDJBPJMJ
    );
    fpOJLLOCJDBLM___ctor(__this, NFADCMKHEAI, PIOECLPHAFK, LFLBBLLOAKF, ODCLDJBPJMJ, method);
}

void Hook_OJLLOCJDBLM___ctor(void) {
    printf("Hook_OJLLOCJDBLM___ctor called\n");
    if (MH_CreateHook(
        (void *)(uintptr_t)OJLLOCJDBLM___ctor,
        (LPVOID)(uintptr_t)&Detour_OJLLOCJDBLM___ctor,
        (LPVOID *)&fpOJLLOCJDBLM___ctor
    ) != MH_OK) {
        printf("Failed to create OJLLOCJDBLM___ctor hook\n");
        return;
    }

    if (MH_EnableHook((void *)(uintptr_t)OJLLOCJDBLM___ctor, /* changePermissions = */ FALSE) != MH_OK) {
        printf("Failed to enable OJLLOCJDBLM___ctor hook\n");
        return;
    }
}

void ApplyVersionSpecificHooks(void) {
    OJLLOCJDBLM___ctor = (OJLLOCJDBLM___ctor_FuncPtr)((uintptr_t)GameAssembly + 60351888ull);
    Hook_OJLLOCJDBLM___ctor();
}