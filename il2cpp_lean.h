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

typedef struct Cysharp_Threading_Tasks_UniTask_XbUpdateTensionResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_XbUpdateTensionResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_XbUpdateTensionResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_XbUpdateTensionResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_XbUpdateTensionResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_XbUpdateTensionResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_XbUpdateTensionResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_XbUpdateTensionResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_XbUpdateTensionResponse__o {
	Cysharp_Threading_Tasks_UniTask_XbUpdateTensionResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_XbUpdateTensionResponse__o;

typedef struct Neon_Model_Api_Rpc_XbUpdateTensionRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t xbId_;
	struct Google_Protobuf_Collections_RepeatedField_int__o* tensionFluctuationIds_;
} Neon_Model_Api_Rpc_XbUpdateTensionRequest_Fields;

typedef struct Neon_Model_Api_Rpc_XbUpdateTensionRequest_VTable {
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
} Neon_Model_Api_Rpc_XbUpdateTensionRequest_VTable;

typedef struct Neon_Model_Api_Rpc_XbUpdateTensionRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_XbUpdateTensionRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_XbUpdateTensionRequest_VTable vtable;
} Neon_Model_Api_Rpc_XbUpdateTensionRequest_c;

typedef struct Neon_Model_Api_Rpc_XbUpdateTensionRequest_o {
	Neon_Model_Api_Rpc_XbUpdateTensionRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_XbUpdateTensionRequest_Fields fields;
} Neon_Model_Api_Rpc_XbUpdateTensionRequest_o;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPlayResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_XbPlayResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_XbPlayResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPlayResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_XbPlayResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPlayResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_XbPlayResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_XbPlayResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPlayResponse__o {
	Cysharp_Threading_Tasks_UniTask_XbPlayResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_XbPlayResponse__o;

typedef struct Neon_Model_Api_Rpc_XbPlayRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t xbId_;
	int32_t zoneAreaIndex_;
	int32_t commandId_;
	struct System_Nullable_int__o magicOrbId_;
	bool isAtBatSkip_;
} Neon_Model_Api_Rpc_XbPlayRequest_Fields;

typedef struct Neon_Model_Api_Rpc_XbPlayRequest_VTable {
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
} Neon_Model_Api_Rpc_XbPlayRequest_VTable;

typedef struct Neon_Model_Api_Rpc_XbPlayRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_XbPlayRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_XbPlayRequest_VTable vtable;
} Neon_Model_Api_Rpc_XbPlayRequest_c;

typedef struct Neon_Model_Api_Rpc_XbPlayRequest_o {
	Neon_Model_Api_Rpc_XbPlayRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_XbPlayRequest_Fields fields;
} Neon_Model_Api_Rpc_XbPlayRequest_o;

typedef struct Cysharp_Threading_Tasks_UniTask_XbStartResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_XbStartResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_XbStartResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_XbStartResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_XbStartResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_XbStartResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_XbStartResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_XbStartResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_XbStartResponse__o {
	Cysharp_Threading_Tasks_UniTask_XbStartResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_XbStartResponse__o;

typedef struct Neon_Model_Api_Rpc_XbStartRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t xbId_;
	struct Google_Protobuf_Collections_RepeatedField_XbMemberRequest__o* playerMembers_;
	struct System_Nullable_long__o enemyUserId_;
	struct System_Nullable_int__o enemyCpuUserId_;
	struct System_Nullable_int__o actionSequenceId_;
} Neon_Model_Api_Rpc_XbStartRequest_Fields;

typedef struct Neon_Model_Api_Rpc_XbStartRequest_VTable {
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
} Neon_Model_Api_Rpc_XbStartRequest_VTable;

typedef struct Neon_Model_Api_Rpc_XbStartRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_XbStartRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_XbStartRequest_VTable vtable;
} Neon_Model_Api_Rpc_XbStartRequest_c;

typedef struct Neon_Model_Api_Rpc_XbStartRequest_o {
	Neon_Model_Api_Rpc_XbStartRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_XbStartRequest_Fields fields;
} Neon_Model_Api_Rpc_XbStartRequest_o;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureAccessWarpPointResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_AdventureAccessWarpPointResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_AdventureAccessWarpPointResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureAccessWarpPointResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_AdventureAccessWarpPointResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureAccessWarpPointResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_AdventureAccessWarpPointResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_AdventureAccessWarpPointResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureAccessWarpPointResponse__o {
	Cysharp_Threading_Tasks_UniTask_AdventureAccessWarpPointResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_AdventureAccessWarpPointResponse__o;

typedef struct Neon_Model_Api_Rpc_AdventureAccessWarpPointRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t warpPointId_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
} Neon_Model_Api_Rpc_AdventureAccessWarpPointRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AdventureAccessWarpPointRequest_VTable {
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
} Neon_Model_Api_Rpc_AdventureAccessWarpPointRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AdventureAccessWarpPointRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AdventureAccessWarpPointRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AdventureAccessWarpPointRequest_VTable vtable;
} Neon_Model_Api_Rpc_AdventureAccessWarpPointRequest_c;

typedef struct Neon_Model_Api_Rpc_AdventureAccessWarpPointRequest_o {
	Neon_Model_Api_Rpc_AdventureAccessWarpPointRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AdventureAccessWarpPointRequest_Fields fields;
} Neon_Model_Api_Rpc_AdventureAccessWarpPointRequest_o;

typedef struct Neon_Model_Api_Rpc_FractalViseAcquireAreaItemRequest_Fields {
        struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
        int32_t fractalViseAreaId_;
        int32_t entityId_;
        struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
} Neon_Model_Api_Rpc_FractalViseAcquireAreaItemRequest_Fields;

typedef struct Neon_Model_Api_Rpc_FractalViseAcquireAreaItemRequest_VTable {
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
} Neon_Model_Api_Rpc_FractalViseAcquireAreaItemRequest_VTable;

typedef struct Neon_Model_Api_Rpc_FractalViseAcquireAreaItemRequest_c {
        Il2CppClass_1 _1;
        struct Neon_Model_Api_Rpc_FractalViseAcquireAreaItemRequest_StaticFields* static_fields;
        Il2CppRGCTXData* rgctx_data;
        Il2CppClass_2 _2;
        Neon_Model_Api_Rpc_FractalViseAcquireAreaItemRequest_VTable vtable;
} Neon_Model_Api_Rpc_FractalViseAcquireAreaItemRequest_c;

typedef struct Neon_Model_Api_Rpc_FractalViseAcquireAreaItemRequest_o {
        Neon_Model_Api_Rpc_FractalViseAcquireAreaItemRequest_c *klass;
        void *monitor;
        Neon_Model_Api_Rpc_FractalViseAcquireAreaItemRequest_Fields fields;
} Neon_Model_Api_Rpc_FractalViseAcquireAreaItemRequest_o;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseAcquireAreaItemResponse__Fields {
        struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
        struct Neon_Model_Api_Rpc_FractalViseAcquireAreaItemResponse_o* result;
        int16_t token;
} Cysharp_Threading_Tasks_UniTask_FractalViseAcquireAreaItemResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseAcquireAreaItemResponse__VTable {
        VirtualInvokeData _0_Equals;
        VirtualInvokeData _1_Finalize;
        VirtualInvokeData _2_GetHashCode;
        VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_FractalViseAcquireAreaItemResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseAcquireAreaItemResponse__c {
        Il2CppClass_1 _1;
        void* static_fields;
        Il2CppRGCTXData* rgctx_data;
        Il2CppClass_2 _2;
        Cysharp_Threading_Tasks_UniTask_FractalViseAcquireAreaItemResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_FractalViseAcquireAreaItemResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseAcquireAreaItemResponse__o {
        Cysharp_Threading_Tasks_UniTask_FractalViseAcquireAreaItemResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_FractalViseAcquireAreaItemResponse__o;

typedef struct Neon_Model_Api_Rpc_CharacterLimitBreakRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t characterId_;
	int32_t limitBreakCount_;
} Neon_Model_Api_Rpc_CharacterLimitBreakRequest_Fields;

typedef struct Neon_Model_Api_Rpc_CharacterLimitBreakRequest_VTable {
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
} Neon_Model_Api_Rpc_CharacterLimitBreakRequest_VTable;

typedef struct Neon_Model_Api_Rpc_CharacterLimitBreakRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_CharacterLimitBreakRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_CharacterLimitBreakRequest_VTable vtable;
} Neon_Model_Api_Rpc_CharacterLimitBreakRequest_c;

typedef struct Neon_Model_Api_Rpc_CharacterLimitBreakRequest_o {
	Neon_Model_Api_Rpc_CharacterLimitBreakRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_CharacterLimitBreakRequest_Fields fields;
} Neon_Model_Api_Rpc_CharacterLimitBreakRequest_o;

typedef struct Neon_Model_Api_Rpc_XbPvpFormationUpdateRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_XbPvpMemberRequest__o* playerMembers_;
} Neon_Model_Api_Rpc_XbPvpFormationUpdateRequest_Fields;

typedef struct Neon_Model_Api_Rpc_XbPvpFormationUpdateRequest_VTable {
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
} Neon_Model_Api_Rpc_XbPvpFormationUpdateRequest_VTable;

typedef struct Neon_Model_Api_Rpc_XbPvpFormationUpdateRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_XbPvpFormationUpdateRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_XbPvpFormationUpdateRequest_VTable vtable;
} Neon_Model_Api_Rpc_XbPvpFormationUpdateRequest_c;

typedef struct Neon_Model_Api_Rpc_XbPvpFormationUpdateRequest_o {
	Neon_Model_Api_Rpc_XbPvpFormationUpdateRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_XbPvpFormationUpdateRequest_Fields fields;
} Neon_Model_Api_Rpc_XbPvpFormationUpdateRequest_o;

typedef struct Neon_Model_Api_Rpc_TrialBattleStartRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t trialCharacterEventId_;
	int32_t trialBattleId_;
} Neon_Model_Api_Rpc_TrialBattleStartRequest_Fields;

typedef struct Neon_Model_Api_Rpc_TrialBattleStartRequest_VTable {
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
} Neon_Model_Api_Rpc_TrialBattleStartRequest_VTable;

typedef struct Neon_Model_Api_Rpc_TrialBattleStartRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_TrialBattleStartRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_TrialBattleStartRequest_VTable vtable;
} Neon_Model_Api_Rpc_TrialBattleStartRequest_c;

typedef struct Neon_Model_Api_Rpc_TrialBattleStartRequest_o {
	Neon_Model_Api_Rpc_TrialBattleStartRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_TrialBattleStartRequest_Fields fields;
} Neon_Model_Api_Rpc_TrialBattleStartRequest_o;

typedef struct Neon_Model_Api_Rpc_EventFinishNodeRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t eventFloorNodeId_;
	struct Google_Protobuf_Collections_RepeatedField_int__o* clearedAchievementIds_;
	bool isConsumeItem_;
	struct Neon_Model_Api_Model_EventFloorNodeQuestResult_o* result_;
	int32_t questResult_;
} Neon_Model_Api_Rpc_EventFinishNodeRequest_Fields;

typedef struct Neon_Model_Api_Rpc_EventFinishNodeRequest_VTable {
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
} Neon_Model_Api_Rpc_EventFinishNodeRequest_VTable;

typedef struct Neon_Model_Api_Rpc_EventFinishNodeRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_EventFinishNodeRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_EventFinishNodeRequest_VTable vtable;
} Neon_Model_Api_Rpc_EventFinishNodeRequest_c;

typedef struct Neon_Model_Api_Rpc_EventFinishNodeRequest_o {
	Neon_Model_Api_Rpc_EventFinishNodeRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_EventFinishNodeRequest_Fields fields;
} Neon_Model_Api_Rpc_EventFinishNodeRequest_o;

typedef struct Neon_Model_Api_Rpc_AdventureFindGraffitiRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t graffitiArtId_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
} Neon_Model_Api_Rpc_AdventureFindGraffitiRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AdventureFindGraffitiRequest_VTable {
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
} Neon_Model_Api_Rpc_AdventureFindGraffitiRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AdventureFindGraffitiRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AdventureFindGraffitiRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AdventureFindGraffitiRequest_VTable vtable;
} Neon_Model_Api_Rpc_AdventureFindGraffitiRequest_c;

typedef struct Neon_Model_Api_Rpc_AdventureFindGraffitiRequest_o {
	Neon_Model_Api_Rpc_AdventureFindGraffitiRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AdventureFindGraffitiRequest_Fields fields;
} Neon_Model_Api_Rpc_AdventureFindGraffitiRequest_o;

typedef struct Neon_Model_Api_Rpc_FollowRemoveRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int64_t userId_;
} Neon_Model_Api_Rpc_FollowRemoveRequest_Fields;

typedef struct Neon_Model_Api_Rpc_FollowRemoveRequest_VTable {
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
} Neon_Model_Api_Rpc_FollowRemoveRequest_VTable;

typedef struct Neon_Model_Api_Rpc_FollowRemoveRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_FollowRemoveRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_FollowRemoveRequest_VTable vtable;
} Neon_Model_Api_Rpc_FollowRemoveRequest_c;

typedef struct Neon_Model_Api_Rpc_FollowRemoveRequest_o {
	Neon_Model_Api_Rpc_FollowRemoveRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_FollowRemoveRequest_Fields fields;
} Neon_Model_Api_Rpc_FollowRemoveRequest_o;

typedef struct Neon_Model_Api_Rpc_FractalViseStartRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t fractalViseId_;
} Neon_Model_Api_Rpc_FractalViseStartRequest_Fields;

typedef struct Neon_Model_Api_Rpc_FractalViseStartRequest_VTable {
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
} Neon_Model_Api_Rpc_FractalViseStartRequest_VTable;

typedef struct Neon_Model_Api_Rpc_FractalViseStartRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_FractalViseStartRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_FractalViseStartRequest_VTable vtable;
} Neon_Model_Api_Rpc_FractalViseStartRequest_c;

typedef struct Neon_Model_Api_Rpc_FractalViseStartRequest_o {
	Neon_Model_Api_Rpc_FractalViseStartRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_FractalViseStartRequest_Fields fields;
} Neon_Model_Api_Rpc_FractalViseStartRequest_o;

typedef struct Neon_Model_Api_Rpc_RefundApplicationRequestRefundRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	bool isSkipItunesGoogleplay_;
	Il2CppObject* refundDestination_;
	int32_t refundDestinationCase_;
} Neon_Model_Api_Rpc_RefundApplicationRequestRefundRequest_Fields;

typedef struct Neon_Model_Api_Rpc_RefundApplicationRequestRefundRequest_VTable {
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
} Neon_Model_Api_Rpc_RefundApplicationRequestRefundRequest_VTable;

typedef struct Neon_Model_Api_Rpc_RefundApplicationRequestRefundRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_RefundApplicationRequestRefundRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_RefundApplicationRequestRefundRequest_VTable vtable;
} Neon_Model_Api_Rpc_RefundApplicationRequestRefundRequest_c;

typedef struct Neon_Model_Api_Rpc_RefundApplicationRequestRefundRequest_o {
	Neon_Model_Api_Rpc_RefundApplicationRequestRefundRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_RefundApplicationRequestRefundRequest_Fields fields;
} Neon_Model_Api_Rpc_RefundApplicationRequestRefundRequest_o;

typedef struct Neon_Model_Api_Rpc_TipReleaseByBattleRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t battleResult_;
} Neon_Model_Api_Rpc_TipReleaseByBattleRequest_Fields;

typedef struct Neon_Model_Api_Rpc_TipReleaseByBattleRequest_VTable {
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
} Neon_Model_Api_Rpc_TipReleaseByBattleRequest_VTable;

typedef struct Neon_Model_Api_Rpc_TipReleaseByBattleRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_TipReleaseByBattleRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_TipReleaseByBattleRequest_VTable vtable;
} Neon_Model_Api_Rpc_TipReleaseByBattleRequest_c;

typedef struct Neon_Model_Api_Rpc_TipReleaseByBattleRequest_o {
	Neon_Model_Api_Rpc_TipReleaseByBattleRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_TipReleaseByBattleRequest_Fields fields;
} Neon_Model_Api_Rpc_TipReleaseByBattleRequest_o;

typedef struct Neon_Model_Api_Rpc_FollowSearchRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int64_t userId_;
} Neon_Model_Api_Rpc_FollowSearchRequest_Fields;

typedef struct Neon_Model_Api_Rpc_FollowSearchRequest_VTable {
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
} Neon_Model_Api_Rpc_FollowSearchRequest_VTable;

typedef struct Neon_Model_Api_Rpc_FollowSearchRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_FollowSearchRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_FollowSearchRequest_VTable vtable;
} Neon_Model_Api_Rpc_FollowSearchRequest_c;

typedef struct Neon_Model_Api_Rpc_FollowSearchRequest_o {
	Neon_Model_Api_Rpc_FollowSearchRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_FollowSearchRequest_Fields fields;
} Neon_Model_Api_Rpc_FollowSearchRequest_o;

typedef struct Neon_Model_Api_Rpc_ItemRequestPublishRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t deliveryRequestItemId_;
} Neon_Model_Api_Rpc_ItemRequestPublishRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ItemRequestPublishRequest_VTable {
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
} Neon_Model_Api_Rpc_ItemRequestPublishRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ItemRequestPublishRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ItemRequestPublishRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ItemRequestPublishRequest_VTable vtable;
} Neon_Model_Api_Rpc_ItemRequestPublishRequest_c;

typedef struct Neon_Model_Api_Rpc_ItemRequestPublishRequest_o {
	Neon_Model_Api_Rpc_ItemRequestPublishRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ItemRequestPublishRequest_Fields fields;
} Neon_Model_Api_Rpc_ItemRequestPublishRequest_o;

typedef struct Neon_Model_Api_Rpc_XbAddCommandUnlockItemRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t xbId_;
	int32_t magicOrbId_;
	int32_t quantity_;
} Neon_Model_Api_Rpc_XbAddCommandUnlockItemRequest_Fields;

typedef struct Neon_Model_Api_Rpc_XbAddCommandUnlockItemRequest_VTable {
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
} Neon_Model_Api_Rpc_XbAddCommandUnlockItemRequest_VTable;

typedef struct Neon_Model_Api_Rpc_XbAddCommandUnlockItemRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_XbAddCommandUnlockItemRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_XbAddCommandUnlockItemRequest_VTable vtable;
} Neon_Model_Api_Rpc_XbAddCommandUnlockItemRequest_c;

typedef struct Neon_Model_Api_Rpc_XbAddCommandUnlockItemRequest_o {
	Neon_Model_Api_Rpc_XbAddCommandUnlockItemRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_XbAddCommandUnlockItemRequest_Fields fields;
} Neon_Model_Api_Rpc_XbAddCommandUnlockItemRequest_o;

typedef struct Neon_Model_Api_Rpc_RefundApplicationUpdateEmailIdRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_String_o* emailId_;
} Neon_Model_Api_Rpc_RefundApplicationUpdateEmailIdRequest_Fields;

typedef struct Neon_Model_Api_Rpc_RefundApplicationUpdateEmailIdRequest_VTable {
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
} Neon_Model_Api_Rpc_RefundApplicationUpdateEmailIdRequest_VTable;

typedef struct Neon_Model_Api_Rpc_RefundApplicationUpdateEmailIdRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_RefundApplicationUpdateEmailIdRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_RefundApplicationUpdateEmailIdRequest_VTable vtable;
} Neon_Model_Api_Rpc_RefundApplicationUpdateEmailIdRequest_c;

typedef struct Neon_Model_Api_Rpc_RefundApplicationUpdateEmailIdRequest_o {
	Neon_Model_Api_Rpc_RefundApplicationUpdateEmailIdRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_RefundApplicationUpdateEmailIdRequest_Fields fields;
} Neon_Model_Api_Rpc_RefundApplicationUpdateEmailIdRequest_o;

typedef struct Neon_Model_Api_Rpc_FractalViseResumeRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t fractalViseId_;
} Neon_Model_Api_Rpc_FractalViseResumeRequest_Fields;

typedef struct Neon_Model_Api_Rpc_FractalViseResumeRequest_VTable {
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
} Neon_Model_Api_Rpc_FractalViseResumeRequest_VTable;

typedef struct Neon_Model_Api_Rpc_FractalViseResumeRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_FractalViseResumeRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_FractalViseResumeRequest_VTable vtable;
} Neon_Model_Api_Rpc_FractalViseResumeRequest_c;

typedef struct Neon_Model_Api_Rpc_FractalViseResumeRequest_o {
	Neon_Model_Api_Rpc_FractalViseResumeRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_FractalViseResumeRequest_Fields fields;
} Neon_Model_Api_Rpc_FractalViseResumeRequest_o;

typedef struct Neon_Model_Api_Rpc_ShopCycleUpdateShopReleaseRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t cycleUpdateShopId_;
} Neon_Model_Api_Rpc_ShopCycleUpdateShopReleaseRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ShopCycleUpdateShopReleaseRequest_VTable {
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
} Neon_Model_Api_Rpc_ShopCycleUpdateShopReleaseRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ShopCycleUpdateShopReleaseRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ShopCycleUpdateShopReleaseRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ShopCycleUpdateShopReleaseRequest_VTable vtable;
} Neon_Model_Api_Rpc_ShopCycleUpdateShopReleaseRequest_c;

typedef struct Neon_Model_Api_Rpc_ShopCycleUpdateShopReleaseRequest_o {
	Neon_Model_Api_Rpc_ShopCycleUpdateShopReleaseRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ShopCycleUpdateShopReleaseRequest_Fields fields;
} Neon_Model_Api_Rpc_ShopCycleUpdateShopReleaseRequest_o;

typedef struct Neon_Model_Api_Rpc_FractalViseBattleStartRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t fractalViseAreaId_;
	struct Google_Protobuf_Collections_RepeatedField_int__o* entityIds_;
	struct Google_Protobuf_Collections_RepeatedField_int__o* lineCharacterIds_;
	int32_t advantageType_;
	bool isAttackHit_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
	struct Neon_Model_Api_Model_BloodStainLocation_o* bloodStainLocation_;
} Neon_Model_Api_Rpc_FractalViseBattleStartRequest_Fields;

