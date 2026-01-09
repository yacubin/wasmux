/*
 * MIT License
 *
 * Copyright (c) 2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 * Permission is granted to use, copy, modify, and distribute this software
 * under the MIT License. See LICENSE file for details.
 */

"use strict";

const WEB_KERNEL_MEMORY_ID = 1;
const WEB_KERNEL_MODULE_ID = 2;
const WEI_FALSE_BOOLEAN_ID = 6;
const WEI_TRUE_BOOLEAN_ID = 7;
const WEB_NULL_OBJECT_ID = 8;
const WEB_GLOBAL_THIS_ID = 9;
const WEB_SCRIPT_URL_ID = 10;

const WEB_ConsoleWrite = 11;
const WEB_ObjectRelease = 12;
const WEB_NumberCreate = 13;
  
const WEB_UserInstanceStart = 14;
const WEB_PostMessage2 = 15;
const WEB_PostMessage3 = 16;
const WEB_PostMessage4 = 17;
const WEB_PostMessage5 = 18;
const WEB_PostMessage6 = 19;
  
const WEB_WorkerInstance = 20;
const WEB_MemoryCopy = 21;
const WEB_MemorySize = 22;
const WEB_MemoryGrow = 23;
const WEB_MemoryStrnlen = 24;
const WEB_MemoryStrncpy = 25;
const WEB_MemoryFill = 26;
const WEB_StringCreate = 27;
const WEB_StringCreateByArgs = 28;
const WEB_CallObjectMethod = 29;
const WEB_CallIntegerMethod = 30;
const WEB_ObjectCreate = 31;
const WEB_GetObjectProperty = 32;
const WEB_GetIntegerProperty = 33;
const WEB_SetObjectProperty = 34;
const WEB_SetIntegerProperty = 35;
const WEB_AddEventListener = 36;
const WEB_PromiseThen = 37;
const WEB_SetTimeout = 38;
const WEB_SetInterval = 39;
const WEB_ClearTimeout = 40;
const WEB_ClearInterval = 41;
const WEB_ObjectRetain = 42;
const WEB_RemoveEventListener = 43;
  
const WEB_WorkerPerform2 = 44;
const WEB_WorkerPerform3 = 45;
const WEB_WorkerPerform4 = 46;
const WEB_WorkerPerform5 = 47;

