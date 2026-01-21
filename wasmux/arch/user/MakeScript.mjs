export default (mk) => {
  const headers = [
    "include/wasmux/arch/log.h",
    "include/wasmux/arch/mm.h",
    "include/wasmux/arch/string.h",
    "include/wasmux/arch/syscalls.h",
    "include/wasmux/arch/unistd.h",
  ];

  const sources = [
  ];

  const includes = [
    mk.BINARY_DIR.join("include"),
    mk.SOURCE_DIR.join("include"),
  ];

  const arch_syscall_h = mk.BINARY_DIR.join("include/wasmux/arch/arch-syscall.h");
  mk.addCustomScript("include/wasmux/arch/arch-syscall.h.mjs", {
    SCRIPT_NAME: "<wasmux/arch/arch-syscall.h>",
    SCRIPT_INPUT: mk.PROJECT_SOURCE_DIR.join("data/syscall.js"),
    SCRIPT_OUTPUT: arch_syscall_h,
  });

  mk.target("wasmux").addSources(headers, sources, arch_syscall_h);
  mk.target("wasmux").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
  mk.install(arch_syscall_h, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: mk.BINARY_DIR.join("include"),
  });
}
