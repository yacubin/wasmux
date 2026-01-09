/*
 * MIT License
 *
 * Copyright (c) 2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 * Permission is granted to use, copy, modify, and distribute this software
 * under the MIT License. See LICENSE file for details.
 */

"use strict";

const fs = require("node:fs");
const url = require("node:url");

const { createUserInstance } = require("./main-instance");

async function fetchBuffer(str) {
  if (!(str.startsWith("http://") || str.startsWith("https://"))) {
    const filepath = str.startsWith("file://") ? url.fileURLToPath(str) : str;
    return await fs.promises.readFile(filepath);
  }
  const response = await fetch(str);
  return Buffer.from(await response.arrayBuffer());
}

async function createInstance(moduleUrl) {
  return createUserInstance(await fetchBuffer(moduleUrl));
}

module.exports = Object.assign(createInstance, {
});
