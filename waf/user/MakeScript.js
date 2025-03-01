module.exports = (scope) => {
  const wauser = scope.addStaticLibrary("wauser");

  const headers = [
    "include/wasmux/syscalls.h",
    "include/wasmux/thread_data.h",
    "include/wasmux/waitstatus.h",
  ];

  wauser.addSources(
    "src/thread_data.cpp",
  );

  wauser.addPublicIncludes(
    scope.BINARY_DIR.join("include"),
    scope.SOURCE_DIR.join("include"),
  );

  wauser.addPublicLibraries(
    "wabase",
  );

  const arch_syscall_h = scope.BINARY_DIR.join("include/wasmux/arch-syscall.h");
  scope.addCustomTarget("<wasmux/arch-syscall.h>", {
    script: "src/arch-syscall.h.mjs",
    depends: scope.PROJECT_DIR.join("data/syscall.mjs"),
    output: arch_syscall_h,
  });

  wauser.addSources(arch_syscall_h);
  wauser.addInstallHeaders(arch_syscall_h, { baseDir: scope.BINARY_DIR });
  wauser.addSources(headers);
  wauser.addInstallHeaders(headers, { baseDir: "include" });
}
