macro(__gen_script_output_impl _script)
  cmake_parse_arguments(__gen_${_script}
    ""
    "OUTPUT"
    ""
    ${ARGN}
    )
  add_custom_command(COMMAND "${NODE_EXECUTABLE}"
      "${WASMUX_SCRIPT_DIR}/run/${_script}.js"
      "${__gen_${_script}_OUTPUT}"
    DEPENDS
      "${WASMUX_SCRIPT_DIR}/run/${_script}.js"
    OUTPUT
      "${__gen_${_script}_OUTPUT}"
    WORKING_DIRECTORY
      "${CMAKE_CURRENT_BINARY_DIR}"
    VERBATIM
    )
endmacro()

macro(GEN_KUTSVERSION)
  __gen_script_output_impl(utsversion ${ARGN})
endmacro()

macro(__gen_syscallhdr_impl _script)
  cmake_parse_arguments(__gen_${_script}
    ""
    "INPUT;OUTPUT"
    ""
    ${ARGN}
    )
  add_custom_command(COMMAND "${NODE_EXECUTABLE}"
      "${WASMUX_SCRIPT_DIR}/run/${_script}.js"
      "${__gen_${_script}_INPUT}"
      "${__gen_${_script}_OUTPUT}"
    DEPENDS
      "${WASMUX_SCRIPT_DIR}/run/${_script}.js"
      "${__gen_${_script}_INPUT}"
    OUTPUT
      "${__gen_${_script}_OUTPUT}"
    WORKING_DIRECTORY
      "${CMAKE_CURRENT_BINARY_DIR}"
    VERBATIM
    )
endmacro()

function (add_custom_javescript _script _options _one_value_keyword)
  set(_input "")
  set(_output "")
  set(_arg_list "--script=${_script}")

  set(_key "")
  foreach (_iter ${ARGN})
    if (_key)
      list(APPEND _arg_list "--${_key}=${_iter}")
      if ("${_key}" STREQUAL input)
        set(_input "${_iter}")
      elseif ("${_key}" STREQUAL output)
        set(_output "${_iter}")
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

  add_custom_command(COMMAND "${NODE_EXECUTABLE}" "${WASMUX_SCRIPT_DIR}/JaveScriptLoader.mjs" ${_arg_list}
    DEPENDS
      "${_script}"
      "${_input}"
    OUTPUT
      "${_output}"
    WORKING_DIRECTORY
      "${CMAKE_CURRENT_BINARY_DIR}"
    VERBATIM
    )
endfunction ()

macro(GEN_KSYSCALLHDR)
  add_custom_javescript("${WASMUX_SCRIPT_DIR}/run/ksyscallhdr.js" "" "INPUT;OUTPUT" ${ARGN})
endmacro()

macro(GEN_USYSCALLHDR)
  add_custom_javescript("${WASMUX_SCRIPT_DIR}/run/usyscallhdr.js" "" "INPUT;OUTPUT" ${ARGN})
endmacro()

macro(GEN_KWEBCALLHDR)
  add_custom_javescript("${WASMUX_SCRIPT_DIR}/run/webcallhdr.js" "" "INPUT;OUTPUT" ${ARGN})
endmacro()

macro(GEN_KWEBCALLTBL)
  add_custom_javescript("${WASMUX_SCRIPT_DIR}/run/webcalltbl.js" "" "SIDE;INPUT;OUTPUT" ${ARGN})
endmacro()

macro(GEN_KWEBCALLESX)
  add_custom_javescript("${WASMUX_SCRIPT_DIR}/run/webcallesx.js" "" "SIDE;INPUT;OUTPUT" ${ARGN})
endmacro()

macro (GEN_WACUSTSEC)
  add_custom_javescript("${WASMUX_SCRIPT_DIR}/run/wacustsec.js" "" "CPU;SECTION;INPUT;OUTPUT" ${ARGN})
endmacro ()
