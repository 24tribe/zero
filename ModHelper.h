#ifndef MOD_HELPER_H_2026_02_21_03_16
#define MOD_HELPER_H_2026_02_21_03_16

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

struct ModManager;

char *ModHelper_GetTextureChanges(struct ModManager *mgr, const char *bundlePath);
struct ModManager *ModHelper_ParseMods(const char *modsPath);
wchar_t *ModHelper_GetPathForNewBundle(const char *bundlePath);


#ifdef __cplusplus
}
#endif

#endif