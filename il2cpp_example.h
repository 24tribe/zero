#include <cstdint>

typedef void(*Il2CppMethodPointer)();

struct MethodInfo;

struct VirtualInvokeData
{
    Il2CppMethodPointer methodPtr;
    const MethodInfo* method;
};

struct Il2CppType
{
    void* data;
    unsigned int bits;
};

struct Il2CppClass;


union Il2CppRGCTXData
{
    void* rgctxDataDummy;
    const MethodInfo* method;
    const Il2CppType* type;
    Il2CppClass* klass;
};

struct Il2CppRuntimeInterfaceOffsetPair
{
    Il2CppClass* interfaceType;
    int32_t offset;
};
struct Il2CppClass_1
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
};

struct Il2CppClass_2
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
};

struct Il2CppClass
{
    Il2CppClass_1 _1;
    void* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    VirtualInvokeData vtable[255];
};

typedef uintptr_t il2cpp_array_size_t;
typedef int32_t il2cpp_array_lower_bound_t;
struct Il2CppArrayBounds
{
    il2cpp_array_size_t length;
    il2cpp_array_lower_bound_t lower_bound;
};

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

struct UnityEngine_Color_Fields {
	float r;
	float g;
	float b;
	float a;
};
struct UnityEngine_Color_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equals;
	VirtualInvokeData _5_ToString;
};
struct UnityEngine_Color_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Color_VTable vtable;
};
struct UnityEngine_Color_o {
	UnityEngine_Color_Fields fields;
};

struct UnityEngine_Vector4_Fields {
	float x;
	float y;
	float z;
	float w;
};
struct UnityEngine_Vector4_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equals;
	VirtualInvokeData _5_ToString;
};
struct UnityEngine_Vector4_c {
	Il2CppClass_1 _1;
	struct UnityEngine_Vector4_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Vector4_VTable vtable;
};
struct UnityEngine_Vector4_o {
	UnityEngine_Vector4_Fields fields;
};
struct UnityEngine_Vector4_StaticFields {
	struct UnityEngine_Vector4_o zeroVector;
	struct UnityEngine_Vector4_o oneVector;
	struct UnityEngine_Vector4_o positiveInfinityVector;
	struct UnityEngine_Vector4_o negativeInfinityVector;
};

struct UnityEngine_Object_Fields {
	intptr_t m_CachedPtr;
};

struct UnityEngine_Component_Fields : UnityEngine_Object_Fields {
};

struct UnityEngine_Behaviour_Fields : UnityEngine_Component_Fields {
};

struct UnityEngine_MonoBehaviour_Fields : UnityEngine_Behaviour_Fields {
	struct System_Threading_CancellationTokenSource_o* m_CancellationTokenSource;
};

struct UnityEngine_EventSystems_UIBehaviour_Fields : UnityEngine_MonoBehaviour_Fields {
};

struct UnityEngine_UI_Graphic_Fields : UnityEngine_EventSystems_UIBehaviour_Fields {
	struct UnityEngine_Material_o* m_Material;
	struct UnityEngine_Color_o m_Color;
	bool m_SkipLayoutUpdate;
	bool m_SkipMaterialUpdate;
	bool m_RaycastTarget;
	bool m_RaycastTargetCache;
	struct UnityEngine_Vector4_o m_RaycastPadding;
	struct UnityEngine_RectTransform_o* m_RectTransform;
	struct UnityEngine_CanvasRenderer_o* m_CanvasRenderer;
	struct UnityEngine_Canvas_o* m_Canvas;
	bool m_VertsDirty;
	bool m_MaterialDirty;
	struct UnityEngine_Events_UnityAction_o* m_OnDirtyLayoutCallback;
	struct UnityEngine_Events_UnityAction_o* m_OnDirtyVertsCallback;
	struct UnityEngine_Events_UnityAction_o* m_OnDirtyMaterialCallback;
	struct UnityEngine_Mesh_o* m_CachedMesh;
	struct UnityEngine_Vector2_array* m_CachedUvs;
	struct UnityEngine_UI_CoroutineTween_TweenRunner_ColorTween__o* m_ColorTweenRunner;
	bool _useLegacyMeshGeneration_k__BackingField;
};
struct UnityEngine_UI_Graphic_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Awake;
	VirtualInvokeData _5_OnEnable;
	VirtualInvokeData _6_Start;
	VirtualInvokeData _7_OnDisable;
	VirtualInvokeData _8_OnDestroy;
	VirtualInvokeData _9_IsActive;
	VirtualInvokeData _10_OnRectTransformDimensionsChange;
	VirtualInvokeData _11_OnBeforeTransformParentChanged;
	VirtualInvokeData _12_OnTransformParentChanged;
	VirtualInvokeData _13_OnDidApplyAnimationProperties;
	VirtualInvokeData _14_OnCanvasGroupChanged;
	VirtualInvokeData _15_OnCanvasHierarchyChanged;
	VirtualInvokeData _16_IsDestroyed;
	VirtualInvokeData _17_unknown;
	VirtualInvokeData _18_UnityEngine_UI_ICanvasElement_get_transform;
	VirtualInvokeData _19_unknown;
	VirtualInvokeData _20_unknown;
	VirtualInvokeData _21_unknown;
	VirtualInvokeData _22_get_color;
	VirtualInvokeData _23_set_color;
	VirtualInvokeData _24_get_raycastTarget;
	VirtualInvokeData _25_set_raycastTarget;
	VirtualInvokeData _26_SetAllDirty;
	VirtualInvokeData _27_SetLayoutDirty;
	VirtualInvokeData _28_SetVerticesDirty;
	VirtualInvokeData _29_SetMaterialDirty;
	VirtualInvokeData _30_get_rectTransform;
	VirtualInvokeData _31_get_defaultMaterial;
	VirtualInvokeData _32_get_material;
	VirtualInvokeData _33_set_material;
	VirtualInvokeData _34_get_materialForRendering;
	VirtualInvokeData _35_get_mainTexture;
	VirtualInvokeData _36_OnCullingChanged;
	VirtualInvokeData _37_Rebuild;
	VirtualInvokeData _38_LayoutComplete;
	VirtualInvokeData _39_GraphicUpdateComplete;
	VirtualInvokeData _40_UpdateMaterial;
	VirtualInvokeData _41_UpdateGeometry;
	VirtualInvokeData _42_OnFillVBO;
	VirtualInvokeData _43_OnPopulateMesh;
	VirtualInvokeData _44_OnPopulateMesh;
	VirtualInvokeData _45_SetNativeSize;
	VirtualInvokeData _46_Raycast;
	VirtualInvokeData _47_CrossFadeColor;
	VirtualInvokeData _48_CrossFadeColor;
	VirtualInvokeData _49_CrossFadeAlpha;
};
struct UnityEngine_UI_Graphic_c {
	Il2CppClass_1 _1;
	struct UnityEngine_UI_Graphic_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_UI_Graphic_VTable vtable;
};
struct UnityEngine_UI_Graphic_o {
	UnityEngine_UI_Graphic_c *klass;
	void *monitor;
	UnityEngine_UI_Graphic_Fields fields;
};
struct UnityEngine_UI_Graphic_StaticFields {
	struct UnityEngine_Material_o* s_DefaultUI;
	struct UnityEngine_Texture2D_o* s_WhiteTexture;
	struct UnityEngine_Mesh_o* s_Mesh;
	struct UnityEngine_UI_VertexHelper_o* s_VertexHelper;
};
struct UnityEngine_UI_MaskableGraphic_Fields : UnityEngine_UI_Graphic_Fields {
	bool m_ShouldRecalculateStencil;
	struct UnityEngine_Material_o* m_MaskMaterial;
	struct UnityEngine_UI_RectMask2D_o* m_ParentMask;
	bool m_Maskable;
	bool m_IsMaskingGraphic;
	bool m_IncludeForMasking;
	struct UnityEngine_UI_MaskableGraphic_CullStateChangedEvent_o* m_OnCullStateChanged;
	bool m_ShouldRecalculate;
	int32_t m_StencilValue;
	struct UnityEngine_Vector3_array* m_Corners;
};



