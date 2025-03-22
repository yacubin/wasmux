"use strict";

module.exports = (mk) => {
  const headers = [
  ];

  const sources = [
    "stub/__cxa_demangle.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wabase"),
  ];

  const libcxxabi = mk.addStaticLibrary("libcxxabi", headers, sources);
  libcxxabi.addIncludes(includes);
  libcxxabi.addLibraries(libraries);
  libcxxabi.addInstallDestination(mk.INSTALL_LIBDIR);
  libcxxabi.setOutputName("c++abi");

  mk.install(libcxxabi, mk.INSTALL_LIBDIR);
}
