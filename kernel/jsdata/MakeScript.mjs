export default async (mk) => {
  const MainCalls_mjs = mk.BINARY_DIR.join("generated/MainCalls.mjs");
  mk.addCustomScript("webcallesx.mjs", {
    SCRIPT_INPUT: mk.PROJECT_SOURCE_DIR.join("data/webcalls.js"),
    SCRIPT_OUTPUT: MainCalls_mjs,
    SCRIPT_SIDE: "main",
  });

  const loader_js = mk.BINARY_DIR.join("dist/loader.js");
  mk.addCustomScript("loader.build.js", {
    SCRIPT_INPUT: MainCalls_mjs,
    SCRIPT_OUTPUT: loader_js,
  });

  const loader_S = mk.BINARY_DIR.join("src/loader.S");
  mk.addCustomScript("mkcustsec.mjs", {
    SCRIPT_INPUT: loader_js,
    SCRIPT_OUTPUT: loader_S,
    SCRIPT_SECTION: mk.WASMUX_LOADER_SECTION,
  });

  const WorkerCalls_mjs = mk.BINARY_DIR.join("generated/WorkerCalls.mjs");
  mk.addCustomScript("webcallesx.mjs", {
    SCRIPT_INPUT: mk.PROJECT_SOURCE_DIR.join("data/webcalls.js"),
    SCRIPT_OUTPUT: WorkerCalls_mjs,
    SCRIPT_SIDE: "worker",
  });

  const worker_js = mk.BINARY_DIR.join("dist/worker.js");
  mk.addCustomScript("worker.build.js", {
    SCRIPT_INPUT: WorkerCalls_mjs,
    SCRIPT_OUTPUT: worker_js,
  });

  const worker_S = mk.BINARY_DIR.join("src/worker.S");
  mk.addCustomScript("mkcustsec.mjs", {
    SCRIPT_INPUT: worker_js,
    SCRIPT_OUTPUT: worker_S,
    SCRIPT_SECTION: mk.WASMUX_WORKER_SECTION,
  });

  mk.target("walinuz").addSources(loader_S, worker_S);
}
