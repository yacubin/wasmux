"use strict";

const { Scope } = require("###/bitmake/Scope.js");
const { SourceFile } = require("###/bitmake/SourceFile.js");
const { SourceFileList } = require("###/bitmake/SourceFileList.js");
const { RefTarget } = require("###/bitmake/RefTarget.js");
const { StaticLibrary, SharedLibrary, Executable } = require("###/bitmake/Target.js");

module.exports = {
  Scope,
  SourceFile,
  SourceFileList,
  StaticLibrary,
  SharedLibrary,
  Executable,
  RefTarget,
};
