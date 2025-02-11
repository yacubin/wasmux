set(regex_HEADERS
  include/bits/__regex_version.h
  include/regex.h
  )

set(regex_SOURCES
  src/regex.cpp
  )

set(regex_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(regex_DEFINITIONS
  )

set(regex_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${regex_HEADERS} ${regex_SOURCES})
add_library(regex STATIC ${regex_HEADERS} ${regex_SOURCES})
target_include_directories(regex PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(regex PRIVATE "${regex_INCLUDES}")
target_compile_definitions(regex PRIVATE "${regex_DEFINITIONS}")
target_link_libraries(regex PRIVATE ${regex_LIBRARIES})

set_target_properties(regex PROPERTIES GNU_VERSIONS_INCLUDE "#include <bits/__regex_version.h>")

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${regex_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
