export default (mk) => {
  const headers = [
    "include/bits/wcsmbs_comm.h",
    "include/wcsmbs.h",
    "include/wctype.h",
  ];

  const sources = [
    "src/btowc.cpp",
    "src/mblen.cpp",
    "src/mbrlen.cpp",
    "src/mbrtowc.cpp",
    "src/mbsinit.cpp",
    "src/mbsnrtowcs.cpp",
    "src/mbsrtowcs.cpp",
    "src/mbstowcs.cpp",
    "src/mbtowc.cpp",
    "src/wcrtomb.cpp",
    "src/wcscat.cpp",
    "src/wcschr.cpp",
    "src/wcscmp.cpp",
    "src/wcscpy.cpp",
    "src/wcslen.cpp",
    "src/wcsncmp.cpp",
    "src/wcsrtombs.cpp",
    "src/wcstombs.cpp",
    "src/wctob.cpp",
    "src/wctomb.cpp",
    "src/wctype.cpp",
    "src/wmemchr.cpp",
    "src/wmemcpy.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  mk.script("<stdlib.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/wcsmbs_comm.h>" ],
  });

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
