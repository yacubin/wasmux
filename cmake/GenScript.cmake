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

macro(GEN_USYSCALLHDR)
  add_custom_javescript("${WASMUX_SCRIPT_DIR}/run/usyscallhdr.js" "" "INPUT;OUTPUT;WORK_DIR" ${ARGN})
endmacro()

macro(GEN_KWEBCALLHDR)
  add_custom_javescript("${WASMUX_SCRIPT_DIR}/run/webcallhdr.js" "" "INPUT;OUTPUT;WORK_DIR" ${ARGN})
endmacro()

macro(GEN_KWEBCALLTBL)
  add_custom_javescript("${WASMUX_SCRIPT_DIR}/run/webcalltbl.js" "" "SIDE;INPUT;OUTPUT;WORK_DIR" ${ARGN})
endmacro()

macro(GEN_KWEBCALLESX)
  add_custom_javescript("${WASMUX_SCRIPT_DIR}/run/webcallesx.js" "" "SIDE;INPUT;OUTPUT;WORK_DIR" ${ARGN})
endmacro()

macro (GEN_WACUSTSEC)
  add_custom_javescript("${WASMUX_SCRIPT_DIR}/run/wacustsec.js" "" "CPU;SECTION;INPUT;OUTPUT;WORK_DIR" ${ARGN})
endmacro ()

macro(GEN_ERRNO_HEADER)
  add_custom_javescript("${WASMUX_SCRIPT_DIR}/run/GenErrnoHeader.mjs" "" "INPUT;OUTPUT;WORK_DIR" ${ARGN})
endmacro()
