"use strict";

module.exports = (mk) => {
  const headers = [
    "include/malloc.h",
  ];

  const sources = [
    "src/malloc.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
    mk.target("libc").INCLUDES,
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const malloc = mk.addStaticLibrary("malloc", headers, sources);
  malloc.addPublicIncludes(includes);
  malloc.addPublicLibraries(libraries);
  malloc.getSourceFiles(headers).setInstallBaseDir("include");
  malloc.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);
}
