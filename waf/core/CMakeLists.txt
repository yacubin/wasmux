set(wacore_HEADERS
  include/wasmux/cxx/HostHeap.h
  include/wasmux/cxx/ObjectCast.h
  include/wasmux/cxx/WasmHeap.h
  include/wasmux/web/arraybuffer.h
  include/wasmux/web/console.h
  include/wasmux/web/getcurrenttimer.h
  include/wasmux/web/getrandombytes.h
  include/wasmux/web/object.h
  include/wasmux/web/string.h
  include/wasmux/web/terminal.h
  include/wasmux/web/webassembly.h
  include/wasmux/web/worker.h
  include/wasmux/web/xmlhttprequest.h
  include/wasmux/alert.h
  include/wasmux/file_system.h
  include/wasmux/init.h
  include/wasmux/main_loop.h
  include/wasmux/main_thread.h
  include/wasmux/memory_alloc.h
  include/wasmux/user_access.h
  include/wasmux/wasm_page.h
  include/wasmux/wei.h
  include/wasmux/worker_instance.h
  include/wasmux/worker_thread.h
  )

set(wacore_SOURCES
  src/cxx/HostHeap.cpp
  src/web/arraybuffer.cpp
  src/web/console.cpp
  src/web/getcurrenttimer.cpp
  src/web/getrandombytes.cpp
  src/web/object.cpp
  src/web/string.cpp
  src/web/terminal.cpp
  src/web/webassembly.cpp
  src/web/worker.cpp
  src/web/xmlhttprequest.cpp
  src/alert.cpp
  src/file_system.cpp
  src/main_loop.cpp
  src/main_thread.cpp
  src/memory_alloc.cpp
  src/start_worker.cpp
  src/user_access.cpp
  src/wei.cpp
  src/worker_instance.cpp
  src/worker_instanceInit.S
  src/worker_thread.cpp
  )

set(wacore_INCLUDES
  "${CMAKE_CURRENT_BINARY_DIR}/include"
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

set(wacore_LIBRARIES
  wabase
  )

set(wacore_GENFILES
  "${CMAKE_CURRENT_BINARY_DIR}/include/uapi/asm/unistd.h"
  "${CMAKE_CURRENT_BINARY_DIR}/include/utsversion.h"
  "${CMAKE_CURRENT_BINARY_DIR}/include/wasmux/webcall-nums.h"
  "${CMAKE_CURRENT_BINARY_DIR}/include/wasmux/webcall-main.h"
  "${CMAKE_CURRENT_BINARY_DIR}/include/wasmux/webcall-worker.h"
  )

if (WIN32)
  list(APPEND wacore_HEADERS
    src/windows/BaseThreadContext.h
    src/windows/Looper.h
    src/windows/MainThreadContext.h
    src/windows/NJSObject.h
    src/windows/NJSObjectList.h
    src/windows/NJSString.h
    src/windows/OSMalloc.h
    src/windows/WorkerThreadContext.h
    )
  list(APPEND wacore_SOURCES
    src/windows/BaseThreadContext.cpp
    src/windows/Looper.cpp
    src/windows/MainThreadContext.cpp
    src/windows/NJSObject.cpp
    src/windows/NJSObjectList.cpp
    src/windows/NJSString.cpp
    src/windows/OSMalloc.cpp
    src/windows/OSAddEventListener.cpp
    src/windows/OSCallMethod.cpp
    src/windows/OSConsoleWrite.cpp
    src/windows/OSGetMathRandom.cpp
    src/windows/OSGetPerformanceNow.cpp
    src/windows/OSGetProperty.cpp
    src/windows/OSMemory.cpp
    src/windows/OSObjectCreate.cpp
    src/windows/OSNotImplemented.cpp
    src/windows/OSNumberCreate.cpp
    src/windows/OSObjectRelease.cpp
    src/windows/OSObjectRetain.cpp
    src/windows/OSPostMessage.cpp
    src/windows/OSPromiseThen.cpp
    src/windows/OSRemoveEventListener.cpp
    src/windows/OSSetProperty.cpp
    src/windows/OSStringCreate.cpp
    src/windows/OSStringCreateByArgs.cpp
    src/windows/OSTimeout.cpp
    src/windows/OSUserInstanceStart.cpp
    src/windows/OSWorkerInstance.cpp
    src/windows/OSWorkerPerform.cpp
    src/windows/WebCall.cpp
    src/windows/WorkerThreadContext.cpp
    )
endif ()

# TODO: Move to linux dep
GEN_KSYSCALLHDR(
  INPUT "${WASMUX_ROOT_DIR}/waf/syscall.js"
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/include/uapi/asm/unistd.h"
)

# TODO: Move to linux dep
GEN_KUTSVERSION(
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/include/utsversion.h"
)

GEN_KWEBCALLHDR(
  INPUT "${WASMUX_ROOT_DIR}/waf/webcalls.js"
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/include/wasmux/webcall-nums.h"
)

GEN_KWEBCALLTBL(
  SIDE main
  INPUT "${WASMUX_ROOT_DIR}/waf/webcalls.js"
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/include/wasmux/webcall-main.h"
)

GEN_KWEBCALLTBL(
  SIDE worker
  INPUT "${WASMUX_ROOT_DIR}/waf/webcalls.js"
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/include/wasmux/webcall-worker.h"
)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${wacore_HEADERS} ${wacore_SOURCES})
add_library(wacore STATIC ${wacore_HEADERS} ${wacore_SOURCES} ${wacore_GENFILES})
target_include_directories(wacore PUBLIC ${wacore_INCLUDES})
target_link_libraries(wacore PUBLIC ${wacore_LIBRARIES})
set_target_properties(wacore PROPERTIES LINKER_LANGUAGE CXX)
