project('libhbo', 'c',
    version : '0.1.0',
    default_options : [
        'warning_level=3',
        'c_std=c11',
        'default_library=both'
    ]
)

sources = [
    'src/hbo/string-view.c',
    'src/hbo/arraylist.c',
]

# gtkmmdep = dependency('gtkmm-3.0')

hbo = library('hbo', sources,
    version: '0.1.0',
    soversion: '0',
#   dependencies : [
#       gtkmmdep,
#   ],
    install: true
)

lib_include_path = include_directories('src')

# Tests - Unit Tests

add_languages('cpp')

catch2_dep = dependency('catch2', method: 'pkg-config')

# TODO there must be a better scallable way of this this, right?!
unit_tests_string_view = executable('unit-tests-string-view', 'src/hbo/string-view.test.cpp',
    dependencies: [ catch2_dep ],
    include_directories: lib_include_path,
    link_with: [ hbo ],
)
unit_tests_arraylist = executable('unit-tests-arraylist', 'src/hbo/arraylist.test.cpp',
    dependencies: [ catch2_dep ],
    include_directories: lib_include_path,
    link_with: [ hbo ],
)
test('unit-tests-arraylist', unit_tests_arraylist)
