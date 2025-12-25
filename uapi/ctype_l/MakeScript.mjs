export default (mk) => {
  const headers = [
    "include/bits/ctype_l.h",
  ];

  const sources = [
    "src/isalnum_l.c",
    "src/isalpha_l.c",
    "src/isascii_l.c",
    "src/isblank_l.c",
    "src/iscntrl_l.c",
    "src/isdigit_l.c",
    "src/isgraph_l.c",
    "src/islower_l.c",
    "src/isprint_l.c",
    "src/ispunct_l.c",
    "src/isspace_l.c",
    "src/isupper_l.c",
    "src/isxdigit_l.c",
    "src/tolower_l.c",
    "src/toupper_l.c",
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
