export default (mk) => {
  const headers = [
    "include/bits/time.h",
  ];

  const sources = [
    "src/clock_getres.c",
    "src/clock_gettime.c",
    "src/clock_nanosleep.c",
  ];

  const libraries = [
    mk.target("wasmux"),
    mk.target("libc"),
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

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

  mk.script("<time.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/time.h>" ],
  });
}
