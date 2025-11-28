export default (mk) => {
  const headers = [
    "include/glob.h",
  ];

  const sources = [
    "src/glob.c",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  mk.script("<gnu-versions.h>").mergeVariables({
    SCRIPT_DEFINES: [ "#define _GNU_GLOB_INTERFACE_VERSION 2" ],
  });

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
