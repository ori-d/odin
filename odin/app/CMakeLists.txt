cmake_minimum_required (VERSION 3.20...3.23 FATAL_ERROR)

add_executable(main main.c)

target_link_libraries (main PRIVATE odin::core)

target_include_directories (main
                            PRIVATE
                            "../core/include")
