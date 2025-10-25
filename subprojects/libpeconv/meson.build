project('peconv', 'cpp', default_options : 'warning_level=3')

incdir = [
    'libpeconv/include'
]

src = [
    'libpeconv/src/buffer_util.cpp',
    'libpeconv/src/caves.cpp',
    'libpeconv/src/delayed_imports_loader.cpp',
    'libpeconv/src/exceptions_parser.cpp',
    'libpeconv/src/exported_func.cpp',
    'libpeconv/src/exports_lookup.cpp',
    'libpeconv/src/exports_mapper.cpp',
    'libpeconv/src/file_util.cpp',
    'libpeconv/src/find_base.cpp',
    'libpeconv/src/fix_dot_net_ep.cpp',
    'libpeconv/src/fix_imports.cpp',
    'libpeconv/src/function_resolver.cpp',
    'libpeconv/src/hooks.cpp',
    'libpeconv/src/imports_loader.cpp',
    'libpeconv/src/imports_uneraser.cpp',
    'libpeconv/src/load_config_util.cpp',
    'libpeconv/src/pe_dumper.cpp',
    'libpeconv/src/pe_hdrs_helper.cpp',
    'libpeconv/src/pe_loader.cpp',
    'libpeconv/src/pe_mode_detector.cpp',
    'libpeconv/src/pe_raw_to_virtual.cpp',
    'libpeconv/src/pe_virtual_to_raw.cpp',
    'libpeconv/src/peb_lookup.cpp',
    'libpeconv/src/relocate.cpp',
    'libpeconv/src/remote_pe_reader.cpp',
    'libpeconv/src/resource_parser.cpp',
    'libpeconv/src/resource_util.cpp',
    'libpeconv/src/tls_parser.cpp',
    'libpeconv/src/util.cpp'
]

libpeconv = static_library('peconv', src, include_directories : incdir)

libpeconv_dep = declare_dependency(include_directories : incdir, link_with : libpeconv)