export default (mk) => {
  const headers = [
    "include/mntent.h",
  ];

  const sources = [
    "src/endmntent.c",
    "src/getmntent_r.c",
    "src/getmntent.c",
    "src/hasmntopt.c",
    "src/setmntent.c",
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
