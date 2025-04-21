export default (mk) => {
  const headers = [
    "include/mntent.h",
  ];

  const sources = [
    "src/endmntent.cpp",
    "src/getmntent_r.cpp",
    "src/getmntent.cpp",
    "src/hasmntopt.cpp",
    "src/setmntent.cpp",
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
