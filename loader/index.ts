/*
 * MIT License
 *
 * Copyright (c) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 * Permission is granted to use, copy, modify, and distribute this software
 * under the MIT License. See LICENSE file for details.
 */

interface WrapperInstance {
  set baseFsUrl(value: string);
  set onmessage(callback: () => void);
  registerDriver(name: string, driverClass: any): void;
  start(): void;
  stop(): void;
};

class UserInstance implements WrapperInstance {
  private _context: any;
  private _loaderUrl: string;
  private _workerUrl: string;

  constructor(context: any, loaderUrl: string, workerUrl: string) {
    this._context = context;
    this._loaderUrl = loaderUrl;
    this._workerUrl = workerUrl;
  }

  public set baseFsUrl(value: string) {
  }

  public set onmessage(callback: () => void) {
  }

  public registerDriver(name: string, driverClass: any): void {
  }

  public start(): void {
    setTimeout(() => this._context.init(), 0);
  }

  public stop(): void {
    URL.revokeObjectURL(this._loaderUrl);
    URL.revokeObjectURL(this._workerUrl);
  }
};

async function createInstance(moduleUrl: string): Promise<WrapperInstance> {
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

export default defaultContext;
