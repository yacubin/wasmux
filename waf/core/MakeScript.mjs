export default (mk) => {
  const headers = [
    "include/wasmux/cxx/HostHeap.h",
    "include/wasmux/cxx/ObjectCast.h",
    "include/wasmux/cxx/WasmHeap.h",
    "include/wasmux/web/arraybuffer.h",
    "include/wasmux/web/console.h",
    "include/wasmux/web/getcurrenttimer.h",
    "include/wasmux/web/getrandombytes.h",
    "include/wasmux/web/object.h",
    "include/wasmux/web/string.h",
    "include/wasmux/web/terminal.h",
    "include/wasmux/web/webassembly.h",
    "include/wasmux/web/worker.h",
    "include/wasmux/web/xmlhttprequest.h",
    "include/wasmux/alert.h",
    "include/wasmux/file_system.h",
    "include/wasmux/init.h",
    "include/wasmux/main_loop.h",
    "include/wasmux/main_thread.h",
    "include/wasmux/memory_alloc.h",
    "include/wasmux/syscalls.h",
    "include/wasmux/user_access.h",
    "include/wasmux/wasm_page.h",
    "include/wasmux/wei.h",
    "include/wasmux/worker_instance.h",
    "include/wasmux/worker_thread.h",
  ];

  const sources = [
    "src/cxx/HostHeap.cpp",
    "src/web/arraybuffer.cpp",
    "src/web/console.cpp",
    "src/web/getcurrenttimer.cpp",
    "src/web/getrandombytes.cpp",
    "src/web/object.cpp",
    "src/web/string.cpp",
    "src/web/terminal.cpp",
    "src/web/webassembly.cpp",
    "src/web/worker.cpp",
    "src/web/xmlhttprequest.cpp",
    "src/alert.cpp",
    "src/file_system.cpp",
    "src/main_loop.cpp",
    "src/main_thread.cpp",
    "src/memory_alloc.cpp",
    "src/start_worker.cpp",
    "src/user_access.cpp",
    "src/wei.cpp",
    "src/worker_instance.cpp",
    "src/worker_instanceInit.S",
    "src/worker_thread.cpp",
  ];

  const includes = [
    mk.BINARY_DIR.join("include"),
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wabase"),
  ];

  if (mk.SYSTEM_NAME === "Windows") {
    headers.push(
      "include/wasmux/win32/BaseThreadContext.h",
      "include/wasmux/win32/Looper.h",
      "include/wasmux/win32/MainThreadContext.h",
      "include/wasmux/win32/NJSObject.h",
      "include/wasmux/win32/NJSObjectList.h",
      "include/wasmux/win32/NJSString.h",
      "include/wasmux/win32/OSMalloc.h",
      "include/wasmux/win32/WorkerThreadContext.h",
    );
    sources.push(
      "src/win32/BaseThreadContext.cpp",
      "src/win32/Looper.cpp",
      "src/win32/MainThreadContext.cpp",
      "src/win32/NJSObject.cpp",
      "src/win32/NJSObjectList.cpp",
      "src/win32/NJSString.cpp",
      "src/win32/OSMalloc.cpp",
      "src/win32/OSAddEventListener.cpp",
      "src/win32/OSCallMethod.cpp",
      "src/win32/OSConsoleWrite.cpp",
      "src/win32/OSGetMathRandom.cpp",
      "src/win32/OSGetPerformanceNow.cpp",
      "src/win32/OSGetProperty.cpp",
      "src/win32/OSMemory.cpp",
      "src/win32/OSObjectCreate.cpp",
      "src/win32/OSNotImplemented.cpp",
      "src/win32/OSNumberCreate.cpp",
      "src/win32/OSObjectRelease.cpp",
      "src/win32/OSObjectRetain.cpp",
      "src/win32/OSPostMessage.cpp",
      "src/win32/OSPromiseThen.cpp",
      "src/win32/OSRemoveEventListener.cpp",
      "src/win32/OSSetProperty.cpp",
      "src/win32/OSStringCreate.cpp",
      "src/win32/OSStringCreateByArgs.cpp",
      "src/win32/OSTimeout.cpp",
      "src/win32/OSUserInstanceStart.cpp",
      "src/win32/OSWorkerInstance.cpp",
      "src/win32/OSWorkerPerform.cpp",
      "src/win32/WebCall.cpp",
      "src/win32/WorkerThreadContext.cpp",
    );
  }

  const webcall_nums_h = mk.BINARY_DIR.join("include/wasmux/webcall-nums.h");
  mk.addCustomScript("src/webcall-nums.h.js", {
    SCRIPT_NAME: "<wasmux/webcall-nums.h>",
    SCRIPT_INPUT:  mk.PROJECT_SOURCE_DIR.join("data/webcalls.js"),
    SCRIPT_OUTPUT: webcall_nums_h,
  });

  const webcall_main_h = mk.BINARY_DIR.join("include/wasmux/webcall-main.h");
  mk.addCustomScript("src/webcall-main.h.js", {
    SCRIPT_NAME: "<wasmux/webcall-main.h>",
    SCRIPT_INPUT: mk.PROJECT_SOURCE_DIR.join("data/webcalls.js"),
    SCRIPT_OUTPUT: webcall_main_h,
  });

  const webcall_worker_h = mk.BINARY_DIR.join("include/wasmux/webcall-worker.h");
  mk.addCustomScript("src/webcall-worker.h.js", {
    SCRIPT_NAME: "<wasmux/webcall-worker.h>",
    SCRIPT_INPUT: mk.PROJECT_SOURCE_DIR.join("data/webcalls.js"),
    SCRIPT_OUTPUT: webcall_worker_h,
  });

  const syscall_nums_h = mk.BINARY_DIR.join("include/wasmux/syscall-nums.h");
  mk.addCustomScript("src/syscall-nums.h.mjs", {
    SCRIPT_NAME: "<wasmux/syscall-nums.h>",
    SCRIPT_INPUT: mk.PROJECT_SOURCE_DIR.join("data/syscall.js"),
    SCRIPT_OUTPUT: syscall_nums_h,
  });

  const syscall_list_h = mk.BINARY_DIR.join("include/wasmux/syscall-list.h");
  mk.addCustomScript("src/syscall-list.h.mjs", {
    SCRIPT_NAME: "<wasmux/syscall-list.h>",
    SCRIPT_INPUT: mk.PROJECT_SOURCE_DIR.join("data/syscall.js"),
    SCRIPT_OUTPUT: syscall_list_h,
  });

  const target = mk.addStaticLibrary("wacore", sources, headers);
  target.addSources(webcall_nums_h, webcall_main_h, webcall_worker_h, syscall_nums_h, syscall_list_h);
  target.addPublicIncludes(includes);
  target.addPublicLibraries(libraries);
}
