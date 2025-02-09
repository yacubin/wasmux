export default {
  name: "wauser",
  type: "static",
  language: "cxx",

  entry: (ctx, env) => {
    const headers = [
      "include/wasmux/syscalls.h",
      "include/wasmux/thread_data.h",
      "include/wasmux/waitstatus.h",
    ];
  
    const sources = [
      "src/thread_data.cpp",
    ];
  
    const includes = [
      "include",
      ctx.path.resolve(env.binaryDir, "include"),
    ];
  
    const libraries = [
      "wabase",
    ];
  
    const genfiles = [
      {
        script: ctx.path.resolve(ctx.global.sourceDir, "scripts/run/usyscallhdr.js"),
        args: [
          ctx.path.resolve(ctx.global.sourceDir, "waf/syscall.js"),
          ctx.path.resolve(env.binaryDir, "include/wasmux/syscall-nums.h"),
        ],
        input: ctx.path.resolve(ctx.global.sourceDir, "waf/syscall.js"),
        output: ctx.path.resolve(env.binaryDir, "include/wasmux/syscall-nums.h"),
        workDir: env.binaryDir,
      },
    ];
  
    return {
      private: {
        headers,
        sources,
        genfiles,
      },
  
      public: {
        includes,
        libraries,
      },
  
      install: {
        headers: [
          {
            files: headers,
            baseDir: "include",
          },
          {
            files: ctx.path.resolve(env.binaryDir, "include/wasmux/syscall-nums.h"),
            baseDir: ctx.path.resolve(env.binaryDir, "include"),
          },
        ],
      },
    };
  },
};
