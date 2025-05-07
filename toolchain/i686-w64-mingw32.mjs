import fs from "node:fs";
import os from "node:os";
import bitmake from "bitmake";

const { path } = bitmake;

const toolchainUtils = {
  ASM_COMPILER: "clang",
  C_COMPILER:   "clang",
  CXX_COMPILER: "clang++",
  AR:           "llvm-ar",
  RANLIB:       "llvm-ranlib",
  LINKER:       "wasm-ld",
  NM:           "llvm-nm",
  OBJCOPY:      "llvm-objcopy",
  OBJDUMP:      "llvm-objdump",
  STRIP:        "llvm-strip",
  LLVM_LLC:     "llc",
};

export default (mk) => {
  mk.SYSTEM_NAME = "Windows";
  mk.SYSTEM_VERSION = 10;
  mk.SYSTEM_PROCESSOR = "i686";
  mk.SIZEOF_VOID_P = 4;

  mk.WASMUX_TARGET_TRIPLET = "i686-w64-mingw32";

  let MINGW_TOOLCHAIN_ROOT = "";
  if (mk.MINGW_ROOT) {
    MINGW_TOOLCHAIN_ROOT = path.resolve(mk.MINGW_ROOT, mk.WASMUX_TARGET_TRIPLET);
    if (!fs.existsSync(MINGW_TOOLCHAIN_ROOT))
      MINGW_TOOLCHAIN_ROOT = path.resolve(mk.MINGW_ROOT, "x86_64-w64-mingw32");
  }

  const clangPath = mk.findProgram("clang");
  const toolchainPrefix = clangPath ? path.dirname(clangPath) : "";
  const toolchainSuffix = (os.platform() === "win32") ? ".exe" : "";

  for (const [key, val] of Object.entries(toolchainUtils)) {
    const filename = val + toolchainSuffix;
    mk[key] = toolchainPrefix ? path.resolve(toolchainPrefix, filename) : filename;
  }

  const compilerFlags = [
    "--target=" + mk.WASMUX_TARGET_TRIPLET,
    "--no-standard-libraries",
    "-m32",
    "-D_WIN32_WINNT=0x0601",
  ];

  const linkerFlags = [
    "-nostartfiles",
    "-nostdlib",
    "-nodefaultlibs",
  ];

  if (MINGW_TOOLCHAIN_ROOT) {
    compilerFlags.push("-I" + path.resolve(MINGW_TOOLCHAIN_ROOT, "include"));
    if (fs.existsSync(path.resolve(MINGW_TOOLCHAIN_ROOT, "lib32")))
      linkerFlags.push("-L" + path.resolve(MINGW_TOOLCHAIN_ROOT, "lib32"));
    if (fs.existsSync(path.resolve(MINGW_TOOLCHAIN_ROOT, "lib")))
      linkerFlags.push("-L" + path.resolve(MINGW_TOOLCHAIN_ROOT, "lib"));
  }

  if (mk.WASMUX_NO_STDLIB)
    compilerFlags.push("--no-standard-libraries");

  mk.ASM_FLAGS.push(...compilerFlags);
  mk.C_FLAGS.push(...compilerFlags, "-fno-builtin-memset", "-Wno-pragma-pack", "-O3");
  mk.CXX_FLAGS.push(...compilerFlags, "-fno-builtin-memset", "-Wno-pragma-pack", "-O3", "-fno-exceptions", "-fno-rtti");
}
