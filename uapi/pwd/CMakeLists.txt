set(pwd_HEADERS
  include/pwd.h
  )

set(pwd_SOURCES
  src/pwd.cpp
  )

set(pwd_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(pwd_DEFINITIONS
  )

set(pwd_LIBRARIES
  wauser
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${pwd_HEADERS} ${pwd_SOURCES})
add_library(pwd STATIC ${pwd_HEADERS} ${pwd_SOURCES})
target_include_directories(pwd PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(pwd PRIVATE "${pwd_INCLUDES}")
target_compile_definitions(pwd PRIVATE "${pwd_DEFINITIONS}")
target_link_libraries(pwd PRIVATE ${pwd_LIBRARIES})

if (WASMUX_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${pwd_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
