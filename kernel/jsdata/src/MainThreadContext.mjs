import { BaseThreadContext } from './BaseThreadContext.mjs';
import webcalls from 'generated/MainCalls.mjs';

class MainThreadContext extends BaseThreadContext {
  constructor({kernelModule, kernelMemory, scriptUrl}) {
    super(kernelModule, kernelMemory, window, scriptUrl);
    this._webcalls = webcalls;
  }

  async init()
  {
    // WebAssembly.Instance is disallowed on the main thread, if the buffer size is larger than 8MB
    const kinst = await WebAssembly.instantiate(this._kernelModule, this.makeImports());
    this._kernel = kinst.exports;
    this._kernel._start_kernel();
  }
};

export class Kernel {
  _system;
  _workerUrl;

  constructor(kernelModule) {
    if (!crossOriginIsolated) {
      throw 'Only crossOriginIsolated'
    }
  
    const kernelMemory = new WebAssembly.Memory({
      initial: process.env.KPSL_INIT_PAGE_ORDER,
      maximum: process.env.KPSL_MAX_PAGE_ORDER,
      shared: true,
    });

    const workerList = WebAssembly.Module.customSections(kernelModule, process.env.KPSL_WORKER_SECTION);
    const workerBlob = new Blob(workerList, { type: 'application/javascript' });
    this._workerUrl = URL.createObjectURL(workerBlob);

    this._system = new MainThreadContext({kernelModule, kernelMemory, scriptUrl: this._workerUrl});

    setTimeout(async () => await this._system.init(), 0);
  }

  terminate() {
    URL.revokeObjectURL(this._workerUrl);
  }
}
