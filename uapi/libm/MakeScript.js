"use strict";

module.exports = (mk) => {
  const headers = [
    "include/math.h",
  ];

  const sources = [
    "src/math.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
    mk.target("libc"),
  ];

  const libm = mk.addStaticLibrary("libm", headers, sources);
  libm.setPrefix("");
  libm.addIncludes(includes);
  libm.addLibraries(libraries);

  libm.addInstallDestination(mk.INSTALL_LIBDIR);
  libm.getSourceFiles(headers).setInstallBaseDir("include");
  libm.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
  mk.install(libm, mk.INSTALL_LIBDIR);
}
