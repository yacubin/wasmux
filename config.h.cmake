/* WASMUX Version */
#define WASMUX_VERSION "@PROJECT_VERSION@"

/* WASMUX Description */
#define WASMUX_DESCRIPTION "@PROJECT_DESCRIPTION@"

/* WASMUX URL */
#define WASMUX_URL "@PROJECT_HOMEPAGE_URL@"

/* A triplet defines the architecture parameters */
#cmakedefine CONFIG_TARGET_TRIPLET "@CONFIG_TARGET_TRIPLET@"

/* Enable thread-local storage */
#cmakedefine01 CONFIG_ENABLE_TLS

/* Enable kernel installation */
#cmakedefine01 CONFIG_ENABLE_KERNEL

/* Enable getopt functionality */
#cmakedefine01 CONFIG_ENABLE_GETOPT

/* Enable pthread library */
#cmakedefine01 CONFIG_ENABLE_PTHREAD

/* Enable env argument for main function */
#cmakedefine01 CONFIG_ENABLE_MAIN_ENV_ARG
