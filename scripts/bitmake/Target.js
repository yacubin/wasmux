"use strict";

const path = require("node:path");

const { arrayWrapper } = require("###/utils/Primitives.js");
const { AbsolutePath } = require("###/utils/AbsolutePath.js");
const { SourceFile } = require("###/bitmake/SourceFile.js");
const { SourceFileList } = require("###/bitmake/SourceFileList.js");

const NAME            = Symbol("NAME");
const TARGET_SCOPE    = Symbol("TARGET_SCOPE");
const OUTPUT_NAME     = Symbol("OUTPUT_NAME");
const COMPILE_OPTIONS = Symbol("COMPILE_OPTIONS");

function mustBeBoolean(value) {
  if (typeof value === "boolean")
    return value;
  throw new Error(`Value ${value} is not a boolean`);
}

function mustBeString(value) {
  if (typeof value === "string")
    return value;
  throw new Error(`Value ${value} is not a string`);
}

function mustBeAbsolutePath(value) {
  if (value instanceof AbsolutePath)
    return value;
  throw new Error(`Value ${value} is not a AbsolutePath`);
}

function BaseTarget(scope, name) {
  Object.defineProperties(this, {
    PREFIX: {
      value: "",
      writable: true,
      enumerable: true,
    },
    SUFFIX: {
      value: "",
      writable: true,
      enumerable: true,
    },
    LINK_OPTIONS: {
      value: "",
      writable: true,
      enumerable: true,
    },
    INCLUDES: {
      value: [],
      writable: false,
      enumerable: true,
    },
    SOURCES: {
      value: [],
      writable: false,
      enumerable: true,
    },
    LIBRARIES: {
      value: [],
      writable: false,
      enumerable: true,
    },
    INSTALL_DESTINATION: {
      value: null,
      writable: true,
      enumerable: true,
    },
  });
  this[NAME] = name;
  this[TARGET_SCOPE] = scope;
  this[OUTPUT_NAME] = name;
  this[COMPILE_OPTIONS] = [];
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
    set(value) { this[OUTPUT_NAME] = mustBeString(value); },
    enumerable: true,
  },
  COMPILE_OPTIONS: {
    get() { return this[COMPILE_OPTIONS]; },
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
      this.SOURCES.push(SourceFile.create(this, it));
  }
}

BaseTarget.prototype.addIncludes = function(...includes) {
  for (const iter of includes) {
    for (const it of arrayWrapper(iter)) {
      this.INCLUDES.push(this[TARGET_SCOPE].SOURCE_DIR.resolve(it));
    }
  }
}

BaseTarget.prototype.addLibraries = function(...libraries) {
  for (const iter of libraries) {
    for (const it of arrayWrapper(iter))
      this.LIBRARIES.push(it);
  }
}

BaseTarget.prototype.addCompileOptions = function(...options) {
  for (const iter of options) {
    for (let it of arrayWrapper(iter))
      this.COMPILE_OPTIONS.push(it);
  }
}

BaseTarget.prototype.addInstallDestination = function(dir) {
  this.INSTALL_DESTINATION = dir;
}

BaseTarget.prototype.getSourceFiles = function(...sources) {
  const result = [];
  for (const iter of sources) {
    for (let it of arrayWrapper(iter)) {
      const filename = this[TARGET_SCOPE].SOURCE_DIR.resolve(it).toString();
      const src = this.SOURCES.find(i => i.FILE.toString() === filename);
      if (!src)
        throw new Error(`Cannot find "${it}"`);
      result.push(src);
    }
  }
  return SourceFileList.create(this[TARGET_SCOPE], result.length ? result : this.SOURCES);
}

BaseTarget.prototype.toJSON = function() {
  const json = {};
  for (const key in this)
    json[key] = this[key];
  return json;
}

function BaseLibrary(scope, name) {
  BaseTarget.call(this, scope, name);
  Object.defineProperties(this, {
    PUBLIC_INCLUDES: {
      value: [],
      writable: false,
      enumerable: true,
    },
    PUBLIC_LIBRARIES: {
      value: [],
      writable: false,
      enumerable: true,
    },
  });
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
      this.INCLUDES.push(this[TARGET_SCOPE].SOURCE_DIR.resolve(it));
      this.PUBLIC_INCLUDES.push(this[TARGET_SCOPE].SOURCE_DIR.resolve(it));
    }
  }
}

BaseLibrary.prototype.addPublicLibraries = function(...libraries) {
  for (const iter of libraries) {
    for (const it of arrayWrapper(iter)) {
      this.LIBRARIES.push(it);
      this.PUBLIC_LIBRARIES.push(it);
    }
  }
}

function StaticLibrary(scope, name) {
  BaseLibrary.call(this, scope, name);
  this.PREFIX = scope.STATIC_LIBRARY_PREFIX;
  this.SUFFIX = scope.STATIC_LIBRARY_SUFFIX;
  this.LINK_OPTIONS = scope.STATIC_LINKER_FLAGS;
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
  this.PREFIX = scope.SHARED_LIBRARY_PREFIX;
  this.SUFFIX = scope.SHARED_LIBRARY_SUFFIX;
  this.LINK_OPTIONS = scope.SHARED_LINKER_FLAGS;
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
  this.PREFIX = "";
  this.SUFFIX = scope.EXECUTABLE_SUFFIX;
  this.LINK_OPTIONS = scope.EXE_LINKER_FLAGS;
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