function sys_NotImplemented() {
  console.error('Not Implemented');
  return -1;
}
function sys_ConsoleWrite(level, msg_id) {
  const message = this._objects[msg_id];

  switch (level) {
  case 3:
    console.error(message);
    break;
  case 4:
    console.warn(message);
    break;
  case 6:
    console.info(message);
    break;
  case 7:
    console.debug(message);
    break;
  default:
    console.log(message);
    break;
  }

  return message.length;
}
function sys_MemoryCopy(dst_mid, dst_offset, src_mid, src_offset, size) {
  const dstObj = this._objects[dst_mid];
  const srcObj = this._objects[src_mid];

  let dstBuf = dstObj.buffer;
  if (!dstBuf) // Not WebAssembly.Memory
    dstBuf = dstObj; // FIXME: ArrayBuffer, SharedBuffer, etc

  let srcBuf = srcObj.buffer;
  if (!srcBuf) // Not WebAssembly.Memory
    srcBuf = srcObj; // FIXME: ArrayBuffer, SharedBuffer, etc

  const dst = new Uint8Array(dstBuf, dst_offset, size);
  const src = new Uint8Array(srcBuf, src_offset, size);

  for (let i = 0; i < size; i++) {
    dst[i] = src[i];
  }

  return 0;
}
function sys_MemoryFill(mid, offset, value, length) {
  const bytes = new Uint8Array(this._objects[mid].buffer, offset, length);
  bytes.fill(value);
  return 0;
}
function sys_MemoryStrnlen(mid, offset, length) {
  // TODO: On exception, returns 0
  const bytes = new Uint8Array(this._objects[mid].buffer, offset, length);

  let len = 0;
  while (len < bytes.length && bytes[len] != 0) {
    len++;
  }

  return len + 1;
}
function sys_MemoryStrncpy(dstMemory, dstOffset, srcMemory, srcOffset, count) {
  const dstObj = this._objects[dstMemory];
  const srcObj = this._objects[srcMemory];

  const dst = new Uint8Array(dstObj.buffer, dstOffset, count);
  const src = new Uint8Array(srcObj.buffer, srcOffset, count);

  let result = 0;
  while (result < count) {
    if (!(dst[result] = src[result]))
      break;
    result++;
  }

  return result;
}
function sys_MemorySize(memoryId) {
  const buffer = this._objects[memoryId].buffer;
  return buffer.byteLength;
}
function sys_MemoryGrow(memoryId, delta) {
  const memory = this._objects[memoryId];
  return memory.grow(delta);
}
function sys_UserInstanceStart(moduleId, memoryId) {
  const module = this._objects[moduleId];
  const memory = this._objects[memoryId];

  const imports = {
    env: { memory },
    kernel: this._kernel,
  };

  this._uinst = new WebAssembly.Instance(module, imports);
  // TODO:  return instanceId
  this._uinst.exports._start();
}
function sys_WorkerInstance(workerId) {
  const worker = this._objects[workerId];
  worker.onmessage = (event) => {
    this.perform(...event.data);
  };
  worker.onerror = (event) => {
    console.log("<<<", event);
  };
  worker.postMessage({
    type: 'instance',
    kernelModule: this._kernelModule,
    kernelMemory: this._kernelMemory,
  });
  return 0;
}
function sys_ClearInterval(intervalId) {
  clearInterval(intervalId);
}
function sys_ClearTimeout(timeoutId) {
  clearTimeout(timeoutId);
}
function sys_SetInterval(callback, userdata, delayMs) {
  return setInterval(this._kernel.perform, delayMs, 2, callback, userdata);
}
function sys_SetTimeout(callback, userdata, delayMs) {
  return setTimeout(this._kernel.perform, delayMs, 2, callback, userdata);
}
function sys_ObjectRetain(objectId) {
  if (!objectId)
    return 0;
  const object = this._objects[objectId];
  return this.createObjectId(object);
}
function sys_ObjectRelease(id) {
  if (!this._objects.hasOwnProperty(id))
    return -1;
  this.deleteObjectId(id);
  return 0;
}
function sys_StringCreate(memoryId, offset, size) {
  const buffer = this._objects[memoryId].buffer;
  const bytes = new Uint8Array(buffer, offset, size);
  const str =  String.fromCharCode.apply(String, bytes);
  return this.createObjectId(str);
}
function sys_StringCreateByArgs() {
  const len = arguments[0] & 0xff;
  if (len >= arguments.length * 4) {
    return -1; // Error: Invalid argument
  }

  let index = 0;
  let shift = 8;

  let bytes = new Uint8Array(len);
  for (let i = 0; i < len; i++) {
    bytes[i] = (arguments[index] >> shift) & 0xff;
    shift += 8;
    if (shift >= 32) {
      shift = 0;
      index++;
    }
  }

  const decoder = new TextDecoder("utf-8");
  const str = decoder.decode(bytes);

  return this.createObjectId(str);
}
function sys_CallObjectMethod(objectId, methodId) {
  const object = this._objects[objectId];
  const method = this._objects[methodId];

  const args = [];
  for (let i = 2; i < arguments.length; i++) {
    const id = arguments[i];
    if (!id) {
      break;
    }
    args.push(this._objects[id]);
  }

  const result = object[method](...args);
  return this.createObjectId(result);
}
function sys_CallIntegerMethod(objectId, methodId) {
  const object = this._objects[objectId];
  const method = this._objects[methodId];

  const args = [];
  for (let i = 2; i < arguments.length; i++) {
    const id = arguments[i];
    if (!id) {
      break;
    }
    args.push(this._objects[id]);
  }

  return object[method](...args);
}
function sys_ObjectCreate(classId) {
  const cls = this._objects[classId];
  const args = [];
  for (let i = 1; i < arguments.length; i++) {
    const id = arguments[i];
    if (!id) {
      break;
    }
    args.push(this._objects[id]);
  }
  const object = new cls(...args);
  return this.createObjectId(object);
}
function sys_NumberCreate(value) {
  return this.createObjectId(value);
}
function sys_GetObjectProperty(objectId, propId) {
  const object = this._objects[objectId];
  const prop = this._objects[propId];
  const result = object[prop];
  if (result === undefined)
    return 0;
  return this.createObjectId(result);
}
function sys_GetIntegerProperty(objectId, propId) {
  const object = this._objects[objectId];
  const prop = this._objects[propId];
  return object[prop];
}
function sys_SetObjectProperty(objectId, propId, valueId) {
  const object = this._objects[objectId];
  const prop = this._objects[propId];
  const value = this._objects[valueId];

  object[prop] = value;

  return 0;
}
function sys_SetIntegerProperty(objectId, propId, value) {
  const object = this._objects[objectId];
  const prop = this._objects[propId];

  object[prop] = value;

  return 0;
}
function sys_AddEventListener(objectId, typeId, callback, userdata) {
  const object = this._objects[objectId];
  const type = this._objects[typeId];
  const listener = (event) => {
    const eventId = this.createObjectId(event);
    this._kernel.perform(3, callback, userdata, eventId);
    this.deleteObjectId(eventId);
  };

  object.addEventListener(type, listener);
  return this.createObjectId(listener);
}
function sys_RemoveEventListener(objectId, typeId, listenerId) {
  const object = this._objects[objectId];
  const type = this._objects[typeId];
  const listener = this._objects[listenerId];

  object.removeEventListener(type, listener);
  this.deleteObjectId(listenerId);
  return 0;
}
function sys_PromiseThen(objectId, resultCallback, errorCallback, userdata) {
  const object = this._objects[objectId];

  object.then(
    (value) => {
      const resultId = this.createObjectId(value);
      this._kernel.perform(3, resultCallback, userdata, resultId);
      this.deleteObjectId(resultId);
    },
    (reason) => {
      const reasonId = this.createObjectId(reason);
      this._kernel.perform(3, errorCallback, userdata, reasonId);
      this.deleteObjectId(reasonId);
    },
  );

  return 0;
}
function sys_WorkerPerform2(workerId, callback, userdata) {
  const worker = this._objects[workerId];
  worker.postMessage({
    type: 'perform',
    args: [
      callback,
      userdata,
    ]
  });
}
function sys_WorkerPerform3(workerId, callback, userdata, arg1) {
  const worker = this._objects[workerId];
  worker.postMessage({
    type: 'perform',
    args: [
      callback,
      userdata,
      arg1 ? this._objects[arg1] : undefined,
    ]
  });
}
function sys_WorkerPerform4(workerId, callback, userdata, arg1, arg2) {
  const worker = this._objects[workerId];
  worker.postMessage({
    type: 'perform',
    args: [
      callback,
      userdata,
      arg1 ? this._objects[arg1] : undefined,
      arg2 ? this._objects[arg2] : undefined,
    ]
  });
}
function sys_WorkerPerform5(workerId, callback, userdata, arg1, arg2, arg3) {
  const worker = this._objects[workerId];
  worker.postMessage({
    type: 'perform',
    args: [
      callback,
      userdata,
      arg1 ? this._objects[arg1] : undefined,
      arg2 ? this._objects[arg2] : undefined,
      arg3 ? this._objects[arg3] : undefined,
    ]
  });
}
function sys_PostMessage2(callback, userdata) {
  self.postMessage([
    callback,
    userdata,
  ]);
}
function sys_PostMessage3(callback, userdata, arg1) {
  self.postMessage([
    callback,
    userdata,
    arg1 ? this._objects[arg1] : undefined,
  ]);
}
function sys_PostMessage4(callback, userdata, arg1, arg2) {
  self.postMessage([
    callback,
    userdata,
    arg1 ? this._objects[arg1] : undefined,
    arg2 ? this._objects[arg2] : undefined,
  ]);
}
function sys_PostMessage5(callback, userdata, arg1, arg2, arg3) {
  self.postMessage([
    callback,
    userdata,
    arg1 ? this._objects[arg1] : undefined,
    arg2 ? this._objects[arg2] : undefined,
    arg3 ? this._objects[arg3] : undefined,
  ]);
}
function sys_PostMessage6(callback, userdata, arg1, arg2, arg3, arg4) {
  self.postMessage([
    callback,
    userdata,
    arg1 ? this._objects[arg1] : undefined,
    arg2 ? this._objects[arg2] : undefined,
    arg3 ? this._objects[arg3] : undefined,
    arg4 ? this._objects[arg4] : undefined,
  ]);
}

