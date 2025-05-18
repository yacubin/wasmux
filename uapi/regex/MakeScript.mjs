export default (mk) => {
  const headers = [
    "include/regex.h",
  ];

  const sources = [
    "src/regex.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  mk.script("<gnu-versions.h>").mergeVariables({
    SCRIPT_DEFINES: [ "#define _GNU_REGEX_INTERFACE_VERSION 1" ],
  });

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
