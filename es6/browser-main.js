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
  WEB_WorkerInstance,
  WEB_WorkerPerform2,
  WEB_WorkerPerform3,
  WEB_WorkerPerform4,
  WEB_WorkerPerform5,
} = require("./webcalls-num");

const {
  sys_NotImplemented,
  sys_WorkerInstance,
  sys_WorkerPerform2,
  sys_WorkerPerform3,
  sys_WorkerPerform4,
  sys_WorkerPerform5,
} = require("./webcall-funcs");

function MainContext({kernelModule, kernelMemory, scriptUrl}) {
  BaseThreadContext.call(this, kernelModule, kernelMemory, window, scriptUrl);

  this._objects[WEB_UserInstanceStart] = sys_NotImplemented;
  this._objects[WEB_PostMessage2] = sys_NotImplemented;
  this._objects[WEB_PostMessage3] = sys_NotImplemented;
  this._objects[WEB_PostMessage4] = sys_NotImplemented;
  this._objects[WEB_PostMessage5] = sys_NotImplemented;
  this._objects[WEB_PostMessage6] = sys_NotImplemented;
  this._objects[WEB_WorkerInstance] = sys_WorkerInstance;
  this._objects[WEB_WorkerPerform2] = sys_WorkerPerform2;
  this._objects[WEB_WorkerPerform3] = sys_WorkerPerform3;
  this._objects[WEB_WorkerPerform4] = sys_WorkerPerform4;
  this._objects[WEB_WorkerPerform5] = sys_WorkerPerform5;
}

MainContext.prototype = Object.create(BaseThreadContext.prototype);
MainContext.prototype.constructor = MainContext;

MainContext.prototype.init = async function() {
  // WebAssembly.Instance is disallowed on the main thread, if the buffer size is larger than 8MB
  const kinst = await WebAssembly.instantiate(this._kernelModule, this.makeImports());
  this._kernel = kinst.exports;
  this._kernel._start_kernel();
}

MainContext.create = (kernelModule, workerUrl) => {
  if (!crossOriginIsolated) {
    throw 'Only crossOriginIsolated'
  }

  const kernelMemory = new WebAssembly.Memory({
    initial: 0, // process.env.WASMUX_CORE_INIT_PAGES,
    maximum: 0, // process.env.WASMUX_CORE_MAX_PAGES,
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

async function createInstance(moduleUrl) {
  const kresponse = await fetch(moduleUrl);
  const kbuffer = await kresponse.arrayBuffer();
  const module = await WebAssembly.compile(kbuffer);

  const loaderList = WebAssembly.Module.customSections(module, ".jsdata.loader");
  const loaderBlob = new Blob(loaderList, { type: "application/javascript" });
  const loaderUrl = URL.createObjectURL(loaderBlob);

  const workerList = WebAssembly.Module.customSections(module, ".jsdata.worker");
  const workerBlob = new Blob(workerList, { type: 'application/javascript' });
  const workerUrl = URL.createObjectURL(workerBlob);

  const { MainContext } = await import(/* webpackIgnore: true */ loaderUrl);

  const mainContext = MainContext.create(module, workerUrl);
  return new UserInstance(mainContext, loaderUrl, workerUrl);
}

const defaultContext = Object.assign(createInstance, {
});

module.exports = defaultContext;
