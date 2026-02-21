#ifndef IL2CPP_SHARED_H_7_SEP_2025_10_40
#define IL2CPP_SHARED_H_7_SEP_2025_10_40

#include <stdint.h>
#include <stdbool.h>

typedef struct Il2CppType Il2CppType;
typedef struct MethodInfo MethodInfo;
typedef struct Il2CppArray Il2CppArray;

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

typedef uint32_t (*IL2CPP_ARRAY_LENGTH)(Il2CppArray * array);

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
extern IL2CPP_ARRAY_LENGTH il2cpp_array_length;

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

typedef struct UnityEngine_Transform_o UnityEngine_Transform_o;
typedef struct System_Type_o System_Type_o;
typedef struct UnityEngine_Object_o UnityEngine_Object_o;
typedef struct UnityEngine_Camera_o UnityEngine_Camera_o;
typedef struct Neon_Model_Api_ApiService_o Neon_Model_Api_ApiService_o;
typedef struct CDGPJELFAMK_o CDGPJELFAMK_o;
typedef struct JDGBHFIBACG_o JDGBHFIBACG_o;
typedef struct EMDHIMNBAPC_o EMDHIMNBAPC_o;
typedef struct System_Collections_Generic_IReadOnlyList_PDIFPHMPPAG__o System_Collections_Generic_IReadOnlyList_PDIFPHMPPAG__o;
typedef struct BJAFDMJIDMJ_o BJAFDMJIDMJ_o;
typedef struct LPCOHPIGHIN_o LPCOHPIGHIN_o;
typedef struct CDGPJELFAMK_c CDGPJELFAMK_c;

typedef struct System_Threading_CancellationToken_Fields {
	struct System_Threading_CancellationTokenSource_o* _source;
} System_Threading_CancellationToken_Fields;

typedef struct System_Threading_CancellationToken_o {
	System_Threading_CancellationToken_Fields fields;
} System_Threading_CancellationToken_o;

typedef struct System_Nullable_long__Fields {
	bool hasValue;
	int64_t value;
} System_Nullable_long__Fields;

typedef struct System_Nullable_long__o {
	System_Nullable_long__Fields fields;
} System_Nullable_long__o;

typedef struct System_Nullable_int__Fields {
	bool hasValue;
	int32_t value;
} System_Nullable_int__Fields;

typedef struct System_Nullable_int__o {
	System_Nullable_int__Fields fields;
} System_Nullable_int__o;

typedef struct System_Nullable_double__Fields {
	bool hasValue;
	double value;
} System_Nullable_double__Fields;

typedef struct System_Nullable_double__o {
	System_Nullable_double__Fields fields;
} System_Nullable_double__o;

typedef struct Best_HTTP_HTTPRequest_Fields {
	int32_t _MethodType_k__BackingField;
	struct System_Uri_o* _Uri_k__BackingField;
	struct Best_HTTP_HTTPResponse_o* _Response_k__BackingField;
	struct Best_HTTP_Request_Settings_DownloadSettings_o* DownloadSettings;
	struct Best_HTTP_Request_Settings_UploadSettings_o* UploadSettings;
	struct Best_HTTP_Request_Settings_TimeoutSettings_o* TimeoutSettings;
	struct Best_HTTP_Request_Settings_RetrySettings_o* RetrySettings;
	struct Best_HTTP_Request_Settings_ProxySettings_o* ProxySettings;
	struct Best_HTTP_Request_Settings_RedirectSettings_o* _RedirectSettings_k__BackingField;
	struct Best_HTTP_OnRequestFinishedDelegate_o* _Callback_k__BackingField;
	struct System_Threading_CancellationTokenSource_o* _CancellationTokenSource_k__BackingField;
	struct System_Action_HTTPRequest__o* OnCancellationRequested;
	struct System_Exception_o* _Exception_k__BackingField;
	Il2CppObject* _Tag_k__BackingField;
	int32_t _state;
	struct Best_HTTP_Request_Timings_TimingCollector_o* _Timing_k__BackingField;
	struct Best_HTTP_Request_Authenticators_IAuthenticator_o* Authenticator;
	struct Best_HTTP_Shared_Logger_LoggingContext_o* _Context_k__BackingField;
	struct System_Collections_Generic_Dictionary_string__List_string___o* _Headers_k__BackingField;
} Best_HTTP_HTTPRequest_Fields;

