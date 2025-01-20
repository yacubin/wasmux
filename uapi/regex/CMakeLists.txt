set(regex_HEADERS
  regex.h
  )

set(regex_SOURCES
  regex.cpp
  )

set(regex_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}"
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(regex_DEFINITIONS
  )

set(regex_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${regex_HEADERS} ${regex_SOURCES})
add_library(regex STATIC ${regex_HEADERS} ${regex_SOURCES})
target_include_directories(regex PUBLIC "${regex_INCLUDES}")
target_compile_definitions(regex PRIVATE "${regex_DEFINITIONS}")
target_link_libraries(regex PRIVATE ${regex_LIBRARIES})

set_target_properties(regex PROPERTIES GNU_VERSIONS_H_DEFINE "#define _GNU_REGEX_INTERFACE_VERSION 1")

if (CONFIG_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${regex_HEADERS} DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
