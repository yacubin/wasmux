export default (mk) => {
  const headers = [
    "include/sys/signalfd.h",
    "include/signal.h",
  ];

  const sources = [
    "src/sys/signalfd.cpp",
    "src/sigemptyset.cpp",
    "src/signal.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
