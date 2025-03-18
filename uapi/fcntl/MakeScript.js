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
    mk.target("libc").includes(),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const fcntl = mk.addStaticLibrary("fcntl", headers, sources);
  fcntl.addPublicIncludes(includes);
  fcntl.addPublicLibraries(libraries);
  fcntl.getSourceFiles(headers).setInstallBaseDir("include");
  fcntl.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);
}