struct UnityEngine_Component_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct UnityEngine_Component_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Component_VTable vtable;
};
struct UnityEngine_Component_o {
	UnityEngine_Component_c *klass;
	void *monitor;
	UnityEngine_Component_Fields fields;
};


struct System_Threading_CancellationTokenSource_Fields {
	struct System_Threading_ManualResetEvent_o* _kernelEvent;
	struct System_Threading_SparselyPopulatedArray_CancellationCallbackInfo__array* _registeredCallbacksLists;
	int32_t _state;
	int32_t _threadIDExecutingCallbacks;
	bool _disposed;
	struct System_Threading_CancellationCallbackInfo_o* _executingCallback;
	struct System_Threading_Timer_o* _timer;
};
struct System_Threading_CancellationTokenSource_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Dispose;
	VirtualInvokeData _5_Dispose;
};
struct System_Threading_CancellationTokenSource_c {
	Il2CppClass_1 _1;
	struct System_Threading_CancellationTokenSource_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Threading_CancellationTokenSource_VTable vtable;
};
struct System_Threading_CancellationTokenSource_o {
	System_Threading_CancellationTokenSource_c *klass;
	void *monitor;
	System_Threading_CancellationTokenSource_Fields fields;
};




struct NewBehaviourScript_Fields : UnityEngine_MonoBehaviour_Fields {
	struct TMPro_TextMeshProUGUI_o* tmp_pro;
};
struct NewBehaviourScript_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct NewBehaviourScript_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	NewBehaviourScript_VTable vtable;
};
struct NewBehaviourScript_o {
	NewBehaviourScript_c *klass;
	void *monitor;
	NewBehaviourScript_Fields fields;
};



struct TMPro_TMP_TextProcessingStack_int__Fields {
	struct System_Int32_array* itemStack;
	int32_t index;
	int32_t m_DefaultItem;
	int32_t m_Capacity;
	int32_t m_RolloverSize;
	int32_t m_Count;
};
struct TMPro_TMP_TextProcessingStack_int__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct TMPro_TMP_TextProcessingStack_int__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	TMPro_TMP_TextProcessingStack_int__VTable vtable;
};
struct TMPro_TMP_TextProcessingStack_int__o {
	TMPro_TMP_TextProcessingStack_int__Fields fields;
};

struct UnityEngine_Rect_Fields {
	float m_XMin;
	float m_YMin;
	float m_Width;
	float m_Height;
};


struct UnityEngine_Rect_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equals;
	VirtualInvokeData _5_ToString;
};

struct UnityEngine_Matrix4x4_Fields {
	float m00;
	float m10;
	float m20;
	float m30;
	float m01;
	float m11;
	float m21;
	float m31;
	float m02;
	float m12;
	float m22;
	float m32;
	float m03;
	float m13;
	float m23;
	float m33;
};
struct UnityEngine_Matrix4x4_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equals;
	VirtualInvokeData _5_ToString;
};
struct UnityEngine_Matrix4x4_c {
	Il2CppClass_1 _1;
	struct UnityEngine_Matrix4x4_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Matrix4x4_VTable vtable;
};
struct UnityEngine_Matrix4x4_o {
	UnityEngine_Matrix4x4_Fields fields;
};
struct UnityEngine_Matrix4x4_StaticFields {
	struct UnityEngine_Matrix4x4_o zeroMatrix;
	struct UnityEngine_Matrix4x4_o identityMatrix;
};
struct UnityEngine_Rect_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Rect_VTable vtable;
};
struct UnityEngine_Rect_o {
	UnityEngine_Rect_Fields fields;
};


