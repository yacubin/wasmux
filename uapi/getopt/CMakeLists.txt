set(getopt_HEADERS
  getopt_core.h
  getopt.h
  )

set(getopt_SOURCES
  getopt.cpp
  )

set(getopt_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}"
  )

set(getopt_DEFINITIONS
  )

set(getopt_LIBRARIES
  WASMUX::WAF
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${getopt_HEADERS} ${getopt_SOURCES})
add_library(getopt STATIC ${getopt_HEADERS} ${getopt_SOURCES})
target_include_directories(getopt PUBLIC "${getopt_INCLUDES}")
target_compile_definitions(getopt PRIVATE "${getopt_DEFINITIONS}")
target_link_libraries(getopt PRIVATE ${getopt_LIBRARIES})

add_library(WASMUX::GETOPT ALIAS getopt)

WASMUX_INSTALL_HEADERS(HEADERS ${getopt_HEADERS} DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
