"use strict";

module.exports = (mk) => {
  mk.addCacheVariables("data/variables.js");

  mk.MODULE_PATH.push(mk.PROJECT_SOURCE_DIR.join("scripts"));

  mk.INSTALL_BINDIR = "bin";
  mk.INSTALL_LIBDIR = "lib";
  mk.INSTALL_INCLUDEDIR = "include";

  mk.ASM_FLAGS.push("-D__ASSEMBLY__");

  mk.executeScript("wasmux-config.h.js", {
    input: mk.getCacheVariables(),
    output: mk.BINARY_DIR.join("wasmux-config.h"),
  });

  mk.addIncludeDirectories(mk.BINARY_DIR);

  mk.addSubdirectory("waf");
  mk.addSubdirectory("uapi");
  mk.addSubdirectory("kernel");
  mk.addSubdirectory("tools");
}
