/*
 *
 *  Copyright (C) 2025-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

export default (mk) => {
  const headers = [
    "include/arpa/inet.h",
    "include/bits/thread_data.h",
    "include/bits/waitstatus.h",
    "include/net/ethernet.h",
    "include/net/route.h",
    "include/net/if.h",
    "include/netinet/in.h",
    "include/netinet/ip.h",
    "include/netinet/tcp.h",
    "include/netpacket/packet.h",
    "include/sys/epoll.h",
    "include/sys/eventfd.h",
    "include/sys/file.h",
    "include/sys/inotify.h",
    "include/sys/ioctl.h",
    "include/sys/ipc.h",
    "include/sys/klog.h",
    "include/sys/mman.h",
    "include/sys/mount.h",
    "include/sys/param.h",
    "include/sys/poll.h",
    "include/sys/prctl.h",
    "include/sys/random.h",
    "include/sys/reboot.h",
    "include/sys/resource.h",
    "include/sys/select.h",
    "include/sys/sendfile.h",
    "include/sys/socket.h",
    "include/sys/stat.h",
    "include/sys/statfs.h",
    "include/sys/statvfs.h",
    "include/sys/sysinfo.h",
    "include/sys/syslog.h",
    "include/sys/sysmacros.h",
    "include/sys/time.h",
    "include/sys/timerfd.h",
    "include/sys/times.h",
    "include/sys/ttydefaults.h",
    "include/sys/types.h",
    "include/sys/uio.h",
    "include/sys/un.h",
    "include/sys/utsname.h",
    "include/sys/vfs.h",
    "include/sys/wait.h",
    "include/sys/xattr.h",
    "include/ar.h",
    "include/assert.h",
    "include/byteswap.h",
    "include/endian.h",
    "include/err.h",
    "include/errno.h",
    "include/float.h",
    "include/ifaddrs.h",
    "include/inttypes.h",
    "include/limits.h",
    "include/memory.h",
    "include/paths.h",
    "include/poll.h",
    "include/sched.h",
    "include/setjmp.h",
    "include/spawn.h",
    "include/stdarg.h",
    "include/stddef.h",
    "include/stdint.h",
    "include/syscall.h",
    "include/sysexits.h",
    "include/syslog.h",
    "include/ucontext.h",
    "include/utime.h",
  ];

  const sources = [
    "stub/apra/inet.c",
    "stub/net/if_indextoname.c",
    "stub/net/if_nametoindex.c",
    "stub/sys/epoll.c",
    "stub/sys/eventfd.c",
    "stub/sys/inotify.c",
    "stub/sys/mman.c",
    "stub/sys/prctl.c",
    "stub/sys/random.c",
    "stub/sys/resource.c",
    "stub/sys/select.c",
    "stub/sys/sendfile.c",
    "stub/sys/socket.c",
    "stub/sys/stat.c",
    "stub/sys/statfs.c",
    "stub/sys/statvfs.c",
    "stub/sys/sysinfo.c",
    "stub/sys/time.c",
    "stub/sys/timerfd.c",
    "stub/sys/wait.c",
    "stub/sys/xattr.c",
    "stub/access.c",
    "stub/assert.c",
    "stub/atexit.c",
    "stub/err.c",
    "stub/getifaddrs.c",
    "stub/pipe.c",
    "stub/poll.c",
    "stub/progname.c",
    "stub/qsort.c",
    "stub/read.c",
    "stub/sched_getaffinity.c",
    "stub/sched_getcpu.c",
    "stub/sched_setscheduler.c",
    "stub/sched_yield.c",
    "stub/setjmp.c",
    "stub/stack_chk_fail.c",
    "stub/stdlib.c",
    "stub/strtol.c",
    "stub/syslog.c",
    "stub/time.c",
    "stub/ucontext.c",
    "stub/unistd.c",
    "stub/utime.c",
    "syscalls/_exit.c",
    "syscalls/brk.c",
    "syscalls/chdir.c",
    "syscalls/close.c",
    "syscalls/dup2.c",
    "syscalls/execve.c",
    "syscalls/fdatasync.c",
    "syscalls/fstatat.c",
    "syscalls/getcwd.c",
    "syscalls/getegid.c",
    "syscalls/geteuid.c",
    "syscalls/getgid.c",
    "syscalls/getpid.c",
    "syscalls/getppid.c",
    "syscalls/gettid.c",
    "syscalls/gettimeofday.c",
    "syscalls/getuid.c",
    "syscalls/ioctl.c",
    "syscalls/klogctl.c",
    "syscalls/lseek.c",
    "syscalls/mknod.c",
    "syscalls/mount.c",
    "syscalls/read.c",
    "syscalls/readv.c",
    "syscalls/reboot.c",
    "syscalls/sched_get_priority_max.c",
    "syscalls/sched_get_priority_min.c",
    "syscalls/sethostname.c",
    "syscalls/statx.c",
    "syscalls/sync.c",
    "syscalls/syscall.c",
    "syscalls/umount.c",
    "syscalls/umount2.c",
    "syscalls/uname.c",
    "syscalls/vhangup.c",
    "syscalls/waitpid.c",
    "syscalls/write.c",
    "syscalls/writev.c",
    "src/netinet/in6addr_any.c",
    "src/netinet/in6addr_loopback.c",
    "src/sys/futimens.c",
    "src/sys/stat.c",
    "src/sys/unistd/getpgrp.c",
    "src/abort.c",
    "src/exit.c",
    "src/gethostname.c",
    "src/posix_openpt.c",
    "src/sbrk.c",
    "src/thread_data.c",
    "src/usleep.c",
  ];

  const includes = [
    mk.BINARY_DIR.join("include"),
    mk.SOURCE_DIR.join("include"),
  ];

  const syscall_h = mk.BINARY_DIR.join("include/sys/syscall.h");
  mk.addCustomScript("src/sys/syscall.h.js", {
    SCRIPT_NAME: "<sys/syscall.h>",
    SCRIPT_INPUT: mk.PROJECT_SOURCE_DIR.join("data/syscall.js"),
    SCRIPT_OUTPUT: syscall_h,
  });

  const ctype_h = mk.BINARY_DIR.join("include/ctype.h");
  mk.addCustomScript("configure_file", {
    SCRIPT_NAME: "<ctype.h>",
    SCRIPT_INPUT: mk.SOURCE_DIR.join("include/ctype.h.in"),
    SCRIPT_OUTPUT: ctype_h,
    SCRIPT_INCLUDES: [],
  });

  const wctype_h = mk.BINARY_DIR.join("include/wctype.h");
  mk.addCustomScript("configure_file", {
    SCRIPT_NAME: "<wctype.h>",
    SCRIPT_INPUT: mk.SOURCE_DIR.join("include/wctype.h.in"),
    SCRIPT_OUTPUT: wctype_h,
    SCRIPT_INCLUDES: [],
  });

  const gnu_versions_h = mk.BINARY_DIR.join("include/gnu-versions.h");
  mk.addCustomScript("configure_file", {
    SCRIPT_NAME: "<gnu-versions.h>",
    SCRIPT_INPUT: mk.SOURCE_DIR.join("include/gnu-versions.h.in"),
    SCRIPT_OUTPUT: gnu_versions_h,
    SCRIPT_DEFINES: [],
  });

  const stdlib_h = mk.BINARY_DIR.join("include/stdlib.h");
  mk.addCustomScript("configure_file", {
    SCRIPT_NAME: "<stdlib.h>",
    SCRIPT_INPUT: mk.SOURCE_DIR.join("include/stdlib.h.in"),
    SCRIPT_OUTPUT: stdlib_h,
    SCRIPT_INCLUDES: [],
  });

  const unistd_h = mk.BINARY_DIR.join("include/unistd.h");
  mk.addCustomScript("configure_file", {
    SCRIPT_NAME: "<unistd.h>",
    SCRIPT_INPUT: mk.SOURCE_DIR.join("include/unistd.h.in"),
    SCRIPT_OUTPUT: unistd_h,
    SCRIPT_INCLUDES: [],
  });

  const time_h = mk.BINARY_DIR.join("include/time.h");
  mk.addCustomScript("configure_file", {
    SCRIPT_NAME: "<time.h>",
    SCRIPT_INPUT: mk.SOURCE_DIR.join("include/time.h.in"),
    SCRIPT_OUTPUT: time_h,
    SCRIPT_INCLUDES: [],
  });

  const wchar_h = mk.BINARY_DIR.join("include/wchar.h");
  mk.addCustomScript("configure_file", {
    SCRIPT_NAME: "<wchar.h>",
    SCRIPT_INPUT: mk.SOURCE_DIR.join("include/wchar.h.in"),
    SCRIPT_OUTPUT: wchar_h,
    SCRIPT_INCLUDES: [],
  });

  const features_h = mk.BINARY_DIR.join("include/features.h");
  mk.addCustomScript("configure_file", {
    SCRIPT_NAME: "<features.h>",
    SCRIPT_INPUT: mk.SOURCE_DIR.join(`features/${mk.WASMUX_LIBC_FEATURES}-features.h`),
    SCRIPT_OUTPUT: features_h,
  });

  if (mk.WASMUX_LIBC_FEATURES === "glibc") {
    headers.push("include/gnu/libc-version.h");
    sources.push("src/gnu/libc-version.c");
  }

  mk.script("<wasmux/thread_data.h>").mergeVariables({
    SCRIPT_ENTITIES: [ "int errcode;", "char buffer[256];" ],
  });

  const libc = mk.addStaticLibrary("libc", headers, sources);
  libc.addSources(syscall_h, ctype_h, wctype_h, gnu_versions_h, stdlib_h, unistd_h, time_h, wchar_h, features_h);
  libc.addSources(mk.target("wasmux").objects);
  libc.addPublicLibraries(mk.target("wasmux"));
  libc.addPublicIncludes(includes);
  libc.setPrefix("");

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
  mk.install([ syscall_h, ctype_h, wctype_h, gnu_versions_h, stdlib_h, unistd_h, time_h, wchar_h, features_h ], {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: mk.BINARY_DIR.join("include"),
  });
  mk.install(libc, mk.INSTALL_LIBDIR);
}
