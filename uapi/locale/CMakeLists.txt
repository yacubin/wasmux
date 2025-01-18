set(locale_HEADERS
  bits/locale_struct.h
  langinfo.h
  locale.h
  )

set(locale_SOURCES
  langinfo.cpp
  locale.cpp
  )

set(locale_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}"
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(locale_DEFINITIONS
  )

set(locale_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${locale_HEADERS} ${locale_SOURCES})
add_library(locale STATIC ${locale_HEADERS} ${locale_SOURCES})
target_include_directories(locale PUBLIC "${locale_INCLUDES}")
target_compile_definitions(locale PRIVATE "${locale_DEFINITIONS}")
target_link_libraries(locale PRIVATE ${locale_LIBRARIES})

WX_INSTALL_HEADERS(HEADERS ${locale_HEADERS} DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
