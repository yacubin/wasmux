import path from 'node:path';
import url from 'node:url';

import { saveIfDifferent } from "###/utils/FileSystem.js";
import * as CXX from "###/utils/CXX.js";
import * as CMake from "###/utils/CMake.js";

async function linesSaveTo(filename, lines)
{
  await saveIfDifferent(filename, lines.join('\n'));
}

class InjectHooks {
  _callbacks = {};

  on(name, callback)
  {
    if (!this._callbacks[name])
      this._callbacks[name] = [];
    this._callbacks[name].push(callback);
  }

  async emit(name, event)
  {
    if (this._callbacks[name]) {
      for (const callback of this._callbacks[name]) {
        const res = callback(event);
        if (res instanceof Promise)
          await res;
      }
    }
  }
};

function transformCMakeConfigToObject(config)
{
  const result = {};
  for (const [key, entry] of Object.entries(config)) {
    if (entry.type === "boolean") {
      result[key] = entry.value.toUpperCase() === "ON" || entry.value.toUpperCase() === "TRUE";
    }
    else if (entry.type === "number") {
      result[key] = entry.value;
    }
    else if (entry.type === "string") {
      result[key] = entry.value;
    }
    else if (entry.type === "strings") {
      result[key] = entry.value ? entry.value.split(";") : [];
    }
    else if (Array.isArray(entry.type)) {
      result[key] = entry.value;
    }
    else {
      throw `Not supported type ${entry.type}`;
    }
  }
  return result;
}

class ErrnoModule {
  _ctx;
  _config = {
    errors: {},
    aliases: {},
  };

  constructor(ctx)
  {
    this._ctx = ctx;
  }

  async loadConfig(filename)
  {
    const fileUrl = url.pathToFileURL(filename);
    const module = await import(fileUrl);
    if (module.errors)
      this._config.errors = module.errors;
    if (module.aliases)
      this._config.aliases = module.aliases;
  }

  async triggerEvent()
  {
    await this._ctx.hooks.emit("errno.config", this._config);
  }

  async saveHeader(filename)
  {
    let errors = [];
    let aliases = [];

    let maxNameLength = 0;
    let maxCodeLength = 0;
    for (const [name, entry] of Object.entries(this._config.errors)) {
      maxNameLength = Math.max(maxNameLength, name.length);
      maxCodeLength = Math.max(maxCodeLength, entry.code.toString().length);
      errors.push({ name, ...entry });
    }

    for (const [name, alias] of Object.entries(this._config.aliases)) {
      maxNameLength = Math.max(maxNameLength, name.length);
      const entry = this._config.errors[alias];
      aliases.push({ name, ...entry, alias });
    }

    let nameSpace = " ".repeat(maxNameLength);
    let codeSpace = " ".repeat(maxNameLength);
    errors = errors.sort((a, b) => a.code - b.code);
    aliases = aliases.sort((a, b) => a.code - b.code);

    const lines = [];

    const pragmaOnce = CXX.filepathToMacroCIdentifier(filename);
    lines.push(CXX.generatedScriptNameComment(this._ctx.entryScript));
    lines.push("");
    lines.push(`#ifndef ${pragmaOnce}`);
    lines.push(`#define ${pragmaOnce}`);
    lines.push("");
    for (const {name, code, description} of errors) {
      const desc = description ? `/* ${description} */` : "";
      lines.push(`#define ${name}${nameSpace.substring(name.length)} ${code} ${codeSpace.substring(code.length)}${desc}`);
    }
    lines.push("");
    for (const {name, alias} of aliases) {
      const desc = alias.description ? `/* ${alias.description} */` : "";
      lines.push(`#define ${name}${nameSpace.substring(name.length)} ${alias}${desc}`);
    }
    lines.push("");
    lines.push(`#endif /* ${pragmaOnce} */`);
    lines.push("");

    await linesSaveTo(filename, lines);
  }
};

class LibrariesModule {
  _ctx;
  _config = {};

  constructor(ctx)
  {
    this._ctx = ctx;
  }

  async loadIndex(filename)
  {
    const fileUrl = url.pathToFileURL(filename);
    const module = await import(fileUrl);
    this._config = module.default;
  }

  async triggerEvent()
  {
    for (const [key, val] of Object.entries(this._config)) {
      await this._ctx.hooks.emit(`libraries.${key}`, val);
    }
  }

  async saveSubdirEntry(filename)
  {
    const lines = [];

    for (const [name, entry] of Object.entries(this._config)) {
      const space = entry.depends ? "  " : "";
      if (entry.depends) {
        lines.push(`if (${entry.depends})`);
      }
      lines.push(`${space}set(${name}_OBJLIB_LIST "")`);
      if (entry.objlibs) {
        for (const [key, lib] of Object.entries(entry.objlibs)) {
          if (!lib) continue;
          if (key === lib.cmakeDir)
            lines.push(`${space}add_subdirectory(${key})`);
          else
            lines.push(`${space}add_subdirectory("${lib.cmakeDir}" ${key})`);
          lines.push(`${space}list(APPEND ${name}_OBJLIB_LIST ${key})`);
        }
      }
      lines.push(`${space}add_subdirectory(${name})`);
      if (entry.depends) {
        lines.push(`endif ()`);
      }
      lines.push("");
    }
  
    await linesSaveTo(filename, lines);
  }
};

class VariablesModule {
  _ctx;
  _initConfig = {};

  constructor(ctx)
  {
    this._ctx = ctx;
  }

