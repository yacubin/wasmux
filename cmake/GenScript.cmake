find_program(NODE_EXECUTABLE node REQUIRED)
get_filename_component(__gen_scripts_node_scripts_dir "${CMAKE_CURRENT_LIST_DIR}/../scripts" ABSOLUTE)

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
