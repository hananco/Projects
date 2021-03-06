﻿cmake_minimum_required (VERSION 3.14)

project ("Portal")

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
    add_compile_options (/permissive-)
endif ()

add_executable (Portal WIN32)

add_subdirectory (include)
add_subdirectory (src)
add_subdirectory (resources)
add_subdirectory (Box2d/box2d/src)


set (SFML_STATIC_LIBRARIES TRUE)
set (SFML_DIR "C:/SFML/SFML-2.5.1/lib/cmake/SFML")

find_package (SFML 2.5 COMPONENTS audio graphics REQUIRED)

set_target_properties (sfml-main sfml-system sfml-window sfml-graphics sfml-audio sfml-network PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)

target_link_libraries (Portal sfml-graphics sfml-audio sfml-main)
target_link_libraries (Portal box2d)

configure_file (C:/SFML/SFML-2.5.1/bin/openal32.dll ${CMAKE_BINARY_DIR} COPYONLY)

# TODO: Add tests and install targets if needed.