function BaseThreadContext(kernelModule, kernelMemory, isWorker, scriptUrl) {
  this._objects = {};
  this._objectCount = 0;
  this._webcalls = {};

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
  this._objects[WEB_WorkerInstance] = isWorker ? sys_NotImplemented : sys_WorkerInstance;
  this._objects[WEB_WorkerPerform2] = isWorker ? sys_NotImplemented : sys_WorkerPerform2;
  this._objects[WEB_WorkerPerform3] = isWorker ? sys_NotImplemented : sys_WorkerPerform3;
  this._objects[WEB_WorkerPerform4] = isWorker ? sys_NotImplemented : sys_WorkerPerform4;
  this._objects[WEB_WorkerPerform5] = isWorker ? sys_NotImplemented : sys_WorkerPerform5;

  this._objects[WEB_UserInstanceStart] = isWorker ? sys_UserInstanceStart : sys_NotImplemented;
  this._objects[WEB_PostMessage2] = isWorker ? sys_PostMessage2 : sys_NotImplemented;
  this._objects[WEB_PostMessage3] = isWorker ? sys_PostMessage3 : sys_NotImplemented;
  this._objects[WEB_PostMessage4] = isWorker ? sys_PostMessage4 : sys_NotImplemented;
  this._objects[WEB_PostMessage5] = isWorker ? sys_PostMessage5 : sys_NotImplemented;
  this._objects[WEB_PostMessage6] = isWorker ? sys_PostMessage6 : sys_NotImplemented;
}

