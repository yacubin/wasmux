import { WEB_KERNEL_MEMORY_ID } from './Object.mjs';
import { WEB_KERNEL_MODULE_ID } from './Object.mjs';
import { WEI_FALSE_BOOLEAN_ID } from './Object.mjs';
import { WEI_TRUE_BOOLEAN_ID } from './Object.mjs';
import { WEB_NULL_OBJECT_ID } from './Object.mjs';
import { WEB_GLOBAL_THIS_ID } from './Object.mjs';
import { WEB_SCRIPT_URL_ID } from './Object.mjs';

export class BaseThreadContext {
  _objects = {};
  _objectCount = 0;
  _webcalls = {};

  _objectCount;
  _kernelModule;
  _kernelMemory;

  constructor(kernelModule, kernelMemory, globalThis, scriptUrl) {
    this._objectCount = 0x00000100;
    this._kernelModule = kernelModule;
    this._kernelMemory = kernelMemory;

    this._objects[WEB_KERNEL_MEMORY_ID] = kernelMemory;
    this._objects[WEB_KERNEL_MODULE_ID] = kernelModule;
    this._objects[3] = null;
    this._objects[4] = null;
    this._objects[5] = null;
    this._objects[WEI_FALSE_BOOLEAN_ID] = false;
    this._objects[WEI_TRUE_BOOLEAN_ID] = true;
    this._objects[WEB_NULL_OBJECT_ID] = null;
    this._objects[WEB_GLOBAL_THIS_ID] = globalThis;
    this._objects[WEB_SCRIPT_URL_ID] = scriptUrl;
  }

  makeImports()
  {
    return {
      env: {
        memory: this._kernelMemory,
        math_random: Math.random,
        date_now: Date.now,
        performance_now: performance.now.bind(performance),
        webcall0: (number) => this._webcalls[number].call(this),
        webcall1: (number, arg1) => this._webcalls[number].call(this, arg1),
        webcall2: (number, arg1, arg2) => this._webcalls[number].call(this, arg1, arg2),
        webcall3: (number, arg1, arg2, arg3) => this._webcalls[number].call(this, arg1, arg2, arg3),
        webcall4: (number, arg1, arg2, arg3, arg4) => this._webcalls[number].call(this, arg1, arg2, arg3, arg4),
        webcall5: (number, arg1, arg2, arg3, arg4, arg5) => this._webcalls[number].call(this, arg1, arg2, arg3, arg4, arg5),
        webcall6: (number, arg1, arg2, arg3, arg4, arg5, arg6) => this._webcalls[number].call(this, arg1, arg2, arg3, arg4, arg5, arg6),
      },
    };
  }

  getStringByMid(mid, offset, size)
  {
    const buffer = this._objects[mid].buffer;
    const bytes = new Uint8Array(buffer, offset, size);
    return String.fromCharCode.apply(String, bytes);
  }

  createObjectId(object)
  {
    const objectId = this._objectCount++;
    this._objects[objectId] = object;
    return objectId;
  }

  deleteObjectId(objectId)
  {
    delete this._objects[objectId];
  }

  perform(callback, userdata, ...args)
  {
    const argsIds = args.map((o) => o && this.createObjectId(o));
    this._kernel.perform(callback, userdata, ...argsIds);
    argsIds.forEach(i => i && this.deleteObjectId(i));
  }
};
