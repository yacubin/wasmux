"use strict";

const { Scope } = require("./Scope.js");
const { SourceFile } = require("./SourceFile.js");
const { SourceFileList } = require("./SourceFileList.js");
const { IncludeDirectory } = require("./IncludeDirectory.js");
const { StaticLibrary, SharedLibrary, Executable } = require("./Target.js");
const { CustomTarget } = require("./CustomTarget.js");
const { ScriptFile } = require("./ScriptFile.js");
const { InterfaceTarget } = require("./InterfaceTarget.js");
const { InterfaceIncludes } = require("./InterfaceIncludes.js");
const { InterfaceObjects } = require("./InterfaceObjects.js");

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
  InterfaceObjects,
};
