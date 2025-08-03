export default (mk) => {
  const headers = [
    "include/wasmux/cxx/Atomic.h",
    "include/wasmux/cxx/BitVector.h",
    "include/wasmux/cxx/Characters.h",
    "include/wasmux/cxx/Leb128.h",
    "include/wasmux/cxx/Math.h",
    "include/wasmux/cxx/MemoryManager.h",
    "include/wasmux/cxx/MemoryUtils.h",
    "include/wasmux/cxx/New.h",
    "include/wasmux/cxx/PrintTo.h",
    "include/wasmux/cxx/RefPtr.h",
    "include/wasmux/cxx/StaticStorage.h",
    "include/wasmux/cxx/TypeTraits.h",
    "include/wasmux/align.h",
    "include/wasmux/assert.h",
    "include/wasmux/bulk-memory.h",
    "include/wasmux/byteorder.h",
    "include/wasmux/compiler.h",
    "include/wasmux/cpu_set.h",
    "include/wasmux/eventfd.h",
    "include/wasmux/eventpoll.h",
    "include/wasmux/export.h",
    "include/wasmux/fcntl.h",
    "include/wasmux/fs.h",
    "include/wasmux/fsblkcnt.h",
    "include/wasmux/fsfilcnt.h",
    "include/wasmux/if.h",
    "include/wasmux/inotify.h",
    "include/wasmux/int-types.h",
    "include/wasmux/ioctl.h",
    "include/wasmux/ioctls.h",
    "include/wasmux/limits-base.h",
    "include/wasmux/limits.h",
    "include/wasmux/log.h",
    "include/wasmux/notify_waiter.h",
    "include/wasmux/mman.h",
    "include/wasmux/mount.h",
    "include/wasmux/mutex.h",
    "include/wasmux/nullptr.h",
    "include/wasmux/platform.h",
    "include/wasmux/posix_types.h",
    "include/wasmux/prctl.h",
    "include/wasmux/reboot.h",
    "include/wasmux/sched.h",
    "include/wasmux/section.h",
    "include/wasmux/signal.h",
    "include/wasmux/signalfd.h",
    "include/wasmux/sizeof.h",
    "include/wasmux/sleep_ms.h",
    "include/wasmux/socket.h",
    "include/wasmux/sockios.h",
    "include/wasmux/sprintf.h",
    "include/wasmux/stack_pointer.h",
    "include/wasmux/stat.h",
    "include/wasmux/statfs.h",
    "include/wasmux/statvfs.h",
    "include/wasmux/stdarg.h",
    "include/wasmux/swab.h",
    "include/wasmux/sys_ni.h",
    "include/wasmux/syscalls.h",
    "include/wasmux/sysinfo.h",
    "include/wasmux/termios.h",
    "include/wasmux/time.h",
    "include/wasmux/time64.h",
    "include/wasmux/timerfd.h",
    "include/wasmux/types.h",
    "include/wasmux/uio.h",
    "include/wasmux/wainst_names.h",
    "include/wasmux/wasm_header.h",
    "include/wasmux/wasm_module.h",
    "include/wasmux/wasm_page.h",
    "include/wasmux/wasm_symbols.h",
    "include/wasmux/widechar.h",
  ];

  const sources = [
    "src/fs/fcntl.cpp",
    "src/kernel/sys.cpp",
    "src/kernel/sys_ni.cpp",
    "src/kernel/wamm.cpp",
    "src/bulk-memory.cpp",
    "src/bulk-memory.S",
    "src/byteorder.cpp",
    "src/log.cpp",
    "src/mutex.S",
    "src/notify_waiter.cpp",
    "src/PrintTo.cpp",
    "src/sleep_ms.cpp",
    "src/sprintf.cpp",
    "src/TypesCheck.cpp",
    "src/wasm_module.cpp",
  ];

  const includes = [
    mk.BINARY_DIR.join("include"),
    mk.SOURCE_DIR.join("include"),
  ];

  if (mk.WASMUX_WEI) {
    headers.push("include/wasmux/wei.h");
    sources.push("src/wei/wei.cpp");

    const webcall_nums_h = mk.BINARY_DIR.join("include/wasmux/webcall-nums.h");
    mk.addCustomScript("src/wei/webcall-nums.h.js", {
      SCRIPT_NAME: "<wasmux/webcall-nums.h>",
      SCRIPT_INPUT:  mk.PROJECT_SOURCE_DIR.join("data/webcalls.js"),
      SCRIPT_OUTPUT: webcall_nums_h,
    });
    sources.push(webcall_nums_h);

    const webcall_main_h = mk.BINARY_DIR.join("include/wasmux/webcall-main.h");
    mk.addCustomScript("src/wei/webcall-main.h.js", {
      SCRIPT_NAME: "<wasmux/webcall-main.h>",
      SCRIPT_INPUT: mk.PROJECT_SOURCE_DIR.join("data/webcalls.js"),
      SCRIPT_OUTPUT: webcall_main_h,
    });
    sources.push(webcall_main_h);

    const webcall_worker_h = mk.BINARY_DIR.join("include/wasmux/webcall-worker.h");
    mk.addCustomScript("src/wei/webcall-worker.h.js", {
      SCRIPT_NAME: "<wasmux/webcall-worker.h>",
      SCRIPT_INPUT: mk.PROJECT_SOURCE_DIR.join("data/webcalls.js"),
      SCRIPT_OUTPUT: webcall_worker_h,
    });
    sources.push(webcall_worker_h);
  }

  const errno_h = mk.BINARY_DIR.join("include/wasmux/errno.h");
  mk.addCustomScript("src/errno.h.js", {
    SCRIPT_NAME: "<wasmux/errno.h>",
    SCRIPT_INPUT:  mk.PROJECT_SOURCE_DIR.join("data/errno.js"),
    SCRIPT_OUTPUT: errno_h,
  });

  const thread_data_h = mk.BINARY_DIR.join("include/wasmux/thread_data.h");
  mk.addCustomScript("configure_file", {
    SCRIPT_NAME: "<wasmux/thread_data.h>",
    SCRIPT_INPUT: mk.SOURCE_DIR.join("include/wasmux/thread_data.h.in"),
    SCRIPT_OUTPUT: thread_data_h,
    SCRIPT_ENTITIES: [],
  });

  const wasmux = mk.addStaticLibrary("wasmux", headers, sources, errno_h, thread_data_h);
  wasmux.addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
  mk.install([ errno_h, thread_data_h ], {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: mk.BINARY_DIR.join("include"),
  });

  mk.addSubdirectory(`arch/${mk.WASMUX_ARCH}`);
}
