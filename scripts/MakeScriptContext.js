const os = require("node:os");
const fs = require("node:fs");
const path = require("node:path");

const { arrayWrapper } = require("###/utils/Primitives.js");
const { fileExistsSync } = require("###/utils/FileSystem.js");
const { AbsolutePath } = require("###/utils/AbsolutePath.js");

const MAKE_SCRIPT = "MakeScript.js";

const currentFunctionName = () => {
  const stack = new Error().stack.split("\n")[2];
  return stack.match(/at (\S+)/)?.[1];
};

function MakeScriptContext() {
  this.__TARGETS = {};
}

function makeLogger(loggerFunc) {
  return function() {
    const list = [ "[" + this.__logTag() + "]" ];
    for (const iter of arguments) {
      if (iter && typeof iter === "object")
        list.push(JSON.stringify(iter));
      else
        list.push(iter.toString());
    }
    loggerFunc(list.join(" "));
  };
}

MakeScriptContext.prototype.logDefault = makeLogger(console.log);
MakeScriptContext.prototype.logInfo = makeLogger(console.info);
MakeScriptContext.prototype.logDebug = makeLogger(console.debug);
MakeScriptContext.prototype.logWarn = makeLogger(console.warn);
MakeScriptContext.prototype.logError = makeLogger(console.error);

MakeScriptContext.prototype.__logTag = function() {
  const tag = this.SOURCE_DIR.relative(this.CURRENT_SOURCE_DIR);
  return path.posix.join(this.PROJECT_NAME, tag);
}

MakeScriptContext.prototype.addVariables = function(filepath) {
  this.logDebug(currentFunctionName());
}

MakeScriptContext.prototype.addIncludeDirectories = function(...dirs) {
  this.logDebug(currentFunctionName());

  for (const iter of dirs) {
    for (const dirpath of arrayWrapper(iter)) {
      this.INCLUDE_DIRECTORIES.push(dirpath);
    }
  }
}

MakeScriptContext.prototype.__scopeArrayConcat = function(name) {
  this.logDebug(currentFunctionName());

  let result = [];
  let current = this;
  while (current instanceof MakeScriptContext) {
    result = current[name].concat(result);
    current = Object.getPrototypeOf(current);
  }

  return result;
}

MakeScriptContext.prototype.addSubdirectory = function(sourceDir, binaryDir) {
  this.logDebug(currentFunctionName());

  binaryDir = binaryDir || path.isAbsolute(sourceDir) ? undefined : sourceDir;

  const SOURCE_DIR = path.isAbsolute(sourceDir) ? new AbsolutePath(sourceDir) : this.CURRENT_SOURCE_DIR.join(sourceDir);
  const BINARY_DIR = path.isAbsolute(binaryDir) ? new AbsolutePath(binaryDir) : this.CURRENT_BINARY_DIR.join(binaryDir);
  
  this.__applyDirectory(SOURCE_DIR, BINARY_DIR);
}

MakeScriptContext.prototype.__init = function() {
  this.logDebug(currentFunctionName());

  this.MODULE_PATH = [];
  this.INCLUDE_DIRECTORIES = [];
  this.ASM_FLAGS = [];
  this.C_FLAGS = [];
  this.CXX_FLAGS = [];
  this.SHARED_LINKER_FLAGS = [];
  this.EXE_LINKER_FLAGS = [];
}

MakeScriptContext.prototype.__applyDirectory = function(sourceDir, binaryDir) {
  this.logDebug(currentFunctionName(), sourceDir, binaryDir);

  const scope = Object.create(this);

  scope.CURRENT_SOURCE_DIR = sourceDir;
  scope.CURRENT_BINARY_DIR = binaryDir;
  scope.CURRENT_SCRIPT_FILE = scope.CURRENT_SOURCE_DIR.join(MAKE_SCRIPT);

  scope.__init();

  const module = require(scope.CURRENT_SCRIPT_FILE.toString());
  module(scope);
  // scope.dump();
}

MakeScriptContext.prototype.addCustomTarget = function(target, options) {
  this.logDebug(currentFunctionName(), target);

  if (!options || !options.script)
    throw new Error("Script file not specified");

  if (this.__TARGETS[target])
    throw new Error(`Target "${target}" exists`);

  this.__TARGETS[target] = {
    TYPE: "script",
    OPTIONS: options,
  };
}

MakeScriptContext.prototype.dump = function() {
  this.logDebug(currentFunctionName());

  const printedValues = {};

  let current = this;
  let deep = 0;
  while (current instanceof MakeScriptContext) {
    const space = deep ? "  ".repeat(deep) : "";
    for (const [key, val] of Object.entries(current)) {
      if (key === "__TARGETS" || Object.hasOwn(printedValues, key))
        continue;
      this.logInfo(`${space}${key}: ${val}`);
      printedValues[key] = val;
    }
    current = Object.getPrototypeOf(current);
    deep++;
  }
}

