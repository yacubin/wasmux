set(argp_HEADERS
  include/argp.h
  )

set(argp_SOURCES
  src/argp.cpp
  )

set(argp_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

set(argp_DEFINITIONS
  )

set(argp_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${argp_HEADERS} ${argp_SOURCES})
add_library(argp STATIC ${argp_HEADERS} ${argp_SOURCES})
target_include_directories(argp PUBLIC "${argp_INCLUDES}")
target_include_directories(argp PRIVATE $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>)
target_compile_definitions(argp PRIVATE "${argp_DEFINITIONS}")
target_link_libraries(argp PRIVATE ${argp_LIBRARIES})

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${argp_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