struct TMPro_TextMeshProUGUI_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Awake;
	VirtualInvokeData _5_OnEnable;
	VirtualInvokeData _6_Start;
	VirtualInvokeData _7_OnDisable;
	VirtualInvokeData _8_OnDestroy;
	VirtualInvokeData _9_IsActive;
	VirtualInvokeData _10_OnRectTransformDimensionsChange;
	VirtualInvokeData _11_OnBeforeTransformParentChanged;
	VirtualInvokeData _12_OnTransformParentChanged;
	VirtualInvokeData _13_OnDidApplyAnimationProperties;
	VirtualInvokeData _14_OnCanvasGroupChanged;
	VirtualInvokeData _15_OnCanvasHierarchyChanged;
	VirtualInvokeData _16_IsDestroyed;
	VirtualInvokeData _17_unknown;
	VirtualInvokeData _18_UnityEngine_UI_ICanvasElement_get_transform;
	VirtualInvokeData _19_unknown;
	VirtualInvokeData _20_unknown;
	VirtualInvokeData _21_unknown;
	VirtualInvokeData _22_get_color;
	VirtualInvokeData _23_set_color;
	VirtualInvokeData _24_get_raycastTarget;
	VirtualInvokeData _25_set_raycastTarget;
	VirtualInvokeData _26_SetAllDirty;
	VirtualInvokeData _27_SetLayoutDirty;
	VirtualInvokeData _28_SetVerticesDirty;
	VirtualInvokeData _29_SetMaterialDirty;
	VirtualInvokeData _30_get_rectTransform;
	VirtualInvokeData _31_get_defaultMaterial;
	VirtualInvokeData _32_get_material;
	VirtualInvokeData _33_set_material;
	VirtualInvokeData _34_get_materialForRendering;
	VirtualInvokeData _35_get_mainTexture;
	VirtualInvokeData _36_OnCullingChanged;
	VirtualInvokeData _37_Rebuild;
	VirtualInvokeData _38_LayoutComplete;
	VirtualInvokeData _39_GraphicUpdateComplete;
	VirtualInvokeData _40_UpdateMaterial;
	VirtualInvokeData _41_UpdateGeometry;
	VirtualInvokeData _42_OnFillVBO;
	VirtualInvokeData _43_OnPopulateMesh;
	VirtualInvokeData _44_OnPopulateMesh;
	VirtualInvokeData _45_SetNativeSize;
	VirtualInvokeData _46_Raycast;
	VirtualInvokeData _47_CrossFadeColor;
	VirtualInvokeData _48_CrossFadeColor;
	VirtualInvokeData _49_CrossFadeAlpha;
	VirtualInvokeData _50_UnityEngine_UI_IClippable_get_gameObject;
	VirtualInvokeData _51_unknown;
	VirtualInvokeData _52_unknown;
	VirtualInvokeData _53_unknown;
	VirtualInvokeData _54_unknown;
	VirtualInvokeData _55_unknown;
	VirtualInvokeData _56_unknown;
	VirtualInvokeData _57_unknown;
	VirtualInvokeData _58_GetModifiedMaterial;
	VirtualInvokeData _59_Cull;
	VirtualInvokeData _60_SetClipRect;
	VirtualInvokeData _61_SetClipSoftness;
	VirtualInvokeData _62_ParentMaskStateChanged;
	VirtualInvokeData _63_RecalculateClipping;
	VirtualInvokeData _64_RecalculateMasking;
	VirtualInvokeData _65_get_text;
	VirtualInvokeData _66_set_text;
	VirtualInvokeData _67_get_fontSharedMaterial;
	VirtualInvokeData _68_set_fontSharedMaterial;
	VirtualInvokeData _69_get_fontSharedMaterials;
	VirtualInvokeData _70_set_fontSharedMaterials;
	VirtualInvokeData _71_get_fontMaterials;
	VirtualInvokeData _72_set_fontMaterials;
	VirtualInvokeData _73_get_margin;
	VirtualInvokeData _74_set_margin;
	VirtualInvokeData _75_get_autoSizeTextContainer;
	VirtualInvokeData _76_set_autoSizeTextContainer;
	VirtualInvokeData _77_get_mesh;
	VirtualInvokeData _78_add_OnPreRenderText;
	VirtualInvokeData _79_remove_OnPreRenderText;
	VirtualInvokeData _80_get_flexibleHeight;
	VirtualInvokeData _81_get_flexibleWidth;
	VirtualInvokeData _82_get_minWidth;
	VirtualInvokeData _83_get_minHeight;
	VirtualInvokeData _84_get_preferredWidth;
	VirtualInvokeData _85_get_preferredHeight;
	VirtualInvokeData _86_get_renderedWidth;
	VirtualInvokeData _87_get_renderedHeight;
	VirtualInvokeData _88_get_layoutPriority;
	VirtualInvokeData _89_LoadFontAsset;
	VirtualInvokeData _90_SetSharedMaterial;
	VirtualInvokeData _91_GetMaterial;
	VirtualInvokeData _92_SetFontBaseMaterial;
	VirtualInvokeData _93_GetSharedMaterials;
	VirtualInvokeData _94_SetSharedMaterials;
	VirtualInvokeData _95_GetMaterials;
	VirtualInvokeData _96_CreateMaterialInstance;
	VirtualInvokeData _97_SetFaceColor;
	VirtualInvokeData _98_SetOutlineColor;
	VirtualInvokeData _99_SetOutlineThickness;
	VirtualInvokeData _100_SetShaderDepth;
	VirtualInvokeData _101_SetCulling;
	VirtualInvokeData _102_UpdateCulling;
	VirtualInvokeData _103_GetPaddingForMaterial;
	VirtualInvokeData _104_GetPaddingForMaterial;
	VirtualInvokeData _105_GetTextContainerLocalCorners;
	VirtualInvokeData _106_ForceMeshUpdate;
	VirtualInvokeData _107_UpdateGeometry;
	VirtualInvokeData _108_UpdateVertexData;
	VirtualInvokeData _109_UpdateVertexData;
	VirtualInvokeData _110_SetVertices;
	VirtualInvokeData _111_UpdateMeshPadding;
	VirtualInvokeData _112_InternalCrossFadeColor;
	VirtualInvokeData _113_InternalCrossFadeAlpha;
	VirtualInvokeData _114_SetArraySizes;
	VirtualInvokeData _115_CalculatePreferredValues;
	VirtualInvokeData _116_GetCompoundBounds;
	VirtualInvokeData _117_GetCanvasSpaceClippingRect;
	VirtualInvokeData _118_GetTextInfo;
	VirtualInvokeData _119_ComputeMarginSize;
	VirtualInvokeData _120_SaveGlyphVertexInfo;
	VirtualInvokeData _121_SaveSpriteVertexInfo;
	VirtualInvokeData _122_FillCharacterVertexBuffers;
	VirtualInvokeData _123_FillCharacterVertexBuffers;
	VirtualInvokeData _124_FillSpriteVertexBuffers;
	VirtualInvokeData _125_DrawUnderlineMesh;
	VirtualInvokeData _126_DrawTextHighlight;
	VirtualInvokeData _127_SetActiveSubMeshes;
	VirtualInvokeData _128_DestroySubMeshObjects;
	VirtualInvokeData _129_ClearMesh;
	VirtualInvokeData _130_ClearMesh;
	VirtualInvokeData _131_GetParsedText;
	VirtualInvokeData _132_InternalUpdate;
	VirtualInvokeData _133_CalculateLayoutInputHorizontal;
	VirtualInvokeData _134_CalculateLayoutInputVertical;
	VirtualInvokeData _135_unknown;
	VirtualInvokeData _136_unknown;
	VirtualInvokeData _137_unknown;
	VirtualInvokeData _138_unknown;
	VirtualInvokeData _139_unknown;
	VirtualInvokeData _140_unknown;
	VirtualInvokeData _141_unknown;
	VirtualInvokeData _142_GenerateTextMesh;
};
struct TMPro_TextMeshProUGUI_c {
	Il2CppClass_1 _1;
	struct TMPro_TextMeshProUGUI_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	TMPro_TextMeshProUGUI_VTable vtable;
};



struct Unity_Profiling_ProfilerMarker_Fields {
	intptr_t m_Ptr;
};
struct Unity_Profiling_ProfilerMarker_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct Unity_Profiling_ProfilerMarker_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Unity_Profiling_ProfilerMarker_VTable vtable;
};
struct Unity_Profiling_ProfilerMarker_o {
	Unity_Profiling_ProfilerMarker_Fields fields;
};

