cmake_minimum_required(VERSION 3.20.0)
project(wasmux VERSION 0.0.3
  DESCRIPTION "WebAssembly toolchain for compiling libc and kernel into system-level WASM modules"
  HOMEPAGE_URL "https://github.com/yacubin/wasmux"
  )

find_package(LibNetQ REQUIRED)
find_program(NODE_EXECUTABLE node REQUIRED)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES tools/emit.c)
add_executable(emit tools/emit.c)
target_link_libraries(emit LibNetQ::LibNetQ)

configure_file(wasmux-config.h.in "${CMAKE_CURRENT_BINARY_DIR}/wasmux-config.h" @ONLY)

add_subdirectory(wasmux)
