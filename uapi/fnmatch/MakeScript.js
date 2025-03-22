"use strict";

module.exports = (mk) => {
  const headers = [
    "include/fnmatch.h",
  ];

  const sources = [
    "src/fnmatch.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const fnmatch = mk.addStaticLibrary("fnmatch", headers, sources);
  fnmatch.addIncludes(mk.target("libc").includes);
  fnmatch.addPublicIncludes(includes);
  fnmatch.addPublicLibraries(libraries);
  fnmatch.getSourceFiles(headers).setInstallBaseDir("include");
  fnmatch.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
