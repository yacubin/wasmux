const path = require('path');
const fs = require('fs');

const { fileExists, directoryExists }  = require('./utils/FileSystem.js');
const { spawnAsync } = require('./utils/ChildProcess.js');
const cmake  = require('./utils/CMake.js');
const { requestGet } = require('./utils/HttpRequest.js');

function toArray(o)
{
  if (o === undefined)
    return [];
  return Array.isArray(o) ? o : [o];
}

class SettingsStorage {
  _filename;
  _encoding = "utf-8";
  _settings;
  _current;

  constructor(filename)
  {
    this._filename = filename;
  }

  async push(name)
  {
    if (!this._settings)
      await this.load();
    let object = this._current.object[name];
    if (!object)
      object = this._current.object[name] = {};
    this._current = { parent: this._current, object };
  }

  async pop()
  {
    if (!this._settings)
      await this.load();
    console.assert(this._current.parent);
    this._current = this._current.parent;
  }

  async get(name)
  {
    if (!this._settings)
      await this.load();
    return this._current.object[name];
  }

  async set(name, value)
  {
    if (!this._settings)
      await this.load();
    this._current.object[name] = value;
    await this.save();
  }

  async load()
  {
    try {
      const stat = await fs.promises.stat(this._filename);
      const content = await fs.promises.readFile(this._filename, this._encoding);
      this._settings = JSON.parse(content);
    }
    catch (e) {
      this._settings = {};
    }
    this._current =
    {
      parent: null,
      object: this._settings,
    };
  }

  async save()
  {
    const space = 2;
    const content = JSON.stringify(this._settings, undefined, space);
    await fs.promises.writeFile(this._filename, content, { encoding: this._encoding, flag: 'w', flush: true });
  }
};

function mergeEnvironment(...args)
{
  const environment = {};
  for (const env of args) {
    const list = Object.entries(env || {});
    while (list.length) {
      let [key,val] = list.pop();
      let delimiter;
      let joinAfter = true;
      switch (key) {
      case "PATH":
        delimiter = path.delimiter;
        joinAfter = false;
        break;
      case "CFLAGS":
      case "CXXFLAGS":
      case "LDFLAGS":
        delimiter = " ";
        break;
      }
      if (typeof val === 'number')
        val = val.toString();
      else if (Array.isArray(val))
        val = val.join(delimiter);
      if (!delimiter || !environment[key])
        environment[key] = val;
      else if (joinAfter)
        environment[key] = val + delimiter + environment[key];
      else
        environment[key] = environment[key] + delimiter + val;
    }
  }
  return environment;
}

const actionHandlers = {
  none: async (config, settings) => {
    /* do nothing */
  },
  cmake: async (config, settings) => {
    const cmakeArgs = {
      environment: {
        ...config.environment,
        DESTDIR: config.destDir,
      },
      generator: config.generator || "Unix Makefiles",
      cacheVariables: config.cacheVariables,
      sourceDir: config.sourceDir,
      binaryDir: config.binaryDir,
    };

    await cmake.configure(cmakeArgs);
    await cmake.build(cmakeArgs);
    await cmake.install(cmakeArgs);
  },
  configure: async (config, settings) => {
    let step = await settings.get("configure") || "config";
    if (step === "config") {
      const command = path.resolve(config.sourceDir, "configure");
      const params = [];
      if (Array.isArray(config.variables)) {
        for (const iter of config.variables)
          params.push(iter);
      }
      else if (config.variables) {
        for (const [key,val] of Object.entries(config.variables)) {
          if (key === "features" && Array.isArray(val)) {
            for (const iter of val)
              params.push(`--${iter}`);
          }
          else if (val === null)
            params.push(`--${key}`);
          else
            params.push(`--${key}=${val}`);
        }
      }
      const res1 = await spawnAsync(command, params, {
        cwd: config.binaryDir,
        env: config.environment,
        extra: {
          output: `ac.config.log`,
        },
      });
      if (res1.status !== 0) {
        throw `configure returned status ${res1.status}`;
      }
      step = "install";
      await settings.set("configure", step);
    }
    if (step === "install") {
      const args = [ 'install' ];
      if (config.destDir) {
        args.push(`DESTDIR=${config.destDir}`);
      }
      const res2 = await spawnAsync("make", args, {
        cwd: config.binaryDir,
        env: config.environment,
        extra: {
          output: `ac.build.log`,
        },
      });
      if (res2.status !== 0) {
        throw `make returned status ${res2.status}`;
      }
      step = "done";
      await settings.set("configure", step);
    }
  },
  make: async (config, settings) => {
    const args = config.args || [];
    if (config.destDir) {
      args.push(`DESTDIR=${config.destDir}`);
    }
    const res2 = await spawnAsync("make", args, {
      cwd: config.binaryDir,
      env: config.environment,
      extra: {
        output: `make.log`,
      },
    });
    if (res2.status !== 0) {
      throw `make returned status ${res2.status}`;
    }
  },
  process: async (config, settings) => {
    if (!config.command)
      throw "Required command field for process action";
    let { command } = config;
    if (!path.isAbsolute(command) && (command.includes(path.posix.delimiter) || command.includes(path.win32.delimiter))) {
      command = path.resolve(config.sourceDir, command);
    }
    const res = await spawnAsync(command, config.args || [], {
      cwd: config.binaryDir,
      env: config.environment,
      extra: {
        output: `process.log`,
      },
    });
    if (res.status !== 0) {
      throw `process returned status ${res.status}`;
    }
  },
};

