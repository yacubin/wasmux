set(libcxxabi_HEADERS
  )

set(libcxxabi_SOURCES
  stub/__cxa_demangle.cpp
  )

set(libcxxabi_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

set(libcxxabi_DEFINITIONS
  )

set(libcxxabi_LIBRARIES
  wabase
  )

add_library(libcxxabi STATIC ${libcxxabi_SOURCES})
target_include_directories(libcxxabi PRIVATE "${libcxxabi_INCLUDES}")
target_compile_definitions(libcxxabi PRIVATE "${libcxxabi_DEFINITIONS}")
target_link_libraries(libcxxabi PRIVATE ${libcxxabi_LIBRARIES})
set_target_properties(libcxxabi PROPERTIES OUTPUT_NAME "c++abi")

add_library(WASMUX::LIBCXXABI ALIAS libcxxabi)

install(TARGETS libcxxabi
  RUNTIME DESTINATION "${WASMUX_INSTALL_BINDIR}"
  LIBRARY DESTINATION "${WASMUX_INSTALL_LIBDIR}"
  ARCHIVE DESTINATION "${WASMUX_INSTALL_LIBDIR}"
  )

if (CONFIG_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${libcxxabi_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
