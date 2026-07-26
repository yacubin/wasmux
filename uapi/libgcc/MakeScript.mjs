export default (mk) => {
  const libgcc = mk.addStaticLibrary("libgcc", mk.target("ti128").objects);
  libgcc.setPrefix("");

  mk.install(libgcc, mk.INSTALL_LIBDIR);
}
