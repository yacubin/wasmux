"use strict";

module.exports = (mk) => {
  const crt1_sources = [
    "src/start.c",
    "src/version.c",
  ];

  const crt1_includes = [
    mk.target("wauser").includes,
  ];

  const crt1 = mk.addObjectLibrary("crt1", crt1_sources);
  crt1.addIncludes(crt1_includes);

  mk.install(crt1, mk.INSTALL_LIBDIR);

  const crt1_reactor_sources = [
    "src/initialize.c",
    "src/version.c",
  ];

  const crt1_reactor_includes = [
    mk.target("wauser").includes,
  ];

  const crt1_reactor = mk.addObjectLibrary("crt1_reactor", crt1_reactor_sources);
  crt1_reactor.addIncludes(crt1_reactor_includes);
  crt1_reactor.setOutputName("crt1-reactor");

  mk.install(crt1_reactor, mk.INSTALL_LIBDIR);
}
