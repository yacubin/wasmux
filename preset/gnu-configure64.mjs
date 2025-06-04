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
    action: "configure",
    variables: {
      build: "x86_64-pc-linux-gnu",
      host: "wasm64",
      target: "wasm64",
      prefix: "/usr",
    },
    environment: {
      CC: "clang",
      CXX: "clang++",
      LD: "wasm-ld",
      AR: "llvm-ar",
      NM: "llvm-nm",
      STRIP: "llvm-strip",
      RANLIB: "llvm-ranlib",
      CFLAGS: [
        "--target=wasm64",
        "-matomics",
        "-mmultivalue",
        "-mbulk-memory",
        "-O3",
        "--sysroot=${bundle:wasmux.destDir}/usr",
      ],
      CXXFLAGS: [
        "--target=wasm64",
        "-matomics",
        "-mmultivalue",
        "-mbulk-memory",
        "-O3",
        "--sysroot=${bundle:wasmux.destDir}/usr",
      ],
      LDFLAGS: [
        "-Wl,--max-memory=2147483648",
        "-Wl,--export-dynamic",
        "-Wl,--import-memory",
        "-Wl,--stack-first",
        "-z", "stack-size=131072",
        "-rtlib=libgcc",
      ],
    },
    sourceDir: "${sourceRoot}",
    destDir: "${binaryRoot}/output",
    rebuild: true,
  },
};
