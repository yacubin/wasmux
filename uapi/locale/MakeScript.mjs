export default (mk) => {
  const headers = [
    "include/bits/locale_category.h",
    "include/bits/locale_ctype.h",
    "include/bits/locale_struct.h",
    "include/langinfo.h",
    "include/locale.h",
  ];

  const sources = [
    "src/isalnum_l.c",
    "src/langinfo.c",
    "src/locale.c",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  mk.script("<ctype.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/locale_ctype.h>" ],
  });

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
