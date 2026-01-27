d3d11_lib = cc.find_library('d3d11')
imgui = dependency('imgui', default_options : 'default_library=static')

gui_src = files(
    'Backend.cpp',
    'DrawFunc.cpp',
    'UserInterface.cpp'
)

executable('imguitest', 'imguitest.cpp', 'DrawFunc.cpp', '../TimeUtil.c', dependencies : [d3d11_lib, imgui])