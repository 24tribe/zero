project('tribenine_zero', ['c', 'cpp'], default_options : ['warning_level=3'], meson_version : '>=1.4.0')

game_version = get_option('game_version')
dump_ga_support = get_option('dump_ga_support')

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

semba_project = subproject('semba', default_options : 'default_library=static')
semba_dep = semba_project.get_variable('semba_dep')

subdir('gui')
subdir('bundlemod')

zero_common_src = [
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

if game_version == '1.1.3.35'
    subdir('stable')
elif game_version == '0.2.1.20'
    subdir('demo')
endif

libcurl_dep = dependency('libcurl', default_options : [
    'default_library=static',
    'alt-svc=disabled', 'proxy=disabled','kerberos-auth=disabled', 'dict=disabled',
    'file=disabled', 'ftp=disabled', 'gopher=disabled', 'imap=disabled',
    'ipfs=disabled', 'ldap=disabled', 'ldaps=disabled', 'mqtt=disabled',
    'pop3=disabled', 'rtmp=disabled', 'rtsp=disabled', 'smb=disabled',
    'smtp=disabled', 'telnet=disabled', 'tftp=disabled', 'websockets=disabled',
    'ntlm=disabled',
])

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
    'UnityPlayer', zero_src, dependencies : zero_deps, install : true,
    install_dir : '.', include_directories : zero_incdir,
    link_with : bundlemod,
    link_args: '-s',
    vs_module_defs: 'UnityPlayer.def',
    name_prefix : '',
)

executable('test_utf', 'test_utf.c', 'sds_utf_conv.c', dependencies : sds_dep)

executable('test_re', 'test_re.c', 're.c', 'Patterns.c', dependencies : sds_dep)

test_hair_color_helper = executable(
    'test_hair_color_helper', 'test_hair_color_helper.cpp', 'HairColorHelper.cpp'
)
test('test hair color helper', test_hair_color_helper)

subdir('dump_ga')

fs.copyfile('LICENSE', 'LICENSE.txt', install : true, install_dir : '.')
fs.copyfile('THIRD_PARTY_LICENSES.txt', install : true, install_dir : '.')