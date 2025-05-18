import baseToolchain from "./common.mjs";

export default (mk) => {
  mk.WASMUX_TARGET_TRIPLET = "wasm64-unknown-unknown";
  mk.SYSTEM_PROCESSOR = "wasm64";
  mk.SIZEOF_VOID_P = 8;

  baseToolchain(mk);
}
