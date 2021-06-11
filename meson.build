project('libhbo', 'c',
    version : '0.1.0',
    default_options : [
        'warning_level=3',
        'c_std=c11',
    ]
)
add_languages('cpp')

sources = [
    'src/hbo/string-view.c',
    'src/hbo/arraylist.c',
]

# gtkmmdep = dependency('gtkmm-3.0')

lib = library('hbo', sources,
    version: '0.1.0',
    soversion: '0',
#   dependencies : [
#       gtkmmdep,
#   ],
    install: true
)

lib_include_path = include_directories('src')

catch2_dep = dependency('catch2',
    method: 'pkg-config',
    link_args: ['-L .' ]
)

unit_tests = executable('unit-tests', 'src/tests/unit-tests/main.cpp',
    dependencies: [ catch2_dep ],
    include_directories: lib_include_path,
    link_with: [ lib ],
    link_args: '-L ./builddir'
)
test('unit-tests', unit_tests)
