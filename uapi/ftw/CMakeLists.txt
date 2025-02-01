set(ftw_HEADERS
  include/ftw.h
  )

set(ftw_SOURCES
  src/ftw.cpp
  src/nftw.cpp
  )

set(ftw_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(ftw_DEFINITIONS
  )

set(ftw_LIBRARIES
  wauser
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${ftw_HEADERS} ${ftw_SOURCES})
add_library(ftw STATIC ${ftw_HEADERS} ${ftw_SOURCES})
target_include_directories(ftw PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(ftw PRIVATE "${ftw_INCLUDES}")
target_compile_definitions(ftw PRIVATE "${ftw_DEFINITIONS}")
target_link_libraries(ftw PRIVATE ${ftw_LIBRARIES})

if (CONFIG_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${ftw_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
