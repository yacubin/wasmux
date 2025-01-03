set(libcxx_HEADERS
  )

set(libcxx_SOURCES
  stub/__cxa_atexit.cpp
  stub/__cxa_pure_virtual.cpp
  stub/new.cpp
  )

set(libcxx_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

set(libcxx_DEFINITIONS
  )

set(libcxx_LIBRARIES
  WASMUX::WAF
  )

set_source_files_properties(stub/new.cpp PROPERTIES COMPILE_FLAGS -fvisibility-global-new-delete=force-hidden)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${libcxx_HEADERS} ${libcxx_SOURCES})
add_library(libcxx STATIC ${libcxx_HEADERS} ${libcxx_SOURCES})
target_include_directories(libcxx PRIVATE "${libcxx_INCLUDES}")
target_compile_definitions(libcxx PRIVATE "${libcxx_DEFINITIONS}")
target_link_libraries(libcxx PRIVATE ${libcxx_LIBRARIES})
set_target_properties(libcxx PROPERTIES OUTPUT_NAME "c++")

add_library(WASMUX::LIBCXX ALIAS libcxx)

install(TARGETS libcxx
  RUNTIME DESTINATION "${WASMUX_INSTALL_BINDIR}"
  LIBRARY DESTINATION "${WASMUX_INSTALL_LIBDIR}"
  ARCHIVE DESTINATION "${WASMUX_INSTALL_LIBDIR}"
  )

WASMUX_INSTALL_HEADERS(HEADERS ${libcxx_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
