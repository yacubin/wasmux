const os = require("node:os");
const path = require("node:path");

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

const toolchainSettings = {
  WASMUX_NO_START_FILES: true,
  WASMUX_NO_ENTRY: true,
  WASMUX_NO_STDLIB: true,
  WASMUX_NODEFAULTLIBS: true,
  WASMUX_EXPORT_DYNAMIC: true,
  WASMUX_STACK_FIRST: true,
  WASMUX_STACK_SIZE: 65536,
  WASMUX_IMPORT_MEMORY: true,
  WASMUX_MAX_MEMORY: 2147483648,
  WASMUX_GLOBAL_BASE: 0,
  WASMUX_NO_GC_SECTIONS: true,
  WASMUX_LLVM_RTLIB: "",
  WASMUX_LLVM_LTO: false,
  WASMUX_LLVM_USE_FIND_UNIX_PATHS: false,
  WASMUX_SHARED_MEMORY: true,
};

module.exports = function(scope)
{
  scope.SYSTEM_NAME = scope.SYSTEM_NAME || "Generic";
  const clangPath = scope.findProgram("clang");
  const toolchainPrefix = clangPath ? path.posix.dirname(clangPath) : "";
  const toolchainSuffix = (os.platform() === "win32") ? ".exe" : "";

  for (const [key, val] of Object.entries(toolchainUtils)) {
    const filename = val + toolchainSuffix;
    scope[key] = toolchainPrefix ? path.posix.resolve(toolchainPrefix, filename) : filename;
  }

  for (const [key, val] of Object.entries(toolchainSettings)) {
    scope[key] = val;
  }

  const compilerFlags = [
    "--target=" + scope.WASMUX_TARGET_TRIPLET,
    "-matomics",
    "-mmultivalue",
    "-mbulk-memory",
  ];

  if (scope.WASMUX_NO_STDLIB)
    compilerFlags.push("--no-standard-libraries");

  // if (scope.SYSTEM_NAME === "Linux")
  //   compilerFlags.push("-D__linux__");

  const objectFlags = [];

  if (scope.WASMUX_ENABLE_EH)
    objectFlags.push("-mllvm", "-wasm-enable-eh");

  if (scope.WASMUX_ENABLE_SJLJ)
    objectFlags.push("-mllvm", "-wasm-enable-sjlj");

  if (scope.WASMUX_ENABLE_EMSCRIPTEN_SJLJ)
    objectFlags.push("-mllvm", "-enable-emscripten-sjlj");

  if (scope.WASMUX_ENABLE_EMSCRIPTEN_CXX_EXCEPTIONS)
    objectFlags.push("-mllvm", "-enable-emscripten-cxx-exceptions");

  scope.ASM_FLAGS.push(...compilerFlags);
  scope.C_FLAGS.push(...compilerFlags, "-O3");
  scope.CXX_FLAGS.push(...compilerFlags, "-O3");

  scope.SHARED_LINKER_FLAGS.push("-mexec-model=reactor", "-Wl,--no-entry");

  if (scope.WASMUX_NO_START_FILES)
    scope.EXE_LINKER_FLAGS.push("-nostartfiles");

  if (scope.WASMUX_NO_ENTRY)
    scope.EXE_LINKER_FLAGS.push("-Wl,--no-entry");

  if (scope.WASMUX_IMPORT_MEMORY) {
    scope.EXE_LINKER_FLAGS.push("-Wl,--import-memory");
    scope.SHARED_LINKER_FLAGS.push("-Wl,--import-memory");
  }

  if (scope.WASMUX_EXPORT_DYNAMIC)
    scope.SHARED_LINKER_FLAGS.push("-Wl,--export-dynamic");

  if (scope.WASMUX_SHARED_MEMORY) {
    scope.EXE_LINKER_FLAGS.push("-Wl,--shared-memory");
    scope.SHARED_LINKER_FLAGS.push("-Wl,--shared-memory");
  }

  if (scope.WASMUX_MAX_MEMORY) {
    scope.EXE_LINKER_FLAGS.push("-Wl,--max-memory=" + scope.WASMUX_MAX_MEMORY);
    scope.SHARED_LINKER_FLAGS.push("-Wl,--max-memory=" + scope.WASMUX_MAX_MEMORY);
  }

  if (scope.WASMUX_NODEFAULTLIBS) {
    scope.EXE_LINKER_FLAGS.push("-nodefaultlibs");
    scope.SHARED_LINKER_FLAGS.push("-nodefaultlibs");
  }

  if (scope.WASMUX_STACK_FIRST)
    scope.EXE_LINKER_FLAGS.push("-Wl,--stack-first");

  if (scope.WASMUX_STACK_SIZE)
    scope.EXE_LINKER_FLAGS.push("-z", "stack-size=" + scope.WASMUX_STACK_SIZE);

  if (scope.WASMUX_GLOBAL_BASE)
    scope.EXE_LINKER_FLAGS.push("-Wl,--global-base=" + scope.WASMUX_GLOBAL_BASE);

  if (scope.WASMUX_NO_GC_SECTIONS)
    scope.EXE_LINKER_FLAGS.push("-Wl,--no-gc-sections");

  if (scope.WASMUX_LLVM_RTLIB) {
    scope.EXE_LINKER_FLAGS.push("-rtlib=" + scope.WASMUX_LLVM_RTLIB);
    scope.SHARED_LINKER_FLAGS.push("-rtlib=" + scope.WASMUX_LLVM_RTLIB);
  }

  if (scope.WASMUX_LLVM_LTO) {
    scope.CXX_FLAGS.push("-flto");
    scope.EXE_LINKER_FLAGS.push("-Wl,--lto-O3");
    scope.SHARED_LINKER_FLAGS.push("-Wl,--lto-O3");
  }

  if (scope.WASMUX_LLVM_USE_FIND_UNIX_PATHS) {
    scope.C_FLAGS.push(`--include-directory=${scope.SYSROOT}/usr/include`);
    scope.CXX_FLAGS.push(`--include-directory=${scope.SYSROOT}/usr/include`);
    scope.EXE_LINKER_FLAGS.push(`--library-directory=${scope.SYSROOT}/usr/lib`);
    scope.SHARED_LINKER_FLAGS.push(`--library-directory=${scope.SYSROOT}/usr/lib`);
  }
}