typedef struct Best_HTTP_HTTPRequest_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_MoveNext;
	VirtualInvokeData _5_get_Current;
	VirtualInvokeData _6_Reset;
} Best_HTTP_HTTPRequest_VTable;

typedef struct Best_HTTP_HTTPRequest_c {
	Il2CppClass_1 _1;
	struct Best_HTTP_HTTPRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Best_HTTP_HTTPRequest_VTable vtable;
} Best_HTTP_HTTPRequest_c;

typedef struct Best_HTTP_HTTPRequest_o {
	Best_HTTP_HTTPRequest_c *klass;
	void *monitor;
	Best_HTTP_HTTPRequest_Fields fields;
} Best_HTTP_HTTPRequest_o;

typedef struct Best_HTTP_HTTPRequest_StaticFields {
	struct System_String_array* MethodNames;
} Best_HTTP_HTTPRequest_StaticFields;

typedef struct System_Uri_Fields {
	struct System_String_o* m_String;
	struct System_String_o* m_originalUnicodeString;
	struct System_UriParser_o* m_Syntax;
	struct System_String_o* m_DnsSafeHost;
	uint64_t m_Flags;
	struct System_Uri_UriInfo_o* m_Info;
	bool m_iriParsing;
} System_Uri_Fields;

typedef struct System_Uri_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_System_Runtime_Serialization_ISerializable_GetObjectData;
} System_Uri_VTable;

typedef struct System_Uri_c {
	Il2CppClass_1 _1;
	struct System_Uri_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Uri_VTable vtable;
} System_Uri_c;

typedef struct System_Uri_o {
	System_Uri_c *klass;
	void *monitor;
	System_Uri_Fields fields;
} System_Uri_o;

typedef struct System_Uri_StaticFields {
	struct System_String_o* UriSchemeFile;
	struct System_String_o* UriSchemeFtp;
	struct System_String_o* UriSchemeGopher;
	struct System_String_o* UriSchemeHttp;
	struct System_String_o* UriSchemeHttps;
	struct System_String_o* UriSchemeWs;
	struct System_String_o* UriSchemeWss;
	struct System_String_o* UriSchemeMailto;
	struct System_String_o* UriSchemeNews;
	struct System_String_o* UriSchemeNntp;
	struct System_String_o* UriSchemeNetTcp;
	struct System_String_o* UriSchemeNetPipe;
	struct System_String_o* SchemeDelimiter;
	bool s_ConfigInitialized;
	bool s_ConfigInitializing;
	int32_t s_IdnScope;
	bool s_IriParsing;
	bool useDotNetRelativeOrAbsolute;
	bool IsWindowsFileSystem;
	Il2CppObject* s_initLock;
	struct System_Char_array* HexLowerChars;
	struct System_Char_array* _WSchars;
} System_Uri_StaticFields;