MakeScriptContext.prototype.dumpTargets = function() {
  this.logDebug(currentFunctionName());

  for (const [name, target] of Object.entries(this.__TARGETS)) {
    this.logInfo(`${name}:`);
    for (const [key, entry] of Object.entries(target)) {
      if (entry && typeof entry === "object") {
        this.logInfo(`  ${key}:`);
        for (const [k, v] of Object.entries(entry))
          this.logInfo(`    ${k}: ${JSON.stringify(v)}`);
      }
      else {
        this.logInfo(`  ${key}: ${JSON.stringify(entry)}`);
      }
    }
  }
}

MakeScriptContext.prototype.saveTargetsAsJSON = async function(filename) {
  this.logDebug(currentFunctionName(), filename);
  
  const content = JSON.stringify(this.__TARGETS, null, 2);
  await fs.promises.mkdir(path.dirname(filename), { recursive: true });
  await fs.promises.writeFile(filename, content, { encoding: "utf8" });
}

MakeScriptContext.prototype.__addTarget = function(name, type) {
  this.logDebug(currentFunctionName(), name, type);

  if (this.__TARGETS[name])
    throw new Error(`Target "${name}" exists`);

  this.__TARGETS[name] = {
    NAME: name,
    TYPE: type,
    SOURCE_DIR: this.CURRENT_SOURCE_DIR,
    BINARY_DIR: this.CURRENT_BINARY_DIR,
    INCLUDE_DIRECTORIES: this.__scopeArrayConcat("INCLUDE_DIRECTORIES"),
    ASM_COMPILER: this.ASM_COMPILER,
    ASM_FLAGS: this.__scopeArrayConcat("ASM_FLAGS"),
    C_COMPILER: this.C_COMPILER,
    C_FLAGS: this.__scopeArrayConcat("C_FLAGS"),
    CXX_COMPILER: this.CXX_COMPILER,
    CXX_FLAGS: this.__scopeArrayConcat("CXX_FLAGS"),
    SHARED_LINKER_FLAGS: this.__scopeArrayConcat("SHARED_LINKER_FLAGS"),
    EXE_LINKER_FLAGS: this.__scopeArrayConcat("EXE_LINKER_FLAGS"),
    INCLUDES: [],
    LIBRARIES: [],
    SOURCES: [],
    INSTALL_HEADERS: [],
  };

  return Object.seal({
    addSources: (...sources) => this.targetSources(name, ...sources),
    addIncludeDirectories: (includes, options) => this.targetIncludeDirectories(name, includes, options),
    addPublicIncludes: (...includes) => this.targetPublicInclude(name, ...includes),
    addIncludes: (...includes) => this.targetInclude(name, ...includes),
    addInstallHeaders: (headers, options) => this.targetInstallHeaders(name, headers, options),
    addPublicLibraries: (...libraries) => this.targetPublicLibraries(name, ...libraries),
    addLibraries: (...libraries) => this.targetLibraries(name, ...libraries),
    addLinkLibraries: (libraries, options) => this.targetLinkLibraries(name, libraries, options),
    addInstallDestination: (options) => this.targetInstallDestination(name, options),
  });
}

MakeScriptContext.prototype.addStaticLibrary = function(name, ...sources) {
  this.logDebug(currentFunctionName(), name);

  const target = this.__addTarget(name, "library");
  target.addSources(...sources);
  return target;
}

MakeScriptContext.prototype.addExecutable = function(name) {
  this.logDebug(currentFunctionName(), name);

  const target = this.__addTarget(name, "executable");
  target.addSources(...sources);
  return target;
}

MakeScriptContext.prototype.__target = function(name) {
  this.logDebug(currentFunctionName(), name);

  const target = this.__TARGETS[name];
  if (!target) {
    throw `Target ${name} does not exist`;
  }

  return target;
}

MakeScriptContext.prototype.__toAbsolutePath = function(filepath) {
  this.logDebug(currentFunctionName(), filepath);

  if (filepath instanceof AbsolutePath)
    return filepath;

  if (typeof filepath !== "string")
    throw `Not correct type of ${filepath}`;

  if (path.isAbsolute(filepath))
    return new AbsolutePath(filepath);
  
  return this.CURRENT_SOURCE_DIR.join(filepath);
}

MakeScriptContext.prototype.targetSources = function(name, ...sources) {
  this.logDebug(currentFunctionName(), name);

  const result = [];
  const target = this.__target(name);
  for (const it of sources) {
    for (let iter of arrayWrapper(it)) {
      result.push(iter);
      target.SOURCES.push(this.__toAbsolutePath(iter));
    }
  }

  return result;
}

MakeScriptContext.prototype.targetIncludeDirectories = function(name, includes, options) {
  this.logDebug(currentFunctionName(), name);

  const target = this.__target(name);
  const public = !!(options && options.public);
  for (const value of arrayWrapper(includes)) {
    target.INCLUDES.push({ value, public });
  }
}

