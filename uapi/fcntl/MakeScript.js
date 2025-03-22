"use strict";

module.exports = (mk) => {
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

  const libraries = [
    mk.target("wauser"),
  ];

  const fcntl = mk.addStaticLibrary("fcntl", headers, sources);
  fcntl.addPublicIncludes(includes);
  fcntl.addIncludes(mk.target("libc").includes);
  fcntl.addPublicLibraries(libraries);
  fcntl.getSourceFiles(headers).setInstallBaseDir("include");
  fcntl.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
