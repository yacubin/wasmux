"use strict";

module.exports = (mk) => {
  const headers = [
    "include/pthread.h",
  ];

  const sources = [
    "src/pthread.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const pthread = mk.addStaticLibrary("pthread", headers, sources);
  pthread.addPublicIncludes(includes);
  pthread.addPublicLibraries(libraries);
  pthread.addInstallDestination(mk.INSTALL_LIBDIR);
  pthread.getSourceFiles(headers).setInstallBaseDir("include");
  pthread.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
  mk.install(pthread, mk.INSTALL_LIBDIR);
}
