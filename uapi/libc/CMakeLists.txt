set(libc_HEADERS
  include/ar.h
  include/arpa/inet.h
  include/assert.h
  include/bits/thread_data.h
  include/bits/waitstatus.h
  include/byteswap.h
  include/endian.h
  include/err.h
  include/errno.h
  include/float.h
  include/gnu/libc-version.h
  include/ifaddrs.h
  include/intprops.h
  include/inttypes.h
  include/limits.h
  include/memory.h
  include/net/ethernet.h
  include/net/if.h
  include/net/route.h
  include/netinet/in.h
  include/netinet/ip.h
  include/netinet/tcp.h
  include/netpacket/packet.h
  include/paths.h
  include/poll.h
  include/sched.h
  include/setjmp.h
  include/spawn.h
  include/stdarg.h
  include/stddef.h
  include/stdint.h
  include/sys/epoll.h
  include/sys/eventfd.h
  include/sys/file.h
  include/sys/inotify.h
  include/sys/ioctl.h
  include/sys/ipc.h
  include/sys/klog.h
  include/sys/mman.h
  include/sys/mount.h
  include/sys/param.h
  include/sys/poll.h
  include/sys/prctl.h
  include/sys/random.h
  include/sys/reboot.h
  include/sys/resource.h
  include/sys/select.h
  include/sys/sendfile.h
  include/sys/socket.h
  include/sys/stat.h
  include/sys/statfs.h
  include/sys/statvfs.h
  include/sys/sysinfo.h
  include/sys/syslog.h
  include/sys/sysmacros.h
  include/sys/time.h
  include/sys/timerfd.h
  include/sys/times.h
  include/sys/ttydefaults.h
  include/sys/types.h
  include/sys/uio.h
  include/sys/un.h
  include/sys/utsname.h
  include/sys/vfs.h
  include/sys/wait.h
  include/sys/xattr.h
  include/syscall.h
  include/sysexits.h
  include/syslog.h
  include/ucontext.h
  include/utime.h
  )

set(libc_SOURCES
  features/glibc-features.h
  features/none-features.h
  features/uclibc-features.h
  src/gnu/libc-version.c
  src/netinet/in6addr_any.c
  src/netinet/in6addr_loopback.c
  # src/sys/unistd/getpgrp.c
  # src/sys/futimens.c
  # src/sys/stat.c
  # src/abort.c
  # src/exit.c
  # src/gethostname.c
  # src/posix_openpt.c
  # src/sbrk.c
  # src/thread_data.c
  # src/usleep.c
  )

set(libc_DATAFILES
  include/ctype.h.in
  include/gnu-versions.h.in
  include/stdlib.h.in
  include/time.h.in
  include/unistd.h.in
  include/wchar.h.in
  include/wctype.h.in
  src/sys/syscall.h.js
  MakeScript.mjs
  )

set(libc_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  "${CMAKE_BINARY_DIR}"
  )

set(libc_OPTIONS
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${libc_HEADERS} ${libc_SOURCES} ${libc_DATAFILES})
add_library(libc STATIC ${libc_HEADERS} ${libc_SOURCES} ${libc_DATAFILES})
target_include_directories(libc PUBLIC ${libc_INCLUDES})
target_compile_options(libc PRIVATE -nostdinc)
target_link_libraries(libc PUBLIC wasmux)
# target_link_options(libc PRIVATE -nostdlib)
