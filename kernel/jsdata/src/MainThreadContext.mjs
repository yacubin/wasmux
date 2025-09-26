import { BaseThreadContext } from './BaseThreadContext.mjs';

import { WEB_UserInstanceStart } from "./Object.mjs";
import { WEB_PostMessage2 } from "./Object.mjs";
import { WEB_PostMessage3 } from "./Object.mjs";
import { WEB_PostMessage4 } from "./Object.mjs";
import { WEB_PostMessage5 } from "./Object.mjs";
import { WEB_PostMessage6 } from "./Object.mjs";
import { WEB_WorkerInstance } from "./Object.mjs";
import { WEB_WorkerPerform2 } from "./Object.mjs";
import { WEB_WorkerPerform3 } from "./Object.mjs";
import { WEB_WorkerPerform4 } from "./Object.mjs";
import { WEB_WorkerPerform5 } from "./Object.mjs";

import { sys_NotImplemented } from "./SystemCalls.mjs";
import { sys_WorkerInstance } from "./SystemCalls.mjs";
import { sys_WorkerPerform2 } from "./SystemCalls.mjs";
import { sys_WorkerPerform3 } from "./SystemCalls.mjs";
import { sys_WorkerPerform4 } from "./SystemCalls.mjs";
import { sys_WorkerPerform5 } from "./SystemCalls.mjs";

export class MainContext extends BaseThreadContext {
  constructor({kernelModule, kernelMemory, scriptUrl}) {
    super(kernelModule, kernelMemory, window, scriptUrl);
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

  async init()
  {
    // WebAssembly.Instance is disallowed on the main thread, if the buffer size is larger than 8MB
    const kinst = await WebAssembly.instantiate(this._kernelModule, this.makeImports());
    this._kernel = kinst.exports;
    this._kernel._start_kernel();
  }

  static create(kernelModule, workerUrl) {
    if (!crossOriginIsolated) {
      throw 'Only crossOriginIsolated'
    }
  
    const kernelMemory = new WebAssembly.Memory({
      initial: process.env.WASMUX_CORE_INIT_PAGES,
      maximum: process.env.WASMUX_CORE_MAX_PAGES,
      shared: true,
    });

    return new MainContext({kernelModule, kernelMemory, scriptUrl: workerUrl});
  }
};
