cmake_minimum_required(VERSION 3.20.0)
project(wasmux VERSION 0.0.1
  DESCRIPTION "WebAssembly Software Development Kit"
  HOMEPAGE_URL "https://github.com/ykbin/wasmux"
  LANGUAGES ASM C CXX
  )

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_program(NODE_EXECUTABLE node REQUIRED)

set(WASMUX_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(WASMUX_SCRIPT_DIR "${CMAKE_CURRENT_LIST_DIR}/scripts")

include(WxVariables)

set(WASMUX_INSTALL_BINDIR "bin")
set(WASMUX_INSTALL_LIBDIR "lib")
set(WASMUX_INSTALL_INCLUDEDIR "include")

if (WASMUX_TARGET_SYSTEM MATCHES "-wasi$")
  set(WASMUX_INSTALL_LIBDIR "${WASMUX_INSTALL_LIBDIR}/${CMAKE_SYSTEM_PROCESSOR}-wasi")
endif ()

include(WxMacros)
include(GenScript)

set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -D__ASSEMBLY__")

set(WASMUX_CONFIG_HEADER "${CMAKE_CURRENT_BINARY_DIR}/wasmux-config.h")
set(WASMUX_CONFIG_OBJECT "${CMAKE_CURRENT_BINARY_DIR}/wasmux-config.mjs")

WX_MAKE_VARIABLES(
  INPUT "${WASMUX_ROOT_DIR}/variables.mjs"
  OUTPUT_HEADER "${WASMUX_CONFIG_HEADER}.in"
  OUTPUT_OBJECT "${WASMUX_CONFIG_OBJECT}.in"
  OUTPUT_SCRIPT "${CMAKE_CURRENT_BINARY_DIR}/wasmux-config.cmake"
  PRINT
  )

include("${CMAKE_CURRENT_BINARY_DIR}/wasmux-config.cmake")

configure_file("${WASMUX_CONFIG_HEADER}.in" "${WASMUX_CONFIG_HEADER}" @ONLY)
configure_file("${WASMUX_CONFIG_OBJECT}.in" "${WASMUX_CONFIG_OBJECT}" @ONLY)

include_directories("${CMAKE_CURRENT_BINARY_DIR}")

add_subdirectory(waf)
add_subdirectory(uapi)
add_subdirectory(kernel)
add_subdirectory(tools)

if (WASMUX_ENABLE_INSTALL_HEADERS)
file(READ "cmake/toolchain/LinuxSystem.cmake" _TOOLCHAIN_CONTENT1)
file(READ "cmake/toolchain/UserConfig.cmake" _TOOLCHAIN_CONTENT2)
file(READ "cmake/toolchain/CommonToolchain.cmake" _TOOLCHAIN_CONTENT3)
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/cmake/${WASMUX_TARGET_SYSTEM}.toolchain.cmake"
"set(CONFIG_TARGET_TRIPLET ${WASMUX_TARGET_SYSTEM})\n
${_TOOLCHAIN_CONTENT1}
set(CMAKE_SYSTEM_PROCESSOR ${CMAKE_SYSTEM_PROCESSOR})
set(CMAKE_SIZEOF_VOID_P ${CMAKE_SIZEOF_VOID_P})
set(CONFIG_BUILD_C_COMPILER \"${CMAKE_C_COMPILER}\")
set(CONFIG_BUILD_CXX_COMPILER \"${CMAKE_CXX_COMPILER}\")

get_filename_component(CMAKE_SYSROOT \"\${CMAKE_CURRENT_LIST_DIR}/../..\" ABSOLUTE)

${_TOOLCHAIN_CONTENT2}
${_TOOLCHAIN_CONTENT3}
")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/cmake/${WASMUX_TARGET_SYSTEM}.toolchain.cmake" DESTINATION "share/wasmux")
endif ()
