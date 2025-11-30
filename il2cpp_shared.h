#ifndef IL2CPP_SHARED_H_7_SEP_2025_10_40
#define IL2CPP_SHARED_H_7_SEP_2025_10_40

#include <stdint.h>

typedef struct Il2CppType Il2CppType;
typedef struct MethodInfo MethodInfo;

typedef struct Il2CppDomain Il2CppDomain;

typedef struct System_String_c System_String_c;

typedef struct System_String_Fields {
	int32_t _stringLength;
	uint16_t _firstChar;
} System_String_Fields;

typedef struct System_String_o {
	System_String_c *klass;
	void *monitor;
	System_String_Fields fields;
} System_String_o;

typedef struct Il2CppClass Il2CppClass;

typedef struct Il2CppObject
{
    Il2CppClass *klass;
    void *monitor;
} Il2CppObject;

typedef Il2CppDomain *(*IL2CPPDOMAINGET)(void);
extern IL2CPPDOMAINGET il2cpp_domain_get;

typedef void (*IL2CPPTHREADATTACH)(Il2CppDomain *);
extern IL2CPPTHREADATTACH il2cpp_thread_attach;

typedef Il2CppObject *(*IL2CPPOBJECTNEW)(const Il2CppClass *klass);
extern IL2CPPOBJECTNEW il2cpp_object_new;

typedef System_String_o *(*IL2CPPSTRINGNEW)(char *s);
extern IL2CPPSTRINGNEW il2cpp_string_new;

typedef void (*IL2CPPRUNTIMECLASSINIT)(Il2CppClass *klass);
extern IL2CPPRUNTIMECLASSINIT il2cpp_runtime_class_init;

struct Il2CppAssembly;

#define PUBLIC_KEY_BYTE_LENGTH 8

typedef struct Il2CppAssemblyName
{
    const char* name;
    const char* culture;
    const uint8_t* public_key;
    uint32_t hash_alg;
    int32_t hash_len;
    uint32_t flags;
    int32_t major;
    int32_t minor;
    int32_t build;
    int32_t revision;
    uint8_t public_key_token[PUBLIC_KEY_BYTE_LENGTH];
} Il2CppAssemblyName;

typedef const struct ___Il2CppMetadataImageHandle* Il2CppMetadataImageHandle;
typedef struct Il2CppNameToTypeHandleHashTable Il2CppNameToTypeHandleHashTable;
typedef struct Il2CppCodeGenModule Il2CppCodeGenModule;

typedef struct Il2CppImage
{
    const char* name;
    const char *nameNoExt;
    struct Il2CppAssembly* assembly;

    uint32_t typeCount;
    uint32_t exportedTypeCount;
    uint32_t customAttributeCount;

    Il2CppMetadataImageHandle metadataHandle;

#ifdef __cplusplus
    mutable
#endif
    Il2CppNameToTypeHandleHashTable * nameToClassHashTable;

    const Il2CppCodeGenModule* codeGenModule;

    uint32_t token;
    uint8_t dynamic;
} Il2CppImage;

typedef struct Il2CppAssembly
{
    struct Il2CppImage* image;
    uint32_t token;
    int32_t referencedAssemblyStart;
    int32_t referencedAssemblyCount;
    struct Il2CppAssemblyName aname;
    struct Il2CppAssembly* originAssembly;
} Il2CppAssembly;

typedef struct Il2CppException Il2CppException;

typedef const Il2CppAssembly**(*IL2CPP_DOMAIN_GET_ASSEMBLIES)(const Il2CppDomain * domain, size_t * size);
extern IL2CPP_DOMAIN_GET_ASSEMBLIES il2cpp_domain_get_assemblies;

typedef const char *(*IL2CPP_IMAGE_GET_NAME)(const Il2CppImage * image);
extern IL2CPP_IMAGE_GET_NAME il2cpp_image_get_name;

typedef size_t (*IL2CPP_IMAGE_GET_CLASS_COUNT)(const Il2CppImage * image);
extern IL2CPP_IMAGE_GET_CLASS_COUNT il2cpp_image_get_class_count;

typedef const Il2CppClass*(*IL2CPP_IMAGE_GET_CLASS)(const Il2CppImage * image, size_t index);
extern IL2CPP_IMAGE_GET_CLASS il2cpp_image_get_class;

typedef const char*(*IL2CPP_CLASS_GET_NAME)(Il2CppClass * klass);
extern IL2CPP_CLASS_GET_NAME il2cpp_class_get_name;

typedef const char*(*IL2CPP_CLASS_GET_NAMESPACE)(Il2CppClass * klass);
extern IL2CPP_CLASS_GET_NAMESPACE il2cpp_class_get_namespace;

typedef const Il2CppType* (*IL2CPP_METHOD_GET_RETURN_TYPE)(const MethodInfo * method);

typedef const char* (*IL2CPP_METHOD_GET_NAME)(const MethodInfo * method);

typedef const MethodInfo* (*IL2CPP_CLASS_GET_METHODS)(Il2CppClass * klass, void* *iter);

typedef char *(*IL2CPP_TYPE_GET_NAME)(const Il2CppType * type);

typedef void (*IL2CPP_FREE)(void *);

typedef const MethodInfo* (*IL2CPP_CLASS_GET_METHOD_FROM_NAME)(Il2CppClass * klass, const char* name, int argsCount);

typedef Il2CppObject* (*IL2CPP_RUNTIME_INVOKE)(const MethodInfo * method, void *obj, void **params, Il2CppException **exc);
typedef Il2CppObject* (*IL2CPP_TYPE_GET_OBJECT)(const Il2CppType * type);
typedef Il2CppClass* (*IL2CPP_TYPE_GET_CLASS_OR_ELEMENT_CLASS)(const Il2CppType * type);

