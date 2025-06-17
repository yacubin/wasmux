export default (mk) => {
  const headers = [
    "include/bits/ctype.h",
  ];

  const sources = [
    "src/ctype.cpp",
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

  mk.script("<ctype.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/ctype.h>" ],
  });
}
