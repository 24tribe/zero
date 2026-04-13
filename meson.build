project('tribenine_zero', ['c', 'cpp'], default_options : ['warning_level=3'], meson_version : '>=1.4.0')

dump_ga_support = get_option('dump_ga_support')
build_libzero_demo = get_option('build_libzero_demo')

add_project_arguments('-Wno-pedantic', language : ['c', 'cpp'])
add_global_link_arguments('-static', language : ['c', 'cpp'])

cc = meson.get_compiler('c')
fs = import('fs')
python3 = find_program('python3', required : true)

ntdll_lib = cc.find_library('ntdll')
shlwapi_lib = cc.find_library('shlwapi')

if dump_ga_support
libpeconv_proj = subproject('libpeconv')
libpeconv_dep = libpeconv_proj.get_variable('libpeconv_dep')
endif

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

UnityPlayer_proj = subproject('UnityPlayer')
UnityPlayer = UnityPlayer_proj.get_variable('UnityPlayer')

semba_project = subproject('semba', default_options : 'default_library=static')
semba_dep = semba_project.get_variable('semba_dep')

subdir('stable')
# subdir('autogen_demo')
subdir('gui')
subdir('bundlemod')

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
    'runtime_version.c',
    'create_file_hook.c',
    'TimeUtil.c',
    'ModHelper.cpp',
    'HairColorHelper.cpp',
    'SembaContext.c',
    'SembaRemote.cpp',
    gui_src,
]

zero_stable_incdir = include_directories('stable')

zero_stable_src = [
    zero_src,
    func_ptrs,
    autohook_tn,
]

if build_libzero_demo
zero_demo_incdir = include_directories('demo')

zero_demo_src = [
    zero_src,
    func_ptrs_demo,
    autohook_tn_demo,
]
endif

libcurl_dep = dependency('libcurl', default_options : 'default_library=static')

zero_deps = [
    libminhook_dep,
    ntdll_lib,
    sds_dep,
    jansson_dep,
    inih_dep,
    semba_dep,
    shlwapi_lib,
    imgui,
    libcurl_dep,
]

if dump_ga_support
    zero_deps += [libpeconv_dep]
endif

shared_library(
    'UnityPlayer', zero_stable_src, dependencies : zero_deps, install : true,
    install_dir : '.', include_directories : zero_stable_incdir,
    link_with : bundlemod,
    link_args: '-s',
    vs_module_defs: 'UnityPlayer.def',
    name_prefix : '',
)

if build_libzero_demo
shared_library(
    'zerodemo', zero_demo_src, dependencies : zero_deps, install : true,
    install_dir : '.', include_directories : zero_demo_incdir,
    link_with : bundlemod
)
endif

executable('test_utf', 'test_utf.c', 'sds_utf_conv.c', dependencies : sds_dep)

executable('test_re', 'test_re.c', 're.c', 'Patterns.c', dependencies : sds_dep)

test_hair_color_helper = executable(
    'test_hair_color_helper', 'test_hair_color_helper.cpp', 'HairColorHelper.cpp'
)
test('test hair color helper', test_hair_color_helper)

subdir('dump_ga')

fs.copyfile('LICENSE', 'LICENSE.txt', install : true, install_dir : '.')
fs.copyfile('THIRD_PARTY_LICENSES.txt', install : true, install_dir : '.')