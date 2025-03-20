"use strict";

module.exports = (mk) => {
  const headers = [
    "include/netdb.h",
  ];

  const sources = [
    "src/netdb.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const netdb = mk.addStaticLibrary("netdb", headers, sources);
  netdb.addIncludes(mk.target("libc").includes);
  netdb.addPublicIncludes(includes);
  netdb.addPublicLibraries(libraries);
  netdb.getSourceFiles(headers).setInstallBaseDir("include");
  netdb.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);
}
