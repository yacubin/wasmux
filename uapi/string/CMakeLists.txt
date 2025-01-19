set(string_HEADERS
  include/string.h
  include/strings.h
  )

set(string_SOURCES
  src/memcpy.cpp
  src/memset.cpp
  src/stpcpy.cpp
  src/strchrnul.cpp
  src/strdup.cpp
  src/string.cpp
  )

set(string_INCLUDES
  $<TARGET_PROPERTY:wabase,INTERFACE_INCLUDE_DIRECTORIES>
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(string_DEFINITIONS
  )

set(string_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${string_HEADERS} ${string_SOURCES})
add_library(string STATIC ${string_HEADERS} ${string_SOURCES})
target_include_directories(string PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(string PRIVATE "${string_INCLUDES}")
target_compile_definitions(string PRIVATE "${string_DEFINITIONS}")
target_link_libraries(string PRIVATE ${string_LIBRARIES})

if (CONFIG_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${string_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
