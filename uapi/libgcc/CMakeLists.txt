set(libgcc_HEADERS
  fp_lib.h
  )

set(libgcc_SOURCES
  fp_lib.cpp
  )

set(libgcc_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}"
  )

set(libgcc_DEFINITIONS
  )

set(libgcc_LIBRARIES
  wabase
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${libgcc_HEADERS} ${libgcc_SOURCES})
add_library(libgcc STATIC ${libgcc_HEADERS} ${libgcc_SOURCES})
target_include_directories(libgcc PRIVATE "${libgcc_INCLUDES}")
target_compile_definitions(libgcc PRIVATE "${libgcc_DEFINITIONS}")
target_link_libraries(libgcc PRIVATE ${libgcc_LIBRARIES})
set_target_properties(libgcc PROPERTIES PREFIX "")

install(TARGETS libgcc
  RUNTIME DESTINATION "${WASMUX_INSTALL_BINDIR}"
  LIBRARY DESTINATION "${WASMUX_INSTALL_LIBDIR}"
  ARCHIVE DESTINATION "${WASMUX_INSTALL_LIBDIR}"
  )