typedef struct Neon_Model_Api_Rpc_FractalViseBattleStartRequest_VTable {
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
} Neon_Model_Api_Rpc_FractalViseBattleStartRequest_VTable;

typedef struct Neon_Model_Api_Rpc_FractalViseBattleStartRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_FractalViseBattleStartRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_FractalViseBattleStartRequest_VTable vtable;
} Neon_Model_Api_Rpc_FractalViseBattleStartRequest_c;

typedef struct Neon_Model_Api_Rpc_FractalViseBattleStartRequest_o {
	Neon_Model_Api_Rpc_FractalViseBattleStartRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_FractalViseBattleStartRequest_Fields fields;
} Neon_Model_Api_Rpc_FractalViseBattleStartRequest_o;

typedef struct Neon_Model_Api_Rpc_AdventureHospitalRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
} Neon_Model_Api_Rpc_AdventureHospitalRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AdventureHospitalRequest_VTable {
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
} Neon_Model_Api_Rpc_AdventureHospitalRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AdventureHospitalRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AdventureHospitalRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AdventureHospitalRequest_VTable vtable;
} Neon_Model_Api_Rpc_AdventureHospitalRequest_c;

typedef struct Neon_Model_Api_Rpc_AdventureHospitalRequest_o {
	Neon_Model_Api_Rpc_AdventureHospitalRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AdventureHospitalRequest_Fields fields;
} Neon_Model_Api_Rpc_AdventureHospitalRequest_o;

typedef struct Neon_Model_Api_Rpc_DungeonAcquireAreaItemRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t dungeonDifficultyId_;
	int32_t entityId_;
} Neon_Model_Api_Rpc_DungeonAcquireAreaItemRequest_Fields;

typedef struct Neon_Model_Api_Rpc_DungeonAcquireAreaItemRequest_VTable {
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
} Neon_Model_Api_Rpc_DungeonAcquireAreaItemRequest_VTable;

typedef struct Neon_Model_Api_Rpc_DungeonAcquireAreaItemRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_DungeonAcquireAreaItemRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_DungeonAcquireAreaItemRequest_VTable vtable;
} Neon_Model_Api_Rpc_DungeonAcquireAreaItemRequest_c;

typedef struct Neon_Model_Api_Rpc_DungeonAcquireAreaItemRequest_o {
	Neon_Model_Api_Rpc_DungeonAcquireAreaItemRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_DungeonAcquireAreaItemRequest_Fields fields;
} Neon_Model_Api_Rpc_DungeonAcquireAreaItemRequest_o;

typedef struct Neon_Model_Api_Rpc_FieldBossEntryRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t fieldBossId_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
} Neon_Model_Api_Rpc_FieldBossEntryRequest_Fields;

typedef struct Neon_Model_Api_Rpc_FieldBossEntryRequest_VTable {
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
} Neon_Model_Api_Rpc_FieldBossEntryRequest_VTable;

typedef struct Neon_Model_Api_Rpc_FieldBossEntryRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_FieldBossEntryRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_FieldBossEntryRequest_VTable vtable;
} Neon_Model_Api_Rpc_FieldBossEntryRequest_c;

typedef struct Neon_Model_Api_Rpc_FieldBossEntryRequest_o {
	Neon_Model_Api_Rpc_FieldBossEntryRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_FieldBossEntryRequest_Fields fields;
} Neon_Model_Api_Rpc_FieldBossEntryRequest_o;

typedef struct Neon_Model_Api_Rpc_ShopGearShopPurchaseRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t shopGearProductId_;
	int32_t quantity_;
} Neon_Model_Api_Rpc_ShopGearShopPurchaseRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ShopGearShopPurchaseRequest_VTable {
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
} Neon_Model_Api_Rpc_ShopGearShopPurchaseRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ShopGearShopPurchaseRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ShopGearShopPurchaseRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ShopGearShopPurchaseRequest_VTable vtable;
} Neon_Model_Api_Rpc_ShopGearShopPurchaseRequest_c;

typedef struct Neon_Model_Api_Rpc_ShopGearShopPurchaseRequest_o {
	Neon_Model_Api_Rpc_ShopGearShopPurchaseRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ShopGearShopPurchaseRequest_Fields fields;
} Neon_Model_Api_Rpc_ShopGearShopPurchaseRequest_o;

typedef struct Neon_Model_Api_Rpc_StaminaUseItemRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t itemId_;
	int32_t count_;
} Neon_Model_Api_Rpc_StaminaUseItemRequest_Fields;

typedef struct Neon_Model_Api_Rpc_StaminaUseItemRequest_VTable {
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
} Neon_Model_Api_Rpc_StaminaUseItemRequest_VTable;

typedef struct Neon_Model_Api_Rpc_StaminaUseItemRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_StaminaUseItemRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_StaminaUseItemRequest_VTable vtable;
} Neon_Model_Api_Rpc_StaminaUseItemRequest_c;

typedef struct Neon_Model_Api_Rpc_StaminaUseItemRequest_o {
	Neon_Model_Api_Rpc_StaminaUseItemRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_StaminaUseItemRequest_Fields fields;
} Neon_Model_Api_Rpc_StaminaUseItemRequest_o;

typedef struct Neon_Model_Api_Rpc_DungeonResumeRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t dungeonDifficultyId_;
} Neon_Model_Api_Rpc_DungeonResumeRequest_Fields;

typedef struct Neon_Model_Api_Rpc_DungeonResumeRequest_VTable {
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
} Neon_Model_Api_Rpc_DungeonResumeRequest_VTable;

typedef struct Neon_Model_Api_Rpc_DungeonResumeRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_DungeonResumeRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_DungeonResumeRequest_VTable vtable;
} Neon_Model_Api_Rpc_DungeonResumeRequest_c;

typedef struct Neon_Model_Api_Rpc_DungeonResumeRequest_o {
	Neon_Model_Api_Rpc_DungeonResumeRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_DungeonResumeRequest_Fields fields;
} Neon_Model_Api_Rpc_DungeonResumeRequest_o;

typedef struct Neon_Model_Api_Rpc_ShopRandomCostumePurchaseRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t shopId_;
	int32_t characterCostumeId_;
} Neon_Model_Api_Rpc_ShopRandomCostumePurchaseRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ShopRandomCostumePurchaseRequest_VTable {
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
} Neon_Model_Api_Rpc_ShopRandomCostumePurchaseRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ShopRandomCostumePurchaseRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ShopRandomCostumePurchaseRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ShopRandomCostumePurchaseRequest_VTable vtable;
} Neon_Model_Api_Rpc_ShopRandomCostumePurchaseRequest_c;

typedef struct Neon_Model_Api_Rpc_ShopRandomCostumePurchaseRequest_o {
	Neon_Model_Api_Rpc_ShopRandomCostumePurchaseRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ShopRandomCostumePurchaseRequest_Fields fields;
} Neon_Model_Api_Rpc_ShopRandomCostumePurchaseRequest_o;

typedef struct Neon_Model_Api_Rpc_TensionCardDisassembleRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* entityIds_;
} Neon_Model_Api_Rpc_TensionCardDisassembleRequest_Fields;

typedef struct Neon_Model_Api_Rpc_TensionCardDisassembleRequest_VTable {
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
} Neon_Model_Api_Rpc_TensionCardDisassembleRequest_VTable;

typedef struct Neon_Model_Api_Rpc_TensionCardDisassembleRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_TensionCardDisassembleRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_TensionCardDisassembleRequest_VTable vtable;
} Neon_Model_Api_Rpc_TensionCardDisassembleRequest_c;

typedef struct Neon_Model_Api_Rpc_TensionCardDisassembleRequest_o {
	Neon_Model_Api_Rpc_TensionCardDisassembleRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_TensionCardDisassembleRequest_Fields fields;
} Neon_Model_Api_Rpc_TensionCardDisassembleRequest_o;

typedef struct Neon_Model_Api_Rpc_TensionCardLimitBreakEnhanceRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t entityId_;
	struct Google_Protobuf_Collections_RepeatedField_int__o* consumedEntityIds_;
	struct Neon_Model_Api_Model_ConsumedItem_o* consumedItem_;
} Neon_Model_Api_Rpc_TensionCardLimitBreakEnhanceRequest_Fields;

typedef struct Neon_Model_Api_Rpc_TensionCardLimitBreakEnhanceRequest_VTable {
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
} Neon_Model_Api_Rpc_TensionCardLimitBreakEnhanceRequest_VTable;

typedef struct Neon_Model_Api_Rpc_TensionCardLimitBreakEnhanceRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_TensionCardLimitBreakEnhanceRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_TensionCardLimitBreakEnhanceRequest_VTable vtable;
} Neon_Model_Api_Rpc_TensionCardLimitBreakEnhanceRequest_c;

typedef struct Neon_Model_Api_Rpc_TensionCardLimitBreakEnhanceRequest_o {
	Neon_Model_Api_Rpc_TensionCardLimitBreakEnhanceRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_TensionCardLimitBreakEnhanceRequest_Fields fields;
} Neon_Model_Api_Rpc_TensionCardLimitBreakEnhanceRequest_o;

typedef struct Neon_Model_Api_Rpc_MailDeleteRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* entityIds_;
} Neon_Model_Api_Rpc_MailDeleteRequest_Fields;

typedef struct Neon_Model_Api_Rpc_MailDeleteRequest_VTable {
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
} Neon_Model_Api_Rpc_MailDeleteRequest_VTable;

typedef struct Neon_Model_Api_Rpc_MailDeleteRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_MailDeleteRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_MailDeleteRequest_VTable vtable;
} Neon_Model_Api_Rpc_MailDeleteRequest_c;

typedef struct Neon_Model_Api_Rpc_MailDeleteRequest_o {
	Neon_Model_Api_Rpc_MailDeleteRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_MailDeleteRequest_Fields fields;
} Neon_Model_Api_Rpc_MailDeleteRequest_o;

typedef struct Neon_Model_Api_Rpc_AdventureTrackTargetRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_Nullable_int__o warpPointId_;
	struct System_Nullable_int__o fieldBossId_;
	struct System_Nullable_int__o dungeonId_;
} Neon_Model_Api_Rpc_AdventureTrackTargetRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AdventureTrackTargetRequest_VTable {
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
} Neon_Model_Api_Rpc_AdventureTrackTargetRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AdventureTrackTargetRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AdventureTrackTargetRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AdventureTrackTargetRequest_VTable vtable;
} Neon_Model_Api_Rpc_AdventureTrackTargetRequest_c;

typedef struct Neon_Model_Api_Rpc_AdventureTrackTargetRequest_o {
	Neon_Model_Api_Rpc_AdventureTrackTargetRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AdventureTrackTargetRequest_Fields fields;
} Neon_Model_Api_Rpc_AdventureTrackTargetRequest_o;

typedef struct Neon_Model_Api_Rpc_CharacterEnhanceRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t characterId_;
	struct Google_Protobuf_Collections_RepeatedField_ConsumedItem__o* consumedItems_;
} Neon_Model_Api_Rpc_CharacterEnhanceRequest_Fields;

typedef struct Neon_Model_Api_Rpc_CharacterEnhanceRequest_VTable {
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
} Neon_Model_Api_Rpc_CharacterEnhanceRequest_VTable;

typedef struct Neon_Model_Api_Rpc_CharacterEnhanceRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_CharacterEnhanceRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_CharacterEnhanceRequest_VTable vtable;
} Neon_Model_Api_Rpc_CharacterEnhanceRequest_c;

typedef struct Neon_Model_Api_Rpc_CharacterEnhanceRequest_o {
	Neon_Model_Api_Rpc_CharacterEnhanceRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_CharacterEnhanceRequest_Fields fields;
} Neon_Model_Api_Rpc_CharacterEnhanceRequest_o;

typedef struct Neon_Model_Api_Rpc_DungeonEntryRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t dungeonId_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
} Neon_Model_Api_Rpc_DungeonEntryRequest_Fields;

typedef struct Neon_Model_Api_Rpc_DungeonEntryRequest_VTable {
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
} Neon_Model_Api_Rpc_DungeonEntryRequest_VTable;

typedef struct Neon_Model_Api_Rpc_DungeonEntryRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_DungeonEntryRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_DungeonEntryRequest_VTable vtable;
} Neon_Model_Api_Rpc_DungeonEntryRequest_c;

typedef struct Neon_Model_Api_Rpc_DungeonEntryRequest_o {
	Neon_Model_Api_Rpc_DungeonEntryRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_DungeonEntryRequest_Fields fields;
} Neon_Model_Api_Rpc_DungeonEntryRequest_o;

typedef struct Neon_Model_Api_Rpc_ShopCycleUpdateShopPurchaseRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t cycleUpdateShopId_;
	struct Google_Protobuf_WellKnownTypes_Timestamp_o* clientTimestamp_;
} Neon_Model_Api_Rpc_ShopCycleUpdateShopPurchaseRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ShopCycleUpdateShopPurchaseRequest_VTable {
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
} Neon_Model_Api_Rpc_ShopCycleUpdateShopPurchaseRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ShopCycleUpdateShopPurchaseRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ShopCycleUpdateShopPurchaseRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ShopCycleUpdateShopPurchaseRequest_VTable vtable;
} Neon_Model_Api_Rpc_ShopCycleUpdateShopPurchaseRequest_c;

typedef struct Neon_Model_Api_Rpc_ShopCycleUpdateShopPurchaseRequest_o {
	Neon_Model_Api_Rpc_ShopCycleUpdateShopPurchaseRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ShopCycleUpdateShopPurchaseRequest_Fields fields;
} Neon_Model_Api_Rpc_ShopCycleUpdateShopPurchaseRequest_o;

typedef struct Neon_Model_Api_Rpc_GearUnlockRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* gearEntityIds_;
} Neon_Model_Api_Rpc_GearUnlockRequest_Fields;

typedef struct Neon_Model_Api_Rpc_GearUnlockRequest_VTable {
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
} Neon_Model_Api_Rpc_GearUnlockRequest_VTable;

typedef struct Neon_Model_Api_Rpc_GearUnlockRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_GearUnlockRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_GearUnlockRequest_VTable vtable;
} Neon_Model_Api_Rpc_GearUnlockRequest_c;

typedef struct Neon_Model_Api_Rpc_GearUnlockRequest_o {
	Neon_Model_Api_Rpc_GearUnlockRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_GearUnlockRequest_Fields fields;
} Neon_Model_Api_Rpc_GearUnlockRequest_o;

typedef struct Neon_Model_Api_Rpc_XbPvpCasualMatchingRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_Nullable_long__o enemyUserId_;
} Neon_Model_Api_Rpc_XbPvpCasualMatchingRequest_Fields;

typedef struct Neon_Model_Api_Rpc_XbPvpCasualMatchingRequest_VTable {
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
} Neon_Model_Api_Rpc_XbPvpCasualMatchingRequest_VTable;

typedef struct Neon_Model_Api_Rpc_XbPvpCasualMatchingRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_XbPvpCasualMatchingRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_XbPvpCasualMatchingRequest_VTable vtable;
} Neon_Model_Api_Rpc_XbPvpCasualMatchingRequest_c;

typedef struct Neon_Model_Api_Rpc_XbPvpCasualMatchingRequest_o {
	Neon_Model_Api_Rpc_XbPvpCasualMatchingRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_XbPvpCasualMatchingRequest_Fields fields;
} Neon_Model_Api_Rpc_XbPvpCasualMatchingRequest_o;

typedef struct System_Nullable_double__Fields {
	bool hasValue;
	double value;
} System_Nullable_double__Fields;

typedef struct System_Nullable_double__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} System_Nullable_double__VTable;

typedef struct System_Nullable_double__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Nullable_double__VTable vtable;
} System_Nullable_double__c;

typedef struct System_Nullable_double__o {
	System_Nullable_double__Fields fields;
} System_Nullable_double__o;

typedef struct Neon_Model_Api_Rpc_PurchaseVerifyRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_String_o* purchaseSessionId_;
	struct System_String_o* transactionId_;
	struct System_String_o* clientCurrency_;
	struct System_Nullable_double__o clientPrice_;
	struct System_String_o* purchaseData_;
	struct System_String_o* dataSignature_;
} Neon_Model_Api_Rpc_PurchaseVerifyRequest_Fields;

typedef struct Neon_Model_Api_Rpc_PurchaseVerifyRequest_VTable {
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
} Neon_Model_Api_Rpc_PurchaseVerifyRequest_VTable;

typedef struct Neon_Model_Api_Rpc_PurchaseVerifyRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_PurchaseVerifyRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_PurchaseVerifyRequest_VTable vtable;
} Neon_Model_Api_Rpc_PurchaseVerifyRequest_c;

typedef struct Neon_Model_Api_Rpc_PurchaseVerifyRequest_o {
	Neon_Model_Api_Rpc_PurchaseVerifyRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_PurchaseVerifyRequest_Fields fields;
} Neon_Model_Api_Rpc_PurchaseVerifyRequest_o;

typedef struct Neon_Model_Api_Rpc_PurchaseSessionPublishRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_String_o* purchaseSessionId_;
	struct System_String_o* eventType_;
	struct System_String_o* transactionId_;
	struct System_String_o* productId_;
	struct System_String_o* clientCurrency_;
	struct System_Nullable_double__o clientPrice_;
	struct System_String_o* purchaseData_;
	struct System_String_o* dataSignature_;
	struct System_String_o* receipt_;
	struct System_String_o* failureReason_;
} Neon_Model_Api_Rpc_PurchaseSessionPublishRequest_Fields;

typedef struct Neon_Model_Api_Rpc_PurchaseSessionPublishRequest_VTable {
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
} Neon_Model_Api_Rpc_PurchaseSessionPublishRequest_VTable;

typedef struct Neon_Model_Api_Rpc_PurchaseSessionPublishRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_PurchaseSessionPublishRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_PurchaseSessionPublishRequest_VTable vtable;
} Neon_Model_Api_Rpc_PurchaseSessionPublishRequest_c;

typedef struct Neon_Model_Api_Rpc_PurchaseSessionPublishRequest_o {
	Neon_Model_Api_Rpc_PurchaseSessionPublishRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_PurchaseSessionPublishRequest_Fields fields;
} Neon_Model_Api_Rpc_PurchaseSessionPublishRequest_o;

typedef struct Neon_Model_Api_Rpc_TrialBattleRewardReceiveRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t trialCharacterEventId_;
	int32_t trialBattleId_;
} Neon_Model_Api_Rpc_TrialBattleRewardReceiveRequest_Fields;

typedef struct Neon_Model_Api_Rpc_TrialBattleRewardReceiveRequest_VTable {
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
} Neon_Model_Api_Rpc_TrialBattleRewardReceiveRequest_VTable;

typedef struct Neon_Model_Api_Rpc_TrialBattleRewardReceiveRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_TrialBattleRewardReceiveRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_TrialBattleRewardReceiveRequest_VTable vtable;
} Neon_Model_Api_Rpc_TrialBattleRewardReceiveRequest_c;

typedef struct Neon_Model_Api_Rpc_TrialBattleRewardReceiveRequest_o {
	Neon_Model_Api_Rpc_TrialBattleRewardReceiveRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_TrialBattleRewardReceiveRequest_Fields fields;
} Neon_Model_Api_Rpc_TrialBattleRewardReceiveRequest_o;

typedef struct Neon_Model_Api_Rpc_FormationSwitchRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t formationNumber_;
} Neon_Model_Api_Rpc_FormationSwitchRequest_Fields;

typedef struct Neon_Model_Api_Rpc_FormationSwitchRequest_VTable {
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
} Neon_Model_Api_Rpc_FormationSwitchRequest_VTable;

typedef struct Neon_Model_Api_Rpc_FormationSwitchRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_FormationSwitchRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_FormationSwitchRequest_VTable vtable;
} Neon_Model_Api_Rpc_FormationSwitchRequest_c;

typedef struct Neon_Model_Api_Rpc_FormationSwitchRequest_o {
	Neon_Model_Api_Rpc_FormationSwitchRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_FormationSwitchRequest_Fields fields;
} Neon_Model_Api_Rpc_FormationSwitchRequest_o;

typedef struct Neon_Model_Api_Rpc_CharacterSkillPanelResetRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t characterId_;
} Neon_Model_Api_Rpc_CharacterSkillPanelResetRequest_Fields;

typedef struct Neon_Model_Api_Rpc_CharacterSkillPanelResetRequest_VTable {
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
} Neon_Model_Api_Rpc_CharacterSkillPanelResetRequest_VTable;

typedef struct Neon_Model_Api_Rpc_CharacterSkillPanelResetRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_CharacterSkillPanelResetRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_CharacterSkillPanelResetRequest_VTable vtable;
} Neon_Model_Api_Rpc_CharacterSkillPanelResetRequest_c;

typedef struct Neon_Model_Api_Rpc_CharacterSkillPanelResetRequest_o {
	Neon_Model_Api_Rpc_CharacterSkillPanelResetRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_CharacterSkillPanelResetRequest_Fields fields;
} Neon_Model_Api_Rpc_CharacterSkillPanelResetRequest_o;

typedef struct Neon_Model_Api_Rpc_XbFormationUpdateRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t xbId_;
	struct Google_Protobuf_Collections_RepeatedField_XbMemberRequest__o* playerMembers_;
} Neon_Model_Api_Rpc_XbFormationUpdateRequest_Fields;

typedef struct Neon_Model_Api_Rpc_XbFormationUpdateRequest_VTable {
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
} Neon_Model_Api_Rpc_XbFormationUpdateRequest_VTable;

typedef struct Neon_Model_Api_Rpc_XbFormationUpdateRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_XbFormationUpdateRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_XbFormationUpdateRequest_VTable vtable;
} Neon_Model_Api_Rpc_XbFormationUpdateRequest_c;

typedef struct Neon_Model_Api_Rpc_XbFormationUpdateRequest_o {
	Neon_Model_Api_Rpc_XbFormationUpdateRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_XbFormationUpdateRequest_Fields fields;
} Neon_Model_Api_Rpc_XbFormationUpdateRequest_o;

typedef struct Neon_Model_Api_Rpc_FractalViseRewardsReceiveRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Neon_Model_Api_Rpc_FractalViseRewardsReceiveMissionParam_o* receiveMission_;
	bool isReceiveTotalScoreRewards_;
} Neon_Model_Api_Rpc_FractalViseRewardsReceiveRequest_Fields;

