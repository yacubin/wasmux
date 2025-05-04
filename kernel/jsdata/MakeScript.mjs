export default async (mk) => {
  const MainCalls_mjs = mk.BINARY_DIR.join("generated/MainCalls.mjs");
  mk.addCustomScript("webcallesx.js", {
    side: "main",
    SCRIPT_INPUT: mk.PROJECT_SOURCE_DIR.join("data/webcalls.js"),
    SCRIPT_OUTPUT: MainCalls_mjs,
  });

  const loader_js = mk.BINARY_DIR.join("dist/loader.js");
  mk.addCustomScript("loader.build.js", {
    buildType: mk.BUILD_TYPE,
    buildDirectory: mk.BINARY_DIR,
    SCRIPT_INPUT: MainCalls_mjs,
    SCRIPT_OUTPUT: loader_js,
  });

  const loader_S = mk.BINARY_DIR.join("src/loader.S");
  mk.addCustomScript("mkcustsec.js", {
    cpu: mk.SYSTEM_PROCESSOR,
    section: mk.WASMUX_LOADER_SECTION,
    SCRIPT_INPUT: loader_js,
    SCRIPT_OUTPUT: loader_S,
  });

  const WorkerCalls_mjs = mk.BINARY_DIR.join("generated/WorkerCalls.mjs");
  mk.addCustomScript("webcallesx.js", {
    side: "worker",
    SCRIPT_INPUT: mk.PROJECT_SOURCE_DIR.join("data/webcalls.js"),
    SCRIPT_OUTPUT: WorkerCalls_mjs,
  });

  const worker_js = mk.BINARY_DIR.join("dist/worker.js");
  mk.addCustomScript("worker.build.js", {
    buildType: mk.BUILD_TYPE,
    buildDirectory: mk.BINARY_DIR,
    SCRIPT_INPUT: WorkerCalls_mjs,
    SCRIPT_OUTPUT: worker_js,
  });

  const worker_S = mk.BINARY_DIR.join("src/worker.S");
  mk.addCustomScript("mkcustsec.js", {
    cpu: mk.SYSTEM_PROCESSOR,
    section: mk.WASMUX_WORKER_SECTION,
    SCRIPT_INPUT: worker_js,
    SCRIPT_OUTPUT: worker_S,
  });

  mk.target("walinuz").addSources(loader_S, worker_S);
}