function prepearAction(config)
{
  if (config.action === 'cmake') {
    config.cacheVariables = config.cacheVariables || {};
    config.cacheVariables.CMAKE_BUILD_TYPE = config.cacheVariables.CMAKE_BUILD_TYPE || config.buildType;
    config.cacheVariables.CMAKE_INSTALL_PREFIX = config.cacheVariables.CMAKE_INSTALL_PREFIX || "/";
    if (config.sysroot && !config.cacheVariables.CMAKE_TOOLCHAIN_FILE) {
      const installDir = config.sysroot.destDir + config.cacheVariables.CMAKE_INSTALL_PREFIX;
      config.cacheVariables.CMAKE_TOOLCHAIN_FILE = path.resolve(installDir, `share/wasmux/${config.sysroot.arch}.toolchain.cmake`);
    }
  }
}

async function doTargetBuild(ctx, config, settings)
{
  if (!await directoryExists(config.binaryDir)) {
    await fs.promises.mkdir(config.binaryDir, { recursive: true });
  }
  if (actionHandlers[config.action]) {
    await actionHandlers[config.action](config, settings);
  }
}

async function tryRequestGet(sourceUrl, arcFile, attempts)
{
  for(;;) {
    try {
      const buffer = await requestGet(sourceUrl);
      await fs.promises.writeFile(arcFile, buffer);
      return;
    }
    catch (e) {
      if (--attempts < 0) {
        throw e;
      }
      console.warn(e);
    }
  }
}

async function doExtractArchive(ctx, config, settings)
{
  if (!config.sourceUrl)
    throw "Unknown sourceUrl";
  if (!config.arcDir)
    throw "Unknown arcDir";
  if (!config.extractDir)
    throw "Unknown extractDir";

  if (!await directoryExists(config.arcDir))
    await fs.promises.mkdir(config.arcDir, { recursive: true });

  if (!await directoryExists(config.tempDir))
    await fs.promises.mkdir(config.tempDir, { recursive: true });

  const arcName = `${config.name}${path.extname(config.sourceUrl)}`;

  let arcFile;
  let downloadUrls = await settings.get("downloadUrls") || {};
  if (downloadUrls[config.sourceUrl])
    arcFile = downloadUrls[config.sourceUrl];
  else {
    arcFile = path.join(config.arcDir, arcName);
    await tryRequestGet(config.sourceUrl, arcFile, ctx.requestAttempts);
    downloadUrls[config.sourceUrl] = arcFile;
    await settings.set("downloadUrls", downloadUrls);
  }

  let extractDir;
  let extractFiles = await settings.get("extractFiles") || {};
  if (extractFiles[arcFile]) {
    extractDir = extractFiles[arcFile];
  }
  else {
    extractDir = await fs.promises.mkdtemp(path.resolve(config.tempDir, arcName + '.'));
  
    await cmake.extract({
      environment: config.environment,
      filename: arcFile,
      workDir: extractDir,
      logFile:  path.join(config.tempDir, path.basename(extractDir) + ".log"),
    });
  
    const extractList = fs.readdirSync(extractDir);
    if (extractList.length === 1) {
      extractDir = path.resolve(extractDir, extractList[0]);
      if (!fs.statSync(extractDir).isDirectory()) {
        await fs.promises.rm(extractDir, { recursive: true });
        throw `Support only directory for archive`;
      }
    }
  
    if (await directoryExists(config.extractDir)) {
      // TODO: Marge extractDir with output
      console.log(`rm -fr ${config.extractDir}`);
      await fs.promises.rm(config.extractDir, { recursive: true });
    }
    else {
      const parentDir = path.dirname(config.extractDir);
      if (!await directoryExists(parentDir)) {
        console.log(`mkdir -p ${parentDir}`);
        await fs.promises.mkdir(parentDir, { recursive: true }); 
      }
    }
  
    console.log(`mv ${extractDir} ${config.extractDir}`);
    await fs.promises.rename(extractDir, config.extractDir);
  
    extractFiles[arcFile] = extractDir;
    await settings.set("extractFiles", extractFiles);
  }
}

