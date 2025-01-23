set(libm_HEADERS
  include/math.h
  )

set(libm_SOURCES
  src/math.cpp
  )

set(libm_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

set(libm_DEFINITIONS
  )

set(libm_LIBRARIES
  wauser
  libc
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${libm_HEADERS} ${libm_SOURCES})
add_library(libm STATIC ${libm_HEADERS} ${libm_SOURCES})
target_include_directories(libm PRIVATE "${libm_INCLUDES}")
target_compile_definitions(libm PRIVATE "${libm_DEFINITIONS}")
target_link_libraries(libm PRIVATE ${libm_LIBRARIES})
set_target_properties(libm PROPERTIES PREFIX "")

add_library(WASMUX::LIBM ALIAS libm)

install(TARGETS libm
  RUNTIME DESTINATION "${WASMUX_INSTALL_BINDIR}"
  LIBRARY DESTINATION "${WASMUX_INSTALL_LIBDIR}"
  ARCHIVE DESTINATION "${WASMUX_INSTALL_LIBDIR}"
  )

if (CONFIG_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${libm_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
