set(CONFIG_TARGET_TRIPLET wasm32-unknown-wasi)

include("${CMAKE_CURRENT_LIST_DIR}/toolchain/WasmProcessor32.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/toolchain/LinuxSystem.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/toolchain/UserConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/toolchain/CommonToolchain.cmake")
