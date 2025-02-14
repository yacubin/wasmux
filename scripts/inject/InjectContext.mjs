import path from 'node:path';
import url from 'node:url';

import { saveIfDifferent } from "###/utils/FileSystem.js";

async function linesSaveTo(filename, lines)
{
  await saveIfDifferent(filename, lines.join('\n'));
}

class InjectHooks {
  _settingsCallbacks = [];
  _librariesCallbacks = [];

  async emitSettingsEvent(settings)
  {
    for (const callback of this._settingsCallbacks) {
      const res = callback(settings);
      if (res instanceof Promise)
        await res;
    }
  }

  addSettingsListener(callback)
  {
    this._settingsCallbacks.push(callback);
  }

  async emitLibrariesEvent(libraries)
  {
    for (const callback of this._librariesCallbacks) {
      const res = callback(libraries);
      if (res instanceof Promise)
        await res;
    }
  }

  addLibrariesListener(callback)
  {
    this._librariesCallbacks.push(callback);
  }
};

export class InjectContext {
  _config = {};
  _libraries = {};
  _plugins = [];
  _hooks = new InjectHooks;
  _path = {
    join: path.posix.join,
    dirname: path.posix.dirname,
  };

  constructor()
  {
  }

  get hooks()
  {
    return this._hooks;
  }

  get path()
  {
    return this._path;
  }

  async loadConfig(filename)
  {
    const configUrl = url.pathToFileURL(filename);
    const module = await import(configUrl);
    this._config = module.default;
  }

  async loadIndex(filename)
  {
    const indexUrl = url.pathToFileURL(filename);
    const module = await import(indexUrl);
    this._libraries = module.default;
  }

  async loadPlugin(filename)
  {
    const pluginUrl = url.pathToFileURL(filename);
    const module = await import(pluginUrl);
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

  async triggerLibraries()
  {
    await this._hooks.emitLibrariesEvent(this._libraries);
  }

  async saveSubdirEntry(filename)
  {
    const lines = [];
  
    lines.push(`message(STATUS "Entry to subdirectory")`);

    for (const [name, entry] of Object.entries(this._libraries)) {
      for (const [key, lib] of Object.entries(entry.objlibs)) {
        if (lib) {
          lines.push(`message(STATUS "  Library ${key}:${lib.cmakeDir}")`);
        }
      }
    }

    lines.push("");
  
    await linesSaveTo(filename, lines);
  }
};
