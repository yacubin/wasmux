set(kernel_HEADERS
  )

set(kernel_SOURCES
  start_kernel.cpp
  start_kernel.S
  )

set(kernel_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}"
  )

set(kernel_DEFINITIONS
  )

set(kernel_LIBRARIES
  WASMUX::WACORE
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${kernel_HEADERS} ${kernel_SOURCES})
add_executable(kernel ${kernel_HEADERS} ${kernel_SOURCES})
target_include_directories(kernel PRIVATE "${kernel_INCLUDES}")
target_compile_definitions(kernel PRIVATE "${kernel_DEFINITIONS}")
target_link_libraries(kernel PRIVATE ${kernel_LIBRARIES})

install(TARGETS kernel RUNTIME DESTINATION /boot)
