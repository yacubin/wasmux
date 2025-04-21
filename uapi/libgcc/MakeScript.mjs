export default (mk) => {
  const headers = [
    "include/fp_lib.h",
  ];

  const sources = [
    "src/fp_lib.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wabase"),
  ];

  const libgcc = mk.addStaticLibrary("libgcc", headers, sources);
  libgcc.addIncludes(includes);
  libgcc.addLibraries(libraries);
  libgcc.setPrefix("");

  mk.install(libgcc, mk.INSTALL_LIBDIR);
}
