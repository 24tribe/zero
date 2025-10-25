project('tribenine_zero', ['c', 'cpp'], default_options : ['warning_level=3'])

cc = meson.get_compiler('c')

ntdll_lib = cc.find_library('ntdll')

libpeconv_proj = subproject('libpeconv')
libpeconv_dep = libpeconv_proj.get_variable('libpeconv_dep')

minhook_proj = subproject('minhook')
libminhook_dep = minhook_proj.get_variable('libminhook_dep')

zero_src = [
    'mylib.c',
    'load_library_hook.c',
    'NtQueryDirectoryFileHook.c',
    'RemapMem.c',
    'MetadataDump.c',
    'Recons.cpp',
    'Section.c'
]

shared_library('zero', zero_src, dependencies : [libminhook_dep, ntdll_lib, libpeconv_dep])

executable('loader', 'loader.c')
executable('metadata_test', 'metadata_test.c', 'MetadataDump.c')
executable('printsections', 'printsections.c', 'MetadataDump.c', dependencies : ntdll_lib)

executable(
    'reconsdll', 'reconsdll.cpp', 'MetadataDump.c', 'Section.c', 'Recons.cpp',
    dependencies : [libpeconv_dep, ntdll_lib]
)

executable('RegenSections', 'RegenSections.c', 'Section.c')