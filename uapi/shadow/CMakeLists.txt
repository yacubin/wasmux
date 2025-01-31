set(shadow_HEADERS
  include/shadow.h
  )

set(shadow_SOURCES
  src/shadow.cpp
  )

set(shadow_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(shadow_DEFINITIONS
  )

set(shadow_LIBRARIES
  wauser
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${shadow_HEADERS} ${shadow_SOURCES})
add_library(shadow STATIC ${shadow_HEADERS} ${shadow_SOURCES})
target_include_directories(shadow PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(shadow PRIVATE "${shadow_INCLUDES}")
target_compile_definitions(shadow PRIVATE "${shadow_DEFINITIONS}")
target_link_libraries(shadow PRIVATE ${shadow_LIBRARIES})

if (CONFIG_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${shadow_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
