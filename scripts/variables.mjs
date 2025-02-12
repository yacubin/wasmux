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
  CONFIG_MALLOC_PATH: {
    description: "Path to malloc standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/malloc",
  },
  CONFIG_STRING_PATH: {
    description: "Path to string standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/string",
  },
  CONFIG_CTYPE_PATH: {
    description: "Path to ctype standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/ctype",
  },
  CONFIG_STDLIB_PATH: {
    description: "Path to stdlib standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/stdlib",
  },
  CONFIG_SIGNAL_PATH: {
    description: "Path to signal standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/signal",
  },
  CONFIG_SEMAPHORE_PATH: {
    description: "Path to semaphore standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/semaphore",
  },
  CONFIG_WCSMBS_PATH: {
    description: "Path to wcsmbs standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/wcsmbs",
  },
  CONFIG_LIBIO_PATH: {
    description: "Path to libio standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/libio",
  },
  CONFIG_DIRENT_PATH: {
    description: "Path to dirent standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/dirent",
  },
  CONFIG_GRP_PATH: {
    description: "Path to grp standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/grp",
  },
  CONFIG_PWD_PATH: {
    description: "Path to pwd standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/pwd",
  },
  CONFIG_FTW_PATH: {
    description: "Path to ftw standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/ftw",
  },
  CONFIG_WORDEXP_PATH: {
    description: "Path to wordexp standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/wordexp",
  },
  CONFIG_LOGIN_PATH: {
    description: "Path to login standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/login",
  },
  CONFIG_MNTENT_PATH: {
    description: "Path to mntent standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/mntent",
  },
  CONFIG_SHADOW_PATH: {
    description: "Path to shadow standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/shadow",
  },
  CONFIG_TERMIOS_PATH: {
    description: "Path to termios standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/termios",
  },
  CONFIG_ARGP_PATH: {
    description: "Path to argp standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/argp",
  },
  CONFIG_FTS_PATH: {
    description: "Path to fts standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/fts",
  },
  CONFIG_NETDB_PATH: {
    description: "Path to netdb standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/netdb",
  },
  CONFIG_OBSTACK_PATH: {
    description: "Path to obstack standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/obstack",
  },
  CONFIG_LIBINTL_PATH: {
    description: "Path to libintl standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/libintl",
  },
  CONFIG_LOCALE_PATH: {
    description: "Path to locale standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/locale",
  },
  CONFIG_GETOPT_PATH: {
    description: "Path to getopt standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/getopt",
  },
  CONFIG_REGEX_PATH: {
    description: "Path to regex standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/regex",
  },
  CONFIG_GLOB_PATH: {
    description: "Path to glob standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/glob",
  },
  CONFIG_FNMATCH_PATH: {
    description: "Path to fnmatch standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/fnmatch",
  },
  CONFIG_ULINUX_PATH: {
    description: "Path to ulinux standalone",
    depends: "WASMUX_ENABLE_LIBC",
    value: "${WASMUX_ROOT_DIR}/uapi/ulinux",
  },
  CONFIG_JSDATA_PATH: {
    description: "Path to jsdata standalone",
    depends: "WASMUX_ENABLE_KERNEL",
    value: "${WASMUX_ROOT_DIR}/kernel/jsdata",
  },
};
