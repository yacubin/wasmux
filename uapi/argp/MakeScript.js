"use strict";

module.exports = (mk) => {
  const headers = [
    "include/argp.h",
  ];

  const sources = [
    "src/argp.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const argp = mk.addStaticLibrary("argp", headers, sources);
  argp.addIncludes(mk.target("libc").includes);
  argp.addPublicIncludes(includes);
  argp.addPublicLibraries(libraries);
  argp.getSourceFiles(headers).setInstallBaseDir("include");
  argp.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
