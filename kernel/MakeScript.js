"use strict";

module.exports = (mk) => {
  if (mk.WASMUX_ENABLE_KERNEL) {
    mk.addSubdirectory("jsdata");
    mk.addSubdirectory("walinuz");
  }
}
