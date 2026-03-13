d3d11_lib = cc.find_library('d3d11')

vulkan_proj = subproject('vulkan')
vulkan_dep = vulkan_proj.get_variable('vulkan_dep')

imgui = dependency('imgui', default_options : 'default_library=static,vulkan=true')

gui_deps = [d3d11_lib, imgui, jansson_dep, vulkan_dep]

gui_src = files(
    'BackendVulkan.cpp',
    'DrawFunc.cpp',
    'UserInterface.cpp',
    'GachaRatesWindow.cpp',
    'CustomColorWindow.cpp',
)

executable(
    'imguitest',
    'imguitest.cpp', 'DrawFunc.cpp', '../TimeUtil.c', 'GachaRatesWindow.cpp', 'CustomColorWindow.cpp',
    '../HairColorHelper.cpp',
    dependencies : gui_deps
)