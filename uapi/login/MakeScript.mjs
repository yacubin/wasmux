export default (mk) => {
  const headers = [
    "include/utmp.h",
    "include/utmpx.h",
  ];

  const sources = [
    "src/utmp.c",
    "src/utmpx.c",
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
