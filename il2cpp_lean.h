#ifndef IL2CPP_LEAN_H_2025_06_09_2025_04_07
#define IL2CPP_LEAN_H_2025_06_09_2025_04_07

#include <stdint.h>
#include <stdbool.h>

typedef void(*Il2CppMethodPointer)();

typedef struct MethodInfo MethodInfo;
typedef struct Il2CppDomain Il2CppDomain;

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

typedef struct Il2CppClass Il2CppClass;

typedef struct Il2CppObject
{
    Il2CppClass *klass;
    void *monitor;
} Il2CppObject;

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

typedef struct System_String_Fields {
	int32_t _stringLength;
	uint16_t _firstChar;
} System_String_Fields;

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

typedef struct System_String_o {
	System_String_c *klass;
	void *monitor;
	System_String_Fields fields;
} System_String_o;

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

typedef struct System_Byte_array {
	Il2CppObject obj;
	Il2CppArrayBounds *bounds;
	il2cpp_array_size_t max_length;
	uint8_t m_Items[65535];
} System_Byte_array;

typedef struct ONFKFJKNECJ_Fields {
	struct System_Security_Cryptography_ICryptoTransform_o* NIEAFLBOJBE;
} ONFKFJKNECJ_Fields;

typedef struct ONFKFJKNECJ_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_DNMKCHKIBEJ;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_DNMKCHKIBEJ;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_unknown;
	VirtualInvokeData _7_Dispose;
	VirtualInvokeData _8_GHCGEDKKFPH;
} ONFKFJKNECJ_VTable;

typedef struct ONFKFJKNECJ_c {
	Il2CppClass_1 _1;
	struct ONFKFJKNECJ_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	ONFKFJKNECJ_VTable vtable;
} ONFKFJKNECJ_c;

typedef struct ONFKFJKNECJ_o {
	ONFKFJKNECJ_c *klass;
	void *monitor;
	ONFKFJKNECJ_Fields fields;
} ONFKFJKNECJ_o;

typedef struct ONFKFJKNECJ_StaticFields {
	struct System_Security_Cryptography_Aes_o* PPBNDDBMFJM;
} ONFKFJKNECJ_StaticFields;

typedef Il2CppObject *(*IL2CPPOBJECTNEW)(const Il2CppClass *klass);
typedef System_String_o *(*IL2CPPSTRINGNEW)(char *s);
typedef Il2CppDomain *(*IL2CPPDOMAINGET)(void);
typedef void (*IL2CPPTHREADATTACH)(Il2CppDomain *);

Il2CppObject *my_il2cpp_object_new(const Il2CppClass *klass);
System_String_o *my_il2cpp_string_new(char *s);
Il2CppDomain *my_il2cpp_domain_get(void);
void my_il2cpp_thread_attach(Il2CppDomain *);

#endif