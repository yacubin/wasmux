"use strict";

module.exports = (mk) => {
  const headers = [
    "include/termios.h",
  ];

  const sources = [
    "src/isatty.cpp",
    "src/tcgetpgrp.cpp",
    "src/termios.cpp",
    "src/ttyname.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const termios = mk.addStaticLibrary("termios", headers, sources);
  termios.addIncludes(mk.target("libc").includes);
  termios.addPublicIncludes(includes);
  termios.addPublicLibraries(libraries);
  termios.getSourceFiles(headers).setInstallBaseDir("include");
  termios.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
