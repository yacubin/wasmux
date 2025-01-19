set(libc_HEADERS
  include/arpa/inet.h
  include/linux/version.h
  include/net/if.h
  include/netinet/in.h
  include/netinet/tcp.h
  include/sys/endian.h
  include/sys/file.h
  include/sys/ioctl.h
  include/sys/mman.h
  include/sys/param.h
  include/sys/random.h
  include/sys/resource.h
  include/sys/select.h
  include/sys/socket.h
  include/sys/stat.h
  include/sys/statfs.h
  include/sys/syscall.h
  include/sys/sysinfo.h
  include/sys/sysmacros.h
  include/sys/time.h
  include/sys/times.h
  include/sys/types.h
  include/sys/uio.h
  include/sys/un.h
  include/sys/utsname.h
  include/sys/vfs.h
  include/sys/wait.h
  include/sys/xattr.h
  include/alloca.h
  include/ar.h
  include/assert.h
  include/byteswap.h
  include/ctype.h
  include/dirent.h
  include/endian.h
  include/errno.h
  include/fcntl.h
  include/fnmatch.h
  include/ftw.h
  include/grp.h
  include/inttypes.h
  include/libgen.h
  include/limits.h
  include/memory.h
  include/mntent.h
  include/paths.h
  include/poll.h
  include/pwd.h
  include/sched.h
  include/search.h
  include/setjmp.h
  include/setjmp.h
  include/signal.h
  include/spawn.h
  include/stdarg.h
  include/stddef.h
  include/stdint.h
  include/stdlib.h
  include/sysexits.h
  include/syslog.h
  include/syslog.h
  include/termios.h
  include/time.h
  include/ucontext.h
  include/unistd.h
  include/utime.h
  include/utmp.h
  include/utmpx.h
  include/wchar.h
  )

set(libc_SOURCES
  dirent/dirfd.cpp
  stub/apra/inet.cpp
  stub/sys/mman.cpp
  stub/sys/random.cpp
  stub/sys/resource.cpp
  stub/sys/select.cpp
  stub/sys/socket.cpp
  stub/sys/stat.cpp
  stub/sys/statfs.cpp
  stub/sys/sysinfo.cpp
  stub/sys/sysmacros.cpp
  stub/sys/time.cpp
  stub/sys/uio.cpp
  stub/sys/utsname.cpp
  stub/sys/vfs.cpp
  stub/sys/wait.cpp
  stub/sys/xattr.cpp
  stub/abort.cpp
  stub/access.cpp
  stub/ctype.cpp
  stub/dirent.cpp
  stub/environ.cpp
  stub/exit.cpp
  stub/fcntl.cpp
  stub/fnmatch.cpp
  stub/getenv.cpp
  stub/getmntent.cpp
  stub/grp.cpp
  stub/libgen.cpp
  stub/lseek.cpp
  stub/pipe.cpp
  stub/poll.cpp
  stub/progname.cpp
  stub/putc.cpp
  stub/pwd.cpp
  stub/qsort.cpp
  stub/read.cpp
  stub/search.cpp
  stub/setjmp.cpp
  stub/signal.cpp
  stub/stdlib.cpp
  stub/strtol.cpp
  stub/syslog.cpp
  stub/termios.cpp
  stub/time.cpp
  stub/unistd.cpp
  stub/utime.cpp
  stub/utmpx.cpp
  stub/wchar.cpp
  syscalls/brk.cpp
  syscalls/chdir.cpp
  syscalls/close.cpp
  syscalls/creat.cpp
  syscalls/execve.cpp
  syscalls/getcwd.cpp
  syscalls/getegid.cpp
  syscalls/geteuid.cpp
  syscalls/getgid.cpp
  syscalls/gettid.cpp
  syscalls/getuid.cpp
  syscalls/ioctl.cpp
  syscalls/mknod.cpp
  syscalls/open.cpp
  syscalls/read.cpp
  syscalls/waitpid.cpp
  syscalls/write.cpp
  isatty.cpp
  ttyname.cpp
  sbrk.cpp

  $<TARGET_OBJECTS:wabase>
  $<TARGET_OBJECTS:wauser>
  $<TARGET_OBJECTS:netdb>
  )

