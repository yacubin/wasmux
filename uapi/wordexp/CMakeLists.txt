set(wordexp_HEADERS
  include/wordexp.h
  )

set(wordexp_SOURCES
  src/wordexp.cpp
  )

set(wordexp_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(wordexp_DEFINITIONS
  )

set(wordexp_LIBRARIES
  wauser
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${wordexp_HEADERS} ${wordexp_SOURCES})
add_library(wordexp STATIC ${wordexp_HEADERS} ${wordexp_SOURCES})
target_include_directories(wordexp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(wordexp PRIVATE "${wordexp_INCLUDES}")
target_compile_definitions(wordexp PRIVATE "${wordexp_DEFINITIONS}")
target_link_libraries(wordexp PRIVATE ${wordexp_LIBRARIES})

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${wordexp_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
