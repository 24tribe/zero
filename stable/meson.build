dumper_out_proj = subproject('dumper_out')
script_json = dumper_out_proj.get_variable('script_json')

UnityPlayer_proj = subproject('UnityPlayer')

func_ptrs = custom_target(
    'il2cppFuncPtrs',
    input : ['../scripts/genIl2CppPtrs.py', script_json, 'gameFuncs.txt', 'typeInfos.txt'],
    output : 'funcPtrs.h',
    command : [python3, '@INPUT@', '@OUTPUT@']
)

autohook_tn = custom_target(
    'autohookTN',
    input: ['../scripts/genReqHook.py', script_json, 'reqHooks.csv'],
    output : 'autohookTN.h',
    command : [python3, '@INPUT@', 'requestHandler', '@OUTPUT@']
)

zero_incdir = include_directories('.')

zero_src = [
    zero_common_src,
    func_ptrs,
    autohook_tn,
]