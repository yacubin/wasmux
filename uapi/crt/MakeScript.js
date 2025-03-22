"use strict";

module.exports = (mk) => {
  const crt1 = mk.addObjectLibrary("crt1", [
    "src/start.c",
    "src/version.c",
  ]);
  crt1.addIncludes(mk.target("wauser").includes);
  crt1.addInstallDestination(mk.INSTALL_BINDIR);

  mk.install(crt1, mk.INSTALL_BINDIR);

  const crt1_reactor = mk.addObjectLibrary("crt1_reactor", [
    "src/initialize.c",
    "src/version.c",
  ]);
  crt1_reactor.addIncludes(mk.target("wauser").includes);
  crt1_reactor.addInstallDestination(mk.INSTALL_BINDIR);
  crt1_reactor.setOutputName("crt1-reactor");

  mk.install(crt1_reactor, mk.INSTALL_BINDIR);
}
