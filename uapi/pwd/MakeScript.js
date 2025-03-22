"use strict";

module.exports = (mk) => {
  const headers = [
    "include/pwd.h",
  ];

  const sources = [
    "src/pwd.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const pwd = mk.addStaticLibrary("pwd", headers, sources);
  pwd.addIncludes(mk.target("libc").includes);
  pwd.addPublicIncludes(includes);
  pwd.addPublicLibraries(libraries);
  pwd.getSourceFiles(headers).setInstallBaseDir("include");
  pwd.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
