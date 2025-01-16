set(getopt_HEADERS
  getopt_unistd.h
  getopt.h
  )

set(getopt_SOURCES
  getopt.cpp
  )

set(getopt_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}"
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(getopt_DEFINITIONS
  )

set(getopt_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${getopt_HEADERS} ${getopt_SOURCES})
add_library(getopt STATIC ${getopt_HEADERS} ${getopt_SOURCES})
target_include_directories(getopt PUBLIC "${getopt_INCLUDES}")
target_compile_definitions(getopt PRIVATE "${getopt_DEFINITIONS}")
target_link_libraries(getopt PRIVATE ${getopt_LIBRARIES})

add_library(WASMUX::GETOPT ALIAS getopt)

WX_INSTALL_HEADERS(HEADERS ${getopt_HEADERS} DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
