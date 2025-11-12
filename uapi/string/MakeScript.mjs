export default (mk) => {
  const headers = [
    "include/bits/string_basename.h",
    "include/libgen.h",
    "include/string.h",
    "include/strings.h",
  ];

  const sources = [
    "src/basename.c",
    "src/dirname.c",
    "src/memchr.c",
    "src/memcmp.c",
    "src/memcpy.c",
    "src/memmem.c",
    "src/memrchr.c",
    "src/memset.c",
    "src/rindex.c",
    "src/stpcpy.c",
    "src/strchrnul.c",
    "src/strcmp.c",
    "src/strcpy.c",
    "src/strdup.c",
    "src/string.c",
    "src/strncmp.c",
    "src/strncpy.c",
    "src/strrchr.c",
    "src/strsep.c",
    "src/strtok_r.c",
    "src/strverscmp.c",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const strerror_cpp = mk.BINARY_DIR.join("src/strerror.c");
  mk.addCustomScript("src/strerror.c.mjs", {
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
