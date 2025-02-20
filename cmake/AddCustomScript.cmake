
include(CMakeParseArguments)

function (add_custom_script)
  cmake_parse_arguments(__arg "" "INPUT;OUTPUT;SCRIPT;WORK_DIR" "" ${ARGN})
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