struct TMPro_TextMeshProUGUI_StaticFields {
	struct Unity_Profiling_ProfilerMarker_o k_GenerateTextMarker;
	struct Unity_Profiling_ProfilerMarker_o k_SetArraySizesMarker;
	struct Unity_Profiling_ProfilerMarker_o k_GenerateTextPhaseIMarker;
	struct Unity_Profiling_ProfilerMarker_o k_ParseMarkupTextMarker;
	struct Unity_Profiling_ProfilerMarker_o k_CharacterLookupMarker;
	struct Unity_Profiling_ProfilerMarker_o k_HandleGPOSFeaturesMarker;
	struct Unity_Profiling_ProfilerMarker_o k_CalculateVerticesPositionMarker;
	struct Unity_Profiling_ProfilerMarker_o k_ComputeTextMetricsMarker;
	struct Unity_Profiling_ProfilerMarker_o k_HandleVisibleCharacterMarker;
	struct Unity_Profiling_ProfilerMarker_o k_HandleWhiteSpacesMarker;
	struct Unity_Profiling_ProfilerMarker_o k_HandleHorizontalLineBreakingMarker;
	struct Unity_Profiling_ProfilerMarker_o k_HandleVerticalLineBreakingMarker;
	struct Unity_Profiling_ProfilerMarker_o k_SaveGlyphVertexDataMarker;
	struct Unity_Profiling_ProfilerMarker_o k_ComputeCharacterAdvanceMarker;
	struct Unity_Profiling_ProfilerMarker_o k_HandleCarriageReturnMarker;
	struct Unity_Profiling_ProfilerMarker_o k_HandleLineTerminationMarker;
	struct Unity_Profiling_ProfilerMarker_o k_SavePageInfoMarker;
	struct Unity_Profiling_ProfilerMarker_o k_SaveProcessingStatesMarker;
	struct Unity_Profiling_ProfilerMarker_o k_GenerateTextPhaseIIMarker;
	struct Unity_Profiling_ProfilerMarker_o k_GenerateTextPhaseIIIMarker;
};

struct TMPro_TMP_Text_SpecialCharacter_Fields {
	struct TMPro_TMP_Character_o* character;
	struct TMPro_TMP_FontAsset_o* fontAsset;
	struct UnityEngine_Material_o* material;
	int32_t materialIndex;
};
struct TMPro_TMP_Text_SpecialCharacter_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct TMPro_TMP_Text_SpecialCharacter_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	TMPro_TMP_Text_SpecialCharacter_VTable vtable;
};
struct TMPro_TMP_Text_SpecialCharacter_o {
	TMPro_TMP_Text_SpecialCharacter_Fields fields;
};

struct UnityEngine_Color32_Fields {
	int32_t rgba;
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};
struct UnityEngine_Color32_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_ToString;
};

struct TMPro_TMP_Text_TextBackingContainer_Fields {
	struct System_UInt32_array* m_Array;
	int32_t m_Count;
};
struct TMPro_TMP_Text_TextBackingContainer_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct TMPro_TMP_Text_TextBackingContainer_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	TMPro_TMP_Text_TextBackingContainer_VTable vtable;
};
struct TMPro_TMP_Text_TextBackingContainer_o {
	TMPro_TMP_Text_TextBackingContainer_Fields fields;
};

struct UnityEngine_Color32_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Color32_VTable vtable;
};
struct UnityEngine_Color32_o {
	UnityEngine_Color32_Fields fields;
};

struct TMPro_TMP_TextProcessingStack_float__Fields {
	struct System_Single_array* itemStack;
	int32_t index;
	float m_DefaultItem;
	int32_t m_Capacity;
	int32_t m_RolloverSize;
	int32_t m_Count;
};
struct TMPro_TMP_TextProcessingStack_float__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct TMPro_TMP_TextProcessingStack_float__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	TMPro_TMP_TextProcessingStack_float__VTable vtable;
};
struct TMPro_TMP_TextProcessingStack_float__o {
	TMPro_TMP_TextProcessingStack_float__Fields fields;
};


struct TMPro_TMP_Offset_Fields {
	float m_Left;
	float m_Right;
	float m_Top;
	float m_Bottom;
};
struct TMPro_TMP_Offset_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};

struct UnityEngine_Vector2_Fields {
	float x;
	float y;
};
struct UnityEngine_Vector2_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equals;
	VirtualInvokeData _5_ToString;
};
struct UnityEngine_Vector2_c {
	Il2CppClass_1 _1;
	struct UnityEngine_Vector2_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Vector2_VTable vtable;
};
struct UnityEngine_Vector2_o {
	UnityEngine_Vector2_Fields fields;
};

struct TMPro_TMP_TextProcessingStack_HorizontalAlignmentOptions__Fields {
	struct TMPro_HorizontalAlignmentOptions_array* itemStack;
	int32_t index;
	int32_t m_DefaultItem;
	int32_t m_Capacity;
	int32_t m_RolloverSize;
	int32_t m_Count;
};
struct TMPro_TMP_TextProcessingStack_HorizontalAlignmentOptions__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct TMPro_TMP_TextProcessingStack_HorizontalAlignmentOptions__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	TMPro_TMP_TextProcessingStack_HorizontalAlignmentOptions__VTable vtable;
};
struct TMPro_TMP_TextProcessingStack_HorizontalAlignmentOptions__o {
	TMPro_TMP_TextProcessingStack_HorizontalAlignmentOptions__Fields fields;
};

struct UnityEngine_Vector2_StaticFields {
	struct UnityEngine_Vector2_o zeroVector;
	struct UnityEngine_Vector2_o oneVector;
	struct UnityEngine_Vector2_o upVector;
	struct UnityEngine_Vector2_o downVector;
	struct UnityEngine_Vector2_o leftVector;
	struct UnityEngine_Vector2_o rightVector;
	struct UnityEngine_Vector2_o positiveInfinityVector;
	struct UnityEngine_Vector2_o negativeInfinityVector;
};
struct TMPro_Extents_Fields {
	struct UnityEngine_Vector2_o min;
	struct UnityEngine_Vector2_o max;
};
struct TMPro_Extents_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct TMPro_Extents_c {
	Il2CppClass_1 _1;
	struct TMPro_Extents_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	TMPro_Extents_VTable vtable;
};
struct TMPro_Extents_o {
	TMPro_Extents_Fields fields;
};
struct TMPro_Extents_StaticFields {
	struct TMPro_Extents_o zero;
	struct TMPro_Extents_o uninitialized;
};

