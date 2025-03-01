set(fcntl_HEADERS
  include/fcntl.h
  )

set(fcntl_SOURCES
  internal/fcntl.h
  src/creat.cpp
  src/fcntl.cpp
  src/open.cpp
  src/openat.cpp
  )

set(fcntl_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/internal"
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

set(fcntl_DEFINITIONS
  )

set(fcntl_LIBRARIES
  wauser
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${fcntl_HEADERS} ${fcntl_SOURCES})
add_library(fcntl STATIC ${fcntl_HEADERS} ${fcntl_SOURCES})
target_include_directories(fcntl PUBLIC ${fcntl_INCLUDES})
target_include_directories(fcntl PRIVATE $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>)
target_compile_definitions(fcntl PRIVATE "${fcntl_DEFINITIONS}")
target_link_libraries(fcntl PRIVATE ${fcntl_LIBRARIES})

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${fcntl_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
