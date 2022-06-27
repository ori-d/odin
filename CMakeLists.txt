cmake_minimum_required (VERSION 3.20...3.23 FATAL_ERROR)

project ("odin" LANGUAGES C VERSION 1.0.0.0)

option(ODIN_BUILD_DOC "Build documentation" ON)

add_subdirectory ("extern")
add_subdirectory ("odin")
