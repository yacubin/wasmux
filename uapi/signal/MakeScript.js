"use strict";

module.exports = (mk) => {
  const headers = [
    "include/sys/signalfd.h",
    "include/signal.h",
  ];

  const sources = [
    "src/sys/signalfd.cpp",
    "src/sigemptyset.cpp",
    "src/signal.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const signal = mk.addStaticLibrary("signal", headers, sources);
  signal.addIncludes(mk.target("libc").includes);
  signal.addPublicIncludes(includes);
  signal.addPublicLibraries(libraries);
  signal.getSourceFiles(headers).setInstallBaseDir("include");
  signal.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
