export default (mk) => {
  const headers = [
    "include/bits/wctype.h",
  ];

  const sources = [
    "src/iswalnum.c",
    "src/iswalpha.c",
    "src/iswblank.c",
    "src/iswcntrl.c",
    "src/iswctype.c",
    "src/iswdigit.c",
    "src/iswgraph.c",
    "src/iswlower.c",
    "src/iswprint.c",
    "src/iswpunct.c",
    "src/iswspace.c",
    "src/iswupper.c",
    "src/iswxdigit.c",
    "src/towlower.c",
    "src/towupper.c",
    "src/wctype.c",
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
    SCRIPT_INCLUDES: [ "#include <bits/wctype.h>" ],
  });

  mk.script("<wchar.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/wctype.h>" ],
  });
}
