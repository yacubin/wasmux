find_program(NODE_EXECUTABLE node REQUIRED)

if (NOT WASMUX_ARCH_DIR)
  set(WASMUX_ARCH_DIR "${CMAKE_CURRENT_SOURCE_DIR}/arch/${WASMUX_ARCH}")
endif ()

add_subdirectory("${WASMUX_ARCH_DIR}" wasmux_arch)

add_custom_command(
  COMMENT "Generating errors header, errno.json, errno.h"
  DEPENDS emit include/wasmux/errno.h.mjs
  COMMAND "$<TARGET_FILE:emit>" errno-json > "${CMAKE_CURRENT_BINARY_DIR}/errno.json"
  COMMAND "${NODE_EXECUTABLE}" include/wasmux/errno.h.mjs "${CMAKE_CURRENT_BINARY_DIR}/errno.json" include/wasmux/errno.h
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
  OUTPUT  include/wasmux/errno.h
  )
set_source_files_properties(include/wasmux/errno.h PROPERTIES GENERATED TRUE)

set(wasmux_HEADERS
  include/wasmux/arch-generic/log.h
  include/wasmux/arch-generic/string.h
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
  include/wasmux/wei/alert.h
  include/wasmux/wei/file_system.h
  include/wasmux/wei/main_loop.h
  include/wasmux/wei/main_thread.h
  include/wasmux/wei/memory_alloc.h
  include/wasmux/wei/user_access.h
  include/wasmux/wei/webcall-nums.h
  include/wasmux/wei/worker_instance.h
  include/wasmux/wei/worker_thread.h
  include/wasmux/align.h
  include/wasmux/assert.h
  include/wasmux/atomic.h
  include/wasmux/bits.h
  include/wasmux/bitset.h
  include/wasmux/bulk-memory.h
  include/wasmux/byteorder.h
  include/wasmux/compiler.h
  include/wasmux/cpu_set.h
  include/wasmux/errno.h
  )

set(wasmux_SOURCES
  main/InstanceExit.cpp
  main/InstancePerform.cpp
  main/manifest.c
  main/StartKernel.cpp
  main/StartKernel.S
  # main/StartWindows.cpp
  # main/syscall_stubs.c
  main/version.c
  src/fs/fcntl.cpp
  src/kernel/sys.c
  src/kernel/sys_ni.c
  # src/kernel/wamm.c
  src/net/net1.h
  src/net/net1.c
  # src/web/arraybuffer.cpp
  # src/web/console.cpp
  # src/web/getcurrenttimer.cpp
  # src/web/getrandombytes.cpp
  # src/web/object.cpp
  # src/web/string.cpp
  # src/web/terminal.cpp
  # src/web/webassembly.cpp
  # src/web/worker.cpp
  # src/web/xmlhttprequest.cpp
  # src/wei/alert.cpp
  # src/wei/file_system.cpp
  src/wei/host_alloc.h
  src/wei/host_alloc_linux.c
  # src/wei/host_alloc_win32.c
  src/wei/main_loop.cpp
  # src/wei/main_thread.cpp
  src/wei/memory_alloc.cpp
  src/wei/memory_heap.h
  src/wei/memory_heap.c
  src/wei/memory_manager.h
  src/wei/memory_manager.cpp
  # src/wei/wei.cpp
  # src/wei/worker_instance.cpp
  src/wei/worker_instanceInit.S
  # src/wei/worker_thread.cpp
  src/bulk-memory.c
  src/bulk-memory.S
  src/byteorder.c
  src/log.c
  src/mutex.S
  src/notify_waiter.c
  src/sleep_ms.c
  src/sprintf.c
  src/string.c
  src/TypesCheck.cpp
  src/wasm_module.cpp
  )

set(wasmux_DATAFILES
  include/wasmux/errno.h.mjs
  src/errno.h.js
  )

set(wasmux_INCLUDES
  "${WASMUX_ARCH_DIR}/include"
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  "${CMAKE_BINARY_DIR}"
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${wasmux_HEADERS} ${wasmux_SOURCES} ${wasmux_DATAFILES})
add_library(wasmux OBJECT ${wasmux_HEADERS} ${wasmux_SOURCES} ${wasmux_DATAFILES})
target_include_directories(wasmux PUBLIC ${wasmux_INCLUDES})
target_link_libraries(wasmux PUBLIC wasmux_arch)
set_target_properties(wasmux PROPERTIES LINKER_LANGUAGE CXX)
