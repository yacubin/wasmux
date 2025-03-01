module.exports = (scope) => {
  const exec = scope.addExecutable("waeditor");

  exec.addSources([
    "waeditor.cpp",
  ]);

  exec.addIncludeDirectories([
    scope.BINARY_DIR.join("include"),
    scope.SOURCE_DIR.join("include"),
  ]);

  exec.addInstallDestination({
    RUNTIME: scope.INSTALL_BINDIR,
  });
}
