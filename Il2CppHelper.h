#ifndef IL2CPP_HELPER_H_2025_09_13_04_23
#define IL2CPP_HELPER_H_2025_09_13_04_23

#include "il2cpp_shared.h"

void PrintAssemblyNames(void);
Il2CppImage *HelperGetImage(const char *name);
void HelperGetClassesAndNamesFromAssembly(const Il2CppImage* _image);
const Il2CppClass *HelperGetClass(const Il2CppImage *_image, const char *name, const char *namespaze);
void HelperPrintMethods(Il2CppClass* klass);

#endif