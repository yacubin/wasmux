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
import { sys_UserInstanceStart } from "./SystemCalls.mjs";
import { sys_PostMessage2 } from "./SystemCalls.mjs";
import { sys_PostMessage3 } from "./SystemCalls.mjs";
import { sys_PostMessage4 } from "./SystemCalls.mjs";
import { sys_PostMessage5 } from "./SystemCalls.mjs";
import { sys_PostMessage6 } from "./SystemCalls.mjs";

class WorkerThreadContext extends BaseThreadContext {
  constructor({kernelModule, kernelMemory})
  {
    if (!(typeof WorkerGlobalScope !== 'undefined' && self instanceof WorkerGlobalScope)) {
      throw 'Only for Worker';
    }

    super(kernelModule, kernelMemory, self, null);
    this._objects[WEB_UserInstanceStart] = sys_UserInstanceStart;
    this._objects[WEB_PostMessage2] = sys_PostMessage2;
    this._objects[WEB_PostMessage3] = sys_PostMessage3;
    this._objects[WEB_PostMessage4] = sys_PostMessage4;
    this._objects[WEB_PostMessage5] = sys_PostMessage5;
    this._objects[WEB_PostMessage6] = sys_PostMessage6;
    this._objects[WEB_WorkerInstance] = sys_NotImplemented;
    this._objects[WEB_WorkerPerform2] = sys_NotImplemented;
    this._objects[WEB_WorkerPerform3] = sys_NotImplemented;
    this._objects[WEB_WorkerPerform4] = sys_NotImplemented;
    this._objects[WEB_WorkerPerform5] = sys_NotImplemented;

    const kinst = new WebAssembly.Instance(this._kernelModule, this.makeImports());
    this._kernel = kinst.exports;
  }
}

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
