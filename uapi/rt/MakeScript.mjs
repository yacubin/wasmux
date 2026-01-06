export default (mk) => {
  const headers = [
  ];

  const sources = [
    "src/dummy.c",
  ];

  const libraries = [
    mk.target("wasmux"),
    mk.target("libc"),
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const rt = mk.addStaticLibrary("rt", headers, sources);
  rt.addPublicIncludes(includes);
  rt.addLibraries(libraries);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
  mk.install(rt, mk.INSTALL_LIBDIR);
}
