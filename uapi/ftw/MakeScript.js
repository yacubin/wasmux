"use strict";

module.exports = (mk) => {
  const headers = [
    "include/ftw.h",
  ];

  const sources = [
    "src/ftw.cpp",
    "src/nftw.cpp",
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
}
