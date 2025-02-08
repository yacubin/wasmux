module.exports = {
  CONFIG_ENABLE_INSTALL_HEADERS: {
    description: "Enable install headers",
    value: true,
  },
  CONFIG_TARGET_SYSTEM: {
    description: "Target system",
    type: [ "wasm32", "wasm64", "wasm32-wasi", "wasm64-wasi" ],
    value: "wasm32",
  },
  CONFIG_ENABLE_TLS: {
    description: "Enable thread-local storage",
    value: true,
  },
  CONFIG_ENABLE_KERNEL: {
    description: "Enable kernel installation",
    value: false,
  },
  CONFIG_ENABLE_LIBGCC: {
    description: "Enable libgcc library",
    value: true,
  },
  CONFIG_ENABLE_LIBC: {
    description: "Enable libc library",
    value: true,
  },
  CONFIG_ENABLE_CRT: {
    description: "Enable C Run-Time",
    value: true,
  },
  CONFIG_ENABLE_LIBM: {
    description: "Enable Math library",
    value: true,
  },
  CONFIG_ENABLE_DL: {
    description: "Enable Dynamic library",
    value: true,
  },
  CONFIG_ENABLE_LIBCXX: {
    description: "Enable libc++ library",
    value: true,
  },
  CONFIG_ENABLE_PTHREAD: {
    description: "Enable pthread library",
    value: true,
  },
  CONFIG_ENABLE_MAIN_ENV_ARG: {
    description: "Enable env argument for main function",
    value: false,
  },
  CONFIG_LIBC_FEATURES: {
    description: "Choosing features for libc",
    type: [ "none", "glibc", "uclibc" ],
    value: "glibc",
  },
  CONFIG_CORE_INIT_PAGES: {
    description: "Initial size of core pages",
    value: 16,
  },
  CONFIG_CORE_MAX_PAGES: {
    description: "Maximum size of core pages",
    value: 124,
  },
  CONFIG_MALLOC_PATH: {
    description: "Path to malloc standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/malloc",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_STRING_PATH: {
    description: "Path to string standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/string",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_CTYPE_PATH: {
    description: "Path to ctype standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/ctype",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_STDLIB_PATH: {
    description: "Path to stdlib standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/stdlib",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_SIGNAL_PATH: {
    description: "Path to signal standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/signal",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_SEMAPHORE_PATH: {
    description: "Path to semaphore standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/semaphore",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_WCSMBS_PATH: {
    description: "Path to wcsmbs standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/wcsmbs",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_LIBIO_PATH: {
    description: "Path to libio standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/libio",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_DIRENT_PATH: {
    description: "Path to dirent standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/dirent",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_GRP_PATH: {
    description: "Path to grp standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/grp",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_PWD_PATH: {
    description: "Path to pwd standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/pwd",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_FTW_PATH: {
    description: "Path to ftw standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/ftw",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_WORDEXP_PATH: {
    description: "Path to wordexp standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/wordexp",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_LOGIN_PATH: {
    description: "Path to login standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/login",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_MNTENT_PATH: {
    description: "Path to mntent standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/mntent",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_SHADOW_PATH: {
    description: "Path to shadow standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/shadow",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_TERMIOS_PATH: {
    description: "Path to termios standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/termios",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_ARGP_PATH: {
    description: "Path to argp standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/argp",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_FTS_PATH: {
    description: "Path to fts standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/fts",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_NETDB_PATH: {
    description: "Path to netdb standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/netdb",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_OBSTACK_PATH: {
    description: "Path to obstack standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/obstack",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_LIBINTL_PATH: {
    description: "Path to libintl standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/libintl",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_LOCALE_PATH: {
    description: "Path to locale standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/locale",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_GETOPT_PATH: {
    description: "Path to getopt standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/getopt",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_REGEX_PATH: {
    description: "Path to regex standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/regex",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_GLOB_PATH: {
    description: "Path to glob standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/glob",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_FNMATCH_PATH: {
    description: "Path to fnmatch standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/fnmatch",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_ULINUX_PATH: {
    description: "Path to ulinux standalone",
    value: "${WASMUX_ROOT_DIR}/uapi/ulinux",
    dependency: "CONFIG_ENABLE_LIBC",
  },
  CONFIG_JSDATA_PATH: {
    description: "Path to jsdata standalone",
    value: "${WASMUX_ROOT_DIR}/kernel/jsdata",
    dependency: "CONFIG_ENABLE_KERNEL",
  },
  CONFIG_ENABLE_WAEDITOR: {
    description: "Enable waeditor tool",
    value: false,
  },
};
