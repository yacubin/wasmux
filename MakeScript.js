module.exports = (scope) => {
  scope.addVariables("data/variables.mjs");

  scope.MODULE_PATH.push(scope.PROJECT_DIR.join("scripts"));

  scope.INSTALL_BINDIR = "bin";
  scope.INSTALL_LIBDIR = "lib";
  scope.INSTALL_INCLUDEDIR = "include";

  scope.ASM_FLAGS.push("-D__ASSEMBLY__");

  scope.addIncludeDirectories(scope.CURRENT_BINARY_DIR);

  scope.addSubdirectory("waf");
  scope.addSubdirectory("uapi");
  // scope.addSubdirectory("kernel");
  scope.addSubdirectory("tools");
}
