export default (mk) => {
  const headers = [
    "include/fcntl.h",
  ];

  const sources = [
    "internal/fcntl.h",
    "src/creat.cpp",
    "src/fcntl.cpp",
    "src/open.cpp",
    "src/openat.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("internal"),
    mk.SOURCE_DIR.join("include"),
  ];

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
