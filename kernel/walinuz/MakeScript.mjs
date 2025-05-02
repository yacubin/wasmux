export default (mk) => {
  const headers = [
  ];

  const sources = [
    "src/InstanceExit.cpp",
    "src/InstancePerform.cpp",
    "src/StartKernel.cpp",
    "src/KernelVersion.cpp",
    "src/syscall-stub.cpp",
    "src/syscall.cpp",
  ];

  const includes = [
    mk.BINARY_DIR.join("include"),
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wacore"),
  ];

  if (mk.SYSTEM_PROCESSOR.match(/wasm(32|64)/)) {
    sources.push("src/StartKernel.S");
  }

  if (mk.SYSTEM_NAME === "Windows") {
    sources.push(
      "src/StartWindows.cpp",
      "src/walinuz.lds",
    );
    mk.EXE_LINKER_FLAGS.push(
      "-Wl,--stack,65536",
      "-Wl,--script=" + mk.SOURCE_DIR.join("src/walinuz.lds"),
    );
  }

  mk.EXE_LINKER_FLAGS.push(
    "-Wl,--Map=" + mk.BINARY_DIR.join("walinuz.map"),
  );

  const walinuz = mk.addExecutable("walinuz", headers, sources);
  walinuz.addIncludes(includes);
  walinuz.addLibraries(libraries);

  mk.install(walinuz, "/boot");

  if (mk.SYSTEM_PROCESSOR.match(/wasm(32|64)/)) {
    walinuz.addLinkOptions(
      "-Wl,--export=_start_kernel",
      "-Wl,--export=WEI_perform",
      "-Wl,--export=WEI_exit",
    );

    const waeditor = mk.findProgram("waeditor");
    if (waeditor) {
      
    }
  }
}