typedef struct Neon_Model_Api_Rpc_FractalViseRewardsReceiveRequest_VTable {
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
} Neon_Model_Api_Rpc_FractalViseRewardsReceiveRequest_VTable;

typedef struct Neon_Model_Api_Rpc_FractalViseRewardsReceiveRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_FractalViseRewardsReceiveRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_FractalViseRewardsReceiveRequest_VTable vtable;
} Neon_Model_Api_Rpc_FractalViseRewardsReceiveRequest_c;

typedef struct Neon_Model_Api_Rpc_FractalViseRewardsReceiveRequest_o {
	Neon_Model_Api_Rpc_FractalViseRewardsReceiveRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_FractalViseRewardsReceiveRequest_Fields fields;
} Neon_Model_Api_Rpc_FractalViseRewardsReceiveRequest_o;

typedef struct Neon_Model_Api_Rpc_DungeonBattleStartRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t dungeonDifficultyId_;
	struct Google_Protobuf_Collections_RepeatedField_int__o* entityIds_;
	struct Google_Protobuf_Collections_RepeatedField_int__o* lineCharacterIds_;
	int32_t advantageType_;
	bool isAttackHit_;
} Neon_Model_Api_Rpc_DungeonBattleStartRequest_Fields;

typedef struct Neon_Model_Api_Rpc_DungeonBattleStartRequest_VTable {
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
} Neon_Model_Api_Rpc_DungeonBattleStartRequest_VTable;

typedef struct Neon_Model_Api_Rpc_DungeonBattleStartRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_DungeonBattleStartRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_DungeonBattleStartRequest_VTable vtable;
} Neon_Model_Api_Rpc_DungeonBattleStartRequest_c;

typedef struct Neon_Model_Api_Rpc_DungeonBattleStartRequest_o {
	Neon_Model_Api_Rpc_DungeonBattleStartRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_DungeonBattleStartRequest_Fields fields;
} Neon_Model_Api_Rpc_DungeonBattleStartRequest_o;

typedef struct Neon_Model_Api_Rpc_AuthSignUpRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_String_o* deviceSecret_;
	struct System_String_o* deviceUniqueId_;
	struct System_String_o* deviceModel_;
	struct System_Nullable_int__o language_;
	struct System_Nullable_int__o locale_;
} Neon_Model_Api_Rpc_AuthSignUpRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AuthSignUpRequest_VTable {
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
} Neon_Model_Api_Rpc_AuthSignUpRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AuthSignUpRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AuthSignUpRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AuthSignUpRequest_VTable vtable;
} Neon_Model_Api_Rpc_AuthSignUpRequest_c;

typedef struct Neon_Model_Api_Rpc_AuthSignUpRequest_o {
	Neon_Model_Api_Rpc_AuthSignUpRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AuthSignUpRequest_Fields fields;
} Neon_Model_Api_Rpc_AuthSignUpRequest_o;

typedef struct Neon_Model_Api_Rpc_DebugChallengeClearRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t challengeId_;
} Neon_Model_Api_Rpc_DebugChallengeClearRequest_Fields;

typedef struct Neon_Model_Api_Rpc_DebugChallengeClearRequest_VTable {
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
} Neon_Model_Api_Rpc_DebugChallengeClearRequest_VTable;

typedef struct Neon_Model_Api_Rpc_DebugChallengeClearRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_DebugChallengeClearRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_DebugChallengeClearRequest_VTable vtable;
} Neon_Model_Api_Rpc_DebugChallengeClearRequest_c;

typedef struct Neon_Model_Api_Rpc_DebugChallengeClearRequest_o {
	Neon_Model_Api_Rpc_DebugChallengeClearRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_DebugChallengeClearRequest_Fields fields;
} Neon_Model_Api_Rpc_DebugChallengeClearRequest_o;

typedef struct Neon_Model_Api_Rpc_LoginBonusReceiveRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t loginBonusId_;
} Neon_Model_Api_Rpc_LoginBonusReceiveRequest_Fields;

typedef struct Neon_Model_Api_Rpc_LoginBonusReceiveRequest_VTable {
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
} Neon_Model_Api_Rpc_LoginBonusReceiveRequest_VTable;

typedef struct Neon_Model_Api_Rpc_LoginBonusReceiveRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_LoginBonusReceiveRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_LoginBonusReceiveRequest_VTable vtable;
} Neon_Model_Api_Rpc_LoginBonusReceiveRequest_c;

typedef struct Neon_Model_Api_Rpc_LoginBonusReceiveRequest_o {
	Neon_Model_Api_Rpc_LoginBonusReceiveRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_LoginBonusReceiveRequest_Fields fields;
} Neon_Model_Api_Rpc_LoginBonusReceiveRequest_o;

typedef struct Neon_Model_Api_Rpc_TensionCardEnhanceRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_ConsumedItem__o* consumedItems_;
	int32_t entityId_;
} Neon_Model_Api_Rpc_TensionCardEnhanceRequest_Fields;

typedef struct Neon_Model_Api_Rpc_TensionCardEnhanceRequest_VTable {
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
} Neon_Model_Api_Rpc_TensionCardEnhanceRequest_VTable;

typedef struct Neon_Model_Api_Rpc_TensionCardEnhanceRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_TensionCardEnhanceRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_TensionCardEnhanceRequest_VTable vtable;
} Neon_Model_Api_Rpc_TensionCardEnhanceRequest_c;

typedef struct Neon_Model_Api_Rpc_TensionCardEnhanceRequest_o {
	Neon_Model_Api_Rpc_TensionCardEnhanceRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_TensionCardEnhanceRequest_Fields fields;
} Neon_Model_Api_Rpc_TensionCardEnhanceRequest_o;

typedef struct Neon_Model_Api_Rpc_DungeonFinishRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t dungeonDifficultyId_;
} Neon_Model_Api_Rpc_DungeonFinishRequest_Fields;

typedef struct Neon_Model_Api_Rpc_DungeonFinishRequest_VTable {
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
} Neon_Model_Api_Rpc_DungeonFinishRequest_VTable;

typedef struct Neon_Model_Api_Rpc_DungeonFinishRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_DungeonFinishRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_DungeonFinishRequest_VTable vtable;
} Neon_Model_Api_Rpc_DungeonFinishRequest_c;

typedef struct Neon_Model_Api_Rpc_DungeonFinishRequest_o {
	Neon_Model_Api_Rpc_DungeonFinishRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_DungeonFinishRequest_Fields fields;
} Neon_Model_Api_Rpc_DungeonFinishRequest_o;

typedef struct Neon_Model_Api_Rpc_DebugMailSendRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t count_;
} Neon_Model_Api_Rpc_DebugMailSendRequest_Fields;

typedef struct Neon_Model_Api_Rpc_DebugMailSendRequest_VTable {
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
} Neon_Model_Api_Rpc_DebugMailSendRequest_VTable;

typedef struct Neon_Model_Api_Rpc_DebugMailSendRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_DebugMailSendRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_DebugMailSendRequest_VTable vtable;
} Neon_Model_Api_Rpc_DebugMailSendRequest_c;

typedef struct Neon_Model_Api_Rpc_DebugMailSendRequest_o {
	Neon_Model_Api_Rpc_DebugMailSendRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_DebugMailSendRequest_Fields fields;
} Neon_Model_Api_Rpc_DebugMailSendRequest_o;

typedef struct Neon_Model_Api_Rpc_CharacterRankEnhanceRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t characterId_;
} Neon_Model_Api_Rpc_CharacterRankEnhanceRequest_Fields;

typedef struct Neon_Model_Api_Rpc_CharacterRankEnhanceRequest_VTable {
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
} Neon_Model_Api_Rpc_CharacterRankEnhanceRequest_VTable;

typedef struct Neon_Model_Api_Rpc_CharacterRankEnhanceRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_CharacterRankEnhanceRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_CharacterRankEnhanceRequest_VTable vtable;
} Neon_Model_Api_Rpc_CharacterRankEnhanceRequest_c;

typedef struct Neon_Model_Api_Rpc_CharacterRankEnhanceRequest_o {
	Neon_Model_Api_Rpc_CharacterRankEnhanceRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_CharacterRankEnhanceRequest_Fields fields;
} Neon_Model_Api_Rpc_CharacterRankEnhanceRequest_o;

typedef struct Neon_Model_Api_Rpc_FractalViseClearRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t fractalViseId_;
} Neon_Model_Api_Rpc_FractalViseClearRequest_Fields;

typedef struct Neon_Model_Api_Rpc_FractalViseClearRequest_VTable {
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
} Neon_Model_Api_Rpc_FractalViseClearRequest_VTable;

typedef struct Neon_Model_Api_Rpc_FractalViseClearRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_FractalViseClearRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_FractalViseClearRequest_VTable vtable;
} Neon_Model_Api_Rpc_FractalViseClearRequest_c;

typedef struct Neon_Model_Api_Rpc_FractalViseClearRequest_o {
	Neon_Model_Api_Rpc_FractalViseClearRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_FractalViseClearRequest_Fields fields;
} Neon_Model_Api_Rpc_FractalViseClearRequest_o;

typedef struct Neon_Model_Api_Rpc_XbPvpRankMatchHistoryListRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t seasonId_;
} Neon_Model_Api_Rpc_XbPvpRankMatchHistoryListRequest_Fields;

typedef struct Neon_Model_Api_Rpc_XbPvpRankMatchHistoryListRequest_VTable {
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
} Neon_Model_Api_Rpc_XbPvpRankMatchHistoryListRequest_VTable;

typedef struct Neon_Model_Api_Rpc_XbPvpRankMatchHistoryListRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_XbPvpRankMatchHistoryListRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_XbPvpRankMatchHistoryListRequest_VTable vtable;
} Neon_Model_Api_Rpc_XbPvpRankMatchHistoryListRequest_c;

typedef struct Neon_Model_Api_Rpc_XbPvpRankMatchHistoryListRequest_o {
	Neon_Model_Api_Rpc_XbPvpRankMatchHistoryListRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_XbPvpRankMatchHistoryListRequest_Fields fields;
} Neon_Model_Api_Rpc_XbPvpRankMatchHistoryListRequest_o;

typedef struct Neon_Model_Api_Rpc_DungeonStartRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t dungeonDifficultyId_;
	int32_t bulkConsumeCount_;
	struct Neon_Model_Api_Model_BloodStainLocation_o* bloodStainLocation_;
} Neon_Model_Api_Rpc_DungeonStartRequest_Fields;

typedef struct Neon_Model_Api_Rpc_DungeonStartRequest_VTable {
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
} Neon_Model_Api_Rpc_DungeonStartRequest_VTable;

typedef struct Neon_Model_Api_Rpc_DungeonStartRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_DungeonStartRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_DungeonStartRequest_VTable vtable;
} Neon_Model_Api_Rpc_DungeonStartRequest_c;

typedef struct Neon_Model_Api_Rpc_DungeonStartRequest_o {
	Neon_Model_Api_Rpc_DungeonStartRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_DungeonStartRequest_Fields fields;
} Neon_Model_Api_Rpc_DungeonStartRequest_o;

typedef struct Neon_Model_Api_Rpc_ItemExchangeRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t itemExchangeId_;
	int32_t count_;
	struct Google_Protobuf_Collections_RepeatedField_int__o* consumedItemIds_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
} Neon_Model_Api_Rpc_ItemExchangeRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ItemExchangeRequest_VTable {
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
} Neon_Model_Api_Rpc_ItemExchangeRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ItemExchangeRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ItemExchangeRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ItemExchangeRequest_VTable vtable;
} Neon_Model_Api_Rpc_ItemExchangeRequest_c;

typedef struct Neon_Model_Api_Rpc_ItemExchangeRequest_o {
	Neon_Model_Api_Rpc_ItemExchangeRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ItemExchangeRequest_Fields fields;
} Neon_Model_Api_Rpc_ItemExchangeRequest_o;

typedef struct Neon_Model_Api_Rpc_FollowAddRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int64_t userId_;
} Neon_Model_Api_Rpc_FollowAddRequest_Fields;

typedef struct Neon_Model_Api_Rpc_FollowAddRequest_VTable {
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
} Neon_Model_Api_Rpc_FollowAddRequest_VTable;

typedef struct Neon_Model_Api_Rpc_FollowAddRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_FollowAddRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_FollowAddRequest_VTable vtable;
} Neon_Model_Api_Rpc_FollowAddRequest_c;

typedef struct Neon_Model_Api_Rpc_FollowAddRequest_o {
	Neon_Model_Api_Rpc_FollowAddRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_FollowAddRequest_Fields fields;
} Neon_Model_Api_Rpc_FollowAddRequest_o;

typedef struct Neon_Model_Api_Rpc_UserLinkAppleRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_String_o* idToken_;
} Neon_Model_Api_Rpc_UserLinkAppleRequest_Fields;

typedef struct Neon_Model_Api_Rpc_UserLinkAppleRequest_VTable {
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
} Neon_Model_Api_Rpc_UserLinkAppleRequest_VTable;

typedef struct Neon_Model_Api_Rpc_UserLinkAppleRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_UserLinkAppleRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_UserLinkAppleRequest_VTable vtable;
} Neon_Model_Api_Rpc_UserLinkAppleRequest_c;

typedef struct Neon_Model_Api_Rpc_UserLinkAppleRequest_o {
	Neon_Model_Api_Rpc_UserLinkAppleRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_UserLinkAppleRequest_Fields fields;
} Neon_Model_Api_Rpc_UserLinkAppleRequest_o;

typedef struct Neon_Model_Api_Rpc_SeasonPassTierPurchaseRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t seasonId_;
	int32_t purchaseCount_;
} Neon_Model_Api_Rpc_SeasonPassTierPurchaseRequest_Fields;

typedef struct Neon_Model_Api_Rpc_SeasonPassTierPurchaseRequest_VTable {
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
} Neon_Model_Api_Rpc_SeasonPassTierPurchaseRequest_VTable;

typedef struct Neon_Model_Api_Rpc_SeasonPassTierPurchaseRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_SeasonPassTierPurchaseRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_SeasonPassTierPurchaseRequest_VTable vtable;
} Neon_Model_Api_Rpc_SeasonPassTierPurchaseRequest_c;

typedef struct Neon_Model_Api_Rpc_SeasonPassTierPurchaseRequest_o {
	Neon_Model_Api_Rpc_SeasonPassTierPurchaseRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_SeasonPassTierPurchaseRequest_Fields fields;
} Neon_Model_Api_Rpc_SeasonPassTierPurchaseRequest_o;

typedef struct Neon_Model_Api_Rpc_ShopGearShopListRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t shopId_;
} Neon_Model_Api_Rpc_ShopGearShopListRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ShopGearShopListRequest_VTable {
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
} Neon_Model_Api_Rpc_ShopGearShopListRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ShopGearShopListRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ShopGearShopListRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ShopGearShopListRequest_VTable vtable;
} Neon_Model_Api_Rpc_ShopGearShopListRequest_c;

typedef struct Neon_Model_Api_Rpc_ShopGearShopListRequest_o {
	Neon_Model_Api_Rpc_ShopGearShopListRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ShopGearShopListRequest_Fields fields;
} Neon_Model_Api_Rpc_ShopGearShopListRequest_o;

typedef struct Neon_Model_Api_Rpc_FractalViseNextAreaRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t fractalViseAreaId_;
} Neon_Model_Api_Rpc_FractalViseNextAreaRequest_Fields;

typedef struct Neon_Model_Api_Rpc_FractalViseNextAreaRequest_VTable {
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
} Neon_Model_Api_Rpc_FractalViseNextAreaRequest_VTable;

typedef struct Neon_Model_Api_Rpc_FractalViseNextAreaRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_FractalViseNextAreaRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_FractalViseNextAreaRequest_VTable vtable;
} Neon_Model_Api_Rpc_FractalViseNextAreaRequest_c;

typedef struct Neon_Model_Api_Rpc_FractalViseNextAreaRequest_o {
	Neon_Model_Api_Rpc_FractalViseNextAreaRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_FractalViseNextAreaRequest_Fields fields;
} Neon_Model_Api_Rpc_FractalViseNextAreaRequest_o;

typedef struct Neon_Model_Api_Rpc_ItemSellRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_ConsumedItem__o* items_;
} Neon_Model_Api_Rpc_ItemSellRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ItemSellRequest_VTable {
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
} Neon_Model_Api_Rpc_ItemSellRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ItemSellRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ItemSellRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ItemSellRequest_VTable vtable;
} Neon_Model_Api_Rpc_ItemSellRequest_c;

typedef struct Neon_Model_Api_Rpc_ItemSellRequest_o {
	Neon_Model_Api_Rpc_ItemSellRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ItemSellRequest_Fields fields;
} Neon_Model_Api_Rpc_ItemSellRequest_o;

typedef struct Neon_Model_Api_Rpc_ItemRequestFulfillRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int64_t userId_;
	int32_t deliveryRequestItemId_;
} Neon_Model_Api_Rpc_ItemRequestFulfillRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ItemRequestFulfillRequest_VTable {
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
} Neon_Model_Api_Rpc_ItemRequestFulfillRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ItemRequestFulfillRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ItemRequestFulfillRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ItemRequestFulfillRequest_VTable vtable;
} Neon_Model_Api_Rpc_ItemRequestFulfillRequest_c;

typedef struct Neon_Model_Api_Rpc_ItemRequestFulfillRequest_o {
	Neon_Model_Api_Rpc_ItemRequestFulfillRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ItemRequestFulfillRequest_Fields fields;
} Neon_Model_Api_Rpc_ItemRequestFulfillRequest_o;

typedef struct Neon_Model_Api_Rpc_SeasonPassReceiveAllRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t seasonId_;
} Neon_Model_Api_Rpc_SeasonPassReceiveAllRequest_Fields;

typedef struct Neon_Model_Api_Rpc_SeasonPassReceiveAllRequest_VTable {
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
} Neon_Model_Api_Rpc_SeasonPassReceiveAllRequest_VTable;

typedef struct Neon_Model_Api_Rpc_SeasonPassReceiveAllRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_SeasonPassReceiveAllRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_SeasonPassReceiveAllRequest_VTable vtable;
} Neon_Model_Api_Rpc_SeasonPassReceiveAllRequest_c;

typedef struct Neon_Model_Api_Rpc_SeasonPassReceiveAllRequest_o {
	Neon_Model_Api_Rpc_SeasonPassReceiveAllRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_SeasonPassReceiveAllRequest_Fields fields;
} Neon_Model_Api_Rpc_SeasonPassReceiveAllRequest_o;

typedef struct Neon_Model_Api_Rpc_RefundApplicationVerifyEmailIdRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t verificationCode_;
} Neon_Model_Api_Rpc_RefundApplicationVerifyEmailIdRequest_Fields;

typedef struct Neon_Model_Api_Rpc_RefundApplicationVerifyEmailIdRequest_VTable {
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
} Neon_Model_Api_Rpc_RefundApplicationVerifyEmailIdRequest_VTable;

typedef struct Neon_Model_Api_Rpc_RefundApplicationVerifyEmailIdRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_RefundApplicationVerifyEmailIdRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_RefundApplicationVerifyEmailIdRequest_VTable vtable;
} Neon_Model_Api_Rpc_RefundApplicationVerifyEmailIdRequest_c;

typedef struct Neon_Model_Api_Rpc_RefundApplicationVerifyEmailIdRequest_o {
	Neon_Model_Api_Rpc_RefundApplicationVerifyEmailIdRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_RefundApplicationVerifyEmailIdRequest_Fields fields;
} Neon_Model_Api_Rpc_RefundApplicationVerifyEmailIdRequest_o;

typedef struct Neon_Model_Api_Rpc_FractalViseRetireRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t fractalViseId_;
} Neon_Model_Api_Rpc_FractalViseRetireRequest_Fields;

typedef struct Neon_Model_Api_Rpc_FractalViseRetireRequest_VTable {
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
} Neon_Model_Api_Rpc_FractalViseRetireRequest_VTable;

typedef struct Neon_Model_Api_Rpc_FractalViseRetireRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_FractalViseRetireRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_FractalViseRetireRequest_VTable vtable;
} Neon_Model_Api_Rpc_FractalViseRetireRequest_c;

typedef struct Neon_Model_Api_Rpc_FractalViseRetireRequest_o {
	Neon_Model_Api_Rpc_FractalViseRetireRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_FractalViseRetireRequest_Fields fields;
} Neon_Model_Api_Rpc_FractalViseRetireRequest_o;

typedef struct Neon_Model_Api_Rpc_ItemUseSupplyRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t itemId_;
	int32_t count_;
	struct System_Nullable_int__o characterId_;
} Neon_Model_Api_Rpc_ItemUseSupplyRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ItemUseSupplyRequest_VTable {
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
} Neon_Model_Api_Rpc_ItemUseSupplyRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ItemUseSupplyRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ItemUseSupplyRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ItemUseSupplyRequest_VTable vtable;
} Neon_Model_Api_Rpc_ItemUseSupplyRequest_c;

typedef struct Neon_Model_Api_Rpc_ItemUseSupplyRequest_o {
	Neon_Model_Api_Rpc_ItemUseSupplyRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ItemUseSupplyRequest_Fields fields;
} Neon_Model_Api_Rpc_ItemUseSupplyRequest_o;

typedef struct Neon_Model_Api_Rpc_MissionReceiveRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* missionIds_;
} Neon_Model_Api_Rpc_MissionReceiveRequest_Fields;

typedef struct Neon_Model_Api_Rpc_MissionReceiveRequest_VTable {
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
} Neon_Model_Api_Rpc_MissionReceiveRequest_VTable;

typedef struct Neon_Model_Api_Rpc_MissionReceiveRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_MissionReceiveRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_MissionReceiveRequest_VTable vtable;
} Neon_Model_Api_Rpc_MissionReceiveRequest_c;

typedef struct Neon_Model_Api_Rpc_MissionReceiveRequest_o {
	Neon_Model_Api_Rpc_MissionReceiveRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_MissionReceiveRequest_Fields fields;
} Neon_Model_Api_Rpc_MissionReceiveRequest_o;

