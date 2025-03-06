"use strict";

module.exports = (make) => {
  make.addCacheVariables("data/variables.js");

  make.MODULE_PATH.push(make.PROJECT_SOURCE_DIR.join("scripts"));

  make.INSTALL_BINDIR = "bin";
  make.INSTALL_LIBDIR = "lib";
  make.INSTALL_INCLUDEDIR = "include";

  make.ASM_FLAGS.push("-D__ASSEMBLY__");

  make.executeScript("wasmux-config.h.js", {
    input: make.getCacheVariables(),
    output: make.BINARY_DIR.join("wasmux-config.h"),
  });

  make.addIncludeDirectories(make.BINARY_DIR);

  make.addSubdirectory("waf");
  make.addSubdirectory("uapi");
  // mk.addSubdirectory("kernel");
  make.addSubdirectory("tools");
}
