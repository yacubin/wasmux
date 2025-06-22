export function sys_NotImplemented()
{
  console.error('Not Implemented');
  return -1;
}

export function sys_ConsoleWrite(level, msg_id)
{
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

export function sys_MemoryCreate(initial, maximum, shared)
{
  // TODO: Move to C++ code
  const memory = new WebAssembly.Memory({
    initial,
    maximum,
    shared: !!shared,
  });

  return this.createObjectId(memory);
}

export function sys_MemoryCopy(dst_mid, dst_offset, src_mid, src_offset, size)
{
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

export function sys_MemoryFill(mid, offset, value, length)
{
  const bytes = new Uint8Array(this._objects[mid].buffer, offset, length);
  bytes.fill(value);
  return 0;
}

export function sys_MemoryStrnlen(mid, offset, length)
{
  // TODO: On exception, returns 0
  const bytes = new Uint8Array(this._objects[mid].buffer, offset, length);

  let len = 0;
  while (len < bytes.length && bytes[len] != 0) {
    len++;
  }

  return len + 1;
}

export function sys_MemoryStrncpy(dstMemory, dstOffset, srcMemory, srcOffset, count)
{
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

export function sys_MemorySize(memoryId)
{
  const buffer = this._objects[memoryId].buffer;
  return buffer.byteLength;
}

export function sys_MemoryGrow(memoryId, delta)
{
  const memory = this._objects[memoryId];
  return memory.grow(delta);
}

export function sys_UserInstanceStart(moduleId, memoryId)
{
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

export function sys_WorkerInstance(workerId)
{
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

export function sys_ClearInterval(intervalId)
{
  clearInterval(intervalId);
}

export function sys_ClearTimeout(timeoutId)
{
  clearTimeout(timeoutId);
}

export function sys_SetInterval(callback, userdata, delayMs)
{
  return setInterval(this._kernel.perform, delayMs, 2, callback, userdata);
}

export function sys_SetTimeout(callback, userdata, delayMs)
{
  return setTimeout(this._kernel.perform, delayMs, 2, callback, userdata);
}

export function sys_ObjectRetain(objectId)
{
  if (!objectId)
    return 0;
  const object = this._objects[objectId];
  return this.createObjectId(object);
}

export function sys_ObjectRelease(id)
{
  if (!this._objects.hasOwnProperty(id))
    return -1;
  this.deleteObjectId(id);
  return 0;
}

export function sys_StringCreate(memoryId, offset, size)
{
  const buffer = this._objects[memoryId].buffer;
  const bytes = new Uint8Array(buffer, offset, size);
  const str =  String.fromCharCode.apply(String, bytes);
  return this.createObjectId(str);
}

export function sys_StringCreateByArgs()
{
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

export function sys_CallObjectMethod(objectId, methodId)
{
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

export function sys_CallIntegerMethod(objectId, methodId)
{
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

export function sys_ObjectCreate(classId)
{
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

export function sys_NumberCreate(value)
{
  return this.createObjectId(value);
}

export function sys_GetObjectProperty(objectId, propId)
{
  const object = this._objects[objectId];
  const prop = this._objects[propId];
  const result = object[prop];
  if (result === undefined)
    return 0;
  return this.createObjectId(result);
}

export function sys_GetIntegerProperty(objectId, propId)
{
  const object = this._objects[objectId];
  const prop = this._objects[propId];
  return object[prop];
}

export function sys_SetObjectProperty(objectId, propId, valueId)
{
  const object = this._objects[objectId];
  const prop = this._objects[propId];
  const value = this._objects[valueId];

  object[prop] = value;

  return 0;
}

export function sys_SetIntegerProperty(objectId, propId, value)
{
  const object = this._objects[objectId];
  const prop = this._objects[propId];

  object[prop] = value;

  return 0;
}

export function sys_AddEventListener(objectId, typeId, callback, userdata)
{
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

export function sys_RemoveEventListener(objectId, typeId, listenerId)
{
  const object = this._objects[objectId];
  const type = this._objects[typeId];
  const listener = this._objects[listenerId];

  object.removeEventListener(type, listener);
  this.deleteObjectId(listenerId);
  return 0;
}

export function sys_PromiseThen(objectId, resultCallback, errorCallback, userdata)
{
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

export function sys_WorkerPerform2(workerId, callback, userdata)
{
  const worker = this._objects[workerId];
  worker.postMessage({
    type: 'perform',
    args: [
      callback,
      userdata,
    ]
  });
}

export function sys_WorkerPerform3(workerId, callback, userdata, arg1)
{
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

export function sys_WorkerPerform4(workerId, callback, userdata, arg1, arg2)
{
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

export function sys_WorkerPerform5(workerId, callback, userdata, arg1, arg2, arg3)
{
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

export function sys_PostMessage2(callback, userdata)
{
  self.postMessage([
    callback,
    userdata,
  ]);
}

export function sys_PostMessage3(callback, userdata, arg1)
{
  self.postMessage([
    callback,
    userdata,
    arg1 ? this._objects[arg1] : undefined,
  ]);
}

export function sys_PostMessage4(callback, userdata, arg1, arg2)
{
  self.postMessage([
    callback,
    userdata,
    arg1 ? this._objects[arg1] : undefined,
    arg2 ? this._objects[arg2] : undefined,
  ]);
}

export function sys_PostMessage5(callback, userdata, arg1, arg2, arg3)
{
  self.postMessage([
    callback,
    userdata,
    arg1 ? this._objects[arg1] : undefined,
    arg2 ? this._objects[arg2] : undefined,
    arg3 ? this._objects[arg3] : undefined,
  ]);
}

export function sys_PostMessage6(callback, userdata, arg1, arg2, arg3, arg4)
{
  self.postMessage([
    callback,
    userdata,
    arg1 ? this._objects[arg1] : undefined,
    arg2 ? this._objects[arg2] : undefined,
    arg3 ? this._objects[arg3] : undefined,
    arg4 ? this._objects[arg4] : undefined,
  ]);
}
