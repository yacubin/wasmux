export default async (mk) => {
  const settings = {};
  for (const name of Object.keys(mk.getCacheVariables()))
    settings[name] = mk[name];

  const MainCalls_mjs = mk.BINARY_DIR.join("generated/MainCalls.mjs");
  mk.addCustomScript("webcallesx.js", {
    side: "main",
    input: mk.PROJECT_SOURCE_DIR.join("data/webcalls.js"),
    output: MainCalls_mjs,
  });

  const loader_js = mk.BINARY_DIR.join("dist/loader.js");
  mk.addCustomScript("loader.build.js", {
    buildType: mk.BUILD_TYPE,
    buildDirectory: mk.BINARY_DIR,
    settings,
    input: MainCalls_mjs,
    output: loader_js,
  });

  const loader_S = mk.BINARY_DIR.join("src/loader.S");
  mk.addCustomScript("mkcustsec.js", {
    cpu: mk.SYSTEM_PROCESSOR,
    section: mk.WASMUX_LOADER_SECTION,
    input: loader_js,
    output: loader_S,
  });

  const WorkerCalls_mjs = mk.BINARY_DIR.join("generated/WorkerCalls.mjs");
  mk.addCustomScript("webcallesx.js", {
    side: "worker",
    input: mk.PROJECT_SOURCE_DIR.join("data/webcalls.js"),
    output: WorkerCalls_mjs,
  });

  const worker_js = mk.BINARY_DIR.join("dist/worker.js");
  mk.addCustomScript("worker.build.js", {
    buildType: mk.BUILD_TYPE,
    buildDirectory: mk.BINARY_DIR,
    settings,
    input: WorkerCalls_mjs,
    output: worker_js,
  });

  const worker_S = mk.BINARY_DIR.join("src/worker.S");
  mk.addCustomScript("mkcustsec.js", {
    cpu: mk.SYSTEM_PROCESSOR,
    section: mk.WASMUX_WORKER_SECTION,
    input: worker_js,
    output: worker_S,
  });

  mk.target("walinuz").addSources(loader_S, worker_S);
}
