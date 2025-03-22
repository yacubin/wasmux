"use strict";

module.exports = (mk) => {
  const settings = {};
  const variables = require(mk.PROJECT_SOURCE_DIR.join("data/variables.js").toString());
  for (const key of Object.keys(variables)) {
    settings[key] = mk[key];
  }

  const MainCalls_mjs = mk.BINARY_DIR.join("generated/MainCalls.mjs");
  mk.addCustomScript("MainCalls.mjs", {
    script: "webcallesx.js",
    side: "main",
    input: mk.PROJECT_SOURCE_DIR.join("data/webcalls.js"),
    output: MainCalls_mjs,
  });

  const loader_js = mk.BINARY_DIR.join("dist/loader.js");
  mk.addCustomScript("dist/loader.js", {
    script: "loader.build.js",
    buildType: mk.BUILD_TYPE,
    buildDirectory: mk.BINARY_DIR,
    settings,
    input: MainCalls_mjs,
    output: loader_js,
  });

  const loader_S = mk.BINARY_DIR.join("src/loader.S");
  mk.addCustomScript("src/loader.S", {
    script: "mkcustsec.js",
    cpu: mk.SYSTEM_PROCESSOR,
    section: mk.WASMUX_LOADER_SECTION,
    input: loader_js,
    output: loader_S,
  });

  const WorkerCalls_mjs = mk.BINARY_DIR.join("generated/WorkerCalls.mjs");
  mk.addCustomScript("WorkerCalls.mjs", {
    script: "webcallesx.js",
    side: "worker",
    input: mk.PROJECT_SOURCE_DIR.join("data/webcalls.js"),
    output: WorkerCalls_mjs,
  });

  const worker_js = mk.BINARY_DIR.join("dist/worker.js");
  mk.addCustomScript("worker.build.js", {
    script: "worker.build.js",
    buildType: mk.BUILD_TYPE,
    buildDirectory: mk.BINARY_DIR,
    settings,
    input: WorkerCalls_mjs,
    output: worker_js,
  });

  const worker_S = mk.BINARY_DIR.join("src/worker.S");
  mk.addCustomScript("worker.S", {
    script: "mkcustsec.js",
    cpu: mk.SYSTEM_PROCESSOR,
    section: mk.WASMUX_WORKER_SECTION,
    input: worker_js,
    output: worker_S,
  });

  mk.target("walinuz").addSource(loader_S, worker_S);
}
