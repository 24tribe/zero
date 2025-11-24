project('webview', 'cpp', default_options : 'cpp_std=c++14')

cpp = meson.get_compiler('cpp')

advapi32_lib = cpp.find_library('advapi32')
ole32_lib = cpp.find_library('ole32')
shell32_lib = cpp.find_library('shell32')
shlwapi_lib = cpp.find_library('shlwapi')
user32_lib = cpp.find_library('user32')
version_lib = cpp.find_library('version')

deps = [
    advapi32_lib, ole32_lib, shell32_lib, shlwapi_lib, user32_lib, version_lib
]

incdir = include_directories('core/include')

webview_lib = static_library(
    'webview', 'core/src/webview.cc', include_directories: incdir, dependencies : deps
)

webview_dep = declare_dependency(
    link_with : webview_lib,
    include_directories : incdir,
    dependencies : deps
)