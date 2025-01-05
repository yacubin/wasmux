if (CONFIG_ARGP_PATH)
  add_subdirectory("${CONFIG_ARGP_PATH}" argp)
endif ()

if (CONFIG_FTS_PATH)
  add_subdirectory("${CONFIG_FTS_PATH}" fts)
endif ()

add_subdirectory(netdb)

if (CONFIG_OBSTACK_PATH)
  add_subdirectory("${CONFIG_OBSTACK_PATH}" obstack)
endif ()

if (CONFIG_LOCALE_PATH)
  add_subdirectory("${CONFIG_LOCALE_PATH}" locale)
endif ()

if (CONFIG_GETOPT_PATH)
  add_subdirectory("${CONFIG_GETOPT_PATH}" getopt)
endif ()

if (CONFIG_LIBINTL_PATH)
  add_subdirectory("${CONFIG_LIBINTL_PATH}" libintl)
endif ()

if (CONFIG_ENABLE_LIBGCC)
  add_subdirectory(libgcc)
endif ()

if (CONFIG_ENABLE_LIBC)
  add_subdirectory(libc)
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
