project('vulkan', 'c', default_options : 'warning_level=3')

libvolk = static_library('volk', 'volk.c')

incdir = include_directories('.')

vulkan_dep = declare_dependency(link_with : libvolk, include_directories : incdir)

meson.override_dependency('vulkan', vulkan_dep)