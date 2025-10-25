#ifndef IL2CPP_LEAN_H_2025_06_09_2025_04_07
#define IL2CPP_LEAN_H_2025_06_09_2025_04_07

#include "il2cpp_shared.h"

#include <stdint.h>
#include <stdbool.h>

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

typedef struct Neon_Model_Api_ApiService_Fields Neon_Model_Api_ApiService_Fields; /* : CDGPJELFAMK_Fields */

typedef struct Neon_Model_Api_ApiService_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_ONIFJDGBNFE;
	VirtualInvokeData _5_KGFOAKGJBOL;
	VirtualInvokeData _6_unknown;
	VirtualInvokeData _7_LKHAOCKIOPL;
	VirtualInvokeData _8_PIJBCEBGIOH;
	VirtualInvokeData _9_unknown;
	VirtualInvokeData _10_BPCKJFKOKOM;
	VirtualInvokeData _11_NDHHPKBFJBA;
	VirtualInvokeData _12_DAOEJIDKBPB;
	VirtualInvokeData _13_unknown;
	VirtualInvokeData _14_unknown;
	VirtualInvokeData _15_EIJFILJLCCN;
	VirtualInvokeData _16_unknown;
	VirtualInvokeData _17_unknown;
	VirtualInvokeData _18_unknown;
	VirtualInvokeData _19_unknown;
	VirtualInvokeData _20_AKFPCAOAKKF;
	VirtualInvokeData _21_IDKDCHPAICO;
	VirtualInvokeData _22_unknown;
	VirtualInvokeData _23_Adventure_AreaObject;
	VirtualInvokeData _24_Adventure_ReadSequence;
	VirtualInvokeData _25_Adventure_AccessWarpPoint;
	VirtualInvokeData _26_Adventure_ReleaseEventLift;
	VirtualInvokeData _27_Adventure_WarpAreaLocator;
	VirtualInvokeData _28_Adventure_AcquireAreaItem;
	VirtualInvokeData _29_Adventure_FindGraffiti;
	VirtualInvokeData _30_Adventure_MoveToArea;
	VirtualInvokeData _31_Adventure_Hospital;
	VirtualInvokeData _32_Adventure_TrackTarget;
	VirtualInvokeData _33_Adventure_UpdateCharacterStatus;
	VirtualInvokeData _34_Auth_SignIn;
	VirtualInvokeData _35_Auth_SignUp;
	VirtualInvokeData _36_Auth_SignUpApple;
	VirtualInvokeData _37_Auth_SignUpGoogle;
	VirtualInvokeData _38_Auth_SignUpPasscode;
	VirtualInvokeData _39_Auth_SteamUser;
	VirtualInvokeData _40_Auth_Nonce;
	VirtualInvokeData _41_Battle_Start;
	VirtualInvokeData _42_Battle_Finish;
	VirtualInvokeData _43_Battle_Skip;
	VirtualInvokeData _44_Battle_Restart;
	VirtualInvokeData _45_Character_Enhance;
	VirtualInvokeData _46_Character_RankEnhance;
	VirtualInvokeData _47_Character_LimitBreak;
	VirtualInvokeData _48_Character_Equip;
	VirtualInvokeData _49_Character_SkillPanelEnhance;
	VirtualInvokeData _50_Character_SkillPanelReset;
	VirtualInvokeData _51_Character_CostumeUpdate;
	VirtualInvokeData _52_Character_ItemPresent;
	VirtualInvokeData _53_City_ReleaseGearShop;
	VirtualInvokeData _54_Debug_ClientError;
	VirtualInvokeData _55_Debug_ServerError;
	VirtualInvokeData _56_Debug_UserError;
	VirtualInvokeData _57_Debug_JiraToken;
	VirtualInvokeData _58_Debug_ChallengeClear;
	VirtualInvokeData _59_Debug_MailSend;
	VirtualInvokeData _60_Debug_UserBulkResource;
	VirtualInvokeData _61_Debug_ShopPurchase;
	VirtualInvokeData _62_Debug_XbPvpSpecifyEnemy;
	VirtualInvokeData _63_Dish_Order;
	VirtualInvokeData _64_Dungeon_Entry;
	VirtualInvokeData _65_Dungeon_Start;
	VirtualInvokeData _66_Dungeon_Finish;
	VirtualInvokeData _67_Dungeon_Resume;
	VirtualInvokeData _68_Dungeon_AcquireAreaItem;
	VirtualInvokeData _69_Dungeon_BattleStart;
	VirtualInvokeData _70_Dungeon_BattleSkip;
	VirtualInvokeData _71_Event_ListNode;
	VirtualInvokeData _72_Event_FinishNode;
	VirtualInvokeData _73_FieldBoss_Entry;
	VirtualInvokeData _74_Follow_List;
	VirtualInvokeData _75_Follow_Detail;
	VirtualInvokeData _76_Follow_Search;
	VirtualInvokeData _77_Follow_Add;
	VirtualInvokeData _78_Follow_Remove;
	VirtualInvokeData _79_Formation_Update;
	VirtualInvokeData _80_Formation_Switch;
	VirtualInvokeData _81_FractalVise_RewardsTop;
	VirtualInvokeData _82_FractalVise_RewardsReceive;
	VirtualInvokeData _83_FractalVise_Start;
	VirtualInvokeData _84_FractalVise_NextArea;
	VirtualInvokeData _85_FractalVise_Resume;
	VirtualInvokeData _86_FractalVise_Clear;
	VirtualInvokeData _87_FractalVise_Retire;
	VirtualInvokeData _88_FractalVise_AcquireAreaItem;
	VirtualInvokeData _89_FractalVise_BattleStart;
	VirtualInvokeData _90_FractalVise_BossDifficulty;
	VirtualInvokeData _91_FractalVise_BattleStartBossBattle;
	VirtualInvokeData _92_Gacha_List;
	VirtualInvokeData _93_Gacha_Execute;
	VirtualInvokeData _94_Gacha_Select;
	VirtualInvokeData _95_Gear_Lock;
	VirtualInvokeData _96_Gear_Unlock;
	VirtualInvokeData _97_Gear_Compress;
	VirtualInvokeData _98_HappyWorker_List;
	VirtualInvokeData _99_HappyWorker_Start;
	VirtualInvokeData _100_HappyWorker_Cancel;
	VirtualInvokeData _101_Item_Synthesize;
	VirtualInvokeData _102_Item_Exchange;
	VirtualInvokeData _103_Item_UseSupply;
	VirtualInvokeData _104_Item_UseSupplyGearEffect;
	VirtualInvokeData _105_Item_Sell;
	VirtualInvokeData _106_Item_OpenSelectBox;
	VirtualInvokeData _107_ItemRequest_List;
	VirtualInvokeData _108_ItemRequest_Get;
	VirtualInvokeData _109_ItemRequest_Publish;
	VirtualInvokeData _110_ItemRequest_Cancel;
	VirtualInvokeData _111_ItemRequest_Fulfill;
	VirtualInvokeData _112_ItemRequest_Collect;
	VirtualInvokeData _113_LoginBonus_List;
	VirtualInvokeData _114_LoginBonus_Receive;
	VirtualInvokeData _115_Mail_List;
	VirtualInvokeData _116_Mail_Open;
	VirtualInvokeData _117_Mail_Delete;
	VirtualInvokeData _118_Mission_Receive;
	VirtualInvokeData _119_Mission_CountRewardReceive;
	VirtualInvokeData _120_News_List;
	VirtualInvokeData _121_News_UserList;
	VirtualInvokeData _122_Profile_UpdateName;
	VirtualInvokeData _123_Profile_UpdateBanner;
	VirtualInvokeData _124_Profile_UpdateBadges;
	VirtualInvokeData _125_Profile_UpdateCharacterLikabilityScale;
	VirtualInvokeData _126_Purchase_SessionStart;
	VirtualInvokeData _127_Purchase_SessionPublish;
	VirtualInvokeData _128_Purchase_Verify;
	VirtualInvokeData _129_Purchase_History;
	VirtualInvokeData _130_RecipeShop_Purchase;
	VirtualInvokeData _131_RefundApplication_Get;
	VirtualInvokeData _132_RefundApplication_UpdateEmailId;
	VirtualInvokeData _133_RefundApplication_SendVerificationCode;
	VirtualInvokeData _134_RefundApplication_VerifyEmailId;
	VirtualInvokeData _135_RefundApplication_RequestRefund;
	VirtualInvokeData _136_RuledBattle_Start;
	VirtualInvokeData _137_SeasonPass_Receive;
	VirtualInvokeData _138_SeasonPass_ReceiveAll;
	VirtualInvokeData _139_SeasonPass_TierPurchase;
	VirtualInvokeData _140_SeasonPass_PurchasePaidPass;
	VirtualInvokeData _141_Shop_GemList;
	VirtualInvokeData _142_Shop_Purchase;
	VirtualInvokeData _143_Shop_GearShopList;
	VirtualInvokeData _144_Shop_GearShopPurchase;
	VirtualInvokeData _145_Shop_CycleUpdateShopRelease;
	VirtualInvokeData _146_Shop_CycleUpdateShopPurchase;
	VirtualInvokeData _147_Shop_RandomCostumeList;
	VirtualInvokeData _148_Shop_RandomCostumePurchase;
	VirtualInvokeData _149_Stamina_Purchase;
	VirtualInvokeData _150_Stamina_UseItem;
	VirtualInvokeData _151_Subsystem_Status;
	VirtualInvokeData _152_TensionCard_Enhance;
	VirtualInvokeData _153_TensionCard_LevelLimitEnhance;
	VirtualInvokeData _154_TensionCard_LimitBreakEnhance;
	VirtualInvokeData _155_TensionCard_Lock;
	VirtualInvokeData _156_TensionCard_Disassemble;
	VirtualInvokeData _157_Tip_Release;
	VirtualInvokeData _158_Tip_ReleaseByBattle;
	VirtualInvokeData _159_TrialBattle_Start;
	VirtualInvokeData _160_TrialBattle_RewardReceive;
	VirtualInvokeData _161_Tutorial_Skip;
	VirtualInvokeData _162_User_LogIn;
	VirtualInvokeData _163_User_CrossDate;
	VirtualInvokeData _164_User_LinksList;
	VirtualInvokeData _165_User_LinkApple;
	VirtualInvokeData _166_User_UnlinkApple;
	VirtualInvokeData _167_User_LinkGoogle;
	VirtualInvokeData _168_User_UnlinkGoogle;
	VirtualInvokeData _169_User_UnlinkSteam;
	VirtualInvokeData _170_User_UpdateBirthdate;
	VirtualInvokeData _171_User_UpdateLanguage;
	VirtualInvokeData _172_User_Delete;
	VirtualInvokeData _173_User_Notification;
	VirtualInvokeData _174_WebSession_Token;
	VirtualInvokeData _175_Xb_Formation;
	VirtualInvokeData _176_Xb_FormationUpdate;
	VirtualInvokeData _177_Xb_Start;
	VirtualInvokeData _178_Xb_Play;
	VirtualInvokeData _179_Xb_UpdateTension;
	VirtualInvokeData _180_Xb_AddCommandUnlockItem;
	VirtualInvokeData _181_Xb_UpdateSkillOrbStatus;
	VirtualInvokeData _182_Xb_Status;
	VirtualInvokeData _183_Xb_Retire;
	VirtualInvokeData _184_Xb_ForceRetire;
	VirtualInvokeData _185_XbPvp_Formation;
	VirtualInvokeData _186_XbPvp_FormationUpdate;
	VirtualInvokeData _187_XbPvp_Entry;
	VirtualInvokeData _188_XbPvp_QuickMatching;
	VirtualInvokeData _189_XbPvp_RankMatching;
	VirtualInvokeData _190_XbPvp_CasualMatching;
	VirtualInvokeData _191_XbPvp_RankMatchHistoryList;
} Neon_Model_Api_ApiService_VTable;

