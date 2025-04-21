export default (mk) => {
  const headers = [
    "include/malloc.h",
  ];

  const sources = [
    "src/malloc.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  mk.script("<stdlib.h>").addProperty("STDLIB_INCLUDE_LIST", "#include <alloca.h>", "#include <malloc.h>");

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
