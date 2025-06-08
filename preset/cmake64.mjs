export default {
  "bundle:wasmux": {
    action: "bitmake",
    variables: {
      TOOLCHAIN_FILE: "import://wasmux/toolchain/wasm64",
      INSTALL_PREFIX: "/usr",
      WASMUX_ARCH: "user",
    },
    sourceDir: "${wasmux.mainDir}",
    destDir: "${binaryRoot}/sysroot",
    buildType: "Release",
  },

  "bundle:output": {
    action: "cmake",
    generator: "Unix Makefiles",
    cacheVariables: {
      CMAKE_TOOLCHAIN_FILE: "${bundle:wasmux.destDir}/usr/share/wasmux/wasm64.toolchain.cmake",
      CMAKE_INSTALL_PREFIX: "/usr",
    },
    sourceDir: "${sourceRoot}",
    destDir: "${binaryRoot}/output",
    rebuild: true,
  },
};
