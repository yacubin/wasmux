import { BaseThreadContext } from './BaseThreadContext.mjs';
import webcalls from 'generated/MainCalls.mjs';

export class MainContext extends BaseThreadContext {
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
