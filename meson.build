project('tribenine_zero', ['c', 'cpp'], default_options : ['warning_level=3'])

cc = meson.get_compiler('c')

ntdll_lib = cc.find_library('ntdll')

libpeconv_proj = subproject('libpeconv')
libpeconv_dep = libpeconv_proj.get_variable('libpeconv_dep')

minhook_proj = subproject('minhook')
libminhook_dep = minhook_proj.get_variable('libminhook_dep')

sds_proj = subproject('sds')
sds_dep = sds_proj.get_variable('libsds_dep')

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
    'HookExample.cpp',
    'StackTraceLogger.c'
]

zero_deps = [libminhook_dep, ntdll_lib, libpeconv_dep, sds_dep]

shared_library('zero', zero_src, dependencies : zero_deps)

executable('loader', 'loader.c')
executable('metadata_test', 'metadata_test.c', 'MetadataDump.c')
executable('printsections', 'printsections.c', 'MetadataDump.c', dependencies : ntdll_lib)
executable('test_utf', 'test_utf.c', 'utils.c', dependencies : sds_dep)

executable(
    'reconsdll', 'reconsdll.cpp', 'MetadataDump.c', 'Section.c', 'Recons.cpp',
    dependencies : [libpeconv_dep, ntdll_lib]
)

executable('RegenSections', 'RegenSections.c', 'Section.c')
executable(
    'Bruteforce', 'Bruteforce.c', 'Recons.cpp', 'MetadataDump.c', 'Section.c',
    dependencies : [libpeconv_dep, ntdll_lib])

executable('test_stacktrace_logger', 'test_stacktrace_logger.c', zero_src, dependencies : zero_deps)