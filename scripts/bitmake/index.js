"use strict";

const { Scope } = require("###/bitmake/Scope.js");
const { SourceFile } = require("###/bitmake/SourceFile.js");
const { SourceFileList } = require("###/bitmake/SourceFileList.js");
const { IncludeDirectory } = require("###/bitmake/IncludeDirectory.js");
const { StaticLibrary, SharedLibrary, Executable } = require("###/bitmake/Target.js");
const { CustomTarget } = require("###/bitmake/CustomTarget.js");
const { ScriptFile } = require("###/bitmake/ScriptFile.js");
const { InterfaceTarget } = require("###/bitmake/InterfaceTarget.js");
const { InterfaceIncludes } = require("###/bitmake/InterfaceIncludes.js");

module.exports = {
  Scope,
  SourceFile,
  SourceFileList,
  IncludeDirectory,
  StaticLibrary,
  SharedLibrary,
  Executable,
  CustomTarget,
  ScriptFile,
  InterfaceTarget,
  InterfaceIncludes,
};
