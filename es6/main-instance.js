/*
 * MIT License
 *
 * Copyright (c) 2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 * Permission is granted to use, copy, modify, and distribute this software
 * under the MIT License. See LICENSE file for details.
 */

"use strict";

const BaseThreadContext = require("./browser-instance");

const {
  WEB_UserInstanceStart,
  WEB_PostMessage2,
  WEB_PostMessage3,
  WEB_PostMessage4,
  WEB_PostMessage5,
  WEB_PostMessage6,
} = require("./webcalls-num");

const { sys_NotImplemented } = require("./webcall-funcs");

function MainContext({kernelModule, kernelMemory, scriptUrl }) {
  BaseThreadContext.call(this, kernelModule, kernelMemory, globalThis, scriptUrl);

  this._objects[WEB_UserInstanceStart] = sys_NotImplemented;
  this._objects[WEB_PostMessage2] = sys_NotImplemented;
  this._objects[WEB_PostMessage3] = sys_NotImplemented;
  this._objects[WEB_PostMessage4] = sys_NotImplemented;
  this._objects[WEB_PostMessage5] = sys_NotImplemented;
  this._objects[WEB_PostMessage6] = sys_NotImplemented;
}

MainContext.prototype = Object.create(BaseThreadContext.prototype);
MainContext.prototype.constructor = MainContext;

MainContext.prototype.init = async function() {
  // WebAssembly.Instance is disallowed on the main thread, if the buffer size is larger than 8MB
  const kinst = await WebAssembly.instantiate(this._kernelModule, this.makeImports());
  this._kernel = kinst.exports;
  this._kernel._start_kernel();
}

MainContext.create = (kernelModule, workerUrl, manifest) => {
  const kernelMemory = new WebAssembly.Memory({
    initial: manifest.initPages,
    maximum: manifest.maxPages,
    shared: true,
  });

  return new MainContext({kernelModule, kernelMemory, scriptUrl: workerUrl});
}

function UserInstance(context, loaderUrl, workerUrl) {
  this._context = context;
  this._loaderUrl = loaderUrl;
  this._workerUrl = workerUrl;
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
  setTimeout(() => this._context.init(), 0);
}

UserInstance.prototype.stop = function() {
  URL.revokeObjectURL(this._loaderUrl);
  URL.revokeObjectURL(this._workerUrl);
}

module.exports.createUserInstance = async function(bytes) {
  const module = await WebAssembly.compile(bytes);

  const manifestList = WebAssembly.Module.customSections(module, ".jsdata.manifest");

  const loaderList = WebAssembly.Module.customSections(module, ".jsdata.loader");
  const loaderBlob = new Blob(loaderList, { type: "application/javascript" });
  const loaderUrl = URL.createObjectURL(loaderBlob);

  const workerList = WebAssembly.Module.customSections(module, ".jsdata.worker");
  const workerBlob = new Blob(workerList, { type: 'application/javascript' });
  const workerUrl = URL.createObjectURL(workerBlob);

  let mainContext;
  if (manifestList.length) {
    const decoder = new TextDecoder();
    const manifestStr = decoder.decode(manifestList[0]);
    mainContext = MainContext.create(module, workerUrl, JSON.parse(manifestStr));
  }
  else {
    const { MainContext } = await import(/* webpackIgnore: true */ loaderUrl);
    mainContext = MainContext.create(module, workerUrl);
  }

  return new UserInstance(mainContext, loaderUrl, workerUrl);
}
