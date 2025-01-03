add_subdirectory(argp)
add_subdirectory(fts)
add_subdirectory(netdb)
add_subdirectory(obstack)

if (CONFIG_ENABLE_GETOPT)
  add_subdirectory(getopt)
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
