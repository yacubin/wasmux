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
const { Worker } = require("node:worker_threads");

const { createUserInstance } = require("./main-instance");

async function createInstance(options) {
  return createUserInstance(options, {
    WorkerCtor: Worker,
    fetchBuffer: async (input) => {
      const filepath = input.startsWith("file://") ? url.fileURLToPath(input) : input;
      return await fs.promises.readFile(filepath);
    },
  });
}

module.exports = Object.assign(createInstance, {
});
