project('semba', 'c', default_options : 'warning_level=3', meson_version : '>=1.4.0')

fs = import('fs')

nimble = find_program('nimble', required : true)

python = find_program('python', required : true)

sqlite3_c = fs.copyfile('src/sqlite3.c')

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)

sqlite3 = executable('sqlite3', 'src/shell.c', sqlite3_c, dependencies : m_dep)

nim_release_args = ['--cc:gcc', '--gcc.exe=cc', '--gcc.linkerexe=cc']

semba_db = custom_target(
    'semba_db',
    input : 'src/semba/semba.sql',
    output : 'semba.db',
    command : [sqlite3, '@OUTPUT@'],
    feed : true,
    build_by_default : true,
    install : true,
    install_dir : '.'
)

# always static link libc with windows (to avoid shipping mingw dlls)
if host_machine.system() == 'windows'
    nim_release_args += ['--passL:-static']
endif

if get_option('buildtype') == 'release'
    nim_release_args += ['-d:release']
endif

if build_machine.system() != 'windows' and host_machine.system() == 'windows'
    nim_release_args += ['-d:mingw']
endif

if get_option('default_library') == 'static'
    semba_output = 'libsemba.a'
    app_arg = '--app:staticlib'
else
    if host_machine.system() == 'windows'
        semba_output = 'libsemba.dll'
    else
        semba_output = 'libsemba.so'
    endif
    app_arg = '--app:lib'
endif

if host_machine.system() == 'windows'
    exe_suffix = '.exe'
else
    exe_suffix = ''
endif

libsemba = custom_target(
    'libsemba',
    depends : [sqlite3_c, semba_db],
    input : ['src/semba.nim'],
    output : semba_output,
    command : [
        python, files('nimble_wrapper.py'), 'c', '-d:staticSqlite', app_arg, '--noMain:on', nim_release_args,
        '-o:@OUTPUT@', '@INPUT@'
    ],
    build_by_default : true
)

semba_dep = declare_dependency(
    link_with : libsemba,
    include_directories : include_directories('src')
)