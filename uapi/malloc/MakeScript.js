module.exports = (scope) => {
  const headers = [
    "malloc.h",
  ];

  const sources = [
    "malloc.cpp",
  ];

  const includes = [
    scope.SOURCE_DIR.join("include"),
    "${libc.INCLUDE_DIRECTORIES}",
  ];

  const libraries = [
    "wauser",
  ];

  const target = scope.addStaticLibrary("malloc");
  target.addSources(headers, sources);
  target.addIncludeDirectories(includes, { public: true });
  target.addLinkLibraries(libraries, { public: true });
  target.addInstallHeaders(headers);
}
