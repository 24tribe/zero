d3d11_lib = cc.find_library('d3d11')
imgui = dependency('imgui', default_options : 'default_library=static')

gui_deps = [d3d11_lib, imgui, jansson_dep]

gui_src = files(
    'Backend.cpp',
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