struct TMPro_TMP_Offset_c {
	Il2CppClass_1 _1;
	struct TMPro_TMP_Offset_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	TMPro_TMP_Offset_VTable vtable;
};
struct TMPro_TMP_Offset_o {
	TMPro_TMP_Offset_Fields fields;
};
struct TMPro_TMP_Offset_StaticFields {
	struct TMPro_TMP_Offset_o k_ZeroOffset;
};


struct TMPro_HighlightState_Fields {
	struct UnityEngine_Color32_o color;
	struct TMPro_TMP_Offset_o padding;
};
struct TMPro_HighlightState_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct TMPro_HighlightState_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	TMPro_HighlightState_VTable vtable;
};
struct TMPro_HighlightState_o {
	TMPro_HighlightState_Fields fields;
};
struct TMPro_TMP_TextProcessingStack_HighlightState__Fields {
	struct TMPro_HighlightState_array* itemStack;
	int32_t index;
	struct TMPro_HighlightState_o m_DefaultItem;
	int32_t m_Capacity;
	int32_t m_RolloverSize;
	int32_t m_Count;
};
struct TMPro_TMP_TextProcessingStack_HighlightState__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct TMPro_TMP_TextProcessingStack_HighlightState__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	TMPro_TMP_TextProcessingStack_HighlightState__VTable vtable;
};
struct TMPro_TMP_TextProcessingStack_HighlightState__o {
	TMPro_TMP_TextProcessingStack_HighlightState__Fields fields;
};
struct TMPro_TMP_TextProcessingStack_TMP_ColorGradient__Fields {
	struct TMPro_TMP_ColorGradient_array* itemStack;
	int32_t index;
	struct TMPro_TMP_ColorGradient_o* m_DefaultItem;
	int32_t m_Capacity;
	int32_t m_RolloverSize;
	int32_t m_Count;
};
struct TMPro_TMP_TextProcessingStack_TMP_ColorGradient__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct TMPro_TMP_TextProcessingStack_TMP_ColorGradient__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	TMPro_TMP_TextProcessingStack_TMP_ColorGradient__VTable vtable;
};
struct TMPro_TMP_TextProcessingStack_TMP_ColorGradient__o {
	TMPro_TMP_TextProcessingStack_TMP_ColorGradient__Fields fields;
};
struct TMPro_TMP_TextProcessingStack_Color32__Fields {
	struct UnityEngine_Color32_array* itemStack;
	int32_t index;
	struct UnityEngine_Color32_o m_DefaultItem;
	int32_t m_Capacity;
	int32_t m_RolloverSize;
	int32_t m_Count;
};
struct TMPro_TMP_TextProcessingStack_Color32__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct TMPro_TMP_TextProcessingStack_Color32__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	TMPro_TMP_TextProcessingStack_Color32__VTable vtable;
};
struct TMPro_TMP_TextProcessingStack_Color32__o {
	TMPro_TMP_TextProcessingStack_Color32__Fields fields;
};

struct TMPro_TMP_FontStyleStack_Fields {
	uint8_t bold;
	uint8_t italic;
	uint8_t underline;
	uint8_t strikethrough;
	uint8_t highlight;
	uint8_t superscript;
	uint8_t subscript;
	uint8_t uppercase;
	uint8_t lowercase;
	uint8_t smallcaps;
};
struct TMPro_TMP_FontStyleStack_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct TMPro_TMP_FontStyleStack_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	TMPro_TMP_FontStyleStack_VTable vtable;
};
struct TMPro_TMP_FontStyleStack_o {
	TMPro_TMP_FontStyleStack_Fields fields;
};

struct TMPro_TMP_TextProcessingStack_FontWeight__Fields {
	struct TMPro_FontWeight_array* itemStack;
	int32_t index;
	int32_t m_DefaultItem;
	int32_t m_Capacity;
	int32_t m_RolloverSize;
	int32_t m_Count;
};
struct TMPro_TMP_TextProcessingStack_FontWeight__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct TMPro_TMP_TextProcessingStack_FontWeight__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	TMPro_TMP_TextProcessingStack_FontWeight__VTable vtable;
};
struct TMPro_TMP_TextProcessingStack_FontWeight__o {
	TMPro_TMP_TextProcessingStack_FontWeight__Fields fields;
};

struct TMPro_VertexGradient_Fields {
	struct UnityEngine_Color_o topLeft;
	struct UnityEngine_Color_o topRight;
	struct UnityEngine_Color_o bottomLeft;
	struct UnityEngine_Color_o bottomRight;
};
struct TMPro_VertexGradient_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct TMPro_VertexGradient_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	TMPro_VertexGradient_VTable vtable;
};
struct TMPro_VertexGradient_o {
	TMPro_VertexGradient_Fields fields;
};

struct System_Delegate_Fields {
	intptr_t method_ptr;
	intptr_t invoke_impl;
	Il2CppObject* m_target;
	intptr_t method;
	intptr_t delegate_trampoline;
	intptr_t extra_arg;
	intptr_t method_code;
	intptr_t interp_method;
	intptr_t interp_invoke_impl;
	struct System_Reflection_MethodInfo_o* method_info;
	struct System_Reflection_MethodInfo_o* original_method_info;
	struct System_DelegateData_o* data;
	bool method_is_virtual;
};
struct System_Delegate_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_Clone;
	VirtualInvokeData _7_GetMethodImpl;
	VirtualInvokeData _8_GetObjectData;
	VirtualInvokeData _9_GetInvocationList;
	VirtualInvokeData _10_CombineImpl;
	VirtualInvokeData _11_RemoveImpl;
};
struct System_Delegate_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Delegate_VTable vtable;
};
struct System_Delegate_o {
	System_Delegate_c *klass;
	void *monitor;
	System_Delegate_Fields fields;
};
struct System_MulticastDelegate_Fields : System_Delegate_Fields {
	struct System_Delegate_array* delegates;
};

struct System_Action_T__Fields : System_MulticastDelegate_Fields {
};
struct System_Action_T__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_Clone;
	VirtualInvokeData _7_GetMethodImpl;
	VirtualInvokeData _8_GetObjectData;
	VirtualInvokeData _9_GetInvocationList;
	VirtualInvokeData _10_CombineImpl;
	VirtualInvokeData _11_RemoveImpl;
	VirtualInvokeData _12_Invoke;
};
struct System_Action_T__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Action_T__VTable vtable;
};
struct System_Action_T__o {
	System_Action_T__c *klass;
	void *monitor;
	System_Action_T__Fields fields;
};

struct MethodInfo_108E1F0 {
	Il2CppMethodPointer methodPointer;
	Il2CppMethodPointer virtualMethodPointer;
	InvokerMethod invoker_method;
	const char* name;
	System_Action_T__c *klass;
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
};

