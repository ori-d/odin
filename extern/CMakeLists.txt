cmake_minimum_required (VERSION 3.20...3.23 FATAL_ERROR)

set (CMAKE_C_STANDARD 17)
set (CMAKE_C_STANDARD_REQUIRED ON)

option (MI_USE_CXX OFF)
option (MI_BUILD_TESTS OFF)
option (MI_BUILD_SHARED OFF)
option (MI_BUILD_OBJECT OFF)

add_subdirectory ("allocator")

add_library(mi::static ALIAS mimalloc-static)
