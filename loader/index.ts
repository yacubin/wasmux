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
  get drivers(): any;
};

async function createInstance(moduleUrl: string): Promise<WrapperInstance> {
  const kresponse = await fetch(moduleUrl);
  const kbuffer = await kresponse.arrayBuffer();
  const kmodule = await WebAssembly.compile(kbuffer);

  const loaderList = WebAssembly.Module.customSections(kmodule, ".jsdata.loader");
  const loaderBlob = new Blob(loaderList, { type: "application/javascript" });

  const loaderUrl = URL.createObjectURL(loaderBlob);
  const { Kernel } = await import(/* webpackIgnore: true */ loaderUrl);
  URL.revokeObjectURL(loaderUrl);

  return new Kernel(kmodule);
}

const defaultContext = Object.assign(createInstance, {
});

export default defaultContext;
