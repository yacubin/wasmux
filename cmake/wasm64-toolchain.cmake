set(CONFIG_TARGET_TRIPLET wasm64-unknown-unknown)

include("${CMAKE_CURRENT_LIST_DIR}/toolchain/WasmProcessor64.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/toolchain/GenericSystem.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/toolchain/KernelConfig.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/toolchain/CommonToolchain.cmake")
