export default (mk) => {
  const headers = [
    "include/sys/signalfd.h",
    "include/signal.h",
  ];

  const sources = [
    "src/sys/signalfd.c",
    "src/sigemptyset.c",
    "src/signal.c",
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
