import path from "node:path";

export default function(env, argv) {
  return {
    sysroot: {
      arch: "wasm32",
      generator: "Unix Makefiles",
      cacheVariables: {
        CMAKE_INSTALL_PREFIX: "/usr",
        WASMUX_ENABLE_THREADS: true,
        WASMUX_ENABLE_KERNEL: false,
        WASMUX_ENABLE_LIBC: true,
        WASMUX_ENABLE_CRT: true,
        WASMUX_ENABLE_LIBM: true,
        CONFIG_ENABLE_DL: true,
        CONFIG_ENABLE_MAIN_ENV_ARG: false,
      },
      binaryDir: path.resolve(process.cwd(), "build/wasm32/wasmux"),
      destDir: path.resolve(process.cwd(), "build/sysroot"),
    },
    output: {
      action: "cmake",
      generator: "Unix Makefiles",
      cacheVariables: {
        CMAKE_INSTALL_PREFIX: "/usr",
      },
      binaryDir: path.resolve(process.cwd(), "build/wasm32/output"),
      destDir: path.resolve(process.cwd(), "build/output"),
    },
  };
}
