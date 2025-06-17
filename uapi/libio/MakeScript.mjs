export default (mk) => {
  const headers = [
    "include/bits/file_struct.h",
    "include/bits/wchar_libio.h",
    "include/stdio.h",
    "include/stdio_ext.h",
  ];

  const sources = [
    "src/_stdio.cpp",
    "src/flockfile.cpp",
    "src/fprintf.cpp",
    "src/ftrylockfile.cpp",
    "src/funlockfile.cpp",
    "src/getc_unlocked.cpp",
    "src/getdelim.cpp",
    "src/getline.cpp",
    "src/putwc.cpp",
    "src/putc.cpp",
    "src/setvbuf.cpp",
    "src/sprintf.cpp",
    "src/stdio_ext.cpp",
    "src/stdio.cpp",
  ];

  const includes = [
    mk.SOURCE_DIR.join("include"),
  ];

  mk.script("<wchar.h>").mergeVariables({
    SCRIPT_INCLUDES: [ "#include <bits/wchar_libio.h>" ],
  });

  mk.target("libc").addSources(headers, sources);
  mk.target("libc").addPublicIncludes(includes);

  mk.install(headers, {
    destination: mk.INSTALL_INCLUDEDIR,
    baseDir: "include",
  });
}