typedef struct Neon_Model_Api_ApiService_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_ApiService_VTable vtable;
} Neon_Model_Api_ApiService_c;

typedef struct Neon_Model_Api_ApiService_o {
	Neon_Model_Api_ApiService_c *klass;
	void *monitor;
	/* Neon_Model_Api_ApiService_Fields fields; */
} Neon_Model_Api_ApiService_o;

typedef struct System_Threading_CancellationToken_Fields {
	struct System_Threading_CancellationTokenSource_o* _source;
} System_Threading_CancellationToken_Fields;

typedef struct System_Threading_CancellationToken_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} System_Threading_CancellationToken_VTable;

typedef struct System_Threading_CancellationToken_c {
	Il2CppClass_1 _1;
	struct System_Threading_CancellationToken_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Threading_CancellationToken_VTable vtable;
} System_Threading_CancellationToken_c;

typedef struct System_Threading_CancellationToken_o {
	System_Threading_CancellationToken_Fields fields;
} System_Threading_CancellationToken_o;

typedef struct System_Threading_CancellationToken_StaticFields {
	struct System_Action_object__o* s_actionToActionObjShunt;
} System_Threading_CancellationToken_StaticFields;

typedef struct LPCOHPIGHIN_Fields LPCOHPIGHIN_Fields;

typedef struct LPCOHPIGHIN_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	VirtualInvokeData vtable[32];
} LPCOHPIGHIN_c;

typedef struct LPCOHPIGHIN_o {
	LPCOHPIGHIN_c *klass;
	void *monitor;
	/* LPCOHPIGHIN_Fields fields; */
} LPCOHPIGHIN_o;

typedef struct Neon_Model_Api_Rpc_AuthSteamUserRequest_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_MergeFrom;
	VirtualInvokeData _5_MergeFrom;
	VirtualInvokeData _6_WriteTo;
	VirtualInvokeData _7_CalculateSize;
	VirtualInvokeData _8_pb__Google_Protobuf_IMessage_get_Descriptor;
	VirtualInvokeData _9_Equals;
	VirtualInvokeData _10_Clone;
	VirtualInvokeData _11_pb__Google_Protobuf_IBufferMessage_InternalMergeFrom;
	VirtualInvokeData _12_pb__Google_Protobuf_IBufferMessage_InternalWriteTo;
} Neon_Model_Api_Rpc_AuthSteamUserRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AuthSteamUserRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AuthSteamUserRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AuthSteamUserRequest_VTable vtable;
} Neon_Model_Api_Rpc_AuthSteamUserRequest_c;

typedef struct Neon_Model_Api_Rpc_AuthSteamUserRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_String_o* sessionTicket_;
} Neon_Model_Api_Rpc_AuthSteamUserRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AuthSteamUserRequest_o {
	Neon_Model_Api_Rpc_AuthSteamUserRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AuthSteamUserRequest_Fields fields;
} Neon_Model_Api_Rpc_AuthSteamUserRequest_o;

typedef struct Neon_Model_Api_Rpc_AuthSteamUserRequest_StaticFields {
	struct Google_Protobuf_MessageParser_AuthSteamUserRequest__o* _parser;
} Neon_Model_Api_Rpc_AuthSteamUserRequest_StaticFields;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSteamUserResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_AuthSteamUserResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_AuthSteamUserResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSteamUserResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_AuthSteamUserResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSteamUserResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_AuthSteamUserResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_AuthSteamUserResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSteamUserResponse__o {
	Cysharp_Threading_Tasks_UniTask_AuthSteamUserResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_AuthSteamUserResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSource_Fields {
	struct System_Threading_CancellationToken_o cancellationToken;
	struct Cysharp_Threading_Tasks_ExceptionHolder_o* exception;
	Il2CppObject* gate;
	struct System_Action_object__o* singleContinuation;
	Il2CppObject* singleState;
	struct System_Collections_Generic_List_ValueTuple_Action_object___object___o* secondaryContinuationList;
	int32_t intStatus;
	bool handled;
} Cysharp_Threading_Tasks_UniTaskCompletionSource_Fields;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSource_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_System_Threading_Tasks_Sources_IValueTaskSource_GetStatus;
	VirtualInvokeData _5_System_Threading_Tasks_Sources_IValueTaskSource_GetResult;
	VirtualInvokeData _6_System_Threading_Tasks_Sources_IValueTaskSource_OnCompleted;
	VirtualInvokeData _7_UnsafeGetStatus;
	VirtualInvokeData _8_unknown;
	VirtualInvokeData _9_unknown;
	VirtualInvokeData _10_unknown;
	VirtualInvokeData _11_unknown;
	VirtualInvokeData _12_unknown;
	VirtualInvokeData _13_GetResult;
	VirtualInvokeData _14_TrySetResult;
	VirtualInvokeData _15_TrySetException;
	VirtualInvokeData _16_TrySetCanceled;
} Cysharp_Threading_Tasks_UniTaskCompletionSource_VTable;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSource_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTaskCompletionSource_VTable vtable;
} Cysharp_Threading_Tasks_UniTaskCompletionSource_c;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSource_o {
	Cysharp_Threading_Tasks_UniTaskCompletionSource_c *klass;
	void *monitor;
	Cysharp_Threading_Tasks_UniTaskCompletionSource_Fields fields;
} Cysharp_Threading_Tasks_UniTaskCompletionSource_o;

typedef struct Neon_Model_Api_Rpc_AuthSteamUserResponse_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int64_t userId_;
} Neon_Model_Api_Rpc_AuthSteamUserResponse_Fields;

typedef struct Neon_Model_Api_Rpc_AuthSteamUserResponse_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_MergeFrom;
	VirtualInvokeData _5_MergeFrom;
	VirtualInvokeData _6_WriteTo;
	VirtualInvokeData _7_CalculateSize;
	VirtualInvokeData _8_pb__Google_Protobuf_IMessage_get_Descriptor;
	VirtualInvokeData _9_Equals;
	VirtualInvokeData _10_Clone;
	VirtualInvokeData _11_pb__Google_Protobuf_IBufferMessage_InternalMergeFrom;
	VirtualInvokeData _12_pb__Google_Protobuf_IBufferMessage_InternalWriteTo;
} Neon_Model_Api_Rpc_AuthSteamUserResponse_VTable;

typedef struct Neon_Model_Api_Rpc_AuthSteamUserResponse_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AuthSteamUserResponse_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AuthSteamUserResponse_VTable vtable;
} Neon_Model_Api_Rpc_AuthSteamUserResponse_c;

typedef struct Neon_Model_Api_Rpc_AuthSteamUserResponse_o {
	Neon_Model_Api_Rpc_AuthSteamUserResponse_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AuthSteamUserResponse_Fields fields;
} Neon_Model_Api_Rpc_AuthSteamUserResponse_o;

typedef struct Neon_Model_Api_Rpc_AuthSteamUserResponse_StaticFields {
	struct Google_Protobuf_MessageParser_AuthSteamUserResponse__o* _parser;
} Neon_Model_Api_Rpc_AuthSteamUserResponse_StaticFields;

typedef struct Cysharp_Threading_Tasks_IUniTaskSource_T__Fields Cysharp_Threading_Tasks_IUniTaskSource_T__Fields;

typedef struct Cysharp_Threading_Tasks_IUniTaskSource_T__RGCTXs {
	Il2CppClass* _0_Cysharp_Threading_Tasks_IUniTaskSource_T_;
	MethodInfo* _1_Cysharp_Threading_Tasks_IUniTaskSource_T__GetResult;
	Il2CppClass* _2_T;
} Cysharp_Threading_Tasks_IUniTaskSource_T__RGCTXs;

typedef struct Cysharp_Threading_Tasks_IUniTaskSource_T__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Cysharp_Threading_Tasks_IUniTaskSource_T__RGCTXs* rgctx_data;
	Il2CppClass_2 _2;
	VirtualInvokeData vtable[32];
} Cysharp_Threading_Tasks_IUniTaskSource_T__c;

typedef struct Cysharp_Threading_Tasks_IUniTaskSource_T__o {
	Cysharp_Threading_Tasks_IUniTaskSource_T__c *klass;
	void *monitor;
	/* Cysharp_Threading_Tasks_IUniTaskSource_T__Fields fields; */
} Cysharp_Threading_Tasks_IUniTaskSource_T__o;

typedef struct Cysharp_Threading_Tasks_UniTask_Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_o* source;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_c {
	Il2CppClass_1 _1;
	struct Cysharp_Threading_Tasks_UniTask_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_VTable vtable;
} Cysharp_Threading_Tasks_UniTask_c;

typedef struct Cysharp_Threading_Tasks_UniTask_o {
	Cysharp_Threading_Tasks_UniTask_Fields fields;
} Cysharp_Threading_Tasks_UniTask_o;

typedef struct Cysharp_Threading_Tasks_UniTask_StaticFields {
	struct Cysharp_Threading_Tasks_UniTask_o CanceledUniTask;
	struct Cysharp_Threading_Tasks_UniTask_o CompletedTask;
} Cysharp_Threading_Tasks_UniTask_StaticFields;

typedef struct Cysharp_Threading_Tasks_UniTask_T__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	Il2CppObject* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_T__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_T__RGCTXs {
	Il2CppClass* _0_Cysharp_Threading_Tasks_UniTask_T_;
	Il2CppClass* _1_Cysharp_Threading_Tasks_IUniTaskSource_T_;
	Il2CppClass* _2_T;
	MethodInfo* _3_Cysharp_Threading_Tasks_IUniTaskSource_T__GetStatus;
	Il2CppClass* _4_Cysharp_Threading_Tasks_UniTask_Awaiter_T_;
	MethodInfo* _5_Cysharp_Threading_Tasks_UniTask_Awaiter_T___ctor;
	Il2CppClass* _6_Cysharp_Threading_Tasks_UniTask_T_;
	MethodInfo* _7_Cysharp_Threading_Tasks_IUniTaskSource_T__GetResult;
	MethodInfo* _8_Cysharp_Threading_Tasks_UniTask_T__AsUniTask;
	Il2CppClass* _9_Cysharp_Threading_Tasks_UniTask_T_;
	Il2CppClass* _10_System_ValueTuple_bool__T_;
	MethodInfo* _11_System_ValueTuple_bool__T___ctor;
	Il2CppClass* _12_Cysharp_Threading_Tasks_UniTask_ValueTuple_bool__T__;
	MethodInfo* _13_Cysharp_Threading_Tasks_UniTask_ValueTuple_bool__T____ctor;
	Il2CppClass* _14_Cysharp_Threading_Tasks_UniTask_IsCanceledSource_T_;
	MethodInfo* _15_Cysharp_Threading_Tasks_UniTask_IsCanceledSource_T___ctor;
	MethodInfo* _16_Cysharp_Threading_Tasks_UniTask_ValueTuple_bool__T____ctor;
	Il2CppClass* _17_Cysharp_Threading_Tasks_IUniTaskSource_ValueTuple_bool__T__;
} Cysharp_Threading_Tasks_UniTask_T__RGCTXs;

