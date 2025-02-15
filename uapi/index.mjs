export default {
  libc: {
    depends: "WASMUX_ENABLE_LIBC",
    objlibs: {
      malloc:    { cmakeDir: "malloc"    },
      string:    { cmakeDir: "string"    },
      ctype:     { cmakeDir: "ctype"     },
      stdlib:    { cmakeDir: "stdlib"    },
      signal:    { cmakeDir: "signal"    },
      semaphore: { cmakeDir: "semaphore" },
      wcsmbs:    { cmakeDir: "wcsmbs"    },
      libio:     { cmakeDir: "libio"     },
      dirent:    { cmakeDir: "dirent"    },
      grp:       { cmakeDir: "grp"       },
      pwd:       { cmakeDir: "pwd"       },
      ftw:       { cmakeDir: "ftw"       },
      wordexp:   { cmakeDir: "wordexp"   },
      login:     { cmakeDir: "login"     },
      mntent:    { cmakeDir: "mntent"    },
      shadow:    { cmakeDir: "shadow"    },
      termios:   { cmakeDir: "termios"   },
      argp:      { cmakeDir: "argp"      },
      fts:       { cmakeDir: "fts"       },
      netdb:     { cmakeDir: "netdb"     },
      obstack:   { cmakeDir: "obstack"   },
      libintl:   { cmakeDir: "libintl"   },
      locale:    { cmakeDir: "locale"    },
      getopt:    { cmakeDir: "getopt"    },
      regex:     { cmakeDir: "regex"     },
      glob:      { cmakeDir: "glob"      },
      fnmatch:   { cmakeDir: "fnmatch"   },
      ulinux:    { cmakeDir: "ulinux"    },
    },
  },
  libgcc: {
    depends: "WASMUX_ENABLE_LIBGCC",
  },
  crt: {
    depends: "WASMUX_ENABLE_CRT",
  },
  libcxx: {
    depends: "WASMUX_ENABLE_LIBCXX",
  },
  libcxxabi: {
    depends: "WASMUX_ENABLE_LIBCXX",
  },
  libm: {
    depends: "WASMUX_ENABLE_LIBM",
  },
  dl: {
    depends: "WASMUX_ENABLE_DL",
  },
  pthread: {
    depends: "WASMUX_ENABLE_PTHREAD",
  },
};
