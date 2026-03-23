
cmake_minimum_required(VERSION 4.0...4.2)

# message(AUTHOR_WARNING "Old value of `CMAKE_SYSTEM_VERSION' is `${CMAKE_SYSTEM_VERSION}'")
set(CMAKE_SYSTEM_VERSION 11.0.26100.0)
# message(AUTHOR_WARNING "NEW value of `CMAKE_SYSTEM_VERSION' is `${CMAKE_SYSTEM_VERSION}'")

project(CxxTemplatesTheCompleteGuide LANGUAGES CXX)

message(STATUS "test: ${CMAKE_SYSTEM_VERSION}")

add_library(foo.bar)
add_library(foo::bar ALIAS foo.bar)

target_sources(
        foo.bar

        PUBLIC FILE_SET HEADERS BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

set_target_properties(foo.bar PROPERTIES VERIFY_INTERFACE_HEADER_SETS ON)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(examples) # main's
