set(waeditor_SOURCES
  waeditor.cpp
  )

set(waeditor_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}"
  "${CMAKE_CURRENT_BINARY_DIR}"
  )

set(waeditor_LIBRARIES
  wabase
  )

set(waeditor_DEFINITIONS
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${waeditor_SOURCES})
add_executable(waeditor ${waeditor_SOURCES})
target_include_directories(waeditor PRIVATE ${waeditor_INCLUDES})
target_link_libraries(waeditor PRIVATE ${waeditor_LIBRARIES})
target_compile_definitions(waeditor PRIVATE "${waeditor_DEFINITIONS}")
set_target_properties(waeditor PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS OFF)

install(TARGETS waeditor
  RUNTIME DESTINATION "${WASMUX_INSTALL_BINDIR}"
  )