typedef struct System_String_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_CompareTo;
	VirtualInvokeData _5_System_Collections_IEnumerable_GetEnumerator;
	VirtualInvokeData _6_System_Collections_Generic_IEnumerable_System_Char__GetEnumerator;
	VirtualInvokeData _7_CompareTo;
	VirtualInvokeData _8_Equals;
	VirtualInvokeData _9_GetTypeCode;
	VirtualInvokeData _10_System_IConvertible_ToBoolean;
	VirtualInvokeData _11_System_IConvertible_ToChar;
	VirtualInvokeData _12_System_IConvertible_ToSByte;
	VirtualInvokeData _13_System_IConvertible_ToByte;
	VirtualInvokeData _14_System_IConvertible_ToInt16;
	VirtualInvokeData _15_System_IConvertible_ToUInt16;
	VirtualInvokeData _16_System_IConvertible_ToInt32;
	VirtualInvokeData _17_System_IConvertible_ToUInt32;
	VirtualInvokeData _18_System_IConvertible_ToInt64;
	VirtualInvokeData _19_System_IConvertible_ToUInt64;
	VirtualInvokeData _20_System_IConvertible_ToSingle;
	VirtualInvokeData _21_System_IConvertible_ToDouble;
	VirtualInvokeData _22_System_IConvertible_ToDecimal;
	VirtualInvokeData _23_System_IConvertible_ToDateTime;
	VirtualInvokeData _24_ToString;
	VirtualInvokeData _25_System_IConvertible_ToType;
	VirtualInvokeData _26_Clone;
} System_String_VTable;

typedef struct System_String_c {
	Il2CppClass_1 _1;
	struct System_String_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_String_VTable vtable;
} System_String_c;

typedef struct System_String_StaticFields {
	struct System_String_o* Empty;
} System_String_StaticFields;

typedef struct Best_HTTP_Request_Settings_ProxySettings_Fields {
	struct Best_HTTP_Proxies_Proxy_o* _Proxy_k__BackingField;
} Best_HTTP_Request_Settings_ProxySettings_Fields;

typedef struct Best_HTTP_Request_Settings_ProxySettings_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Best_HTTP_Request_Settings_ProxySettings_VTable;

typedef struct Best_HTTP_Request_Settings_ProxySettings_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Best_HTTP_Request_Settings_ProxySettings_VTable vtable;
} Best_HTTP_Request_Settings_ProxySettings_c;

typedef struct Best_HTTP_Request_Settings_ProxySettings_o {
	Best_HTTP_Request_Settings_ProxySettings_c *klass;
	void *monitor;
	Best_HTTP_Request_Settings_ProxySettings_Fields fields;
} Best_HTTP_Request_Settings_ProxySettings_o;

typedef struct Best_HTTP_Proxies_Proxy_Fields {
	struct System_Uri_o* _Address_k__BackingField;
	struct Best_HTTP_Request_Authentication_Credentials_o* _Credentials_k__BackingField;
	struct System_Collections_Generic_List_string__o* _Exceptions_k__BackingField;
} Best_HTTP_Proxies_Proxy_Fields;

typedef struct Best_HTTP_Proxies_Proxy_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Best_HTTP_Proxies_Proxy_VTable;

typedef struct Best_HTTP_Proxies_Proxy_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Best_HTTP_Proxies_Proxy_VTable vtable;
} Best_HTTP_Proxies_Proxy_c;

typedef struct Best_HTTP_Proxies_Proxy_o {
	Best_HTTP_Proxies_Proxy_c *klass;
	void *monitor;
	Best_HTTP_Proxies_Proxy_Fields fields;
} Best_HTTP_Proxies_Proxy_o;

typedef struct Best_HTTP_Proxies_HTTPProxy_Fields {
	bool _IsTransparent_k__BackingField;
	bool _SendWholeUri_k__BackingField;
	bool _NonTransparentForHTTPS_k__BackingField;
} Best_HTTP_Proxies_HTTPProxy_Fields;

typedef struct Best_HTTP_Proxies_HTTPProxy_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_BeginConnect;
	VirtualInvokeData _5_GetRequestPath;
	VirtualInvokeData _6_SetupRequest;
} Best_HTTP_Proxies_HTTPProxy_VTable;

typedef struct Best_HTTP_Proxies_HTTPProxy_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Best_HTTP_Proxies_HTTPProxy_VTable vtable;
} Best_HTTP_Proxies_HTTPProxy_c;

