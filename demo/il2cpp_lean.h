#ifndef IL2CPP_LEAN_H_2025_06_09_2025_04_07
#define IL2CPP_LEAN_H_2025_06_09_2025_04_07

#include "il2cpp_shared.h"

#include <stdint.h>
#include <stdbool.h>

typedef struct MethodInfo_1C7D920 GetResultMethodInfo;
typedef struct MethodInfo_E255C0 NeonApiGetResponse_MethodInfo;
typedef struct CDPAJOEFJDI_o NeonApiGetResponse_ThirdParam;

typedef struct CDPAJOEFJDI_o CDPAJOEFJDI_o;

typedef struct CDGPJELFAMK_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_LKHAOCKIOPL;
	VirtualInvokeData _6_DAOEJIDKBPB;
	VirtualInvokeData _7_NDHHPKBFJBA;
	VirtualInvokeData _8_unknown;
	VirtualInvokeData _9_ONIFJDGBNFE;
	VirtualInvokeData _10_OCCJINKDNDF;
	VirtualInvokeData _11_unknown;
	VirtualInvokeData _12_FFNNCLNIBNJ;
	VirtualInvokeData _13_unknown;
	VirtualInvokeData _14_IDKDCHPAICO;
	VirtualInvokeData _15_unknown;
	VirtualInvokeData _16_unknown;
	VirtualInvokeData _17_unknown;
	VirtualInvokeData _18_EIJFILJLCCN;
	VirtualInvokeData _19_unknown;
	VirtualInvokeData _20_MJGHFDHINGD;
} CDGPJELFAMK_VTable;

typedef struct CDGPJELFAMK_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	CDGPJELFAMK_VTable vtable;
} CDGPJELFAMK_c;

typedef struct MethodInfo_E255C0_RGCTXs {
	MethodInfo* _0_Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_TResponse__Create;
	Il2CppClass* _1_Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_TResponse_;
	Il2CppClass* _2_Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_TResponse_;
	Il2CppClass* _3_CDGPJELFAMK_FONKLPFFEFK_TResponse_;
	Il2CppClass* _4_Google_Protobuf_MessageParser_TResponse_;
	MethodInfo* _5_Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_TResponse__Start_CDGPJELFAMK_FONKLPFFEFK_TResponse__;
	Il2CppClass* _6_CDGPJELFAMK_FONKLPFFEFK_TResponse_;
	MethodInfo* _7_Cysharp_Threading_Tasks_CompilerServices_AsyncUniTaskMethodBuilder_TResponse__get_Task;
	Il2CppClass* _8_Cysharp_Threading_Tasks_UniTask_TResponse_;
} MethodInfo_E255C0_RGCTXs;

typedef struct MethodInfo_E255C0 {
	Il2CppMethodPointer methodPointer;
	Il2CppMethodPointer virtualMethodPointer;
	InvokerMethod invoker_method;
	const char* name;
	CDGPJELFAMK_c *klass;
	const Il2CppType *return_type;
	const Il2CppType** parameters;
	const MethodInfo_E255C0_RGCTXs* rgctx_data;
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
} MethodInfo_E255C0;

typedef struct MethodInfo_1C7D920 {
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
} MethodInfo_1C7D920;

typedef struct Neon_Model_Api_Rpc_XbStartRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t xbId_;
	struct Google_Protobuf_Collections_RepeatedField_XbMemberRequest__o* playerMembers_;
	struct System_Nullable_long__o enemyUserId_;
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

typedef struct Neon_Model_Api_Rpc_BattleRestartRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* lineCharacterIds_;
	struct Google_Protobuf_Collections_RepeatedField_int__o* encounteredEnemyIds_;
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

typedef struct Neon_Model_Api_Rpc_TensionCardEnhanceRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t tensionCardId_;
	struct Google_Protobuf_Collections_RepeatedField_ConsumedItem__o* consumedItems_;
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

typedef struct Neon_Model_Api_Rpc_UserLinkGoogleRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_String_o* idToken_;
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

typedef struct Neon_Model_Api_Rpc_ItemSellSupplyRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* itemSupplyEntityIds_;
} Neon_Model_Api_Rpc_ItemSellSupplyRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ItemSellSupplyRequest_VTable {
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
} Neon_Model_Api_Rpc_ItemSellSupplyRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ItemSellSupplyRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ItemSellSupplyRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ItemSellSupplyRequest_VTable vtable;
} Neon_Model_Api_Rpc_ItemSellSupplyRequest_c;

typedef struct Neon_Model_Api_Rpc_ItemSellSupplyRequest_o {
	Neon_Model_Api_Rpc_ItemSellSupplyRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ItemSellSupplyRequest_Fields fields;
} Neon_Model_Api_Rpc_ItemSellSupplyRequest_o;

