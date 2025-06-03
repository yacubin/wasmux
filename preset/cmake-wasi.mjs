export default {
  "bundle:wasmux": {
    action: "bitmake",
    variables: {
      TOOLCHAIN_FILE:  "${wasmux.mainDir}/toolchain/wasm32-wasi.js",
      INSTALL_PREFIX: "/usr",
      WASMUX_ENABLE_THREADS: true,
      WASMUX_ENABLE_KERNEL: false,
      WASMUX_ENABLE_LIBC: true,
      WASMUX_ENABLE_MAIN_ENV_ARG: false,
    },
    sourceDir: "${wasmux.mainDir}",
    destDir: "${binaryRoot}/sysroot",
    buildType: "Release",
  },

  "bundle:output": {
    action: "cmake",
    generator: "Unix Makefiles",
    cacheVariables: {
      CMAKE_TOOLCHAIN_FILE: "${bundle:wasmux.destDir}/usr/share/wasmux/wasm32-wasi.toolchain.cmake",
      CMAKE_INSTALL_PREFIX: "/usr",
    },
    sourceDir: "${sourceRoot}",
    destDir: "${binaryRoot}/output",
    rebuild: true,
  },
};
