import path from 'node:path';
import url from 'node:url';

import { saveIfDifferent } from "###/utils/FileSystem.js";
import { generatedScriptNameComment } from "###/utils/CXXHelper.js";

async function linesSaveTo(filename, lines)
{
  await saveIfDifferent(filename, lines.join('\n'));
}

class InjectHook {
  _callbacks = {};

  constructor()
  {
  }

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
}

export class InjectContext {
  _entryScript;
  _initConfig = {};
  _config = {};
  _libraries = {};
  _plugins = [];

  _hooks = {
    variables: new InjectHook,
    libraries: new InjectHook,
  };

  _path = {
    join: path.posix.join,
    dirname: path.posix.dirname,
  };

  constructor(entryScript)
  {
    this._entryScript = entryScript;
  }

  get hooks()
  {
    return this._hooks;
  }

  get path()
  {
    return this._path;
  }

  async loadInitConfig(filename)
  {
    const fileUrl = url.pathToFileURL(filename);
    const module = await import(fileUrl);
    this._initConfig = module.default;
  }

  async loadConfig(filename)
  {
    const fileUrl = url.pathToFileURL(filename);
    const module = await import(fileUrl);
    this._config = module.default;
  }

  async loadIndex(filename)
  {
    const fileUrl = url.pathToFileURL(filename);
    const module = await import(fileUrl);
    this._libraries = module.default;
  }

  async loadPlugin(filename)
  {
    const fileUrl = url.pathToFileURL(filename);
    const module = await import(fileUrl);
    const Plugin = module.default;
    this._plugins.push(new Plugin);
  }

  async initPlugins()
  {
    for (const plugin of this._plugins) {
      const res = plugin.entry(this);
      if (res instanceof Promise)
        await res;
    }
  }

  async triggerInitConfig()
  {
    await this._hooks.variables.emit("init", this._initConfig);
  }

  async triggerLibraries()
  {
    for (const [key, val] of Object.entries(this._libraries)) {
      await this._hooks.libraries.emit(key, val);
    }
  }

  async saveSubdirEntry(filename)
  {
    const lines = [];

    for (const [name, entry] of Object.entries(this._libraries)) {
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

  async saveInitConfigAsCMake(filename, print)
  {
    let maxLength = 0;
    for (const name of Object.keys(this._initConfig))
      maxLength = Math.max(maxLength, name.length);
    const leader = " .".repeat((maxLength + 4) / 2);
  
    const lines = [];
  
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
  
    lines.push(generatedScriptNameComment(this._entryScript));
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
  
    lines.push("export default {");
  
    for (const [name, entry] of Object.entries(this._initConfig)) {
      let val;
      if (typeof entry.value === "boolean") {
        val = `"@${name}@" === "ON"`;
      }
      else if (typeof entry.value === "number") {
        val = `@${name}@`;
      }
      else if (typeof entry.value === "string") {
        val = `"@${name}@"`;
      }
      else {
        throw `Not supported value of ${entry.value}`;
      }
      lines.push(`  ${name}: ${val},`);
    }
  
    lines.push("};");
    lines.push("");
  
    await linesSaveTo(filename, lines);
  }
};
