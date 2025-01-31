set(libio_HEADERS
  include/bits/file_struct.h
  include/libio_wchar.h
  include/stdio.h
  include/stdio_ext.h
  )

set(libio_SOURCES
  src/_stdio.cpp
  src/fprintf.cpp
  src/getc_unlocked.cpp
  src/getdelim.cpp
  src/getline.cpp
  src/libio_wchar.cpp
  src/putc.cpp
  src/setvbuf.cpp
  src/sprintf.cpp
  src/stdio_ext.cpp
  src/stdio.cpp
  )

set(libio_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(libio_DEFINITIONS
  )

set(libio_LIBRARIES
  wauser
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${libio_HEADERS} ${libio_SOURCES})
add_library(libio STATIC ${libio_HEADERS} ${libio_SOURCES})
target_include_directories(libio PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(libio PRIVATE "${libio_INCLUDES}")
target_compile_definitions(libio PRIVATE "${libio_DEFINITIONS}")
target_link_libraries(libio PRIVATE ${libio_LIBRARIES})
set_target_properties(libio PROPERTIES PREFIX "")

if (CONFIG_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${libio_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
