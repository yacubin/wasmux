set(WASMUX_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

set(WASMUX_INSTALL_BINDIR "bin")
set(WASMUX_INSTALL_LIBDIR "lib")
set(WASMUX_INSTALL_INCLUDEDIR "include")

set(CONFIG_TARGET_SYSTEM wasm32 CACHE STRING "Target system")
set_property(CACHE CONFIG_TARGET_SYSTEM PROPERTY STRINGS wasm32 wasm64 wasm32-wasi wasm64-wasi)

if (CONFIG_TARGET_SYSTEM MATCHES "-wasi$")
  set(WASMUX_INSTALL_LIBDIR "${WASMUX_INSTALL_LIBDIR}/${CMAKE_SYSTEM_PROCESSOR}-wasi")
endif ()

option(CONFIG_ENABLE_TLS "Enable thread-local storage" ON)
option(CONFIG_ENABLE_KERNEL "Enable kernel installation" OFF)
option(CONFIG_ENABLE_GETOPT "Enable getopt functionality" ON)
option(CONFIG_ENABLE_LIBGCC "Enable libgcc library" ON)
option(CONFIG_ENABLE_LIBC "Enable libc library" ON)
option(CONFIG_ENABLE_CRT "Enable C Run-Time" ON)
option(CONFIG_ENABLE_LIBM "Enable Math library" ON)
option(CONFIG_ENABLE_DL "Enable Dynamic library" ON)
option(CONFIG_ENABLE_LIBCXX "Enable libc++ library" ON)
option(CONFIG_ENABLE_PTHREAD "Enable pthread library" ON)
option(CONFIG_ENABLE_MAIN_ENV_ARG "Enable env argument for main function" OFF)

set(CONFIG_ARGP_PATH "${WASMUX_ROOT_DIR}/uapi/argp" CACHE STRING "Path to argp standalone")
set(CONFIG_FTS_PATH "${WASMUX_ROOT_DIR}/uapi/fts" CACHE STRING "Path to fts standalone")
set(CONFIG_OBSTACK_PATH "${WASMUX_ROOT_DIR}/uapi/obstack" CACHE STRING "Path to obstack standalone")

macro(WASMUX_INSTALL_HEADERS)
  cmake_parse_arguments(__waf_install_headers
    ""
    "BASE_DIR;DESTINATION"
    "HEADERS"
    ${ARGN}
    )
  foreach (__waf_install_headers_iter IN LISTS __waf_install_headers_HEADERS)
    set(__waf_install_headers_file "${__waf_install_headers_iter}")
    if (__waf_install_headers_BASE_DIR)
      string(REGEX REPLACE "^${__waf_install_headers_BASE_DIR}[\\/]?(.*)" "\\1" __waf_install_headers_file "${__waf_install_headers_iter}")
    endif ()
    get_filename_component(__waf_install_headers_dir "${__waf_install_headers_DESTINATION}/${__waf_install_headers_file}" DIRECTORY)
    install(FILES "${__waf_install_headers_iter}" DESTINATION "${__waf_install_headers_dir}")
  endforeach ()
endmacro()

include(GenScript)
