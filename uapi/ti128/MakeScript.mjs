export default (mk) => {
  const headers = [
    "include/ti128.h",
  ];

  const sources = [
    "src/ti128.c",
    "src/multi3.c",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wasmux"),
  ];

  const ti128 = mk.addObjectLibrary("ti128", headers, sources);
  ti128.addIncludes(includes);
  ti128.addLibraries(libraries);
}
