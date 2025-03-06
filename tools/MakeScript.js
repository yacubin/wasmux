"use strict";

module.exports = (scope) => {
  if (scope.WASMUX_ENABLE_WAEDITOR) {
    scope.addSubdirectory("waeditor");
  }
}
