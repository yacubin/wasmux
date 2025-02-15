export default {
  WASMUX_VERSION: {
    description: "WASMUX Version",
    value: "${PROJECT_VERSION}",
  },
  WASMUX_DESCRIPTION: {
    description: "${PROJECT_DESCRIPTION}",
    value: "WASMUX Description",
  },
  WASMUX_URL: {
    description: "WASMUX URL",
    value: "${PROJECT_HOMEPAGE_URL}",
  },
  WASMUX_LOADER_SECTION: {
    description: "Loader section",
    value: ".jsdata.loader",
  },
  WASMUX_WORKER_SECTION: {
    description: "Worker section",
    value: ".jsdata.worker",
  },
  WASMUX_VERSION_SECTION: {
    description: "Version section",
    value: ".jsdata.version",
  },
  WASMUX_ENABLE_INSTALL_HEADERS: {
    description: "Enable install headers",
    value: true,
  },
  WASMUX_ENABLE_THREADS: {
    description: "Enable threads",
    value: true,
  },
  WASMUX_ENABLE_KERNEL: {
    description: "Enable kernel installation",
    value: false,
  },
  WASMUX_ENABLE_LIBGCC: {
    description: "Enable libgcc library",
    value: true,
  },
  WASMUX_ENABLE_LIBC: {
    description: "Enable libc library",
    value: true,
  },
  WASMUX_ENABLE_CRT: {
    description: "Enable C Run-Time",
    value: true,
  },
  WASMUX_ENABLE_LIBM: {
    description: "Enable Math library",
    value: true,
  },
  WASMUX_ENABLE_DL: {
    description: "Enable Dynamic library",
    value: true,
  },
  WASMUX_ENABLE_LIBCXX: {
    description: "Enable libc++ library",
    value: true,
  },
  WASMUX_ENABLE_PTHREAD: {
    description: "Enable pthread library",
    value: true,
  },
  WASMUX_ENABLE_MAIN_ENV_ARG: {
    description: "Enable env argument for main function",
    value: false,
  },
  WASMUX_ENABLE_WAEDITOR: {
    description: "Enable waeditor tool",
    value: false,
  },
  WASMUX_CORE_INIT_PAGES: {
    description: "Initial size of core pages",
    value: 16,
  },
  WASMUX_CORE_MAX_PAGES: {
    description: "Maximum size of core pages",
    value: 124,
  },
  WASMUX_TARGET_SYSTEM: {
    description: "Target system",
    type: [ "wasm32", "wasm64", "wasm32-wasi", "wasm64-wasi" ],
    value: "wasm32",
  },
  WASMUX_LIBC_FEATURES: {
    description: "Choosing features for libc",
    type: [ "none", "glibc", "uclibc" ],
    value: "glibc",
  },
  WASMUX_INJECT_SCRIPT_LIST: {
    description: "Injections to build",
    value: "",
  },
  CONFIG_JSDATA_PATH: {
    description: "Path to jsdata standalone",
    depends: "WASMUX_ENABLE_KERNEL",
    value: "${WASMUX_ROOT_DIR}/kernel/jsdata",
  },
};
