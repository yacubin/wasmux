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
  include/endian.h
  include/errno.h
  include/fcntl.h
  include/float.h
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
  include/spawn.h
  include/stdarg.h
  include/stddef.h
  include/stdint.h
  include/sysexits.h
  include/syslog.h
  include/syslog.h
  include/time.h
  include/ucontext.h
  include/utime.h
  include/utmp.h
  include/utmpx.h
  include/wchar.h
  )

set(libc_SOURCES
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
  stub/sys/utsname.cpp
  stub/sys/vfs.cpp
  stub/sys/wait.cpp
  stub/sys/xattr.cpp
  stub/abort.cpp
  stub/access.cpp
  stub/ctype.cpp
  stub/environ.cpp
  stub/exit.cpp
  stub/fcntl.cpp
  stub/fnmatch.cpp
  stub/getenv.cpp
  stub/getmntent.cpp
  stub/grp.cpp
  stub/libgen.cpp
  stub/pipe.cpp
  stub/poll.cpp
  stub/progname.cpp
  stub/putc.cpp
  stub/pwd.cpp
  stub/qsort.cpp
  stub/read.cpp
  stub/search.cpp
  stub/setjmp.cpp
  stub/stdlib.cpp
  stub/strtol.cpp
  stub/syscall.cpp
  stub/syslog.cpp
  stub/time.cpp
  stub/unistd.cpp
  stub/utime.cpp
  stub/utmpx.cpp
  stub/wchar.cpp
  syscalls/brk.cpp
  syscalls/chdir.cpp
  syscalls/close.cpp
  syscalls/creat.cpp
  syscalls/dup2.cpp
  syscalls/execve.cpp
  syscalls/getcwd.cpp
  syscalls/getegid.cpp
  syscalls/geteuid.cpp
  syscalls/getgid.cpp
  syscalls/gettid.cpp
  syscalls/gettimeofday.cpp
  syscalls/getuid.cpp
  syscalls/ioctl.cpp
  syscalls/lseek.cpp
  syscalls/mknod.cpp
  syscalls/open.cpp
  syscalls/read.cpp
  syscalls/readv.cpp
  syscalls/waitpid.cpp
  syscalls/write.cpp
  syscalls/writev.cpp
  src/isatty.cpp
  src/sbrk.cpp
  src/ttyname.cpp

  $<TARGET_OBJECTS:wabase>
  $<TARGET_OBJECTS:wauser>
  )

set(libc_DATAFILES
  include/gnu-versions.h.in
  include/stdlib.h.in
  include/unistd.h.in
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

foreach (_lib ${LIBC_DEPENDENCIES})
  list(APPEND libc_INCLUDES $<TARGET_PROPERTY:${_lib},INTERFACE_INCLUDE_DIRECTORIES>)
  list(APPEND libc_SOURCES $<TARGET_OBJECTS:${_lib}>)
endforeach ()

set(GNU_VERSIONS_INCLUDE_LIST "")
set(STDLIB_INCLUDE_LIST "")
set(UNISTD_INCLUDE_LIST "")

foreach (_iter GNU_VERSIONS_INCLUDE STDLIB_INCLUDE UNISTD_INCLUDE)
  set(${_iter}_LIST "")
  foreach (_lib ${LIBC_DEPENDENCIES})
    get_target_property(_versions_include ${_lib} ${_iter})
    if (_versions_include)
      list(APPEND ${_iter}_LIST "${_versions_include}")
    endif ()
  endforeach ()
  string(REPLACE ";" "\n" ${_iter}_LIST "${${_iter}_LIST}")
endforeach ()

configure_file("include/gnu-versions.h.in" "${CMAKE_CURRENT_BINARY_DIR}/include/gnu-versions.h" @ONLY)
configure_file("include/stdlib.h.in" "${CMAKE_CURRENT_BINARY_DIR}/include/stdlib.h" @ONLY)
configure_file("include/unistd.h.in" "${CMAKE_CURRENT_BINARY_DIR}/include/unistd.h" @ONLY)

configure_file("features/${CONFIG_LIBC_FEATURES}-features.h" "${CMAKE_CURRENT_BINARY_DIR}/include/features.h" COPYONLY)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${libc_HEADERS} ${libc_SOURCES} ${libc_DATAFILES})
add_library(libc STATIC ${libc_HEADERS} ${libc_SOURCES} ${libc_DATAFILES})
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
  install(FILES "${CMAKE_CURRENT_BINARY_DIR}/include/stdlib.h" DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
  install(FILES "${CMAKE_CURRENT_BINARY_DIR}/include/unistd.h" DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
