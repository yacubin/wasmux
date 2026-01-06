export default (mk) => {
  const headers = [
    "include/wasmux/arch/log.h",
    "include/wasmux/arch/string.h",
    "include/wasmux/arch/syscalls.h",
    "include/wasmux/arch/unistd.h",
  ];

  const sources = [
    "src/start_worker.cpp",
  ];

  const includes = [
    mk.BINARY_DIR.join("include"),
    mk.SOURCE_DIR.join("include"),
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
      "include/wasmux/win32/RefPtr.h",
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

  mk.target("wasmux").addSources(sources, headers);
  mk.target("wasmux").addPublicIncludes(includes);
}
