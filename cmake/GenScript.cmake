
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

function (add_custom_javescript _script _options _one_value_keyword)
  set(_input "")
  set(_output "")
  set(_arg_list
    "--script=${_script}"
    "--plugin-list=${WASMUX_INJECT_SCRIPT_LIST}"
    "--config-script=${WASMUX_CONFIG_OBJECT}"
    )
  set(_work_dir "${CMAKE_CURRENT_BINARY_DIR}")

  set(_key "")
  foreach (_iter ${ARGN})
    if (_key)
      list(APPEND _arg_list "--${_key}=${_iter}")
      if ("${_key}" STREQUAL "input")
        set(_input "${_iter}")
      elseif ("${_key}" STREQUAL "output")
        set(_output "${_iter}")
      elseif ("${_key}" STREQUAL "work-dir")
        set(_work_dir "${_iter}")
      endif ()
      set(_key "")
    else ()
      string(REPLACE "_" "-" _key "${_iter}")
      string(TOLOWER "${_key}" _key)
      if ("${_iter}" IN_LIST _options)
        list(APPEND _arg_list "--${_key}")
      elseif ("${_iter}" IN_LIST _one_value_keyword)
        continue ()
      else ()
        message(FATAL_ERROR "Unknown ${_iter} keyword")
      endif ()
    endif ()
  endforeach ()

  if (_output AND NOT IS_ABSOLUTE "${_output}")
    set(_output "${_work_dir}/${_output}")
  endif ()

  add_custom_command(COMMAND "${NODE_EXECUTABLE}" "${WASMUX_SCRIPT_DIR}/JaveScriptLoader.mjs" ${_arg_list}
    DEPENDS
      "${_script}"
      "${_input}"
    OUTPUT
      "${_output}"
    WORKING_DIRECTORY
      "${_work_dir}"
    VERBATIM
    )
endfunction ()

macro(GEN_KSYSCALLHDR)
  add_custom_javescript("${WASMUX_SCRIPT_DIR}/run/ksyscallhdr.js" "" "INPUT;OUTPUT;WORK_DIR" ${ARGN})
endmacro()

macro(GEN_KUTSVERSION)
  add_custom_javescript("${WASMUX_SCRIPT_DIR}/run/utsversion.js" "" "OUTPUT;WORK_DIR" ${ARGN})
endmacro()

macro(GEN_KWEBCALLHDR)
  add_custom_javescript("${WASMUX_SCRIPT_DIR}/run/webcallhdr.js" "" "INPUT;OUTPUT;WORK_DIR" ${ARGN})
endmacro()

macro(GEN_KWEBCALLTBL)
  add_custom_javescript("${WASMUX_SCRIPT_DIR}/run/webcalltbl.js" "" "SIDE;INPUT;OUTPUT;WORK_DIR" ${ARGN})
endmacro()
