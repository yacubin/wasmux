set(locale_HEADERS
  include/bits/locale_category.h
  include/bits/locale_ctype.h
  include/bits/locale_struct.h
  include/langinfo.h
  include/locale.h
  )

set(locale_SOURCES
  src/isalnum_l.cpp
  src/langinfo.cpp
  src/locale.cpp
  )

set(locale_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(locale_DEFINITIONS
  )

set(locale_LIBRARIES
  wauser
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${locale_HEADERS} ${locale_SOURCES})
add_library(locale STATIC ${locale_HEADERS} ${locale_SOURCES})
target_include_directories(locale PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(locale PRIVATE "${locale_INCLUDES}")
target_compile_definitions(locale PRIVATE "${locale_DEFINITIONS}")
target_link_libraries(locale PRIVATE ${locale_LIBRARIES})

set_target_properties(locale PROPERTIES CTYPE_INCLUDE "#include <bits/locale_ctype.h>")

if (CONFIG_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${locale_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
