export default (mk) => {
  const headers = [
    "include/bits/__string_basename.h",
    "include/libgen.h",
    "include/string.h",
    "include/strings.h",
  ];

  const sources = [
    "src/basename.cpp",
    "src/dirname.cpp",
    "src/memchr.cpp",
    "src/memcpy.cpp",
    "src/memrchr.cpp",
    "src/memset.cpp",
    "src/rindex.cpp",
    "src/stpcpy.cpp",
    "src/strchrnul.cpp",
    "src/strdup.cpp",
    "src/string.cpp",
    "src/strrchr.cpp",
    "src/strsep.cpp",
    "src/strtok_r.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const strerror_cpp = mk.BINARY_DIR.join("src/strerror.cpp");
  mk.addCustomScript("src/strerror.cpp.js", {
    SCRIPT_INPUT: mk.PROJECT_SOURCE_DIR.join("data/errno.js"),
    SCRIPT_OUTPUT: strerror_cpp,
  });

  mk.target("libc").addSources(headers, sources, strerror_cpp);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
