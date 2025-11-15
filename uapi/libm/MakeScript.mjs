export default (mk) => {
  const headers = [
    "include/math.h",
  ];

  const sources = [
    "src/math.c",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wasmux"),
    mk.target("libc"),
  ];

  const libm = mk.addStaticLibrary("libm", headers, sources);
  libm.addPublicIncludes(includes);
  libm.addLibraries(libraries);
  libm.setPrefix("");

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
  mk.install(libm, mk.INSTALL_LIBDIR);
}
