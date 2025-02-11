get_filename_component(__gen_scripts_node_scripts_dir "${CMAKE_CURRENT_LIST_DIR}/../scripts" ABSOLUTE)

macro(__gen_script_output_impl _script)
  cmake_parse_arguments(__gen_${_script}
    ""
    "OUTPUT"
    ""
    ${ARGN}
    )
  add_custom_command(COMMAND "${NODE_EXECUTABLE}"
      "${__gen_scripts_node_scripts_dir}/run/${_script}.js"
      "${__gen_${_script}_OUTPUT}"
    DEPENDS
      "${__gen_scripts_node_scripts_dir}/run/${_script}.js"
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
      "${__gen_scripts_node_scripts_dir}/run/${_script}.js"
      "${__gen_${_script}_INPUT}"
      "${__gen_${_script}_OUTPUT}"
    DEPENDS
      "${__gen_scripts_node_scripts_dir}/run/${_script}.js"
      "${__gen_${_script}_INPUT}"
    OUTPUT
      "${__gen_${_script}_OUTPUT}"
    WORKING_DIRECTORY
      "${CMAKE_CURRENT_BINARY_DIR}"
    VERBATIM
    )
endmacro()

macro(GEN_KSYSCALLHDR)
  __gen_syscallhdr_impl(ksyscallhdr ${ARGN})
endmacro()

macro(GEN_USYSCALLHDR)
  __gen_syscallhdr_impl(usyscallhdr ${ARGN})
endmacro()

macro(GEN_KWEBCALLHDR)
  __gen_syscallhdr_impl(webcallhdr ${ARGN})
endmacro()

macro(__gen_kwebcallxxx_impl _script)
  cmake_parse_arguments(__gen_${_script}
    ""
    "SIDE;INPUT;OUTPUT"
    ""
    ${ARGN}
    )
  add_custom_command(COMMAND "${NODE_EXECUTABLE}"
      "${__gen_scripts_node_scripts_dir}/run/${_script}.js"
      "${__gen_${_script}_SIDE}"
      "${__gen_${_script}_INPUT}"
      "${__gen_${_script}_OUTPUT}"
    DEPENDS
      "${__gen_scripts_node_scripts_dir}/run/${_script}.js"
      "${__gen_${_script}_INPUT}"
    OUTPUT
      "${__gen_${_script}_OUTPUT}"
    WORKING_DIRECTORY
      "${CMAKE_CURRENT_BINARY_DIR}"
    VERBATIM
    )
endmacro()

macro(GEN_KWEBCALLTBL)
  __gen_kwebcallxxx_impl(webcalltbl ${ARGN})
endmacro()

macro(GEN_KWEBCALLESX)
  __gen_kwebcallxxx_impl(webcallesx ${ARGN})
endmacro()

macro(__gen_wacustsec_impl _script)
  cmake_parse_arguments(__gen_${_script}
    ""
    "CPU;SECTION;INPUT;OUTPUT"
    ""
    ${ARGN}
    )
  add_custom_command(COMMAND "${NODE_EXECUTABLE}"
      "${__gen_scripts_node_scripts_dir}/run/${_script}.js"
      "${__gen_${_script}_CPU}"
      "${__gen_${_script}_SECTION}"
      "${__gen_${_script}_INPUT}"
      "${__gen_${_script}_OUTPUT}"
    DEPENDS
      "${__gen_scripts_node_scripts_dir}/run/${_script}.js"
      "${__gen_${_script}_INPUT}"
    OUTPUT
      "${__gen_${_script}_OUTPUT}"
    WORKING_DIRECTORY
      "${CMAKE_CURRENT_BINARY_DIR}"
    VERBATIM
    )
endmacro()

function (execute_javescript _script _options _one_value_keyword)
  set(_input "")
  set(_output "")
  set(_arg_list "")

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

  add_custom_command(COMMAND "${NODE_EXECUTABLE}" "${__gen_scripts_node_scripts_dir}/ExecuteLoader.mjs"
      "${_script}" ${_arg_list}
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

macro (GEN_WACUSTSEC)
  execute_javescript("${__gen_scripts_node_scripts_dir}/run/wacustsec.js"
    "" "CPU;SECTION;INPUT;OUTPUT" ${ARGN}
    )
endmacro ()
