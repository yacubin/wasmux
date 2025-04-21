import baseToolchain from "./common.mjs";

export default (mk) => {
  mk.WASMUX_TARGET_TRIPLET = "wasm32-unknown-wasi";
  mk.SYSTEM_PROCESSOR = "wasm32";
  mk.SIZEOF_VOID_P = 4;

  baseToolchain(mk);
}
