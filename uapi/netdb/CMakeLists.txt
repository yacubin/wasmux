set(netdb_HEADERS
  netdb.h
  )

set(netdb_SOURCES
  netdb.cpp
  )

set(netdb_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}"
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(netdb_DEFINITIONS
  )

set(netdb_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${netdb_HEADERS} ${netdb_SOURCES})
add_library(netdb STATIC ${netdb_HEADERS} ${netdb_SOURCES})
target_include_directories(netdb PRIVATE "${netdb_INCLUDES}")
target_compile_definitions(netdb PRIVATE "${netdb_DEFINITIONS}")
target_link_libraries(netdb PRIVATE ${netdb_LIBRARIES})

WX_INSTALL_HEADERS(HEADERS ${netdb_HEADERS} DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
