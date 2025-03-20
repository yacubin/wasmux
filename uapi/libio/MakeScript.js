"use strict";

module.exports = (mk) => {
  const headers = [
    "include/bits/file_struct.h",
    "include/libio_wchar.h",
    "include/stdio.h",
    "include/stdio_ext.h",
  ];

  const sources = [
    "src/_stdio.cpp",
    "src/flockfile.cpp",
    "src/fprintf.cpp",
    "src/ftrylockfile.cpp",
    "src/funlockfile.cpp",
    "src/getc_unlocked.cpp",
    "src/getdelim.cpp",
    "src/getline.cpp",
    "src/libio_wchar.cpp",
    "src/putc.cpp",
    "src/setvbuf.cpp",
    "src/sprintf.cpp",
    "src/stdio_ext.cpp",
    "src/stdio.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wauser"),
  ];

  const libio = mk.addStaticLibrary("libio", headers, sources);
  libio.addIncludes(mk.target("libc").includes);
  libio.addPublicIncludes(includes);
  libio.addPublicLibraries(libraries);
  libio.getSourceFiles(headers).setInstallBaseDir("include");
  libio.getSourceFiles(headers).setInstallDestination(mk.INSTALL_INCLUDEDIR);

  mk.target("libc").addSource(headers, sources);
  mk.target("libc").addPublicIncludes(includes);
}
