export default (mk) => {
  const headers = [
    "include/bits/__getopt_base.h",
    "include/getopt.h",
  ];

  const sources = [
    "src/getopt.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  mk.script("<gnu-versions.h>").mergeVariables({
    SCRIPT_DEFINES: [ "#define _GNU_GETOPT_INTERFACE_VERSION 2" ],
  });
  mk.script("<unistd.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/__getopt_base.h>" ],
  });

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