typedef struct Neon_Model_Api_Rpc_AdventureReleaseWarpPointRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t warpPointId_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
} Neon_Model_Api_Rpc_AdventureReleaseWarpPointRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AdventureReleaseWarpPointRequest_VTable {
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
} Neon_Model_Api_Rpc_AdventureReleaseWarpPointRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AdventureReleaseWarpPointRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AdventureReleaseWarpPointRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AdventureReleaseWarpPointRequest_VTable vtable;
} Neon_Model_Api_Rpc_AdventureReleaseWarpPointRequest_c;

typedef struct Neon_Model_Api_Rpc_AdventureReleaseWarpPointRequest_o {
	Neon_Model_Api_Rpc_AdventureReleaseWarpPointRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AdventureReleaseWarpPointRequest_Fields fields;
} Neon_Model_Api_Rpc_AdventureReleaseWarpPointRequest_o;

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

typedef struct Neon_Model_Api_Rpc_BattleFinishRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t battleResult_;
	struct Google_Protobuf_Collections_RepeatedField_BattleCharacterUpdate__o* characterUpdates_;
	struct Google_Protobuf_Collections_RepeatedField_BattleTaskTopic__o* battleTaskTopics_;
	struct Google_Protobuf_Collections_RepeatedField_int__o* encounteredEnemyIds_;
	int32_t battleTimeSecond_;
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

typedef struct Neon_Model_Api_Rpc_NewsListRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_Nullable_int__o language_;
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

typedef struct Neon_Model_Api_Rpc_TensionCardLevelLimitEnhanceRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t tensionCardId_;
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

typedef struct Neon_Model_Api_Rpc_AuthSignUpRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_String_o* deviceSecret_;
	struct System_String_o* deviceUniqueId_;
	struct System_String_o* deviceModel_;
	struct System_Nullable_int__o language_;
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

typedef struct Neon_Model_Api_Rpc_XbPlayRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t xbId_;
	int32_t zoneAreaIndex_;
	int32_t commandId_;
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

typedef struct Neon_Model_Api_Rpc_ItemUseSupplyRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* itemSupplyEntityIds_;
	int32_t characterId_;
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

typedef struct Neon_Model_Api_Rpc_AdventureReadSequenceRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* sequenceRequestIds_;
	struct Google_Protobuf_Collections_RepeatedField_NineSequenceRequest__o* nineSequences_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
	struct System_Nullable_int__o miniGameId_;
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

typedef struct Neon_Model_Api_Rpc_XbRestoreCheckPointRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t xbId_;
} Neon_Model_Api_Rpc_XbRestoreCheckPointRequest_Fields;

typedef struct Neon_Model_Api_Rpc_XbRestoreCheckPointRequest_VTable {
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
} Neon_Model_Api_Rpc_XbRestoreCheckPointRequest_VTable;

typedef struct Neon_Model_Api_Rpc_XbRestoreCheckPointRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_XbRestoreCheckPointRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_XbRestoreCheckPointRequest_VTable vtable;
} Neon_Model_Api_Rpc_XbRestoreCheckPointRequest_c;

typedef struct Neon_Model_Api_Rpc_XbRestoreCheckPointRequest_o {
	Neon_Model_Api_Rpc_XbRestoreCheckPointRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_XbRestoreCheckPointRequest_Fields fields;
} Neon_Model_Api_Rpc_XbRestoreCheckPointRequest_o;

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

typedef struct Neon_Model_Api_Rpc_BattleRewardRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t recoveryType_;
	struct System_Nullable_int__o itemId_;
	int32_t count_;
} Neon_Model_Api_Rpc_BattleRewardRequest_Fields;

typedef struct Neon_Model_Api_Rpc_BattleRewardRequest_VTable {
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
} Neon_Model_Api_Rpc_BattleRewardRequest_VTable;

typedef struct Neon_Model_Api_Rpc_BattleRewardRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_BattleRewardRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_BattleRewardRequest_VTable vtable;
} Neon_Model_Api_Rpc_BattleRewardRequest_c;

typedef struct Neon_Model_Api_Rpc_BattleRewardRequest_o {
	Neon_Model_Api_Rpc_BattleRewardRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_BattleRewardRequest_Fields fields;
} Neon_Model_Api_Rpc_BattleRewardRequest_o;

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

