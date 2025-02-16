include(CMakeParseArguments)

function (WX_INIT_VARIABLES)
  cmake_parse_arguments(__mk_var "PRINT" "INPUT;OUTPUT_HEADER;OUTPUT_OBJECT;OUTPUT_SCRIPT" "${WASMUX_CONFIG_CMAKE}" "" ${ARGN})
  set(__print_arg "")
  if (__mk_var_PRINT)
    set(__print_arg "--print")
  endif ()
  execute_process(COMMAND "${NODE_EXECUTABLE}" "${WASMUX_SCRIPT_DIR}/JaveScriptLoader.mjs"
      "--script=${WASMUX_SCRIPT_DIR}/run/InitVariables.mjs"
      "--plugin-list=${WASMUX_INJECT_SCRIPT_LIST}"
      "--input=${__mk_var_INPUT}"
      "--output-header=${__mk_var_OUTPUT_HEADER}"
      "--output-object=${__mk_var_OUTPUT_OBJECT}"
      "--output-script=${__mk_var_OUTPUT_SCRIPT}"
      ${__print_arg}
    WORKING_DIRECTORY
      "${CMAKE_CURRENT_BINARY_DIR}"
    RESULT_VARIABLE
      _result
    )
  if (_result)
    message(FATAL_ERROR "Unable to process variables")
  endif ()
endfunction ()
