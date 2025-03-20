set(netdb_HEADERS
  include/netdb.h
  )

set(netdb_SOURCES
  src/netdb.cpp
  )

set(netdb_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

set(netdb_DEFINITIONS
  )

set(netdb_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${netdb_HEADERS} ${netdb_SOURCES})
add_library(netdb STATIC ${netdb_HEADERS} ${netdb_SOURCES})
target_include_directories(netdb PUBLIC "${netdb_INCLUDES}")
target_include_directories(netdb PRIVATE $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>)
target_compile_definitions(netdb PRIVATE "${netdb_DEFINITIONS}")
target_link_libraries(netdb PRIVATE ${netdb_LIBRARIES})

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${netdb_HEADERS} DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
