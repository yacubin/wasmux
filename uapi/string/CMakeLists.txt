add_custom_command(
  COMMENT "Generating errors messages, strerror.c"
  DEPENDS emit src/strerror.c.mjs
  COMMAND "$<TARGET_FILE:emit>" errno-json > "${CMAKE_CURRENT_BINARY_DIR}/errno.json"
  COMMAND "${NODE_EXECUTABLE}" src/strerror.c.mjs "${CMAKE_CURRENT_BINARY_DIR}/errno.json" src/strerror.c
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
  OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/src/strerror.c"
  )
set_source_files_properties("${CMAKE_CURRENT_SOURCE_DIR}/src/strerror.c" PROPERTIES GENERATED TRUE)

set(string_HEADERS
  include/bits/string_basename.h
  include/libgen.h
  include/string.h
  include/strings.h
  )

set(string_SOURCES
  src/basename.c
  src/bcopy.c
  src/dirname.c
  src/ffs.c
  src/memchr.c
  src/memcmp.c
  src/memcpy.c
  src/memmem.c
  src/memmove.c
  src/mempcpy.c
  src/memrchr.c
  src/memset.c
  src/rindex.c
  src/stpcpy.c
  src/stpncpy.c
  src/strcasecmp.c
  src/strcat.c
  src/strchr.c
  src/strchrnul.c
  src/strcmp.c
  src/strcoll.c
  src/strcpy.c
  src/strcspn.c
  # src/strdup.c
  src/strerror.c
  src/string.c
  src/strlen.c
  src/strncasecmp.c
  src/strncat.c
  src/strncmp.c
  src/strncpy.c
  src/strndup.c
  src/strnlen.c
  src/strpbrk.c
  src/strrchr.c
  src/strsep.c
  src/strspn.c
  src/strstr.c
  src/strtok.c
  src/strtok_r.c
  src/strverscmp.c
  src/strxfrm.c
  )

set(string_DATAFILES
  src/strerror.c.mjs
  )

set(string_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  $<TARGET_PROPERTY:libc,INTERFACE_INCLUDE_DIRECTORIES>
  "${CMAKE_BINARY_DIR}"
  )

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${string_HEADERS} ${string_SOURCES} ${string_DATAFILES})
add_library(string OBJECT ${string_HEADERS} ${string_SOURCES} ${string_DATAFILES})
target_include_directories(string PUBLIC ${string_INCLUDES})
target_compile_options(string PRIVATE -nostdinc)
