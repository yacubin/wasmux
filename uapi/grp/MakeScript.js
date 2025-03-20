"use strict";

module.exports = (mk) => {
  const headers = [
    "include/grp.h",
  ];

  const sources = [
    "src/grp.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const grp = mk.addStaticLibrary("grp", headers, sources);
  grp.addIncludes(mk.target("libc").includes);
  grp.addPublicIncludes(includes);
  grp.addPublicLibraries(libraries);
  grp.getSourceFiles(headers).setInstallBaseDir("include");
  grp.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);
}
