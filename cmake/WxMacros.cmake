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
