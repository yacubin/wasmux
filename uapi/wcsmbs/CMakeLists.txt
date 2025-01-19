set(wcsmbs_HEADERS
  include/wcsmbs_stdlib.h
  include/wcsmbs.h
  include/wctype.h
  )

set(wcsmbs_SOURCES
  src/btowc.cpp
  src/mblen.cpp
  src/mbrlen.cpp
  src/mbrtowc.cpp
  src/mbsinit.cpp
  src/mbsnrtowcs.cpp
  src/mbsrtowcs.cpp
  src/mbstowcs.cpp
  src/mbtowc.cpp
  src/wcrtomb.cpp
  src/wcscat.cpp
  src/wcschr.cpp
  src/wcscmp.cpp
  src/wcscpy.cpp
  src/wcslen.cpp
  src/wcsncmp.cpp
  src/wcsrtombs.cpp
  src/wcstombs.cpp
  src/wctob.cpp
  src/wctomb.cpp
  src/wctype.cpp
  src/wmemchr.cpp
  src/wmemcpy.cpp
  )

set(wcsmbs_INCLUDES
  $<TARGET_PROPERTY:wabase,INTERFACE_INCLUDE_DIRECTORIES>
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(wcsmbs_DEFINITIONS
  )

set(wcsmbs_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${wcsmbs_HEADERS} ${wcsmbs_SOURCES})
add_library(wcsmbs STATIC ${wcsmbs_HEADERS} ${wcsmbs_SOURCES})
target_include_directories(wcsmbs PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(wcsmbs PRIVATE "${wcsmbs_INCLUDES}")
target_compile_definitions(wcsmbs PRIVATE "${wcsmbs_DEFINITIONS}")
target_link_libraries(wcsmbs PRIVATE ${wcsmbs_LIBRARIES})

if (CONFIG_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${wcsmbs_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
