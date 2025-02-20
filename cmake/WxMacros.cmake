include(CMakeParseArguments)

find_program(NODE_EXECUTABLE node REQUIRED)

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

function (add_custom_script)
  cmake_parse_arguments(__arg "" "SCRIPT;INPUT;OUTPUT;WORK_DIR" "" ${ARGN})
  set(__ARG_LIST "")
  foreach (_iter ${ARGN})
    list(APPEND __ARG_LIST "$<1:${_iter}>")
  endforeach ()

  if (NOT __arg_SCRIPT)
    message(FATAL_ERROR "SCRIPT argument is mandatory")
  elseif (NOT IS_ABSOLUTE "${__arg_SCRIPT}")
    set(__arg_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/${__arg_SCRIPT}")
  endif ()

  if (__arg_WORK_DIR)
    make_directory("${__arg_WORK_DIR}")
  else ()
    set(__arg_WORK_DIR "${CMAKE_CURRENT_BINARY_DIR}")
  endif ()

  if (__arg_OUTPUT AND NOT IS_ABSOLUTE "${__arg_OUTPUT}")
    set(__arg_OUTPUT "${__arg_WORK_DIR}/${__arg_OUTPUT}")
  endif ()

  add_custom_command(COMMAND "${NODE_EXECUTABLE}"
      "${WASMUX_SCRIPT_DIR}/JaveScriptLoader.mjs"
      "--type=add_custom_script"
      "--script=${__arg_SCRIPT}"
      "--plugin-list=${WASMUX_INJECT_SCRIPT_LIST}"
      "--config-script=${WASMUX_CONFIG_OBJECT}"
      "--"
      ${__ARG_LIST}
    DEPENDS
      "${__arg_SCRIPT}"
      "${__arg_INPUT}"
    OUTPUT
      "${__arg_OUTPUT}"
    WORKING_DIRECTORY
      "${__arg_WORK_DIR}"
    VERBATIM
    )
endfunction ()

function (execute_script)
  cmake_parse_arguments(__arg "" "SCRIPT;WORK_DIR" "" ${ARGN})

  if (NOT __arg_SCRIPT)
    message(FATAL_ERROR "SCRIPT argument is mandatory")
  elseif (NOT IS_ABSOLUTE "${__arg_SCRIPT}")
    set(__arg_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/${__arg_SCRIPT}")
  endif ()

  if (__arg_WORK_DIR)
    make_directory("${__arg_WORK_DIR}")
  else ()
    set(__arg_WORK_DIR "${CMAKE_CURRENT_BINARY_DIR}")
  endif ()

  execute_process(COMMAND "${NODE_EXECUTABLE}"
      "${WASMUX_SCRIPT_DIR}/JaveScriptLoader.mjs"
      "--type=execute_script"
      "--script=${__arg_SCRIPT}"
      "--plugin-list=${WASMUX_INJECT_SCRIPT_LIST}"
      "--config-script=${WASMUX_CONFIG_OBJECT}"
      "--"
      ${ARGN}
    WORKING_DIRECTORY
      "${__arg_WORK_DIR}"
    RESULT_VARIABLE
      _result
    )
    if (_result)
      message(FATAL_ERROR "Unable to process subdir entry, result ${_result}")
    endif ()
endfunction ()

macro (WX_SUBDIR_ENTRY)
  execute_script(
    SCRIPT "${WASMUX_SCRIPT_DIR}/run/SubdirEntry.mjs"
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}"
    BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}"
    OUTPUT SubdirEntry.cmake
    WORK_DIR "${CMAKE_CURRENT_BINARY_DIR}"
    )
  include("${CMAKE_CURRENT_BINARY_DIR}/SubdirEntry.cmake")
endmacro ()
