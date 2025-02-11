set(obstack_HEADERS
  include/bits/__obstack_version.h
  include/obstack.h
  )

set(obstack_SOURCES
  src/obstack.cpp
  )

set(obstack_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(obstack_DEFINITIONS
  )

set(obstack_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${obstack_HEADERS} ${obstack_SOURCES})
add_library(obstack STATIC ${obstack_HEADERS} ${obstack_SOURCES})
target_include_directories(obstack PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(obstack PRIVATE "${obstack_INCLUDES}")
target_compile_definitions(obstack PRIVATE "${obstack_DEFINITIONS}")
target_link_libraries(obstack PRIVATE ${obstack_LIBRARIES})

set_target_properties(obstack PROPERTIES GNU_VERSIONS_INCLUDE "#include <bits/__obstack_version.h>")

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${obstack_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
