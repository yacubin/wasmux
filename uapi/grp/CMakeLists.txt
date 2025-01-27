set(grp_HEADERS
  include/grp.h
  )

set(grp_SOURCES
  src/grp.cpp
  )

set(grp_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(grp_DEFINITIONS
  )

set(grp_LIBRARIES
  wauser
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${grp_HEADERS} ${grp_SOURCES})
add_library(grp STATIC ${grp_HEADERS} ${grp_SOURCES})
target_include_directories(grp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(grp PRIVATE "${grp_INCLUDES}")
target_compile_definitions(grp PRIVATE "${grp_DEFINITIONS}")
target_link_libraries(grp PRIVATE ${grp_LIBRARIES})

if (CONFIG_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${grp_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
