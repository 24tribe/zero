project('jansson', 'c', default_options : 'warning_level=3')

incdir = '.'

src = [
    'dtoa.c',
    'dump.c',
    'error.c',
    'hashtable.c',
    'hashtable_seed.c',
    'load.c',
    'memory.c',
    'pack_unpack.c',
    'strbuffer.c',
    'strconv.c',
    'utf.c',
    'value.c',
    'version.c',
]

libjansson = static_library('jansson', src, include_directories : incdir)

libjansson_dep = declare_dependency(include_directories : incdir, link_with : libjansson)