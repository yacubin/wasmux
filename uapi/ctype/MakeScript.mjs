export default (mk) => {
  const headers = [
    "include/bits/ctype.h",
  ];

  const sources = [
    "src/isalnum.c",
    "src/isalpha.c",
    "src/isascii.c",
    "src/isblank.c",
    "src/iscntrl.c",
    "src/isdigit.c",
    "src/isgraph.c",
    "src/islower.c",
    "src/isprint.c",
    "src/ispunct.c",
    "src/isspace.c",
    "src/isupper.c",
    "src/isxdigit.c",
    "src/tolower.c",
    "src/toupper.c",
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
