set(ulinux_HEADERS
  include/linux/blkpg.h
  include/linux/magic.h
  include/linux/version.h
  include/linux/vt.h
  )

set(ulinux_SOURCES
  )

set(ulinux_INCLUDES
  )

set(ulinux_DEFINITIONS
  )

set(ulinux_LIBRARIES
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${ulinux_HEADERS} ${ulinux_SOURCES})
add_library(ulinux STATIC ${ulinux_HEADERS} ${ulinux_SOURCES})
target_include_directories(ulinux PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_definitions(ulinux PRIVATE "${ulinux_DEFINITIONS}")
target_link_libraries(ulinux PRIVATE ${ulinux_LIBRARIES})

set_target_properties(ulinux PROPERTIES LINKER_LANGUAGE "C")

if (CONFIG_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${ulinux_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