typedef struct Cysharp_Threading_Tasks_UniTask_T__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_T__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_T__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Cysharp_Threading_Tasks_UniTask_T__RGCTXs* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_T__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_T__c;

typedef struct Cysharp_Threading_Tasks_UniTask_T__o {
	Cysharp_Threading_Tasks_UniTask_T__Fields fields;
} Cysharp_Threading_Tasks_UniTask_T__o;

typedef struct System_Action_T__Fields System_Action_T__Fields; /* : System_MulticastDelegate_Fields */

typedef struct System_Action_T__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_DynamicInvokeImpl;
	VirtualInvokeData _7_Clone;
	VirtualInvokeData _8_GetMethodImpl;
	VirtualInvokeData _9_GetObjectData;
	VirtualInvokeData _10_GetInvocationList;
	VirtualInvokeData _11_CombineImpl;
	VirtualInvokeData _12_RemoveImpl;
	VirtualInvokeData _13_Invoke;
} System_Action_T__VTable;

typedef struct System_Action_T__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Action_T__VTable vtable;
} System_Action_T__c;

typedef struct System_Action_T__o {
	System_Action_T__c *klass;
	void *monitor;
	/* System_Action_T__Fields fields; */
} System_Action_T__o;

typedef struct MethodInfo_110C390_RGCTXs {
	Il2CppClass* _0_Cysharp_Threading_Tasks_UniTaskExtensions__ContinueWith_d__22_T_;
	Il2CppClass* _1_Cysharp_Threading_Tasks_UniTask_T_;
	Il2CppClass* _2_System_Action_T_;
	MethodInfo* _3_Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_Start_UniTaskExtensions__ContinueWith_d__22_T__;
	Il2CppClass* _4_Cysharp_Threading_Tasks_UniTaskExtensions__ContinueWith_d__22_T_;
} MethodInfo_110C390_RGCTXs;

typedef struct Cysharp_Threading_Tasks_UniTaskExtensions_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTaskExtensions_VTable;

typedef struct Cysharp_Threading_Tasks_UniTaskExtensions_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTaskExtensions_VTable vtable;
} Cysharp_Threading_Tasks_UniTaskExtensions_c;

typedef struct Cysharp_Threading_Tasks_UniTaskExtensions_Fields Cysharp_Threading_Tasks_UniTaskExtensions_Fields;

typedef struct Cysharp_Threading_Tasks_UniTaskExtensions_o {
	Cysharp_Threading_Tasks_UniTaskExtensions_c *klass;
	void *monitor;
	/* Cysharp_Threading_Tasks_UniTaskExtensions_Fields fields; */
} Cysharp_Threading_Tasks_UniTaskExtensions_o;

typedef struct MethodInfo_110C390 {
	Il2CppMethodPointer methodPointer;
	Il2CppMethodPointer virtualMethodPointer;
	InvokerMethod invoker_method;
	const char* name;
	Cysharp_Threading_Tasks_UniTaskExtensions_c *klass;
	const Il2CppType *return_type;
	const Il2CppType** parameters;
	const MethodInfo_110C390_RGCTXs* rgctx_data;
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
} MethodInfo_110C390;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSource_T__Fields {
	struct System_Threading_CancellationToken_o cancellationToken;
	Il2CppObject* result;
	struct Cysharp_Threading_Tasks_ExceptionHolder_o* exception;
	Il2CppObject* gate;
	struct System_Action_object__o* singleContinuation;
	Il2CppObject* singleState;
	struct System_Collections_Generic_List_ValueTuple_Action_object___object___o* secondaryContinuationList;
	int32_t intStatus;
	bool handled;
} Cysharp_Threading_Tasks_UniTaskCompletionSource_T__Fields;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSource_T__RGCTXs {
	Il2CppClass* _0_Cysharp_Threading_Tasks_UniTaskCompletionSource_T_;
	Il2CppClass* _1_Cysharp_Threading_Tasks_UniTask_T_;
	MethodInfo* _2_Cysharp_Threading_Tasks_UniTask_T___ctor;
	Il2CppClass* _3_Cysharp_Threading_Tasks_IUniTaskSource_T_;
	MethodInfo* _4_Cysharp_Threading_Tasks_UniTaskCompletionSource_T__UnsafeGetStatus;
	Il2CppClass* _5_T;
	MethodInfo* _6_Cysharp_Threading_Tasks_UniTaskCompletionSource_T__TrySignalCompletion;
	MethodInfo* _7_Cysharp_Threading_Tasks_UniTaskCompletionSource_T__TrySetCanceled;
	MethodInfo* _8_Cysharp_Threading_Tasks_UniTaskCompletionSource_T__MarkHandled;
	MethodInfo* _9_Cysharp_Threading_Tasks_UniTaskCompletionSource_T__GetResult;
} Cysharp_Threading_Tasks_UniTaskCompletionSource_T__RGCTXs;
typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSource_T__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_System_Threading_Tasks_Sources_IValueTaskSource_T__GetStatus;
	VirtualInvokeData _4_System_Threading_Tasks_Sources_IValueTaskSource_GetStatus;
	VirtualInvokeData _5_System_Threading_Tasks_Sources_IValueTaskSource_T__OnCompleted;
	VirtualInvokeData _6_System_Threading_Tasks_Sources_IValueTaskSource_OnCompleted;
	VirtualInvokeData _7_unknown;
	VirtualInvokeData _8_unknown;
	VirtualInvokeData _9_unknown;
	VirtualInvokeData _10_GetStatus;
	VirtualInvokeData _11_OnCompleted;
	VirtualInvokeData _12_Cysharp_Threading_Tasks_IUniTaskSource_GetResult;
	VirtualInvokeData _13_UnsafeGetStatus;
	VirtualInvokeData _14_unknown;
	VirtualInvokeData _15_unknown;
	VirtualInvokeData _16_unknown;
	VirtualInvokeData _17_unknown;
	VirtualInvokeData _18_unknown;
	VirtualInvokeData _19_unknown;
	VirtualInvokeData _20_unknown;
	VirtualInvokeData _21_unknown;
	VirtualInvokeData _22_GetResult;
	VirtualInvokeData _23_TrySetResult;
	VirtualInvokeData _24_TrySetException;
	VirtualInvokeData _25_TrySetCanceled;
} Cysharp_Threading_Tasks_UniTaskCompletionSource_T__VTable;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSource_T__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Cysharp_Threading_Tasks_UniTaskCompletionSource_T__RGCTXs* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTaskCompletionSource_T__VTable vtable;
} Cysharp_Threading_Tasks_UniTaskCompletionSource_T__c;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSource_T__o {
	Cysharp_Threading_Tasks_UniTaskCompletionSource_T__c *klass;
	void *monitor;
	Cysharp_Threading_Tasks_UniTaskCompletionSource_T__Fields fields;
} Cysharp_Threading_Tasks_UniTaskCompletionSource_T__o;

typedef struct MethodInfo_2352A00 {
	Il2CppMethodPointer methodPointer;
	Il2CppMethodPointer virtualMethodPointer;
	InvokerMethod invoker_method;
	const char* name;
	Cysharp_Threading_Tasks_UniTaskCompletionSource_T__c *klass;
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
} MethodInfo_2352A00;

typedef struct System_Threading_Tasks_TaskCompletionSource_object__Fields {
	struct System_Threading_Tasks_Task_TResult__o* _task;
} System_Threading_Tasks_TaskCompletionSource_object__Fields;

typedef struct System_Threading_Tasks_TaskCompletionSource_object__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} System_Threading_Tasks_TaskCompletionSource_object__VTable;
typedef struct System_Threading_Tasks_TaskCompletionSource_object__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Threading_Tasks_TaskCompletionSource_object__VTable vtable;
} System_Threading_Tasks_TaskCompletionSource_object__c;
typedef struct System_Threading_Tasks_TaskCompletionSource_object__o {
	System_Threading_Tasks_TaskCompletionSource_object__c *klass;
	void *monitor;
	System_Threading_Tasks_TaskCompletionSource_object__Fields fields;
}System_Threading_Tasks_TaskCompletionSource_object__o;

typedef struct  System_Threading_Tasks_TaskCompletionSource_TResult__Fields {
	struct System_Threading_Tasks_Task_TResult__o* _task;
} System_Threading_Tasks_TaskCompletionSource_TResult__Fields;
typedef struct System_Threading_Tasks_TaskCompletionSource_TResult__RGCTXs {
	Il2CppClass* _0_System_Threading_Tasks_Task_TResult_;
	MethodInfo* _1_System_Threading_Tasks_Task_TResult___ctor;
	Il2CppClass* _2_System_Threading_Tasks_TaskCompletionSource_TResult_;
	MethodInfo* _3_System_Threading_Tasks_TaskCompletionSource_TResult___ctor;
	MethodInfo* _4_System_Threading_Tasks_Task_TResult___ctor;
	MethodInfo* _5_System_Threading_Tasks_TaskCompletionSource_TResult__SpinUntilCompleted;
	MethodInfo* _6_System_Threading_Tasks_TaskCompletionSource_TResult__TrySetException;
	Il2CppClass* _7_TResult;
	MethodInfo* _8_System_Threading_Tasks_Task_TResult__TrySetResult;
	MethodInfo* _9_System_Threading_Tasks_TaskCompletionSource_TResult__TrySetResult;
	MethodInfo* _10_System_Threading_Tasks_TaskCompletionSource_TResult__TrySetCanceled;
	MethodInfo* _11_System_Threading_Tasks_TaskCompletionSource_TResult__TrySetCanceled;
 } System_Threading_Tasks_TaskCompletionSource_TResult__RGCTXs;
typedef struct System_Threading_Tasks_TaskCompletionSource_TResult__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} System_Threading_Tasks_TaskCompletionSource_TResult__VTable;
typedef struct System_Threading_Tasks_TaskCompletionSource_TResult__c {
	Il2CppClass_1 _1;
	void* static_fields;
	System_Threading_Tasks_TaskCompletionSource_TResult__RGCTXs* rgctx_data;
	Il2CppClass_2 _2;
	System_Threading_Tasks_TaskCompletionSource_TResult__VTable vtable;
} System_Threading_Tasks_TaskCompletionSource_TResult__c;
typedef struct System_Threading_Tasks_TaskCompletionSource_TResult__o {
	System_Threading_Tasks_TaskCompletionSource_TResult__c *klass;
	void *monitor;
	System_Threading_Tasks_TaskCompletionSource_TResult__Fields fields;
} System_Threading_Tasks_TaskCompletionSource_TResult__o;

