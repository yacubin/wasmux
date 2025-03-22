"use strict";

module.exports = (mk) => {
  const headers = [
    "include/libintl.h",
  ];

  const sources = [
    "src/libintl.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const libintl = mk.addStaticLibrary("libintl", headers, sources);
  libintl.addIncludes(mk.target("libc").includes);
  libintl.addPublicIncludes(includes);
  libintl.addPublicLibraries(libraries);
  libintl.setPrefix("");
  libintl.getSourceFiles(headers).setInstallBaseDir("include");
  libintl.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
