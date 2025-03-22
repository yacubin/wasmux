"use strict";

module.exports = (mk) => {
  const headers = [
    "include/ftw.h",
  ];

  const sources = [
    "src/ftw.cpp",
    "src/nftw.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const ftw = mk.addStaticLibrary("ftw", headers, sources);
  ftw.addIncludes(mk.target("libc").includes);
  ftw.addPublicIncludes(includes);
  ftw.addPublicLibraries(libraries);
  ftw.getSourceFiles(headers).setInstallBaseDir("include");
  ftw.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
