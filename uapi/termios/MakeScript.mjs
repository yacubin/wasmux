export default (mk) => {
  const headers = [
    "include/bits/termios_unistd.h",
    "include/termios.h",
  ];

  const sources = [
    "src/isatty.cpp",
    "src/tcgetpgrp.cpp",
    "src/tcsetpgrp.cpp",
    "src/termios.cpp",
    "src/ttyname.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  mk.script("<unistd.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/termios_unistd.h>" ],
  });

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
