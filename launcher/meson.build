curl = find_program('curl')

url = 'https://www.dropbox.com/scl/fi/rel70y0nj0bay4t37lyrl/launcher_bg.png?rlkey=917h1rk3wvr7iyz8lwxy8pwte&st=x4a7wxe8&dl=1'

fs.copyfile('index.html', install : true, install_dir : '.')

launcher_bg = custom_target(
    'launcher_bg',
    output : 'launcher_bg.png',
    command : [curl, '-L', '--output', '@OUTPUT@', url],
    build_by_default : true,
    install : true, install_dir : '.'
)

executable(
    'launcher', 'launcher.cpp',
    dependencies : [webview_dep, sds_dep, jansson_dep],
    win_subsystem : 'windows',
    install : true, install_dir : '.'
)