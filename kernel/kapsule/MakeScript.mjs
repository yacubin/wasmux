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
    mk.target("wasmux"),
  ];

  if (mk.SYSTEM_PROCESSOR.match(/wasm(32|64)/)) {
    sources.push("src/StartKernel.S");
  }

  if (mk.SYSTEM_NAME === "Windows") {
    sources.push(
      "src/StartWindows.cpp",
      "src/kernel.lds",
    );
    mk.EXE_LINKER_FLAGS.push(
      "-Wl,--stack,65536",
      "-Wl,--script=" + mk.SOURCE_DIR.join("src/kapsule.lds"),
    );
  }

  mk.EXE_LINKER_FLAGS.push(
    "-Wl,--Map=" + mk.BINARY_DIR.join("kapsule.map"),
  );

  const kapsule = mk.addExecutable("kapsule", headers, sources);
  kapsule.addIncludes(includes);
  kapsule.addLibraries(libraries);

  mk.install(kapsule, "/boot");

  if (mk.SYSTEM_PROCESSOR.match(/wasm(32|64)/)) {
    const waeditor = mk.findProgram("waeditor");
    if (waeditor) {
      kapsule.addPostBuild(waeditor, [ "--add-user-memory", kapsule.targetFile ]);
    }
  }
}
