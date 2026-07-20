find_program(NODE_EXECUTABLE node REQUIRED)

add_custom_command(
  COMMENT "Generating errors header, errno.json, errno.h"
  DEPENDS emit
  COMMAND "$<TARGET_FILE:emit>" errno-json > "${CMAKE_CURRENT_BINARY_DIR}/errno.json"
  COMMAND "${NODE_EXECUTABLE}" "${CMAKE_SOURCE_DIR}/tools/errno.h.mjs" "${CMAKE_CURRENT_BINARY_DIR}/errno.json" include/wasmux/errno.h
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
  OUTPUT  include/wasmux/errno.h
  )
set_source_files_properties(include/wasmux/errno.h PROPERTIES GENERATED TRUE)

set(wasmux_HEADERS
  include/wasmux/errno.h
  )

set(wasmux_SOURCES
  src/fs/fcntl.cpp
  )

set(wasmux_INCLUDES
  "${CMAKE_BINARY_DIR}"
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${wasmux_HEADERS} ${wasmux_SOURCES})
add_library(wasmux OBJECT ${wasmux_HEADERS} ${wasmux_SOURCES})
target_include_directories(wasmux PUBLIC ${wasmux_INCLUDES})
set_target_properties(wasmux PROPERTIES LINKER_LANGUAGE CXX)