typedef struct Neon_Model_Api_Rpc_AdventureFastTravelRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_Nullable_int__o warpPointId_;
	struct System_Nullable_int__o dungeonId_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
} Neon_Model_Api_Rpc_AdventureFastTravelRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AdventureFastTravelRequest_VTable {
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
} Neon_Model_Api_Rpc_AdventureFastTravelRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AdventureFastTravelRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AdventureFastTravelRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AdventureFastTravelRequest_VTable vtable;
} Neon_Model_Api_Rpc_AdventureFastTravelRequest_c;

typedef struct Neon_Model_Api_Rpc_AdventureFastTravelRequest_o {
	Neon_Model_Api_Rpc_AdventureFastTravelRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AdventureFastTravelRequest_Fields fields;
} Neon_Model_Api_Rpc_AdventureFastTravelRequest_o;

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

typedef struct Neon_Model_Api_Rpc_ShopPurchaseRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t shopProductId_;
	int32_t quantity_;
	struct System_Nullable_int__o shopProductLimitedDiscountId_;
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

typedef struct Neon_Model_Api_Rpc_DungeonStartRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t dungeonDifficultyId_;
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

typedef struct Neon_Model_Api_Rpc_XbFormationRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t xbId_;
	struct System_Nullable_long__o enemyUserId_;
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

typedef struct Neon_Model_Api_Rpc_ItemUseRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t itemId_;
	int32_t count_;
	int32_t characterId_;
} Neon_Model_Api_Rpc_ItemUseRequest_Fields;

typedef struct Neon_Model_Api_Rpc_ItemUseRequest_VTable {
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
} Neon_Model_Api_Rpc_ItemUseRequest_VTable;

typedef struct Neon_Model_Api_Rpc_ItemUseRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_ItemUseRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_ItemUseRequest_VTable vtable;
} Neon_Model_Api_Rpc_ItemUseRequest_c;

typedef struct Neon_Model_Api_Rpc_ItemUseRequest_o {
	Neon_Model_Api_Rpc_ItemUseRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_ItemUseRequest_Fields fields;
} Neon_Model_Api_Rpc_ItemUseRequest_o;

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

typedef struct Neon_Model_Api_Rpc_BattleSkipRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t battleEntryId_;
	struct Neon_Model_Api_Model_BattleTrigger_o* battleTrigger_;
	struct Neon_Model_Api_Model_CurrentLocation_o* currentLocation_;
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

typedef struct Neon_Model_Api_Rpc_AdventureVariableRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct Google_Protobuf_Collections_RepeatedField_int__o* adventureVariableIds_;
} Neon_Model_Api_Rpc_AdventureVariableRequest_Fields;

typedef struct Neon_Model_Api_Rpc_AdventureVariableRequest_VTable {
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
} Neon_Model_Api_Rpc_AdventureVariableRequest_VTable;

typedef struct Neon_Model_Api_Rpc_AdventureVariableRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_AdventureVariableRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_AdventureVariableRequest_VTable vtable;
} Neon_Model_Api_Rpc_AdventureVariableRequest_c;

typedef struct Neon_Model_Api_Rpc_AdventureVariableRequest_o {
	Neon_Model_Api_Rpc_AdventureVariableRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_AdventureVariableRequest_Fields fields;
} Neon_Model_Api_Rpc_AdventureVariableRequest_o;

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

typedef struct Neon_Model_Api_Rpc_AuthSignUpGoogleRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_String_o* deviceSecret_;
	struct System_String_o* deviceUniqueId_;
	struct System_String_o* deviceModel_;
	struct System_String_o* idToken_;
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

typedef struct Neon_Model_Api_Rpc_GearEnhanceRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t gearEntityId_;
	struct Google_Protobuf_Collections_RepeatedField_int__o* consumedGearEntityIds_;
	struct Google_Protobuf_Collections_RepeatedField_ConsumedItem__o* consumedItems_;
} Neon_Model_Api_Rpc_GearEnhanceRequest_Fields;

typedef struct Neon_Model_Api_Rpc_GearEnhanceRequest_VTable {
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
} Neon_Model_Api_Rpc_GearEnhanceRequest_VTable;

typedef struct Neon_Model_Api_Rpc_GearEnhanceRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_GearEnhanceRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_GearEnhanceRequest_VTable vtable;
} Neon_Model_Api_Rpc_GearEnhanceRequest_c;

typedef struct Neon_Model_Api_Rpc_GearEnhanceRequest_o {
	Neon_Model_Api_Rpc_GearEnhanceRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_GearEnhanceRequest_Fields fields;
} Neon_Model_Api_Rpc_GearEnhanceRequest_o;

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

typedef struct Neon_Model_Api_Rpc_XbRewardRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t xbId_;
	int32_t recoveryType_;
	struct System_Nullable_int__o itemId_;
	int32_t count_;
} Neon_Model_Api_Rpc_XbRewardRequest_Fields;

