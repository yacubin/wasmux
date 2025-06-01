export default (mk) => {
  const headers = [
    "include/pthread.h",
  ];

  const sources = [
    "src/pthread.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wasmux"),
  ];

  const pthread = mk.addStaticLibrary("pthread", headers, sources);
  pthread.addPublicIncludes(includes);
  pthread.addPublicLibraries(libraries);

  if (mk.WASMUX_PTHREAD_WITH_LIBC)
    mk.target("libc").addSources(mk.target("pthread").objects);
  else
    mk.install(pthread, mk.INSTALL_LIBDIR);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