function copyObject(o)
{
  if (!o || typeof o !== 'object')
    return o;

  if (Array.isArray(o)) {
    const result = [];
    for (const iter of o)
      result.push(copyObject(iter));
    return result;
  }
  else {
    const result = {};
    for (const [key,val] of Object.entries(o))
      result[key] = copyObject(val);
    return result;
  }
}

async function doConfigNode(ctx, name, binaryDir, config, parentConfig)
{
  if (!name)
    throw "Not supported empty name";

  config.name = name;
  config.environment = mergeEnvironment(config.environment, parentConfig.environment);
  config.buildType = config.buildType || parentConfig.buildType;
  config.destDir = config.destDir || parentConfig.destDir;
  config.arcDir = config.arcDir || parentConfig.arcDir;
  config.tempDir = config.tempDir || parentConfig.tempDir;
  config.wasmuxDir = config.wasmuxDir || parentConfig.wasmuxDir;
  config.workDir = config.workDir || parentConfig.workDir;

  if (config.sysroot) {
    config.sysroot.arch = config.sysroot.arch || (parentConfig.sysroot ? parentConfig.sysroot.arch : "wasm32");
    config.sysroot.environment = mergeEnvironment(config.sysroot.environment, config.environment);
    config.sysroot.buildType = config.sysroot.buildType || config.buildType;
    config.sysroot.sourceDir = config.sysroot.sourceDir || config.wasmuxDir;

    let binaryDirName = "sysroot-build";
    const packagePath = path.resolve(config.sysroot.sourceDir, "package.json");
    if (await fileExists(packagePath)) {
      const packageContent = await fs.promises.readFile(packagePath, 'utf-8');
      const packageJson = JSON.parse(packageContent);
      binaryDirName = packageJson.name || binaryDirName;
      if (packageJson.version)
        binaryDirName = `${binaryDirName}-${packageJson.version}`;
    }

    config.sysroot.binaryDir = config.sysroot.binaryDir || path.resolve(binaryDir, binaryDirName);
    config.sysroot.arcDir = config.sysroot.arcDir || config.arcDir || path.resolve(binaryDir, "sysroot-arc");
    config.sysroot.tempDir = config.sysroot.tempDir || config.tempDir || path.resolve(binaryDir, "sysroot-tmp");
    config.sysroot.destDir = config.sysroot.destDir || config.destDir || path.resolve(binaryDir, "sysroot-dest");
    config.sysroot.action = 'cmake';
    config.sysroot.cacheVariables = config.sysroot.cacheVariables || {};
    config.sysroot.cacheVariables.CMAKE_BUILD_TYPE = config.sysroot.cacheVariables.CMAKE_BUILD_TYPE || config.sysroot.buildType;
    config.sysroot.cacheVariables.CMAKE_INSTALL_PREFIX = config.sysroot.cacheVariables.CMAKE_INSTALL_PREFIX || "/";
    config.sysroot.cacheVariables.CONFIG_TARGET_SYSTEM = config.sysroot.cacheVariables.CONFIG_TARGET_SYSTEM || config.sysroot.arch;
    if (!config.sysroot.cacheVariables.CMAKE_TOOLCHAIN_FILE) {
      const toolchainFile = config.sysroot.arch.includes("wasm64") ? 'cmake/wasm64-toolchain.cmake' : 'cmake/wasm32-toolchain.cmake';
      config.sysroot.cacheVariables.CMAKE_TOOLCHAIN_FILE = path.resolve(config.sysroot.sourceDir, toolchainFile);
    }
  }
  else if (parentConfig.sysroot) {
    config.sysroot = copyObject(parentConfig.sysroot);
    config.sysroot.action = 'none';
  }

  const output = config.output || config;
  output.name = output.name || name;
  output.environment = mergeEnvironment(output.environment, config.environment);
  output.buildType = output.buildType || config.buildType;
  let workDir = config.workDir;
  if (output.sourceUrl) {
    output.extractDir = output.extractDir || path.resolve(binaryDir, `output-src`);
    workDir = output.extractDir;
  }
  if (!output.sourceDir) {
    output.sourceDir = workDir;
  }
  else if (!path.isAbsolute(output.sourceDir)) {
    output.sourceDir = path.resolve(workDir, output.sourceDir);
  }
  if (output.binaryDir === null) {
    output.binaryDir = output.sourceDir;
  }
  else {
    output.binaryDir = output.binaryDir || path.resolve(binaryDir, `output-build`);
  }
  output.arcDir = output.arcDir || config.arcDir || path.resolve(binaryDir, `output-arc`);
  output.tempDir = output.tempDir || config.tempDir || path.resolve(binaryDir, `output-tmp`);
  output.destDir = output.destDir || config.destDir;
  output.sysroot = output.sysroot || config.sysroot;

  if (Array.isArray(output.action)) {
    for (const iter of output.action) {
      iter.sysroot = iter.iter || output.sysroot;
      iter.environment = mergeEnvironment(iter.environment, output.environment);
      iter.buildType = iter.buildType || output.buildType;
      iter.sourceDir = iter.sourceDir || output.sourceDir;
      iter.binaryDir =(iter.binaryDir === null) ? iter.sourceDir : (iter.binaryDir || output.binaryDir);
      iter.destDir = iter.destDir || output.destDir;
      iter.arcDir = iter.arcDir || output.arcDir;
      iter.tempDir = iter.tempDir || output.tempDir;
      prepearAction(iter);
    }
  }
  else {
    prepearAction(output);
  }

  config.binaryDir = config.binaryDir || binaryDir;

  if (config.required) {
    for (const [name, conf] of Object.entries(config.required)) {
      await doConfigNode(ctx, name, path.resolve(binaryDir, name), conf, config);
    }
  }
}

