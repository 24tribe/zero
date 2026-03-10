executable('metadata_test', 'metadata_test.c', 'MetadataDump.c')
executable('printsections', 'printsections.c', 'MetadataDump.c', dependencies : ntdll_lib)

if dump_ga_support
executable(
    'reconsdll', 'reconsdll.cpp', 'MetadataDump.c', 'Section.c', 'Recons.cpp',
    dependencies : [libpeconv_dep, ntdll_lib]
)
endif

executable('RegenSections', 'RegenSections.c', 'Section.c')