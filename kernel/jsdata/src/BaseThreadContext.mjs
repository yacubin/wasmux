import { WEB_KERNEL_MEMORY_ID } from './Object.mjs';
import { WEB_KERNEL_MODULE_ID } from './Object.mjs';
import { WEI_FALSE_BOOLEAN_ID } from './Object.mjs';
import { WEI_TRUE_BOOLEAN_ID } from './Object.mjs';
import { WEB_NULL_OBJECT_ID } from './Object.mjs';
import { WEB_GLOBAL_THIS_ID } from './Object.mjs';
import { WEB_SCRIPT_URL_ID } from './Object.mjs';

import { WEB_ConsoleWrite } from "./Object.mjs";
import { WEB_ObjectRelease } from "./Object.mjs";
import { WEB_NumberCreate } from "./Object.mjs";
import { WEB_MemoryCopy } from "./Object.mjs";
import { WEB_MemorySize } from "./Object.mjs";
import { WEB_MemoryGrow } from "./Object.mjs";
import { WEB_MemoryStrnlen } from "./Object.mjs";
import { WEB_MemoryStrncpy } from "./Object.mjs";
import { WEB_MemoryFill } from "./Object.mjs";
import { WEB_StringCreate } from "./Object.mjs";
import { WEB_StringCreateByArgs } from "./Object.mjs";
import { WEB_CallObjectMethod } from "./Object.mjs";
import { WEB_CallIntegerMethod } from "./Object.mjs";
import { WEB_ObjectCreate } from "./Object.mjs";
import { WEB_GetObjectProperty } from "./Object.mjs";
import { WEB_GetIntegerProperty } from "./Object.mjs";
import { WEB_SetObjectProperty } from "./Object.mjs";
import { WEB_SetIntegerProperty } from "./Object.mjs";
import { WEB_AddEventListener } from "./Object.mjs";
import { WEB_PromiseThen } from "./Object.mjs";
import { WEB_SetTimeout } from "./Object.mjs";
import { WEB_SetInterval } from "./Object.mjs";
import { WEB_ClearTimeout } from "./Object.mjs";
import { WEB_ClearInterval } from "./Object.mjs";
import { WEB_ObjectRetain } from "./Object.mjs";
import { WEB_RemoveEventListener } from "./Object.mjs";

import { sys_ConsoleWrite } from "./SystemCalls.mjs";
import { sys_ObjectRelease } from "./SystemCalls.mjs";
import { sys_NumberCreate } from "./SystemCalls.mjs";
import { sys_MemoryCopy } from "./SystemCalls.mjs";
import { sys_MemorySize } from "./SystemCalls.mjs";
import { sys_MemoryGrow } from "./SystemCalls.mjs";
import { sys_MemoryStrnlen } from "./SystemCalls.mjs";
import { sys_MemoryStrncpy } from "./SystemCalls.mjs";
import { sys_MemoryFill } from "./SystemCalls.mjs";
import { sys_StringCreate } from "./SystemCalls.mjs";
import { sys_StringCreateByArgs } from "./SystemCalls.mjs";
import { sys_CallObjectMethod } from "./SystemCalls.mjs";
import { sys_CallIntegerMethod } from "./SystemCalls.mjs";
import { sys_ObjectCreate } from "./SystemCalls.mjs";
import { sys_GetObjectProperty } from "./SystemCalls.mjs";
import { sys_GetIntegerProperty } from "./SystemCalls.mjs";
import { sys_SetObjectProperty } from "./SystemCalls.mjs";
import { sys_SetIntegerProperty } from "./SystemCalls.mjs";
import { sys_AddEventListener } from "./SystemCalls.mjs";
import { sys_PromiseThen } from "./SystemCalls.mjs";
import { sys_SetTimeout } from "./SystemCalls.mjs";
import { sys_SetInterval } from "./SystemCalls.mjs";
import { sys_ClearTimeout } from "./SystemCalls.mjs";
import { sys_ClearInterval } from "./SystemCalls.mjs";
import { sys_ObjectRetain } from "./SystemCalls.mjs";
import { sys_RemoveEventListener } from "./SystemCalls.mjs";

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
    this._objects[WEB_ConsoleWrite] = sys_ConsoleWrite;
    this._objects[WEB_ObjectRelease] = sys_ObjectRelease;
    this._objects[WEB_NumberCreate] = sys_NumberCreate;
    this._objects[WEB_MemoryCopy] = sys_MemoryCopy;
    this._objects[WEB_MemorySize] = sys_MemorySize;
    this._objects[WEB_MemoryGrow] = sys_MemoryGrow;
    this._objects[WEB_MemoryStrnlen] = sys_MemoryStrnlen;
    this._objects[WEB_MemoryStrncpy] = sys_MemoryStrncpy;
    this._objects[WEB_MemoryFill] = sys_MemoryFill;
    this._objects[WEB_StringCreate] = sys_StringCreate;
    this._objects[WEB_StringCreateByArgs] = sys_StringCreateByArgs;
    this._objects[WEB_CallObjectMethod] = sys_CallObjectMethod;
    this._objects[WEB_CallIntegerMethod] = sys_CallIntegerMethod;
    this._objects[WEB_ObjectCreate] = sys_ObjectCreate;
    this._objects[WEB_GetObjectProperty] = sys_GetObjectProperty;
    this._objects[WEB_GetIntegerProperty] = sys_GetIntegerProperty;
    this._objects[WEB_SetObjectProperty] = sys_SetObjectProperty;
    this._objects[WEB_SetIntegerProperty] = sys_SetIntegerProperty;
    this._objects[WEB_AddEventListener] = sys_AddEventListener;
    this._objects[WEB_PromiseThen] = sys_PromiseThen;
    this._objects[WEB_SetTimeout] = sys_SetTimeout;
    this._objects[WEB_SetInterval] = sys_SetInterval;
    this._objects[WEB_ClearTimeout] = sys_ClearTimeout;
    this._objects[WEB_ClearInterval] = sys_ClearInterval;
    this._objects[WEB_ObjectRetain] = sys_ObjectRetain;
    this._objects[WEB_RemoveEventListener] = sys_RemoveEventListener;
  }

  makeImports()
  {
    return {
      env: {
        memory: this._kernelMemory,
        _math_random: Math.random,
        _date_now: Date.now,
        _performance_now: performance.now.bind(performance),
        _webcall: (number, arg1, arg2, arg3, arg4, arg5, arg6) => this._objects[number].call(this, arg1, arg2, arg3, arg4, arg5, arg6),
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
    const argsIds = args.map((o) => o !== undefined ? this.createObjectId(o) : 0);
    this._kernel.perform(2 + argsIds.length, callback, userdata, ...argsIds);
    argsIds.forEach(i => i && this.deleteObjectId(i));
  }
};
