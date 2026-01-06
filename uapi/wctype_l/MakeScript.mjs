export default (mk) => {
  const headers = [
    "include/bits/wctype_l.h",
  ];

  const sources = [
    "src/iswalnum_l.c",
    "src/iswalpha_l.c",
    "src/iswblank_l.c",
    "src/iswcntrl_l.c",
    "src/iswctype_l.c",
    "src/iswdigit_l.c",
    "src/iswgraph_l.c",
    "src/iswlower_l.c",
    "src/iswprint_l.c",
    "src/iswpunct_l.c",
    "src/iswspace_l.c",
    "src/iswupper_l.c",
    "src/iswxdigit_l.c",
    "src/towlower_l.c",
    "src/towupper_l.c",
    "src/wctype_l.c",
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

  mk.script("<wctype.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/wctype_l.h>" ],
  });
}
