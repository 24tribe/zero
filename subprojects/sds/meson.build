project('sds', 'c', default_options : 'warning_level=3')

incdir = [
    '.'
]

libsds = static_library('sds', 'sds.c', include_directories : incdir)

libsds_dep = declare_dependency(include_directories : incdir, link_with : libsds)