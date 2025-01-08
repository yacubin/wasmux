set(wacore_HEADERS
  include/wasmux/init.h
  include/wasmux/wasm_page.h
  )

set(wacore_SOURCES
  src/wacore_dump.cpp
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
  )

GEN_KSYSCALLHDR(
  INPUT "${WASMUX_ROOT_DIR}/waf/syscall.json"
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/include/uapi/asm/unistd.h"
)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${wacore_HEADERS} ${wacore_SOURCES})
add_library(wacore STATIC ${wacore_HEADERS} ${wacore_SOURCES} ${wacore_GENFILES})
target_include_directories(wacore PUBLIC ${wacore_INCLUDES})
target_link_libraries(wacore PUBLIC ${wacore_LIBRARIES})
set_target_properties(wacore PROPERTIES LINKER_LANGUAGE CXX)

add_library(WASMUX::WACORE ALIAS wacore)
