set(walinuz_SOURCES
  InstanceExit.cpp
  InstancePerform.cpp
  StartKernel.cpp
  KernelVersion.cpp
  )

set(walinuz_DEFINITIONS
  )

set(walinuz_LIBRARIES
  wacore
  ${KERNEL_DEPENDENCIES}
  )

if (CMAKE_SYSTEM_PROCESSOR MATCHES "wasm(32|64)")
  list(APPEND walinuz_SOURCES StartKernel.S)
endif ()

if (WIN32)
  list(APPEND walinuz_SOURCES StartWindows.cpp)
  list(APPEND walinuz_SOURCES walinuz.lds)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,65536 -Wl,--script=${CMAKE_CURRENT_SOURCE_DIR}/walinuz.lds")
endif ()

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--Map=${CMAKE_CURRENT_BINARY_DIR}/walinuz.map")

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${walinuz_SOURCES})
add_executable(walinuz ${walinuz_SOURCES})
target_compile_definitions(walinuz PRIVATE "${walinuz_DEFINITIONS}")
target_link_libraries(walinuz PUBLIC ${walinuz_LIBRARIES})
set_target_properties(walinuz PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS OFF)

if (CMAKE_SYSTEM_PROCESSOR MATCHES "wasm(32|64)")
  target_link_options(walinuz PRIVATE -Wl,--export=_start_kernel -Wl,--export=WEI_perform -Wl,--export=WEI_exit)
endif ()

if (CMAKE_SYSTEM_PROCESSOR MATCHES "wasm(32|64)")
  find_program(WAEDITOR_EXECUTABLE waeditor)
  if (WAEDITOR_EXECUTABLE)
    add_custom_command(TARGET walinuz POST_BUILD
      BYPRODUCTS "${CMAKE_CURRENT_BINARY_DIR}/waeditor-walinuz.ts"
      COMMAND "${WAEDITOR_EXECUTABLE}"
        --add-user-memory
        $<TARGET_FILE:walinuz>
      WORKING_DIRECTORY
          "${CMAKE_CURRENT_BINARY_DIR}"
      VERBATIM
      )
  endif ()
endif ()

install(TARGETS walinuz RUNTIME DESTINATION /boot)
