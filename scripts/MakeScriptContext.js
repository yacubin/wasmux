"use strict";

const os = require("node:os");
const fs = require("node:fs");
const path = require("node:path");
const { spawnSync } = require("node:child_process");

const { arrayWrapper, copyValue } = require("###/utils/Primitives.js");
const { fileExistsSync } = require("###/utils/FileSystem.js");
const { AbsolutePath } = require("###/utils/AbsolutePath.js");
const bitmake = require("###/bitmake/index.js");

const MAKE_SCRIPT = "MakeScript.js";
const MAKE_CACHE = "MakeCache.json";

const currentFunctionName = () => {
  const stack = new Error().stack.split("\n")[2];
  return stack.match(/at (\S+)/)?.[1];
};

function cloneScopeValue(o) {
  if (typeof o === "undefined")
    return o;
  if (typeof o === "boolean")
    return o;
  if (typeof o === "number")
    return o;
  if (typeof o === "string")
    return o;
  if (typeof o === "object") {
    if (!o)
      return o;
    if (o instanceof AbsolutePath) {
      return new AbsolutePath(o.toString());
    }
    if (o instanceof Array) {
      const result = [];
      for (const i of o)
        result.push(cloneScopeValue(i));
      return result;
    }
    if (o instanceof Object) {
      const result = {};
      for (const [k,v] of Object.entries(o))
        result[k] = cloneScopeValue(v);
      return result;
    }
  }
  throw new Error(`Unknown instance of ${o}`);
}

function scopeValueAsPrimitives(o) {
  if (typeof o === "undefined")
    return o;
  if (typeof o === "boolean")
    return o;
  if (typeof o === "number")
    return o;
  if (typeof o === "string")
    return o;
  if (typeof o === "object") {
    if (!o)
      return o;
    if (o instanceof AbsolutePath) {
      return o.toString();
    }
    if (o instanceof Array) {
      const result = [];
      for (const i of o)
        result.push(scopeValueAsPrimitives(i));
      return result;
    }
    if (o instanceof Object) {
      const result = {};
      for (const [k,v] of Object.entries(o))
        result[k] = scopeValueAsPrimitives(v);
      return result;
    }
  }
  throw new Error(`Unknown instance of ${o}`);
}

const SCRIPT_GOAL = "script";
const EXEC_GOAL = "exec";
const TARGET_GOAL = "target";

class GoalList {
  _list = [];

  findScriptByOutput(output) {
    if (!output)
      return undefined;
    return this._list.find((i) => i.type === SCRIPT_GOAL && i.output === output);
  }

  hasScriptByOutput(output) {
    return !!this.findScriptByOutput(output);
  }

  addScript(script, name, depends, output, params, msg) {
    if (this.hasScriptByOutput(output.toString()))
      throw new Error(`Output "${output}" exists`);
    this._list.push({ name, type: SCRIPT_GOAL, script, output, depends, params, msg });
  }

  addExec(output, depends, command, args, cwd, msg) {
    this._list.push({ name: "", type: EXEC_GOAL, depends, output, command, args, cwd, msg });
  }

  addTarget(name, depends, msg) {
    this._list.push({ name, type: TARGET_GOAL, depends, msg });
  }

  getTarget(name) {
    return this._list.find((i) => i.type === TARGET_GOAL && i.name === name);
  }

  addTargetListImpl(name, result) {
    if (result.find(i => i.name === name || i.output === name)) {
      return;
    }

    const goal = this._list.find(i => i.name === name || i.output === name);
    if (!goal) {
      return;
    }

    for (const iter of goal.depends) {
      this.addTargetListImpl(iter.toString(), result);
    }

    result.push(goal);
  }

  getTargetList(name) {
    const result = [];
    this.addTargetListImpl(name, result);
    return result;
  }

  valueOf() {
    return this._list;
  }
};

