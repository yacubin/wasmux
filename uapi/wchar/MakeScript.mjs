export default (mk) => {
  const headers = [
    "include/bits/wchar.h",
  ];

  const sources = [
    "src/wcscoll.cpp",
    "src/wcswidth.cpp",
    "src/wcwidth.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  mk.script("<wchar.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/wchar.h>" ],
  });

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