typedef struct MethodInfo_223E1D0 {
	Il2CppMethodPointer methodPointer;
	Il2CppMethodPointer virtualMethodPointer;
	InvokerMethod invoker_method;
	const char* name;
	System_Threading_Tasks_TaskCompletionSource_TResult__c *klass;
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
} MethodInfo_223E1D0;

typedef struct Cysharp_Threading_Tasks_UniTask_Awaiter_object__Fields {
	struct Cysharp_Threading_Tasks_UniTask_T__o task;
} Cysharp_Threading_Tasks_UniTask_Awaiter_object__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_Awaiter_object__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_UnsafeOnCompleted;
} Cysharp_Threading_Tasks_UniTask_Awaiter_object__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_Awaiter_object__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_Awaiter_object__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_Awaiter_object__c;

typedef struct Cysharp_Threading_Tasks_UniTask_Awaiter_object__o {
	Cysharp_Threading_Tasks_UniTask_Awaiter_object__Fields fields;
} Cysharp_Threading_Tasks_UniTask_Awaiter_object__o;

typedef struct Cysharp_Threading_Tasks_UniTask_Awaiter_T__Fields {
	struct Cysharp_Threading_Tasks_UniTask_T__o task;
} Cysharp_Threading_Tasks_UniTask_Awaiter_T__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_Awaiter_T__RGCTXs {
	Il2CppClass* _0_Cysharp_Threading_Tasks_UniTask_T_;
	Il2CppClass* _1_Cysharp_Threading_Tasks_UniTask_T_;
	Il2CppClass* _2_Cysharp_Threading_Tasks_UniTask_Awaiter_T_;
	MethodInfo* _3_Cysharp_Threading_Tasks_UniTask_T__get_Status;
	Il2CppClass* _4_Cysharp_Threading_Tasks_UniTask_T_;
	Il2CppClass* _5_Cysharp_Threading_Tasks_IUniTaskSource_T_;
	Il2CppClass* _6_T;
	MethodInfo* _7_Cysharp_Threading_Tasks_IUniTaskSource_T__GetResult;
	MethodInfo* _8_Cysharp_Threading_Tasks_IUniTaskSource_T__OnCompleted;
} Cysharp_Threading_Tasks_UniTask_Awaiter_T__RGCTXs;
typedef struct Cysharp_Threading_Tasks_UniTask_Awaiter_T__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_UnsafeOnCompleted;
} Cysharp_Threading_Tasks_UniTask_Awaiter_T__VTable;
typedef struct Cysharp_Threading_Tasks_UniTask_Awaiter_T__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Cysharp_Threading_Tasks_UniTask_Awaiter_T__RGCTXs* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_Awaiter_T__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_Awaiter_T__c;
typedef struct Cysharp_Threading_Tasks_UniTask_Awaiter_T__o {
	Cysharp_Threading_Tasks_UniTask_Awaiter_T__Fields fields;
} Cysharp_Threading_Tasks_UniTask_Awaiter_T__o;

typedef struct MethodInfo_2ED6660 {
	Il2CppMethodPointer methodPointer;
	Il2CppMethodPointer virtualMethodPointer;
	InvokerMethod invoker_method;
	const char* name;
	Cysharp_Threading_Tasks_UniTask_Awaiter_T__c *klass;
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
} MethodInfo_2ED6660;

typedef struct System_Threading_SparselyPopulatedArrayAddInfo_CancellationCallbackInfo__Fields {
	struct System_Threading_SparselyPopulatedArrayFragment_T__o* _source;
	int32_t _index;
} System_Threading_SparselyPopulatedArrayAddInfo_CancellationCallbackInfo__Fields;
typedef struct System_Threading_SparselyPopulatedArrayAddInfo_CancellationCallbackInfo__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} System_Threading_SparselyPopulatedArrayAddInfo_CancellationCallbackInfo__VTable;
typedef struct System_Threading_SparselyPopulatedArrayAddInfo_CancellationCallbackInfo__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Threading_SparselyPopulatedArrayAddInfo_CancellationCallbackInfo__VTable vtable;
} System_Threading_SparselyPopulatedArrayAddInfo_CancellationCallbackInfo__c;
typedef struct System_Threading_SparselyPopulatedArrayAddInfo_CancellationCallbackInfo__o {
	System_Threading_SparselyPopulatedArrayAddInfo_CancellationCallbackInfo__Fields fields;
} System_Threading_SparselyPopulatedArrayAddInfo_CancellationCallbackInfo__o;

typedef struct System_Threading_CancellationTokenRegistration_Fields {
	struct System_Threading_CancellationCallbackInfo_o* m_callbackInfo;
	struct System_Threading_SparselyPopulatedArrayAddInfo_CancellationCallbackInfo__o m_registrationInfo;
} System_Threading_CancellationTokenRegistration_Fields;

typedef struct System_Threading_CancellationTokenRegistration_o {
	System_Threading_CancellationTokenRegistration_Fields fields;
} System_Threading_CancellationTokenRegistration_o;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__Fields {
	Il2CppObject* result;
	Il2CppObject* error;
	int16_t version;
	bool hasUnhandledError;
	int32_t completedCount;
	struct System_Action_object__o* continuation;
	Il2CppObject* continuationState;
} Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__Fields;
typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__VTable;
typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__VTable vtable;
} Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__c;
typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__o {
	Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__Fields fields;
} Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__o;

