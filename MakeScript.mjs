import fs from "node:fs";

export default function(mk) {
  mk.addCacheVariables("wasmux/MakeConfig.mjs");
  mk.addCacheVariables(`wasmux/arch/${mk.WASMUX_ARCH}/MakeConfig.mjs`);

  mk.WASMUX_VERSION = mk.PROJECT_VERSION;
  mk.WASMUX_DESCRIPTION = mk.PROJECT_DESCRIPTION;
  mk.WASMUX_URL = mk.PROJECT_HOMEPAGE_URL;

  mk.INSTALL_BINDIR = "bin";
  mk.INSTALL_INCLUDEDIR = "include";
  mk.INSTALL_LIBDIR = "lib";

  if (mk.WASMUX_TARGET_TRIPLET && mk.WASMUX_TARGET_TRIPLET.match(/-wasi$/))
    mk.INSTALL_LIBDIR = `lib/${mk.SYSTEM_PROCESSOR}-wasi`;

  mk.ASM_FLAGS.push("-D__ASSEMBLY__");

  mk.executeScript("wasmux-config.h.mjs", {
    SCRIPT_INPUT: mk.getCacheVariables(),
    SCRIPT_OUTPUT: mk.BINARY_DIR.join("wasmux-config.h"),
  });

  mk.addIncludeDirectories(mk.BINARY_DIR);

  mk.addSubdirectory("wasmux");
  mk.addSubdirectory("uapi");
  mk.addSubdirectory("kernel");

  if (mk.WASMUX_TARGET_TRIPLET) {
    const toolchainLines = [
      "set(CMAKE_SYSTEM_NAME Linux)",
      "set(CMAKE_SYSTEM_VERSION 1)",
      `set(CMAKE_SYSTEM_PROCESSOR ${mk.SYSTEM_PROCESSOR})`,
      `set(CMAKE_SIZEOF_VOID_P ${mk.SIZEOF_VOID_P})`,
      `set(CONFIG_BUILD_C_COMPILER \"${mk.C_COMPILER}\")`,
      `set(CONFIG_BUILD_CXX_COMPILER \"${mk.CXX_COMPILER}\")`,
      "",
      'get_filename_component(CMAKE_SYSROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)',
      "set(CONFIG_NO_START_FILES OFF)",
      "set(CONFIG_NO_ENTRY OFF)",
      "set(CONFIG_NO_STDLIB OFF)",
      "set(CONFIG_NODEFAULTLIBS OFF)",
      "set(CONFIG_EXPORT_DYNAMIC ON)",
      "set(CONFIG_STACK_FIRST ON)",
      "set(CONFIG_STACK_SIZE 131072)",
      "",
      `set(WASMUX_TARGET_TRIPLET ${mk.WASMUX_TARGET_TRIPLET})`,
      `set(WASMUX_MAX_MEMORY ${mk.WASMUX_MAX_MEMORY})`,
      "",
      "set(WASMUX_GLOBAL_BASE 0)",
      "set(WASMUX_NO_GC_SECTIONS OFF)",
      "set(WASMUX_RTLIB_DEFAULT libgcc)",
      "set(WASMUX_LTO_DEFAULT OFF)",
      "set(WASMUX_USE_FIND_UNIX_PATHS_DEFAULT ON)",
      "set(WASMUX_IMPORT_MEMORY_DEFAULT ON)",
      "set(WASMUX_EXPORT_MEMORY_DEFAULT OFF)",
      "set(WASMUX_SHARED_MEMORY_DEFAULT OFF)",
      "",
      "",
    ];

    const commonToolchain = fs.readFileSync("cmake/CommonToolchain.cmake");
    const toolchainOutput = toolchainLines.join("\n") + commonToolchain;

    const toolchainName = mk.SYSTEM_PROCESSOR + (mk.WASMUX_TARGET_TRIPLET.match(/-wasi$/) ? "-wasi" : "") + ".toolchain.cmake";
    const toolchainFile = mk.BINARY_DIR.join("cmake", toolchainName);
    fs.mkdirSync(toolchainFile.dirname().toString(), { recursive: true });
    fs.writeFileSync(toolchainFile.toString(), toolchainOutput, "utf8");
    mk.install(toolchainFile.toString(), "share/wasmux");
  }
}