typedef struct Best_HTTP_Proxies_HTTPProxy_o {
	Best_HTTP_Proxies_HTTPProxy_c *klass;
	void *monitor;
	Best_HTTP_Proxies_HTTPProxy_Fields fields;
} Best_HTTP_Proxies_HTTPProxy_o;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__Fields {
	Il2CppObject* result;
	Il2CppObject* error;
	int16_t version;
	bool hasUnhandledError;
	int32_t completedCount;
	struct System_Action_object__o* continuation;
	Il2CppObject* continuationState;
} Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__Fields;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__o {
	Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__Fields fields;
} Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__o;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_TResult__RGCTXs {
	MethodInfo* _0_Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_TResult__ReportUnhandledError;
	Il2CppClass* _1_Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_TResult_;
	Il2CppClass* _2_Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_TResult_;
	Il2CppClass* _3_TResult;
	MethodInfo* _4_Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_TResult__ValidateToken;
} Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_TResult__RGCTXs;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_TResult__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_TResult__VTable;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_TResult__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_TResult__RGCTXs* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_TResult__VTable vtable;
} Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_TResult__c;

typedef struct System_DateTime_Fields {
	uint64_t _dateData;
} System_DateTime_Fields;

typedef struct System_DateTime_o {
	System_DateTime_Fields fields;
} System_DateTime_o;

typedef struct UnityEngine_Vector3_Fields {
	float x;
	float y;
	float z;
} UnityEngine_Vector3_Fields;

typedef struct UnityEngine_Vector3_o {
	UnityEngine_Vector3_Fields fields;
} UnityEngine_Vector3_o;

typedef struct UnityEngine_Quaternion_Fields {
	float x;
	float y;
	float z;
	float w;
} UnityEngine_Quaternion_Fields;

typedef struct UnityEngine_Quaternion_o {
	UnityEngine_Quaternion_Fields fields;
} UnityEngine_Quaternion_o;

typedef struct UnityEngine_Object_array {
	Il2CppObject obj;
	Il2CppArrayBounds *bounds;
	il2cpp_array_size_t max_length;
	UnityEngine_Object_o* m_Items[65535];
} UnityEngine_Object_array;

typedef struct System_Diagnostics_StackTrace_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_get_FrameCount;
	VirtualInvokeData _5_GetFrame;
	VirtualInvokeData _6_GetFrames;
} System_Diagnostics_StackTrace_VTable;

typedef struct System_Diagnostics_StackTrace_c {
	Il2CppClass_1 _1;
	struct System_Diagnostics_StackTrace_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Diagnostics_StackTrace_VTable vtable;
} System_Diagnostics_StackTrace_c;

typedef struct System_Diagnostics_StackTrace_Fields {
	struct System_Diagnostics_StackFrame_array* frames;
	struct System_Diagnostics_StackTrace_array* captured_traces;
	bool debug_info;
} System_Diagnostics_StackTrace_Fields;

typedef struct System_Diagnostics_StackTrace_o {
	System_Diagnostics_StackTrace_c *klass;
	void *monitor;
	System_Diagnostics_StackTrace_Fields fields;
} System_Diagnostics_StackTrace_o;

typedef struct System_Diagnostics_StackTrace_StaticFields {
	bool isAotidSet;
	struct System_String_o* aotid;
} System_Diagnostics_StackTrace_StaticFields;

typedef struct Cysharp_Threading_Tasks_UniTask_Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_o* source;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_o {
	Cysharp_Threading_Tasks_UniTask_Fields fields;
} Cysharp_Threading_Tasks_UniTask_o;

