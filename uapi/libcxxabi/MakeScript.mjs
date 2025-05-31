export default (mk) => {
  const headers = [
  ];

  const sources = [
    "stub/__cxa_demangle.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wasmux"),
  ];

  const libcxxabi = mk.addStaticLibrary("libcxxabi", headers, sources);
  libcxxabi.addIncludes(includes);
  libcxxabi.addLibraries(libraries);
  libcxxabi.setOutputName("c++abi");

  mk.install(libcxxabi, mk.INSTALL_LIBDIR);
}