  async loadConfig(filename)
  {
    const fileUrl = url.pathToFileURL(filename);
    const module = await import(fileUrl);
    this._initConfig = module.default;
  }

  async triggerEvent()
  {
    await this._ctx.hooks.emit("variables.init", this._initConfig);
  }

  async saveInitConfigAsCMake(filename, print)
  {
    let maxLength = 0;
    for (const name of Object.keys(this._initConfig))
      maxLength = Math.max(maxLength, name.length);
    const leader = " .".repeat((maxLength + 4) / 2);
  
    const lines = [];
  
    lines.push(CMake.generatedScriptNameComment(this._ctx.entryScript));
    for (const [name, entry] of Object.entries(this._initConfig)) {
      const space = entry.depends ? "  " : "";
      if (entry.depends) {
        lines.push(`if (${entry.depends})`);
      }
      const description = entry.description || "";
      if (typeof entry.value === "boolean") {
        lines.push(`${space}option(${name} "${description}" ${entry.value ? "ON" : "OFF"})`);
      }
      else if (typeof entry.value === "number") {
        lines.push(`${space}set(${name} ${entry.value} CACHE STRING "${description}")`);
      }
      else if (typeof entry.value === "string") {
        lines.push(`${space}set(${name} "${entry.value}" CACHE STRING "${description}")`);
        if (Array.isArray(entry.type)) {
          const strings = entry.type.map((i) => '"' + i + '"').join(' ');
          lines.push(`${space}set_property(CACHE ${name} PROPERTY STRINGS ${strings})`);
        }
      }
      else if (Array.isArray(entry.value)) {
        lines.push(`${space}set(${name} "${entry.value}" CACHE STRING "${description}")`);
      }
      else {
        throw `Not supported value of ${entry.value}`;
      }
      if (print) {
        lines.push(`${space}message(STATUS "${name}:${leader.substring(name.length)} \${${name}}")`);
      }
      if (entry.depends) {
        lines.push("endif ()");
      }
      lines.push("");
    }
  
    await linesSaveTo(filename, lines);
  }
  
  async saveInitConfigAsCHeader(filename)
  {
    const lines = [];
  
    lines.push(CXX.generatedScriptNameComment(this._ctx.entryScript));
    lines.push("");
  
    for (const [name, entry] of Object.entries(this._initConfig)) {
      if (entry.description) {
        lines.push(`/* ${entry.description} */`);
      }
      if (typeof entry.value === "boolean") {
        lines.push(`#cmakedefine01 ${name}`);
      }
      else if (typeof entry.value === "number") {
        lines.push(`#define ${name} @${name}@`);
      }
      else if (typeof entry.value === "string") {
        lines.push(`#define ${name} "@${name}@"`);
      }
      else if (Array.isArray(entry.value)) {
        lines.push(`#define ${name} "@${name}@"`);
      }
      else {
        throw `Not supported value of ${entry.value}`;
      }
      lines.push("");
    }
  
    await linesSaveTo(filename, lines);
  }
  
  async saveInitConfigAsModule(filename)
  {
    const lines = [];

    lines.push(CXX.generatedScriptNameComment(this._ctx.entryScript));
    lines.push("export default {");

    for (const [name, entry] of Object.entries(this._initConfig)) {
      let type = entry.type;
      let value = `@${name}@`;

      if (type === undefined) {
        if (typeof entry.value === "boolean") {
          type = "boolean";
        }
        else if (typeof entry.value === "number") {
          type = "number";
        }
        else if (typeof entry.value === "string") {
          type = "string";
        }
        else if (Array.isArray(entry.value)) {
          type = "strings";
        }
        else {
          throw `Not supported value of ${entry.value}`;
        }
      }

      if (type !== "number") {
        value = '"' + value + '"';
      }

      lines.push(`  ${name}: {`);
      lines.push(`    type: ${JSON.stringify(type)},`);
      lines.push(`    value: ${value},`);
      lines.push(`  },`);
    }

    lines.push("};");
    lines.push("");

    await linesSaveTo(filename, lines);
  }
};

export class InjectContext {
  _entryScript;
  _config = {};
  _plugins = [];
  _errno;
  _libraries;
  _variables;

  _hooks = new InjectHooks;

  _path = {
    join: path.posix.join,
    dirname: path.posix.dirname,
  };

  constructor(entryScript)
  {
    this._entryScript = entryScript;
    this._errno = new ErrnoModule(this);
    this._libraries = new LibrariesModule(this);
    this._variables = new VariablesModule(this);
  }

  get hooks()
  {
    return this._hooks;
  }

  get errno()
  {
    return this._errno;
  }

  get libraries()
  {
    return this._libraries;
  }

  get variables()
  {
    return this._variables;
  }

  get path()
  {
    return this._path;
  }

  get entryScript()
  {
    return this._entryScript;
  }

  async loadConfig(filename)
  {
    const fileUrl = url.pathToFileURL(filename);
    const module = await import(fileUrl);
    this._config = transformCMakeConfigToObject(module.default);
  }

  async loadPlugin(filename)
  {
    const fileUrl = url.pathToFileURL(filename);
    const module = await import(fileUrl);
    const Plugin = module.default;
    this._plugins.push(new Plugin);
  }

  async loadPlugins()
  {
    for (const filename of (this._config.WASMUX_INJECT_SCRIPT_LIST || [])) {
      await this.loadPlugin(filename);
    }
  }

  async initPlugins()
  {
    for (const plugin of this._plugins) {
      const res = plugin.entry(this);
      if (res instanceof Promise)
        await res;
    }
  }
};
