"use strict";

module.exports = (mk) => {
  const headers = [
    "include/linux/blkpg.h",
    "include/linux/magic.h",
    "include/linux/version.h",
    "include/linux/vt.h",
  ];

  const sources = [
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const ulinux = mk.addStaticLibrary("ulinux", headers, sources);
  ulinux.addIncludes(mk.target("libc").includes);
  ulinux.addPublicIncludes(includes);
  ulinux.addPublicLibraries(libraries);
  ulinux.getSourceFiles(headers).setInstallBaseDir("include");
  ulinux.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
