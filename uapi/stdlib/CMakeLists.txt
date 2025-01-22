set(stdlib_HEADERS
  include/bits/__stdlib.h
  )

set(stdlib_SOURCES
  src/qsort.cpp
  )

set(stdlib_INCLUDES
  $<TARGET_PROPERTY:wabase,INTERFACE_INCLUDE_DIRECTORIES>
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(stdlib_DEFINITIONS
  )

set(stdlib_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${stdlib_HEADERS} ${stdlib_SOURCES})
add_library(stdlib STATIC ${stdlib_HEADERS} ${stdlib_SOURCES})
target_include_directories(stdlib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(stdlib PRIVATE "${stdlib_INCLUDES}")
target_compile_definitions(stdlib PRIVATE "${stdlib_DEFINITIONS}")
target_link_libraries(stdlib PRIVATE ${stdlib_LIBRARIES})

set_target_properties(stdlib PROPERTIES STDLIB_H_INCLUDE "#include <bits/__stdlib.h>")

if (CONFIG_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${stdlib_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
