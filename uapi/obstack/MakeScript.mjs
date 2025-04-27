export default (mk) => {
  const headers = [
    "include/bits/__obstack_version.h",
    "include/obstack.h",
  ];

  const sources = [
    "src/obstack.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  mk.script("<gnu-versions.h>").mergeVariables({
    GNU_VERSIONS_INCLUDE_LIST: [ "#include <bits/__obstack_version.h>" ],
  });

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
