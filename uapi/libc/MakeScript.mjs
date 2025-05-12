export default (mk) => {
  const headers = [
    "include/arpa/inet.h",
    "include/bits/syscalls.h",
    "include/bits/thread_data.h",
    "include/bits/waitstatus.h",
    "include/net/if.h",
    "include/netinet/in.h",
    "include/netinet/tcp.h",
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
    "include/alloca.h",
    "include/ar.h",
    "include/assert.h",
    "include/byteswap.h",
    "include/endian.h",
    "include/err.h",
    "include/errno.h",
    "include/float.h",
    "include/inttypes.h",
    "include/limits.h",
    "include/memory.h",
    "include/paths.h",
    "include/poll.h",
    "include/sched.h",
    "include/search.h",
    "include/setjmp.h",
    "include/spawn.h",
    "include/stdarg.h",
    "include/stddef.h",
    "include/stdint.h",
    "include/sysexits.h",
    "include/syslog.h",
    "include/time.h",
    "include/ucontext.h",
    "include/utime.h",
    "include/wchar.h",
  ];

  const sources = [
    "stub/apra/inet.cpp",
    "stub/net/if_indextoname.cpp",
    "stub/net/if_nametoindex.cpp",
    "stub/sys/epoll.cpp",
    "stub/sys/eventfd.cpp",
    "stub/sys/inotify.cpp",
    "stub/sys/mman.cpp",
    "stub/sys/prctl.cpp",
    "stub/sys/random.cpp",
    "stub/sys/resource.cpp",
    "stub/sys/select.cpp",
    "stub/sys/sendfile.cpp",
    "stub/sys/socket.cpp",
    "stub/sys/stat.cpp",
    "stub/sys/statfs.cpp",
    "stub/sys/statvfs.cpp",
    "stub/sys/sysinfo.cpp",
    "stub/sys/time.cpp",
    "stub/sys/timerfd.cpp",
    "stub/sys/wait.cpp",
    "stub/sys/xattr.cpp",
    "stub/access.cpp",
    "stub/assert.cpp",
    "stub/atexit.cpp",
    "stub/environ.cpp",
    "stub/err.cpp",
    "stub/getenv.cpp",
    "stub/pipe.cpp",
    "stub/poll.cpp",
    "stub/progname.cpp",
    "stub/qsort.cpp",
    "stub/read.cpp",
    "stub/sched_getaffinity.cpp",
    "stub/sched_setscheduler.cpp",
    "stub/sched_yield.cpp",
    "stub/search.cpp",
    "stub/setjmp.cpp",
    "stub/stdlib.cpp",
    "stub/strtol.cpp",
    "stub/syscall.cpp",
    "stub/syslog.cpp",
    "stub/time.cpp",
    "stub/ucontext.cpp",
    "stub/unistd.cpp",
    "stub/utime.cpp",
    "stub/wchar.cpp",
    "syscalls/_exit.cpp",
    "syscalls/brk.cpp",
    "syscalls/chdir.cpp",
    "syscalls/close.cpp",
    "syscalls/dup2.cpp",
    "syscalls/execve.cpp",
    "syscalls/fdatasync.cpp",
    "syscalls/fstatat.cpp",
    "syscalls/getcwd.cpp",
    "syscalls/getegid.cpp",
    "syscalls/geteuid.cpp",
    "syscalls/getgid.cpp",
    "syscalls/getpid.cpp",
    "syscalls/getppid.cpp",
    "syscalls/gettid.cpp",
    "syscalls/gettimeofday.cpp",
    "syscalls/getuid.cpp",
    "syscalls/ioctl.cpp",
    "syscalls/klogctl.cpp",
    "syscalls/lseek.cpp",
    "syscalls/mknod.cpp",
    "syscalls/mount.cpp",
    "syscalls/read.cpp",
    "syscalls/readv.cpp",
    "syscalls/reboot.cpp",
    "syscalls/sched_get_priority_max.cpp",
    "syscalls/sched_get_priority_min.cpp",
    "syscalls/sethostname.cpp",
    "syscalls/statx.cpp",
    "syscalls/sync.cpp",
    "syscalls/umount.cpp",
    "syscalls/umount2.cpp",
    "syscalls/uname.cpp",
    "syscalls/vhangup.cpp",
    "syscalls/waitpid.cpp",
    "syscalls/write.cpp",
    "syscalls/writev.cpp",
    "src/sys/futimens.cpp",
    "src/sys/stat.cpp",
    "src/sys/unistd/getpgrp.cpp",
    "src/abort.cpp",
    "src/exit.cpp",
    "src/gethostname.cpp",
    "src/posix_openpt.cpp",
    "src/sbrk.cpp",
    "src/thread_data.cpp",
    "src/usleep.cpp",
    mk.target("wabase").objects,
  ];

  const includes = [
    mk.BINARY_DIR.join("include"),
    mk.SOURCE_DIR.join("internal"),
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wabase"),
  ];

  const arch_syscall_h = mk.BINARY_DIR.join("include/bits/arch-syscall.h");
  mk.addCustomScript("include/bits/arch-syscall.h.mjs", {
    SCRIPT_NAME: "<bits/arch-syscall.h>",
    SCRIPT_INPUT: mk.PROJECT_SOURCE_DIR.join("data/syscall.js"),
    SCRIPT_OUTPUT: arch_syscall_h,
  });

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

  const features_h = mk.BINARY_DIR.join("include/features.h");
  mk.addCustomScript("configure_file", {
    SCRIPT_NAME: "<features.h>",
    SCRIPT_INPUT: mk.SOURCE_DIR.join(`features/${mk.WASMUX_LIBC_FEATURES}-features.h`),
    SCRIPT_OUTPUT: features_h,
  });

  const libc = mk.addStaticLibrary("libc", headers, sources);
  libc.addSources(arch_syscall_h, syscall_h, ctype_h, gnu_versions_h, stdlib_h, unistd_h, features_h);
  libc.addPublicIncludes(includes);
  libc.addPublicLibraries(libraries);
  libc.setPrefix("");

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
  mk.install([ arch_syscall_h, syscall_h, ctype_h, gnu_versions_h, stdlib_h, unistd_h, features_h ], {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: mk.BINARY_DIR.join("include"),
  });
  mk.install(libc, mk.INSTALL_LIBDIR);
}
