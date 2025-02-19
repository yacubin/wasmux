set(string_HEADERS
  include/bits/__string_basename.h
  include/libgen.h
  include/string.h
  include/strings.h
  )

set(string_SOURCES
  src/basename.cpp
  src/dirname.cpp
  src/memchr.cpp
  src/memcpy.cpp
  src/memrchr.cpp
  src/memset.cpp
  src/rindex.cpp
  src/stpcpy.cpp
  src/strchrnul.cpp
  src/strdup.cpp
  src/string.cpp
  src/strrchr.cpp
  src/strsep.cpp
  src/strtok_r.cpp
  )

set(string_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(string_DEFINITIONS
  )

set(string_LIBRARIES
  wauser
  )

set(string_GENFILES
  "${CMAKE_CURRENT_BINARY_DIR}/src/strerror.cpp"
  )

add_custom_script(
  SCRIPT src/strerror.cpp.mjs
  INPUT "${WASMUX_ROOT_DIR}/data/errno.mjs"
  OUTPUT strerror.cpp
  WORK_DIR "${CMAKE_CURRENT_BINARY_DIR}/src"
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${string_HEADERS} ${string_SOURCES})
add_library(string STATIC ${string_HEADERS} ${string_SOURCES} ${string_GENFILES})
target_include_directories(string PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(string PRIVATE "${string_INCLUDES}")
target_compile_definitions(string PRIVATE "${string_DEFINITIONS}")
target_link_libraries(string PRIVATE ${string_LIBRARIES})

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${string_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
