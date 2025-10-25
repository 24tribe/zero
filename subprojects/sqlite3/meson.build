project('sqlite3', 'c', default_options : 'warning_level=3')

incdir = [
    '.'
]

libsqlite3 = static_library('sqlite3', 'sqlite3.c', include_directories : incdir)

executable('sqlite3', 'shell.c', link_with : libsqlite3)

libsqlite3_dep = declare_dependency(include_directories : incdir, link_with : libsqlite3)