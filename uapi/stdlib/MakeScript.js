"use strict";

module.exports = (mk) => {
  const headers = [
    "include/bits/__stdlib.h",
  ];

  const sources = [
    "src/abs.cpp",
    "src/mkostemp.cpp",
    "src/qsort.cpp",
    "src/realpath.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const stdlib = mk.addStaticLibrary("stdlib", headers, sources);
  stdlib.addIncludes(mk.target("libc").includes);
  stdlib.addPublicIncludes(includes);
  stdlib.addPublicLibraries(libraries);
  stdlib.getSourceFiles(headers).setInstallBaseDir("include");
  stdlib.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.script("<stdlib.h>").addProperty("STDLIB_INCLUDE_LIST", "#include <bits/__stdlib.h>");

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
