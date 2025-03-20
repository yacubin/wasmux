"use strict";

module.exports = (mk) => {
  const headers = [
    "include/shadow.h",
  ];

  const sources = [
    "src/shadow.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const shadow = mk.addStaticLibrary("shadow", headers, sources);
  shadow.addIncludes(mk.target("libc").includes);
  shadow.addPublicIncludes(includes);
  shadow.addPublicLibraries(libraries);
  shadow.getSourceFiles(headers).setInstallBaseDir("include");
  shadow.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);
}
