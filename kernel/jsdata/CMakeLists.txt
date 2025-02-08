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

GEN_KWEBCALLESX(
  SIDE "main"
  INPUT "${WASMUX_ROOT_DIR}/waf/webcalls.js"
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/generated/MainCalls.mjs"
  )

GEN_KWEBCALLESX(
  SIDE "worker"
  INPUT "${WASMUX_ROOT_DIR}/waf/webcalls.js"
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/generated/WorkerCalls.mjs"
  )

find_program(NPX_EXECUTABLE npx REQUIRED)
add_custom_command(
  COMMAND "${NPX_EXECUTABLE}" webpack
    --config webpack.config.mjs
    --env "buildType=${CMAKE_BUILD_TYPE}"
    --env "buildDirectory=${CMAKE_CURRENT_BINARY_DIR}"
    --env "settings=${CMAKE_CURRENT_SOURCE_DIR}/settings.mjs"
  DEPENDS ${jsdata_SOURCES} ${jsdata_GENFILES} "${CMAKE_CURRENT_SOURCE_DIR}/settings.mjs"
  OUTPUT
    "${CMAKE_CURRENT_BINARY_DIR}/dist/loader.js"
    "${CMAKE_CURRENT_BINARY_DIR}/dist/worker.js"
  WORKING_DIRECTORY
    "${CMAKE_CURRENT_SOURCE_DIR}"
  )

GEN_WACUSTSEC(
  CPU "${CMAKE_SYSTEM_PROCESSOR}"
  SECTION ".jsdata.loader"
  INPUT "${CMAKE_CURRENT_BINARY_DIR}/dist/loader.js"
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/loader.S"
  )

GEN_WACUSTSEC(
  CPU "${CMAKE_SYSTEM_PROCESSOR}"
  SECTION ".jsdata.worker"
  INPUT "${CMAKE_CURRENT_BINARY_DIR}/dist/worker.js"
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/worker.S"
  )

add_library(jsdata OBJECT "${CMAKE_CURRENT_BINARY_DIR}/loader.S" "${CMAKE_CURRENT_BINARY_DIR}/worker.S")
target_sources(jsdata PRIVATE ${jsdata_SOURCES} ${jsdata_GENFILES})
