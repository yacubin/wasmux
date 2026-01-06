export default (mk) => {
  const headers = [
    "include/bits/wchar.h",
  ];

  const sources = [
    "src/wcscoll.c",
    "src/wcswidth.c",
    "src/wcwidth.c",
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

  mk.script("<wchar.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/wchar.h>" ],
  });
}
