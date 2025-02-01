if (CONFIG_ENABLE_KERNEL)
  if (CONFIG_WAML_PATH)
    list(APPEND KERNEL_DEPENDENCIES waml)
    add_subdirectory("${CONFIG_WAML_PATH}" waml)
  endif ()

  if (CONFIG_JSDATA_PATH)
    list(APPEND KERNEL_DEPENDENCIES jsdata)
    add_subdirectory("${CONFIG_JSDATA_PATH}" jsdata)
  endif ()

  add_subdirectory(kernel)
endif ()