typedef struct Neon_Model_Api_Rpc_ItemSynthesizeRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t itemSynthesisId_;
	int32_t count_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
} Neon_Model_Api_Rpc_ItemSynthesizeRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ItemSynthesizeRequest_VTable {
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
} Neon_Model_Api_Rpc_ItemSynthesizeRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ItemSynthesizeRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ItemSynthesizeRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ItemSynthesizeRequest_VTable vtable;
} Neon_Model_Api_Rpc_ItemSynthesizeRequest_c;

typedef struct Neon_Model_Api_Rpc_ItemSynthesizeRequest_o {
	Neon_Model_Api_Rpc_ItemSynthesizeRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ItemSynthesizeRequest_Fields fields;
} Neon_Model_Api_Rpc_ItemSynthesizeRequest_o;

typedef struct Neon_Model_Api_Rpc_HappyWorkerStartRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t happyWorkerItemId_;
} Neon_Model_Api_Rpc_HappyWorkerStartRequest_Fields;

typedef struct Neon_Model_Api_Rpc_HappyWorkerStartRequest_VTable {
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
} Neon_Model_Api_Rpc_HappyWorkerStartRequest_VTable;

typedef struct Neon_Model_Api_Rpc_HappyWorkerStartRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_HappyWorkerStartRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_HappyWorkerStartRequest_VTable vtable;
} Neon_Model_Api_Rpc_HappyWorkerStartRequest_c;

typedef struct Neon_Model_Api_Rpc_HappyWorkerStartRequest_o {
	Neon_Model_Api_Rpc_HappyWorkerStartRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_HappyWorkerStartRequest_Fields fields;
} Neon_Model_Api_Rpc_HappyWorkerStartRequest_o;

typedef struct Neon_Model_Api_Rpc_GearLockRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* gearEntityIds_;
} Neon_Model_Api_Rpc_GearLockRequest_Fields;

typedef struct Neon_Model_Api_Rpc_GearLockRequest_VTable {
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
} Neon_Model_Api_Rpc_GearLockRequest_VTable;

typedef struct Neon_Model_Api_Rpc_GearLockRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_GearLockRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_GearLockRequest_VTable vtable;
} Neon_Model_Api_Rpc_GearLockRequest_c;

typedef struct Neon_Model_Api_Rpc_GearLockRequest_o {
	Neon_Model_Api_Rpc_GearLockRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_GearLockRequest_Fields fields;
} Neon_Model_Api_Rpc_GearLockRequest_o;

typedef struct Neon_Model_Api_Rpc_FractalViseBossDifficultyRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t fractalViseId_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
} Neon_Model_Api_Rpc_FractalViseBossDifficultyRequest_Fields;

typedef struct Neon_Model_Api_Rpc_FractalViseBossDifficultyRequest_VTable {
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
} Neon_Model_Api_Rpc_FractalViseBossDifficultyRequest_VTable;

typedef struct Neon_Model_Api_Rpc_FractalViseBossDifficultyRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_FractalViseBossDifficultyRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_FractalViseBossDifficultyRequest_VTable vtable;
} Neon_Model_Api_Rpc_FractalViseBossDifficultyRequest_c;

typedef struct Neon_Model_Api_Rpc_FractalViseBossDifficultyRequest_o {
	Neon_Model_Api_Rpc_FractalViseBossDifficultyRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_FractalViseBossDifficultyRequest_Fields fields;
} Neon_Model_Api_Rpc_FractalViseBossDifficultyRequest_o;

typedef struct Neon_Model_Api_Rpc_AdventureReleaseEventLiftRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t eventLiftId_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
} Neon_Model_Api_Rpc_AdventureReleaseEventLiftRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AdventureReleaseEventLiftRequest_VTable {
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
} Neon_Model_Api_Rpc_AdventureReleaseEventLiftRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AdventureReleaseEventLiftRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AdventureReleaseEventLiftRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AdventureReleaseEventLiftRequest_VTable vtable;
} Neon_Model_Api_Rpc_AdventureReleaseEventLiftRequest_c;

typedef struct Neon_Model_Api_Rpc_AdventureReleaseEventLiftRequest_o {
	Neon_Model_Api_Rpc_AdventureReleaseEventLiftRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AdventureReleaseEventLiftRequest_Fields fields;
} Neon_Model_Api_Rpc_AdventureReleaseEventLiftRequest_o;

typedef struct Neon_Model_Api_Rpc_GearCompressRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* gearEntityIds_;
} Neon_Model_Api_Rpc_GearCompressRequest_Fields;

typedef struct Neon_Model_Api_Rpc_GearCompressRequest_VTable {
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
} Neon_Model_Api_Rpc_GearCompressRequest_VTable;

typedef struct Neon_Model_Api_Rpc_GearCompressRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_GearCompressRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_GearCompressRequest_VTable vtable;
} Neon_Model_Api_Rpc_GearCompressRequest_c;

typedef struct Neon_Model_Api_Rpc_GearCompressRequest_o {
	Neon_Model_Api_Rpc_GearCompressRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_GearCompressRequest_Fields fields;
} Neon_Model_Api_Rpc_GearCompressRequest_o;

typedef struct Neon_Model_Api_Rpc_HappyWorkerCancelRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t happyWorkerItemId_;
} Neon_Model_Api_Rpc_HappyWorkerCancelRequest_Fields;

typedef struct Neon_Model_Api_Rpc_HappyWorkerCancelRequest_VTable {
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
} Neon_Model_Api_Rpc_HappyWorkerCancelRequest_VTable;

typedef struct Neon_Model_Api_Rpc_HappyWorkerCancelRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_HappyWorkerCancelRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_HappyWorkerCancelRequest_VTable vtable;
} Neon_Model_Api_Rpc_HappyWorkerCancelRequest_c;

typedef struct Neon_Model_Api_Rpc_HappyWorkerCancelRequest_o {
	Neon_Model_Api_Rpc_HappyWorkerCancelRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_HappyWorkerCancelRequest_Fields fields;
} Neon_Model_Api_Rpc_HappyWorkerCancelRequest_o;

typedef struct Neon_Model_Api_Rpc_FollowDetailRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int64_t userId_;
} Neon_Model_Api_Rpc_FollowDetailRequest_Fields;

typedef struct Neon_Model_Api_Rpc_FollowDetailRequest_VTable {
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
} Neon_Model_Api_Rpc_FollowDetailRequest_VTable;

typedef struct Neon_Model_Api_Rpc_FollowDetailRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_FollowDetailRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_FollowDetailRequest_VTable vtable;
} Neon_Model_Api_Rpc_FollowDetailRequest_c;

typedef struct Neon_Model_Api_Rpc_FollowDetailRequest_o {
	Neon_Model_Api_Rpc_FollowDetailRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_FollowDetailRequest_Fields fields;
} Neon_Model_Api_Rpc_FollowDetailRequest_o;

typedef struct Neon_Model_Api_Rpc_UserUpdateBirthdateRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t year_;
	int32_t month_;
} Neon_Model_Api_Rpc_UserUpdateBirthdateRequest_Fields;

typedef struct Neon_Model_Api_Rpc_UserUpdateBirthdateRequest_VTable {
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
} Neon_Model_Api_Rpc_UserUpdateBirthdateRequest_VTable;

typedef struct Neon_Model_Api_Rpc_UserUpdateBirthdateRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_UserUpdateBirthdateRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_UserUpdateBirthdateRequest_VTable vtable;
} Neon_Model_Api_Rpc_UserUpdateBirthdateRequest_c;

typedef struct Neon_Model_Api_Rpc_UserUpdateBirthdateRequest_o {
	Neon_Model_Api_Rpc_UserUpdateBirthdateRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_UserUpdateBirthdateRequest_Fields fields;
} Neon_Model_Api_Rpc_UserUpdateBirthdateRequest_o;

typedef struct Neon_Model_Api_Rpc_AuthSignUpPasscodeRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_String_o* deviceSecret_;
	struct System_String_o* deviceUniqueId_;
	struct System_String_o* deviceModel_;
	int64_t userId_;
	struct System_String_o* passcode_;
	bool execute_;
} Neon_Model_Api_Rpc_AuthSignUpPasscodeRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AuthSignUpPasscodeRequest_VTable {
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
} Neon_Model_Api_Rpc_AuthSignUpPasscodeRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AuthSignUpPasscodeRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AuthSignUpPasscodeRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AuthSignUpPasscodeRequest_VTable vtable;
} Neon_Model_Api_Rpc_AuthSignUpPasscodeRequest_c;

typedef struct Neon_Model_Api_Rpc_AuthSignUpPasscodeRequest_o {
	Neon_Model_Api_Rpc_AuthSignUpPasscodeRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AuthSignUpPasscodeRequest_Fields fields;
} Neon_Model_Api_Rpc_AuthSignUpPasscodeRequest_o;

typedef struct Neon_Model_Api_Rpc_ProfileUpdateCharacterLikabilityScaleRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t scale_;
} Neon_Model_Api_Rpc_ProfileUpdateCharacterLikabilityScaleRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ProfileUpdateCharacterLikabilityScaleRequest_VTable {
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
} Neon_Model_Api_Rpc_ProfileUpdateCharacterLikabilityScaleRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ProfileUpdateCharacterLikabilityScaleRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ProfileUpdateCharacterLikabilityScaleRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ProfileUpdateCharacterLikabilityScaleRequest_VTable vtable;
} Neon_Model_Api_Rpc_ProfileUpdateCharacterLikabilityScaleRequest_c;

typedef struct Neon_Model_Api_Rpc_ProfileUpdateCharacterLikabilityScaleRequest_o {
	Neon_Model_Api_Rpc_ProfileUpdateCharacterLikabilityScaleRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ProfileUpdateCharacterLikabilityScaleRequest_Fields fields;
} Neon_Model_Api_Rpc_ProfileUpdateCharacterLikabilityScaleRequest_o;

typedef struct Neon_Model_Api_Rpc_DebugXbPvpSpecifyEnemyRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_Nullable_long__o enemyUserId_;
} Neon_Model_Api_Rpc_DebugXbPvpSpecifyEnemyRequest_Fields;

typedef struct Neon_Model_Api_Rpc_DebugXbPvpSpecifyEnemyRequest_VTable {
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
} Neon_Model_Api_Rpc_DebugXbPvpSpecifyEnemyRequest_VTable;

typedef struct Neon_Model_Api_Rpc_DebugXbPvpSpecifyEnemyRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_DebugXbPvpSpecifyEnemyRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_DebugXbPvpSpecifyEnemyRequest_VTable vtable;
} Neon_Model_Api_Rpc_DebugXbPvpSpecifyEnemyRequest_c;

typedef struct Neon_Model_Api_Rpc_DebugXbPvpSpecifyEnemyRequest_o {
	Neon_Model_Api_Rpc_DebugXbPvpSpecifyEnemyRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_DebugXbPvpSpecifyEnemyRequest_Fields fields;
} Neon_Model_Api_Rpc_DebugXbPvpSpecifyEnemyRequest_o;

typedef struct Neon_Model_Api_Rpc_RecipeShopPurchaseRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t recipeShopId_;
} Neon_Model_Api_Rpc_RecipeShopPurchaseRequest_Fields;

typedef struct Neon_Model_Api_Rpc_RecipeShopPurchaseRequest_VTable {
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
} Neon_Model_Api_Rpc_RecipeShopPurchaseRequest_VTable;

typedef struct Neon_Model_Api_Rpc_RecipeShopPurchaseRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_RecipeShopPurchaseRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_RecipeShopPurchaseRequest_VTable vtable;
} Neon_Model_Api_Rpc_RecipeShopPurchaseRequest_c;

typedef struct Neon_Model_Api_Rpc_RecipeShopPurchaseRequest_o {
	Neon_Model_Api_Rpc_RecipeShopPurchaseRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_RecipeShopPurchaseRequest_Fields fields;
} Neon_Model_Api_Rpc_RecipeShopPurchaseRequest_o;

typedef struct Neon_Model_Api_Rpc_ItemOpenSelectBoxRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_SelectBoxChoice__o* selectBoxChoices_;
} Neon_Model_Api_Rpc_ItemOpenSelectBoxRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ItemOpenSelectBoxRequest_VTable {
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
} Neon_Model_Api_Rpc_ItemOpenSelectBoxRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ItemOpenSelectBoxRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ItemOpenSelectBoxRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ItemOpenSelectBoxRequest_VTable vtable;
} Neon_Model_Api_Rpc_ItemOpenSelectBoxRequest_c;

typedef struct Neon_Model_Api_Rpc_ItemOpenSelectBoxRequest_o {
	Neon_Model_Api_Rpc_ItemOpenSelectBoxRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ItemOpenSelectBoxRequest_Fields fields;
} Neon_Model_Api_Rpc_ItemOpenSelectBoxRequest_o;

typedef struct Neon_Model_Api_Rpc_SeasonPassPurchasePaidPassRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t seasonId_;
	bool purchaseUpper_;
} Neon_Model_Api_Rpc_SeasonPassPurchasePaidPassRequest_Fields;

typedef struct Neon_Model_Api_Rpc_SeasonPassPurchasePaidPassRequest_VTable {
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
} Neon_Model_Api_Rpc_SeasonPassPurchasePaidPassRequest_VTable;

typedef struct Neon_Model_Api_Rpc_SeasonPassPurchasePaidPassRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_SeasonPassPurchasePaidPassRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_SeasonPassPurchasePaidPassRequest_VTable vtable;
} Neon_Model_Api_Rpc_SeasonPassPurchasePaidPassRequest_c;

typedef struct Neon_Model_Api_Rpc_SeasonPassPurchasePaidPassRequest_o {
	Neon_Model_Api_Rpc_SeasonPassPurchasePaidPassRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_SeasonPassPurchasePaidPassRequest_Fields fields;
} Neon_Model_Api_Rpc_SeasonPassPurchasePaidPassRequest_o;

typedef struct Neon_Model_Api_Rpc_ShopPurchaseRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t shopProductId_;
	int32_t quantity_;
} Neon_Model_Api_Rpc_ShopPurchaseRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ShopPurchaseRequest_VTable {
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
} Neon_Model_Api_Rpc_ShopPurchaseRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ShopPurchaseRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ShopPurchaseRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ShopPurchaseRequest_VTable vtable;
} Neon_Model_Api_Rpc_ShopPurchaseRequest_c;

typedef struct Neon_Model_Api_Rpc_ShopPurchaseRequest_o {
	Neon_Model_Api_Rpc_ShopPurchaseRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ShopPurchaseRequest_Fields fields;
} Neon_Model_Api_Rpc_ShopPurchaseRequest_o;

typedef struct Neon_Model_Api_Rpc_DebugUserBulkResourceRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* types_;
	int32_t stackableResourceRate_;
	int32_t entityCount_;
} Neon_Model_Api_Rpc_DebugUserBulkResourceRequest_Fields;

typedef struct Neon_Model_Api_Rpc_DebugUserBulkResourceRequest_VTable {
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
} Neon_Model_Api_Rpc_DebugUserBulkResourceRequest_VTable;

typedef struct Neon_Model_Api_Rpc_DebugUserBulkResourceRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_DebugUserBulkResourceRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_DebugUserBulkResourceRequest_VTable vtable;
} Neon_Model_Api_Rpc_DebugUserBulkResourceRequest_c;

typedef struct Neon_Model_Api_Rpc_DebugUserBulkResourceRequest_o {
	Neon_Model_Api_Rpc_DebugUserBulkResourceRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_DebugUserBulkResourceRequest_Fields fields;
} Neon_Model_Api_Rpc_DebugUserBulkResourceRequest_o;

typedef struct Neon_Model_Api_Rpc_AdventureWarpAreaLocatorRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t warpAreaType_;
	int32_t warpAreaId_;
} Neon_Model_Api_Rpc_AdventureWarpAreaLocatorRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AdventureWarpAreaLocatorRequest_VTable {
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
} Neon_Model_Api_Rpc_AdventureWarpAreaLocatorRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AdventureWarpAreaLocatorRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AdventureWarpAreaLocatorRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AdventureWarpAreaLocatorRequest_VTable vtable;
} Neon_Model_Api_Rpc_AdventureWarpAreaLocatorRequest_c;

typedef struct Neon_Model_Api_Rpc_AdventureWarpAreaLocatorRequest_o {
	Neon_Model_Api_Rpc_AdventureWarpAreaLocatorRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AdventureWarpAreaLocatorRequest_Fields fields;
} Neon_Model_Api_Rpc_AdventureWarpAreaLocatorRequest_o;

typedef struct Neon_Model_Api_Rpc_XbUpdateSkillOrbStatusRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t xbId_;
	struct Google_Protobuf_Collections_RepeatedField_XbSkillOrbStatusRequest__o* skillOrbStatuses_;
} Neon_Model_Api_Rpc_XbUpdateSkillOrbStatusRequest_Fields;

typedef struct Neon_Model_Api_Rpc_XbUpdateSkillOrbStatusRequest_VTable {
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
} Neon_Model_Api_Rpc_XbUpdateSkillOrbStatusRequest_VTable;

typedef struct Neon_Model_Api_Rpc_XbUpdateSkillOrbStatusRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_XbUpdateSkillOrbStatusRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_XbUpdateSkillOrbStatusRequest_VTable vtable;
} Neon_Model_Api_Rpc_XbUpdateSkillOrbStatusRequest_c;

typedef struct Neon_Model_Api_Rpc_XbUpdateSkillOrbStatusRequest_o {
	Neon_Model_Api_Rpc_XbUpdateSkillOrbStatusRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_XbUpdateSkillOrbStatusRequest_Fields fields;
} Neon_Model_Api_Rpc_XbUpdateSkillOrbStatusRequest_o;

typedef struct Neon_Model_Api_Rpc_BattleRestartRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* lineCharacterIds_;
	struct Google_Protobuf_Collections_RepeatedField_int__o* encounteredEnemyIds_;
	bool isDifficultyDecrease_;
} Neon_Model_Api_Rpc_BattleRestartRequest_Fields;

typedef struct Neon_Model_Api_Rpc_BattleRestartRequest_VTable {
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
} Neon_Model_Api_Rpc_BattleRestartRequest_VTable;

typedef struct Neon_Model_Api_Rpc_BattleRestartRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_BattleRestartRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_BattleRestartRequest_VTable vtable;
} Neon_Model_Api_Rpc_BattleRestartRequest_c;

typedef struct Neon_Model_Api_Rpc_BattleRestartRequest_o {
	Neon_Model_Api_Rpc_BattleRestartRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_BattleRestartRequest_Fields fields;
} Neon_Model_Api_Rpc_BattleRestartRequest_o;

typedef struct Neon_Model_Api_Rpc_CharacterEquipRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t characterId_;
	struct System_Nullable_int__o gearSlot1_;
	struct System_Nullable_int__o gearSlot2_;
	struct System_Nullable_int__o gearSlot3_;
} Neon_Model_Api_Rpc_CharacterEquipRequest_Fields;

typedef struct Neon_Model_Api_Rpc_CharacterEquipRequest_VTable {
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
} Neon_Model_Api_Rpc_CharacterEquipRequest_VTable;

typedef struct Neon_Model_Api_Rpc_CharacterEquipRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_CharacterEquipRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_CharacterEquipRequest_VTable vtable;
} Neon_Model_Api_Rpc_CharacterEquipRequest_c;

typedef struct Neon_Model_Api_Rpc_CharacterEquipRequest_o {
	Neon_Model_Api_Rpc_CharacterEquipRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_CharacterEquipRequest_Fields fields;
} Neon_Model_Api_Rpc_CharacterEquipRequest_o;

typedef struct Neon_Model_Api_Rpc_UserUpdateLanguageRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t language_;
} Neon_Model_Api_Rpc_UserUpdateLanguageRequest_Fields;

typedef struct Neon_Model_Api_Rpc_UserUpdateLanguageRequest_VTable {
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
} Neon_Model_Api_Rpc_UserUpdateLanguageRequest_VTable;

typedef struct Neon_Model_Api_Rpc_UserUpdateLanguageRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_UserUpdateLanguageRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_UserUpdateLanguageRequest_VTable vtable;
} Neon_Model_Api_Rpc_UserUpdateLanguageRequest_c;

typedef struct Neon_Model_Api_Rpc_UserUpdateLanguageRequest_o {
	Neon_Model_Api_Rpc_UserUpdateLanguageRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_UserUpdateLanguageRequest_Fields fields;
} Neon_Model_Api_Rpc_UserUpdateLanguageRequest_o;

typedef struct Neon_Model_Api_Rpc_MailOpenRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* entityIds_;
} Neon_Model_Api_Rpc_MailOpenRequest_Fields;

typedef struct Neon_Model_Api_Rpc_MailOpenRequest_VTable {
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
} Neon_Model_Api_Rpc_MailOpenRequest_VTable;

typedef struct Neon_Model_Api_Rpc_MailOpenRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_MailOpenRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_MailOpenRequest_VTable vtable;
} Neon_Model_Api_Rpc_MailOpenRequest_c;

typedef struct Neon_Model_Api_Rpc_MailOpenRequest_o {
	Neon_Model_Api_Rpc_MailOpenRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_MailOpenRequest_Fields fields;
} Neon_Model_Api_Rpc_MailOpenRequest_o;

typedef struct Neon_Model_Api_Rpc_ItemUseSupplyGearEffectRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t itemId_;
	int32_t baseGearEntityId_;
} Neon_Model_Api_Rpc_ItemUseSupplyGearEffectRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ItemUseSupplyGearEffectRequest_VTable {
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
} Neon_Model_Api_Rpc_ItemUseSupplyGearEffectRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ItemUseSupplyGearEffectRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ItemUseSupplyGearEffectRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ItemUseSupplyGearEffectRequest_VTable vtable;
} Neon_Model_Api_Rpc_ItemUseSupplyGearEffectRequest_c;

typedef struct Neon_Model_Api_Rpc_ItemUseSupplyGearEffectRequest_o {
	Neon_Model_Api_Rpc_ItemUseSupplyGearEffectRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ItemUseSupplyGearEffectRequest_Fields fields;
} Neon_Model_Api_Rpc_ItemUseSupplyGearEffectRequest_o;

typedef struct Neon_Model_Api_Rpc_TensionCardLevelLimitEnhanceRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t entityId_;
} Neon_Model_Api_Rpc_TensionCardLevelLimitEnhanceRequest_Fields;