typedef struct Neon_Model_Api_Rpc_XbRewardRequest_VTable {
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
} Neon_Model_Api_Rpc_XbRewardRequest_VTable;

typedef struct Neon_Model_Api_Rpc_XbRewardRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_XbRewardRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_XbRewardRequest_VTable vtable;
} Neon_Model_Api_Rpc_XbRewardRequest_c;

typedef struct Neon_Model_Api_Rpc_XbRewardRequest_o {
	Neon_Model_Api_Rpc_XbRewardRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_XbRewardRequest_Fields fields;
} Neon_Model_Api_Rpc_XbRewardRequest_o;

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

typedef struct Neon_Model_Api_Rpc_DungeonRestartRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t dungeonDifficultyId_;
} Neon_Model_Api_Rpc_DungeonRestartRequest_Fields;

typedef struct Neon_Model_Api_Rpc_DungeonRestartRequest_VTable {
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
} Neon_Model_Api_Rpc_DungeonRestartRequest_VTable;

typedef struct Neon_Model_Api_Rpc_DungeonRestartRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_DungeonRestartRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_DungeonRestartRequest_VTable vtable;
} Neon_Model_Api_Rpc_DungeonRestartRequest_c;

typedef struct Neon_Model_Api_Rpc_DungeonRestartRequest_o {
	Neon_Model_Api_Rpc_DungeonRestartRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_DungeonRestartRequest_Fields fields;
} Neon_Model_Api_Rpc_DungeonRestartRequest_o;

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

typedef struct Neon_Model_Api_Rpc_AdventureAcquireAreaItemRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	struct System_Nullable_int__o areaItemSpawnId_;
	struct System_Nullable_int__o areaObjectBehaviorId_;
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

typedef struct Neon_Model_Api_Rpc_XbPvpQuickMatchingRequest_Fields {
	struct Google_Protobuf_UnknownFieldSet_o* _unknownFields;
	int32_t xbId_;
} Neon_Model_Api_Rpc_XbPvpQuickMatchingRequest_Fields;

typedef struct Neon_Model_Api_Rpc_XbPvpQuickMatchingRequest_VTable {
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
} Neon_Model_Api_Rpc_XbPvpQuickMatchingRequest_VTable;

typedef struct Neon_Model_Api_Rpc_XbPvpQuickMatchingRequest_c {
	Il2CppClass_1 _1;
	struct Neon_Model_Api_Rpc_XbPvpQuickMatchingRequest_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Neon_Model_Api_Rpc_XbPvpQuickMatchingRequest_VTable vtable;
} Neon_Model_Api_Rpc_XbPvpQuickMatchingRequest_c;

