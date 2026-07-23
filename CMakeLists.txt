cmake_minimum_required(VERSION 3.20.0)
project(wasmux VERSION 0.0.3
  DESCRIPTION "WebAssembly toolchain for compiling libc and kernel into system-level WASM modules"
  HOMEPAGE_URL "https://github.com/yacubin/wasmux"
  )

find_package(LibNetQ REQUIRED)
find_program(NODE_EXECUTABLE node REQUIRED)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES tools/emit.c)
add_executable(emit tools/emit.c)
target_link_libraries(emit LibNetQ::LibNetQ)

macro (WASMUX_OPTION_DEFINE _name _description _type _value)
  if ("${_type}" STREQUAL BOOL)
    option(WASMUX_${_name} "${_description}" ${_value})
  endif ()

  if ("${_type}" STREQUAL NUMBER)
    set(WASMUX_${_name} "${_value}" CACHE STRING "${_description}")
  endif ()

  if ("${_type}" STREQUAL STRING)
    set(WASMUX_${_name} "${_value}" CACHE STRING "${_description}")
  endif ()

  if ("${_type}" STREQUAL ENUM)
    set(WASMUX_${_name} "${_value}" CACHE STRING "${_description}")
    if (NOT "${ARGN}" STREQUAL "")
      set_property(CACHE WASMUX_${_name} PROPERTY STRINGS "${_value};${ARGN}")
    endif ()
  endif ()
endmacro ()

WASMUX_OPTION_DEFINE(ARCH "Target architecture for libc" ENUM "user" "core" "seal")
WASMUX_OPTION_DEFINE(ARCH_DIR "Architecture directory" STRING "")
WASMUX_OPTION_DEFINE(VERSION "WASMUX Version" STRING "${PROJECT_VERSION}")
WASMUX_OPTION_DEFINE(DESCRIPTION "WASMUX Description" STRING "${PROJECT_DESCRIPTION}")
WASMUX_OPTION_DEFINE(URL "WASMUX URL" STRING "${PROJECT_HOMEPAGE_URL}")
WASMUX_OPTION_DEFINE(LOADER_SECTION "Loader section" STRING ".jsdata.loader")
WASMUX_OPTION_DEFINE(WORKER_SECTION "Worker section" STRING ".jsdata.worker")
WASMUX_OPTION_DEFINE(MANIFEST_SECTION "Manifest section" STRING ".jsdata.manifest")
WASMUX_OPTION_DEFINE(THREADS "Enable threads" BOOL TRUE)
WASMUX_OPTION_DEFINE(KERNEL "Enable kernel installation" BOOL FALSE)
WASMUX_OPTION_DEFINE(LIBC "Enable libc library" BOOL FALSE)
WASMUX_OPTION_DEFINE(LIBC_FEATURES "Choosing features for libc" ENUM "none" "glibc" "uclibc")
WASMUX_OPTION_DEFINE(ENV_WITH_LIBC "Built-in env in libc" BOOL TRUE)
WASMUX_OPTION_DEFINE(ENV_STUB "Stub implementations for env" BOOL FALSE)
WASMUX_OPTION_DEFINE(LOCALE_WITH_LIBC "Built-in locale in libc" BOOL TRUE)
WASMUX_OPTION_DEFINE(CRT "Enable C Runtime Library" BOOL FALSE)
WASMUX_OPTION_DEFINE(RT "Enable Real-Time library" BOOL FALSE)
WASMUX_OPTION_DEFINE(TIME_WITH_RT "Built-in time into Real-Time library" BOOL FALSE)
WASMUX_OPTION_DEFINE(LIBGCC "Enable libgcc library" BOOL FALSE)
WASMUX_OPTION_DEFINE(LIBCXX "Enable libcxx library" BOOL FALSE)
WASMUX_OPTION_DEFINE(LIBCXX "Enable libcxxabi library" BOOL FALSE)
WASMUX_OPTION_DEFINE(LIBCXX "Enable Math library" BOOL FALSE)
WASMUX_OPTION_DEFINE(LIBCXX "Enable Dynamic linking library" BOOL FALSE)
WASMUX_OPTION_DEFINE(PTHREAD "Enable pthread library" BOOL FALSE)
WASMUX_OPTION_DEFINE(PTHREAD_WITH_LIBC "Built-in pthread in lib" BOOL FALSE)
WASMUX_OPTION_DEFINE(MAIN_ENV_ARG "Enable env argument for main function" BOOL FALSE)
WASMUX_OPTION_DEFINE(CORE_INIT_PAGES "Initial size of core pages" NUMBER 16)
WASMUX_OPTION_DEFINE(CORE_MAX_PAGES "Maximum size of core pages" NUMBER 124)
WASMUX_OPTION_DEFINE(WEI "Enable Web Enviromet Interface" BOOL FALSE)

# FIXME
include_directories(build/include)

add_subdirectory(wasmux)
add_subdirectory(uapi)

configure_file(wasmux-config.h.in "${CMAKE_CURRENT_BINARY_DIR}/wasmux-config.h" @ONLY)
