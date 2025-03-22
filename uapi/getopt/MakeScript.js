"use strict";

module.exports = (mk) => {
  const headers = [
    "include/bits/__getopt_version.h",
    "include/bits/__getopt_base.h",
    "include/getopt.h",
  ];

  const sources = [
    "src/getopt.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const getopt = mk.addStaticLibrary("getopt", headers, sources);
  getopt.addIncludes(mk.target("libc").includes);
  getopt.addPublicIncludes(includes);
  getopt.addPublicLibraries(libraries);
  getopt.getSourceFiles(headers).setInstallBaseDir("include");
  getopt.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.script("<gnu-versions.h>").addProperty("GNU_VERSIONS_INCLUDE_LIST", "#include <bits/__getopt_version.h>");
  mk.script("<unistd.h>").addProperty("UNISTD_INCLUDE_LIST", "#include <bits/__getopt_base.h>");

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