typedef struct Neon_Model_Api_Rpc_TensionCardLevelLimitEnhanceRequest_VTable {
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
} Neon_Model_Api_Rpc_TensionCardLevelLimitEnhanceRequest_VTable;

typedef struct Neon_Model_Api_Rpc_TensionCardLevelLimitEnhanceRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_TensionCardLevelLimitEnhanceRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_TensionCardLevelLimitEnhanceRequest_VTable vtable;
} Neon_Model_Api_Rpc_TensionCardLevelLimitEnhanceRequest_c;

typedef struct Neon_Model_Api_Rpc_TensionCardLevelLimitEnhanceRequest_o {
	Neon_Model_Api_Rpc_TensionCardLevelLimitEnhanceRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_TensionCardLevelLimitEnhanceRequest_Fields fields;
} Neon_Model_Api_Rpc_TensionCardLevelLimitEnhanceRequest_o;

typedef struct Neon_Model_Api_Rpc_GachaExecuteRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t gachaId_;
	int32_t gachaButtonId_;
	struct Google_Protobuf_WellKnownTypes_Timestamp_o* clientTimestamp_;
} Neon_Model_Api_Rpc_GachaExecuteRequest_Fields;

typedef struct Neon_Model_Api_Rpc_GachaExecuteRequest_VTable {
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
} Neon_Model_Api_Rpc_GachaExecuteRequest_VTable;

typedef struct Neon_Model_Api_Rpc_GachaExecuteRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_GachaExecuteRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_GachaExecuteRequest_VTable vtable;
} Neon_Model_Api_Rpc_GachaExecuteRequest_c;

typedef struct Neon_Model_Api_Rpc_GachaExecuteRequest_o {
	Neon_Model_Api_Rpc_GachaExecuteRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_GachaExecuteRequest_Fields fields;
} Neon_Model_Api_Rpc_GachaExecuteRequest_o;

typedef struct Neon_Model_Api_Rpc_BattleSkipRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t battleEntryId_;
	struct Neon_Model_Api_Model_BattleTrigger_o* battleTrigger_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
	struct Google_Protobuf_Collections_RepeatedField_int__o* lineCharacterIds_;
} Neon_Model_Api_Rpc_BattleSkipRequest_Fields;

typedef struct Neon_Model_Api_Rpc_BattleSkipRequest_VTable {
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
} Neon_Model_Api_Rpc_BattleSkipRequest_VTable;

typedef struct Neon_Model_Api_Rpc_BattleSkipRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_BattleSkipRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_BattleSkipRequest_VTable vtable;
} Neon_Model_Api_Rpc_BattleSkipRequest_c;

typedef struct Neon_Model_Api_Rpc_BattleSkipRequest_o {
	Neon_Model_Api_Rpc_BattleSkipRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_BattleSkipRequest_Fields fields;
} Neon_Model_Api_Rpc_BattleSkipRequest_o;

typedef struct Neon_Model_Api_Rpc_CharacterSkillPanelEnhanceRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t characterSkillPanelId_;
	int32_t level_;
} Neon_Model_Api_Rpc_CharacterSkillPanelEnhanceRequest_Fields;

typedef struct Neon_Model_Api_Rpc_CharacterSkillPanelEnhanceRequest_VTable {
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
} Neon_Model_Api_Rpc_CharacterSkillPanelEnhanceRequest_VTable;

typedef struct Neon_Model_Api_Rpc_CharacterSkillPanelEnhanceRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_CharacterSkillPanelEnhanceRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_CharacterSkillPanelEnhanceRequest_VTable vtable;
} Neon_Model_Api_Rpc_CharacterSkillPanelEnhanceRequest_c;

typedef struct Neon_Model_Api_Rpc_CharacterSkillPanelEnhanceRequest_o {
	Neon_Model_Api_Rpc_CharacterSkillPanelEnhanceRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_CharacterSkillPanelEnhanceRequest_Fields fields;
} Neon_Model_Api_Rpc_CharacterSkillPanelEnhanceRequest_o;

typedef struct Neon_Model_Api_Rpc_ShopRandomCostumeListRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t shopId_;
} Neon_Model_Api_Rpc_ShopRandomCostumeListRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ShopRandomCostumeListRequest_VTable {
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
} Neon_Model_Api_Rpc_ShopRandomCostumeListRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ShopRandomCostumeListRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ShopRandomCostumeListRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ShopRandomCostumeListRequest_VTable vtable;
} Neon_Model_Api_Rpc_ShopRandomCostumeListRequest_c;

typedef struct Neon_Model_Api_Rpc_ShopRandomCostumeListRequest_o {
	Neon_Model_Api_Rpc_ShopRandomCostumeListRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ShopRandomCostumeListRequest_Fields fields;
} Neon_Model_Api_Rpc_ShopRandomCostumeListRequest_o;

typedef struct Neon_Model_Api_Rpc_UserLinkGoogleRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_String_o* idToken_;
	struct System_String_o* code_;
	struct System_String_o* codeVerifier_;
} Neon_Model_Api_Rpc_UserLinkGoogleRequest_Fields;

typedef struct Neon_Model_Api_Rpc_UserLinkGoogleRequest_VTable {
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
} Neon_Model_Api_Rpc_UserLinkGoogleRequest_VTable;

typedef struct Neon_Model_Api_Rpc_UserLinkGoogleRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_UserLinkGoogleRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_UserLinkGoogleRequest_VTable vtable;
} Neon_Model_Api_Rpc_UserLinkGoogleRequest_c;

typedef struct Neon_Model_Api_Rpc_UserLinkGoogleRequest_o {
	Neon_Model_Api_Rpc_UserLinkGoogleRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_UserLinkGoogleRequest_Fields fields;
} Neon_Model_Api_Rpc_UserLinkGoogleRequest_o;

typedef struct Neon_Model_Api_Rpc_DebugShopPurchaseRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t shopProductId_;
} Neon_Model_Api_Rpc_DebugShopPurchaseRequest_Fields;

typedef struct Neon_Model_Api_Rpc_DebugShopPurchaseRequest_VTable {
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
} Neon_Model_Api_Rpc_DebugShopPurchaseRequest_VTable;

typedef struct Neon_Model_Api_Rpc_DebugShopPurchaseRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_DebugShopPurchaseRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_DebugShopPurchaseRequest_VTable vtable;
} Neon_Model_Api_Rpc_DebugShopPurchaseRequest_c;

typedef struct Neon_Model_Api_Rpc_DebugShopPurchaseRequest_o {
	Neon_Model_Api_Rpc_DebugShopPurchaseRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_DebugShopPurchaseRequest_Fields fields;
} Neon_Model_Api_Rpc_DebugShopPurchaseRequest_o;

typedef struct Neon_Model_Api_Rpc_AuthSignUpGoogleRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_String_o* deviceSecret_;
	struct System_String_o* deviceUniqueId_;
	struct System_String_o* deviceModel_;
	struct System_String_o* idToken_;
	struct System_String_o* code_;
	struct System_String_o* codeVerifier_;
	bool execute_;
} Neon_Model_Api_Rpc_AuthSignUpGoogleRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AuthSignUpGoogleRequest_VTable {
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
} Neon_Model_Api_Rpc_AuthSignUpGoogleRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AuthSignUpGoogleRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AuthSignUpGoogleRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AuthSignUpGoogleRequest_VTable vtable;
} Neon_Model_Api_Rpc_AuthSignUpGoogleRequest_c;

typedef struct Neon_Model_Api_Rpc_AuthSignUpGoogleRequest_o {
	Neon_Model_Api_Rpc_AuthSignUpGoogleRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AuthSignUpGoogleRequest_Fields fields;
} Neon_Model_Api_Rpc_AuthSignUpGoogleRequest_o;

typedef struct Neon_Model_Api_Rpc_MissionCountRewardReceiveRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t missionCountRewardId_;
} Neon_Model_Api_Rpc_MissionCountRewardReceiveRequest_Fields;

typedef struct Neon_Model_Api_Rpc_MissionCountRewardReceiveRequest_VTable {
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
} Neon_Model_Api_Rpc_MissionCountRewardReceiveRequest_VTable;

typedef struct Neon_Model_Api_Rpc_MissionCountRewardReceiveRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_MissionCountRewardReceiveRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_MissionCountRewardReceiveRequest_VTable vtable;
} Neon_Model_Api_Rpc_MissionCountRewardReceiveRequest_c;

typedef struct Neon_Model_Api_Rpc_MissionCountRewardReceiveRequest_o {
	Neon_Model_Api_Rpc_MissionCountRewardReceiveRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_MissionCountRewardReceiveRequest_Fields fields;
} Neon_Model_Api_Rpc_MissionCountRewardReceiveRequest_o;

typedef struct Neon_Model_Api_Rpc_ProfileUpdateNameRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_String_o* name_;
} Neon_Model_Api_Rpc_ProfileUpdateNameRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ProfileUpdateNameRequest_VTable {
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
} Neon_Model_Api_Rpc_ProfileUpdateNameRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ProfileUpdateNameRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ProfileUpdateNameRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ProfileUpdateNameRequest_VTable vtable;
} Neon_Model_Api_Rpc_ProfileUpdateNameRequest_c;

typedef struct Neon_Model_Api_Rpc_ProfileUpdateNameRequest_o {
	Neon_Model_Api_Rpc_ProfileUpdateNameRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ProfileUpdateNameRequest_Fields fields;
} Neon_Model_Api_Rpc_ProfileUpdateNameRequest_o;

typedef struct Neon_Model_Api_Rpc_PurchaseSessionStartRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t shopProductId_;
} Neon_Model_Api_Rpc_PurchaseSessionStartRequest_Fields;

typedef struct Neon_Model_Api_Rpc_PurchaseSessionStartRequest_VTable {
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
} Neon_Model_Api_Rpc_PurchaseSessionStartRequest_VTable;

typedef struct Neon_Model_Api_Rpc_PurchaseSessionStartRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_PurchaseSessionStartRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_PurchaseSessionStartRequest_VTable vtable;
} Neon_Model_Api_Rpc_PurchaseSessionStartRequest_c;

typedef struct Neon_Model_Api_Rpc_PurchaseSessionStartRequest_o {
	Neon_Model_Api_Rpc_PurchaseSessionStartRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_PurchaseSessionStartRequest_Fields fields;
} Neon_Model_Api_Rpc_PurchaseSessionStartRequest_o;

typedef struct Neon_Model_Api_Rpc_CityReleaseGearShopRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t cityId_;
} Neon_Model_Api_Rpc_CityReleaseGearShopRequest_Fields;

typedef struct Neon_Model_Api_Rpc_CityReleaseGearShopRequest_VTable {
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
} Neon_Model_Api_Rpc_CityReleaseGearShopRequest_VTable;

typedef struct Neon_Model_Api_Rpc_CityReleaseGearShopRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_CityReleaseGearShopRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_CityReleaseGearShopRequest_VTable vtable;
} Neon_Model_Api_Rpc_CityReleaseGearShopRequest_c;

typedef struct Neon_Model_Api_Rpc_CityReleaseGearShopRequest_o {
	Neon_Model_Api_Rpc_CityReleaseGearShopRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_CityReleaseGearShopRequest_Fields fields;
} Neon_Model_Api_Rpc_CityReleaseGearShopRequest_o;

typedef struct Neon_Model_Api_Rpc_CharacterItemPresentRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t characterId_;
	int32_t itemId_;
	int32_t quantity_;
} Neon_Model_Api_Rpc_CharacterItemPresentRequest_Fields;

typedef struct Neon_Model_Api_Rpc_CharacterItemPresentRequest_VTable {
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
} Neon_Model_Api_Rpc_CharacterItemPresentRequest_VTable;

typedef struct Neon_Model_Api_Rpc_CharacterItemPresentRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_CharacterItemPresentRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_CharacterItemPresentRequest_VTable vtable;
} Neon_Model_Api_Rpc_CharacterItemPresentRequest_c;

typedef struct Neon_Model_Api_Rpc_CharacterItemPresentRequest_o {
	Neon_Model_Api_Rpc_CharacterItemPresentRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_CharacterItemPresentRequest_Fields fields;
} Neon_Model_Api_Rpc_CharacterItemPresentRequest_o;

typedef struct Neon_Model_Api_Rpc_SeasonPassReceiveRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t seasonId_;
	int32_t seasonPassTierId_;
	int32_t seasonPassType_;
} Neon_Model_Api_Rpc_SeasonPassReceiveRequest_Fields;

typedef struct Neon_Model_Api_Rpc_SeasonPassReceiveRequest_VTable {
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
} Neon_Model_Api_Rpc_SeasonPassReceiveRequest_VTable;

typedef struct Neon_Model_Api_Rpc_SeasonPassReceiveRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_SeasonPassReceiveRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_SeasonPassReceiveRequest_VTable vtable;
} Neon_Model_Api_Rpc_SeasonPassReceiveRequest_c;

typedef struct Neon_Model_Api_Rpc_SeasonPassReceiveRequest_o {
	Neon_Model_Api_Rpc_SeasonPassReceiveRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_SeasonPassReceiveRequest_Fields fields;
} Neon_Model_Api_Rpc_SeasonPassReceiveRequest_o;

typedef struct Neon_Model_Api_Rpc_RuledBattleStartRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t ruledBattleId_;
} Neon_Model_Api_Rpc_RuledBattleStartRequest_Fields;

typedef struct Neon_Model_Api_Rpc_RuledBattleStartRequest_VTable {
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
} Neon_Model_Api_Rpc_RuledBattleStartRequest_VTable;

typedef struct Neon_Model_Api_Rpc_RuledBattleStartRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_RuledBattleStartRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_RuledBattleStartRequest_VTable vtable;
} Neon_Model_Api_Rpc_RuledBattleStartRequest_c;

typedef struct Neon_Model_Api_Rpc_RuledBattleStartRequest_o {
	Neon_Model_Api_Rpc_RuledBattleStartRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_RuledBattleStartRequest_Fields fields;
} Neon_Model_Api_Rpc_RuledBattleStartRequest_o;

typedef struct Neon_Model_Api_Rpc_ProfileUpdateBannerRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t profileBannerId_;
} Neon_Model_Api_Rpc_ProfileUpdateBannerRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ProfileUpdateBannerRequest_VTable {
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
} Neon_Model_Api_Rpc_ProfileUpdateBannerRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ProfileUpdateBannerRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ProfileUpdateBannerRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ProfileUpdateBannerRequest_VTable vtable;
} Neon_Model_Api_Rpc_ProfileUpdateBannerRequest_c;

typedef struct Neon_Model_Api_Rpc_ProfileUpdateBannerRequest_o {
	Neon_Model_Api_Rpc_ProfileUpdateBannerRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ProfileUpdateBannerRequest_Fields fields;
} Neon_Model_Api_Rpc_ProfileUpdateBannerRequest_o;

typedef struct Neon_Model_Api_Rpc_GachaSelectRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t gachaId_;
	int32_t gachaCardId_;
} Neon_Model_Api_Rpc_GachaSelectRequest_Fields;

typedef struct Neon_Model_Api_Rpc_GachaSelectRequest_VTable {
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
} Neon_Model_Api_Rpc_GachaSelectRequest_VTable;

typedef struct Neon_Model_Api_Rpc_GachaSelectRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_GachaSelectRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_GachaSelectRequest_VTable vtable;
} Neon_Model_Api_Rpc_GachaSelectRequest_c;

typedef struct Neon_Model_Api_Rpc_GachaSelectRequest_o {
	Neon_Model_Api_Rpc_GachaSelectRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_GachaSelectRequest_Fields fields;
} Neon_Model_Api_Rpc_GachaSelectRequest_o;

typedef struct Neon_Model_Api_Rpc_StaminaPurchaseRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t count_;
} Neon_Model_Api_Rpc_StaminaPurchaseRequest_Fields;

typedef struct Neon_Model_Api_Rpc_StaminaPurchaseRequest_VTable {
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
} Neon_Model_Api_Rpc_StaminaPurchaseRequest_VTable;

typedef struct Neon_Model_Api_Rpc_StaminaPurchaseRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_StaminaPurchaseRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_StaminaPurchaseRequest_VTable vtable;
} Neon_Model_Api_Rpc_StaminaPurchaseRequest_c;

typedef struct Neon_Model_Api_Rpc_StaminaPurchaseRequest_o {
	Neon_Model_Api_Rpc_StaminaPurchaseRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_StaminaPurchaseRequest_Fields fields;
} Neon_Model_Api_Rpc_StaminaPurchaseRequest_o;

typedef struct Neon_Model_Api_Rpc_NewsListRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t language_;
} Neon_Model_Api_Rpc_NewsListRequest_Fields;

typedef struct Neon_Model_Api_Rpc_NewsListRequest_VTable {
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
} Neon_Model_Api_Rpc_NewsListRequest_VTable;

typedef struct Neon_Model_Api_Rpc_NewsListRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_NewsListRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_NewsListRequest_VTable vtable;
} Neon_Model_Api_Rpc_NewsListRequest_c;

typedef struct Neon_Model_Api_Rpc_NewsListRequest_o {
	Neon_Model_Api_Rpc_NewsListRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_NewsListRequest_Fields fields;
} Neon_Model_Api_Rpc_NewsListRequest_o;

typedef struct Neon_Model_Api_Rpc_DishOrderRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t dishId_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
} Neon_Model_Api_Rpc_DishOrderRequest_Fields;

typedef struct Neon_Model_Api_Rpc_DishOrderRequest_VTable {
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
} Neon_Model_Api_Rpc_DishOrderRequest_VTable;

typedef struct Neon_Model_Api_Rpc_DishOrderRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_DishOrderRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_DishOrderRequest_VTable vtable;
} Neon_Model_Api_Rpc_DishOrderRequest_c;

typedef struct Neon_Model_Api_Rpc_DishOrderRequest_o {
	Neon_Model_Api_Rpc_DishOrderRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_DishOrderRequest_Fields fields;
} Neon_Model_Api_Rpc_DishOrderRequest_o;

typedef struct Neon_Model_Api_Rpc_ProfileUpdateBadgesRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* profileBadgeIds_;
} Neon_Model_Api_Rpc_ProfileUpdateBadgesRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ProfileUpdateBadgesRequest_VTable {
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
} Neon_Model_Api_Rpc_ProfileUpdateBadgesRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ProfileUpdateBadgesRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ProfileUpdateBadgesRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ProfileUpdateBadgesRequest_VTable vtable;
} Neon_Model_Api_Rpc_ProfileUpdateBadgesRequest_c;

typedef struct Neon_Model_Api_Rpc_ProfileUpdateBadgesRequest_o {
	Neon_Model_Api_Rpc_ProfileUpdateBadgesRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ProfileUpdateBadgesRequest_Fields fields;
} Neon_Model_Api_Rpc_ProfileUpdateBadgesRequest_o;

typedef struct Neon_Model_Api_Rpc_TensionCardLockRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* entityIds_;
	bool isLock_;
} Neon_Model_Api_Rpc_TensionCardLockRequest_Fields;

typedef struct Neon_Model_Api_Rpc_TensionCardLockRequest_VTable {
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
} Neon_Model_Api_Rpc_TensionCardLockRequest_VTable;

typedef struct Neon_Model_Api_Rpc_TensionCardLockRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_TensionCardLockRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_TensionCardLockRequest_VTable vtable;
} Neon_Model_Api_Rpc_TensionCardLockRequest_c;

typedef struct Neon_Model_Api_Rpc_TensionCardLockRequest_o {
	Neon_Model_Api_Rpc_TensionCardLockRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_TensionCardLockRequest_Fields fields;
} Neon_Model_Api_Rpc_TensionCardLockRequest_o;

typedef struct Neon_Model_Api_Rpc_DungeonBattleSkipRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t dungeonDifficultyId_;
	int32_t entityId_;
	struct Google_Protobuf_Collections_RepeatedField_int__o* lineCharacterIds_;
} Neon_Model_Api_Rpc_DungeonBattleSkipRequest_Fields;

typedef struct Neon_Model_Api_Rpc_DungeonBattleSkipRequest_VTable {
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
} Neon_Model_Api_Rpc_DungeonBattleSkipRequest_VTable;

typedef struct Neon_Model_Api_Rpc_DungeonBattleSkipRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_DungeonBattleSkipRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_DungeonBattleSkipRequest_VTable vtable;
} Neon_Model_Api_Rpc_DungeonBattleSkipRequest_c;

typedef struct Neon_Model_Api_Rpc_DungeonBattleSkipRequest_o {
	Neon_Model_Api_Rpc_DungeonBattleSkipRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_DungeonBattleSkipRequest_Fields fields;
} Neon_Model_Api_Rpc_DungeonBattleSkipRequest_o;

typedef struct Neon_Model_Api_Rpc_FractalViseBattleStartBossBattleRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t fractalViseId_;
	int32_t fractalViseBossDifficultyId_;
	struct Google_Protobuf_Collections_RepeatedField_int__o* lineCharacterIds_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
	struct Neon_Model_Api_Model_BloodStainLocation_o* bloodStainLocation_;
} Neon_Model_Api_Rpc_FractalViseBattleStartBossBattleRequest_Fields;

typedef struct Neon_Model_Api_Rpc_FractalViseBattleStartBossBattleRequest_VTable {
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
} Neon_Model_Api_Rpc_FractalViseBattleStartBossBattleRequest_VTable;

typedef struct Neon_Model_Api_Rpc_FractalViseBattleStartBossBattleRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_FractalViseBattleStartBossBattleRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_FractalViseBattleStartBossBattleRequest_VTable vtable;
} Neon_Model_Api_Rpc_FractalViseBattleStartBossBattleRequest_c;

typedef struct Neon_Model_Api_Rpc_FractalViseBattleStartBossBattleRequest_o {
	Neon_Model_Api_Rpc_FractalViseBattleStartBossBattleRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_FractalViseBattleStartBossBattleRequest_Fields fields;
} Neon_Model_Api_Rpc_FractalViseBattleStartBossBattleRequest_o;

typedef struct Neon_Model_Api_Rpc_FractalViseRewardsTopRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
} Neon_Model_Api_Rpc_FractalViseRewardsTopRequest_Fields;

typedef struct Neon_Model_Api_Rpc_FractalViseRewardsTopRequest_VTable {
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
} Neon_Model_Api_Rpc_FractalViseRewardsTopRequest_VTable;

