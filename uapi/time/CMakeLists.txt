set(time_HEADERS
  include/bits/time.h
  )

set(time_SOURCES
  src/clock_getres.c
  src/clock_gettime.c
  src/clock_nanosleep.c
  )

set(time_DATAFILES
  MakeScript.mjs
  )

set(time_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  "${CMAKE_BINARY_DIR}"
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${time_HEADERS} ${time_SOURCES} ${time_DATAFILES})
add_library(time OBJECT ${time_HEADERS} ${time_SOURCES} ${time_DATAFILES})
target_include_directories(time PUBLIC ${time_INCLUDES})
target_compile_options(time PRIVATE -nostdinc)
