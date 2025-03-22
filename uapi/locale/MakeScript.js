"use strict";

module.exports = (mk) => {
  const headers = [
    "include/bits/locale_category.h",
    "include/bits/locale_ctype.h",
    "include/bits/locale_struct.h",
    "include/langinfo.h",
    "include/locale.h",
  ];

  const sources = [
    "src/isalnum_l.cpp",
    "src/langinfo.cpp",
    "src/locale.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const locale = mk.addStaticLibrary("locale", headers, sources);
  locale.addIncludes(mk.target("libc").includes);
  locale.addPublicIncludes(includes);
  locale.addPublicLibraries(libraries);
  locale.getSourceFiles(headers).setInstallBaseDir("include");
  locale.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.script("<ctype.h>").addProperty("CTYPE_INCLUDE_LIST", "#include <bits/locale_ctype.h>");

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
