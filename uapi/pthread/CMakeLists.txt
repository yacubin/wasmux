set(pthread_HEADERS
  include/pthread.h
  )

set(pthread_SOURCES
  src/pthread.cpp
  )

set(pthread_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

set(pthread_DEFINITIONS
  )

set(pthread_LIBRARIES
  WASMUX::WAF
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${pthread_HEADERS} ${pthread_SOURCES})
add_library(pthread STATIC ${pthread_HEADERS} ${pthread_SOURCES})
target_include_directories(pthread PRIVATE "${pthread_INCLUDES}")
target_compile_definitions(pthread PRIVATE "${pthread_DEFINITIONS}")
target_link_libraries(pthread PRIVATE ${pthread_LIBRARIES})

add_library(WASMUX::Pthread ALIAS pthread)

install(TARGETS pthread
  RUNTIME DESTINATION "${WASMUX_INSTALL_BINDIR}"
  LIBRARY DESTINATION "${WASMUX_INSTALL_LIBDIR}"
  ARCHIVE DESTINATION "${WASMUX_INSTALL_LIBDIR}"
  )

WASMUX_INSTALL_HEADERS(HEADERS ${pthread_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