set(libc_INCLUDES
  "${CMAKE_CURRENT_BINARY_DIR}/include"
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

set(libc_DEFINITIONS
  )

set(libc_LIBRARIES
  wauser
  )

set(libc_DEPENDENCIES
  malloc
  string
  libio
  wcsmbs
  argp
  fts
  libintl
  locale
  )

foreach (_lib ${libc_DEPENDENCIES})
  list(APPEND libc_INCLUDES $<TARGET_PROPERTY:${_lib},INTERFACE_INCLUDE_DIRECTORIES>)
  list(APPEND libc_SOURCES $<TARGET_OBJECTS:${_lib}>)
endforeach ()

if (TARGET obstack)
  set(CONFIG_OBSTACK_INTERFACE_VERSION 1)
  list(APPEND libc_INCLUDES $<TARGET_PROPERTY:obstack,INTERFACE_INCLUDE_DIRECTORIES>)
  list(APPEND libc_SOURCES $<TARGET_OBJECTS:obstack>)
endif ()

if (TARGET getopt)
  set(CONFIG_GETOPT_INTERFACE_VERSION 2)
  list(APPEND libc_INCLUDES $<TARGET_PROPERTY:getopt,INTERFACE_INCLUDE_DIRECTORIES>)
  list(APPEND libc_SOURCES $<TARGET_OBJECTS:getopt>)
else ()
  list(APPEND libc_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/nogetopt")
  WX_INSTALL_HEADERS(HEADERS nogetopt/getopt_unistd.h BASE_DIR nogetopt DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()

if (TARGET regex)
  set(CONFIG_REGEX_INTERFACE_VERSION 1)
  list(APPEND libc_INCLUDES $<TARGET_PROPERTY:regex,INTERFACE_INCLUDE_DIRECTORIES>)
  list(APPEND libc_SOURCES $<TARGET_OBJECTS:regex>)
endif ()

if (TARGET glob)
  set(CONFIG_GLOB_INTERFACE_VERSION 2)
  list(APPEND libc_INCLUDES $<TARGET_PROPERTY:glob,INTERFACE_INCLUDE_DIRECTORIES>)
  list(APPEND libc_SOURCES $<TARGET_OBJECTS:glob>)
endif ()

configure_file("features/${CONFIG_LIBC_FEATURES}-features.h" "${CMAKE_CURRENT_BINARY_DIR}/include/features.h" COPYONLY)
configure_file("gnu-versions.h.cmake" "${CMAKE_CURRENT_BINARY_DIR}/include/gnu-versions.h" @ONLY)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${libc_HEADERS} ${libc_SOURCES})
add_library(libc STATIC ${libc_HEADERS} ${libc_SOURCES})
target_include_directories(libc PUBLIC ${libc_INCLUDES})
target_compile_definitions(libc PRIVATE ${libc_DEFINITIONS})
target_link_libraries(libc PUBLIC ${libc_LIBRARIES})
set_target_properties(libc PROPERTIES PREFIX "")

add_library(WASMUX::LIBC ALIAS libc)

install(TARGETS libc
  RUNTIME DESTINATION "${WASMUX_INSTALL_BINDIR}"
  LIBRARY DESTINATION "${WASMUX_INSTALL_LIBDIR}"
  ARCHIVE DESTINATION "${WASMUX_INSTALL_LIBDIR}"
  )

if (CONFIG_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${libc_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
  install(FILES "${CMAKE_CURRENT_BINARY_DIR}/include/features.h" DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
  install(FILES "${CMAKE_CURRENT_BINARY_DIR}/include/gnu-versions.h" DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
