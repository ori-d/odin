cmake_minimum_required (VERSION 3.20...3.23 FATAL_ERROR)

set (ODIN_NET "odin.net")

add_library(${ODIN_NET} SHARED)

set (odin_net_library  )

set (odin_net_sources   "src/tmp.c")

set (odin_net_headers   "include/odin/net/exports.h"
                        "include/odin/net/packets/ip.h"
                        "include/odin/net/net.h")

target_sources (${ODIN_NET}
                PRIVATE ${odin_net_library}
                PRIVATE ${odin_net_sources}
                PUBLIC  ${odin_net_headers})

set_target_properties (${ODIN_NET}
                        PROPERTIES
                        C_STANDARD 17
                        C_STANDARD_REQUIRED ON
                        C_EXTENSIONS OFF)

target_compile_definitions (${ODIN_NET}
                            PRIVATE
                            -Dodin_net_dll
                            -Dodin_net_dll_exports)

target_link_libraries (${ODIN_NET}
                        PRIVATE
                        odin::core)

target_include_directories (${ODIN_NET}
                            PRIVATE
                            "${CMAKE_CURRENT_LIST_DIR}/include")

add_library (odin::net ALIAS ${ODIN_NET})
