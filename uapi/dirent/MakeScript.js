"use strict";

module.exports = (mk) => {
  const headers = [
    "include/dirent.h",
    "include/bits/__dirent_dir_struct.h",
  ];

  const sources = [
    "src/dirent.cpp",
    "src/dirfd.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const dirent = mk.addStaticLibrary("dirent", headers, sources);
  dirent.addIncludes(mk.target("libc").includes);
  dirent.addPublicIncludes(includes);
  dirent.addPublicLibraries(libraries);
  dirent.getSourceFiles(headers).setInstallBaseDir("include");
  dirent.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
