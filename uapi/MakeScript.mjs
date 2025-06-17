export default (mk) => {
  if (mk.WASMUX_LIBC) {
    mk.addSubdirectory("malloc");
    mk.addSubdirectory("fcntl");
    mk.addSubdirectory("string");
    mk.addSubdirectory("ctype");
    mk.addSubdirectory("wctype");
    mk.addSubdirectory("stdlib");
    mk.addSubdirectory("signal");
    mk.addSubdirectory("semaphore");
    mk.addSubdirectory("wcsmbs");
    mk.addSubdirectory("libio");
    mk.addSubdirectory("time");
    mk.addSubdirectory("backtrace");
    mk.addSubdirectory("dirent");

    if (mk.WASMUX_ENV_WITH_LIBC)
      mk.addSubdirectory("env");

    mk.addSubdirectory("grp");
    mk.addSubdirectory("pwd");
    mk.addSubdirectory("ftw");
    mk.addSubdirectory("wordexp");
    mk.addSubdirectory("search");
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

  if (mk.WASMUX_CRT)
    mk.addSubdirectory("crt");

  if (mk.WASMUX_RT)
    mk.addSubdirectory("rt");

  if (mk.WASMUX_LIBGCC)
    mk.addSubdirectory("libgcc");

  if (mk.WASMUX_LIBCXX)
    mk.addSubdirectory("libcxx");

  if (mk.WASMUX_LIBCXXABI)
    mk.addSubdirectory("libcxxabi");

  if (mk.WASMUX_LIBM)
    mk.addSubdirectory("libm");

  if (mk.WASMUX_DL)
    mk.addSubdirectory("dl");

  if (mk.WASMUX_PTHREAD)
    mk.addSubdirectory("pthread");
}
