"use strict";

module.exports = (mk) => {
  const headers = [
    "include/dlfcn.h",
  ];

  const sources = [
    "src/dlfcn.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const dl = mk.addStaticLibrary("dl", headers, sources);
  dl.addPublicIncludes(includes);
  dl.addPublicLibraries(libraries);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
  mk.install(dl, mk.INSTALL_LIBDIR);
}
