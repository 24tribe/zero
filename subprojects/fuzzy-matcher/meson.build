project('fuzzy-matcher', 'cpp')

libfuzzymatcher = static_library('fuzzy-matcher', 'FuzzyMatcher.cpp')
incdir = include_directories('.')
fuzzymatcher_dep = declare_dependency(link_with: libfuzzymatcher, include_directories: incdir)
