export default (mk) => {
  const headers = [
    "include/bits/ctype_l.h",
  ];

  const sources = [
    "src/isalnum_l.cpp",
    "src/isalpha_l.cpp",
    "src/isascii_l.cpp",
    "src/isblank_l.cpp",
    "src/iscntrl_l.cpp",
    "src/isdigit_l.cpp",
    "src/isgraph_l.cpp",
    "src/islower_l.cpp",
    "src/isprint_l.cpp",
    "src/ispunct_l.cpp",
    "src/isspace_l.cpp",
    "src/isupper_l.cpp",
    "src/isxdigit_l.cpp",
    "src/tolower_l.cpp",
    "src/toupper_l.cpp",
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
    SCRIPT_INCLUDES: [ "#include <bits/ctype_l.h>" ],
  });
}
