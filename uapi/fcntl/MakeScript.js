module.exports = (scope) => {
  const fcntl = scope.addStaticLibrary("fcntl");

  const headers = fcntl.addSources(
    "include/fcntl.h",
  );

  fcntl.addSources(
    "internal/fcntl.h",
    "src/creat.cpp",
    "src/fcntl.cpp",
    "src/open.cpp",
    "src/openat.cpp",
  );

  fcntl.addPublicIncludes(
    scope.SOURCE_DIR.join("internal"),
    scope.SOURCE_DIR.join("include"),
  );

  fcntl.addPublicLibraries(
    "wauser",
  );

  fcntl.addIncludes("${libc.INCLUDE_DIRECTORIES}");
  fcntl.addInstallHeaders(headers, { baseDir: "include" });
}
