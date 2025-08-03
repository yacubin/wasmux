export default (mk) => {
  const headers = [
    "include/bits/wctype_l.h",
  ];

  const sources = [
    "src/iswalnum_l.cpp",
    "src/iswalpha_l.cpp",
    "src/iswblank_l.cpp",
    "src/iswcntrl_l.cpp",
    "src/iswctype_l.cpp",
    "src/iswdigit_l.cpp",
    "src/iswgraph_l.cpp",
    "src/iswlower_l.cpp",
    "src/iswprint_l.cpp",
    "src/iswpunct_l.cpp",
    "src/iswspace_l.cpp",
    "src/iswupper_l.cpp",
    "src/iswxdigit_l.cpp",
    "src/towlower_l.cpp",
    "src/towupper_l.cpp",
    "src/wctype_l.cpp",
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