typedef struct Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__Fields {
	struct Cysharp_Threading_Tasks_Triggers_AsyncTriggerBase_T__o* trigger;
	struct System_Threading_CancellationToken_o cancellationToken;
	struct System_Threading_CancellationTokenRegistration_o registration;
	bool isDisposed;
	bool callOnce;
	struct Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__o core;
	struct Cysharp_Threading_Tasks_ITriggerHandler_T__o* _Cysharp_Threading_Tasks_ITriggerHandler_T__Prev_k__BackingField;
	struct Cysharp_Threading_Tasks_ITriggerHandler_T__o* _Cysharp_Threading_Tasks_ITriggerHandler_T__Next_k__BackingField;
} Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__Fields;
typedef struct Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__RGCTXs {
	Il2CppClass* _0_Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T_;
	Il2CppClass* _1_Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T_;
	MethodInfo* _2_Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__Reset;
	Il2CppClass* _3_Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T_;
	MethodInfo* _4_Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__get_Version;
	Il2CppClass* _5_Cysharp_Threading_Tasks_ITriggerHandler_T_;
	Il2CppClass* _6_Cysharp_Threading_Tasks_Triggers_AsyncTriggerBase_T_;
	MethodInfo* _7_Cysharp_Threading_Tasks_Triggers_AsyncTriggerBase_T__AddHandler;
	Il2CppClass* _8_Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T_;
	MethodInfo* _9_Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__Dispose;
	MethodInfo* _10_Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__TrySetCanceled;
	MethodInfo* _11_Cysharp_Threading_Tasks_Triggers_AsyncTriggerBase_T__RemoveHandler;
	MethodInfo* _12_Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__GetResult;
	Il2CppClass* _13_T;
	MethodInfo* _14_Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__TrySetResult;
	Il2CppClass* _15_Cysharp_Threading_Tasks_IUniTaskSource_T_;
	MethodInfo* _16_Cysharp_Threading_Tasks_IUniTaskSource_T__GetResult;
	MethodInfo* _17_Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__GetStatus;
	MethodInfo* _18_Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__UnsafeGetStatus;
	MethodInfo* _19_Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_T__OnCompleted;
	MethodInfo* _20_Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__CancellationCallback;
} Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__RGCTXs;
typedef struct Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_GetStatus;
	VirtualInvokeData _2_OnCompleted;
	VirtualInvokeData _3_System_Threading_Tasks_Sources_IValueTaskSource_T__GetStatus;
	VirtualInvokeData _4_System_Threading_Tasks_Sources_IValueTaskSource_T__GetResult;
	VirtualInvokeData _5_System_Threading_Tasks_Sources_IValueTaskSource_T__OnCompleted;
	VirtualInvokeData _6_System_Threading_Tasks_Sources_IValueTaskSource_OnCompleted;
	VirtualInvokeData _7_unknown;
	VirtualInvokeData _8_unknown;
	VirtualInvokeData _9_unknown;
	VirtualInvokeData _10_unknown;
	VirtualInvokeData _11_Cysharp_Threading_Tasks_IUniTaskSource_GetStatus;
	VirtualInvokeData _12_Cysharp_Threading_Tasks_IUniTaskSource_OnCompleted;
	VirtualInvokeData _13_Cysharp_Threading_Tasks_IUniTaskSource_GetResult;
	VirtualInvokeData _14_Cysharp_Threading_Tasks_IUniTaskSource_UnsafeGetStatus;
	VirtualInvokeData _15_unknown;
	VirtualInvokeData _16_unknown;
	VirtualInvokeData _17_unknown;
	VirtualInvokeData _18_unknown;
	VirtualInvokeData _19_unknown;
	VirtualInvokeData _20_unknown;
	VirtualInvokeData _21_unknown;
	VirtualInvokeData _22_unknown;
	VirtualInvokeData _23_unknown;
	VirtualInvokeData _24_Cysharp_Threading_Tasks_ITriggerHandler_T__OnNext;
	VirtualInvokeData _25_Cysharp_Threading_Tasks_ITriggerHandler_T__OnCompleted;
	VirtualInvokeData _26_Cysharp_Threading_Tasks_ITriggerHandler_T__get_Prev;
	VirtualInvokeData _27_Cysharp_Threading_Tasks_ITriggerHandler_T__set_Prev;
	VirtualInvokeData _28_Cysharp_Threading_Tasks_ITriggerHandler_T__get_Next;
	VirtualInvokeData _29_Cysharp_Threading_Tasks_ITriggerHandler_T__set_Next;
	VirtualInvokeData _30_Dispose;
	VirtualInvokeData _31_Cysharp_Threading_Tasks_Triggers_IAsyncFixedUpdateHandler_FixedUpdateAsync;
	VirtualInvokeData _32_Cysharp_Threading_Tasks_Triggers_IAsyncLateUpdateHandler_LateUpdateAsync;
	VirtualInvokeData _33_Cysharp_Threading_Tasks_Triggers_IAsyncOnAnimatorIKHandler_OnAnimatorIKAsync;
	VirtualInvokeData _34_Cysharp_Threading_Tasks_Triggers_IAsyncOnAnimatorMoveHandler_OnAnimatorMoveAsync;
	VirtualInvokeData _35_Cysharp_Threading_Tasks_Triggers_IAsyncOnApplicationFocusHandler_OnApplicationFocusAsync;
	VirtualInvokeData _36_Cysharp_Threading_Tasks_Triggers_IAsyncOnApplicationPauseHandler_OnApplicationPauseAsync;
	VirtualInvokeData _37_Cysharp_Threading_Tasks_Triggers_IAsyncOnApplicationQuitHandler_OnApplicationQuitAsync;
	VirtualInvokeData _38_Cysharp_Threading_Tasks_Triggers_IAsyncOnAudioFilterReadHandler_OnAudioFilterReadAsync;
	VirtualInvokeData _39_Cysharp_Threading_Tasks_Triggers_IAsyncOnBecameInvisibleHandler_OnBecameInvisibleAsync;
	VirtualInvokeData _40_Cysharp_Threading_Tasks_Triggers_IAsyncOnBecameVisibleHandler_OnBecameVisibleAsync;
	VirtualInvokeData _41_Cysharp_Threading_Tasks_Triggers_IAsyncOnBeforeTransformParentChangedHandler_OnBeforeTransformParentChangedAsync;
	VirtualInvokeData _42_Cysharp_Threading_Tasks_Triggers_IAsyncOnCanvasGroupChangedHandler_OnCanvasGroupChangedAsync;
	VirtualInvokeData _43_Cysharp_Threading_Tasks_Triggers_IAsyncOnCollisionEnterHandler_OnCollisionEnterAsync;
	VirtualInvokeData _44_Cysharp_Threading_Tasks_Triggers_IAsyncOnCollisionEnter2DHandler_OnCollisionEnter2DAsync;
	VirtualInvokeData _45_Cysharp_Threading_Tasks_Triggers_IAsyncOnCollisionExitHandler_OnCollisionExitAsync;
	VirtualInvokeData _46_Cysharp_Threading_Tasks_Triggers_IAsyncOnCollisionExit2DHandler_OnCollisionExit2DAsync;
	VirtualInvokeData _47_Cysharp_Threading_Tasks_Triggers_IAsyncOnCollisionStayHandler_OnCollisionStayAsync;
	VirtualInvokeData _48_Cysharp_Threading_Tasks_Triggers_IAsyncOnCollisionStay2DHandler_OnCollisionStay2DAsync;
	VirtualInvokeData _49_Cysharp_Threading_Tasks_Triggers_IAsyncOnControllerColliderHitHandler_OnControllerColliderHitAsync;
	VirtualInvokeData _50_Cysharp_Threading_Tasks_Triggers_IAsyncOnDisableHandler_OnDisableAsync;
	VirtualInvokeData _51_Cysharp_Threading_Tasks_Triggers_IAsyncOnDrawGizmosHandler_OnDrawGizmosAsync;
	VirtualInvokeData _52_Cysharp_Threading_Tasks_Triggers_IAsyncOnDrawGizmosSelectedHandler_OnDrawGizmosSelectedAsync;
	VirtualInvokeData _53_Cysharp_Threading_Tasks_Triggers_IAsyncOnEnableHandler_OnEnableAsync;
	VirtualInvokeData _54_Cysharp_Threading_Tasks_Triggers_IAsyncOnGUIHandler_OnGUIAsync;
	VirtualInvokeData _55_Cysharp_Threading_Tasks_Triggers_IAsyncOnJointBreakHandler_OnJointBreakAsync;
	VirtualInvokeData _56_Cysharp_Threading_Tasks_Triggers_IAsyncOnJointBreak2DHandler_OnJointBreak2DAsync;
	VirtualInvokeData _57_Cysharp_Threading_Tasks_Triggers_IAsyncOnMouseDownHandler_OnMouseDownAsync;
	VirtualInvokeData _58_Cysharp_Threading_Tasks_Triggers_IAsyncOnMouseDragHandler_OnMouseDragAsync;
	VirtualInvokeData _59_Cysharp_Threading_Tasks_Triggers_IAsyncOnMouseEnterHandler_OnMouseEnterAsync;
	VirtualInvokeData _60_Cysharp_Threading_Tasks_Triggers_IAsyncOnMouseExitHandler_OnMouseExitAsync;
	VirtualInvokeData _61_Cysharp_Threading_Tasks_Triggers_IAsyncOnMouseOverHandler_OnMouseOverAsync;
	VirtualInvokeData _62_Cysharp_Threading_Tasks_Triggers_IAsyncOnMouseUpHandler_OnMouseUpAsync;
	VirtualInvokeData _63_Cysharp_Threading_Tasks_Triggers_IAsyncOnMouseUpAsButtonHandler_OnMouseUpAsButtonAsync;
	VirtualInvokeData _64_Cysharp_Threading_Tasks_Triggers_IAsyncOnParticleCollisionHandler_OnParticleCollisionAsync;
	VirtualInvokeData _65_Cysharp_Threading_Tasks_Triggers_IAsyncOnParticleSystemStoppedHandler_OnParticleSystemStoppedAsync;
	VirtualInvokeData _66_Cysharp_Threading_Tasks_Triggers_IAsyncOnParticleTriggerHandler_OnParticleTriggerAsync;
	VirtualInvokeData _67_Cysharp_Threading_Tasks_Triggers_IAsyncOnParticleUpdateJobScheduledHandler_OnParticleUpdateJobScheduledAsync;
	VirtualInvokeData _68_Cysharp_Threading_Tasks_Triggers_IAsyncOnPostRenderHandler_OnPostRenderAsync;
	VirtualInvokeData _69_Cysharp_Threading_Tasks_Triggers_IAsyncOnPreCullHandler_OnPreCullAsync;
	VirtualInvokeData _70_Cysharp_Threading_Tasks_Triggers_IAsyncOnPreRenderHandler_OnPreRenderAsync;
	VirtualInvokeData _71_Cysharp_Threading_Tasks_Triggers_IAsyncOnRectTransformDimensionsChangeHandler_OnRectTransformDimensionsChangeAsync;
	VirtualInvokeData _72_Cysharp_Threading_Tasks_Triggers_IAsyncOnRectTransformRemovedHandler_OnRectTransformRemovedAsync;
	VirtualInvokeData _73_Cysharp_Threading_Tasks_Triggers_IAsyncOnRenderImageHandler_OnRenderImageAsync;
	VirtualInvokeData _74_Cysharp_Threading_Tasks_Triggers_IAsyncOnRenderObjectHandler_OnRenderObjectAsync;
	VirtualInvokeData _75_Cysharp_Threading_Tasks_Triggers_IAsyncOnServerInitializedHandler_OnServerInitializedAsync;
	VirtualInvokeData _76_Cysharp_Threading_Tasks_Triggers_IAsyncOnTransformChildrenChangedHandler_OnTransformChildrenChangedAsync;
	VirtualInvokeData _77_Cysharp_Threading_Tasks_Triggers_IAsyncOnTransformParentChangedHandler_OnTransformParentChangedAsync;
	VirtualInvokeData _78_Cysharp_Threading_Tasks_Triggers_IAsyncOnTriggerEnterHandler_OnTriggerEnterAsync;
	VirtualInvokeData _79_Cysharp_Threading_Tasks_Triggers_IAsyncOnTriggerEnter2DHandler_OnTriggerEnter2DAsync;
	VirtualInvokeData _80_Cysharp_Threading_Tasks_Triggers_IAsyncOnTriggerExitHandler_OnTriggerExitAsync;
	VirtualInvokeData _81_Cysharp_Threading_Tasks_Triggers_IAsyncOnTriggerExit2DHandler_OnTriggerExit2DAsync;
	VirtualInvokeData _82_Cysharp_Threading_Tasks_Triggers_IAsyncOnTriggerStayHandler_OnTriggerStayAsync;
	VirtualInvokeData _83_Cysharp_Threading_Tasks_Triggers_IAsyncOnTriggerStay2DHandler_OnTriggerStay2DAsync;
	VirtualInvokeData _84_Cysharp_Threading_Tasks_Triggers_IAsyncOnValidateHandler_OnValidateAsync;
	VirtualInvokeData _85_Cysharp_Threading_Tasks_Triggers_IAsyncOnWillRenderObjectHandler_OnWillRenderObjectAsync;
	VirtualInvokeData _86_Cysharp_Threading_Tasks_Triggers_IAsyncResetHandler_ResetAsync;
	VirtualInvokeData _87_Cysharp_Threading_Tasks_Triggers_IAsyncUpdateHandler_UpdateAsync;
	VirtualInvokeData _88_Cysharp_Threading_Tasks_Triggers_IAsyncOnBeginDragHandler_OnBeginDragAsync;
	VirtualInvokeData _89_Cysharp_Threading_Tasks_Triggers_IAsyncOnCancelHandler_OnCancelAsync;
	VirtualInvokeData _90_Cysharp_Threading_Tasks_Triggers_IAsyncOnDeselectHandler_OnDeselectAsync;
	VirtualInvokeData _91_Cysharp_Threading_Tasks_Triggers_IAsyncOnDragHandler_OnDragAsync;
	VirtualInvokeData _92_Cysharp_Threading_Tasks_Triggers_IAsyncOnDropHandler_OnDropAsync;
	VirtualInvokeData _93_Cysharp_Threading_Tasks_Triggers_IAsyncOnEndDragHandler_OnEndDragAsync;
	VirtualInvokeData _94_Cysharp_Threading_Tasks_Triggers_IAsyncOnInitializePotentialDragHandler_OnInitializePotentialDragAsync;
	VirtualInvokeData _95_Cysharp_Threading_Tasks_Triggers_IAsyncOnMoveHandler_OnMoveAsync;
	VirtualInvokeData _96_Cysharp_Threading_Tasks_Triggers_IAsyncOnPointerClickHandler_OnPointerClickAsync;
	VirtualInvokeData _97_Cysharp_Threading_Tasks_Triggers_IAsyncOnPointerDownHandler_OnPointerDownAsync;
	VirtualInvokeData _98_Cysharp_Threading_Tasks_Triggers_IAsyncOnPointerEnterHandler_OnPointerEnterAsync;
	VirtualInvokeData _99_Cysharp_Threading_Tasks_Triggers_IAsyncOnPointerExitHandler_OnPointerExitAsync;
	VirtualInvokeData _100_Cysharp_Threading_Tasks_Triggers_IAsyncOnPointerUpHandler_OnPointerUpAsync;
	VirtualInvokeData _101_Cysharp_Threading_Tasks_Triggers_IAsyncOnScrollHandler_OnScrollAsync;
	VirtualInvokeData _102_Cysharp_Threading_Tasks_Triggers_IAsyncOnSelectHandler_OnSelectAsync;
	VirtualInvokeData _103_Cysharp_Threading_Tasks_Triggers_IAsyncOnSubmitHandler_OnSubmitAsync;
	VirtualInvokeData _104_Cysharp_Threading_Tasks_Triggers_IAsyncOnUpdateSelectedHandler_OnUpdateSelectedAsync;
} Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__VTable;

typedef struct Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__c {
	Il2CppClass_1 _1;
	struct Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__StaticFields* static_fields;
	Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__RGCTXs* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__VTable vtable;
} Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__c;

typedef struct Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__o {
	Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__c *klass;
	void *monitor;
	Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__Fields fields;
} Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__o;

typedef struct Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__StaticFields {
	struct System_Action_object__o* cancellationCallback;
} Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__StaticFields;

