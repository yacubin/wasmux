set(termios_HEADERS
  include/termios.h
  include/bits/termios_unistd.h
  )

set(termios_SOURCES
  src/ttyname.c
  src/tcsetpgrp.c
  src/isatty.c
  src/termios.c
  src/tcgetpgrp.c
  )

set(termios_DATAFILES
  MakeScript.mjs
  )

set(termios_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  "${CMAKE_BINARY_DIR}"
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${termios_HEADERS} ${termios_SOURCES} ${termios_DATAFILES})
add_library(termios OBJECT ${termios_HEADERS} ${termios_SOURCES} ${termios_DATAFILES})
target_include_directories(termios PUBLIC ${termios_INCLUDES})
target_compile_options(termios PRIVATE -nostdinc)
