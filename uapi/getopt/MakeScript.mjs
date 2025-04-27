export default (mk) => {
  const headers = [
    "include/bits/__getopt_version.h",
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
    GNU_VERSIONS_INCLUDE_LIST: [ "#include <bits/__getopt_version.h>" ],
  });
  mk.script("<unistd.h>").mergeVariables({
    UNISTD_INCLUDE_LIST: [ "#include <bits/__getopt_base.h>" ],
  });

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
