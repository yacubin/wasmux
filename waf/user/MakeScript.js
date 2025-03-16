"use strict";

module.exports = (mk) => {
  const headers = [
    "include/wasmux/syscalls.h",
    "include/wasmux/thread_data.h",
    "include/wasmux/waitstatus.h",
  ];

  const sources = [
    "src/thread_data.cpp",
  ];

  const includes = [
    mk.BINARY_DIR.join("include"),
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wabase"),
  ];

  const arch_syscall_h = mk.BINARY_DIR.join("include/wasmux/arch-syscall.h");
  mk.addCustomTarget("<wasmux/arch-syscall.h>", {
    script: "src/arch-syscall.h.js",
    input: mk.PROJECT_SOURCE_DIR.join("data/syscall.js"),
    output: arch_syscall_h,
  });

  const wauser = mk.addStaticLibrary("wauser", headers, sources, arch_syscall_h);
  wauser.addPublicIncludes(includes);
  wauser.addPublicLibraries(libraries);
  wauser.getSourceFiles(headers).setInstallBaseDir("include");
  wauser.getSourceFiles(arch_syscall_h).setInstallBaseDir(mk.BINARY_DIR.join("include"));
  wauser.getSourceFiles(headers, arch_syscall_h).setInstallDestination(mk.INSTALL_INCLUDEDIR);
}
