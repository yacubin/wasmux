"use strict";

module.exports = (mk) => {
  const headers = [
    "include/dlfcn.h",
  ];

  const sources = [
    "src/dlfcn.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const dl = mk.addStaticLibrary("dl", headers, sources);
  dl.addPublicIncludes(includes);
  dl.addPublicLibraries(libraries);
  dl.addInstallDestination(mk.INSTALL_LIBDIR);
  dl.getSourceFiles(headers).setInstallBaseDir("include");
  dl.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);
}
