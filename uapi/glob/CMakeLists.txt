set(glob_HEADERS
  glob.h
  )

set(glob_SOURCES
  glob.cpp
  )

set(glob_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}"
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(glob_DEFINITIONS
  )

set(glob_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${glob_HEADERS} ${glob_SOURCES})
add_library(glob STATIC ${glob_HEADERS} ${glob_SOURCES})
target_include_directories(glob PUBLIC "${glob_INCLUDES}")
target_compile_definitions(glob PRIVATE "${glob_DEFINITIONS}")
target_link_libraries(glob PRIVATE ${glob_LIBRARIES})

WX_INSTALL_HEADERS(HEADERS ${glob_HEADERS} DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
