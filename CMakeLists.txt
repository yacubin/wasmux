cmake_minimum_required(VERSION 3.20.0)
project(wasmux VERSION 0.0.1
  DESCRIPTION "WebAssembly Software Development Kit"
  HOMEPAGE_URL "https://github.com/ykbin/wasmux"
  LANGUAGES ASM C CXX
  )

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(WxCommon)

execute_process(COMMAND "${NODE_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/MainScript.js"
  "--output=${CMAKE_CURRENT_BINARY_DIR}/BuildScript.cmake"
  )
include("${CMAKE_CURRENT_BINARY_DIR}/BuildScript.cmake")

set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -D__ASSEMBLY__")

configure_file(config.h.cmake "${CMAKE_CURRENT_BINARY_DIR}/config.h" @ONLY)
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

add_subdirectory(waf)
add_subdirectory(uapi)
add_subdirectory(kernel)

if (CONFIG_ENABLE_INSTALL_HEADERS)
file(READ "cmake/toolchain/LinuxSystem.cmake" _TOOLCHAIN_CONTENT1)
file(READ "cmake/toolchain/UserConfig.cmake" _TOOLCHAIN_CONTENT2)
file(READ "cmake/toolchain/CommonToolchain.cmake" _TOOLCHAIN_CONTENT3)
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/cmake/${CONFIG_TARGET_SYSTEM}.toolchain.cmake"
"set(CONFIG_TARGET_TRIPLET ${CONFIG_TARGET_SYSTEM})\n
${_TOOLCHAIN_CONTENT1}
set(CMAKE_SYSTEM_PROCESSOR ${CMAKE_SYSTEM_PROCESSOR})
set(CMAKE_SIZEOF_VOID_P ${CMAKE_SIZEOF_VOID_P})
set(CONFIG_BUILD_C_COMPILER \"${CMAKE_C_COMPILER}\")
set(CONFIG_BUILD_CXX_COMPILER \"${CMAKE_CXX_COMPILER}\")

get_filename_component(CMAKE_SYSROOT \"\${CMAKE_CURRENT_LIST_DIR}/../..\" ABSOLUTE)

${_TOOLCHAIN_CONTENT2}
${_TOOLCHAIN_CONTENT3}
")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/cmake/${CONFIG_TARGET_SYSTEM}.toolchain.cmake" DESTINATION "share/wasmux")
endif ()