BaseThreadContext.prototype.makeImports = function() {
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

BaseThreadContext.prototype.init = async function() {
  // WebAssembly.Instance is disallowed on the main thread, if the buffer size is larger than 8MB
  const kinst = await WebAssembly.instantiate(this._kernelModule, this.makeImports());
  this._kernel = kinst.exports;
}

BaseThreadContext.prototype.getStringByMid = function(mid, offset, size) {
  const buffer = this._objects[mid].buffer;
  const bytes = new Uint8Array(buffer, offset, size);
  return String.fromCharCode.apply(String, bytes);
}

BaseThreadContext.prototype.createObjectId = function(object) {
  const objectId = this._objectCount++;
  this._objects[objectId] = object;
  return objectId;
}

BaseThreadContext.prototype.deleteObjectId = function(objectId) {
  delete this._objects[objectId];
}

BaseThreadContext.prototype.perform = function(callback, userdata, ...args) {
  const argsIds = args.map((o) => o !== undefined ? this.createObjectId(o) : 0);
  this._kernel.perform(2 + argsIds.length, callback, userdata, ...argsIds);
  argsIds.forEach(i => i && this.deleteObjectId(i));
}

let system = null;
if (typeof WorkerGlobalScope !== 'undefined' && globalThis instanceof WorkerGlobalScope) {
  globalThis.addEventListener("message", (event) => {
    const { data } = event;
    switch (data.type) {
    case 'instance':
      system = new BaseThreadContext(data.kernelModule, data.kernelMemory, true, null);
      system.init();
      break;
    case 'perform':
      system.perform(...data.args);
      break;
    }
  });
  if (self !== globalThis) {
    throw "Variable self is not globalThis";
  }
}
else {
  module.exports = BaseThreadContext;
}
