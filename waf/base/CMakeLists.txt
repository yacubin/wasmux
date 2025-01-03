set(wabase_HEADERS
  include/kernel/align.h
  include/kernel/assert.h
  include/kernel/basename.h
  include/kernel/bulk-memory.h
  include/kernel/byteorder.h
  include/kernel/compiler.h
  include/kernel/errno.h
  include/kernel/int-types.h
  include/kernel/ioctls.h
  include/kernel/limits-base.h
  include/kernel/limits.h
  include/kernel/log.h
  include/kernel/notify_waiter.h
  include/kernel/mutex.h
  include/kernel/nullptr.h
  include/kernel/platform.h
  include/kernel/posix_types.h
  include/kernel/sched.h
  include/kernel/signal.h
  include/kernel/sizeof.h
  include/kernel/sleep_ms.h
  include/kernel/socket.h
  include/kernel/sprintf.h
  include/kernel/stack_pointer.h
  include/kernel/stdarg.h
  include/kernel/time.h
  include/kernel/types.h
  include/kernel/wasm_header.h
  include/kernel/wasm_module.h
  include/kernel/wasm_symbols.h
  include/kernel/widechar.h
  include/waf/Atomic.h
  include/waf/BitVector.h
  include/waf/Characters.h
  include/waf/Leb128.h
  include/waf/Math.h
  include/waf/MemoryManager.h
  include/waf/New.h
  include/waf/PrintTo.h
  include/waf/RefPtr.h
  include/waf/Section.h
  include/waf/StaticStorage.h
  include/waf/TypeTraits.h
  )

set(wabase_SOURCES
  src/basename.cpp
  src/bulk-memory.cpp
  src/bulk-memory.S
  src/byteorder.cpp
  src/log.cpp
  src/mutex.S
  src/notify_waiter.cpp
  src/PrintTo.cpp
  src/sleep_ms.cpp
  src/sprintf.cpp
  src/TypesCheck.cpp
  src/wasm_module.cpp
  )

set(wabase_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${wabase_HEADERS} ${wabase_SOURCES})
add_library(wabase STATIC ${wabase_HEADERS} ${wabase_SOURCES})
target_include_directories(wabase PUBLIC ${wabase_INCLUDES})
set_target_properties(wabase PROPERTIES LINKER_LANGUAGE CXX)

add_library(WASMUX::WABASE ALIAS wabase)

WASMUX_INSTALL_HEADERS(HEADERS ${wabase_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
