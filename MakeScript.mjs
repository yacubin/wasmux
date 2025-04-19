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
    const toolchainContent1 = fs.readFileSync("cmake/LinuxSystem.cmake");
    const toolchainContent2 = fs.readFileSync("cmake/UserConfig.cmake");
    const toolchainContent3 = fs.readFileSync("cmake/CommonToolchain.cmake");

    const toolchainOutput = `
set(WASMUX_TARGET_TRIPLET ${mk.WASMUX_TARGET_TRIPLET})\n
${toolchainContent1}
set(CMAKE_SYSTEM_PROCESSOR ${mk.SYSTEM_PROCESSOR})
set(CMAKE_SIZEOF_VOID_P ${mk.SIZEOF_VOID_P})
set(CONFIG_BUILD_C_COMPILER \"${mk.C_COMPILER}\")
set(CONFIG_BUILD_CXX_COMPILER \"${mk.CXX_COMPILER}\")

get_filename_component(CMAKE_SYSROOT "\${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)

${toolchainContent2}
${toolchainContent3}
`;

    const toolchainFilename = mk.BINARY_DIR.join("cmake", mk.SYSTEM_PROCESSOR + (mk.WASMUX_TARGET_TRIPLET.match(/-wasi$/) ? "-wasi" : "") + ".toolchain.cmake");
    fs.mkdirSync(toolchainFilename.dirname().toString(), { recursive: true });
    fs.writeFileSync(toolchainFilename.toString(), toolchainOutput, "utf8");
    mk.install(toolchainFilename.toString(), "share/wasmux");
  }
}
