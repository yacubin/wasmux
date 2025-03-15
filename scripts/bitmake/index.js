"use strict";

const { Scope } = require("###/bitmake/Scope.js");
const { SourceFile } = require("###/bitmake/SourceFile.js");
const { SourceFileList } = require("###/bitmake/SourceFileList.js");
const { IncludeDirectory } = require("###/bitmake/IncludeDirectory.js");
const { LinkLibrary } = require("###/bitmake/LinkLibrary.js");
const { StaticLibrary, SharedLibrary, Executable } = require("###/bitmake/Target.js");
const { CustomTarget } = require("###/bitmake/CustomTarget.js");
const { ScriptFile } = require("###/bitmake/ScriptFile.js");

module.exports = {
  Scope,
  SourceFile,
  SourceFileList,
  IncludeDirectory,
  LinkLibrary,
  StaticLibrary,
  SharedLibrary,
  Executable,
  CustomTarget,
  ScriptFile,
};
