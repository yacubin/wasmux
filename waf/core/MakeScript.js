"use strict";

module.exports = (mk) => {
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
      "src/windows/BaseThreadContext.h",
      "src/windows/Looper.h",
      "src/windows/MainThreadContext.h",
      "src/windows/NJSObject.h",
      "src/windows/NJSObjectList.h",
      "src/windows/NJSString.h",
      "src/windows/OSMalloc.h",
      "src/windows/WorkerThreadContext.h",
    );
    sources.push(
      "src/windows/BaseThreadContext.cpp",
      "src/windows/Looper.cpp",
      "src/windows/MainThreadContext.cpp",
      "src/windows/NJSObject.cpp",
      "src/windows/NJSObjectList.cpp",
      "src/windows/NJSString.cpp",
      "src/windows/OSMalloc.cpp",
      "src/windows/OSAddEventListener.cpp",
      "src/windows/OSCallMethod.cpp",
      "src/windows/OSConsoleWrite.cpp",
      "src/windows/OSGetMathRandom.cpp",
      "src/windows/OSGetPerformanceNow.cpp",
      "src/windows/OSGetProperty.cpp",
      "src/windows/OSMemory.cpp",
      "src/windows/OSObjectCreate.cpp",
      "src/windows/OSNotImplemented.cpp",
      "src/windows/OSNumberCreate.cpp",
      "src/windows/OSObjectRelease.cpp",
      "src/windows/OSObjectRetain.cpp",
      "src/windows/OSPostMessage.cpp",
      "src/windows/OSPromiseThen.cpp",
      "src/windows/OSRemoveEventListener.cpp",
      "src/windows/OSSetProperty.cpp",
      "src/windows/OSStringCreate.cpp",
      "src/windows/OSStringCreateByArgs.cpp",
      "src/windows/OSTimeout.cpp",
      "src/windows/OSUserInstanceStart.cpp",
      "src/windows/OSWorkerInstance.cpp",
      "src/windows/OSWorkerPerform.cpp",
      "src/windows/WebCall.cpp",
      "src/windows/WorkerThreadContext.cpp",
    );
  }

  const webcall_nums_h = mk.BINARY_DIR.join("include/wasmux/webcall-nums.h");
  mk.addCustomTarget("<wasmux/webcall-nums.h>", {
    script: "src/webcall-nums.h.js",
    input:  mk.PROJECT_SOURCE_DIR.join("data/webcalls.js"),
    output: webcall_nums_h,
  });

  const webcall_main_h = mk.BINARY_DIR.join("include/wasmux/webcall-main.h");
  mk.addCustomTarget("<wasmux/webcall-main.h>", {
    script: "src/webcall-main.h.js",
    input: mk.PROJECT_SOURCE_DIR.join("data/webcalls.js"),
    output: webcall_main_h,
  });

  const webcall_worker_h = mk.BINARY_DIR.join("include/wasmux/webcall-worker.h");
  mk.addCustomTarget("<wasmux/webcall-worker.h>", {
    script: "src/webcall-worker.h.js",
    input: mk.PROJECT_SOURCE_DIR.join("data/webcalls.js"),
    output: webcall_worker_h,
  });

  const target = mk.addStaticLibrary("wacore", sources, headers);
  target.addSources(webcall_nums_h, webcall_main_h, webcall_worker_h);
  target.addPublicIncludes(includes);
  target.addPublicLibraries(libraries);
}
