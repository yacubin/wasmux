/*
 * MIT License
 *
 * Copyright (c) 2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 * Permission is granted to use, copy, modify, and distribute this software
 * under the MIT License. See LICENSE file for details.
 */

"use strict";

const WasmuxRuntime = require("./worker");

function UserInstance(context, objectUrls) {
  this._context = context;
  this._objectUrls = objectUrls;
}

Object.defineProperty(UserInstance.prototype, "baseFsUrl", {
  set(value) {
  },
  enumerable: true
});

Object.defineProperty(UserInstance.prototype, "onmessage", {
  set(value) {
  },
  enumerable: true
});

UserInstance.prototype.registerDriver = function(name, driverClass) {
}

UserInstance.prototype.start = function() {
  setTimeout(async () => {
    await this._context.init();
    this._context._kernel._start_kernel();
  });
}

UserInstance.prototype.stop = function() {
  for (const iter of this._objectUrls)
    URL.revokeObjectURL(iter);
}

async function fetchBuffer(context, path) {
  if (path.startsWith("http://") || path.startsWith("https://") || !context.fetchBuffer) {
    const response = await fetch(path);
    return await response.arrayBuffer();
  }
  return await context.fetchBuffer(path);
}

function createModuleSectionURL(module, section, type) {
  const sectionList = WebAssembly.Module.customSections(module, section);
  const sectionBlob = new Blob(sectionList, { type });
  const sectionUrl = URL.createObjectURL(sectionBlob);
  return sectionUrl;
}

module.exports.createUserInstance = async function(options, context) {
  let moduleUrl, workerUrl;
  const objectUrls = [];

  if (typeof options === "string")
    moduleUrl = options;
  else {
    moduleUrl = options.moduleUrl;
    workerUrl = options.workerUrl;
  }

  const bytes = await fetchBuffer(context, moduleUrl);
  const module = await WebAssembly.compile(bytes);

  if (!workerUrl) {
    workerUrl = createModuleSectionURL(module, ".jsdata.worker", "application/javascript");
    objectUrls.push(workerUrl);
  }

  let mainContext;

  const manifestList = WebAssembly.Module.customSections(module, ".jsdata.manifest");
  if (manifestList.length) {
    const decoder = new TextDecoder();
    const manifestStr = decoder.decode(manifestList[0]);
    const manifest = JSON.parse(manifestStr);
    const memory = new WebAssembly.Memory({
      initial: manifest.initPages,
      maximum: manifest.maxPages,
      shared: true,
    });
    mainContext = new WasmuxRuntime(module, memory, false, workerUrl, context.WorkerCtor);
  }
  else {
    const loaderUrl = createModuleSectionURL(module, ".jsdata.loader", "application/javascript");
    objectUrls.push(loaderUrl);
    const { MainContext } = await import(/* webpackIgnore: true */ loaderUrl);
    mainContext = MainContext.create(module, workerUrl);
  }

  return new UserInstance(mainContext, objectUrls);
}
