"use strict";

module.exports = (mk) => {
  const headers = [
    "include/utmp.h",
    "include/utmpx.h",
  ];

  const sources = [
    "src/utmp.cpp",
    "src/utmpx.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const login = mk.addStaticLibrary("login", headers, sources);
  login.addIncludes(mk.target("libc").includes);
  login.addPublicIncludes(includes);
  login.addPublicLibraries(libraries);
  login.getSourceFiles(headers).setInstallBaseDir("include");
  login.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