typedef Il2CppClass* (*IL2CPP_OBJECT_GET_CLASS)(const Il2CppObject *obj);

typedef const Il2CppType* (*IL2CPP_CLASS_GET_TYPE)(Il2CppClass * klass);
typedef Il2CppClass* (*IL2CPP_CLASS_FROM_NAME)(const Il2CppImage * image, const char* namespaze, const char *name);

extern IL2CPP_METHOD_GET_RETURN_TYPE il2cpp_method_get_return_type;
extern IL2CPP_METHOD_GET_NAME il2cpp_method_get_name;
extern IL2CPP_CLASS_GET_METHODS il2cpp_class_get_methods;
extern IL2CPP_TYPE_GET_NAME il2cpp_type_get_name;
extern IL2CPP_FREE il2cpp_free;
extern IL2CPP_CLASS_GET_METHOD_FROM_NAME il2cpp_class_get_method_from_name;
extern IL2CPP_RUNTIME_INVOKE il2cpp_runtime_invoke;
extern IL2CPP_TYPE_GET_OBJECT il2cpp_type_get_object;
extern IL2CPP_TYPE_GET_CLASS_OR_ELEMENT_CLASS il2cpp_type_get_class_or_element_class;
extern IL2CPP_OBJECT_GET_CLASS il2cpp_object_get_class;
extern IL2CPP_CLASS_GET_TYPE il2cpp_class_get_type;
extern IL2CPP_CLASS_FROM_NAME il2cpp_class_from_name;

typedef void(*Il2CppMethodPointer)();

typedef struct MethodInfo MethodInfo;

typedef struct VirtualInvokeData
{
    Il2CppMethodPointer methodPtr;
    const MethodInfo* method;
} VirtualInvokeData;

typedef struct Il2CppType
{
    void* data;
    unsigned int bits;
} Il2CppType;

typedef union Il2CppRGCTXData
{
    void* rgctxDataDummy;
    const MethodInfo* method;
    const Il2CppType* type;
    Il2CppClass* klass;
} Il2CppRGCTXData;

typedef struct Il2CppRuntimeInterfaceOffsetPair
{
    Il2CppClass* interfaceType;
    int32_t offset;
} Il2CppRuntimeInterfaceOffsetPair;

typedef struct Il2CppClass_1
{
    void* image;
    void* gc_desc;
    const char* name;
    const char* namespaze;
    Il2CppType byval_arg;
    Il2CppType this_arg;
    Il2CppClass* element_class;
    Il2CppClass* castClass;
    Il2CppClass* declaringType;
    Il2CppClass* parent;
    void *generic_class;
    void* typeMetadataHandle;
    void* interopData;
    Il2CppClass* klass;
    void* fields;
    void* events;
    void* properties;
    void* methods;
    Il2CppClass** nestedTypes;
    Il2CppClass** implementedInterfaces;
    Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
} Il2CppClass_1;

typedef struct Il2CppClass_2
{
    Il2CppClass** typeHierarchy;
    void *unity_user_data;
    uint32_t initializationExceptionGCHandle;
    uint32_t cctor_started;
    uint32_t cctor_finished;
    size_t cctor_thread;
    void* genericContainerHandle;
    uint32_t instance_size;
    uint32_t actualSize;
    uint32_t element_size;
    int32_t native_size;
    uint32_t static_fields_size;
    uint32_t thread_static_fields_size;
    int32_t thread_static_fields_offset;
    uint32_t flags;
    uint32_t token;
    uint16_t method_count;
    uint16_t property_count;
    uint16_t field_count;
    uint16_t event_count;
    uint16_t nested_type_count;
    uint16_t vtable_count;
    uint16_t interfaces_count;
    uint16_t interface_offsets_count;
    uint8_t typeHierarchyDepth;
    uint8_t genericRecursionDepth;
    uint8_t rank;
    uint8_t minimumAlignment;
    uint8_t naturalAligment;
    uint8_t packingSize;
    uint8_t bitflags1;
    uint8_t bitflags2;
} Il2CppClass_2;

typedef struct Il2CppClass
{
    Il2CppClass_1 _1;
    void* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    VirtualInvokeData vtable[255];
} Il2CppClass;

typedef uintptr_t il2cpp_array_size_t;
typedef int32_t il2cpp_array_lower_bound_t;
typedef struct Il2CppArrayBounds
{
    il2cpp_array_size_t length;
    il2cpp_array_lower_bound_t lower_bound;
} Il2CppArrayBounds;

typedef void (*InvokerMethod)(Il2CppMethodPointer, const MethodInfo*, void*, void**, void*);
struct MethodInfo
{
    Il2CppMethodPointer methodPointer;
    Il2CppMethodPointer virtualMethodPointer;
    InvokerMethod invoker_method;
    const char* name;
    Il2CppClass *klass;
    const Il2CppType *return_type;
    const Il2CppType** parameters;
    union
    {
        const Il2CppRGCTXData* rgctx_data;
        const void* methodMetadataHandle;
    };
    union
    {
        const void* genericMethod;
        const void* genericContainerHandle;
    };
    uint32_t token;
    uint16_t flags;
    uint16_t iflags;
    uint16_t slot;
    uint8_t parameters_count;
    uint8_t bitflags;
};

// typedef struct _Module__Fields _Module__Fields;

typedef struct _Module__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	VirtualInvokeData vtable[32];
} _Module__c;

typedef struct _Module__o {
	_Module__c *klass;
	void *monitor;
	// _Module__Fields fields;
} _Module__o;

#endif