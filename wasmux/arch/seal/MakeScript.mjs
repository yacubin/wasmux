export default (mk) => {
  const headers = [
    "include/wasmux/arch/arch-syscall.h.mjs",
    "include/wasmux/arch/log.h",
    "include/wasmux/arch/mm.h",
    "include/wasmux/arch/string.h",
    "include/wasmux/arch/syscalls_define.h",
    "include/wasmux/arch/syscalls.h",
    "include/wasmux/arch/unistd.h",
  ];

  const sources = [
  ];

  const includes = [
    mk.BINARY_DIR.join("include"),
    mk.SOURCE_DIR.join("include"),
  ];

  mk.target("wasmux").addSources(headers, sources);
  mk.target("wasmux").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
