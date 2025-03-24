"use strict";

module.exports = (mk) => {
  const headers = [
    "include/dirent.h",
    "include/bits/__dirent_dir_struct.h",
  ];

  const sources = [
    "src/dirent.cpp",
    "src/dirfd.cpp",
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