typedef struct Neon_Model_Api_Rpc_XbPvpQuickMatchingRequest_o {
	Neon_Model_Api_Rpc_XbPvpQuickMatchingRequest_c *klass;
	void *monitor;
	Neon_Model_Api_Rpc_XbPvpQuickMatchingRequest_Fields fields;
} Neon_Model_Api_Rpc_XbPvpQuickMatchingRequest_o;

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

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureReleaseWarpPointResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_AdventureReleaseWarpPointResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_AdventureReleaseWarpPointResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureReleaseWarpPointResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_AdventureReleaseWarpPointResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureReleaseWarpPointResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_AdventureReleaseWarpPointResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_AdventureReleaseWarpPointResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureReleaseWarpPointResponse__o {
	Cysharp_Threading_Tasks_UniTask_AdventureReleaseWarpPointResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_AdventureReleaseWarpPointResponse__o;

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

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureVariableResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_AdventureVariableResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_AdventureVariableResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureVariableResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_AdventureVariableResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureVariableResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_AdventureVariableResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_AdventureVariableResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_AdventureVariableResponse__o {
	Cysharp_Threading_Tasks_UniTask_AdventureVariableResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_AdventureVariableResponse__o;

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

typedef struct Cysharp_Threading_Tasks_UniTask_BattleRewardResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_BattleRewardResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_BattleRewardResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleRewardResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_BattleRewardResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleRewardResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_BattleRewardResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_BattleRewardResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_BattleRewardResponse__o {
	Cysharp_Threading_Tasks_UniTask_BattleRewardResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_BattleRewardResponse__o;

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

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonRestartResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_DungeonRestartResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_DungeonRestartResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonRestartResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_DungeonRestartResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonRestartResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_DungeonRestartResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_DungeonRestartResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_DungeonRestartResponse__o {
	Cysharp_Threading_Tasks_UniTask_DungeonRestartResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_DungeonRestartResponse__o;

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

typedef struct Cysharp_Threading_Tasks_UniTask_GearEnhanceResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_GearEnhanceResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_GearEnhanceResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_GearEnhanceResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_GearEnhanceResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_GearEnhanceResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_GearEnhanceResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_GearEnhanceResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_GearEnhanceResponse__o {
	Cysharp_Threading_Tasks_UniTask_GearEnhanceResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_GearEnhanceResponse__o;

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

typedef struct Cysharp_Threading_Tasks_UniTask_ItemUseSupplyResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_ItemUseSupplyResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_ItemUseSupplyResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemUseSupplyResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_ItemUseSupplyResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemUseSupplyResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_ItemUseSupplyResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_ItemUseSupplyResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemUseSupplyResponse__o {
	Cysharp_Threading_Tasks_UniTask_ItemUseSupplyResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_ItemUseSupplyResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemSellSupplyResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_ItemSellSupplyResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_ItemSellSupplyResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemSellSupplyResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_ItemSellSupplyResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemSellSupplyResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_ItemSellSupplyResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_ItemSellSupplyResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_ItemSellSupplyResponse__o {
	Cysharp_Threading_Tasks_UniTask_ItemSellSupplyResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_ItemSellSupplyResponse__o;

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

typedef struct Cysharp_Threading_Tasks_UniTask_XbRestoreCheckPointResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_XbRestoreCheckPointResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_XbRestoreCheckPointResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_XbRestoreCheckPointResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_XbRestoreCheckPointResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_XbRestoreCheckPointResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_XbRestoreCheckPointResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_XbRestoreCheckPointResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_XbRestoreCheckPointResponse__o {
	Cysharp_Threading_Tasks_UniTask_XbRestoreCheckPointResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_XbRestoreCheckPointResponse__o;

typedef struct Cysharp_Threading_Tasks_UniTask_XbRewardResponse__Fields {
	struct Cysharp_Threading_Tasks_IUniTaskSource_T__o* source;
	struct Neon_Model_Api_Rpc_XbRewardResponse_o* result;
	int16_t token;
} Cysharp_Threading_Tasks_UniTask_XbRewardResponse__Fields;

typedef struct Cysharp_Threading_Tasks_UniTask_XbRewardResponse__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
} Cysharp_Threading_Tasks_UniTask_XbRewardResponse__VTable;

typedef struct Cysharp_Threading_Tasks_UniTask_XbRewardResponse__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Cysharp_Threading_Tasks_UniTask_XbRewardResponse__VTable vtable;
} Cysharp_Threading_Tasks_UniTask_XbRewardResponse__c;

typedef struct Cysharp_Threading_Tasks_UniTask_XbRewardResponse__o {
	Cysharp_Threading_Tasks_UniTask_XbRewardResponse__Fields fields;
} Cysharp_Threading_Tasks_UniTask_XbRewardResponse__o;

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

typedef struct CEMAAIHMHDA_Fields {
	int32_t _ACDJAMAIODN_k__BackingField;
	int32_t _JHLAIKLPDDK_k__BackingField;
	struct JDGBHFIBACG_o* _MAPCMMFLHMB_k__BackingField;
	int32_t _DFGNIODGPGN_k__BackingField;
	int32_t _DMAABMDFMBP_k__BackingField;
	int32_t _JMLIJJAAICE_k__BackingField;
	int32_t _OKHGKLPPMJE_k__BackingField;
	struct System_String_o* _PIJKEDKCCPH_k__BackingField;
	int32_t _KDBMHPCDNMG_k__BackingField;
	struct System_String_o* _JEJKFJLMHIM_k__BackingField;
	struct System_Collections_Generic_IReadOnlyList_JPHMCEGLIGJ__o* _IFPMOKILKNM_k__BackingField;
	struct System_Collections_Generic_IReadOnlyList_LIJLAHBHFAG__o* _NCJMNFDBGDL_k__BackingField;
	struct System_String_o* _NAFCMMBOFJE_k__BackingField;
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

typedef struct MasterMemory_TableBase_CEMAAIHMHDA__Fields {
	struct CEMAAIHMHDA_array* data;
} MasterMemory_TableBase_CEMAAIHMHDA__Fields;

typedef struct HNNPFPKEEFE_Fields /* : MasterMemory_TableBase_CEMAAIHMHDA__Fields */ {
	struct CEMAAIHMHDA_array* data;
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
	VirtualInvokeData _5_FGKEAJELDBD;
	VirtualInvokeData _6_HLFGIHHOKHE;
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

#endif