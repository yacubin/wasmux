"use strict";

const { arrayWrapper } = require("###/utils/Primitives.js");
const { cloneString } = require("###/bitmake/StrictType.js");
const { Scope } = require("###/bitmake/Scope.js");
const { SourceFile } = require("###/bitmake/SourceFile.js");
const { SourceFileList } = require("###/bitmake/SourceFileList.js");
const { IncludeDirectory } = require("###/bitmake/IncludeDirectory.js");
const { LinkLibrary } = require("###/bitmake/LinkLibrary.js");

const NAME                = Symbol("NAME");
const TARGET_SCOPE        = Symbol("TARGET_SCOPE");
const OUTPUT_NAME         = Symbol("OUTPUT_NAME");
const COMPILE_OPTIONS     = Symbol("COMPILE_OPTIONS");
const PREFIX              = Symbol("PREFIX");
const SUFFIX              = Symbol("SUFFIX");
const LINK_OPTIONS        = Symbol("LINK_OPTIONS");
const INCLUDES            = Symbol("INCLUDES");
const SOURCES             = Symbol("SOURCES");
const LIBRARIES           = Symbol("LIBRARIES");
const INSTALL_DESTINATION = Symbol("INSTALL_DESTINATION");

function BaseTarget(scope, name) {
  this[NAME] = cloneString(name);
  this[TARGET_SCOPE] = Scope.create(scope);
  this[OUTPUT_NAME] = cloneString(name);
  this[COMPILE_OPTIONS] = [];
  this[PREFIX] = "";
  this[SUFFIX] = "";
  this[LINK_OPTIONS] = [];
  this[INCLUDES] = [];
  this[SOURCES] = [];
  this[LIBRARIES] = [];
  this[INSTALL_DESTINATION] = null;
}

BaseTarget.prototype = Object.create(Object.prototype, {
  constructor: {
    value: BaseTarget,
    enumerable: false,
  },
  NAME: {
    get() { return this[NAME]; },
    enumerable: true,
  },
  TARGET_SCOPE: {
    get() { return this[TARGET_SCOPE]; },
    enumerable: true,
  },
  OUTPUT_NAME: {
    get() { return this[OUTPUT_NAME]; },
    set(value) { this[OUTPUT_NAME] = cloneString(value); },
    enumerable: true,
  },
  COMPILE_OPTIONS: {
    get() { return this[COMPILE_OPTIONS]; },
    enumerable: true,
  },
  PREFIX: {
    get() { return this[PREFIX]; },
    set(value) { this[PREFIX] = value; },
    enumerable: true,
  },
  SUFFIX: {
    get() { return this[SUFFIX]; },
    set(value) { this[SUFFIX] = value; },
    enumerable: true,
  },
  LINK_OPTIONS: {
    get() { return this[LINK_OPTIONS]; },
    enumerable: true,
  },
  INCLUDES: {
    get() { return this[INCLUDES]; },
    enumerable: true,
  },
  SOURCES: {
    get() { return this[SOURCES]; },
    enumerable: true,
  },
  LIBRARIES: {
    get() { return this[LIBRARIES]; },
    enumerable: true,
  },
  INSTALL_DESTINATION: {
    get() { return this[INSTALL_DESTINATION]; },
    set(value) { this[INSTALL_DESTINATION] = value; },
    enumerable: true,
  },
  FILE_DIR: {
    get() { return this[TARGET_SCOPE].BINARY_DIR; },
    enumerable: true,
  },
  FILE_NAME: {
    get() { return this.PREFIX + this.OUTPUT_NAME + this.SUFFIX; },
    enumerable: true,
  },
  FILE: {
    get() { return this.FILE_DIR.join(this.FILE_NAME); },
    enumerable: true,
  },
});

BaseTarget.prototype.addSources = function(...sources) {
  for (const iter of sources) {
    for (let it of arrayWrapper(iter))
      this[SOURCES].push(SourceFile.create(this, it));
  }
}

BaseTarget.prototype.addIncludes = function(...includes) {
  for (const iter of includes) {
    for (const it of arrayWrapper(iter)) {
      this[INCLUDES].push(IncludeDirectory.createPrivate(this[TARGET_SCOPE], it));
    }
  }
}

BaseTarget.prototype.addLibraries = function(...libraries) {
  for (const iter of libraries) {
    for (const it of arrayWrapper(iter))
      this[LIBRARIES].push(LinkLibrary.createPrivate(this[TARGET_SCOPE], it));
  }
}

