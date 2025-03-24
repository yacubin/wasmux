"use strict";

module.exports = (mk) => {
  const headers = [
    "include/bits/__ctype_base.h",
  ];

  const sources = [
    "src/ctype.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  mk.script("<ctype.h>").addProperty("CTYPE_INCLUDE_LIST", "#include <bits/__ctype_base.h>");

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
