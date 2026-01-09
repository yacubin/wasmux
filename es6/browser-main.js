/*
 * MIT License
 *
 * Copyright (c) 2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 * Permission is granted to use, copy, modify, and distribute this software
 * under the MIT License. See LICENSE file for details.
 */

"use strict";

const { createUserInstance } = require("./main-instance");

async function createInstance(options) {
  if (!crossOriginIsolated) {
    throw 'Only crossOriginIsolated'
  }
  return createUserInstance(options, {
    fetchBuffer: null,
  });
}

module.exports = Object.assign(createInstance, {
});
