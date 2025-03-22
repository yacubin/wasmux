"use strict";

module.exports = (mk) => {
  const headers = [
    "include/wordexp.h",
  ];

  const sources = [
    "src/wordexp.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const wordexp = mk.addStaticLibrary("wordexp", headers, sources);
  wordexp.addIncludes(mk.target("libc").includes);
  wordexp.addPublicIncludes(includes);
  wordexp.addPublicLibraries(libraries);
  wordexp.getSourceFiles(headers).setInstallBaseDir("include");
  wordexp.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
