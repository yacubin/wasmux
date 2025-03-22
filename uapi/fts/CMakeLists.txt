set(fts_HEADERS
  include/fts.h
  )

set(fts_SOURCES
  src/fts.cpp
  )

set(fts_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

set(fts_DEFINITIONS
  )

set(fts_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${fts_HEADERS} ${fts_SOURCES})
add_library(fts STATIC ${fts_HEADERS} ${fts_SOURCES})
target_include_directories(fts PUBLIC "${fts_INCLUDES}")
target_include_directories(fts PRIVATE $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>)
target_compile_definitions(fts PRIVATE "${fts_DEFINITIONS}")
target_link_libraries(fts PRIVATE ${fts_LIBRARIES})

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${fts_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
