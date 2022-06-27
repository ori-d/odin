cmake_minimum_required (VERSION 3.20...3.23 FATAL_ERROR)

set (ODIN_CORE "odin.core")

add_library(${ODIN_CORE} SHARED)

set (odin_core_library  "lib/memory.c"
                        "lib/streams/memory.c")

set (odin_core_sources  "src/memory.c"
                        "src/streams/stream.c"
                        "src/streams/memory.c")

set (odin_core_headers  "include/odin/core/exports.h"
                        "include/odin/core/memory.h"
                        "include/odin/core/object.h"
                        "include/odin/core/streams/stream.h"
                        "include/odin/core/core.h")

target_sources (${ODIN_CORE}
                PRIVATE ${odin_core_library}
                PRIVATE ${odin_core_sources}
                PUBLIC  ${odin_core_headers})

set_target_properties (${ODIN_CORE}
                        PROPERTIES
                        C_STANDARD 17
                        C_STANDARD_REQUIRED ON
                        C_EXTENSIONS OFF)

target_compile_definitions (${ODIN_CORE}
                            PRIVATE
                            -Dodin_core_dll
                            -Dodin_core_dll_exports)

target_link_libraries (${ODIN_CORE}
                        PRIVATE
                        mi::static)

target_include_directories (${ODIN_CORE}
                            PRIVATE
                            "${CMAKE_CURRENT_LIST_DIR}/include")

add_library (odin::core ALIAS ${ODIN_CORE})
