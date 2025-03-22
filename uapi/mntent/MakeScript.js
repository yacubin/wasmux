"use strict";

module.exports = (mk) => {
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

  const libraries = [
    mk.target("wauser"),
  ];

  const mntent = mk.addStaticLibrary("mntent", headers, sources);
  mntent.addIncludes(mk.target("libc").includes);
  mntent.addPublicIncludes(includes);
  mntent.addPublicLibraries(libraries);
  mntent.getSourceFiles(headers).setInstallBaseDir("include");
  mntent.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
