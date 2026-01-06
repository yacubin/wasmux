export default (mk) => {
  const headers = [
    "include/wasmux/arch/log.h",
    "include/wasmux/arch/string.h",
    "include/wasmux/arch/syscalls.h",
    "include/wasmux/arch/unistd.h",
  ];

  const sources = [
    "src/start_worker.cpp",
  ];

  const includes = [
    mk.BINARY_DIR.join("include"),
    mk.SOURCE_DIR.join("include"),
  ];

  mk.target("wasmux").addSources(sources, headers);
  mk.target("wasmux").addPublicIncludes(includes);
}
