export default async (mk) => {
  const loader_js = mk.BINARY_DIR.join("dist/loader.js");
  mk.addCustomScript("loader.build.mjs", {
    SCRIPT_OUTPUT: loader_js,
  });

  const loader_S = mk.BINARY_DIR.join("src/loader.S");
  mk.addCustomScript("mkcustsec.mjs", {
    SCRIPT_INPUT: loader_js,
    SCRIPT_OUTPUT: loader_S,
    SCRIPT_SECTION: mk.WASMUX_LOADER_SECTION,
  });

  const worker_js = mk.BINARY_DIR.join("dist/worker.js");
  mk.addCustomScript("worker.build.mjs", {
    SCRIPT_OUTPUT: worker_js,
  });

  const worker_S = mk.BINARY_DIR.join("src/worker.S");
  mk.addCustomScript("mkcustsec.mjs", {
    SCRIPT_INPUT: worker_js,
    SCRIPT_OUTPUT: worker_S,
    SCRIPT_SECTION: mk.WASMUX_WORKER_SECTION,
  });

  mk.target("kapsule").addSources(loader_S, worker_S);
}
