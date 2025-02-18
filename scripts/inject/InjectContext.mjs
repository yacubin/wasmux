import path from 'node:path';
import url from 'node:url';

import { saveIfDifferent } from "###/utils/FileSystem.js";

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

export class InjectContext {
  _args;
  _entryScript;
  _config = {};
  _plugins = [];

  _hooks = new InjectHooks;

  _path = {
    join: path.posix.join,
    dirname: path.posix.dirname,
  };

  _fs = {
    linesSaveTo,
  };

  constructor(entryScript, args)
  {
    this._entryScript = entryScript;
    this._args = args;
  }

  get args()
  {
    return this._args;
  }

  get hooks()
  {
    return this._hooks;
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

  get fs()
  {
    return this._fs;
  }

  get entryScript()
  {
    return this._entryScript;
  }

  async loadConfig(filename)
  {
    const fileUrl = url.pathToFileURL(filename);
    const module = await import(fileUrl);
    const originConfig = module.default;

    const config = {};
    for (const [key, entry] of Object.entries(originConfig)) {
      if (entry.type === "boolean") {
        config[key] = entry.value.toUpperCase() === "ON" || entry.value.toUpperCase() === "TRUE";
      }
      else if (entry.type === "number") {
        config[key] = entry.value;
      }
      else if (entry.type === "string") {
        config[key] = entry.value;
      }
      else if (entry.type === "strings") {
        config[key] = entry.value ? entry.value.split(";") : [];
      }
      else if (Array.isArray(entry.type)) {
        config[key] = entry.value;
      }
      else {
        throw `Not supported type ${entry.type}`;
      }
    }

    this._config = config;
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
