#include "Il2CppHelper.h"

#include <stdio.h>
#include <string.h>

void PrintAssemblyNames(void) {
    const Il2CppDomain *domain = il2cpp_domain_get();

    const Il2CppAssembly **assemblies;
    size_t size;
    
    assemblies = il2cpp_domain_get_assemblies(domain, &size);

    for (size_t i = 0; i < size; ++i) {
        if (assemblies[i]) {
            const char *assemblyName = il2cpp_image_get_name(assemblies[i]->image);

            printf("assemblyName: %s\n", assemblyName);
        }
    }
}

Il2CppImage *HelperGetImage(const char *name) {
    const Il2CppDomain *domain = il2cpp_domain_get();

    const Il2CppAssembly **assemblies;
    size_t size;
    
    assemblies = il2cpp_domain_get_assemblies(domain, &size);

    for (size_t i = 0; i < size; ++i) {
        if (assemblies[i]) {
            const char *assemblyName = il2cpp_image_get_name(assemblies[i]->image);

            if (!strcmp(name, assemblyName)) {
                return assemblies[i]->image;
            }
        }
    }

    return NULL;
}

void HelperGetClassesAndNamesFromAssembly(const Il2CppImage* _image)
{
	if (_image) {
		size_t classCount = il2cpp_image_get_class_count(_image);

		for (size_t i = 0; i < classCount; ++i) {
			const Il2CppClass* _klass = il2cpp_image_get_class(_image, i);

			if (_klass) {
				const char* _name = il2cpp_class_get_name((Il2CppClass *)_klass);
                if (!_name) {
                    _name = "";
                }
				const char* _namespace = il2cpp_class_get_namespace((Il2CppClass *)_klass);

                if (!_namespace) {
                    _namespace = "";
                }

                printf("name: %s, namespace: %s\n", _name, _namespace);
			}
		}
	}
}

const Il2CppClass *HelperGetClass(const Il2CppImage *_image, const char *name, const char *namespaze) {
    if (_image) {
		size_t classCount = il2cpp_image_get_class_count(_image);

		for (size_t i = 0; i < classCount; ++i) {
			const Il2CppClass* _klass = il2cpp_image_get_class(_image, i);

			if (_klass) {
				const char* _name = il2cpp_class_get_name((Il2CppClass *)_klass);
                
				const char* _namespace = il2cpp_class_get_namespace((Il2CppClass *)_klass);

                if (!strcmp(name, _name) && !strcmp(_namespace, namespaze)) {
                    return _klass;
                }
			}
		}
	}

    return NULL;
}


void HelperPrintMethods(Il2CppClass* klass) {
	const MethodInfo* methodIter = NULL;
	void* iter = NULL;

	// Retrieve all methods of the class
	while ((methodIter = il2cpp_class_get_methods(klass, &iter)) != NULL) {
		// Get the name of the method
		const char* methodName = il2cpp_method_get_name(methodIter);

		// Get the return type of the method
		const Il2CppType* methodReturnType = il2cpp_method_get_return_type(methodIter);
		char* returnTypeName = il2cpp_type_get_name(methodReturnType);

		// Print the method name and its return type

        printf("Method Name: %s (%s)\n", methodName, returnTypeName);

		// Perform necessary memory operations
		il2cpp_free(returnTypeName);
	}
}