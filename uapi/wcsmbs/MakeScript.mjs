export default (mk) => {
  const headers = [
    "include/bits/stdlib_wcsmbs.h",
    "include/bits/wchar_wcsmbs.h",
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
    "src/wcslen.c",
    "src/wcsncmp.cpp",
    "src/wcsncpy.cpp",
    "src/wcsrtombs.cpp",
    "src/wcstombs.cpp",
    "src/wctob.cpp",
    "src/wctomb.cpp",
    "src/wmemchr.cpp",
    "src/wmemcpy.cpp",
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

  mk.script("<stdlib.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/stdlib_wcsmbs.h>" ],
  });
  mk.script("<wchar.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/wchar_wcsmbs.h>" ],
  });
}
