
cmake_minimum_required(VERSION 4.0...4.2)

project(CxxTemplatesTheCompleteGuide LANGUAGES CXX)

add_library(foo.bar )
add_library(foo::bar ALIAS foo.bar)

target_sources(
        foo.bar

        PUBLIC FILE_SET HEADERS BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

set_target_properties(foo.bar PROPERTIES VERIFY_INTERFACE_HEADER_SETS ON)

add_subdirectory(include)
add_subdirectory(src)

add_subdirectory(examples)