typedef struct Neon_Model_Api_Rpc_FractalViseRewardsTopRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_FractalViseRewardsTopRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_FractalViseRewardsTopRequest_VTable vtable;
} Neon_Model_Api_Rpc_FractalViseRewardsTopRequest_c;

typedef struct Neon_Model_Api_Rpc_FractalViseRewardsTopRequest_o {
	Neon_Model_Api_Rpc_FractalViseRewardsTopRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_FractalViseRewardsTopRequest_Fields fields;
} Neon_Model_Api_Rpc_FractalViseRewardsTopRequest_o;

typedef struct Neon_Model_Api_Rpc_AuthSignUpAppleRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_String_o* deviceSecret_;
	struct System_String_o* deviceUniqueId_;
	struct System_String_o* deviceModel_;
	struct System_String_o* idToken_;
	bool execute_;
} Neon_Model_Api_Rpc_AuthSignUpAppleRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AuthSignUpAppleRequest_VTable {
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
} Neon_Model_Api_Rpc_AuthSignUpAppleRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AuthSignUpAppleRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AuthSignUpAppleRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AuthSignUpAppleRequest_VTable vtable;
} Neon_Model_Api_Rpc_AuthSignUpAppleRequest_c;

typedef struct Neon_Model_Api_Rpc_AuthSignUpAppleRequest_o {
	Neon_Model_Api_Rpc_AuthSignUpAppleRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AuthSignUpAppleRequest_Fields fields;
} Neon_Model_Api_Rpc_AuthSignUpAppleRequest_o;

typedef struct Neon_Model_Api_Rpc_HappyWorkerListRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
} Neon_Model_Api_Rpc_HappyWorkerListRequest_Fields;

typedef struct Neon_Model_Api_Rpc_HappyWorkerListRequest_VTable {
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
} Neon_Model_Api_Rpc_HappyWorkerListRequest_VTable;

typedef struct Neon_Model_Api_Rpc_HappyWorkerListRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_HappyWorkerListRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_HappyWorkerListRequest_VTable vtable;
} Neon_Model_Api_Rpc_HappyWorkerListRequest_c;