function createMakeScriptContext()
{
  const _priv = {
    targets: {},
    goals: new GoalList,
    cache: {},
    refTrgets: {},
  };

  function MakeScriptContext() {
  }

  function makeLogger(loggerFunc, withTag) {
    if (!loggerFunc)
      return () => {};
    return function() {
      const list = [];
      if (withTag)
        list.push("[" + this.__logTag() + "]");
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
  MakeScriptContext.prototype.logDebug = makeLogger(/*console.debug*/);
  MakeScriptContext.prototype.logWarn = makeLogger(console.warn);
  MakeScriptContext.prototype.logError = makeLogger(console.error);

  MakeScriptContext.prototype.__logTag = function() {
    const tag = this.PROJECT_SOURCE_DIR.relative(this.SOURCE_DIR);
    return path.posix.join(this.PROJECT_NAME, tag);
  }

  MakeScriptContext.prototype.__loadCacheVariables = function() {
    this.logDebug(currentFunctionName());
    const filename = this.PROJECT_BINARY_DIR.join(MAKE_CACHE).toString();
    if (fileExistsSync(filename)) {
      this.addCacheVariables(filename);
    }
  }

  MakeScriptContext.prototype.__syncCacheVariables = function() {
    this.logDebug(currentFunctionName());
    const filename = this.PROJECT_BINARY_DIR.join(MAKE_CACHE).toString();
    const json = JSON.stringify(_priv.cache, null, 2);
    fs.writeFileSync(filename, json, "utf-8");
  }

  MakeScriptContext.prototype.getCacheVariables = function() {
    this.logDebug(currentFunctionName());
    const result = {};
    for (const [key, entry] of Object.entries(_priv.cache)) {
      const value = copyValue(this[key]);
      result[key] = {
        type: copyValue(entry.type) || typeof value,
        description: entry.description || "",
        value,
      };
    }
    return result;
  }

  MakeScriptContext.prototype.addCacheVariables = function(params) {
    this.logDebug(currentFunctionName());

    let variables = params;

    if (typeof variables === "string") {
      const scripts = this.SOURCE_DIR.resolve(variables);
      variables = require(scripts.toString());
    }
    
    if (typeof variables !== "object") {
      throw "Only object type is supported";
    }

    for (const [key, entry] of Object.entries(variables)) {
      _priv.cache[key] = entry;
      if (!Object.hasOwn(this, key)) {
        this[key] = entry.value;
      }
    }
  }

  MakeScriptContext.prototype.addIncludeDirectories = function(...dirs) {
    this.logDebug(currentFunctionName());

    for (const iter of dirs) {
      for (const dirpath of arrayWrapper(iter)) {
        this.INCLUDES.push(dirpath);
      }
    }
  }

  MakeScriptContext.prototype.addSubdirectory = function(sourceDir, binaryDir) {
    this.logDebug(currentFunctionName());

    binaryDir = binaryDir || path.isAbsolute(sourceDir) ? undefined : sourceDir;

    const SOURCE_DIR = path.isAbsolute(sourceDir) ? new AbsolutePath(sourceDir) : this.SOURCE_DIR.join(sourceDir);
    const BINARY_DIR = path.isAbsolute(binaryDir) ? new AbsolutePath(binaryDir) : this.BINARY_DIR.join(binaryDir);

    this.__applyDirectory(SOURCE_DIR, BINARY_DIR);
  }

  MakeScriptContext.prototype.__applyDirectory = function(sourceDir, binaryDir) {
    this.logDebug(currentFunctionName(), scopeValueAsPrimitives(sourceDir), scopeValueAsPrimitives(binaryDir));

    const newMake = this.__clone();

    newMake.SOURCE_DIR = sourceDir;
    newMake.BINARY_DIR = binaryDir;
    newMake.SCRIPT_FILE = newMake.SOURCE_DIR.join(MAKE_SCRIPT);

    const module = require(newMake.SCRIPT_FILE.toString());
    module(newMake);
    // newMake.dump();
    this.__syncCacheVariables();
  }

  MakeScriptContext.prototype.addCustomTarget = function(name, params) {
    this.logDebug(currentFunctionName(), name);

    const target = bitmake.CustomTarget.create(this, name);
    this.__addTarget(name, target);
    if (params && params.script)
      target.addScript(params.script, params);
    else
      throw new Error(`Uknown params ${JSON.stringify(params)}`);
    return target;
  }

  MakeScriptContext.prototype.target = function(name) {
    this.logDebug(currentFunctionName(), name);

    let target = _priv.refTrgets[name];
    if (!target) {
      target = bitmake.InterfaceTarget.create(name);
      _priv.refTrgets[name] = target;
    }

    return target;
  }

  MakeScriptContext.prototype.dump = function() {
    this.logDebug(currentFunctionName());

    const printedValues = {};

    let current = this;
    let deep = 0;
    while (current instanceof MakeScriptContext) {
      const space = deep ? "  ".repeat(deep) : "";
      for (const [key, val] of Object.entries(current)) {
        if (Object.hasOwn(printedValues, key))
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

    for (const [name, target] of Object.entries(_priv.targets)) {
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

  MakeScriptContext.prototype.__saveTargetsAsJSON = function(filename) {
    this.logDebug(currentFunctionName(), filename);
    const json = {
      TARGETS: _priv.targets,
      GOALS: _priv.goals.valueOf(),
      CACHE: _priv.cache,
    };
    const content = JSON.stringify(json, null, 2);
    fs.mkdirSync(path.dirname(filename), { recursive: true });
    fs.writeFileSync(filename, content, { encoding: "utf8" });
  }

  MakeScriptContext.prototype.__addTarget = function(name, target) {
    this.logDebug(currentFunctionName(), name);

    if (_priv.targets[name])
      throw new Error(`Target "${name}" exists`);
    _priv.targets[name] = target;
  }

  MakeScriptContext.prototype.addStaticLibrary = function(name, ...sources) {
    this.logDebug(currentFunctionName(), name);

    const target = bitmake.StaticLibrary.create(this, name);
    this.__addTarget(name, target);

    target.addSources(...sources);
    return target;
  }

  MakeScriptContext.prototype.addSharedLibrary = function(name, ...sources) {
    this.logDebug(currentFunctionName(), name);

    const target = bitmake.SharedLibrary.create(this, name);
    this.__addTarget(name, target);

    target.addSources(...sources);
    return target;
  }

  MakeScriptContext.prototype.addExecutable = function(name) {
    this.logDebug(currentFunctionName(), name);

    const target = bitmake.Executable.create(this, name);
    this.__addTarget(name, target);

    target.addSources(...sources);
    return target;
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

  MakeScriptContext.prototype.executeScript = function(script, options) {
    this.logDebug(currentFunctionName(), script);
    const scriptPath = this.SOURCE_DIR.resolve(script);
    const module = require(scriptPath.toString());
    module(scopeValueAsPrimitives(options));
  }

  function getAllIncludesImpl(includes, targetSet, list) {
    for (const iter of list) {
      if (iter instanceof bitmake.InterfaceIncludes || iter instanceof bitmake.InterfaceTarget) {
        if (!targetSet.has(iter.NAME)) {
          targetSet.add(iter.NAME);
          const target = _priv.targets[iter.NAME];
          getAllIncludesImpl(includes, targetSet, target.getPublicIncludes());
          getAllIncludesImpl(includes, targetSet, target.getPublicLibraries());
        }
      }
      else if (iter instanceof bitmake.IncludeDirectory) {
        if (!includes.includes(iter.toString()))
          includes.push(iter.toString());
      }
      else {
        throw new Error(`Not support instance ${iter}`);
      }
    }
  }

  function getAllIncludes(target) {
    const includes = target.TARGET_SCOPE.INCLUDES.map(i => i.toString());
    const targetSet = new Set;
    getAllIncludesImpl(includes, targetSet, target.getIncludes());
    getAllIncludesImpl(includes, targetSet, target.getLibraries());
    return includes;
  }

  function getAllHeadersImpl(headers, targetSet, list) {
    for (const iter of list) {
      if (iter instanceof bitmake.InterfaceIncludes || iter instanceof bitmake.InterfaceTarget) {
        if (!targetSet.has(iter.NAME)) {
          targetSet.add(iter.NAME);
          const target = _priv.targets[iter.NAME];
          for (const header of target.getHeaders().map(i => i.FILE.toString())) {
            if (!headers.includes(header.toString()))
              headers.push(header.toString());
          }
          getAllHeadersImpl(headers, targetSet, target.getPublicIncludes());
          getAllHeadersImpl(headers, targetSet, target.getPublicLibraries());
        }
      }
    }
  }

  function getAllHeaders(target) {
    const headers = target.getHeaders().map(i => i.FILE.toString());
    const targetSet = new Set;
    getAllHeadersImpl(headers, targetSet, target.getIncludes());
    getAllHeadersImpl(headers, targetSet, target.getLibraries());
    return headers;
  }

  MakeScriptContext.prototype.__populateObjectGoals = async function() {
    this.logDebug(currentFunctionName());

    const install_script = "install_script";
    const install_files = [];

    for (const [name, target] of Object.entries(_priv.targets)) {
      if (target instanceof bitmake.CustomTarget) {
        for (const script of target.SCRIPTS) {      
          const depends = [ script.FILE.toString() ];
          if (script.INPUT)
            depends.push(script.INPUT.toString());
          const msg = "Generating " + target.TARGET_SCOPE.BINARY_DIR.relative(script.OUTPUT);
          _priv.goals.addScript(script.FILE, "", depends, script.OUTPUT.toString(), script.PARAMS, msg);
        }
        continue;
      }

      const headers = getAllHeaders(target);
      const depends = [];
      for (const s of target.SOURCES) {
        if (s instanceof bitmake.InterfaceObjects) {
          const t = _priv.targets[s.NAME];
          for (const f of t.SOURCES) {
            if (f instanceof bitmake.SourceFile && !f.INSTALL_FILE)
              depends.push(f.OBJECT_FILE.toString());
          }
          continue;
        }

        if (s.INSTALL_FILE) {
          const src = s.FILE.toString();
          const dest = s.INSTALL_FILE.toString();
          _priv.goals.addScript(install_script, "", [ src ], dest, {src, dest}, "");
          install_files.push(dest);
        }

        if (s.HEADER_FILE_ONLY)
          continue;

        fs.mkdirSync(s.OBJECT_FILE_DIR.toString(), { recursive: true });

        const relativeObject = target.TARGET_SCOPE.BINARY_DIR.relative(s.OBJECT_FILE);
        const relativeBinaryDir = this.PROJECT_BINARY_DIR.relative(target.TARGET_SCOPE.BINARY_DIR);
        const msg = `Building ${s.LANGUAGE} object ${relativeBinaryDir}/${relativeObject}`;

        const args = [];
        args.push(...target.TARGET_SCOPE[s.LANGUAGE + "_FLAGS"]);
        args.push(...target.TARGET_SCOPE[s.LANGUAGE + "_FLAGS_" + target.TARGET_SCOPE.BUILD_TYPE.toUpperCase()]);
        args.push(...target.COMPILE_OPTIONS);
        args.push(...s.COMPILE_FLAGS);
        args.push(...getAllIncludes(target).map(i => "-I" + i));
        args.push("-o", relativeObject);
        args.push("-c", s.FILE);
        const cwd = target.TARGET_SCOPE.BINARY_DIR.toString();

        const command = target.TARGET_SCOPE[s.LANGUAGE + "_COMPILER"].toString();
        const output = target.TARGET_SCOPE.BINARY_DIR.join(relativeObject).toString();
        depends.push(output);

        _priv.goals.addExec(output, [ ...headers, s.FILE ], command, args, cwd, msg);
      }

      if (target instanceof bitmake.StaticLibrary) {
        const args = [ "rc", target.FILE_NAME ];
        for (const iter of depends) {
          if (iter.endsWith(".o") || iter.endsWith(".obj"))
            args.push(target.FILE_DIR.relative(iter));
        }
        const cwd = target.FILE_DIR.toString();
        const msg = `Linking CXX static library ${target.FILE_NAME}`;
        _priv.goals.addExec(target.FILE.toString(), depends, this.AR, args, cwd, msg);
      }

      if (target instanceof bitmake.SharedLibrary) {
        throw new Error("Not implemented");
      }

      if (target instanceof bitmake.Executable) {
        const msg = `Linking CXX executable ${target.FILE_NAME}`;
      }

      _priv.goals.addTarget(name, [ target.FILE.toString() ], `Built target ${name}`);

      if (target.INSTALL_DESTINATION !== null) {
        let src = target.FILE.toString();
        let dest = target.INSTALL_DESTINATION;
        dest = path.isAbsolute(dest) ? dest : path.posix.join(this.INSTALL_PREFIX, dest);
        dest = path.posix.join(this.DESTDIR, dest, path.basename(src));
        _priv.goals.addScript(install_script, "", [ src ], dest, {src, dest}, "");
        install_files.push(dest);
      }
    }

    _priv.goals.addTarget("install", install_files, "");
    _priv.goals.addTarget("all", Object.keys(_priv.targets), "");
  }

  MakeScriptContext.prototype.__build = function(target) {
    const goalList = _priv.goals.getTargetList(target);

    {
      const filename = this.BINARY_DIR.join("GoalList.json").toString();
      const content = JSON.stringify(goalList, null, 2);
      fs.mkdirSync(path.dirname(filename), { recursive: true });
      fs.writeFileSync(filename, content, { encoding: "utf8" });
    }

    let msgCount = 0;
    for (const iter of goalList)
      msgCount += iter.msg ? 1 : 0;

    let msgIndex = 0;
    for (const goal of goalList) {
      const { type, msg } = goal;
      if (msg) {
        const relationOfLength = Math.round((++msgIndex / msgCount) * 100);
        const percent = "[" + relationOfLength.toString().padStart(3, " ") + "%] ";
        this.logInfo(percent + msg);
      }
      if (type === SCRIPT_GOAL) {
        const { script, params } = goal;
        const module = require(script.toString());
        module(scopeValueAsPrimitives(params));
      }
      else if (type === EXEC_GOAL) {
        const { command, args, cwd, output } = goal;
        fs.mkdirSync(path.posix.dirname(output), { recursive: true });
        const result = spawnSync(command, args, { cwd, encoding: "utf-8" });
        if (result.status) {
          this.logInfo("cd " + cwd);
          let cmd = args.join(" ");
          cmd = command + (cmd ? " " : "") + cmd;
          this.logInfo(cmd);
          this.logInfo("");

          this.logError(result.stderr);

          throw new Error("Status " + result.status);
        }
      }
      else if (type === TARGET_GOAL) {
      }
    }
  }

  MakeScriptContext.prototype.__clone = function() {
    const proto = Object.getPrototypeOf(this);
    const o = Object.create(proto);
    for (const [k,v] of Object.entries(this))
      o[k] = cloneScopeValue(v);
    return o;
  }

  return MakeScriptContext;
}

async function actionMakeScript(config, environment, settings)
{
  process.env = environment;

  const Constructor = createMakeScriptContext();
  const root = new Constructor;

  root.SYSTEM_NAME = "Linux";

  root.PROJECT_SOURCE_DIR = new AbsolutePath(config.sourceDir);
  root.PROJECT_BINARY_DIR = new AbsolutePath(config.binaryDir);
  root.BUILD_TYPE = config.buildType;
  root.SOURCE_DIR = root.PROJECT_SOURCE_DIR;
  root.BINARY_DIR = root.PROJECT_BINARY_DIR;

  const pkg = require(root.SOURCE_DIR.join("package.json").toString());

  root.PROJECT_NAME = pkg.name;
  root.PROJECT_VERSION = pkg.version;

  root.DESTDIR = config.destDir || "";

  root.MODULE_PATH = [];
  root.INCLUDES = [];
  root.ASM_FLAGS = [];
  root.ASM_FLAGS_DEBUG = [];
  root.ASM_FLAGS_RELEASE = [];
  root.C_FLAGS = [];
  root.C_FLAGS_DEBUG = [ "-DNDEBUG" ];
  root.C_FLAGS_RELEASE = [];
  root.CXX_FLAGS = [];
  root.CXX_FLAGS_DEBUG = [ "-DNDEBUG" ];
  root.CXX_FLAGS_RELEASE = [];
  root.STATIC_LIBRARY_PREFIX = "lib";
  root.STATIC_LIBRARY_SUFFIX = ".a";
  root.STATIC_LINKER_FLAGS = [];
  root.SHARED_LIBRARY_PREFIX = "lib";
  root.SHARED_LIBRARY_SUFFIX = ".so";
  root.SHARED_LINKER_FLAGS = [];
  root.EXECUTABLE_SUFFIX = "";
  root.EXE_LINKER_FLAGS = [];

  if (config.variables) {
    for (const [key, val] of Object.entries(config.variables))
      root[key] = val;
  }

  if (root.TOOLCHAIN_NAME) {
    const filename = `scripts/toolchain/${root.TOOLCHAIN_NAME}.js`;
    const toolchain = require(root.PROJECT_SOURCE_DIR.join(filename).toString());
    toolchain(root);
  }

  root.__loadCacheVariables();
  root.__applyDirectory(root.PROJECT_SOURCE_DIR, root.PROJECT_BINARY_DIR);
  root.logInfo("Configuring done");
  // root.__populateOutputs();
  root.__populateObjectGoals();
  root.__saveTargetsAsJSON(root.PROJECT_BINARY_DIR.join("MakePriv.json").toString());
  root.__build("all");
}

module.exports = {
  actionMakeScript,
};