async function doActionNode(ctx, config, settings)
{
  if (config.sysroot) {
    await settings.push("sysroot");
    await doTargetBuild(ctx, config.sysroot, settings);
    await settings.pop();
  }

  if (config.required) {
    await settings.push("required");
    for (const [name, conf] of Object.entries(config.required)) {
      await settings.push(name);
      await doActionNode(ctx, conf, settings);
      await settings.pop();
    }
    await settings.pop();
  }

  const output = config.output || config;
  if (output.sourceUrl) {
    await doExtractArchive(ctx, output, settings);
  }
  if (Array.isArray(output.action)) {
    await settings.push("action");
    for (var i = 0; i < output.action.length; ++i) {
      await settings.push(i.toString());
      await doTargetBuild(ctx, output.action[i], settings);
      await settings.pop();
    }
    await settings.pop();
  }
  else {
    await doTargetBuild(ctx, output, settings);
  }
}

module.exports = async function(ctx)
{
  const rootConfig = {
    environment: process.env,
    buildType: ctx.buildType,
    sourceDir: ctx.workDir,
    binaryDir: ctx.workDir,
    wasmuxDir: ctx.rootDir,
    workDir: ctx.workDir,
  };

  const userConfig = await ctx.getUserConfig();
  const childConfig = copyObject(userConfig);
  const binaryDir = path.resolve(ctx.workDir, "build");
  const settingsFilename = path.resolve(binaryDir, "BuildSettings.json");
  const settings = new SettingsStorage(settingsFilename);
  await doConfigNode(ctx, "workspace", binaryDir, childConfig, rootConfig);

  if (!await directoryExists(binaryDir)) {
    console.log(`mkdir -p "${binaryDir}"`);
    await fs.promises.mkdir(binaryDir, { recursive: true });
  }

  console.log(`echo $jsonConfig > "build.json"`);
  const jsonConfig = JSON.stringify(childConfig, null, 2);
  await fs.promises.writeFile(path.resolve(binaryDir, "build.json"), jsonConfig);

  await doActionNode(ctx, childConfig, settings);
}
