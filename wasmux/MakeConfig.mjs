export default {
  WASMUX_ARCH: {
    description: "Target architecture for libc",
    type: [ "user", "core", "seal" ],
    value: "user",
  },
  WASMUX_VERSION: {
    description: "WASMUX Version",
    type: "string",
  },
  WASMUX_DESCRIPTION: {
    description: "WASMUX Description",
    type: "string",
  },
  WASMUX_URL: {
    description: "WASMUX URL",
    type: "string",
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
  WASMUX_THREADS: {
    description: "Enable threads",
    value: true,
  },
  WASMUX_KERNEL: {
    description: "Enable kernel installation",
    value: false,
  },
  WASMUX_LIBC: {
    description: "Enable libc library",
    value: false,
  },
  WASMUX_LIBC_FEATURES: {
    description: "Choosing features for libc",
    type: [ "none", "glibc", "uclibc" ],
    value: "none",
  },
  WASMUX_ENV_WITH_LIBC: {
    description: "Built-in env in libc",
    value: true,
  },
  WASMUX_ENV_STUB: {
    description: "Stub implementations for env",
    value: false,
  },
  WASMUX_LOCALE_WITH_LIBC: {
    description: "Built-in locale in libc",
    value: true,
  },
  WASMUX_CRT: {
    description: "Enable C Runtime Library",
    value: false,
  },
  WASMUX_RT: {
    description: "Enable Real-Time library",
    value: false,
  },
  WASMUX_TIME_WITH_RT: {
    description: "Built-in time into Real-Time library",
    value: false,
  },
  WASMUX_LIBGCC: {
    description: "Enable libgcc library",
    value: false,
  },
  WASMUX_LIBCXX: {
    description: "Enable libcxx library",
    value: false,
  },
  WASMUX_LIBCXXABI: {
    description: "Enable libcxxabi library",
    value: false,
  },
  WASMUX_LIBM: {
    description: "Enable Math library",
    value: false,
  },
  WASMUX_DL: {
    description: "Enable Dynamic linking library",
    value: false,
  },
  WASMUX_PTHREAD: {
    description: "Enable pthread library",
    value: false,
  },
  WASMUX_PTHREAD_WITH_LIBC: {
    description: "Built-in pthread in libc",
    value: false,
  },
  WASMUX_MAIN_ENV_ARG: {
    description: "Enable env argument for main function",
    value: false,
  },
  WASMUX_WAEDITOR: {
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
  WASMUX_WEI: {
    description: "Enable Web Enviromet Interface",
    value: false,
  },
};
