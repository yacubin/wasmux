export default (mk) => {
  const headers = [
    "include/bits/stdlib.h",
  ];

  const sources = [
    "src/abs.cpp",
    "src/mkostemp.cpp",
    "src/qsort.cpp",
    "src/realpath.cpp",
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
    SCRIPT_INCLUDES: [ "#include <bits/stdlib.h>" ],
  });
}
