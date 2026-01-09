/*
 * MIT License
 *
 * Copyright (c) 2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 * Permission is granted to use, copy, modify, and distribute this software
 * under the MIT License. See LICENSE file for details.
 */

"use strict";

const {
  WEB_KERNEL_MEMORY_ID,
  WEB_KERNEL_MODULE_ID,
  WEI_FALSE_BOOLEAN_ID,
  WEI_TRUE_BOOLEAN_ID,
  WEB_NULL_OBJECT_ID,
  WEB_GLOBAL_THIS_ID,
  WEB_SCRIPT_URL_ID,

  WEB_ConsoleWrite,
  WEB_ObjectRelease,
  WEB_NumberCreate,
  WEB_MemoryCopy,
  WEB_MemorySize,
  WEB_MemoryGrow,
  WEB_MemoryStrnlen,
  WEB_MemoryStrncpy,
  WEB_MemoryFill,
  WEB_StringCreate,
  WEB_StringCreateByArgs,
  WEB_CallObjectMethod,
  WEB_CallIntegerMethod,
  WEB_ObjectCreate,
  WEB_GetObjectProperty,
  WEB_GetIntegerProperty,
  WEB_SetObjectProperty,
  WEB_SetIntegerProperty,
  WEB_AddEventListener,
  WEB_PromiseThen,
  WEB_SetTimeout,
  WEB_SetInterval,
  WEB_ClearTimeout,
  WEB_ClearInterval,
  WEB_ObjectRetain,
  WEB_RemoveEventListener,

  WEB_UserInstanceStart,
  WEB_PostMessage2,
  WEB_PostMessage3,
  WEB_PostMessage4,
  WEB_PostMessage5,
  WEB_PostMessage6,
  WEB_WorkerInstance,
  WEB_WorkerPerform2,
  WEB_WorkerPerform3,
  WEB_WorkerPerform4,
  WEB_WorkerPerform5,
} = require("./webcalls-num");

const {
  sys_ConsoleWrite,
  sys_ObjectRelease,
  sys_NumberCreate,
  sys_MemoryCopy,
  sys_MemorySize,
  sys_MemoryGrow,
  sys_MemoryStrnlen,
  sys_MemoryStrncpy,
  sys_MemoryFill,
  sys_StringCreate,
  sys_StringCreateByArgs,
  sys_CallObjectMethod,
  sys_CallIntegerMethod,
  sys_ObjectCreate,
  sys_GetObjectProperty,
  sys_GetIntegerProperty,
  sys_SetObjectProperty,
  sys_SetIntegerProperty,
  sys_AddEventListener,
  sys_PromiseThen,
  sys_SetTimeout,
  sys_SetInterval,
  sys_ClearTimeout,
  sys_ClearInterval,
  sys_ObjectRetain,
  sys_RemoveEventListener,
  // Main
  sys_WorkerInstance,
  sys_WorkerPerform2,
  sys_WorkerPerform3,
  sys_WorkerPerform4,
  sys_WorkerPerform5,
  // Worker
  sys_UserInstanceStart,
  sys_PostMessage2,
  sys_PostMessage3,
  sys_PostMessage4,
  sys_PostMessage5,
  sys_PostMessage6,
} = require("./webcall-funcs");

function BaseThreadContext(kernelModule, kernelMemory, globalThis, scriptUrl) {
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
  // Main
  this._objects[WEB_WorkerInstance] = sys_WorkerInstance;
  this._objects[WEB_WorkerPerform2] = sys_WorkerPerform2;
  this._objects[WEB_WorkerPerform3] = sys_WorkerPerform3;
  this._objects[WEB_WorkerPerform4] = sys_WorkerPerform4;
  this._objects[WEB_WorkerPerform5] = sys_WorkerPerform5;
  // Worker
  this._objects[WEB_UserInstanceStart] = sys_UserInstanceStart;
  this._objects[WEB_PostMessage2] = sys_PostMessage2;
  this._objects[WEB_PostMessage3] = sys_PostMessage3;
  this._objects[WEB_PostMessage4] = sys_PostMessage4;
  this._objects[WEB_PostMessage5] = sys_PostMessage5;
  this._objects[WEB_PostMessage6] = sys_PostMessage6;
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

module.exports = BaseThreadContext;
