export default {
  "bundle:libnetq": {
    sourceUrl: "https://github.com/libnetq/libnetq/archive/refs/tags/v1.0.16.tar.gz",
    action: "cmake",
    generator: "Unix Makefiles",
    cacheVariables: {
      CMAKE_INSTALL_PREFIX: "/usr",
      CMAKE_PREFIX_PATH: "${binaryRoot}/sysroot/usr",
    },
    destDir: "${binaryRoot}/sysroot",
  },
  "bundle:output": {
    action: "cmake",
    sourceDir: "${sourceRoot}",
    generator: "Unix Makefiles",
    cacheVariables: {
      CMAKE_INSTALL_PREFIX: "/usr",
      CMAKE_PREFIX_PATH: "${binaryRoot}/sysroot/usr",
      CMAKE_MODULE_PATH: "${binaryRoot}/sysroot/usr/share/libnetq/cmake",
      WASMUX_ARCH: "seal",
    },
    destDir: "${binaryRoot}/sysroot",
    buildType: "Debug",
    rebuild: true,
  },
};
