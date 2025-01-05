set(libintl_HEADERS
  libintl.h
  )

set(libintl_SOURCES
  libintl.cpp
  )

set(libintl_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}"
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(libintl_DEFINITIONS
  )

set(libintl_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${libintl_HEADERS} ${libintl_SOURCES})
add_library(libintl STATIC ${libintl_HEADERS} ${libintl_SOURCES})
target_include_directories(libintl PRIVATE "${libintl_INCLUDES}")
target_compile_definitions(libintl PRIVATE "${libintl_DEFINITIONS}")
target_link_libraries(libintl PRIVATE ${libintl_LIBRARIES})
set_target_properties(libintl PROPERTIES PREFIX "")

WASMUX_INSTALL_HEADERS(HEADERS ${libintl_HEADERS} DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