typedef struct MethodInfo_21C8770 {
	Il2CppMethodPointer methodPointer;
	Il2CppMethodPointer virtualMethodPointer;
	InvokerMethod invoker_method;
	const char* name;
	Cysharp_Threading_Tasks_Triggers_AsyncTriggerHandler_T__c *klass;
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
} MethodInfo_21C8770;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__Fields {
	Il2CppObject* result;
	Il2CppObject* error;
	int16_t version;
	bool hasUnhandledError;
	int32_t completedCount;
	struct System_Action_object__o* continuation;
	Il2CppObject* continuationState;
} Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__Fields;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__VTable;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__VTable vtable;
} Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__c;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__o {
	Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__Fields fields;
} Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_object__o;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_TResult__Fields {
	Il2CppObject* result;
	Il2CppObject* error;
	int16_t version;
	bool hasUnhandledError;
	int32_t completedCount;
	struct System_Action_object__o* continuation;
	Il2CppObject* continuationState;
} Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_TResult__Fields;
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
typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_TResult__o {
	Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_TResult__Fields fields;
} Cysharp_Threading_Tasks_UniTaskCompletionSourceCore_TResult__o;

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

typedef struct MethodInfo_110E210_RGCTXs {
	Il2CppClass* _0_T;
	Il2CppClass* _1_Cysharp_Threading_Tasks_UniTask_T_;
	MethodInfo* _2_Cysharp_Threading_Tasks_UniTask_T___ctor;
} MethodInfo_110E210_RGCTXs;

typedef struct MethodInfo_110E210 {
	Il2CppMethodPointer methodPointer;
	Il2CppMethodPointer virtualMethodPointer;
	InvokerMethod invoker_method;
	const char* name;
	Cysharp_Threading_Tasks_UniTask_c *klass;
	const Il2CppType *return_type;
	const Il2CppType** parameters;
	const MethodInfo_110E210_RGCTXs* rgctx_data;
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
} MethodInfo_110E210;

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

typedef struct Cysharp_Threading_Tasks_UniTask_TResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	Il2CppObject* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_TResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_TResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_TResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_TResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_TResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_TResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_TResponse__o {
	Cysharp_Threading_Tasks_UniTask_TResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_TResponse__o;

typedef struct CDGPJELFAMK_Fields {
	struct KCFACGNDKOI_o* FEHDBEMDJLH;
} CDGPJELFAMK_Fields;

typedef struct CDGPJELFAMK_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_ONIFJDGBNFE;
	VirtualInvokeData _5_KGFOAKGJBOL;
	VirtualInvokeData _6_unknown;
	VirtualInvokeData _7_LKHAOCKIOPL;
	VirtualInvokeData _8_PIJBCEBGIOH;
	VirtualInvokeData _9_unknown;
	VirtualInvokeData _10_BPCKJFKOKOM;
	VirtualInvokeData _11_NDHHPKBFJBA;
	VirtualInvokeData _12_DAOEJIDKBPB;
	VirtualInvokeData _13_unknown;
	VirtualInvokeData _14_unknown;
	VirtualInvokeData _15_EIJFILJLCCN;
	VirtualInvokeData _16_unknown;
	VirtualInvokeData _17_unknown;
	VirtualInvokeData _18_unknown;
	VirtualInvokeData _19_unknown;
	VirtualInvokeData _20_AKFPCAOAKKF;
	VirtualInvokeData _21_IDKDCHPAICO;
} CDGPJELFAMK_VTable;

typedef struct CDGPJELFAMK_c {
	Il2CppClass_1 _1;
	struct CDGPJELFAMK_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	CDGPJELFAMK_VTable vtable;
} CDGPJELFAMK_c;

typedef struct CDGPJELFAMK_o {
	CDGPJELFAMK_c *klass;
	void *monitor;
	CDGPJELFAMK_Fields fields;
} CDGPJELFAMK_o;

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

typedef struct BJAFDMJIDMJ_Fields {
	struct System_String_o* _JDLNGBAIDOD_k__BackingField;
	struct System_String_o* _BEDACCGOBCH_k__BackingField;
	bool _LBHKAHENJMJ_k__BackingField;
	struct System_Byte_array* _KJFLKOOKDHN_k__BackingField;
	struct Google_Protobuf_IMessage_o* _OCNDCNNHFPM_k__BackingField;
} BJAFDMJIDMJ_Fields;
typedef struct BJAFDMJIDMJ_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} BJAFDMJIDMJ_VTable;
typedef struct BJAFDMJIDMJ_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	BJAFDMJIDMJ_VTable vtable;
} BJAFDMJIDMJ_c;
typedef struct BJAFDMJIDMJ_o {
	BJAFDMJIDMJ_c *klass;
	void *monitor;
	BJAFDMJIDMJ_Fields fields;
} BJAFDMJIDMJ_o;

typedef struct Neon_Model_UserData_DatabaseMember_T__Fields {
	struct PEAEHFGGOJH_T__o* _subject;
	bool _isDirty;
	bool _IsDisposed_k__BackingField;
} Neon_Model_UserData_DatabaseMember_T__Fields;
typedef struct Neon_Model_UserData_DatabaseMember_T__RGCTXs {
	Il2CppClass* _0_Neon_Model_UserData_DatabaseMember_T_;
	Il2CppClass* _1_PEAEHFGGOJH_T_;
	MethodInfo* _2_Neon_Model_UserData_DatabaseMember_T__get_Current;
	Il2CppClass* _3_T;
	MethodInfo* _4_PEAEHFGGOJH_T__MNGCCHGELDF;
	MethodInfo* _5_Neon_Model_UserData_DatabaseMember_T__set_IsDisposed;
	MethodInfo* _6_PEAEHFGGOJH_T__Dispose;
	Il2CppClass* _7_System_IObserver_T_;
	MethodInfo* _8_Neon_Model_UserData_DatabaseMember_T__Subscribe;
	MethodInfo* _9_Neon_Model_UserData_DatabaseMember_T__get_IsDisposed;
	MethodInfo* _10_System_IObserver_T__OnCompleted;
	MethodInfo* _11_System_IObserver_T__OnNext;
	MethodInfo* _12_PEAEHFGGOJH_T___ctor;
	MethodInfo* _13_PEAEHFGGOJH_T__Subscribe;
} Neon_Model_UserData_DatabaseMember_T__RGCTXs;
typedef struct Neon_Model_UserData_DatabaseMember_T__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Notify;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_get_IsDisposed;
	VirtualInvokeData _7_Subscribe;
	VirtualInvokeData _8_Subscribe;
	VirtualInvokeData _9_unknown;
	VirtualInvokeData _10_Dispose;
} Neon_Model_UserData_DatabaseMember_T__VTable;
typedef struct Neon_Model_UserData_DatabaseMember_T__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Neon_Model_UserData_DatabaseMember_T__RGCTXs* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_UserData_DatabaseMember_T__VTable vtable;
} Neon_Model_UserData_DatabaseMember_T__c;
typedef struct Neon_Model_UserData_DatabaseMember_T__o {
	Neon_Model_UserData_DatabaseMember_T__c *klass;
	void *monitor;
	Neon_Model_UserData_DatabaseMember_T__Fields fields;
} Neon_Model_UserData_DatabaseMember_T__o;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSource_string__Fields {
	struct System_Threading_CancellationToken_o cancellationToken;
	struct System_String_o* result;
	struct Cysharp_Threading_Tasks_ExceptionHolder_o* exception;
	Il2CppObject* gate;
	struct System_Action_object__o* singleContinuation;
	Il2CppObject* singleState;
	struct System_Collections_Generic_List_ValueTuple_Action_object___object___o* secondaryContinuationList;
	int32_t intStatus;
	bool handled;
} Cysharp_Threading_Tasks_UniTaskCompletionSource_string__Fields;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSource_string__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_System_Threading_Tasks_Sources_IValueTaskSource_T__GetStatus;
	VirtualInvokeData _4_System_Threading_Tasks_Sources_IValueTaskSource_GetStatus;
	VirtualInvokeData _5_System_Threading_Tasks_Sources_IValueTaskSource_T__OnCompleted;
	VirtualInvokeData _6_System_Threading_Tasks_Sources_IValueTaskSource_OnCompleted;
	VirtualInvokeData _7_unknown;
	VirtualInvokeData _8_unknown;
	VirtualInvokeData _9_unknown;
	VirtualInvokeData _10_GetStatus;
	VirtualInvokeData _11_OnCompleted;
	VirtualInvokeData _12_Cysharp_Threading_Tasks_IUniTaskSource_GetResult;
	VirtualInvokeData _13_UnsafeGetStatus;
	VirtualInvokeData _14_unknown;
	VirtualInvokeData _15_unknown;
	VirtualInvokeData _16_unknown;
	VirtualInvokeData _17_unknown;
	VirtualInvokeData _18_unknown;
	VirtualInvokeData _19_unknown;
	VirtualInvokeData _20_unknown;
	VirtualInvokeData _21_unknown;
	VirtualInvokeData _22_GetResult;
	VirtualInvokeData _23_TrySetResult;
	VirtualInvokeData _24_TrySetException;
	VirtualInvokeData _25_TrySetCanceled;
} Cysharp_Threading_Tasks_UniTaskCompletionSource_string__VTable;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSource_string__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTaskCompletionSource_string__VTable vtable;
} Cysharp_Threading_Tasks_UniTaskCompletionSource_string__c;

typedef struct Cysharp_Threading_Tasks_UniTaskCompletionSource_string__o {
	Cysharp_Threading_Tasks_UniTaskCompletionSource_string__c *klass;
	void *monitor;
	Cysharp_Threading_Tasks_UniTaskCompletionSource_string__Fields fields;
} Cysharp_Threading_Tasks_UniTaskCompletionSource_string__o;

typedef struct MethodInfo_76FC90 {
	Il2CppMethodPointer methodPointer;
	Il2CppMethodPointer virtualMethodPointer;
	InvokerMethod invoker_method;
	const char* name;
	Neon_Model_UserData_DatabaseMember_T__c *klass;
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
} MethodInfo_76FC90;

typedef struct System_DateTime_Fields {
	uint64_t _dateData;
} System_DateTime_Fields;

typedef struct System_DateTime_o {
	System_DateTime_Fields fields;
} System_DateTime_o;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureAreaObjectResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_AdventureAreaObjectResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_AdventureAreaObjectResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureAreaObjectResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_AdventureAreaObjectResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureAreaObjectResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_AdventureAreaObjectResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_AdventureAreaObjectResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureAreaObjectResponse__o {
	Cysharp_Threading_Tasks_UniTask_AdventureAreaObjectResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_AdventureAreaObjectResponse__o;

typedef struct Neon_Model_Api_Rpc_AdventureAreaObjectRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t areaId_;
} Neon_Model_Api_Rpc_AdventureAreaObjectRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AdventureAreaObjectRequest_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_MergeFrom;
	VirtualInvokeData _5_MergeFrom;
	VirtualInvokeData _6_WriteTo;
	VirtualInvokeData _7_CalculateSize;
	VirtualInvokeData _8_pb__Google_Protobuf_IMessage_get_Descriptor;
	VirtualInvokeData _9_Equals;
	VirtualInvokeData _10_Clone;
	VirtualInvokeData _11_pb__Google_Protobuf_IBufferMessage_InternalMergeFrom;
	VirtualInvokeData _12_pb__Google_Protobuf_IBufferMessage_InternalWriteTo;
} Neon_Model_Api_Rpc_AdventureAreaObjectRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AdventureAreaObjectRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AdventureAreaObjectRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AdventureAreaObjectRequest_VTable vtable;
} Neon_Model_Api_Rpc_AdventureAreaObjectRequest_c;

