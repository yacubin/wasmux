"use strict";

module.exports = (scope) => {
  if (scope.WASMUX_WAEDITOR) {
    scope.addSubdirectory("waeditor");
  }
}
