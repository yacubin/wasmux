export default (mk) => {
  const headers = [
    "include/bits/rt_base.h",
  ];

  const sources = [
    "src/dummy.cpp",
  ];

  const libraries = [
    mk.target("wasmux"),
    mk.target("libc"),
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  mk.script("<time.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/rt_base.h>" ],
  });

  const clockSources = [
    "src/clock_getres.cpp",
    "src/clock_gettime.cpp",
    "src/clock_nanosleep.cpp",
  ];

  if (mk.WASMUX_RT_CLOCK_WITH_LIBC)
    mk.target("libc").addSources(clockSources);
  else
    sources.push(...clockSources);

  mk.target("libc").addPublicIncludes(includes);

  const rt = mk.addStaticLibrary("rt", headers, sources);
  rt.addPublicIncludes(includes);
  rt.addLibraries(libraries);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
  mk.install(rt, mk.INSTALL_LIBDIR);
}
