set(jsdata_SOURCES
  src/MainThreadContext.mjs
  src/Object.mjs
  src/BaseThreadContext.mjs
  src/WorkerThreadContext.mjs
  src/SystemCalls.mjs
  webpack.config.mjs
  )

set(jsdata_GENFILES
  "${CMAKE_CURRENT_BINARY_DIR}/generated/MainCalls.mjs"
  "${CMAKE_CURRENT_BINARY_DIR}/generated/WorkerCalls.mjs"
  )

add_custom_script(
  SCRIPT webcallesx.mjs
  SIDE "main"
  INPUT "${WASMUX_ROOT_DIR}/data/webcalls.js"
  OUTPUT generated/MainCalls.mjs
  WORK_DIR "${CMAKE_CURRENT_BINARY_DIR}"
  )

add_custom_script(
  SCRIPT webcallesx.mjs
  SIDE "worker"
  INPUT "${WASMUX_ROOT_DIR}/data/webcalls.js"
  OUTPUT generated/WorkerCalls.mjs
  WORK_DIR "${CMAKE_CURRENT_BINARY_DIR}"
  )

find_program(NPX_EXECUTABLE npx REQUIRED)
add_custom_command(
  COMMAND "${NPX_EXECUTABLE}" webpack
    --config webpack.config.mjs
    --env "buildType=${CMAKE_BUILD_TYPE}"
    --env "buildDirectory=${CMAKE_CURRENT_BINARY_DIR}"
    --env "settings=${WASMUX_CONFIG_OBJECT}"
  DEPENDS ${jsdata_SOURCES} ${jsdata_GENFILES}
  OUTPUT
    "${CMAKE_CURRENT_BINARY_DIR}/dist/loader.js"
    "${CMAKE_CURRENT_BINARY_DIR}/dist/worker.js"
  WORKING_DIRECTORY
    "${CMAKE_CURRENT_SOURCE_DIR}"
  )

add_custom_script(
  SCRIPT mkcustsec.mjs
  CPU "${CMAKE_SYSTEM_PROCESSOR}"
  SECTION "${WASMUX_LOADER_SECTION}"
  INPUT "${CMAKE_CURRENT_BINARY_DIR}/dist/loader.js"
  OUTPUT loader.S
  WORK_DIR "${CMAKE_CURRENT_BINARY_DIR}"
  )

add_custom_script(
  SCRIPT mkcustsec.mjs
  CPU "${CMAKE_SYSTEM_PROCESSOR}"
  SECTION "${WASMUX_WORKER_SECTION}"
  INPUT "${CMAKE_CURRENT_BINARY_DIR}/dist/worker.js"
  OUTPUT worker.S
  WORK_DIR "${CMAKE_CURRENT_BINARY_DIR}"
  )

add_library(jsdata OBJECT "${CMAKE_CURRENT_BINARY_DIR}/loader.S" "${CMAKE_CURRENT_BINARY_DIR}/worker.S")
target_sources(jsdata PRIVATE ${jsdata_SOURCES} ${jsdata_GENFILES})
