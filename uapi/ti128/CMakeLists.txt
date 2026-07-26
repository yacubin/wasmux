set(ti128_HEADERS
  include/ti128.h
  )

set(ti128_SOURCES
  src/ti128.c
  src/multi3.c
  )

set(ti128_DATAFILES
  MakeScript.mjs
  )

set(ti128_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  $<TARGET_PROPERTY:wasmux,INTERFACE_INCLUDE_DIRECTORIES>
  "${CMAKE_BINARY_DIR}"
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${ti128_HEADERS} ${ti128_SOURCES} ${ti128_DATAFILES})
add_library(ti128 OBJECT ${ti128_HEADERS} ${ti128_SOURCES} ${ti128_DATAFILES})
target_include_directories(ti128 PUBLIC ${ti128_INCLUDES})
target_compile_options(ti128 PRIVATE -nostdinc)
