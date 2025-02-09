cmake_minimum_required(VERSION 3.20.0)
project(wasmux VERSION 0.0.1
  DESCRIPTION "WebAssembly Software Development Kit"
  HOMEPAGE_URL "https://github.com/ykbin/wasmux"
  LANGUAGES ASM C CXX
  )

find_program(NODE_EXECUTABLE node REQUIRED)
execute_process(COMMAND "${NODE_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/MainScript.js"
  "--source-dir=${CMAKE_CURRENT_SOURCE_DIR}"
  "--binary-dir=${CMAKE_CURRENT_BINARY_DIR}"
  "--output=${CMAKE_CURRENT_BINARY_DIR}/BuildScript.cmake"
  OUTPUT_VARIABLE
    _output
  RESULT_VARIABLE
    _result
  )
if (_result)
  message(FATAL_ERROR "Build script could not be created\nResult: ${_result}\nOutput: ${_output}")
endif ()

include("${CMAKE_CURRENT_BINARY_DIR}/BuildScript.cmake")

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
