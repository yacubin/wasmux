set(malloc_HEADERS
  malloc.h
  )

set(malloc_SOURCES
  malloc.cpp
  )

set(malloc_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}"
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(malloc_DEFINITIONS
  )

set(malloc_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${malloc_HEADERS} ${malloc_SOURCES})
add_library(malloc STATIC ${malloc_HEADERS} ${malloc_SOURCES})
target_include_directories(malloc PUBLIC "${malloc_INCLUDES}")
target_compile_definitions(malloc PRIVATE "${malloc_DEFINITIONS}")
target_link_libraries(malloc PRIVATE ${malloc_LIBRARIES})

WASMUX_INSTALL_HEADERS(HEADERS ${malloc_HEADERS} DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
