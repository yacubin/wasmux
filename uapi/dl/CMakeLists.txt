set(dl_HEADERS
  include/dlfcn.h
  )

set(dl_SOURCES
  src/dlfcn.cpp
  )

set(dl_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

set(dl_DEFINITIONS
  )

set(dl_LIBRARIES
  WASMUX::WAF
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${dl_HEADERS} ${dl_SOURCES})
add_library(dl STATIC ${dl_HEADERS} ${dl_SOURCES})
target_include_directories(dl PRIVATE "${dl_INCLUDES}")
target_compile_definitions(dl PRIVATE "${dl_DEFINITIONS}")
target_link_libraries(dl PUBLIC ${dl_LIBRARIES})

add_library(WASMUX::DL ALIAS dl)

install(TARGETS dl
  RUNTIME DESTINATION "${WASMUX_INSTALL_BINDIR}"
  LIBRARY DESTINATION "${WASMUX_INSTALL_LIBDIR}"
  ARCHIVE DESTINATION "${WASMUX_INSTALL_LIBDIR}"
  )

WX_INSTALL_HEADERS(HEADERS ${dl_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
