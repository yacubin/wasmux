export default (mk) => {
  const headers = [
    "include/bits/file_struct.h",
    "include/bits/wchar_libio.h",
    "include/stdio.h",
    "include/stdio_ext.h",
  ];

  const sources = [
    "src/_stdio.c",
    "src/flockfile.c",
    "src/fprintf.c",
    "src/ftrylockfile.c",
    "src/funlockfile.c",
    "src/getc_unlocked.c",
    "src/getdelim.c",
    "src/getline.c",
    "src/putwc.c",
    "src/putc.c",
    "src/setvbuf.c",
    "src/sprintf.c",
    "src/stdio_ext.c",
    "src/stdio.c",
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

  mk.script("<wchar.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/wchar_libio.h>" ],
  });
}
