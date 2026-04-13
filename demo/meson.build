dumper_out_cbt_proj = subproject('dumper_out_cbt')
script_json_demo = dumper_out_cbt_proj.get_variable('script_json')

UnityPlayer_proj = subproject('UnityPlayer_0_2_1_20')

func_ptrs_demo = custom_target(
    'il2cppFuncPtrsDemo',
    input : ['../scripts/genIl2CppPtrs.py', script_json_demo, 'gameFuncsDemo.txt', 'typeInfosDemo.txt'],
    output : 'funcPtrs.h',
    command : [python3, '@INPUT@', '@OUTPUT@']
)

autohook_tn_demo = custom_target(
    'autohookTNDemo',
    input: ['../scripts/genReqHook.py', script_json_demo, 'reqHooksDemo.csv'],
    output : 'autohookTN.h',
    command : [python3, '@INPUT@', 'requestHandle', '@OUTPUT@']
)

zero_incdir = include_directories('.')

zero_src = [
    zero_common_src,
    func_ptrs_demo,
    autohook_tn_demo,
    files('version_specific_hooks.c'),
]