set(semaphore_HEADERS
  include/semaphore.h
  )

set(semaphore_SOURCES
  src/semaphore.cpp
  )

set(semaphore_INCLUDES
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  )

set(semaphore_DEFINITIONS
  )

set(semaphore_LIBRARIES
  wauser
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${semaphore_HEADERS} ${semaphore_SOURCES})
add_library(semaphore STATIC ${semaphore_HEADERS} ${semaphore_SOURCES})
target_include_directories(semaphore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(semaphore PRIVATE "${semaphore_INCLUDES}")
target_compile_definitions(semaphore PRIVATE "${semaphore_DEFINITIONS}")
target_link_libraries(semaphore PRIVATE ${semaphore_LIBRARIES})

if (CONFIG_ENABLE_INSTALL_HEADERS)
  WX_INSTALL_HEADERS(HEADERS ${semaphore_HEADERS} BASE_DIR include DESTINATION "${WASMUX_INSTALL_INCLUDEDIR}")
endif ()
