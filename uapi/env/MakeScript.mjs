export default (mk) => {
  const headers = [
    "include/bits/env_stdlib.h",
    "include/bits/env_unistd.h",
  ];

  const sources = [
    "src/environ.cpp",
    "src/getenv.cpp",
    "src/putenv.cpp",
    "src/setenv.cpp",
    "src/unsetenv.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  mk.script("<stdlib.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/env_stdlib.h>" ],
  });

  mk.script("<unistd.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/env_unistd.h>" ],
  });

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
