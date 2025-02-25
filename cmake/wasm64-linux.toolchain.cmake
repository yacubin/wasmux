set(WASMUX_TARGET_TRIPLET wasm64-unknown-unknown)

include("${CMAKE_CURRENT_LIST_DIR}/toolchain/WasmProcessor64.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/toolchain/LinuxSystem.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/toolchain/UserConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/toolchain/CommonToolchain.cmake")
