set(ctype_HEADERS
  include/ctype.h
  )

set(ctype_SOURCES
  src/ctype.cpp
  )

set(ctype_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(ctype_DEFINITIONS
  )

set(ctype_LIBRARIES
  wauser
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${ctype_HEADERS} ${ctype_SOURCES})
add_library(ctype STATIC ${ctype_HEADERS} ${ctype_SOURCES})
target_include_directories(ctype PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(ctype PRIVATE "${ctype_INCLUDES}")
target_compile_definitions(ctype PRIVATE "${ctype_DEFINITIONS}")
target_link_libraries(ctype PRIVATE ${ctype_LIBRARIES})

if (CONFIG_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${ctype_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