typedef struct Neon_Model_Api_Rpc_AdventureAreaObjectRequest_o {
	Neon_Model_Api_Rpc_AdventureAreaObjectRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AdventureAreaObjectRequest_Fields fields;
} Neon_Model_Api_Rpc_AdventureAreaObjectRequest_o;

typedef struct Cysharp_Threading_Tasks_UniTask_TipReleaseResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_TipReleaseResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_TipReleaseResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_TipReleaseResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_TipReleaseResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_TipReleaseResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_TipReleaseResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_TipReleaseResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_TipReleaseResponse__o {
	Cysharp_Threading_Tasks_UniTask_TipReleaseResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_TipReleaseResponse__o;

typedef struct Neon_Model_Api_Rpc_TipReleaseRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* tipIds_;
} Neon_Model_Api_Rpc_TipReleaseRequest_Fields;

typedef struct Neon_Model_Api_Rpc_TipReleaseRequest_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_MergeFrom;
	VirtualInvokeData _5_MergeFrom;
	VirtualInvokeData _6_WriteTo;
	VirtualInvokeData _7_CalculateSize;
	VirtualInvokeData _8_pb__Google_Protobuf_IMessage_get_Descriptor;
	VirtualInvokeData _9_Equals;
	VirtualInvokeData _10_Clone;
	VirtualInvokeData _11_pb__Google_Protobuf_IBufferMessage_InternalMergeFrom;
	VirtualInvokeData _12_pb__Google_Protobuf_IBufferMessage_InternalWriteTo;
} Neon_Model_Api_Rpc_TipReleaseRequest_VTable;

typedef struct Neon_Model_Api_Rpc_TipReleaseRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_TipReleaseRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_TipReleaseRequest_VTable vtable;
} Neon_Model_Api_Rpc_TipReleaseRequest_c;

typedef struct Neon_Model_Api_Rpc_TipReleaseRequest_o {
	Neon_Model_Api_Rpc_TipReleaseRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_TipReleaseRequest_Fields fields;
} Neon_Model_Api_Rpc_TipReleaseRequest_o;

typedef struct Neon_Model_Api_Rpc_AdventureMoveToAreaRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t areaId_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
	bool respawnAtHospital_;
} Neon_Model_Api_Rpc_AdventureMoveToAreaRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AdventureMoveToAreaRequest_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_MergeFrom;
	VirtualInvokeData _5_MergeFrom;
	VirtualInvokeData _6_WriteTo;
	VirtualInvokeData _7_CalculateSize;
	VirtualInvokeData _8_pb__Google_Protobuf_IMessage_get_Descriptor;
	VirtualInvokeData _9_Equals;
	VirtualInvokeData _10_Clone;
	VirtualInvokeData _11_pb__Google_Protobuf_IBufferMessage_InternalMergeFrom;
	VirtualInvokeData _12_pb__Google_Protobuf_IBufferMessage_InternalWriteTo;
} Neon_Model_Api_Rpc_AdventureMoveToAreaRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AdventureMoveToAreaRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AdventureMoveToAreaRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AdventureMoveToAreaRequest_VTable vtable;
} Neon_Model_Api_Rpc_AdventureMoveToAreaRequest_c;

typedef struct Neon_Model_Api_Rpc_AdventureMoveToAreaRequest_o {
	Neon_Model_Api_Rpc_AdventureMoveToAreaRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AdventureMoveToAreaRequest_Fields fields;
} Neon_Model_Api_Rpc_AdventureMoveToAreaRequest_o;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureMoveToAreaResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_AdventureMoveToAreaResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_AdventureMoveToAreaResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureMoveToAreaResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_AdventureMoveToAreaResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureMoveToAreaResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_AdventureMoveToAreaResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_AdventureMoveToAreaResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureMoveToAreaResponse__o {
	Cysharp_Threading_Tasks_UniTask_AdventureMoveToAreaResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_AdventureMoveToAreaResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleStartResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_BattleStartResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_BattleStartResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleStartResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_BattleStartResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleStartResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_BattleStartResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_BattleStartResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleStartResponse__o {
	Cysharp_Threading_Tasks_UniTask_BattleStartResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_BattleStartResponse__o;

typedef struct Neon_Model_Api_Rpc_BattleStartRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* battleEntryIds_;
	struct Google_Protobuf_Collections_RepeatedField_int__o* lineCharacterIds_;
	struct Google_Protobuf_Collections_RepeatedField_BattleTrigger__o* battleTriggers_;
	int32_t advantageType_;
	bool isAttackHit_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
	struct Neon_Model_Api_Model_BloodStainLocation_o* bloodStainLocation_;
} Neon_Model_Api_Rpc_BattleStartRequest_Fields;

typedef struct Neon_Model_Api_Rpc_BattleStartRequest_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_MergeFrom;
	VirtualInvokeData _5_MergeFrom;
	VirtualInvokeData _6_WriteTo;
	VirtualInvokeData _7_CalculateSize;
	VirtualInvokeData _8_pb__Google_Protobuf_IMessage_get_Descriptor;
	VirtualInvokeData _9_Equals;
	VirtualInvokeData _10_Clone;
	VirtualInvokeData _11_pb__Google_Protobuf_IBufferMessage_InternalMergeFrom;
	VirtualInvokeData _12_pb__Google_Protobuf_IBufferMessage_InternalWriteTo;
} Neon_Model_Api_Rpc_BattleStartRequest_VTable;

typedef struct Neon_Model_Api_Rpc_BattleStartRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_BattleStartRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_BattleStartRequest_VTable vtable;
} Neon_Model_Api_Rpc_BattleStartRequest_c;

typedef struct Neon_Model_Api_Rpc_BattleStartRequest_o {
	Neon_Model_Api_Rpc_BattleStartRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_BattleStartRequest_Fields fields;
} Neon_Model_Api_Rpc_BattleStartRequest_o;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleFinishResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_BattleFinishResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_BattleFinishResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleFinishResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_BattleFinishResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleFinishResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_BattleFinishResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_BattleFinishResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleFinishResponse__o {
	Cysharp_Threading_Tasks_UniTask_BattleFinishResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_BattleFinishResponse__o;

typedef struct Neon_Model_Api_Rpc_BattleFinishRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t battleResult_;
	struct Google_Protobuf_Collections_RepeatedField_CharacterUpdate__o* characterUpdates_;
	struct Google_Protobuf_Collections_RepeatedField_BattleTaskTopic__o* battleTaskTopics_;
	struct Google_Protobuf_Collections_RepeatedField_int__o* encounteredEnemyIds_;
	int32_t battleTimeSecond_;
	struct Neon_Model_Api_Model_BattleTaskConditionResult_o* taskConditionResult_;
} Neon_Model_Api_Rpc_BattleFinishRequest_Fields;

typedef struct Neon_Model_Api_Rpc_BattleFinishRequest_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_MergeFrom;
	VirtualInvokeData _5_MergeFrom;
	VirtualInvokeData _6_WriteTo;
	VirtualInvokeData _7_CalculateSize;
	VirtualInvokeData _8_pb__Google_Protobuf_IMessage_get_Descriptor;
	VirtualInvokeData _9_Equals;
	VirtualInvokeData _10_Clone;
	VirtualInvokeData _11_pb__Google_Protobuf_IBufferMessage_InternalMergeFrom;
	VirtualInvokeData _12_pb__Google_Protobuf_IBufferMessage_InternalWriteTo;
} Neon_Model_Api_Rpc_BattleFinishRequest_VTable;

typedef struct Neon_Model_Api_Rpc_BattleFinishRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_BattleFinishRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_BattleFinishRequest_VTable vtable;
} Neon_Model_Api_Rpc_BattleFinishRequest_c;

typedef struct Neon_Model_Api_Rpc_BattleFinishRequest_o {
	Neon_Model_Api_Rpc_BattleFinishRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_BattleFinishRequest_Fields fields;
} Neon_Model_Api_Rpc_BattleFinishRequest_o;

typedef struct Cysharp_Threading_Tasks_UniTask_ChangedResourcesResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_ChangedResourcesResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_ChangedResourcesResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_ChangedResourcesResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_ChangedResourcesResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_ChangedResourcesResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_ChangedResourcesResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_ChangedResourcesResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_ChangedResourcesResponse__o {
	Cysharp_Threading_Tasks_UniTask_ChangedResourcesResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_ChangedResourcesResponse__o;

typedef struct Neon_Model_Api_Rpc_AdventureUpdateCharacterStatusRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_CharacterUpdate__o* characterUpdates_;
} Neon_Model_Api_Rpc_AdventureUpdateCharacterStatusRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AdventureUpdateCharacterStatusRequest_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_MergeFrom;
	VirtualInvokeData _5_MergeFrom;
	VirtualInvokeData _6_WriteTo;
	VirtualInvokeData _7_CalculateSize;
	VirtualInvokeData _8_pb__Google_Protobuf_IMessage_get_Descriptor;
	VirtualInvokeData _9_Equals;
	VirtualInvokeData _10_Clone;
	VirtualInvokeData _11_pb__Google_Protobuf_IBufferMessage_InternalMergeFrom;
	VirtualInvokeData _12_pb__Google_Protobuf_IBufferMessage_InternalWriteTo;
} Neon_Model_Api_Rpc_AdventureUpdateCharacterStatusRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AdventureUpdateCharacterStatusRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AdventureUpdateCharacterStatusRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AdventureUpdateCharacterStatusRequest_VTable vtable;
} Neon_Model_Api_Rpc_AdventureUpdateCharacterStatusRequest_c;

typedef struct Neon_Model_Api_Rpc_AdventureUpdateCharacterStatusRequest_o {
	Neon_Model_Api_Rpc_AdventureUpdateCharacterStatusRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AdventureUpdateCharacterStatusRequest_Fields fields;
} Neon_Model_Api_Rpc_AdventureUpdateCharacterStatusRequest_o;

typedef struct Neon_Model_Api_Rpc_FormationUpdateRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t number_;
	struct Neon_Model_Api_Model_FormationMembers_o* members_;
	struct Neon_Model_Api_Model_FormationCards_o* cards_;
} Neon_Model_Api_Rpc_FormationUpdateRequest_Fields;

