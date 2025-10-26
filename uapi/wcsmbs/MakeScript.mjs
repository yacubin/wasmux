export default (mk) => {
  const headers = [
    "include/bits/stdlib_wcsmbs.h",
    "include/bits/wchar_wcsmbs.h",
  ];

  const sources = [
    "src/btowc.c",
    "src/mblen.c",
    "src/mbrlen.c",
    "src/mbrtowc.c",
    "src/mbsinit.c",
    "src/mbsnrtowcs.c",
    "src/mbsrtowcs.c",
    "src/mbstowcs.c",
    "src/mbtowc.c",
    "src/wcrtomb.c",
    "src/wcscat.c",
    "src/wcschr.c",
    "src/wcscmp.c",
    "src/wcscpy.c",
    "src/wcslen.c",
    "src/wcsncmp.c",
    "src/wcsncpy.c",
    "src/wcsrtombs.c",
    "src/wcstombs.c",
    "src/wctob.c",
    "src/wctomb.c",
    "src/wmemchr.c",
    "src/wmemcpy.c",
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
