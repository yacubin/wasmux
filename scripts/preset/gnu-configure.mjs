import path from "node:path";

export default function(env, argv) {
  return {
    sysroot: {
      arch: "wasm32",
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
      binaryDir: path.resolve(process.cwd(), "build/wasm32/wasmux"),
      destDir: path.resolve(process.cwd(), "build/sysroot"),
    },
    output: {
      action: "configure",
      variables: {
        build: "x86_64-pc-linux-gnu",
        host: "wasm32",
        target: "wasm32",
        prefix: "/usr",
      },
      environment: {
        CC: "clang",
        CXX: "clang++",
        LD: "wasm-ld",
        AR: "llvm-ar",
        STRIP: "llvm-strip",
        RANLIB: "llvm-ranlib",
        CFLAGS: `--target=wasm32 -matomics -mmultivalue -mbulk-memory -O3 --sysroot=${path.resolve(process.cwd(), "build/sysroot/usr")}`,
        CXXFLAGS: `--target=wasm32 -matomics -mmultivalue -mbulk-memory -O3 --sysroot=${path.resolve(process.cwd(), "build/sysroot/usr")}`,
        LDFLAGS: "-Wl,--max-memory=2147483648 -Wl,--export-dynamic -Wl,--import-memory -Wl,--stack-first -z stack-size=131072 -rtlib=libgcc",
      },
      binaryDir: path.resolve(process.cwd(), "build/wasm32/output"),
      destDir: path.resolve(process.cwd(), "build/output"),
    },
  };
}