typedef struct Neon_Model_Api_Rpc_HappyWorkerListRequest_o {
	Neon_Model_Api_Rpc_HappyWorkerListRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_HappyWorkerListRequest_Fields fields;
} Neon_Model_Api_Rpc_HappyWorkerListRequest_o;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleSkipResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_BattleSkipResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_BattleSkipResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleSkipResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_BattleSkipResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleSkipResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_BattleSkipResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_BattleSkipResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleSkipResponse__o {
	Cysharp_Threading_Tasks_UniTask_BattleSkipResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_BattleSkipResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureFindGraffitiResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_AdventureFindGraffitiResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_AdventureFindGraffitiResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureFindGraffitiResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_AdventureFindGraffitiResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureFindGraffitiResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_AdventureFindGraffitiResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_AdventureFindGraffitiResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureFindGraffitiResponse__o {
	Cysharp_Threading_Tasks_UniTask_AdventureFindGraffitiResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_AdventureFindGraffitiResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignUpResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_AuthSignUpResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_AuthSignUpResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignUpResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_AuthSignUpResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignUpResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_AuthSignUpResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_AuthSignUpResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignUpResponse__o {
	Cysharp_Threading_Tasks_UniTask_AuthSignUpResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_AuthSignUpResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignUpAppleResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_AuthSignUpAppleResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_AuthSignUpAppleResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignUpAppleResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_AuthSignUpAppleResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignUpAppleResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_AuthSignUpAppleResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_AuthSignUpAppleResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignUpAppleResponse__o {
	Cysharp_Threading_Tasks_UniTask_AuthSignUpAppleResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_AuthSignUpAppleResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignUpGoogleResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_AuthSignUpGoogleResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_AuthSignUpGoogleResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignUpGoogleResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_AuthSignUpGoogleResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignUpGoogleResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_AuthSignUpGoogleResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_AuthSignUpGoogleResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignUpGoogleResponse__o {
	Cysharp_Threading_Tasks_UniTask_AuthSignUpGoogleResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_AuthSignUpGoogleResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignUpPasscodeResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_AuthSignUpPasscodeResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_AuthSignUpPasscodeResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignUpPasscodeResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_AuthSignUpPasscodeResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignUpPasscodeResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_AuthSignUpPasscodeResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_AuthSignUpPasscodeResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignUpPasscodeResponse__o {
	Cysharp_Threading_Tasks_UniTask_AuthSignUpPasscodeResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_AuthSignUpPasscodeResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleRestartResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_BattleRestartResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_BattleRestartResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleRestartResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_BattleRestartResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleRestartResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_BattleRestartResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_BattleRestartResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleRestartResponse__o {
	Cysharp_Threading_Tasks_UniTask_BattleRestartResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_BattleRestartResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_CharacterRankEnhanceResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_CharacterRankEnhanceResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_CharacterRankEnhanceResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_CharacterRankEnhanceResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_CharacterRankEnhanceResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_CharacterRankEnhanceResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_CharacterRankEnhanceResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_CharacterRankEnhanceResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_CharacterRankEnhanceResponse__o {
	Cysharp_Threading_Tasks_UniTask_CharacterRankEnhanceResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_CharacterRankEnhanceResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_CharacterLimitBreakResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_CharacterLimitBreakResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_CharacterLimitBreakResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_CharacterLimitBreakResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_CharacterLimitBreakResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_CharacterLimitBreakResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_CharacterLimitBreakResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_CharacterLimitBreakResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_CharacterLimitBreakResponse__o {
	Cysharp_Threading_Tasks_UniTask_CharacterLimitBreakResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_CharacterLimitBreakResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelEnhanceResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_CharacterSkillPanelEnhanceResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelEnhanceResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelEnhanceResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelEnhanceResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelEnhanceResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelEnhanceResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelEnhanceResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelEnhanceResponse__o {
	Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelEnhanceResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelEnhanceResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelResetResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_CharacterSkillPanelResetResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelResetResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelResetResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelResetResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelResetResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelResetResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelResetResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelResetResponse__o {
	Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelResetResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_CharacterSkillPanelResetResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_DebugJiraTokenResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_DebugJiraTokenResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_DebugJiraTokenResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_DebugJiraTokenResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_DebugJiraTokenResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_DebugJiraTokenResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_DebugJiraTokenResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_DebugJiraTokenResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_DebugJiraTokenResponse__o {
	Cysharp_Threading_Tasks_UniTask_DebugJiraTokenResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_DebugJiraTokenResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_DebugChallengeClearResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_DebugChallengeClearResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_DebugChallengeClearResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_DebugChallengeClearResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_DebugChallengeClearResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_DebugChallengeClearResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_DebugChallengeClearResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_DebugChallengeClearResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_DebugChallengeClearResponse__o {
	Cysharp_Threading_Tasks_UniTask_DebugChallengeClearResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_DebugChallengeClearResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonEntryResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_DungeonEntryResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_DungeonEntryResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonEntryResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_DungeonEntryResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonEntryResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_DungeonEntryResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_DungeonEntryResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonEntryResponse__o {
	Cysharp_Threading_Tasks_UniTask_DungeonEntryResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_DungeonEntryResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonStartResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_DungeonStartResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_DungeonStartResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonStartResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_DungeonStartResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonStartResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_DungeonStartResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_DungeonStartResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonStartResponse__o {
	Cysharp_Threading_Tasks_UniTask_DungeonStartResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_DungeonStartResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonResumeResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_DungeonResumeResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_DungeonResumeResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonResumeResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_DungeonResumeResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonResumeResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_DungeonResumeResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_DungeonResumeResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonResumeResponse__o {
	Cysharp_Threading_Tasks_UniTask_DungeonResumeResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_DungeonResumeResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonAcquireAreaItemResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_DungeonAcquireAreaItemResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_DungeonAcquireAreaItemResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonAcquireAreaItemResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_DungeonAcquireAreaItemResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonAcquireAreaItemResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_DungeonAcquireAreaItemResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_DungeonAcquireAreaItemResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonAcquireAreaItemResponse__o {
	Cysharp_Threading_Tasks_UniTask_DungeonAcquireAreaItemResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_DungeonAcquireAreaItemResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_EventFinishNodeResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_EventFinishNodeResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_EventFinishNodeResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_EventFinishNodeResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_EventFinishNodeResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_EventFinishNodeResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_EventFinishNodeResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_EventFinishNodeResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_EventFinishNodeResponse__o {
	Cysharp_Threading_Tasks_UniTask_EventFinishNodeResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_EventFinishNodeResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_FieldBossEntryResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_FieldBossEntryResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_FieldBossEntryResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_FieldBossEntryResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_FieldBossEntryResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_FieldBossEntryResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_FieldBossEntryResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_FieldBossEntryResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_FieldBossEntryResponse__o {
	Cysharp_Threading_Tasks_UniTask_FieldBossEntryResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_FieldBossEntryResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowListResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_FollowListResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_FollowListResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowListResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_FollowListResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowListResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_FollowListResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_FollowListResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowListResponse__o {
	Cysharp_Threading_Tasks_UniTask_FollowListResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_FollowListResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowDetailResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_FollowDetailResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_FollowDetailResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowDetailResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_FollowDetailResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowDetailResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_FollowDetailResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_FollowDetailResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowDetailResponse__o {
	Cysharp_Threading_Tasks_UniTask_FollowDetailResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_FollowDetailResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowSearchResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_FollowSearchResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_FollowSearchResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowSearchResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_FollowSearchResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowSearchResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_FollowSearchResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_FollowSearchResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowSearchResponse__o {
	Cysharp_Threading_Tasks_UniTask_FollowSearchResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_FollowSearchResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowAddResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_FollowAddResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_FollowAddResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowAddResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_FollowAddResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowAddResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_FollowAddResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_FollowAddResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowAddResponse__o {
	Cysharp_Threading_Tasks_UniTask_FollowAddResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_FollowAddResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowRemoveResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_FollowRemoveResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_FollowRemoveResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowRemoveResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_FollowRemoveResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowRemoveResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_FollowRemoveResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_FollowRemoveResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_FollowRemoveResponse__o {
	Cysharp_Threading_Tasks_UniTask_FollowRemoveResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_FollowRemoveResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseRewardsTopResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_FractalViseRewardsTopResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_FractalViseRewardsTopResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseRewardsTopResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_FractalViseRewardsTopResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseRewardsTopResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_FractalViseRewardsTopResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_FractalViseRewardsTopResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseRewardsTopResponse__o {
	Cysharp_Threading_Tasks_UniTask_FractalViseRewardsTopResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_FractalViseRewardsTopResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseRewardsReceiveResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_FractalViseRewardsReceiveResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_FractalViseRewardsReceiveResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseRewardsReceiveResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_FractalViseRewardsReceiveResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseRewardsReceiveResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_FractalViseRewardsReceiveResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_FractalViseRewardsReceiveResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseRewardsReceiveResponse__o {
	Cysharp_Threading_Tasks_UniTask_FractalViseRewardsReceiveResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_FractalViseRewardsReceiveResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseStartResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_FractalViseStartResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_FractalViseStartResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseStartResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_FractalViseStartResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseStartResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_FractalViseStartResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_FractalViseStartResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseStartResponse__o {
	Cysharp_Threading_Tasks_UniTask_FractalViseStartResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_FractalViseStartResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseNextAreaResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_FractalViseNextAreaResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_FractalViseNextAreaResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseNextAreaResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_FractalViseNextAreaResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseNextAreaResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_FractalViseNextAreaResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_FractalViseNextAreaResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseNextAreaResponse__o {
	Cysharp_Threading_Tasks_UniTask_FractalViseNextAreaResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_FractalViseNextAreaResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseResumeResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_FractalViseResumeResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_FractalViseResumeResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseResumeResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_FractalViseResumeResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseResumeResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_FractalViseResumeResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_FractalViseResumeResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseResumeResponse__o {
	Cysharp_Threading_Tasks_UniTask_FractalViseResumeResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_FractalViseResumeResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseClearResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_FractalViseClearResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_FractalViseClearResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseClearResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_FractalViseClearResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseClearResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_FractalViseClearResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_FractalViseClearResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseClearResponse__o {
	Cysharp_Threading_Tasks_UniTask_FractalViseClearResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_FractalViseClearResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseRetireResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_FractalViseRetireResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_FractalViseRetireResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseRetireResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_FractalViseRetireResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseRetireResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_FractalViseRetireResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_FractalViseRetireResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseRetireResponse__o {
	Cysharp_Threading_Tasks_UniTask_FractalViseRetireResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_FractalViseRetireResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseBossDifficultyResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_FractalViseBossDifficultyResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_FractalViseBossDifficultyResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseBossDifficultyResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_FractalViseBossDifficultyResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseBossDifficultyResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_FractalViseBossDifficultyResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_FractalViseBossDifficultyResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_FractalViseBossDifficultyResponse__o {
	Cysharp_Threading_Tasks_UniTask_FractalViseBossDifficultyResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_FractalViseBossDifficultyResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_GachaExecuteResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_GachaExecuteResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_GachaExecuteResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_GachaExecuteResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_GachaExecuteResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_GachaExecuteResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_GachaExecuteResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_GachaExecuteResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_GachaExecuteResponse__o {
	Cysharp_Threading_Tasks_UniTask_GachaExecuteResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_GachaExecuteResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_GachaSelectResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_GachaSelectResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_GachaSelectResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_GachaSelectResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_GachaSelectResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_GachaSelectResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_GachaSelectResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_GachaSelectResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_GachaSelectResponse__o {
	Cysharp_Threading_Tasks_UniTask_GachaSelectResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_GachaSelectResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_GearCompressResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_GearCompressResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_GearCompressResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_GearCompressResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_GearCompressResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_GearCompressResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_GearCompressResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_GearCompressResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_GearCompressResponse__o {
	Cysharp_Threading_Tasks_UniTask_GearCompressResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_GearCompressResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_HappyWorkerListResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_HappyWorkerListResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_HappyWorkerListResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_HappyWorkerListResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_HappyWorkerListResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_HappyWorkerListResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_HappyWorkerListResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_HappyWorkerListResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_HappyWorkerListResponse__o {
	Cysharp_Threading_Tasks_UniTask_HappyWorkerListResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_HappyWorkerListResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_HappyWorkerStartResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_HappyWorkerStartResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_HappyWorkerStartResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_HappyWorkerStartResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_HappyWorkerStartResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_HappyWorkerStartResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_HappyWorkerStartResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_HappyWorkerStartResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_HappyWorkerStartResponse__o {
	Cysharp_Threading_Tasks_UniTask_HappyWorkerStartResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_HappyWorkerStartResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_HappyWorkerCancelResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_HappyWorkerCancelResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_HappyWorkerCancelResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_HappyWorkerCancelResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_HappyWorkerCancelResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_HappyWorkerCancelResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_HappyWorkerCancelResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_HappyWorkerCancelResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_HappyWorkerCancelResponse__o {
	Cysharp_Threading_Tasks_UniTask_HappyWorkerCancelResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_HappyWorkerCancelResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestListResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_ItemRequestListResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_ItemRequestListResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestListResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_ItemRequestListResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestListResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_ItemRequestListResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_ItemRequestListResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestListResponse__o {
	Cysharp_Threading_Tasks_UniTask_ItemRequestListResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_ItemRequestListResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestGetResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_ItemRequestGetResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_ItemRequestGetResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestGetResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_ItemRequestGetResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestGetResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_ItemRequestGetResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_ItemRequestGetResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestGetResponse__o {
	Cysharp_Threading_Tasks_UniTask_ItemRequestGetResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_ItemRequestGetResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestPublishResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_ItemRequestPublishResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_ItemRequestPublishResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestPublishResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_ItemRequestPublishResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestPublishResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_ItemRequestPublishResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_ItemRequestPublishResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestPublishResponse__o {
	Cysharp_Threading_Tasks_UniTask_ItemRequestPublishResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_ItemRequestPublishResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestFulfillResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_ItemRequestFulfillResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_ItemRequestFulfillResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestFulfillResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_ItemRequestFulfillResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestFulfillResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_ItemRequestFulfillResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_ItemRequestFulfillResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestFulfillResponse__o {
	Cysharp_Threading_Tasks_UniTask_ItemRequestFulfillResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_ItemRequestFulfillResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestCollectResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_ItemRequestCollectResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_ItemRequestCollectResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestCollectResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_ItemRequestCollectResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestCollectResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_ItemRequestCollectResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_ItemRequestCollectResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemRequestCollectResponse__o {
	Cysharp_Threading_Tasks_UniTask_ItemRequestCollectResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_ItemRequestCollectResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_LoginBonusReceiveResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_LoginBonusReceiveResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_LoginBonusReceiveResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_LoginBonusReceiveResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_LoginBonusReceiveResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_LoginBonusReceiveResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_LoginBonusReceiveResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_LoginBonusReceiveResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_LoginBonusReceiveResponse__o {
	Cysharp_Threading_Tasks_UniTask_LoginBonusReceiveResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_LoginBonusReceiveResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_MailListResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_MailListResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_MailListResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_MailListResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_MailListResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_MailListResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_MailListResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_MailListResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_MailListResponse__o {
	Cysharp_Threading_Tasks_UniTask_MailListResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_MailListResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_MailOpenResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_MailOpenResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_MailOpenResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_MailOpenResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_MailOpenResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_MailOpenResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_MailOpenResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_MailOpenResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_MailOpenResponse__o {
	Cysharp_Threading_Tasks_UniTask_MailOpenResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_MailOpenResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_MailDeleteResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_MailDeleteResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_MailDeleteResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_MailDeleteResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_MailDeleteResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_MailDeleteResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_MailDeleteResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_MailDeleteResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_MailDeleteResponse__o {
	Cysharp_Threading_Tasks_UniTask_MailDeleteResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_MailDeleteResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_MissionReceiveResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_MissionReceiveResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_MissionReceiveResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_MissionReceiveResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_MissionReceiveResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_MissionReceiveResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_MissionReceiveResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_MissionReceiveResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_MissionReceiveResponse__o {
	Cysharp_Threading_Tasks_UniTask_MissionReceiveResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_MissionReceiveResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_MissionCountRewardReceiveResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_MissionCountRewardReceiveResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_MissionCountRewardReceiveResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_MissionCountRewardReceiveResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_MissionCountRewardReceiveResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_MissionCountRewardReceiveResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_MissionCountRewardReceiveResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_MissionCountRewardReceiveResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_MissionCountRewardReceiveResponse__o {
	Cysharp_Threading_Tasks_UniTask_MissionCountRewardReceiveResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_MissionCountRewardReceiveResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_NewsListResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_NewsListResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_NewsListResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_NewsListResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_NewsListResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_NewsListResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_NewsListResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_NewsListResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_NewsListResponse__o {
	Cysharp_Threading_Tasks_UniTask_NewsListResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_NewsListResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_NewsUserListResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_NewsUserListResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_NewsUserListResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_NewsUserListResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_NewsUserListResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_NewsUserListResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_NewsUserListResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_NewsUserListResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_NewsUserListResponse__o {
	Cysharp_Threading_Tasks_UniTask_NewsUserListResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_NewsUserListResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_PurchaseSessionStartResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_PurchaseSessionStartResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_PurchaseSessionStartResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_PurchaseSessionStartResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_PurchaseSessionStartResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_PurchaseSessionStartResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_PurchaseSessionStartResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_PurchaseSessionStartResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_PurchaseSessionStartResponse__o {
	Cysharp_Threading_Tasks_UniTask_PurchaseSessionStartResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_PurchaseSessionStartResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_PurchaseHistoryResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_PurchaseHistoryResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_PurchaseHistoryResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_PurchaseHistoryResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_PurchaseHistoryResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_PurchaseHistoryResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_PurchaseHistoryResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_PurchaseHistoryResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_PurchaseHistoryResponse__o {
	Cysharp_Threading_Tasks_UniTask_PurchaseHistoryResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_PurchaseHistoryResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationGetResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_RefundApplicationGetResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationGetResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationGetResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationGetResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationGetResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_RefundApplicationGetResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationGetResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationGetResponse__o {
	Cysharp_Threading_Tasks_UniTask_RefundApplicationGetResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationGetResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationUpdateEmailIdResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_RefundApplicationUpdateEmailIdResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationUpdateEmailIdResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationUpdateEmailIdResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationUpdateEmailIdResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationUpdateEmailIdResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_RefundApplicationUpdateEmailIdResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationUpdateEmailIdResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationUpdateEmailIdResponse__o {
	Cysharp_Threading_Tasks_UniTask_RefundApplicationUpdateEmailIdResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationUpdateEmailIdResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationSendVerificationCodeResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_RefundApplicationSendVerificationCodeResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationSendVerificationCodeResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationSendVerificationCodeResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationSendVerificationCodeResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationSendVerificationCodeResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_RefundApplicationSendVerificationCodeResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationSendVerificationCodeResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationSendVerificationCodeResponse__o {
	Cysharp_Threading_Tasks_UniTask_RefundApplicationSendVerificationCodeResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationSendVerificationCodeResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationVerifyEmailIdResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_RefundApplicationVerifyEmailIdResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationVerifyEmailIdResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationVerifyEmailIdResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationVerifyEmailIdResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationVerifyEmailIdResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_RefundApplicationVerifyEmailIdResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationVerifyEmailIdResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationVerifyEmailIdResponse__o {
	Cysharp_Threading_Tasks_UniTask_RefundApplicationVerifyEmailIdResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationVerifyEmailIdResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationRequestRefundResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_RefundApplicationRequestRefundResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationRequestRefundResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationRequestRefundResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationRequestRefundResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationRequestRefundResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_RefundApplicationRequestRefundResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationRequestRefundResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_RefundApplicationRequestRefundResponse__o {
	Cysharp_Threading_Tasks_UniTask_RefundApplicationRequestRefundResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_RefundApplicationRequestRefundResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_SeasonPassReceiveResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveResponse__o {
	Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveAllResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_SeasonPassReceiveAllResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveAllResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveAllResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveAllResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveAllResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveAllResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveAllResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveAllResponse__o {
	Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveAllResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_SeasonPassReceiveAllResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_SeasonPassPurchasePaidPassResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_SeasonPassPurchasePaidPassResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_SeasonPassPurchasePaidPassResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_SeasonPassPurchasePaidPassResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_SeasonPassPurchasePaidPassResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_SeasonPassPurchasePaidPassResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_SeasonPassPurchasePaidPassResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_SeasonPassPurchasePaidPassResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_SeasonPassPurchasePaidPassResponse__o {
	Cysharp_Threading_Tasks_UniTask_SeasonPassPurchasePaidPassResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_SeasonPassPurchasePaidPassResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_ShopGemListResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_ShopGemListResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_ShopGemListResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_ShopGemListResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_ShopGemListResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_ShopGemListResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_ShopGemListResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_ShopGemListResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_ShopGemListResponse__o {
	Cysharp_Threading_Tasks_UniTask_ShopGemListResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_ShopGemListResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_ShopGearShopListResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_ShopGearShopListResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_ShopGearShopListResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_ShopGearShopListResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_ShopGearShopListResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_ShopGearShopListResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_ShopGearShopListResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_ShopGearShopListResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_ShopGearShopListResponse__o {
	Cysharp_Threading_Tasks_UniTask_ShopGearShopListResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_ShopGearShopListResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_ShopGearShopPurchaseResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_ShopGearShopPurchaseResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_ShopGearShopPurchaseResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_ShopGearShopPurchaseResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_ShopGearShopPurchaseResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_ShopGearShopPurchaseResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_ShopGearShopPurchaseResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_ShopGearShopPurchaseResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_ShopGearShopPurchaseResponse__o {
	Cysharp_Threading_Tasks_UniTask_ShopGearShopPurchaseResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_ShopGearShopPurchaseResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_ShopRandomCostumeListResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_ShopRandomCostumeListResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_ShopRandomCostumeListResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_ShopRandomCostumeListResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_ShopRandomCostumeListResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_ShopRandomCostumeListResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_ShopRandomCostumeListResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_ShopRandomCostumeListResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_ShopRandomCostumeListResponse__o {
	Cysharp_Threading_Tasks_UniTask_ShopRandomCostumeListResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_ShopRandomCostumeListResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_SubsystemStatusResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_SubsystemStatusResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_SubsystemStatusResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_SubsystemStatusResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_SubsystemStatusResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_SubsystemStatusResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_SubsystemStatusResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_SubsystemStatusResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_SubsystemStatusResponse__o {
	Cysharp_Threading_Tasks_UniTask_SubsystemStatusResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_SubsystemStatusResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_TensionCardLimitBreakEnhanceResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_TensionCardLimitBreakEnhanceResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_TensionCardLimitBreakEnhanceResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_TensionCardLimitBreakEnhanceResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_TensionCardLimitBreakEnhanceResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_TensionCardLimitBreakEnhanceResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_TensionCardLimitBreakEnhanceResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_TensionCardLimitBreakEnhanceResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_TensionCardLimitBreakEnhanceResponse__o {
	Cysharp_Threading_Tasks_UniTask_TensionCardLimitBreakEnhanceResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_TensionCardLimitBreakEnhanceResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_TensionCardDisassembleResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_TensionCardDisassembleResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_TensionCardDisassembleResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_TensionCardDisassembleResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_TensionCardDisassembleResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_TensionCardDisassembleResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_TensionCardDisassembleResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_TensionCardDisassembleResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_TensionCardDisassembleResponse__o {
	Cysharp_Threading_Tasks_UniTask_TensionCardDisassembleResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_TensionCardDisassembleResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_TrialBattleRewardReceiveResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_TrialBattleRewardReceiveResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_TrialBattleRewardReceiveResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_TrialBattleRewardReceiveResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_TrialBattleRewardReceiveResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_TrialBattleRewardReceiveResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_TrialBattleRewardReceiveResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_TrialBattleRewardReceiveResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_TrialBattleRewardReceiveResponse__o {
	Cysharp_Threading_Tasks_UniTask_TrialBattleRewardReceiveResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_TrialBattleRewardReceiveResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_TutorialSkipResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_TutorialSkipResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_TutorialSkipResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_TutorialSkipResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_TutorialSkipResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_TutorialSkipResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_TutorialSkipResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_TutorialSkipResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_TutorialSkipResponse__o {
	Cysharp_Threading_Tasks_UniTask_TutorialSkipResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_TutorialSkipResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_UserLinksListResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_UserLinksListResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_UserLinksListResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_UserLinksListResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_UserLinksListResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_UserLinksListResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_UserLinksListResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_UserLinksListResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_UserLinksListResponse__o {
	Cysharp_Threading_Tasks_UniTask_UserLinksListResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_UserLinksListResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_UserDeleteResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_UserDeleteResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_UserDeleteResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_UserDeleteResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_UserDeleteResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_UserDeleteResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_UserDeleteResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_UserDeleteResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_UserDeleteResponse__o {
	Cysharp_Threading_Tasks_UniTask_UserDeleteResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_UserDeleteResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_WebSessionTokenResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_WebSessionTokenResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_WebSessionTokenResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_WebSessionTokenResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_WebSessionTokenResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_WebSessionTokenResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_WebSessionTokenResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_WebSessionTokenResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_WebSessionTokenResponse__o {
	Cysharp_Threading_Tasks_UniTask_WebSessionTokenResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_WebSessionTokenResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_XbFormationUpdateResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_XbFormationUpdateResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_XbFormationUpdateResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_XbFormationUpdateResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_XbFormationUpdateResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_XbFormationUpdateResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_XbFormationUpdateResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_XbFormationUpdateResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_XbFormationUpdateResponse__o {
	Cysharp_Threading_Tasks_UniTask_XbFormationUpdateResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_XbFormationUpdateResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_XbAddCommandUnlockItemResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_XbAddCommandUnlockItemResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_XbAddCommandUnlockItemResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_XbAddCommandUnlockItemResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_XbAddCommandUnlockItemResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_XbAddCommandUnlockItemResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_XbAddCommandUnlockItemResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_XbAddCommandUnlockItemResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_XbAddCommandUnlockItemResponse__o {
	Cysharp_Threading_Tasks_UniTask_XbAddCommandUnlockItemResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_XbAddCommandUnlockItemResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_XbUpdateSkillOrbStatusResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_XbUpdateSkillOrbStatusResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_XbUpdateSkillOrbStatusResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_XbUpdateSkillOrbStatusResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_XbUpdateSkillOrbStatusResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_XbUpdateSkillOrbStatusResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_XbUpdateSkillOrbStatusResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_XbUpdateSkillOrbStatusResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_XbUpdateSkillOrbStatusResponse__o {
	Cysharp_Threading_Tasks_UniTask_XbUpdateSkillOrbStatusResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_XbUpdateSkillOrbStatusResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpFormationResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_XbPvpFormationResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_XbPvpFormationResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpFormationResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_XbPvpFormationResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpFormationResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_XbPvpFormationResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_XbPvpFormationResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpFormationResponse__o {
	Cysharp_Threading_Tasks_UniTask_XbPvpFormationResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_XbPvpFormationResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpFormationUpdateResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_XbPvpFormationUpdateResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_XbPvpFormationUpdateResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpFormationUpdateResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_XbPvpFormationUpdateResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpFormationUpdateResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_XbPvpFormationUpdateResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_XbPvpFormationUpdateResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpFormationUpdateResponse__o {
	Cysharp_Threading_Tasks_UniTask_XbPvpFormationUpdateResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_XbPvpFormationUpdateResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpEntryResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_XbPvpEntryResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_XbPvpEntryResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpEntryResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_XbPvpEntryResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpEntryResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_XbPvpEntryResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_XbPvpEntryResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpEntryResponse__o {
	Cysharp_Threading_Tasks_UniTask_XbPvpEntryResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_XbPvpEntryResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpQuickMatchingResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_XbPvpQuickMatchingResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_XbPvpQuickMatchingResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpQuickMatchingResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_XbPvpQuickMatchingResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpQuickMatchingResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_XbPvpQuickMatchingResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_XbPvpQuickMatchingResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpQuickMatchingResponse__o {
	Cysharp_Threading_Tasks_UniTask_XbPvpQuickMatchingResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_XbPvpQuickMatchingResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchingResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_XbPvpRankMatchingResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchingResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchingResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchingResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchingResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchingResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchingResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchingResponse__o {
	Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchingResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchingResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpCasualMatchingResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_XbPvpCasualMatchingResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_XbPvpCasualMatchingResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpCasualMatchingResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_XbPvpCasualMatchingResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpCasualMatchingResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_XbPvpCasualMatchingResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_XbPvpCasualMatchingResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpCasualMatchingResponse__o {
	Cysharp_Threading_Tasks_UniTask_XbPvpCasualMatchingResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_XbPvpCasualMatchingResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchHistoryListResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_XbPvpRankMatchHistoryListResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchHistoryListResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchHistoryListResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchHistoryListResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchHistoryListResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchHistoryListResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchHistoryListResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchHistoryListResponse__o {
	Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchHistoryListResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_XbPvpRankMatchHistoryListResponse__o;

typedef struct Neon_Model_Api_Rpc_AuthSignInRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_String_o* deviceSecret_;
	struct System_String_o* deviceUniqueId_;
	struct System_String_o* deviceToken_;
	struct System_String_o* deviceModel_;
	struct System_String_o* clientDigest_;
} Neon_Model_Api_Rpc_AuthSignInRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AuthSignInRequest_VTable {
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
} Neon_Model_Api_Rpc_AuthSignInRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AuthSignInRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AuthSignInRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AuthSignInRequest_VTable vtable;
} Neon_Model_Api_Rpc_AuthSignInRequest_c;

typedef struct Neon_Model_Api_Rpc_AuthSignInRequest_o {
	Neon_Model_Api_Rpc_AuthSignInRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AuthSignInRequest_Fields fields;
} Neon_Model_Api_Rpc_AuthSignInRequest_o;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignInResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_AuthSignInResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_AuthSignInResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignInResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_AuthSignInResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignInResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_AuthSignInResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_AuthSignInResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthSignInResponse__o {
	Cysharp_Threading_Tasks_UniTask_AuthSignInResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_AuthSignInResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_UserCrossDateResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_UserCrossDateResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_UserCrossDateResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_UserCrossDateResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_UserCrossDateResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_UserCrossDateResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_UserCrossDateResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_UserCrossDateResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_UserCrossDateResponse__o {
	Cysharp_Threading_Tasks_UniTask_UserCrossDateResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_UserCrossDateResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_GachaListResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_GachaListResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_GachaListResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_GachaListResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_GachaListResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_GachaListResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_GachaListResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_GachaListResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_GachaListResponse__o {
	Cysharp_Threading_Tasks_UniTask_GachaListResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_GachaListResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_UserLogInResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_UserLogInResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_UserLogInResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_UserLogInResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_UserLogInResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_UserLogInResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_UserLogInResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_UserLogInResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_UserLogInResponse__o {
	Cysharp_Threading_Tasks_UniTask_UserLogInResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_UserLogInResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthNonceResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_AuthNonceResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_AuthNonceResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthNonceResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_AuthNonceResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthNonceResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_AuthNonceResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_AuthNonceResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_AuthNonceResponse__o {
	Cysharp_Threading_Tasks_UniTask_AuthNonceResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_AuthNonceResponse__o;

typedef struct System_Nullable_DateTime__Fields {
	bool hasValue;
	struct System_DateTime_o value;
} System_Nullable_DateTime__Fields;

typedef struct System_Nullable_DateTime__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} System_Nullable_DateTime__VTable;

typedef struct System_Nullable_DateTime__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Nullable_DateTime__VTable vtable;
} System_Nullable_DateTime__c;

typedef struct System_Nullable_DateTime__o {
	System_Nullable_DateTime__Fields fields;
} System_Nullable_DateTime__o;

typedef struct CEMAAIHMHDA_Fields {
	int32_t _ACDJAMAIODN_k__BackingField;
	int32_t _JHLAIKLPDDK_k__BackingField;
	struct JDGBHFIBACG_o* _MAPCMMFLHMB_k__BackingField;
	int32_t _DFGNIODGPGN_k__BackingField;
	int32_t _DMAABMDFMBP_k__BackingField;
	int32_t _JMLIJJAAICE_k__BackingField;
	int32_t _OKHGKLPPMJE_k__BackingField;
	struct System_String_o* _POMMPBLDAOA_k__BackingField;
	int32_t _KDBMHPCDNMG_k__BackingField;
	struct System_String_o* _JEJKFJLMHIM_k__BackingField;
	bool _KIBGBMHEAGN_k__BackingField;
	bool _CNJLJJOEJFL_k__BackingField;
	struct System_Collections_Generic_IReadOnlyList_JPHMCEGLIGJ__o* _IFPMOKILKNM_k__BackingField;
	struct System_Collections_Generic_IReadOnlyList_LIJLAHBHFAG__o* _NCJMNFDBGDL_k__BackingField;
	struct System_String_o* _NAFCMMBOFJE_k__BackingField;
	struct System_Nullable_DateTime__o _BAIJLBLIKGN_k__BackingField;
} CEMAAIHMHDA_Fields;

typedef struct CEMAAIHMHDA_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} CEMAAIHMHDA_VTable;

typedef struct CEMAAIHMHDA_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	CEMAAIHMHDA_VTable vtable;
} CEMAAIHMHDA_c;

typedef struct CEMAAIHMHDA_o {
	CEMAAIHMHDA_c *klass;
	void *monitor;
	CEMAAIHMHDA_Fields fields;
} CEMAAIHMHDA_o;

typedef struct CEMAAIHMHDA_array {
	Il2CppObject obj;
	Il2CppArrayBounds *bounds;
	il2cpp_array_size_t max_length;
	CEMAAIHMHDA_o* m_Items[65535];
} CEMAAIHMHDA_array;

typedef struct HNNPFPKEEFE_Fields /* : MasterMemory_TableBase_CEMAAIHMHDA__Fields */ {
	struct CEMAAIHMHDA_array* data; // MasterMemory_TableBase_CEMAAIHMHDA__Fields.data
	struct System_Func_CEMAAIHMHDA__FCEBPBJCHIM__o* CFCIMCHKDPA;
	struct CEMAAIHMHDA_array* AGKIMIDFFAI;
	struct System_Func_CEMAAIHMHDA__JIGJHLOCHGD__o* DMLKCLAFCDK;
} HNNPFPKEEFE_Fields;

typedef struct HNNPFPKEEFE_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_NEMCFIJNMAN;
	VirtualInvokeData _5_JJEODNKIDDF;
} HNNPFPKEEFE_VTable;

typedef struct HNNPFPKEEFE_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	HNNPFPKEEFE_VTable vtable;
} HNNPFPKEEFE_c;

typedef struct HNNPFPKEEFE_o {
	HNNPFPKEEFE_c *klass;
	void *monitor;
	HNNPFPKEEFE_Fields fields;
} HNNPFPKEEFE_o;

typedef struct JDGBHFIBACG_Fields {
	struct System_String_o* _OAFMLPAFFNJ_k__BackingField;
	struct System_String_o* _BMNNLBFHCNI_k__BackingField;
	struct System_String_o* _HPDJEPGBKNA_k__BackingField;
	struct System_String_o* _EIBHFAFHCCJ_k__BackingField;
	struct System_String_o* _BBENHFIPPAC_k__BackingField;
} JDGBHFIBACG_Fields;

typedef struct JDGBHFIBACG_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_MCCDMHGBEPG;
	VirtualInvokeData _5_IAGDCBJIJCL;
	VirtualInvokeData _6_MBLPIPHLELK;
	VirtualInvokeData _7_JGHNKLHIOHA;
	VirtualInvokeData _8_GCPPNPLKPPN;
	VirtualInvokeData _9_OGLHPLALAMA;
	VirtualInvokeData _10_FPHDFGMOGDG;
	VirtualInvokeData _11_AFONOGFAMJP;
	VirtualInvokeData _12_PMCHLKGPDIG;
} JDGBHFIBACG_VTable;

typedef struct JDGBHFIBACG_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	JDGBHFIBACG_VTable vtable;
} JDGBHFIBACG_c;

typedef struct JDGBHFIBACG_o {
	JDGBHFIBACG_c *klass;
	void *monitor;
	JDGBHFIBACG_Fields fields;
} JDGBHFIBACG_o;

typedef struct UnityEngine_Object_Fields {
	intptr_t m_CachedPtr;
} UnityEngine_Object_Fields;

typedef struct UnityEngine_Component_Fields /* : UnityEngine_Object_Fields */ {
	intptr_t m_CachedPtr;
} UnityEngine_Component_Fields;

typedef struct UnityEngine_Behaviour_Fields /* : UnityEngine_Component_Fields */ {
	intptr_t m_CachedPtr;
} UnityEngine_Behaviour_Fields;

typedef struct UnityEngine_MonoBehaviour_Fields /* : UnityEngine_Behaviour_Fields */ {
	intptr_t m_CachedPtr;
	struct System_Threading_CancellationTokenSource_o* m_CancellationTokenSource;
} UnityEngine_MonoBehaviour_Fields;

typedef struct Neon_Common_Utility_CameraFovScaler_Fields /* : UnityEngine_MonoBehaviour_Fields */ {
	intptr_t m_CachedPtr;
	struct System_Threading_CancellationTokenSource_o* m_CancellationTokenSource;
	int32_t _fovFitMode;
	float _fov;
	struct UnityEngine_Camera_o* AFKOPCDEOFF;
} Neon_Common_Utility_CameraFovScaler_Fields;

typedef struct Neon_Common_Utility_CameraFovScaler_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Neon_Common_Utility_CameraFovScaler_VTable;

typedef struct Neon_Common_Utility_CameraFovScaler_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Common_Utility_CameraFovScaler_VTable vtable;
} Neon_Common_Utility_CameraFovScaler_c;

typedef struct Neon_Common_Utility_CameraFovScaler_o {
	Neon_Common_Utility_CameraFovScaler_c *klass;
	void *monitor;
	Neon_Common_Utility_CameraFovScaler_Fields fields;
} Neon_Common_Utility_CameraFovScaler_o;

typedef struct DG_Tweening_Tween_o DG_Tweening_Tween_o;
typedef struct UnityEngine_Transform_o UnityEngine_Transform_o;

typedef struct UnityEngine_Vector3_Fields {
	float x;
	float y;
	float z;
} UnityEngine_Vector3_Fields;

typedef struct UnityEngine_Vector3_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equals;
	VirtualInvokeData _5_ToString;
} UnityEngine_Vector3_VTable;

typedef struct UnityEngine_Vector3_c {
	Il2CppClass_1 _1;
	struct UnityEngine_Vector3_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Vector3_VTable vtable;
} UnityEngine_Vector3_c;

typedef struct UnityEngine_Vector3_o {
	UnityEngine_Vector3_Fields fields;
} UnityEngine_Vector3_o;

typedef struct UnityEngine_Quaternion_Fields {
	float x;
	float y;
	float z;
	float w;
} UnityEngine_Quaternion_Fields;

typedef struct UnityEngine_Quaternion_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equals;
	VirtualInvokeData _5_ToString;
} UnityEngine_Quaternion_VTable;

typedef struct UnityEngine_Quaternion_c {
	Il2CppClass_1 _1;
	struct UnityEngine_Quaternion_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Quaternion_VTable vtable;
} UnityEngine_Quaternion_c;

typedef struct UnityEngine_Quaternion_o {
	UnityEngine_Quaternion_Fields fields;
} UnityEngine_Quaternion_o;

typedef struct System_Type_o System_Type_o;
typedef struct UnityEngine_Object_o UnityEngine_Object_o;

typedef struct UnityEngine_Vector2_Fields {
	float x;
	float y;
} UnityEngine_Vector2_Fields;

typedef struct UnityEngine_Vector2_o {
	UnityEngine_Vector2_Fields fields;
} UnityEngine_Vector2_o;

typedef struct Cinemachine_CameraState_CustomBlendable_Fields {
	struct UnityEngine_Object_o* m_Custom;
	float m_Weight;
} Cinemachine_CameraState_CustomBlendable_Fields;

typedef struct Cinemachine_CameraState_CustomBlendable_o {
	Cinemachine_CameraState_CustomBlendable_Fields fields;
} Cinemachine_CameraState_CustomBlendable_o;

typedef struct Cinemachine_LensSettings_Fields {
	float FieldOfView;
	float OrthographicSize;
	float NearClipPlane;
	float FarClipPlane;
	float Dutch;
	int32_t ModeOverride;
	struct UnityEngine_Vector2_o LensShift;
	int32_t GateFit;
	float FocusDistance;
	struct UnityEngine_Vector2_o m_SensorSize;
	bool m_OrthoFromCamera;
	bool m_PhysicalFromCamera;
} Cinemachine_LensSettings_Fields;

typedef struct Cinemachine_LensSettings_o {
	Cinemachine_LensSettings_Fields fields;
} Cinemachine_LensSettings_o;

typedef struct Cinemachine_CameraState_Fields {
	struct Cinemachine_LensSettings_o Lens;
	struct UnityEngine_Vector3_o ReferenceUp;
	struct UnityEngine_Vector3_o ReferenceLookAt;
	struct UnityEngine_Vector3_o RawPosition;
	struct UnityEngine_Quaternion_o RawOrientation;
	struct UnityEngine_Vector3_o PositionDampingBypass;
	float ShotQuality;
	struct UnityEngine_Vector3_o PositionCorrection;
	struct UnityEngine_Quaternion_o OrientationCorrection;
	int32_t BlendHint;
	struct Cinemachine_CameraState_CustomBlendable_o mCustom0;
	struct Cinemachine_CameraState_CustomBlendable_o mCustom1;
	struct Cinemachine_CameraState_CustomBlendable_o mCustom2;
	struct Cinemachine_CameraState_CustomBlendable_o mCustom3;
	struct System_Collections_Generic_List_CameraState_CustomBlendable__o* m_CustomOverflow;
	int32_t _NumCustomBlendables_k__BackingField;
} Cinemachine_CameraState_Fields;

typedef struct Cinemachine_CameraState_o {
	Cinemachine_CameraState_Fields fields;
} Cinemachine_CameraState_o;

typedef struct Cinemachine_CinemachineVirtualCameraBase_TransitionParams_Fields {
	int32_t m_BlendHint;
	bool m_InheritPosition;
	struct Cinemachine_CinemachineBrain_VcamActivatedEvent_o* m_OnCameraLive;
} Cinemachine_CinemachineVirtualCameraBase_TransitionParams_Fields;

typedef struct Cinemachine_CinemachineVirtualCameraBase_TransitionParams_o {
	Cinemachine_CinemachineVirtualCameraBase_TransitionParams_Fields fields;
} Cinemachine_CinemachineVirtualCameraBase_TransitionParams_o;

typedef struct UnityEngine_Object_array {
	Il2CppObject obj;
	Il2CppArrayBounds *bounds;
	il2cpp_array_size_t max_length;
	UnityEngine_Object_o* m_Items[65535];
} UnityEngine_Object_array;

typedef struct Cinemachine_CinemachineVirtualCameraBase_Fields /* : UnityEngine_MonoBehaviour_Fields */ {
	intptr_t m_CachedPtr;
	struct System_Threading_CancellationTokenSource_o* m_CancellationTokenSource;
	struct System_String_array* m_ExcludedPropertiesInInspector;
	struct Cinemachine_CinemachineCore_Stage_array* m_LockStageInInspector;
	int32_t m_ValidatingStreamVersion;
	bool m_OnValidateCalled;
	int32_t m_StreamingVersion;
	int32_t m_Priority;
	int32_t m_ActivationId;
	float FollowTargetAttachment;
	float LookAtTargetAttachment;
	int32_t m_StandbyUpdate;
	struct System_Collections_Generic_List_CinemachineExtension__o* _mExtensions_k__BackingField;
	bool _PreviousStateIsValid_k__BackingField;
	bool m_WasStarted;
	bool mSlaveStatusUpdated;
	struct Cinemachine_CinemachineVirtualCameraBase_o* m_parentVcam;
	int32_t m_QueuePriority;
	float m_blendStartPosition;
	struct UnityEngine_Transform_o* m_CachedFollowTarget;
	struct Cinemachine_CinemachineVirtualCameraBase_o* m_CachedFollowTargetVcam;
	struct Cinemachine_ICinemachineTargetGroup_o* m_CachedFollowTargetGroup;
	struct UnityEngine_Transform_o* m_CachedLookAtTarget;
	struct Cinemachine_CinemachineVirtualCameraBase_o* m_CachedLookAtTargetVcam;
	struct Cinemachine_ICinemachineTargetGroup_o* m_CachedLookAtTargetGroup;
	bool _FollowTargetChanged_k__BackingField;
	bool _LookAtTargetChanged_k__BackingField;
} Cinemachine_CinemachineVirtualCameraBase_Fields;

typedef struct Cinemachine_CinemachineVirtualCamera_Fields /* : Cinemachine_CinemachineVirtualCameraBase_Fields*/ {
	intptr_t m_CachedPtr;
	struct System_Threading_CancellationTokenSource_o* m_CancellationTokenSource;
	struct System_String_array* m_ExcludedPropertiesInInspector;
	struct Cinemachine_CinemachineCore_Stage_array* m_LockStageInInspector;
	int32_t m_ValidatingStreamVersion;
	bool m_OnValidateCalled;
	int32_t m_StreamingVersion;
	int32_t m_Priority;
	int32_t m_ActivationId;
	float FollowTargetAttachment;
	float LookAtTargetAttachment;
	int32_t m_StandbyUpdate;
	struct System_Collections_Generic_List_CinemachineExtension__o* _mExtensions_k__BackingField;
	bool _PreviousStateIsValid_k__BackingField;
	bool m_WasStarted;
	bool mSlaveStatusUpdated;
	struct Cinemachine_CinemachineVirtualCameraBase_o* m_parentVcam;
	int32_t m_QueuePriority;
	float m_blendStartPosition;
	struct UnityEngine_Transform_o* m_CachedFollowTarget;
	struct Cinemachine_CinemachineVirtualCameraBase_o* m_CachedFollowTargetVcam;
	struct Cinemachine_ICinemachineTargetGroup_o* m_CachedFollowTargetGroup;
	struct UnityEngine_Transform_o* m_CachedLookAtTarget;
	struct Cinemachine_CinemachineVirtualCameraBase_o* m_CachedLookAtTargetVcam;
	struct Cinemachine_ICinemachineTargetGroup_o* m_CachedLookAtTargetGroup;
	bool _FollowTargetChanged_k__BackingField;
	bool _LookAtTargetChanged_k__BackingField;
	struct UnityEngine_Transform_o* m_LookAt;
	struct UnityEngine_Transform_o* m_Follow;
	struct Cinemachine_LensSettings_o m_Lens;
	struct Cinemachine_CinemachineVirtualCameraBase_TransitionParams_o m_Transitions;
	int32_t m_LegacyBlendHint;
	struct Cinemachine_CameraState_o m_State;
	struct Cinemachine_CinemachineComponentBase_array* m_ComponentPipeline;
	struct UnityEngine_Transform_o* m_ComponentOwner;
	struct UnityEngine_Transform_o* mCachedLookAtTarget;
	struct Cinemachine_CinemachineVirtualCameraBase_o* mCachedLookAtTargetVcam;
} Cinemachine_CinemachineVirtualCamera_Fields;

typedef struct Cinemachine_CinemachineVirtualCamera_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_get_Name;
	VirtualInvokeData _5_get_Priority;
	VirtualInvokeData _6_unknown;
	VirtualInvokeData _7_unknown;
	VirtualInvokeData _8_unknown;
	VirtualInvokeData _9_get_VirtualCameraGameObject;
	VirtualInvokeData _10_get_IsValid;
	VirtualInvokeData _11_get_ParentCamera;
	VirtualInvokeData _12_unknown;
	VirtualInvokeData _13_UpdateCameraState;
	VirtualInvokeData _14_unknown;
	VirtualInvokeData _15_UnityEngine_ISerializationCallbackReceiver_OnBeforeSerialize;
	VirtualInvokeData _16_UnityEngine_ISerializationCallbackReceiver_OnAfterDeserialize;
	VirtualInvokeData _17_GetMaxDampTime;
	VirtualInvokeData _18_AddExtension;
	VirtualInvokeData _19_RemoveExtension;
	VirtualInvokeData _20_get_Description;
	VirtualInvokeData _21_set_Priority;
	VirtualInvokeData _22_get_State;
	VirtualInvokeData _23_IsLiveChild;
	VirtualInvokeData _24_get_LookAt;
	VirtualInvokeData _25_set_LookAt;
	VirtualInvokeData _26_get_Follow;
	VirtualInvokeData _27_set_Follow;
	VirtualInvokeData _28_get_PreviousStateIsValid;
	VirtualInvokeData _29_set_PreviousStateIsValid;
	VirtualInvokeData _30_InternalUpdateCameraState;
	VirtualInvokeData _31_OnTransitionFromCamera;
	VirtualInvokeData _32_OnDestroy;
	VirtualInvokeData _33_OnTransformParentChanged;
	VirtualInvokeData _34_Start;
	VirtualInvokeData _35_RequiresUserInput;
	VirtualInvokeData _36_OnValidate;
	VirtualInvokeData _37_OnEnable;
	VirtualInvokeData _38_OnDisable;
	VirtualInvokeData _39_Update;
	VirtualInvokeData _40_OnTargetObjectWarped;
	VirtualInvokeData _41_ForceCameraPosition;
	VirtualInvokeData _42_LegacyUpgrade;
	VirtualInvokeData _43_OnBeforeSerialize;
} Cinemachine_CinemachineVirtualCamera_VTable;

typedef struct Cinemachine_CinemachineVirtualCamera_c {
	Il2CppClass_1 _1;
	struct Cinemachine_CinemachineVirtualCamera_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cinemachine_CinemachineVirtualCamera_VTable vtable;
} Cinemachine_CinemachineVirtualCamera_c;

typedef struct Cinemachine_CinemachineVirtualCamera_o {
	Cinemachine_CinemachineVirtualCamera_c *klass;
	void *monitor;
	Cinemachine_CinemachineVirtualCamera_Fields fields;
} Cinemachine_CinemachineVirtualCamera_o;

typedef struct UnityEngine_Camera_o UnityEngine_Camera_o;

typedef struct MasterMemory_TableBase_HAMAAANAAKG__Fields {
	struct HAMAAANAAKG_array* data;
} MasterMemory_TableBase_HAMAAANAAKG__Fields;

typedef struct MasterMemory_TableBase_HAMAAANAAKG__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} MasterMemory_TableBase_HAMAAANAAKG__VTable;

typedef struct MasterMemory_TableBase_HAMAAANAAKG__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	MasterMemory_TableBase_HAMAAANAAKG__VTable vtable;
} MasterMemory_TableBase_HAMAAANAAKG__c;

typedef struct MasterMemory_TableBase_HAMAAANAAKG__o {
	MasterMemory_TableBase_HAMAAANAAKG__c *klass;
	void *monitor;
	MasterMemory_TableBase_HAMAAANAAKG__Fields fields;
} MasterMemory_TableBase_HAMAAANAAKG__o;

typedef struct JJNFAMALKLM_Fields /* : MasterMemory_TableBase_HAMAAANAAKG__Fields */ {
	struct HAMAAANAAKG_array* data;
	struct System_Func_HAMAAANAAKG__FDDCBHIEILM__o* CFCIMCHKDPA;
} JJNFAMALKLM_Fields;

typedef struct JJNFAMALKLM_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_NEMCFIJNMAN;
} JJNFAMALKLM_VTable;

typedef struct JJNFAMALKLM_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	JJNFAMALKLM_VTable vtable;
} JJNFAMALKLM_c;

typedef struct JJNFAMALKLM_o {
	JJNFAMALKLM_c *klass;
	void *monitor;
	JJNFAMALKLM_Fields fields;
} JJNFAMALKLM_o;

typedef struct System_Nullable_BFKEONBGGFP__Fields {
	bool hasValue;
	int32_t value;
} System_Nullable_BFKEONBGGFP__Fields;

typedef struct System_Nullable_BFKEONBGGFP__o {
	System_Nullable_BFKEONBGGFP__Fields fields;
} System_Nullable_BFKEONBGGFP__o;

typedef struct HAMAAANAAKG_Fields {
	int32_t _ACDJAMAIODN_k__BackingField;
	struct System_Nullable_BFKEONBGGFP__o _LFGDJMDIDON_k__BackingField;
	struct System_String_o* _JDCDGFDJNDF_k__BackingField;
} HAMAAANAAKG_Fields;

typedef struct HAMAAANAAKG_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} HAMAAANAAKG_VTable;

typedef struct HAMAAANAAKG_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	HAMAAANAAKG_VTable vtable;
} HAMAAANAAKG_c;

typedef struct HAMAAANAAKG_o {
	HAMAAANAAKG_c *klass;
	void *monitor;
	HAMAAANAAKG_Fields fields;
} HAMAAANAAKG_o;

typedef struct HAMAAANAAKG_array {
	Il2CppObject obj;
	Il2CppArrayBounds *bounds;
	il2cpp_array_size_t max_length;
	HAMAAANAAKG_o* m_Items[65535];
} HAMAAANAAKG_array;

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

typedef struct System_Nullable_IKAFHEBKEHP__Fields {
	bool hasValue;
	int32_t value;
} System_Nullable_IKAFHEBKEHP__Fields;

typedef struct System_Nullable_IKAFHEBKEHP__o {
	System_Nullable_IKAFHEBKEHP__Fields fields;
} System_Nullable_IKAFHEBKEHP__o;

typedef struct System_Collections_Generic_IReadOnlyList_PDIFPHMPPAG__o System_Collections_Generic_IReadOnlyList_PDIFPHMPPAG__o;

typedef struct AKKJOCJPHMD_o AKKJOCJPHMD_o;

typedef struct EMDHIMNBAPC_Fields {
	int32_t _ACDJAMAIODN_k__BackingField;
	struct JDGBHFIBACG_o* _MAPCMMFLHMB_k__BackingField;
	struct JDGBHFIBACG_o* _ONFEJDHIHOI_k__BackingField;
	int32_t _GNHKAJFOFMD_k__BackingField;
	struct System_Nullable_OOJEDNBBGBK__o _FJBJBJOHDOD_k__BackingField;
	struct System_Nullable_DateTime__o _HCNLCGDHEOL_k__BackingField;
	struct System_Nullable_DateTime__o _EAKCHNBBLNJ_k__BackingField;
	struct System_Collections_Generic_IReadOnlyList_PDIFPHMPPAG__o* _OGACABAJBOA_k__BackingField;
	struct System_Nullable_LFJELIPKMBM__o _KKKHDMOPFBJ_k__BackingField;
	struct System_Nullable_IKAFHEBKEHP__o _IBMDFPDGKHP_k__BackingField;
	int32_t _KINKAADAPKL_k__BackingField;
	struct System_String_o* _BODCKIPBBAO_k__BackingField;
} EMDHIMNBAPC_Fields;

typedef struct EMDHIMNBAPC_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} EMDHIMNBAPC_VTable;

typedef struct EMDHIMNBAPC_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	EMDHIMNBAPC_VTable vtable;
} EMDHIMNBAPC_c;

typedef struct EMDHIMNBAPC_o {
	EMDHIMNBAPC_c *klass;
	void *monitor;
	EMDHIMNBAPC_Fields fields;
} EMDHIMNBAPC_o;

typedef struct EMDHIMNBAPC_array {
	Il2CppObject obj;
	Il2CppArrayBounds *bounds;
	il2cpp_array_size_t max_length;
	EMDHIMNBAPC_o* m_Items[65535];
} EMDHIMNBAPC_array;

typedef struct GCHGCKNHMHC_Fields {
	int32_t _ACDJAMAIODN_k__BackingField;
	int32_t _CFJHCJCCJIF_k__BackingField;
	int32_t _DGMECENOBAD_k__BackingField;
} GCHGCKNHMHC_Fields;

typedef struct GCHGCKNHMHC_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_GCHEPAIOFDB;
	VirtualInvokeData _5_KACOBCFPPNA;
} GCHGCKNHMHC_VTable;

typedef struct GCHGCKNHMHC_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	GCHGCKNHMHC_VTable vtable;
} GCHGCKNHMHC_c;

typedef struct GCHGCKNHMHC_o {
	GCHGCKNHMHC_c *klass;
	void *monitor;
	GCHGCKNHMHC_Fields fields;
} GCHGCKNHMHC_o;

typedef struct GCHGCKNHMHC_array {
	Il2CppObject obj;
	Il2CppArrayBounds *bounds;
	il2cpp_array_size_t max_length;
	GCHGCKNHMHC_o* m_Items[65535];
} GCHGCKNHMHC_array;

typedef struct MasterMemory_TableBase_GCHGCKNHMHC__Fields {
	struct GCHGCKNHMHC_array* data;
} MasterMemory_TableBase_GCHGCKNHMHC__Fields;

typedef struct LICGNCFAOFL_Fields /* : MasterMemory_TableBase_GCHGCKNHMHC__Fields */ {
	struct GCHGCKNHMHC_array* data;
	struct System_Func_GCHGCKNHMHC__KBMLGOADIND__o* CFCIMCHKDPA;
	struct GCHGCKNHMHC_array* AGKIMIDFFAI;
	struct System_Func_GCHGCKNHMHC__BJKJJGFABDO__o* DMLKCLAFCDK;
} LICGNCFAOFL_Fields;

typedef struct LICGNCFAOFL_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_NEMCFIJNMAN;
} LICGNCFAOFL_VTable;

typedef struct LICGNCFAOFL_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	LICGNCFAOFL_VTable vtable;
} LICGNCFAOFL_c;

typedef struct LICGNCFAOFL_o {
	LICGNCFAOFL_c *klass;
	void *monitor;
	LICGNCFAOFL_Fields fields;
} LICGNCFAOFL_o;

typedef struct Neon_Model_UserData_IUserDataManager_o Neon_Model_UserData_IUserDataManager_o;

typedef struct System_Nullable_OILFBPIDOLM__Fields {
	bool hasValue;
	int32_t value;
} System_Nullable_OILFBPIDOLM__Fields;

typedef struct System_Nullable_OILFBPIDOLM__o {
	System_Nullable_OILFBPIDOLM__Fields fields;
} System_Nullable_OILFBPIDOLM__o;

typedef struct BHMJBFFHHDF_Fields {
	int32_t _ACDJAMAIODN_k__BackingField;
	struct JDGBHFIBACG_o* _MAPCMMFLHMB_k__BackingField;
	struct JDGBHFIBACG_o* _ONFEJDHIHOI_k__BackingField;
	struct System_String_o* _BCBLDIIPODI_k__BackingField;
	struct System_String_o* _MNHJCGDJIOD_k__BackingField;
	struct System_String_o* _EECLNEPNDMH_k__BackingField;
	int32_t _BDNBGLAPIDC_k__BackingField;
	int32_t _DMAABMDFMBP_k__BackingField;
	int32_t _OKLLAMHIFKD_k__BackingField;
	struct System_Nullable_DateTime__o _HCNLCGDHEOL_k__BackingField;
	struct System_Collections_Generic_IReadOnlyList_DGDHCLLOGKM__o* _MBPIHOIEHCM_k__BackingField;
	struct System_Collections_Generic_IReadOnlyList_IKAFHEBKEHP__o* _HGPOJGMBDHL_k__BackingField;
	struct DCBALGFPAFP_o* _MNMPFFAKGFK_k__BackingField;
	struct System_Collections_Generic_IReadOnlyList_IKAFHEBKEHP__o* _KKBLHLCJGFM_k__BackingField;
	struct System_Collections_Generic_IReadOnlyList_BHMJBFFHHDF_JBBEKHPBKLP__o* _GNONBCGGHHP_k__BackingField;
	struct System_Nullable_OILFBPIDOLM__o _FFHFIFCCIIA_k__BackingField;
} BHMJBFFHHDF_Fields;

typedef struct BHMJBFFHHDF_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} BHMJBFFHHDF_VTable;

typedef struct BHMJBFFHHDF_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	BHMJBFFHHDF_VTable vtable;
} BHMJBFFHHDF_c;

typedef struct BHMJBFFHHDF_o {
	BHMJBFFHHDF_c *klass;
	void *monitor;
	BHMJBFFHHDF_Fields fields;
} BHMJBFFHHDF_o;

typedef struct System_Collections_Generic_IReadOnlyList_BHMJBFFHHDF_JBBEKHPBKLP__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	VirtualInvokeData vtable[32];
} System_Collections_Generic_IReadOnlyList_BHMJBFFHHDF_JBBEKHPBKLP__c;

typedef struct System_Collections_Generic_IReadOnlyList_BHMJBFFHHDF_JBBEKHPBKLP__o {
	System_Collections_Generic_IReadOnlyList_BHMJBFFHHDF_JBBEKHPBKLP__c *klass;
	void *monitor;
	/* System_Collections_Generic_IReadOnlyList_BHMJBFFHHDF_JBBEKHPBKLP__Fields fields; */
} System_Collections_Generic_IReadOnlyList_BHMJBFFHHDF_JBBEKHPBKLP__o;

typedef struct BHMJBFFHHDF_JBBEKHPBKLP_Fields {
	int32_t _DOHHEEOGGIE_k__BackingField;
	int32_t _GHPPBKDAPNB_k__BackingField;
	int32_t _CNPHIKPJOJF_k__BackingField;
} BHMJBFFHHDF_JBBEKHPBKLP_Fields;

typedef struct BHMJBFFHHDF_JBBEKHPBKLP_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} BHMJBFFHHDF_JBBEKHPBKLP_VTable;

typedef struct BHMJBFFHHDF_JBBEKHPBKLP_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	BHMJBFFHHDF_JBBEKHPBKLP_VTable vtable;
} BHMJBFFHHDF_JBBEKHPBKLP_c;

typedef struct BHMJBFFHHDF_JBBEKHPBKLP_o {
	BHMJBFFHHDF_JBBEKHPBKLP_c *klass;
	void *monitor;
	BHMJBFFHHDF_JBBEKHPBKLP_Fields fields;
} BHMJBFFHHDF_JBBEKHPBKLP_o;

#endif