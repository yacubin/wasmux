set(getopt_HEADERS
  include/bits/__getopt_version.h
  include/bits/__getopt_base.h
  include/getopt.h
  )

set(getopt_SOURCES
  src/getopt.cpp
  )

set(getopt_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(getopt_DEFINITIONS
  )

set(getopt_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${getopt_HEADERS} ${getopt_SOURCES})
add_library(getopt STATIC ${getopt_HEADERS} ${getopt_SOURCES})
target_include_directories(getopt PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(getopt PRIVATE "${getopt_INCLUDES}")
target_compile_definitions(getopt PRIVATE "${getopt_DEFINITIONS}")
target_link_libraries(getopt PRIVATE ${getopt_LIBRARIES})

set_target_properties(getopt PROPERTIES GNU_VERSIONS_INCLUDE "#include <bits/__getopt_version.h>")
set_target_properties(getopt PROPERTIES UNISTD_INCLUDE "#include <bits/__getopt_base.h>")

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${getopt_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
