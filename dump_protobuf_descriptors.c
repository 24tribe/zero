#include "il2cpp_shared.h"
#include "Il2CppHelper.h"
#include "utils.h"

#include <sds.h>

#include <stdio.h>
#include <string.h>
#include <defer.h>

typedef struct Google_Protobuf_Reflection_FileDescriptor_o Google_Protobuf_Reflection_FileDescriptor_o;
typedef struct Google_Protobuf_ByteString_o Google_Protobuf_ByteString_o;

static System_String_o *GetFileDescriptorBase64FromClass(Il2CppClass *klass) {
    const MethodInfo *get_Descriptor = il2cpp_class_get_method_from_name(klass, "get_Descriptor", 0);

    if (!get_Descriptor) {
        printf("Failed to get get_Descriptor!\n");
        return NULL;
    }

    Google_Protobuf_Reflection_FileDescriptor_o *descr;
    descr = (Google_Protobuf_Reflection_FileDescriptor_o *)il2cpp_runtime_invoke(
        get_Descriptor, NULL, NULL, NULL
    );

    if (!descr) {
        printf("failed to get descriptor\n");
        return NULL;
    }

    const MethodInfo *get_SerializedData = il2cpp_class_get_method_from_name(
        ((Il2CppObject*)descr)->klass, "get_SerializedData", 0
    );

    if (!get_SerializedData) {
        printf("failed to get get_SerializedData\n");
        return NULL;
    }

    Google_Protobuf_ByteString_o *data = (Google_Protobuf_ByteString_o *)il2cpp_runtime_invoke(
        get_SerializedData, descr, NULL, NULL
    );

    if (!data) {
        printf("failed to get data\n");
        return NULL;
    }

    const MethodInfo *ToBase64 = il2cpp_class_get_method_from_name(
        ((Il2CppObject *)data)->klass, "ToBase64", 0
    );

    if (!ToBase64) {
        printf("failed to get ToBase64\n");
        return NULL;
    }

    System_String_o *b64;
    b64 = (System_String_o *)il2cpp_runtime_invoke(
        ToBase64, data, NULL, NULL
    );

    return b64;
}

static bool wantedNamespace(const char *ns) {
    return ns && (!strcmp(ns, "Neon.Model.Api.Model") || !strcmp(ns, "Neon.Model.Api.Rpc"));
}

static void DumpReflection(const char *namespace, const char *name, Il2CppClass *klass) {
    sds path = sdsnew(namespace);
    path = sdscat(path, ".");
    path = sdscat(path, name);
    path = sdscat(path, ".pb");
    defer { sdsfree(path); }

    System_String_o *base64 = GetFileDescriptorBase64FromClass(klass);
    if (!base64) {
        printf("Failed to get base64 for %s\n", path);
        return;
    }

    sds b64 = System_String_toSds(base64);
    defer { sdsfree(b64); }

    FILE *f = fopen(path, "wb");
    if (!f) {
        printf("failed to open file for %s\n", path);
        return;
    }
    defer { fclose(f); }

    if (!fwrite(b64, sdslen(b64), 1, f)) {
        printf("fwrite failed for %s\n", path);
        return;
    }
}

static void DumpNeonModel() {
    Il2CppImage *neonModel = HelperGetImage("Neon.Model.dll");

    if (!neonModel) {
        printf("Failed to get neon.model.dll!!\n");
        return;
    }

    size_t classCount = il2cpp_image_get_class_count(neonModel);

    for (size_t i = 0; i < classCount; ++i) {
        const Il2CppClass *klass = il2cpp_image_get_class(neonModel, i);
        if (klass) {
            const char *namespace = il2cpp_class_get_namespace((Il2CppClass *)klass);
            if (wantedNamespace(namespace)) {
                const char *name = il2cpp_class_get_name((Il2CppClass *)klass);
                if (name && strstr(name, "Reflection")) {
                    printf("[DUMP] %s.%s\n", namespace, name);
                    DumpReflection(namespace, name, (Il2CppClass *)klass);
                }
            }
        }
    }
}

static void DumpApiClientExtensions() {
    Il2CppImage *aktskApiClient = HelperGetImage("Aktsk.ApiClient.dll");

    if (!aktskApiClient) {
        printf("Failed to get aktskApiClient\n");
        return;
    }

    size_t classCount = il2cpp_image_get_class_count(aktskApiClient);

    for (size_t i = 0; i < classCount; ++i) {
        const Il2CppClass *klass = il2cpp_image_get_class(aktskApiClient, i);
        if (klass) {
            const char *namespace = il2cpp_class_get_namespace((Il2CppClass *)klass);
            if (namespace && !strcmp(namespace, "ApiClient.Extension")) {
                const char *name = il2cpp_class_get_name((Il2CppClass *)klass);
                if (name && strstr(name, "Reflection")) {
                    printf("[DUMP] %s.%s\n", namespace, name);
                    DumpReflection(namespace, name, (Il2CppClass *)klass);
                }
            }
        }
    }
}

static void DumpEnum() {
    Il2CppImage *neonModel = HelperGetImage("Neon.Model.dll");

    if (!neonModel) {
        printf("Failed to get neon.model.dll!!\n");
        return;
    }

    size_t classCount = il2cpp_image_get_class_count(neonModel);

    printf("classCount: %zu\n", classCount);

    for (size_t i = 0; i < classCount; ++i) {
        const Il2CppClass *klass = il2cpp_image_get_class(neonModel, i);
        if (klass) {
            const char *namespace = il2cpp_class_get_namespace((Il2CppClass *)klass);
            if (namespace && !strcmp(namespace, "Neon.Model.Api.Enum")) {
                const char *name = il2cpp_class_get_name((Il2CppClass *)klass);
                if (name && strstr(name, "Reflection")) {
                    printf("[DUMP] %s.%s\n", namespace, name);
                    DumpReflection(namespace, name, (Il2CppClass *)klass);
                }
            }
        }
    }
}

void DumpProtobufDescriptors(void) {
    static bool done = false;

    if (done) {
        return;
    }

    DumpEnum();
    DumpApiClientExtensions();
    DumpNeonModel();

    done = true;
}