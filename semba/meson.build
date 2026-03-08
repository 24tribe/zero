nim = find_program('nim', required : true)
sqlite3_c = fs.copyfile('sqlite3.c')

sqlite3 = executable('sqlite3', 'shell.c', 'sqlite3.c')

semba_extra = static_library('semba_extra', 'NimInit.c')

semba_core_files = [
    'sembacore.nim',
    'sembademo.nim',
    'sembastable.nim',
    'protojson.nim',
    'sembaprivate.nim',
    'dungeongen.nim',
    'extsqlite.nim',
    'sembasave.nim',
]

if get_option('buildtype') == 'release'
    nim_release_args = ['-d:release']
else
    nim_release_args = []
endif

if build_machine.system() != 'windows'
    nim_release_args += ['-d:mingw']
endif

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

libsemba = custom_target(
    'libsemba',
    depends : [sqlite3_c],
    depend_files : semba_core_files,
    input : ['semba.nim'],
    output : 'libsemba.a',
    command : [
        nim, 'c', '-d:staticSqlite', '--app:staticlib', '--noMain:on', nim_release_args,
        '-o:@OUTPUT@', '@INPUT@'
    ]
)

sembaserver = custom_target(
    'sembaserver',
    depends : [sqlite3_c, semba_db],
    depend_files : semba_core_files,
    input : ['sembaserver.nim'],
    output : 'sembaserver.exe',
    command : [
        nim, 'c', '-d:staticSqlite', '--app:console', '--threadAnalysis:off', nim_release_args,
        '-o:@OUTPUT@', '@INPUT@'
    ],
    build_by_default : true
)

test_semba = custom_target(
    depends : [sqlite3_c, semba_db],
    depend_files : semba_core_files,
    input : ['test_semba.nim'],
    output : 'test_semba.exe',
    command : [
        nim, 'c', '-d:staticSqlite', '--app:console', nim_release_args,
        '-o:@OUTPUT@', '@INPUT@'
    ],
    build_by_default : true
)

test_wrapper = executable('test_wrapper', 'test_wrapper.c')

test('test semba', test_wrapper, args: test_semba)

semba_dep = declare_dependency(
    link_with : [libsemba, semba_extra]
)

executable('semba', 'semba.c', dependencies : [semba_dep])