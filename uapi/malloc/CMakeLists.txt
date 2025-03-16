set(malloc_HEADERS
  include/malloc.h
  )

set(malloc_SOURCES
  src/malloc.cpp
  )

set(malloc_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(malloc_DEFINITIONS
  )

set(malloc_LIBRARIES
  wauser
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${malloc_HEADERS} ${malloc_SOURCES})
add_library(malloc STATIC ${malloc_HEADERS} ${malloc_SOURCES})
target_include_directories(malloc PUBLIC "${malloc_INCLUDES}")
target_compile_definitions(malloc PRIVATE "${malloc_DEFINITIONS}")
target_link_libraries(malloc PRIVATE ${malloc_LIBRARIES})

set_target_properties(malloc PROPERTIES STDLIB_INCLUDE "#include <alloca.h>;#include <malloc.h>")

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${malloc_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
