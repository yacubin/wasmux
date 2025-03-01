const baseToolchain = require("./common.js");

module.exports = function(scope)
{
  scope.WASMUX_TARGET_TRIPLET = "wasm32-unknown-unknown";
  scope.SYSTEM_PROCESSOR = "wasm32";
  scope.SIZEOF_VOID_P = 4;

  baseToolchain(scope);
}
