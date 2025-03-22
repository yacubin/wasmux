"use strict";

module.exports = (mk) => {
  const headers = [
    "include/bits/__glob_version.h",
    "include/glob.h",
  ];

  const sources = [
    "src/glob.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const glob = mk.addStaticLibrary("glob", headers, sources);
  glob.addIncludes(mk.target("libc").includes);
  glob.addPublicIncludes(includes);
  glob.addPublicLibraries(libraries);
  glob.getSourceFiles(headers).setInstallBaseDir("include");
  glob.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.script("<gnu-versions.h>").addProperty("GNU_VERSIONS_INCLUDE_LIST", "#include <bits/__glob_version.h>");

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
