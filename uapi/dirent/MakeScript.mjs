export default (mk) => {
  const headers = [
    "include/dirent.h",
  ];

  const sources = [
    "internal/dirent.h",
    "src/dirent.c",
    "src/dirfd.c",
    "src/getdents.c",
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