BaseTarget.prototype.addCompileOptions = function(...options) {
  for (const iter of options) {
    for (let it of arrayWrapper(iter))
      this.COMPILE_OPTIONS.push(it);
  }
}

BaseTarget.prototype.addInstallDestination = function(dir) {
  this[INSTALL_DESTINATION] = dir;
}

BaseTarget.prototype.getSourceFiles = function(...sources) {
  const result = [];
  for (const iter of sources) {
    for (let it of arrayWrapper(iter)) {
      const filename = this[TARGET_SCOPE].SOURCE_DIR.resolve(it).toString();
      const src = this[SOURCES].find(i => i.FILE.toString() === filename);
      if (!src)
        throw new Error(`Cannot find "${it}"`);
      result.push(src);
    }
  }
  return SourceFileList.create(this[TARGET_SCOPE], result.length ? result : this[SOURCES]);
}

BaseTarget.prototype.setPrefix = function(prefix) {
  this[PREFIX] = prefix;
}

BaseTarget.prototype.setSuffix = function(suffix) {
  this[SUFFIX] = suffix;
}

BaseTarget.prototype.setOutputName = function(outputName) {
  this[OUTPUT_NAME] = outputName;
}

BaseTarget.prototype.toJSON = function() {
  const json = {};
  for (const key in this)
    json[key] = this[key];
  return json;
}

function BaseLibrary(scope, name) {
  BaseTarget.call(this, scope, name);
}

BaseLibrary.prototype = Object.create(BaseTarget.prototype, {
  constructor: {
    value: BaseLibrary,
    enumerable: false,
    writable: true,
    configurable: true,
  },
});

BaseLibrary.prototype.addPublicIncludes = function(...includes) {
  for (const iter of includes) {
    for (const it of arrayWrapper(iter)) {
      this[INCLUDES].push(IncludeDirectory.createPublic(this[TARGET_SCOPE], it));
    }
  }
}

BaseLibrary.prototype.addPublicLibraries = function(...libraries) {
  for (const iter of libraries) {
    for (const it of arrayWrapper(iter))
      this[LIBRARIES].push(LinkLibrary.createPublic(this[TARGET_SCOPE], it));
  }
}

BaseLibrary.prototype.getPrivateIncludes = function() {
  return this[INCLUDES].filter(i => !i.PUBLIC_ONLY);
}

BaseLibrary.prototype.getPublicIncludes = function() {
  return this[INCLUDES].filter(i => i.PUBLIC_ONLY);
}

function StaticLibrary(scope, name) {
  BaseLibrary.call(this, scope, name);
  this.PREFIX = this[TARGET_SCOPE].STATIC_LIBRARY_PREFIX;
  this.SUFFIX = this[TARGET_SCOPE].STATIC_LIBRARY_SUFFIX;
  this.LINK_OPTIONS.push(...this[TARGET_SCOPE].STATIC_LINKER_FLAGS);
}

StaticLibrary.prototype = Object.create(BaseLibrary.prototype, {
  constructor: {
    value: StaticLibrary,
    enumerable: false,
    writable: true,
    configurable: true,
  },
});

StaticLibrary.create = (scope, name) => {
  return Object.seal(new StaticLibrary(scope, name));
}

function SharedLibrary(scope, name) {
  BaseLibrary.call(this, scope, name);
  this.PREFIX = this[TARGET_SCOPE].SHARED_LIBRARY_PREFIX;
  this.SUFFIX = this[TARGET_SCOPE].SHARED_LIBRARY_SUFFIX;
  this.LINK_OPTIONS.push(...this[TARGET_SCOPE].SHARED_LINKER_FLAGS);
}

SharedLibrary.prototype = Object.create(BaseLibrary.prototype, {
  constructor: {
    value: SharedLibrary,
    enumerable: false,
    writable: true,
    configurable: true,
  },
});

SharedLibrary.create = (scope, name) => {
  return Object.seal(new SharedLibrary(scope, name));
}

function Executable(scope, name) {
  BaseTarget.call(this, scope, name);
  this.SUFFIX = this[TARGET_SCOPE].EXECUTABLE_SUFFIX;
  this.LINK_OPTIONS.push(...this[TARGET_SCOPE].EXE_LINKER_FLAGS);
}

Executable.prototype = Object.create(BaseTarget.prototype, {
  constructor: {
    value: Executable,
    enumerable: false,
    writable: true,
    configurable: true,
  },
});

Executable.create = (scope, name) => {
  return Object.seal(new Executable(scope, name));
}

module.exports = {
  StaticLibrary,
  SharedLibrary,
  Executable,
};
