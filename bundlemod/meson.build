if get_option('texture_mods_support')

bundlemod_files = files(
    'BundleMod.cs',
    'BundleMod.csproj',
    'BundleMod.h',
    'ImageSharpColorize.cs',
    'TextureSwap.cs',
)

python3 = find_program('python3', required : true)

bundlemod = custom_target(
    'bundlemod',
    depend_files : bundlemod_files,
    output : 'bundlemod.dll',
    command : [
        python3, files('build.py')[0], '@OUTPUT@', '@CURRENT_SOURCE_DIR@'
    ],
    install : true,
    install_dir : '.',
)

else

bundlemod = static_library('bundlemod', 'BundleModMock.c')

endif