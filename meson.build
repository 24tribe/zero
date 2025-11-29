project('tribenine_zero', ['c', 'cpp'], default_options : ['warning_level=3'])

add_global_link_arguments('-static', language : ['c', 'cpp'])

cc = meson.get_compiler('c')
fs = import('fs')
python3 = find_program('python3', required : true)

webview_proj = subproject('webview-55b438dc11d0e46bc68526822380963ae9d362af')
webview_dep = webview_proj.get_variable('webview_dep')

d3d11_lib = cc.find_library('d3d11')
imgui = dependency('imgui', default_options : 'default_library=static')

ntdll_lib = cc.find_library('ntdll')
shlwapi_lib = cc.find_library('shlwapi')

libpeconv_proj = subproject('libpeconv')
libpeconv_dep = libpeconv_proj.get_variable('libpeconv_dep')

minhook_proj = subproject('minhook')
libminhook_dep = minhook_proj.get_variable('libminhook_dep')

sds_proj = subproject('sds')
sds_dep = sds_proj.get_variable('libsds_dep')

jansson_proj = subproject('jansson')
jansson_dep = jansson_proj.get_variable('libjansson_dep')

inih_proj = subproject('inih')
inih_dep = inih_proj.get_variable('libinih_dep')

fs.copyfile('config.ini.dist', 'config.ini', install : true, install_dir : '.')
fs.copyfile('steam_appid.txt', install : true, install_dir : '.')

dumper_out_proj = subproject('dumper_out')
script_json = dumper_out_proj.get_variable('script_json')

goldberg_steam_proj = subproject('goldberg_steam')
goldberg_steam = goldberg_steam_proj.get_variable('steam_api64')

subdir('semba')
subdir('autogen')

zero_src = [
    'mylib.c',
    'load_library_hook.c',
    'NtQueryDirectoryFileHook.c',
    'RemapMem.c',
    'utils.c',
    'HookIl2Cpp.c',
    'HookTN.c',
    'Logger.c',
    'Config.c',
    'Il2CppHelper.c',
    'TimeString.c',
    'FuncPtrs.c',
    'md5sum.c',
    func_ptrs,
    autohook_tn,
    're.c',
    'sds_utf_conv.c',
    'Patterns.c',
    'Backend.cpp',
    'UserInterface.cpp',
    'DrawFunc.cpp',
    'dump_ga/GameAssemblyDump.c',
    'dump_ga/MetadataDump.c',
]

zero_deps = [
    libminhook_dep,
    ntdll_lib,
    libpeconv_dep,
    sds_dep,
    jansson_dep,
    inih_dep,
    semba_dep,
    shlwapi_lib,
    imgui
]

shared_library('zero', zero_src, dependencies : zero_deps, install : true, install_dir : '.')

executable('loader', 'loader.c', install : true, install_dir : '.')
executable('test_utf', 'test_utf.c', 'sds_utf_conv.c', dependencies : sds_dep)

executable('test_re', 'test_re.c', 're.c', 'Patterns.c', dependencies : sds_dep)

executable('test_xoshiro256pp', 'test_xoshiro256pp.c', 'xoshiro256pp.c')

executable('imguitest', 'imguitest.cpp', 'DrawFunc.cpp', dependencies : [d3d11_lib, imgui])

subdir('dump_ga')
subdir('launcher')