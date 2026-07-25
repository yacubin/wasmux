export default (mk) => {
  const headers = [
    "include/bits/string_basename.h",
    "include/libgen.h",
    "include/string.h",
    "include/strings.h",
  ];

  const sources = [
    "src/basename.c",
    "src/dirname.c",
    "src/memchr.c",
    "src/memcmp.c",
    "src/memcpy.c",
    "src/memmem.c",
    "src/memmove.c",
    "src/mempcpy.c",
    "src/memrchr.c",
    "src/memset.c",
    "src/rindex.c",
    "src/stpcpy.c",
    "src/stpncpy.c",
    "src/strcat.c",
    "src/strchr.c",
    "src/strchrnul.c",
    "src/strcmp.c",
    "src/strcoll.c",
    "src/strcpy.c",
    "src/strcspn.c",
    "src/strdup.c",
    "src/strerror.c",
    "src/string.c",
    "src/strlen.c",
    "src/strncat.c",
    "src/strncmp.c",
    "src/strncpy.c",
    "src/strndup.c",
    "src/strnlen.c",
    "src/strpbrk.c",
    "src/strrchr.c",
    "src/strsep.c",
    "src/strspn.c",
    "src/strstr.c",
    "src/strtok.c",
    "src/strtok_r.c",
    "src/strverscmp.c",
    "src/strxfrm.c",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
