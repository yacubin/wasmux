const path = require('node:path');
const fs = require('node:fs');

const settings = require("./scripts/settings.js");
const { fileExists } = require("./scripts/utils/FileSystem.js");

const BuildScriptPlugin = require("./scripts/plugins/BuildScriptPlugin.js");

function toCIdentifier(key) {
  let result = "";

  let pos = 0;
  while (pos < key.length) {
    let end = key.indexOf("-", pos);
    if (end === -1) {
      end = key.length;
    }
    result += result ? key.charAt(pos).toUpperCase() + key.substring(pos + 1, end) : key.substring(pos, end);
    pos = end + 1;
  }

  return result;
}

function toArgMap(args)
{
  const params = {};
  args.forEach(iter => {
    if (iter.startsWith("--")) {
      const pos = iter.indexOf("=");
      const key = (pos === -1) ? iter.substring(2) : iter.substring(2, pos);
      const val = (pos === -1) ? null : iter.substring(pos + 1);
      params[toCIdentifier(key)] = val;
    }
  });
  return params;
}

function currentArgMap()
{
  return toArgMap(process.argv.slice(2));
}

async function saveIfDifferent(filename, content)
{
  if (await fileExists(filename)) {
    const oldContent = await fs.promises.readFile(filename, { encoding: "utf8" });
    if (content == oldContent)
      return;
  }

  await fs.promises.mkdir(path.dirname(filename), { recursive: true });
  await fs.promises.writeFile(filename, content, { encoding: "utf8" });
}

class MainContext {
  _variables = {};
  _package = {};

  constructor(sourceDir)
  {
    this._variables.sourceDir = sourceDir;
    this._variables.install = {
      binDir: "bin",
      libDir: "lib",
      includeDir: "include",
    };
  }

  async _init() {
    await this._loadPackage();
  }

  async _loadPackage() {
    const filepath = path.resolve(this._variables.sourceDir, "package.json");
    const content = await fs.promises.readFile(filepath, "utf-8");
    this._package = JSON.parse(content);
  }

  get package() { return this._package; }
  set package(value) { this._package = value; }

  get variables() { return this._variables; }

  _settings = {};
  get settings() { return this._settings; }
  set settings(value) { this._settings = value; }

  _plugins = [];
  get plugins() { return this._plugins; }

  _assets = {};
  get assets() { return this._assets; }

  _processAssetsCallbacks = [];
  async emitProcessAssets()
  {
    for (const callback of this._processAssetsCallbacks)
    {
      const res = callback();
      if (res instanceof Promise)
        await res;
    }
  }

  addProcessAssets(callback)
  {
    this._processAssetsCallbacks.push(callback);
  }

  _targets = [];
  get targets() { return this._targets; }
};

async function runScript({output})
{
  const ctx = new MainContext(__dirname);
  await ctx._init();

  ctx.settings = settings;
  ctx.plugins.push(new BuildScriptPlugin({ filename: output }));
  ctx.targets.push(path.resolve(__dirname, "waf/base/MakeScript.mjs"));

  for (const plugin of ctx.plugins)
  {
    const res = plugin.apply(ctx);
    if (res instanceof Promise)
      await res;
  }

  await ctx.emitProcessAssets();

  for (const [filename, content] of Object.entries(ctx.assets))
  {
    await saveIfDifferent(filename, content);
  }
}

runScript(currentArgMap()).then(() => process.exit(0)).catch((e) => {
  console.error(e);
  process.exit(1);
});
