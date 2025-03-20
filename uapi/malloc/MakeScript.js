"use strict";

module.exports = (mk) => {
  const headers = [
    "include/malloc.h",
  ];

  const sources = [
    "src/malloc.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const malloc = mk.addStaticLibrary("malloc", headers, sources);
  malloc.addIncludes(mk.target("libc").includes);
  malloc.addPublicIncludes(includes);
  malloc.addPublicLibraries(libraries);
  malloc.getSourceFiles(headers).setInstallBaseDir("include");
  malloc.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.script("<stdlib.h>").addProperty("STDLIB_INCLUDE_LIST", "#include <alloca.h>", "#include <malloc.h>");

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  /*mk(headers).install({
    BASE_DIR: "include",
    DESTENATION: mk.INSTALL_INCLUDEDIR,
  });*/
}
