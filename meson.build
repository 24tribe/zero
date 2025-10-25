project('tribenine_zero', ['c', 'cpp'], default_options : ['warning_level=3'])

cc = meson.get_compiler('c')

ntdll_lib = cc.find_library('ntdll')

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

fs = import('fs')
semba_nimble = fs.copyfile('semba.nimble')
sqlite3_c = fs.copyfile('sqlite3.c')

libsemba = custom_target(
    'libsemba',
    depends : [semba_nimble, sqlite3_c],
    input : ['semba.nim'],
    output : 'libsemba.a',
    command : ['nimble', 'c', '-d:staticSqlite', '--verbose', '--app:staticlib', '--noMain:on', '-o:@OUTPUT@', '@INPUT@']
)

sqlite3 = find_program('sqlite3', required : true)

semba_db = custom_target(
    'semba_db',
    input : 'semba.sql',
    output : 'semba.db',
    command : [sqlite3, '@OUTPUT@'],
    feed : true,
    build_by_default : true
)

python3 = find_program('python3', required : true)

func_ptrs = custom_target(
    'il2cppFuncPtrs',
    input : ['scripts/genIl2CppPtrs.py', 'dumper_out/script.json', 'gameFuncs.txt', 'typeInfos.txt'],
    output : 'funcPtrs.h',
    command : [python3, '@INPUT@', '@OUTPUT@']
)

zero_src = [
    'mylib.c',
    'load_library_hook.c',
    'NtQueryDirectoryFileHook.c',
    'RemapMem.c',
    'MetadataDump.c',
    'Recons.cpp',
    'Section.c',
    'create_file_hook.c',
    'utils.c',
    'HookIl2Cpp.c',
    'HookTN.c',
    'Logger.c',
    'Config.c',
    'Il2CppHelper.c',
    'TimeString.c',
    'FuncPtrs.c',
    func_ptrs
]

semba_dep = declare_dependency(
    link_with : libsemba
)

zero_deps = [
    libminhook_dep,
    ntdll_lib,
    libpeconv_dep,
    sds_dep,
    jansson_dep,
    inih_dep,
    semba_dep
]

shared_library('zero', zero_src, dependencies : zero_deps)

executable('loader', 'loader.c')
executable('metadata_test', 'metadata_test.c', 'MetadataDump.c')
executable('printsections', 'printsections.c', 'MetadataDump.c', dependencies : ntdll_lib)
executable('test_utf', 'test_utf.c', zero_src, dependencies : zero_deps)

executable(
    'reconsdll', 'reconsdll.cpp', 'MetadataDump.c', 'Section.c', 'Recons.cpp',
    dependencies : [libpeconv_dep, ntdll_lib]
)

executable('RegenSections', 'RegenSections.c', 'Section.c')

executable('test_stacktrace_logger', 'test_stacktrace_logger.c', zero_src, dependencies : zero_deps)

executable('test_jansson', 'test_jansson.c', zero_src, dependencies : zero_deps)

executable('test_semba', 'test_semba.c', dependencies : [semba_dep])

executable('semba', 'semba.c', dependencies : [semba_dep])