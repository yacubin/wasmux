set(libintl_HEADERS
  include/libintl.h
  )

set(libintl_SOURCES
  src/libintl.cpp
  )

set(libintl_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

set(libintl_DEFINITIONS
  )

set(libintl_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${libintl_HEADERS} ${libintl_SOURCES})
add_library(libintl STATIC ${libintl_HEADERS} ${libintl_SOURCES})
target_include_directories(libintl PUBLIC "${libintl_INCLUDES}")
target_include_directories(libintl PRIVATE $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>)
target_compile_definitions(libintl PRIVATE "${libintl_DEFINITIONS}")
target_link_libraries(libintl PRIVATE ${libintl_LIBRARIES})
set_target_properties(libintl PROPERTIES PREFIX "")

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${libintl_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