typedef struct Neon_Model_Api_Rpc_FormationUpdateRequest_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_MergeFrom;
	VirtualInvokeData _5_MergeFrom;
	VirtualInvokeData _6_WriteTo;
	VirtualInvokeData _7_CalculateSize;
	VirtualInvokeData _8_pb__Google_Protobuf_IMessage_get_Descriptor;
	VirtualInvokeData _9_Equals;
	VirtualInvokeData _10_Clone;
	VirtualInvokeData _11_pb__Google_Protobuf_IBufferMessage_InternalMergeFrom;
	VirtualInvokeData _12_pb__Google_Protobuf_IBufferMessage_InternalWriteTo;
} Neon_Model_Api_Rpc_FormationUpdateRequest_VTable;

typedef struct Neon_Model_Api_Rpc_FormationUpdateRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_FormationUpdateRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_FormationUpdateRequest_VTable vtable;
} Neon_Model_Api_Rpc_FormationUpdateRequest_c;

typedef struct Neon_Model_Api_Rpc_FormationUpdateRequest_o {
	Neon_Model_Api_Rpc_FormationUpdateRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_FormationUpdateRequest_Fields fields;
} Neon_Model_Api_Rpc_FormationUpdateRequest_o;

typedef struct Neon_Model_Api_Rpc_CharacterCostumeUpdateRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t characterCostumeId_;
} Neon_Model_Api_Rpc_CharacterCostumeUpdateRequest_Fields;

typedef struct Neon_Model_Api_Rpc_CharacterCostumeUpdateRequest_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_MergeFrom;
	VirtualInvokeData _5_MergeFrom;
	VirtualInvokeData _6_WriteTo;
	VirtualInvokeData _7_CalculateSize;
	VirtualInvokeData _8_pb__Google_Protobuf_IMessage_get_Descriptor;
	VirtualInvokeData _9_Equals;
	VirtualInvokeData _10_Clone;
	VirtualInvokeData _11_pb__Google_Protobuf_IBufferMessage_InternalMergeFrom;
	VirtualInvokeData _12_pb__Google_Protobuf_IBufferMessage_InternalWriteTo;
} Neon_Model_Api_Rpc_CharacterCostumeUpdateRequest_VTable;

typedef struct Neon_Model_Api_Rpc_CharacterCostumeUpdateRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_CharacterCostumeUpdateRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_CharacterCostumeUpdateRequest_VTable vtable;
} Neon_Model_Api_Rpc_CharacterCostumeUpdateRequest_c;

typedef struct Neon_Model_Api_Rpc_CharacterCostumeUpdateRequest_o {
	Neon_Model_Api_Rpc_CharacterCostumeUpdateRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_CharacterCostumeUpdateRequest_Fields fields;
} Neon_Model_Api_Rpc_CharacterCostumeUpdateRequest_o;

typedef struct System_Nullable_int__Fields {
	bool hasValue;
	int32_t value;
} System_Nullable_int__Fields;

typedef struct System_Nullable_int__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} System_Nullable_int__VTable;

typedef struct System_Nullable_int__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Nullable_int__VTable vtable;
} System_Nullable_int__c;

typedef struct System_Nullable_int__o {
	System_Nullable_int__Fields fields;
} System_Nullable_int__o;

typedef struct Neon_Model_Api_Rpc_AdventureReadSequenceRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* sequenceRequestIds_;
	struct Google_Protobuf_Collections_RepeatedField_NineSequenceRequest__o* nineSequences_;
	struct System_Nullable_int__o miniGameId_;
	int32_t areaType_;
	int32_t areaKeyId_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
} Neon_Model_Api_Rpc_AdventureReadSequenceRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AdventureReadSequenceRequest_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_MergeFrom;
	VirtualInvokeData _5_MergeFrom;
	VirtualInvokeData _6_WriteTo;
	VirtualInvokeData _7_CalculateSize;
	VirtualInvokeData _8_pb__Google_Protobuf_IMessage_get_Descriptor;
	VirtualInvokeData _9_Equals;
	VirtualInvokeData _10_Clone;
	VirtualInvokeData _11_pb__Google_Protobuf_IBufferMessage_InternalMergeFrom;
	VirtualInvokeData _12_pb__Google_Protobuf_IBufferMessage_InternalWriteTo;
} Neon_Model_Api_Rpc_AdventureReadSequenceRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AdventureReadSequenceRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AdventureReadSequenceRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AdventureReadSequenceRequest_VTable vtable;
} Neon_Model_Api_Rpc_AdventureReadSequenceRequest_c;

typedef struct Neon_Model_Api_Rpc_AdventureReadSequenceRequest_o {
	Neon_Model_Api_Rpc_AdventureReadSequenceRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AdventureReadSequenceRequest_Fields fields;
} Neon_Model_Api_Rpc_AdventureReadSequenceRequest_o;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureReadSequenceResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_AdventureReadSequenceResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_AdventureReadSequenceResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureReadSequenceResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_AdventureReadSequenceResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureReadSequenceResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_AdventureReadSequenceResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_AdventureReadSequenceResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureReadSequenceResponse__o {
	Cysharp_Threading_Tasks_UniTask_AdventureReadSequenceResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_AdventureReadSequenceResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureAcquireAreaItemResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_AdventureAcquireAreaItemResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_AdventureAcquireAreaItemResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureAcquireAreaItemResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_AdventureAcquireAreaItemResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureAcquireAreaItemResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_AdventureAcquireAreaItemResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_AdventureAcquireAreaItemResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureAcquireAreaItemResponse__o {
	Cysharp_Threading_Tasks_UniTask_AdventureAcquireAreaItemResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_AdventureAcquireAreaItemResponse__o;

typedef struct Neon_Model_Api_Rpc_AdventureAcquireAreaItemRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t areaItemId_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
} Neon_Model_Api_Rpc_AdventureAcquireAreaItemRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AdventureAcquireAreaItemRequest_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_MergeFrom;
	VirtualInvokeData _5_MergeFrom;
	VirtualInvokeData _6_WriteTo;
	VirtualInvokeData _7_CalculateSize;
	VirtualInvokeData _8_pb__Google_Protobuf_IMessage_get_Descriptor;
	VirtualInvokeData _9_Equals;
	VirtualInvokeData _10_Clone;
	VirtualInvokeData _11_pb__Google_Protobuf_IBufferMessage_InternalMergeFrom;
	VirtualInvokeData _12_pb__Google_Protobuf_IBufferMessage_InternalWriteTo;
} Neon_Model_Api_Rpc_AdventureAcquireAreaItemRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AdventureAcquireAreaItemRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AdventureAcquireAreaItemRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AdventureAcquireAreaItemRequest_VTable vtable;
} Neon_Model_Api_Rpc_AdventureAcquireAreaItemRequest_c;

typedef struct Neon_Model_Api_Rpc_AdventureAcquireAreaItemRequest_o {
	Neon_Model_Api_Rpc_AdventureAcquireAreaItemRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AdventureAcquireAreaItemRequest_Fields fields;
} Neon_Model_Api_Rpc_AdventureAcquireAreaItemRequest_o;

typedef struct System_Nullable_long__Fields {
	bool hasValue;
	int64_t value;
} System_Nullable_long__Fields;

typedef struct System_Nullable_long__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} System_Nullable_long__VTable;

typedef struct System_Nullable_long__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Nullable_long__VTable vtable;
} System_Nullable_long__c;

typedef struct System_Nullable_long__o {
	System_Nullable_long__Fields fields;
} System_Nullable_long__o;

typedef struct Neon_Model_Api_Rpc_XbFormationRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t xbId_;
	struct System_Nullable_long__o enemyUserId_;
	struct System_Nullable_int__o enemyCpuUserId_;
} Neon_Model_Api_Rpc_XbFormationRequest_Fields;

typedef struct Neon_Model_Api_Rpc_XbFormationRequest_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_MergeFrom;
	VirtualInvokeData _5_MergeFrom;
	VirtualInvokeData _6_WriteTo;
	VirtualInvokeData _7_CalculateSize;
	VirtualInvokeData _8_pb__Google_Protobuf_IMessage_get_Descriptor;
	VirtualInvokeData _9_Equals;
	VirtualInvokeData _10_Clone;
	VirtualInvokeData _11_pb__Google_Protobuf_IBufferMessage_InternalMergeFrom;
	VirtualInvokeData _12_pb__Google_Protobuf_IBufferMessage_InternalWriteTo;
} Neon_Model_Api_Rpc_XbFormationRequest_VTable;

typedef struct Neon_Model_Api_Rpc_XbFormationRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_XbFormationRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_XbFormationRequest_VTable vtable;
} Neon_Model_Api_Rpc_XbFormationRequest_c;

typedef struct Neon_Model_Api_Rpc_XbFormationRequest_o {
	Neon_Model_Api_Rpc_XbFormationRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_XbFormationRequest_Fields fields;
} Neon_Model_Api_Rpc_XbFormationRequest_o;

typedef struct Cysharp_Threading_Tasks_UniTask_XbFormationResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_XbFormationResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_XbFormationResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_XbFormationResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_XbFormationResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_XbFormationResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_XbFormationResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_XbFormationResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_XbFormationResponse__o {
	Cysharp_Threading_Tasks_UniTask_XbFormationResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_XbFormationResponse__o;

typedef struct Neon_Model_Api_Rpc_XbStatusRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t xbId_;
} Neon_Model_Api_Rpc_XbStatusRequest_Fields;

typedef struct Neon_Model_Api_Rpc_XbStatusRequest_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_MergeFrom;
	VirtualInvokeData _5_MergeFrom;
	VirtualInvokeData _6_WriteTo;
	VirtualInvokeData _7_CalculateSize;
	VirtualInvokeData _8_pb__Google_Protobuf_IMessage_get_Descriptor;
	VirtualInvokeData _9_Equals;
	VirtualInvokeData _10_Clone;
	VirtualInvokeData _11_pb__Google_Protobuf_IBufferMessage_InternalMergeFrom;
	VirtualInvokeData _12_pb__Google_Protobuf_IBufferMessage_InternalWriteTo;
} Neon_Model_Api_Rpc_XbStatusRequest_VTable;

typedef struct Neon_Model_Api_Rpc_XbStatusRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_XbStatusRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_XbStatusRequest_VTable vtable;
} Neon_Model_Api_Rpc_XbStatusRequest_c;

typedef struct Neon_Model_Api_Rpc_XbStatusRequest_o {
	Neon_Model_Api_Rpc_XbStatusRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_XbStatusRequest_Fields fields;
} Neon_Model_Api_Rpc_XbStatusRequest_o;

typedef struct Cysharp_Threading_Tasks_UniTask_XbStatusResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_XbStatusResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_XbStatusResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_XbStatusResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_XbStatusResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_XbStatusResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_XbStatusResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_XbStatusResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_XbStatusResponse__o {
	Cysharp_Threading_Tasks_UniTask_XbStatusResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_XbStatusResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_XbRetireResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_XbRetireResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_XbRetireResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_XbRetireResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_XbRetireResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_XbRetireResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_XbRetireResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_XbRetireResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_XbRetireResponse__o {
	Cysharp_Threading_Tasks_UniTask_XbRetireResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_XbRetireResponse__o;

#endif