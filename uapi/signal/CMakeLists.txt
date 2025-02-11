set(signal_HEADERS
  include/bits/signal.h
  include/signal.h
  )

set(signal_SOURCES
  src/sigemptyset.cpp
  src/signal.cpp
  )

set(signal_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(signal_DEFINITIONS
  )

set(signal_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${signal_HEADERS} ${signal_SOURCES})
add_library(signal STATIC ${signal_HEADERS} ${signal_SOURCES})
target_include_directories(signal PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(signal PRIVATE "${signal_INCLUDES}")
target_compile_definitions(signal PRIVATE "${signal_DEFINITIONS}")
target_link_libraries(signal PRIVATE ${signal_LIBRARIES})

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${signal_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
