export default (mk) => {
  if (mk.WASMUX_LIBC) {
    mk.addSubdirectory("malloc");
    mk.addSubdirectory("fcntl");
    mk.addSubdirectory("string");
    mk.addSubdirectory("ctype");
    mk.addSubdirectory("stdlib");
    mk.addSubdirectory("signal");
    mk.addSubdirectory("semaphore");
    mk.addSubdirectory("wcsmbs");
    mk.addSubdirectory("libio");
    mk.addSubdirectory("backtrace");
    mk.addSubdirectory("dirent");

    if (mk.WASMUX_ENV_WITH_LIBC)
      mk.addSubdirectory("env");

    mk.addSubdirectory("grp");
    mk.addSubdirectory("pwd");
    mk.addSubdirectory("ftw");
    mk.addSubdirectory("wordexp");
    mk.addSubdirectory("login");
    mk.addSubdirectory("mntent");
    mk.addSubdirectory("shadow");
    mk.addSubdirectory("termios");
    mk.addSubdirectory("argp");
    mk.addSubdirectory("fts");
    mk.addSubdirectory("netdb");
    mk.addSubdirectory("obstack");
    mk.addSubdirectory("libintl");
    mk.addSubdirectory("locale");
    mk.addSubdirectory("getopt");
    mk.addSubdirectory("regex");
    mk.addSubdirectory("glob");
    mk.addSubdirectory("fnmatch");
    mk.addSubdirectory("ulinux");
    mk.addSubdirectory("libc");
  }
  mk.addSubdirectory("crt");
  mk.addSubdirectory("libgcc");
  mk.addSubdirectory("libcxx");
  mk.addSubdirectory("libcxxabi");
  mk.addSubdirectory("libm");
  mk.addSubdirectory("dl");
  mk.addSubdirectory("pthread");
}
