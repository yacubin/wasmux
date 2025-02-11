set(mntent_HEADERS
  include/mntent.h
  )

set(mntent_SOURCES
  src/endmntent.cpp
  src/getmntent_r.cpp
  src/getmntent.cpp
  src/hasmntopt.cpp
  src/setmntent.cpp
  )

set(mntent_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(mntent_DEFINITIONS
  )

set(mntent_LIBRARIES
  wauser
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${mntent_HEADERS} ${mntent_SOURCES})
add_library(mntent STATIC ${mntent_HEADERS} ${mntent_SOURCES})
target_include_directories(mntent PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(mntent PRIVATE "${mntent_INCLUDES}")
target_compile_definitions(mntent PRIVATE "${mntent_DEFINITIONS}")
target_link_libraries(mntent PRIVATE ${mntent_LIBRARIES})

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${mntent_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