MakeScriptContext.prototype.__targetInclude = function(name, public, ...includes) {
  this.logDebug(currentFunctionName(), name);

  const target = this.__target(name);
  for (const it of includes) {
    for (const value of arrayWrapper(it))
      target.INCLUDES.push({ value, public });
  }
}

MakeScriptContext.prototype.targetPublicInclude = function(name, ...includes) {
  this.logDebug(currentFunctionName(), name);
  return this.__targetInclude(name, true, ...includes);
}

MakeScriptContext.prototype.targetInclude = function(name, ...includes) {
  this.logDebug(currentFunctionName(), name);
  return this.__targetInclude(name, false, ...includes);
}

MakeScriptContext.prototype.targetInstallHeaders = function(name, headers, options) {
  this.logDebug(currentFunctionName(), name);

  const target = this.__target(name);
  const baseDir = options && options?.baseDir.toString();
  for (let value of arrayWrapper(headers)) {
    if (baseDir && AbsolutePath.isAbsolute(baseDir) && !AbsolutePath.isAbsolute(value))
      throw new Error("Header path shoulbe the same kind as baseDir");
    const source = this.__toAbsolutePath(value).toString();
    let destination = ".";
    if (baseDir) {
      const from = this.__toAbsolutePath(baseDir);
      if (!source.toString().startsWith(from.toString()))
        throw new Error("The baseDir is not base dir");
      destination = path.posix.dirname(from.relative(source));
    }
    target.INSTALL_HEADERS.push({ source, destination });
  }
}

MakeScriptContext.prototype.__targetLibraries = function(name, public, ...libraries) {
  this.logDebug(currentFunctionName(), name);

  const target = this.__target(name);
  for (const it of libraries) {
    for (const value of arrayWrapper(it))
      target.LIBRARIES.push({ value, public });
  }
}

MakeScriptContext.prototype.targetLibraries = function(name, ...libraries) {
  this.logDebug(currentFunctionName(), name);
  return this.__targetLibraries(name, false, ...libraries);
}

MakeScriptContext.prototype.targetPublicLibraries = function(name, ...libraries) {
  this.logDebug(currentFunctionName(), name);
  return this.__targetLibraries(name, true, ...libraries);
}

MakeScriptContext.prototype.targetLinkLibraries = function(name, libraries, options) {
  this.logDebug(currentFunctionName(), name);

  const target = this.__target(name);
  const public = !!(options && options.public);
  for (const value of arrayWrapper(libraries)) {
    target.LIBRARIES.push({ value, public });
  }
}

MakeScriptContext.prototype.targetInstallDestination = function(name, options) {
  this.logDebug(currentFunctionName(), name);
}

MakeScriptContext.prototype.findProgram = function(name) {
  this.logDebug(currentFunctionName(), name);

  if (os.platform() === "win32" && !name.endsWith(".exe"))
    name += ".exe";

  const paths = process.env.PATH.split(path.posix.delimiter);
  for (const iter of paths) {
    const filename = path.posix.resolve(iter, name);
    if (fileExistsSync(filename))
      return filename;
  }

  return null;
}

MakeScriptContext.prototype.__build = async function() {
  this.logDebug(currentFunctionName());

  for (const [name, target] of Object.entries(this.__TARGETS)) {
    if (target.TYPE === "library") {
      const targetDir = target.BINARY_DIR.join("MakeScript", name + ".dir");
      await fs.promises.mkdir(targetDir.toString(), { recursive: true });
    }
  }
}

async function actionMakeScript(config, environment, settings)
{
  process.env = environment;

  const root = new MakeScriptContext;

  root.SYSTEM_NAME = "Linux";

  root.SOURCE_DIR = new AbsolutePath(config.sourceDir);
  root.BINARY_DIR = new AbsolutePath(config.binaryDir);
  root.PROJECT_DIR = root.SOURCE_DIR;

  root.DESTDIR = config.destDir || "";

  root.CURRENT_SOURCE_DIR = root.SOURCE_DIR;
  root.CURRENT_BINARY_DIR = root.BINARY_DIR;

  const pkg = require(root.SOURCE_DIR.join("package.json").toString());

  root.PROJECT_NAME = pkg.name;
  root.PROJECT_VERSION = pkg.version;

  root.__init();

  if (config.variables) {
    for (const [key, val] of Object.entries(config.variables))
      root[key] = val;
  }

  if (root.TOOLCHAIN_NAME) {
    const filename = `scripts/toolchain/${root.TOOLCHAIN_NAME}.js`;
    const toolchain = require(root.SOURCE_DIR.join(filename).toString());
    toolchain(root);
  }

  root.__applyDirectory(root.SOURCE_DIR, root.BINARY_DIR);
  await root.saveTargetsAsJSON(root.BINARY_DIR.join("Targets.json").toString());

  await root.__build();
}

module.exports = {
  actionMakeScript,
};
