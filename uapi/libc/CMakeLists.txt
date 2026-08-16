add_custom_command(
  COMMENT "Generating errors header libc/sys/syscall.h"
  DEPENDS include/sys/syscall.h.mjs
  COMMAND "${NODE_EXECUTABLE}" include/sys/syscall.h.mjs "${CMAKE_SOURCE_DIR}/data/syscall.js" include/sys/syscall.h
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
  OUTPUT  "${CMAKE_CURRENT_SOURCE_DIR}/include/sys/syscall.h"
  )
set_source_files_properties(
  "${CMAKE_CURRENT_SOURCE_DIR}/include/sys/syscall.h" PROPERTIES GENERATED TRUE
  )

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
  include/sys/syscall.h
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
  src/thread_data.c
  # src/usleep.c
  # stub/access.c
  stub/apra/inet.c
  # stub/assert.c
  # stub/atexit.c
  stub/err.c
  stub/getifaddrs.c
  stub/net/if_indextoname.c
  stub/net/if_nametoindex.c
  # stub/pipe.c
  stub/poll.c
  stub/progname.c
  # stub/qsort.c
  # stub/read.c
  stub/sched_getaffinity.c
  stub/sched_getcpu.c
  stub/sched_setscheduler.c
  stub/sched_yield.c
  # stub/setjmp.c
  # stub/stack_chk_fail.c
  # stub/stdlib.c
  # stub/strtol.c
  # stub/sys/epoll.c
  stub/sys/eventfd.c
  stub/sys/inotify.c
  stub/sys/mman.c
  stub/sys/prctl.c
  stub/sys/random.c
  # stub/sys/resource.c
  # stub/sys/select.c
  stub/sys/sendfile.c
  stub/sys/socket.c
  # stub/sys/stat.c
  stub/sys/statfs.c
  stub/sys/statvfs.c
  stub/sys/sysinfo.c
  stub/sys/time.c
  # stub/sys/timerfd.c
  # stub/sys/wait.c
  stub/sys/xattr.c
  stub/syslog.c
  # stub/time.c
  # stub/ucontext.c
  # stub/unistd.c
  # stub/utime.c
  # syscalls/brk.c
  syscalls/chdir.c
  syscalls/close.c
  # syscalls/dup2.c
  syscalls/execve.c
  # syscalls/fdatasync.c
  # syscalls/fstatat.c
  syscalls/getcwd.c
  # syscalls/getegid.c
  # syscalls/geteuid.c
  # syscalls/getgid.c
  # syscalls/getpid.c
  # syscalls/getppid.c
  # syscalls/gettid.c
  syscalls/gettimeofday.c
  # syscalls/getuid.c
  syscalls/ioctl.c
  syscalls/klogctl.c
  # syscalls/lseek.c
  # syscalls/mknod.c
  syscalls/mount.c
  syscalls/read.c
  syscalls/readv.c
  syscalls/reboot.c
  syscalls/sched_get_priority_max.c
  syscalls/sched_get_priority_min.c
  # syscalls/sethostname.c
  # syscalls/statx.c
  # syscalls/sync.c
  # syscalls/syscall.c
  syscalls/umount.c
  syscalls/umount2.c
  # syscalls/uname.c
  # syscalls/vhangup.c
  # syscalls/waitpid.c
  syscalls/write.c
  syscalls/writev.c
  # syscalls/_exit.c
  )

set(libc_DATAFILES
  include/sys/syscall.h.mjs
  include/ctype.h.in
  include/gnu-versions.h.in
  include/stdlib.h.in
  include/time.h.in
  include/unistd.h.in
  include/wchar.h.in
  include/wctype.h.in
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
