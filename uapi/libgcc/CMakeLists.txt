add_library(libgcc STATIC $<TARGET_OBJECTS:ti128> MakeScript.mjs)
target_compile_options(libgcc PRIVATE -nostdinc)
set_target_properties(libgcc PROPERTIES PREFIX "" IMPORT_PREFIX "")
