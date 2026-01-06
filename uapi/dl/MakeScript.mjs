export default (mk) => {
  const headers = [
    "include/dlfcn.h",
  ];

  const sources = [
    "src/dlfcn.c",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wasmux"),
    mk.target("libc"),
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
