export default (mk) => {
  const headers = [
    "include/bits/time_base.h",
  ];

  const sources = [
    "src/clock_getres.cpp",
    "src/clock_gettime.cpp",
    "src/clock_nanosleep.cpp",
  ];

  const libraries = [
    mk.target("wasmux"),
    mk.target("libc"),
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  mk.script("<time.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/time_base.h>" ],
  });

  const time = mk.addObjectLibrary("time", headers, sources);
  time.addIncludes(includes);
  time.addLibraries(libraries);

  const builtin = mk.WASMUX_TIME_WITH_RT ? "rt" : "libc";
  mk.target(builtin).addSources(mk.target("time").objects);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
