"use strict";

module.exports = (mk) => {
  const headers = [
    "include/fts.h",
  ];

  const sources = [
    "src/fts.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const fts = mk.addStaticLibrary("fts", headers, sources);
  fts.addIncludes(mk.target("libc").includes);
  fts.addPublicIncludes(includes);
  fts.addPublicLibraries(libraries);
  fts.getSourceFiles(headers).setInstallBaseDir("include");
  fts.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
