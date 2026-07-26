add_custom_command(
  COMMENT "Generating errors header arch-syscall.h"
  DEPENDS include/wasmux/arch/arch-syscall.h.mjs
  COMMAND "${NODE_EXECUTABLE}" include/wasmux/arch/arch-syscall.h.mjs "${CMAKE_SOURCE_DIR}/data/syscall.js" include/wasmux/arch/arch-syscall.h
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
  OUTPUT  "${CMAKE_CURRENT_SOURCE_DIR}/include/wasmux/arch/arch-syscall.h"
  )
set_source_files_properties(
  "${CMAKE_CURRENT_SOURCE_DIR}/include/wasmux/arch/arch-syscall.h" PROPERTIES GENERATED TRUE
  )

set(wasmux_arch_HEADERS
  include/wasmux/arch/arch-syscall.h
  include/wasmux/arch/log.h
  include/wasmux/arch/mm.h
  include/wasmux/arch/string.h
  include/wasmux/arch/syscalls_define.h
  include/wasmux/arch/syscalls.h
  include/wasmux/arch/unistd.h
  )

set(wasmux_arch_DATAFILES
  include/wasmux/arch/arch-syscall.h.mjs
  )

set(wasmux_arch_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${wasmux_arch_HEADERS} ${wasmux_arch_DATAFILES})
add_library(wasmux_arch OBJECT ${wasmux_arch_HEADERS} ${wasmux_arch_DATAFILES})
target_include_directories(wasmux_arch PUBLIC ${wasmux_arch_INCLUDES})
set_target_properties(wasmux_arch PROPERTIES LINKER_LANGUAGE C)

add_library(wasmux::arch ALIAS wasmux_arch)
