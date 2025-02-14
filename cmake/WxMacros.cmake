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

macro (WX_SUBDIR_ENTRY)
  execute_process(COMMAND "${NODE_EXECUTABLE}" "${WASMUX_SCRIPT_DIR}/JaveScriptLoader.mjs"
      "--script=${WASMUX_SCRIPT_DIR}/SubdirEntry.mjs"
      "--config-script=${WASMUX_CONFIG_OBJECT}"
      "--source-dir=${CMAKE_CURRENT_SOURCE_DIR}"
      "--binary-dir=${CMAKE_CURRENT_BINARY_DIR}"
      "--plugin-list=${WASMUX_INJECT_SCRIPT_LIST}"
      "--output=${CMAKE_CURRENT_BINARY_DIR}/SubdirEntry.cmake"
    WORKING_DIRECTORY
      "${CMAKE_CURRENT_BINARY_DIR}"
    RESULT_VARIABLE
      _result
    )
  if (_result)
    message(FATAL_ERROR "Unable to process subdir entry")
  endif ()
  include("${CMAKE_CURRENT_BINARY_DIR}/SubdirEntry.cmake")
endmacro ()
