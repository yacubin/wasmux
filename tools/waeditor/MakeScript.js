"use strict";

module.exports = (make) => {
  const sources = [
    "waeditor.cpp",
  ];

  const includes = [
    make.BINARY_DIR.join("include"),
    make.SOURCE_DIR.join("include"),
  ];

  const waeditor = make.addExecutable("waeditor", sources);
  waeditor.addIncludes(includes);
  waeditor.addInstallDestination(make.INSTALL_BINDIR);
}
