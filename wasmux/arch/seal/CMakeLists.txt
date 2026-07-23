set(wasmux_arch_HEADERS
  include/wasmux/arch/log.h
  include/wasmux/arch/mm.h
  include/wasmux/arch/string.h
  include/wasmux/arch/syscalls_define.h
  include/wasmux/arch/syscalls.h
  include/wasmux/arch/unistd.h
  )

set(wasmux_arch_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${wasmux_arch_HEADERS})
add_library(wasmux_arch OBJECT ${wasmux_arch_HEADERS})
target_include_directories(wasmux_arch PUBLIC ${wasmux_arch_INCLUDES})
set_target_properties(wasmux_arch PROPERTIES LINKER_LANGUAGE C)
