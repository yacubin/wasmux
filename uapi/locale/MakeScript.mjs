export default (mk) => {
  const headers = [
    "include/bits/locale_category.h",
    "include/bits/locale_ctype.h",
    "include/bits/locale_struct.h",
    "include/langinfo.h",
    "include/locale.h",
  ];

  const sources = [
    "src/isalnum_l.cpp",
    "src/langinfo.cpp",
    "src/locale.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  mk.script("<ctype.h>").addProperty("CTYPE_INCLUDE_LIST", "#include <bits/locale_ctype.h>");

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
