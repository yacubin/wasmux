set(dirent_HEADERS
  include/dirent.h
  include/bits/__dirent_dir_struct.h
  )

set(dirent_SOURCES
  src/dirent.cpp
  src/dirfd.cpp
  )

set(dirent_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(dirent_DEFINITIONS
  )

set(dirent_LIBRARIES
  wauser
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${dirent_HEADERS} ${dirent_SOURCES})
add_library(dirent STATIC ${dirent_HEADERS} ${dirent_SOURCES})
target_include_directories(dirent PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(dirent PRIVATE "${dirent_INCLUDES}")
target_compile_definitions(dirent PRIVATE "${dirent_DEFINITIONS}")
target_link_libraries(dirent PRIVATE ${dirent_LIBRARIES})

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${dirent_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
