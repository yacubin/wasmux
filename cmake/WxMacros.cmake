macro(WX_OPTION _name _desc _value _type)
  if (${_type} STREQUAL BOOLEAN)
    option(${_name} "${_desc}" ${_value})
  elseif (${_type} STREQUAL STRING)
    set(${_name} "${_value}" CACHE STRING "${_desc}")
  elseif (${_type} STREQUAL ENUM)
    set(${_name} "${_value}" CACHE STRING "${_desc}")
    set_property(CACHE ${_name} PROPERTY STRINGS ${ARGN})
  else ()
    message(FATAL_ERROR "Unknown '${_type}' type used for '${_name}' option")
  endif ()
endmacro()

macro(WX_INSTALL_HEADERS)
  cmake_parse_arguments(__waf_install_headers
    ""
    "BASE_DIR;DESTINATION"
    "HEADERS"
    ${ARGN}
    )
  foreach (__waf_install_headers_iter IN LISTS __waf_install_headers_HEADERS)
    set(__waf_install_headers_file "${__waf_install_headers_iter}")
    if (__waf_install_headers_BASE_DIR)
      string(REGEX REPLACE "^${__waf_install_headers_BASE_DIR}[\\/]?(.*)" "\\1" __waf_install_headers_file "${__waf_install_headers_iter}")
    endif ()
    get_filename_component(__waf_install_headers_dir "${__waf_install_headers_DESTINATION}/${__waf_install_headers_file}" DIRECTORY)
    install(FILES "${__waf_install_headers_iter}" DESTINATION "${__waf_install_headers_dir}")
  endforeach ()
endmacro()
