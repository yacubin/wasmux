"use strict";

module.exports = (mk) => {
  const sources = [
    "waeditor.cpp",
  ];

  const includes = [
    mk.BINARY_DIR.join("include"),
    mk.SOURCE_DIR.join("include"),
  ];

  const libraries = [
    mk.target("wasmux"),
  ];

  const waeditor = mk.addExecutable("waeditor", sources);
  waeditor.addIncludes(includes);
  waeditor.addLibraries(libraries);

  mk.install(waeditor, mk.INSTALL_BINDIR);
}
