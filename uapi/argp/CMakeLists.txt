set(argp_HEADERS
  argp.h
  )

set(argp_SOURCES
  argp.cpp
  )

set(argp_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}"
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(argp_DEFINITIONS
  )

set(argp_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${argp_HEADERS} ${argp_SOURCES})
add_library(argp STATIC ${argp_HEADERS} ${argp_SOURCES})
target_include_directories(argp PUBLIC "${argp_INCLUDES}")
target_compile_definitions(argp PRIVATE "${argp_DEFINITIONS}")
target_link_libraries(argp PRIVATE ${argp_LIBRARIES})

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${argp_HEADERS} DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
