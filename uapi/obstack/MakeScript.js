"use strict";

module.exports = (mk) => {
  const headers = [
    "include/bits/__obstack_version.h",
    "include/obstack.h",
  ];

  const sources = [
    "src/obstack.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const obstack = mk.addStaticLibrary("obstack", headers, sources);
  obstack.addIncludes(mk.target("libc").includes);
  obstack.addPublicIncludes(includes);
  obstack.addPublicLibraries(libraries);
  obstack.getSourceFiles(headers).setInstallBaseDir("include");
  obstack.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.script("<gnu-versions.h>").addProperty("GNU_VERSIONS_INCLUDE_LIST", "#include <bits/__obstack_version.h>");

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
