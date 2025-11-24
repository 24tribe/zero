nim = find_program('nim', required : true)
sqlite3_c = fs.copyfile('sqlite3.c')

semba_extra = static_library('semba_extra', 'NimInit.c')

libsemba = custom_target(
    'libsemba',
    depends : [sqlite3_c],
    input : ['semba.nim'],
    output : 'libsemba.a',
    command : [
        nim, 'c', '-d:staticSqlite', '--app:staticlib', '--noMain:on',
        '-o:@OUTPUT@', '@INPUT@'
    ]
)

sembaserver = custom_target(
    'sembaserver',
    depends : [sqlite3_c],
    input : ['sembaserver.nim'],
    output : 'sembaserver.exe',
    command : [
        nim, 'c', '-d:staticSqlite', '--app:console', '--threadAnalysis:off',
        '-o:@OUTPUT@', '@INPUT@'
    ],
    build_by_default : true
)

semba_db = custom_target(
    'semba_db',
    input : 'semba.sql',
    output : 'semba.db',
    command : [sqlite3, '@OUTPUT@'],
    feed : true,
    build_by_default : true,
    install : true,
    install_dir : '.'
)

semba_dep = declare_dependency(
    link_with : [libsemba, semba_extra]
)

executable('test_semba', 'test_semba.c', dependencies : [semba_dep])
executable('semba', 'semba.c', dependencies : [semba_dep])