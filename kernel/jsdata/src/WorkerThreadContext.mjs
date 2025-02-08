import { BaseThreadContext } from './BaseThreadContext.mjs';
import webcalls from 'generated/WorkerCalls.mjs';

class WorkerThreadContext extends BaseThreadContext {
  constructor({kernelModule, kernelMemory})
  {
    if (!(typeof WorkerGlobalScope !== 'undefined' && self instanceof WorkerGlobalScope)) {
      throw 'Only for Worker';
    }

    super(kernelModule, kernelMemory, self, null);
    this._webcalls = webcalls;

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
