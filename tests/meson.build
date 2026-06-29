incdir = include_directories('..')

executable('test_utf', 'test_utf.c', '../sds_utf_conv.c', dependencies : sds_dep, include_directories: incdir)

executable('test_re', 'test_re.c', '../re.c', '../Patterns.c', dependencies : sds_dep, include_directories: incdir)

test_hair_color_helper = executable(
    'test_hair_color_helper', 'test_hair_color_helper.cpp', '../HairColorHelper.cpp', include_directories: incdir
)

test('test hair color helper', test_hair_color_helper)
