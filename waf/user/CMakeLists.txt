set(wauser_HEADERS
  include/wasmux/syscalls.h
  include/wasmux/thread_data.h
  )

set(wauser_SOURCES
  src/thread_data.cpp
  )

set(wauser_INCLUDES
  "${CMAKE_CURRENT_BINARY_DIR}/include"
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

set(wauser_LIBRARIES
  wabase
  )

set(wauser_GENFILES
  "${CMAKE_CURRENT_BINARY_DIR}/include/wasmux/syscall-nums.h"
  )

GEN_USYSCALLHDR(
  INPUT "${WASMUX_ROOT_DIR}/waf/syscall.js"
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/include/wasmux/syscall-nums.h"
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${wauser_HEADERS} ${wauser_SOURCES})
add_library(wauser STATIC ${wauser_HEADERS} ${wauser_SOURCES} ${wauser_GENFILES})
target_include_directories(wauser PUBLIC ${wauser_INCLUDES})
target_link_libraries(wauser PUBLIC ${wauser_LIBRARIES})
set_target_properties(wauser PROPERTIES LINKER_LANGUAGE CXX)

add_library(WASMUX::WAF ALIAS wauser)
add_library(WASMUX::WAUSER ALIAS wauser)

if (CONFIG_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${wauser_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
  WX_INSTALL_HEADERS(HEADERS ${wauser_GENFILES} BASE_DIR "${CMAKE_CURRENT_BINARY_DIR}/include" DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
