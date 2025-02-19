set(wauser_HEADERS
  include/wasmux/syscalls.h
  include/wasmux/thread_data.h
  include/wasmux/waitstatus.h
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

add_custom_script(
  SCRIPT src/syscall-nums.h.mjs
  INPUT "${WASMUX_ROOT_DIR}/data/syscall.mjs"
  OUTPUT wasmux/syscall-nums.h
  WORK_DIR "${CMAKE_CURRENT_BINARY_DIR}/include"
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${wauser_HEADERS} ${wauser_SOURCES})
add_library(wauser STATIC ${wauser_HEADERS} ${wauser_SOURCES} ${wauser_GENFILES})
target_include_directories(wauser PUBLIC ${wauser_INCLUDES})
target_link_libraries(wauser PUBLIC ${wauser_LIBRARIES})
set_target_properties(wauser PROPERTIES LINKER_LANGUAGE CXX)

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${wauser_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
  WX_INSTALL_HEADERS(HEADERS ${wauser_GENFILES} BASE_DIR "${CMAKE_CURRENT_BINARY_DIR}/include" DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
