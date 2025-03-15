"use strict";

const { Scope } = require("###/bitmake/Scope.js");
const { cloneString } = require("###/bitmake/StrictType.js");
const { ScriptFile } = require("###/bitmake/ScriptFile.js");

const TARGET_SCOPE = Symbol("TARGET_SCOPE");
const NAME         = Symbol("NAME");
const SCRIPTS      = Symbol("SCRIPTS");

function CustomTarget(scope, name) {
  this[TARGET_SCOPE] = Scope.create(scope);
  this[NAME] = cloneString(name);
  this[SCRIPTS] = [];
}

CustomTarget.create = function(scope, name) {
  return Object.seal(new CustomTarget(scope, name));
}

CustomTarget.prototype = Object.create(Object.prototype, {
  constructor: {
    value: CustomTarget,
    enumerable: false,
  },
  NAME: {
    get() { return this[NAME]; },
    enumerable: true,
  },
  TARGET_SCOPE: {
    get() { return this[TARGET_SCOPE]; },
    enumerable: true,
  },
  SCRIPTS: {
    get() { return this[SCRIPTS]; },
    enumerable: true,
  },
});

CustomTarget.prototype.toString = function() {
  return this[NAME].toString();
}

CustomTarget.prototype.toJSON = function() {
  const json = {};
  for (const key in this)
    json[key] = this[key];
  return json;
}

CustomTarget.prototype.addScript = function(script, params) {
  const item = ScriptFile.create(this[TARGET_SCOPE], script);
  if (params.input)
    item.INPUT = params.input;
  item.OUTPUT = params.output;
  item.PARAMS = params;
  this[SCRIPTS].push(item);
}

CustomTarget.prototype.addDependencies = function(...dependencies) {
}

module.exports = {
  CustomTarget,
};
