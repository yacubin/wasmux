"use strict";

module.exports = (mk) => {
  const headers = [
    "malloc.h",
  ];

  const sources = [
    "malloc.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const malloc = mk.addStaticLibrary("malloc", headers, sources);
  malloc.addIncludes(mk.target("wauser").INCLUDES);
  malloc.addPublicIncludes(includes);
  malloc.addPublicLibraries(libraries);
  malloc.addInstallHeaders(headers);
}
