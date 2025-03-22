"use strict";

module.exports = (mk) => {
  const headers = [
    "include/semaphore.h",
  ];

  const sources = [
    "src/semaphore.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const semaphore = mk.addStaticLibrary("semaphore", headers, sources);
  semaphore.addIncludes(mk.target("libc").includes);
  semaphore.addPublicIncludes(includes);
  semaphore.addPublicLibraries(libraries);
  semaphore.getSourceFiles(headers).setInstallBaseDir("include");
  semaphore.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
