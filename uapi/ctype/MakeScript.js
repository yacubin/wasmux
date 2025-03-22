"use strict";

module.exports = (mk) => {
  const headers = [
    "include/bits/__ctype_base.h",
  ];

  const sources = [
    "src/ctype.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const ctype = mk.addStaticLibrary("ctype", headers, sources);
  ctype.addIncludes(mk.target("libc").includes);
  ctype.addPublicIncludes(includes);
  ctype.addPublicLibraries(libraries);
  ctype.getSourceFiles(headers).setInstallBaseDir("include");
  ctype.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.script("<ctype.h>").addProperty("CTYPE_INCLUDE_LIST", "#include <bits/__ctype_base.h>");

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
