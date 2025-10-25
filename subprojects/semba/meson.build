project('semba', 'c')

libsemba = custom_target(
    'libsemba',
    input : 'semba.nim',
    output : 'libsemba.a',
    command : ['nim', 'c', '--app:staticlib', '--noMain:on', '-o:@OUTPUT@', '@INPUT@']
)

semba_dep = declare_dependency(
    link_with : libsemba,
    include_directories : include_directories('.')
)