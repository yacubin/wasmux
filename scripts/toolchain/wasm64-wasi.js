const baseToolchain = require("./common.js");

module.exports = function(scope) 
{
  scope.WASMUX_TARGET_TRIPLET = "wasm64-unknown-wasi";
  scope.SYSTEM_PROCESSOR = "wasm64";
  scope.SIZEOF_VOID_P = 8;

  baseToolchain(scope);
}
