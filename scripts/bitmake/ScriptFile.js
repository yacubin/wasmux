"use strict";

const { AbsolutePath } = require("###/utils/AbsolutePath.js");

const TARGET_SCOPE = Symbol("TARGET_SCOPE");
const NAME         = Symbol("NAME");
const FILE         = Symbol("FILE");
const INPUT        = Symbol("INPUT");
const OUTPUT       = Symbol("OUTPUT");
const PARAMS       = Symbol("PARAMS");

const SYSTEM_SCRIPTS_DIR = AbsolutePath.create(__dirname).join("SystemScripts");

function ScriptFile(scope, script) {
  this[TARGET_SCOPE] = scope;
  this[NAME] = script;
  if (/[.\/\\]/.test(script))
    this[FILE] = scope.SOURCE_DIR.resolve(script);
  else
    this[FILE] = SYSTEM_SCRIPTS_DIR.join(script + ".js");
  this[INPUT] = null;
  this[OUTPUT] = null;
  this[PARAMS] = {};
}

ScriptFile.create = function(scope, script) {
  return Object.seal(new ScriptFile(scope, script));
}

ScriptFile.prototype = Object.create(Object.prototype, {
  constructor: {
    value: ScriptFile,
    enumerable: false,
  },
  NAME: {
    get() { return this[NAME]; },
    enumerable: true,
  },
  FILE: {
    get() { return this[FILE]; },
    enumerable: true,
  },
  INPUT: {
    get() { return this[INPUT]; },
    set(value) { this[INPUT] = this[TARGET_SCOPE].SOURCE_DIR.resolve(value); },
    enumerable: true,
  },
  OUTPUT: {
    get() { return this[OUTPUT]; },
    set(value) { this[OUTPUT] = AbsolutePath.create(value); },
    enumerable: true,
  },
  PARAMS: {
    get() { return this[PARAMS]; },
    set(value) { this[PARAMS] = value; },
    enumerable: true,
  },
});

ScriptFile.prototype.toString = function() {
  return this[NAME].toString();
}

ScriptFile.prototype.toJSON = function() {
  const json = {};
  for (const key in this)
    json[key] = this[key];
  return json;
}

module.exports = {
  ScriptFile,
};
