set(fts_HEADERS
  fts.h
  )

set(fts_SOURCES
  fts.cpp
  )

set(fts_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}"
  )

set(fts_DEFINITIONS
  )

set(fts_LIBRARIES
  WASMUX::WAF
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${fts_HEADERS} ${fts_SOURCES})
add_library(fts STATIC ${fts_HEADERS} ${fts_SOURCES})
target_include_directories(fts PRIVATE "${fts_INCLUDES}")
target_compile_definitions(fts PRIVATE "${fts_DEFINITIONS}")
target_link_libraries(fts PRIVATE ${fts_LIBRARIES})

add_library(WASMUX::FTS ALIAS fts)

WASMUX_INSTALL_HEADERS(HEADERS ${fts_HEADERS} DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
