"use strict";

module.exports = (mk) => {
  const headers = [
  ];

  const sources = [
    "stub/__cxa_atexit.cpp",
    "stub/__cxa_pure_virtual.cpp",
    "stub/new.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const libcxx = mk.addStaticLibrary("libcxx", headers, sources);
  libcxx.addIncludes(includes);
  libcxx.addLibraries(libraries);
  libcxx.addInstallDestination(mk.INSTALL_LIBDIR);
  libcxx.OUTPUT_NAME = "c++";
  libcxx.getSourceFiles("stub/new.cpp").addCompileFlags("-fvisibility-global-new-delete=force-hidden");
}
