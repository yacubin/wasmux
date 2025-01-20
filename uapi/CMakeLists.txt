if (CONFIG_ENABLE_LIBC)
  if (CONFIG_MALLOC_PATH)
    add_subdirectory("${CONFIG_MALLOC_PATH}" malloc)
  endif ()

  if (CONFIG_STRING_PATH)
    add_subdirectory("${CONFIG_STRING_PATH}" string)
  endif ()

  if (CONFIG_LIBIO_PATH)
    add_subdirectory("${CONFIG_LIBIO_PATH}" libio)
  endif ()

  if (CONFIG_WCSMBS_PATH)
    add_subdirectory("${CONFIG_WCSMBS_PATH}" wcsmbs)
  endif ()

  if (CONFIG_ARGP_PATH)
    add_subdirectory("${CONFIG_ARGP_PATH}" argp)
  endif ()

  if (CONFIG_FTS_PATH)
    add_subdirectory("${CONFIG_FTS_PATH}" fts)
  endif ()

  if (CONFIG_NETDB_PATH)
    add_subdirectory("${CONFIG_NETDB_PATH}" netdb)
  endif ()

  if (CONFIG_OBSTACK_PATH)
    add_subdirectory("${CONFIG_OBSTACK_PATH}" obstack)
  endif ()

  if (CONFIG_LIBINTL_PATH)
    add_subdirectory("${CONFIG_LIBINTL_PATH}" libintl)
  endif ()

  if (CONFIG_LOCALE_PATH)
    add_subdirectory("${CONFIG_LOCALE_PATH}" locale)
  endif ()

  if (CONFIG_GETOPT_PATH)
    add_subdirectory("${CONFIG_GETOPT_PATH}" getopt)
  endif ()

  if (CONFIG_REGEX_PATH)
    add_subdirectory("${CONFIG_REGEX_PATH}" regex)
  endif ()

  if (CONFIG_GLOB_PATH)
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