struct System_Action_string__Fields : System_MulticastDelegate_Fields {
};
struct System_Action_string__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_Clone;
	VirtualInvokeData _7_GetMethodImpl;
	VirtualInvokeData _8_GetObjectData;
	VirtualInvokeData _9_GetInvocationList;
	VirtualInvokeData _10_CombineImpl;
	VirtualInvokeData _11_RemoveImpl;
	VirtualInvokeData _12_Invoke;
};
struct System_Action_string__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Action_string__VTable vtable;
};
struct System_Action_string__o {
	System_Action_string__c *klass;
	void *monitor;
	System_Action_string__Fields fields;
};

struct System_Action_object__Fields : System_MulticastDelegate_Fields {
};
struct System_Action_object__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_Clone;
	VirtualInvokeData _7_GetMethodImpl;
	VirtualInvokeData _8_GetObjectData;
	VirtualInvokeData _9_GetInvocationList;
	VirtualInvokeData _10_CombineImpl;
	VirtualInvokeData _11_RemoveImpl;
	VirtualInvokeData _12_Invoke;
};
struct System_Action_object__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Action_object__VTable vtable;
};
struct System_Action_object__o {
	System_Action_object__c *klass;
	void *monitor;
	System_Action_object__Fields fields;
};

struct TMPro_TMP_Text_Fields : UnityEngine_UI_MaskableGraphic_Fields {
	struct System_String_o* m_text;
	bool m_IsTextBackingStringDirty;
	struct TMPro_ITextPreprocessor_o* m_TextPreprocessor;
	bool m_isRightToLeft;
	struct TMPro_TMP_FontAsset_o* m_fontAsset;
	struct TMPro_TMP_FontAsset_o* m_currentFontAsset;
	bool m_isSDFShader;
	struct UnityEngine_Material_o* m_sharedMaterial;
	struct UnityEngine_Material_o* m_currentMaterial;
	int32_t m_currentMaterialIndex;
	struct UnityEngine_Material_array* m_fontSharedMaterials;
	struct UnityEngine_Material_o* m_fontMaterial;
	struct UnityEngine_Material_array* m_fontMaterials;
	bool m_isMaterialDirty;
	struct UnityEngine_Color32_o m_fontColor32;
	struct UnityEngine_Color_o m_fontColor;
	struct UnityEngine_Color32_o m_underlineColor;
	struct UnityEngine_Color32_o m_strikethroughColor;
	bool m_enableVertexGradient;
	int32_t m_colorMode;
	struct TMPro_VertexGradient_o m_fontColorGradient;
	struct TMPro_TMP_ColorGradient_o* m_fontColorGradientPreset;
	struct TMPro_TMP_SpriteAsset_o* m_spriteAsset;
	bool m_tintAllSprites;
	bool m_tintSprite;
	struct UnityEngine_Color32_o m_spriteColor;
	struct TMPro_TMP_StyleSheet_o* m_StyleSheet;
	struct TMPro_TMP_Style_o* m_TextStyle;
	int32_t m_TextStyleHashCode;
	bool m_overrideHtmlColors;
	struct UnityEngine_Color32_o m_faceColor;
	struct UnityEngine_Color32_o m_outlineColor;
	float m_outlineWidth;
	float m_fontSize;
	float m_currentFontSize;
	float m_fontSizeBase;
	struct TMPro_TMP_TextProcessingStack_float__o m_sizeStack;
	int32_t m_fontWeight;
	int32_t m_FontWeightInternal;
	struct TMPro_TMP_TextProcessingStack_FontWeight__o m_FontWeightStack;
	bool m_enableAutoSizing;
	float m_maxFontSize;
	float m_minFontSize;
	int32_t m_AutoSizeIterationCount;
	int32_t m_AutoSizeMaxIterationCount;
	bool m_IsAutoSizePointSizeSet;
	float m_fontSizeMin;
	float m_fontSizeMax;
	int32_t m_fontStyle;
	int32_t m_FontStyleInternal;
	struct TMPro_TMP_FontStyleStack_o m_fontStyleStack;
	bool m_isUsingBold;
	int32_t m_HorizontalAlignment;
	int32_t m_VerticalAlignment;
	int32_t m_textAlignment;
	int32_t m_lineJustification;
	struct TMPro_TMP_TextProcessingStack_HorizontalAlignmentOptions__o m_lineJustificationStack;
	struct UnityEngine_Vector3_array* m_textContainerLocalCorners;
	float m_characterSpacing;
	float m_cSpacing;
	float m_monoSpacing;
	float m_wordSpacing;
	float m_lineSpacing;
	float m_lineSpacingDelta;
	float m_lineHeight;
	bool m_IsDrivenLineSpacing;
	float m_lineSpacingMax;
	float m_paragraphSpacing;
	float m_charWidthMaxAdj;
	float m_charWidthAdjDelta;
	bool m_enableWordWrapping;
	bool m_isCharacterWrappingEnabled;
	bool m_isNonBreakingSpace;
	bool m_isIgnoringAlignment;
	float m_wordWrappingRatios;
	int32_t m_overflowMode;
	int32_t m_firstOverflowCharacterIndex;
	struct TMPro_TMP_Text_o* m_linkedTextComponent;
	struct TMPro_TMP_Text_o* parentLinkedComponent;
	bool m_isTextTruncated;
	bool m_enableKerning;
	float m_GlyphHorizontalAdvanceAdjustment;
	bool m_enableExtraPadding;
	bool checkPaddingRequired;
	bool m_isRichText;
	bool m_parseCtrlCharacters;
	bool m_isOverlay;
	bool m_isOrthographic;
	bool m_isCullingEnabled;
	bool m_isMaskingEnabled;
	bool isMaskUpdateRequired;
	bool m_ignoreCulling;
	int32_t m_horizontalMapping;
	int32_t m_verticalMapping;
	float m_uvLineOffset;
	int32_t m_renderMode;
	int32_t m_geometrySortingOrder;
	bool m_IsTextObjectScaleStatic;
	bool m_VertexBufferAutoSizeReduction;
	int32_t m_firstVisibleCharacter;
	int32_t m_maxVisibleCharacters;
	int32_t m_maxVisibleWords;
	int32_t m_maxVisibleLines;
	bool m_useMaxVisibleDescender;
	int32_t m_pageToDisplay;
	bool m_isNewPage;
	struct UnityEngine_Vector4_o m_margin;
	float m_marginLeft;
	float m_marginRight;
	float m_marginWidth;
	float m_marginHeight;
	float m_width;
	struct TMPro_TMP_TextInfo_o* m_textInfo;
	bool m_havePropertiesChanged;
	bool m_isUsingLegacyAnimationComponent;
	struct UnityEngine_Transform_o* m_transform;
	struct UnityEngine_RectTransform_o* m_rectTransform;
	struct UnityEngine_Vector2_o m_PreviousRectTransformSize;
	struct UnityEngine_Vector2_o m_PreviousPivotPosition;
	bool _autoSizeTextContainer_k__BackingField;
	bool m_autoSizeTextContainer;
	struct UnityEngine_Mesh_o* m_mesh;
	bool m_isVolumetricText;
	struct System_Action_TMP_TextInfo__o* OnPreRenderText;
	struct TMPro_TMP_SpriteAnimator_o* m_spriteAnimator;
	float m_flexibleHeight;
	float m_flexibleWidth;
	float m_minWidth;
	float m_minHeight;
	float m_maxWidth;
	float m_maxHeight;
	struct UnityEngine_UI_LayoutElement_o* m_LayoutElement;
	float m_preferredWidth;
	float m_renderedWidth;
	bool m_isPreferredWidthDirty;
	float m_preferredHeight;
	float m_renderedHeight;
	bool m_isPreferredHeightDirty;
	bool m_isCalculatingPreferredValues;
	int32_t m_layoutPriority;
	bool m_isLayoutDirty;
	bool m_isAwake;
	bool m_isWaitingOnResourceLoad;
	int32_t m_inputSource;
	float m_fontScaleMultiplier;
	float tag_LineIndent;
	float tag_Indent;
	struct TMPro_TMP_TextProcessingStack_float__o m_indentStack;
	bool tag_NoParsing;
	bool m_isParsingText;
	struct UnityEngine_Matrix4x4_o m_FXMatrix;
	bool m_isFXMatrixSet;
	struct TMPro_TMP_Text_UnicodeChar_array* m_TextProcessingArray;
	int32_t m_InternalTextProcessingArraySize;
	struct TMPro_TMP_CharacterInfo_array* m_internalCharacterInfo;
	int32_t m_totalCharacterCount;
	int32_t m_characterCount;
	int32_t m_firstCharacterOfLine;
	int32_t m_firstVisibleCharacterOfLine;
	int32_t m_lastCharacterOfLine;
	int32_t m_lastVisibleCharacterOfLine;
	int32_t m_lineNumber;
	int32_t m_lineVisibleCharacterCount;
	int32_t m_pageNumber;
	float m_PageAscender;
	float m_maxTextAscender;
	float m_maxCapHeight;
	float m_ElementAscender;
	float m_ElementDescender;
	float m_maxLineAscender;
	float m_maxLineDescender;
	float m_startOfLineAscender;
	float m_startOfLineDescender;
	float m_lineOffset;
	struct TMPro_Extents_o m_meshExtents;
	struct UnityEngine_Color32_o m_htmlColor;
	struct TMPro_TMP_TextProcessingStack_Color32__o m_colorStack;
	struct TMPro_TMP_TextProcessingStack_Color32__o m_underlineColorStack;
	struct TMPro_TMP_TextProcessingStack_Color32__o m_strikethroughColorStack;
	struct TMPro_TMP_TextProcessingStack_HighlightState__o m_HighlightStateStack;
	struct TMPro_TMP_ColorGradient_o* m_colorGradientPreset;
	struct TMPro_TMP_TextProcessingStack_TMP_ColorGradient__o m_colorGradientStack;
	bool m_colorGradientPresetIsTinted;
	float m_tabSpacing;
	float m_spacing;
	struct TMPro_TMP_TextProcessingStack_int__array* m_TextStyleStacks;
	int32_t m_TextStyleStackDepth;
	struct TMPro_TMP_TextProcessingStack_int__o m_ItalicAngleStack;
	int32_t m_ItalicAngle;
	struct TMPro_TMP_TextProcessingStack_int__o m_actionStack;
	float m_padding;
	float m_baselineOffset;
	struct TMPro_TMP_TextProcessingStack_float__o m_baselineOffsetStack;
	float m_xAdvance;
	int32_t m_textElementType;
	struct TMPro_TMP_TextElement_o* m_cached_TextElement;
	struct TMPro_TMP_Text_SpecialCharacter_o m_Ellipsis;
	struct TMPro_TMP_Text_SpecialCharacter_o m_Underline;
	struct TMPro_TMP_SpriteAsset_o* m_defaultSpriteAsset;
	struct TMPro_TMP_SpriteAsset_o* m_currentSpriteAsset;
	int32_t m_spriteCount;
	int32_t m_spriteIndex;
	int32_t m_spriteAnimationID;
	bool m_ignoreActiveState;
	struct TMPro_TMP_Text_TextBackingContainer_o m_TextBackingArray;
	struct System_Decimal_array* k_Power;
};

