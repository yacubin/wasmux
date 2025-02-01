set(login_HEADERS
  include/utmp.h
  include/utmpx.h
  )

set(login_SOURCES
  src/utmp.cpp
  src/utmpx.cpp
  )

set(login_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(login_DEFINITIONS
  )

set(login_LIBRARIES
  wauser
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${login_HEADERS} ${login_SOURCES})
add_library(login STATIC ${login_HEADERS} ${login_SOURCES})
target_include_directories(login PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(login PRIVATE "${login_INCLUDES}")
target_compile_definitions(login PRIVATE "${login_DEFINITIONS}")
target_link_libraries(login PRIVATE ${login_LIBRARIES})

if (CONFIG_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${login_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
