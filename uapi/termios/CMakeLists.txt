set(termios_HEADERS
  include/termios.h
  )

set(termios_SOURCES
  src/termios.cpp
  )

set(termios_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(termios_DEFINITIONS
  )

set(termios_LIBRARIES
  wauser
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${termios_HEADERS} ${termios_SOURCES})
add_library(termios STATIC ${termios_HEADERS} ${termios_SOURCES})
target_include_directories(termios PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(termios PRIVATE "${termios_INCLUDES}")
target_compile_definitions(termios PRIVATE "${termios_DEFINITIONS}")
target_link_libraries(termios PRIVATE ${termios_LIBRARIES})

if (CONFIG_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${termios_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