struct TMPro_TextMeshProUGUI_Fields : TMPro_TMP_Text_Fields {
	bool m_isRebuildingLayout;
	struct UnityEngine_Coroutine_o* m_DelayedGraphicRebuild;
	struct UnityEngine_Coroutine_o* m_DelayedMaterialRebuild;
	struct UnityEngine_Rect_o m_ClipRect;
	bool m_ValidRect;
	struct System_Action_TMP_TextInfo__o* OnPreRenderText;
	bool m_hasFontAssetChanged;
	struct TMPro_TMP_SubMeshUI_array* m_subTextObjects;
	float m_previousLossyScaleY;
	struct UnityEngine_Vector3_array* m_RectTransformCorners;
	struct UnityEngine_CanvasRenderer_o* m_canvasRenderer;
	struct UnityEngine_Canvas_o* m_canvas;
	float m_CanvasScaleFactor;
	bool m_isFirstAllocation;
	int32_t m_max_characters;
	struct UnityEngine_Material_o* m_baseMaterial;
	bool m_isScrollRegionSet;
	struct UnityEngine_Vector4_o m_maskOffset;
	struct UnityEngine_Matrix4x4_o m_EnvMapMatrix;
	bool m_isRegisteredForEvents;
};

struct TMPro_TextMeshProUGUI_o {
	TMPro_TextMeshProUGUI_c *klass;
	void *monitor;
	TMPro_TextMeshProUGUI_Fields fields;
};
struct TMPro_TMP_Text_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Awake;
	VirtualInvokeData _5_OnEnable;
	VirtualInvokeData _6_Start;
	VirtualInvokeData _7_OnDisable;
	VirtualInvokeData _8_OnDestroy;
	VirtualInvokeData _9_IsActive;
	VirtualInvokeData _10_OnRectTransformDimensionsChange;
	VirtualInvokeData _11_OnBeforeTransformParentChanged;
	VirtualInvokeData _12_OnTransformParentChanged;
	VirtualInvokeData _13_OnDidApplyAnimationProperties;
	VirtualInvokeData _14_OnCanvasGroupChanged;
	VirtualInvokeData _15_OnCanvasHierarchyChanged;
	VirtualInvokeData _16_IsDestroyed;
	VirtualInvokeData _17_unknown;
	VirtualInvokeData _18_UnityEngine_UI_ICanvasElement_get_transform;
	VirtualInvokeData _19_unknown;
	VirtualInvokeData _20_unknown;
	VirtualInvokeData _21_unknown;
	VirtualInvokeData _22_get_color;
	VirtualInvokeData _23_set_color;
	VirtualInvokeData _24_get_raycastTarget;
	VirtualInvokeData _25_set_raycastTarget;
	VirtualInvokeData _26_SetAllDirty;
	VirtualInvokeData _27_SetLayoutDirty;
	VirtualInvokeData _28_SetVerticesDirty;
	VirtualInvokeData _29_SetMaterialDirty;
	VirtualInvokeData _30_get_rectTransform;
	VirtualInvokeData _31_get_defaultMaterial;
	VirtualInvokeData _32_get_material;
	VirtualInvokeData _33_set_material;
	VirtualInvokeData _34_get_materialForRendering;
	VirtualInvokeData _35_get_mainTexture;
	VirtualInvokeData _36_OnCullingChanged;
	VirtualInvokeData _37_Rebuild;
	VirtualInvokeData _38_LayoutComplete;
	VirtualInvokeData _39_GraphicUpdateComplete;
	VirtualInvokeData _40_UpdateMaterial;
	VirtualInvokeData _41_UpdateGeometry;
	VirtualInvokeData _42_OnFillVBO;
	VirtualInvokeData _43_OnPopulateMesh;
	VirtualInvokeData _44_OnPopulateMesh;
	VirtualInvokeData _45_SetNativeSize;
	VirtualInvokeData _46_Raycast;
	VirtualInvokeData _47_CrossFadeColor;
	VirtualInvokeData _48_CrossFadeColor;
	VirtualInvokeData _49_CrossFadeAlpha;
	VirtualInvokeData _50_UnityEngine_UI_IClippable_get_gameObject;
	VirtualInvokeData _51_unknown;
	VirtualInvokeData _52_unknown;
	VirtualInvokeData _53_unknown;
	VirtualInvokeData _54_unknown;
	VirtualInvokeData _55_unknown;
	VirtualInvokeData _56_unknown;
	VirtualInvokeData _57_unknown;
	VirtualInvokeData _58_GetModifiedMaterial;
	VirtualInvokeData _59_Cull;
	VirtualInvokeData _60_SetClipRect;
	VirtualInvokeData _61_SetClipSoftness;
	VirtualInvokeData _62_ParentMaskStateChanged;
	VirtualInvokeData _63_RecalculateClipping;
	VirtualInvokeData _64_RecalculateMasking;
	VirtualInvokeData _65_get_text;
	VirtualInvokeData _66_set_text;
	VirtualInvokeData _67_get_fontSharedMaterial;
	VirtualInvokeData _68_set_fontSharedMaterial;
	VirtualInvokeData _69_get_fontSharedMaterials;
	VirtualInvokeData _70_set_fontSharedMaterials;
	VirtualInvokeData _71_get_fontMaterials;
	VirtualInvokeData _72_set_fontMaterials;
	VirtualInvokeData _73_get_margin;
	VirtualInvokeData _74_set_margin;
	VirtualInvokeData _75_get_autoSizeTextContainer;
	VirtualInvokeData _76_set_autoSizeTextContainer;
	VirtualInvokeData _77_get_mesh;
	VirtualInvokeData _78_add_OnPreRenderText;
	VirtualInvokeData _79_remove_OnPreRenderText;
	VirtualInvokeData _80_get_flexibleHeight;
	VirtualInvokeData _81_get_flexibleWidth;
	VirtualInvokeData _82_get_minWidth;
	VirtualInvokeData _83_get_minHeight;
	VirtualInvokeData _84_get_preferredWidth;
	VirtualInvokeData _85_get_preferredHeight;
	VirtualInvokeData _86_get_renderedWidth;
	VirtualInvokeData _87_get_renderedHeight;
	VirtualInvokeData _88_get_layoutPriority;
	VirtualInvokeData _89_LoadFontAsset;
	VirtualInvokeData _90_SetSharedMaterial;
	VirtualInvokeData _91_GetMaterial;
	VirtualInvokeData _92_SetFontBaseMaterial;
	VirtualInvokeData _93_GetSharedMaterials;
	VirtualInvokeData _94_SetSharedMaterials;
	VirtualInvokeData _95_GetMaterials;
	VirtualInvokeData _96_CreateMaterialInstance;
	VirtualInvokeData _97_SetFaceColor;
	VirtualInvokeData _98_SetOutlineColor;
	VirtualInvokeData _99_SetOutlineThickness;
	VirtualInvokeData _100_SetShaderDepth;
	VirtualInvokeData _101_SetCulling;
	VirtualInvokeData _102_UpdateCulling;
	VirtualInvokeData _103_GetPaddingForMaterial;
	VirtualInvokeData _104_GetPaddingForMaterial;
	VirtualInvokeData _105_GetTextContainerLocalCorners;
	VirtualInvokeData _106_ForceMeshUpdate;
	VirtualInvokeData _107_UpdateGeometry;
	VirtualInvokeData _108_UpdateVertexData;
	VirtualInvokeData _109_UpdateVertexData;
	VirtualInvokeData _110_SetVertices;
	VirtualInvokeData _111_UpdateMeshPadding;
	VirtualInvokeData _112_InternalCrossFadeColor;
	VirtualInvokeData _113_InternalCrossFadeAlpha;
	VirtualInvokeData _114_SetArraySizes;
	VirtualInvokeData _115_CalculatePreferredValues;
	VirtualInvokeData _116_GetCompoundBounds;
	VirtualInvokeData _117_GetCanvasSpaceClippingRect;
	VirtualInvokeData _118_GetTextInfo;
	VirtualInvokeData _119_ComputeMarginSize;
	VirtualInvokeData _120_SaveGlyphVertexInfo;
	VirtualInvokeData _121_SaveSpriteVertexInfo;
	VirtualInvokeData _122_FillCharacterVertexBuffers;
	VirtualInvokeData _123_FillCharacterVertexBuffers;
	VirtualInvokeData _124_FillSpriteVertexBuffers;
	VirtualInvokeData _125_DrawUnderlineMesh;
	VirtualInvokeData _126_DrawTextHighlight;
	VirtualInvokeData _127_SetActiveSubMeshes;
	VirtualInvokeData _128_DestroySubMeshObjects;
	VirtualInvokeData _129_ClearMesh;
	VirtualInvokeData _130_ClearMesh;
	VirtualInvokeData _131_GetParsedText;
	VirtualInvokeData _132_InternalUpdate;
};
