set(crt1_HEADERS
  )

set(crt1_SOURCES
  start.c
  version.c
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${crt1_HEADERS} ${crt1_SOURCES})
add_library(crt1 OBJECT ${crt1_HEADERS} ${crt1_SOURCES})
target_include_directories(crt1 PRIVATE $<TARGET_PROPERTY:WASMUX::WAF,INTERFACE_INCLUDE_DIRECTORIES>)

set(crt1_reactor_HEADERS
  )

set(crt1_reactor_SOURCES
  initialize.c
  version.c
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${crt1_reactor_HEADERS} ${crt1_reactor_SOURCES})
add_library(crt1_reactor OBJECT ${crt1_reactor_HEADERS} ${crt1_reactor_SOURCES})
target_include_directories(crt1_reactor PRIVATE $<TARGET_PROPERTY:WASMUX::WAF,INTERFACE_INCLUDE_DIRECTORIES>)

set(CRuntime_FLAGS
  )

if (CMAKE_SYSTEM_PROCESSOR STREQUAL wasm64)
  list(APPEND CRuntime_FLAGS -mwasm64)
endif ()

add_custom_target(CRuntime ALL DEPENDS crt1 crt1_reactor
  COMMAND "${CMAKE_LINKER}" ${CRuntime_FLAGS} -r -o crt1.o $<TARGET_OBJECTS:crt1>
  COMMAND "${CMAKE_LINKER}" ${CRuntime_FLAGS} -r -o crt1-reactor.o $<TARGET_OBJECTS:crt1_reactor>
  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
  COMMAND_EXPAND_LISTS
  VERBATIM
  )

install(
  FILES
    "${CMAKE_CURRENT_BINARY_DIR}/crt1.o"
    "${CMAKE_CURRENT_BINARY_DIR}/crt1-reactor.o"
  DESTINATION
    "${WASMUX_INSTALL_LIBDIR}"
  )
