export default (mk) => {
  const headers = [
    "include/wctype.h",
  ];

  const sources = [
    "src/iswalnum.cpp",
    "src/iswalpha.cpp",
    "src/iswblank.cpp",
    "src/iswcntrl.cpp",
    "src/iswctype.cpp",
    "src/iswdigit.cpp",
    "src/iswgraph.cpp",
    "src/iswlower.cpp",
    "src/iswprint.cpp",
    "src/iswpunct.cpp",
    "src/iswspace.cpp",
    "src/iswupper.cpp",
    "src/iswxdigit.cpp",
    "src/towlower.cpp",
    "src/towupper.cpp",
    "src/wctype.cpp",
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
}
