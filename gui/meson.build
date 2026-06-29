d3d11_lib = cc.find_library('d3d11')
imgui = dependency('imgui', default_options : 'default_library=static')

gui_src = files(
    'Backend.cpp',
    'DrawFunc.cpp',
    'UserInterface.cpp',
    'GachaRatesWindow.cpp',
    'CustomColorWindow.cpp',
    'SavesWindow.cpp',
    'PatimonMakerWindow.cpp',
    'SembaClient.cpp',
)

imguitest_src = [
    'imguitest.cpp',
    'DrawFunc.cpp',
    '../TimeUtil.c',
    'GachaRatesWindow.cpp',
    'CustomColorWindow.cpp',
    '../HairColorHelper.cpp',
    'Backend.cpp',
    'SavesWindow.cpp',
    'PatimonMakerWindow.cpp',
]


imguitest_deps = [
    d3d11_lib,
    imgui,
    jansson_dep,
    libminhook_dep,
    fuzzymatcher_dep,
]

executable('imguitest', imguitest_src, dependencies : imguitest_deps)
