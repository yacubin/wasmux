if (CONFIG_ENABLE_LIBC)
  set(LIBC_DEPENDENCIES "")

  if (CONFIG_MALLOC_PATH)
    list(APPEND LIBC_DEPENDENCIES malloc)
    add_subdirectory("${CONFIG_MALLOC_PATH}" malloc)
  endif ()

  if (CONFIG_STRING_PATH)
    list(APPEND LIBC_DEPENDENCIES string)
    add_subdirectory("${CONFIG_STRING_PATH}" string)
  endif ()

  if (CONFIG_STDLIB_PATH)
    list(APPEND LIBC_DEPENDENCIES stdlib)
    add_subdirectory("${CONFIG_STDLIB_PATH}" stdlib)
  endif ()

  if (CONFIG_LIBIO_PATH)
    list(APPEND LIBC_DEPENDENCIES libio)
    add_subdirectory("${CONFIG_LIBIO_PATH}" libio)
  endif ()

  if (CONFIG_WCSMBS_PATH)
    list(APPEND LIBC_DEPENDENCIES wcsmbs)
    add_subdirectory("${CONFIG_WCSMBS_PATH}" wcsmbs)
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

  add_subdirectory(libc)
endif ()

if (CONFIG_ENABLE_LIBGCC)
  add_subdirectory(libgcc)
endif ()

if (CONFIG_ENABLE_CRT)
  add_subdirectory(crt)
endif ()

if (CONFIG_ENABLE_LIBCXX)
  add_subdirectory(libcxx)
  add_subdirectory(libcxxabi)
endif ()

if (CONFIG_ENABLE_LIBM)
  add_subdirectory(libm)
endif ()

if (CONFIG_ENABLE_DL)
  add_subdirectory(dl)
endif ()

if (CONFIG_ENABLE_PTHREAD)
  add_subdirectory(pthread)
endif ()
