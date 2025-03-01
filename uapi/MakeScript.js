module.exports = (scope) => {
  if (scope.WASMUX_ENABLE_LIBC) {
    scope.addSubdirectory("malloc");
    scope.addSubdirectory("fcntl");
    /*scope.addSubdirectory("string");
    scope.addSubdirectory("ctype");
    scope.addSubdirectory("stdlib");
    scope.addSubdirectory("signal");
    scope.addSubdirectory("semaphore");
    scope.addSubdirectory("wcsmbs");
    scope.addSubdirectory("libio");
    scope.addSubdirectory("dirent");
    scope.addSubdirectory("grp");
    scope.addSubdirectory("pwd");
    scope.addSubdirectory("ftw");
    scope.addSubdirectory("wordexp");
    scope.addSubdirectory("login");
    scope.addSubdirectory("mntent");
    scope.addSubdirectory("shadow");
    scope.addSubdirectory("termios");
    scope.addSubdirectory("argp");
    scope.addSubdirectory("fts");
    scope.addSubdirectory("netdb");
    scope.addSubdirectory("obstack");
    scope.addSubdirectory("libintl");
    scope.addSubdirectory("locale");
    scope.addSubdirectory("getopt");
    scope.addSubdirectory("regex");
    scope.addSubdirectory("glob");
    scope.addSubdirectory("fnmatch");
    scope.addSubdirectory("ulinux");*/
  }
  /*if (scope.WASMUX_ENABLE_LIBGCC) {
    scope.addSubdirectory("libgcc");
  }
  if (scope.WASMUX_ENABLE_CRT) {
    scope.addSubdirectory("crt");
  }
  if (scope.WASMUX_ENABLE_LIBCXX) {
    scope.addSubdirectory("libcxx");
  }
  if (scope.WASMUX_ENABLE_LIBCXX) {
    scope.addSubdirectory("libcxxabi");
  }
  if (scope.WASMUX_ENABLE_LIBM) {
    scope.addSubdirectory("libm");
  }
  if (scope.WASMUX_ENABLE_DL) {
    scope.addSubdirectory("dl");
  }
  if (scope.WASMUX_ENABLE_PTHREAD) {
    scope.addSubdirectory("pthread");
  }*/
}
