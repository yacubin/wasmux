"use strict";

module.exports = (mk) => {
  const headers = [
    "include/semaphore.h",
  ];

  const sources = [
    "src/semaphore.cpp",
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
