"use strict";

module.exports = (mk) => {
  const headers = [
    "include/linux/blkpg.h",
    "include/linux/magic.h",
    "include/linux/version.h",
    "include/linux/vt.h",
  ];

  const sources = [
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
