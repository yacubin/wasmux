/*
 * MIT License
 *
 * Copyright (c) 2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 * Permission is granted to use, copy, modify, and distribute this software
 * under the MIT License. See LICENSE file for details.
 */

"use strict";

const UserInstance = require("./user-instance");

async function createInstance(options) {
  if (!crossOriginIsolated) {
    throw 'Only crossOriginIsolated'
  }
  return UserInstance.createAsync(options, {
    WorkerCtor: globalThis.Worker,
    fetchBuffer: null,
  });
}

module.exports = Object.assign(createInstance, {
});
