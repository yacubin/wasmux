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
  WEB_WorkerInstance,
  WEB_WorkerPerform2,
  WEB_WorkerPerform3,
  WEB_WorkerPerform4,
  WEB_WorkerPerform5,
} = require("./webcalls-num");

const { sys_NotImplemented } = require("./webcall-funcs");

function WorkerThreadContext({kernelModule, kernelMemory}) {
  if (!(typeof WorkerGlobalScope !== 'undefined' && self instanceof WorkerGlobalScope)) {
    throw 'Only for Worker';
  }

  BaseThreadContext.call(this, kernelModule, kernelMemory, self, null);
  this._objects[WEB_WorkerInstance] = sys_NotImplemented;
  this._objects[WEB_WorkerPerform2] = sys_NotImplemented;
  this._objects[WEB_WorkerPerform3] = sys_NotImplemented;
  this._objects[WEB_WorkerPerform4] = sys_NotImplemented;
  this._objects[WEB_WorkerPerform5] = sys_NotImplemented;

  const kinst = new WebAssembly.Instance(this._kernelModule, this.makeImports());
  this._kernel = kinst.exports;
}

WorkerThreadContext.prototype = Object.create(BaseThreadContext.prototype);
WorkerThreadContext.prototype.constructor = WorkerThreadContext;

let system = null;
self.addEventListener('message', (event) => {
  const { data } = event;
  switch (data.type) {
  case 'instance':
    system = new WorkerThreadContext(data);
    break;
  case 'perform':
    system.perform(...data.args);
    break;
  }
});
