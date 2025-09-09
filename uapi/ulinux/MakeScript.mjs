export default (mk) => {
  const headers = [
    "include/linux/blkpg.h",
    "include/linux/if_addr.h",
    "include/linux/if_packet.h",
    "include/linux/magic.h",
    "include/linux/route.h",
    "include/linux/version.h",
    "include/linux/vt.h",
  ];

  const sources = [
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
