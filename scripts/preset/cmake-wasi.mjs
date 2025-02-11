import path from "node:path";

export default function(env, argv) {
  return {
    sysroot: {
      arch: "wasm32-wasi",
      generator: "Unix Makefiles",
      cacheVariables: {
        CMAKE_INSTALL_PREFIX: "/usr",
        WASMUX_ENABLE_THREADS: true,
        WASMUX_ENABLE_KERNEL: false,
        CONFIG_ENABLE_LIBC: true,
        CONFIG_ENABLE_CRT: true,
        CONFIG_ENABLE_LIBM: true,
        CONFIG_ENABLE_DL: true,
        CONFIG_ENABLE_MAIN_ENV_ARG: false,
      },
      binaryDir: path.resolve(process.cwd(), "build/wasm32-wasi/wasmux"),
      destDir: path.resolve(process.cwd(), "build/sysroot"),
    },
    output: {
      action: "cmake",
      generator: "Unix Makefiles",
      cacheVariables: {
        CMAKE_INSTALL_PREFIX: "/usr",
      },
      binaryDir: path.resolve(process.cwd(), "build/wasm32-wasi/output"),
      destDir: path.resolve(process.cwd(), "build/output/release"),
    },
  };
}
