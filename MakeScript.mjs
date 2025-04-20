import fs from "node:fs";

export default function(mk) {
  mk.addCacheVariables("data/variables.js");

  mk.INSTALL_BINDIR = "bin";
  mk.INSTALL_INCLUDEDIR = "include";
  mk.INSTALL_LIBDIR = "lib";

  if (mk.WASMUX_TARGET_TRIPLET && mk.WASMUX_TARGET_TRIPLET.match(/-wasi$/))
    mk.INSTALL_LIBDIR = `lib/${mk.SYSTEM_PROCESSOR}-wasi`;

  mk.ASM_FLAGS.push("-D__ASSEMBLY__");

  mk.executeScript("wasmux-config.h.js", {
    input: mk.getCacheVariables(),
    output: mk.BINARY_DIR.join("wasmux-config.h"),
  });

  mk.addIncludeDirectories(mk.BINARY_DIR);

  mk.addSubdirectory("waf");
  mk.addSubdirectory("uapi");
  mk.addSubdirectory("kernel");
  mk.addSubdirectory("tools");

  if (mk.WASMUX_TARGET_TRIPLET) {
    const toolchainLines = [
      `set(WASMUX_TARGET_TRIPLET ${mk.WASMUX_TARGET_TRIPLET})`,
      "",
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
      "set(CONFIG_IMPORT_MEMORY ON)",
      "set(CONFIG_MAX_MEMORY 2147483648)",
      "set(CONFIG_GLOBAL_BASE 0)",
      "set(CONFIG_NO_GC_SECTIONS OFF)",
      "set(CONFIG_LLVM_RTLIB libgcc)",
      "set(CONFIG_LLVM_LTO OFF)",
      "set(CONFIG_LLVM_USE_FIND_UNIX_PATHS ON)",
      "",
      "if (NOT DEFINED WASMUX_SHARED_MEMORY)",
      "  set(WASMUX_SHARED_MEMORY OFF)",
      "endif ()",
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