typedef struct Cysharp_Threading_Tasks_UniTask_TResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	Il2CppObject* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_TResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_TResponse__o {
	Cysharp_Threading_Tasks_UniTask_TResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_TResponse__o;

typedef struct System_Nullable_OOJEDNBBGBK__Fields {
	bool hasValue;
	int32_t value;
} System_Nullable_OOJEDNBBGBK__Fields;

typedef struct System_Nullable_OOJEDNBBGBK__o {
	System_Nullable_OOJEDNBBGBK__Fields fields;
} System_Nullable_OOJEDNBBGBK__o;

typedef struct System_Nullable_LFJELIPKMBM__Fields {
	bool hasValue;
	int32_t value;
} System_Nullable_LFJELIPKMBM__Fields;

typedef struct System_Nullable_LFJELIPKMBM__o {
	System_Nullable_LFJELIPKMBM__Fields fields;
} System_Nullable_LFJELIPKMBM__o;

typedef struct System_Nullable_DateTime__Fields {
	bool hasValue;
	struct System_DateTime_o value;
} System_Nullable_DateTime__Fields;

typedef struct System_Nullable_DateTime__o {
	System_Nullable_DateTime__Fields fields;
} System_Nullable_DateTime__o;

typedef struct System_Nullable_IKAFHEBKEHP__Fields {
	bool hasValue;
	int32_t value;
} System_Nullable_IKAFHEBKEHP__Fields;

typedef struct System_Nullable_IKAFHEBKEHP__o {
	System_Nullable_IKAFHEBKEHP__Fields fields;
} System_Nullable_IKAFHEBKEHP__o;

typedef struct MethodInfo_20B62E0 {
	Il2CppMethodPointer methodPointer;
	Il2CppMethodPointer virtualMethodPointer;
	InvokerMethod invoker_method;
	const char* name;
	Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_TResult__c *klass;
	const Il2CppType *return_type;
	const Il2CppType** parameters;
	const Il2CppRGCTXData* rgctx_data;
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
} MethodInfo_20B62E0;

typedef struct Google_Protobuf_MessageParser_TResponse__Fields /* : Google_Protobuf_MessageParser_Fields */ {
	struct System_Func_T__o* factory;
} Google_Protobuf_MessageParser_TResponse__Fields;

typedef struct Google_Protobuf_MessageParser_TResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Google_Protobuf_MessageParser_TResponse__VTable;

typedef struct Google_Protobuf_MessageParser_TResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Google_Protobuf_MessageParser_TResponse__VTable vtable;
} Google_Protobuf_MessageParser_TResponse__c;

typedef struct Google_Protobuf_MessageParser_TResponse__o {
	Google_Protobuf_MessageParser_TResponse__c *klass;
	void *monitor;
	Google_Protobuf_MessageParser_TResponse__Fields fields;
} Google_Protobuf_MessageParser_TResponse__o;

typedef struct MethodInfo_F6CAF0_RGCTXs {
	MethodInfo* _0_Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_TResponse__Create;
	Il2CppClass* _1_Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_TResponse_;
	Il2CppClass* _2_Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_TResponse_;
	Il2CppClass* _3_CDGPJELFAMK_BGANPNAFBEF_TResponse_;
	Il2CppClass* _4_Google_Protobuf_MessageParser_TResponse_;
	MethodInfo* _5_Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_TResponse__Start_CDGPJELFAMK_BGANPNAFBEF_TResponse__;
	Il2CppClass* _6_CDGPJELFAMK_BGANPNAFBEF_TResponse_;
	MethodInfo* _7_Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_TResponse__get_Task;
	Il2CppClass* _8_Cysharp_Threading_Tasks_UniTask_TResponse_;
} MethodInfo_F6CAF0_RGCTXs;

typedef struct MethodInfo_F6CAF0 {
	Il2CppMethodPointer methodPointer;
	Il2CppMethodPointer virtualMethodPointer;
	InvokerMethod invoker_method;
	const char* name;
	CDGPJELFAMK_c *klass;
	const Il2CppType *return_type;
	const Il2CppType** parameters;
	const MethodInfo_F6CAF0_RGCTXs* rgctx_data;
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
} MethodInfo_F6CAF0;

#endif