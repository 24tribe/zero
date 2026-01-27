project('tribenine_zero', ['c', 'cpp'], default_options : ['warning_level=3'])

add_global_link_arguments('-static', language : ['c', 'cpp'])

cc = meson.get_compiler('c')
fs = import('fs')
python3 = find_program('python3', required : true)

webview_proj = subproject('webview-55b438dc11d0e46bc68526822380963ae9d362af')
webview_dep = webview_proj.get_variable('webview_dep')

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
subdir('autogen_demo')
subdir('gui')

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
    're.c',
    'sds_utf_conv.c',
    'Patterns.c',
    'dump_ga/GameAssemblyDump.c',
    'dump_ga/MetadataDump.c',
    'version.c',
    'create_file_hook.c',
    'SavesHelper.cpp',
    'TimeUtil.c',
    gui_src,
]

zero_stable_incdir = include_directories('stable')

zero_stable_src = [
    zero_src,
    func_ptrs,
    autohook_tn,
]

zero_demo_incdir = include_directories('demo')

zero_demo_src = [
    zero_src,
    func_ptrs_demo,
    autohook_tn_demo,
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

shared_library(
    'zero', zero_stable_src, dependencies : zero_deps, install : true,
    install_dir : '.', include_directories : zero_stable_incdir
)

shared_library(
    'zerodemo', zero_demo_src, dependencies : zero_deps, install : true,
    install_dir : '.', include_directories : zero_demo_incdir
)

executable('loader', 'loader.c', 'LoaderAux.c')
executable('test_utf', 'test_utf.c', 'sds_utf_conv.c', dependencies : sds_dep)

executable('test_re', 'test_re.c', 're.c', 'Patterns.c', dependencies : sds_dep)

subdir('dump_ga')
subdir('launcher')