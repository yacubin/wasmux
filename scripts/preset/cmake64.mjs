import path from "node:path";

export default function(env, argv) {
  return {
    sysroot: {
      arch: "wasm64",
      generator: "Unix Makefiles",
      cacheVariables: {
        CMAKE_INSTALL_PREFIX: "/usr",
        CONFIG_ENABLE_TLS: true,
        CONFIG_ENABLE_KERNEL: false,
        CONFIG_ENABLE_GETOPT: true,
        CONFIG_ENABLE_LIBC: true,
        CONFIG_ENABLE_CRT: true,
        CONFIG_ENABLE_LIBM: true,
        CONFIG_ENABLE_DL: true,
        CONFIG_ENABLE_MAIN_ENV_ARG: false,
      },
      binaryDir: path.resolve(process.cwd(), "build/wasm64/wasmux"),
      destDir: path.resolve(process.cwd(), "build/sysroot"),
    },
    output: {
      action: "cmake",
      generator: "Unix Makefiles",
      cacheVariables: {
        CMAKE_INSTALL_PREFIX: "/usr",
      },
      binaryDir: path.resolve(process.cwd(), "build/wasm64/output"),
      destDir: path.resolve(process.cwd(), "build/output"),
    },
  };
}
