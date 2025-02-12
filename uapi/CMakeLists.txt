if (WASMUX_ENABLE_LIBC)
  set(LIBC_DEPENDENCIES "")

  if (CONFIG_MALLOC_PATH)
    list(APPEND LIBC_DEPENDENCIES malloc)
    add_subdirectory("${CONFIG_MALLOC_PATH}" malloc)
  endif ()

  if (CONFIG_STRING_PATH)
    list(APPEND LIBC_DEPENDENCIES string)
    add_subdirectory("${CONFIG_STRING_PATH}" string)
  endif ()

  if (CONFIG_CTYPE_PATH)
    list(APPEND LIBC_DEPENDENCIES ctype)
    add_subdirectory("${CONFIG_CTYPE_PATH}" ctype)
  endif ()

  if (CONFIG_STDLIB_PATH)
    list(APPEND LIBC_DEPENDENCIES stdlib)
    add_subdirectory("${CONFIG_STDLIB_PATH}" stdlib)
  endif ()

  if (CONFIG_SIGNAL_PATH)
    list(APPEND LIBC_DEPENDENCIES signal)
    add_subdirectory("${CONFIG_SIGNAL_PATH}" signal)
  endif ()

  if (CONFIG_SEMAPHORE_PATH)
    list(APPEND LIBC_DEPENDENCIES semaphore)
    add_subdirectory("${CONFIG_SEMAPHORE_PATH}" semaphore)
  endif ()

  if (CONFIG_WCSMBS_PATH)
    list(APPEND LIBC_DEPENDENCIES wcsmbs)
    add_subdirectory("${CONFIG_WCSMBS_PATH}" wcsmbs)
  endif ()

  if (CONFIG_LIBIO_PATH)
    list(APPEND LIBC_DEPENDENCIES libio)
    add_subdirectory("${CONFIG_LIBIO_PATH}" libio)
  endif ()

  if (CONFIG_DIRENT_PATH)
    list(APPEND LIBC_DEPENDENCIES dirent)
    add_subdirectory("${CONFIG_DIRENT_PATH}" dirent)
  endif ()

  if (CONFIG_GRP_PATH)
    list(APPEND LIBC_DEPENDENCIES grp)
    add_subdirectory("${CONFIG_GRP_PATH}" grp)
  endif ()

  if (CONFIG_PWD_PATH)
    list(APPEND LIBC_DEPENDENCIES pwd)
    add_subdirectory("${CONFIG_PWD_PATH}" pwd)
  endif ()

  if (CONFIG_FTW_PATH)
    list(APPEND LIBC_DEPENDENCIES ftw)
    add_subdirectory("${CONFIG_FTW_PATH}" ftw)
  endif ()

  if (CONFIG_WORDEXP_PATH)
    list(APPEND LIBC_DEPENDENCIES wordexp)
    add_subdirectory("${CONFIG_WORDEXP_PATH}" wordexp)
  endif ()

  if (CONFIG_LOGIN_PATH)
    list(APPEND LIBC_DEPENDENCIES login)
    add_subdirectory("${CONFIG_LOGIN_PATH}" login)
  endif ()

  if (CONFIG_MNTENT_PATH)
    list(APPEND LIBC_DEPENDENCIES mntent)
    add_subdirectory("${CONFIG_MNTENT_PATH}" mntent)
  endif ()

  if (CONFIG_SHADOW_PATH)
    list(APPEND LIBC_DEPENDENCIES shadow)
    add_subdirectory("${CONFIG_SHADOW_PATH}" shadow)
  endif ()

  if (CONFIG_TERMIOS_PATH)
    list(APPEND LIBC_DEPENDENCIES termios)
    add_subdirectory("${CONFIG_TERMIOS_PATH}" termios)
  endif ()

  if (CONFIG_ARGP_PATH)
    list(APPEND LIBC_DEPENDENCIES argp)
    add_subdirectory("${CONFIG_ARGP_PATH}" argp)
  endif ()

  if (CONFIG_FTS_PATH)
    list(APPEND LIBC_DEPENDENCIES fts)
    add_subdirectory("${CONFIG_FTS_PATH}" fts)
  endif ()

  if (CONFIG_NETDB_PATH)
    list(APPEND LIBC_DEPENDENCIES netdb)
    add_subdirectory("${CONFIG_NETDB_PATH}" netdb)
  endif ()

  if (CONFIG_OBSTACK_PATH)
    list(APPEND LIBC_DEPENDENCIES obstack)
    add_subdirectory("${CONFIG_OBSTACK_PATH}" obstack)
  endif ()

  if (CONFIG_LIBINTL_PATH)
    list(APPEND LIBC_DEPENDENCIES libintl)
    add_subdirectory("${CONFIG_LIBINTL_PATH}" libintl)
  endif ()

  if (CONFIG_LOCALE_PATH)
    list(APPEND LIBC_DEPENDENCIES locale)
    add_subdirectory("${CONFIG_LOCALE_PATH}" locale)
  endif ()

  if (CONFIG_GETOPT_PATH)
    list(APPEND LIBC_DEPENDENCIES getopt)
    add_subdirectory("${CONFIG_GETOPT_PATH}" getopt)
  endif ()

  if (CONFIG_REGEX_PATH)
    list(APPEND LIBC_DEPENDENCIES regex)
    add_subdirectory("${CONFIG_REGEX_PATH}" regex)
  endif ()

  if (CONFIG_GLOB_PATH)
    list(APPEND LIBC_DEPENDENCIES glob)
    add_subdirectory("${CONFIG_GLOB_PATH}" glob)
  endif ()

  if (CONFIG_FNMATCH_PATH)
    list(APPEND LIBC_DEPENDENCIES fnmatch)
    add_subdirectory("${CONFIG_FNMATCH_PATH}" fnmatch)
  endif ()

  if (CONFIG_ULINUX_PATH)
    list(APPEND LIBC_DEPENDENCIES ulinux)
    add_subdirectory("${CONFIG_ULINUX_PATH}" ulinux)
  endif ()

  add_subdirectory(libc)
endif ()

if (WASMUX_ENABLE_LIBGCC)
  add_subdirectory(libgcc)
endif ()

if (WASMUX_ENABLE_CRT)
  add_subdirectory(crt)
endif ()

if (WASMUX_ENABLE_LIBCXX)
  add_subdirectory(libcxx)
  add_subdirectory(libcxxabi)
endif ()

if (WASMUX_ENABLE_LIBM)
  add_subdirectory(libm)
endif ()

if (WASMUX_ENABLE_DL)
  add_subdirectory(dl)
endif ()

if (WASMUX_ENABLE_PTHREAD)
  add_subdirectory(pthread)
endif ()
