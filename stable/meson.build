dumper_out_proj = subproject('dumper_out')
script_json = dumper_out_proj.get_variable('script_json')

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