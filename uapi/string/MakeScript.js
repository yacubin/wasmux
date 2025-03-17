"use strict";

module.exports = (mk) => {
  const headers = [
    "include/bits/__string_basename.h",
    "include/libgen.h",
    "include/string.h",
    "include/strings.h",
  ];

  const sources = [
    "src/basename.cpp",
    "src/dirname.cpp",
    "src/memchr.cpp",
    "src/memcpy.cpp",
    "src/memrchr.cpp",
    "src/memset.cpp",
    "src/rindex.cpp",
    "src/stpcpy.cpp",
    "src/strchrnul.cpp",
    "src/strdup.cpp",
    "src/string.cpp",
    "src/strrchr.cpp",
    "src/strsep.cpp",
    "src/strtok_r.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const strerror_cpp = mk.BINARY_DIR.join("src/strerror.cpp");
  mk.addCustomTarget("strerror.cpp", {
    script: "src/strerror.cpp.js",
    input: mk.PROJECT_SOURCE_DIR.join("data/errno.js"),
    output: strerror_cpp,
  });

  const string = mk.addStaticLibrary("string", headers, sources, strerror_cpp);
  string.addPublicIncludes(includes);
  string.addIncludes(mk.target("libc").INCLUDES);
  string.addPublicLibraries(libraries);
  string.getSourceFiles(headers).setInstallBaseDir("include");
  string.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);
}
