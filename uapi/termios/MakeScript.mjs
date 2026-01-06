export default (mk) => {
  const headers = [
    "include/bits/termios_unistd.h",
    "include/termios.h",
  ];

  const sources = [
    "src/isatty.c",
    "src/tcgetpgrp.c",
    "src/tcsetpgrp.c",
    "src/termios.c",
    "src/ttyname.c",
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
