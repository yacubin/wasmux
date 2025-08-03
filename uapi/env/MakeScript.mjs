export default (mk) => {
  const headers = [
    "include/bits/stdlib_env.h",
    "include/bits/unistd_env.h",
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

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });

  mk.script("<stdlib.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/stdlib_env.h>" ],
  });
  mk.script("<unistd.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/unistd_env.h>" ],
  });
}
