export default (mk) => {
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
    mk.target("wabase"),
  ];

  const libcxx = mk.addStaticLibrary("libcxx", headers, sources);
  libcxx.addIncludes(includes);
  libcxx.addLibraries(libraries);
  libcxx.setOutputName("c++");
  libcxx.getSourceFiles("stub/new.cpp").addCompileFlags("-fvisibility-global-new-delete=force-hidden");

  mk.install(libcxx, mk.INSTALL_LIBDIR);
}
