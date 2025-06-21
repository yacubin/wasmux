export default (mk) => {
  const headers = [
    "include/bits/ctype.h",
  ];

  const sources = [
    "src/isalnum.cpp",
    "src/isalpha.cpp",
    "src/isascii.cpp",
    "src/isblank.cpp",
    "src/iscntrl.cpp",
    "src/isdigit.cpp",
    "src/isgraph.cpp",
    "src/islower.cpp",
    "src/isprint.cpp",
    "src/ispunct.cpp",
    "src/isspace.cpp",
    "src/isupper.cpp",
    "src/isxdigit.cpp",
    "src/tolower.cpp",
    "src/toupper.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });

  mk.script("<ctype.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/ctype.h>" ],
  });
}
