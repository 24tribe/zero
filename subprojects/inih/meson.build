project('inih', 'c', default_options : 'warning_level=3')

incdir = '.'

src = [
    'ini.c'
]

libinih = static_library('inih', src, include_directories : incdir)

libinih_dep = declare_dependency(include_directories : incdir, link_with : libinih)