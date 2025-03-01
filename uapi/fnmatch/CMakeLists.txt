set(fnmatch_HEADERS
  include/fnmatch.h
  )

set(fnmatch_SOURCES
  src/fnmatch.cpp
  )

set(fnmatch_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(fnmatch_DEFINITIONS
  )

set(fnmatch_LIBRARIES
  wauser
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${fnmatch_HEADERS} ${fnmatch_SOURCES})
add_library(fnmatch STATIC ${fnmatch_HEADERS} ${fnmatch_SOURCES})
target_include_directories(fnmatch PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(fnmatch PRIVATE "${fnmatch_INCLUDES}")
target_compile_definitions(fnmatch PRIVATE "${fnmatch_DEFINITIONS}")
target_link_libraries(fnmatch PRIVATE ${fnmatch_LIBRARIES})

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${fnmatch_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
