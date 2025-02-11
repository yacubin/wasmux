set(glob_HEADERS
  include/bits/__glob_version.h
  include/glob.h
  )

set(glob_SOURCES
  src/glob.cpp
  )

set(glob_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(glob_DEFINITIONS
  )

set(glob_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${glob_HEADERS} ${glob_SOURCES})
add_library(glob STATIC ${glob_HEADERS} ${glob_SOURCES})
target_include_directories(glob PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(glob PRIVATE "${glob_INCLUDES}")
target_compile_definitions(glob PRIVATE "${glob_DEFINITIONS}")
target_link_libraries(glob PRIVATE ${glob_LIBRARIES})

set_target_properties(glob PROPERTIES GNU_VERSIONS_INCLUDE "#include <bits/__glob_version.h>")

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${glob_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
