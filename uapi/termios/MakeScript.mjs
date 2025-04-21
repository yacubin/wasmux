export default (mk) => {
  const headers = [
    "include/termios.h",
  ];

  const sources = [
    "src/isatty.cpp",
    "src/tcgetpgrp.cpp",
    "src/termios.cpp",
    "src/ttyname.cpp",
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
