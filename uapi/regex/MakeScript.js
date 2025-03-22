"use strict";

module.exports = (mk) => {
  const headers = [
    "include/bits/__regex_version.h",
    "include/regex.h",
  ];

  const sources = [
    "src/regex.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const regex = mk.addStaticLibrary("regex", headers, sources);
  regex.addIncludes(mk.target("libc").includes);
  regex.addPublicIncludes(includes);
  regex.addPublicLibraries(libraries);
  regex.getSourceFiles(headers).setInstallBaseDir("include");
  regex.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.script("<gnu-versions.h>").addProperty("GNU_VERSIONS_INCLUDE_LIST", "#include <bits/__regex_version.h>");

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
