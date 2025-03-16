"use strict";

const { InterfaceIncludes } = require("###/bitmake/InterfaceIncludes.js");

const NAME     = Symbol("NAME");
const INCLUDES = Symbol("INCLUDES");

function InterfaceTarget(name) {
  this[NAME] = name;
  this[INCLUDES] = InterfaceIncludes.create(name);
}

InterfaceTarget.create = (name) => {
  return Object.seal(new InterfaceTarget(name));
}

InterfaceTarget.asInstance = (value) => {
  if (value instanceof InterfaceTarget)
    return value;
  throw new Error(`The '${value}' is not a InterfaceTarget`);
}

InterfaceTarget.prototype = Object.create(Object.prototype, {
  constructor: {
    value: InterfaceTarget,
    enumerable: false,
  },
  NAME: {
    get () { return this[NAME]; },
    enumerable: true,
  },
  INCLUDES: {
    get () { return this[INCLUDES]; },
    enumerable: false,
  },
});

InterfaceTarget.prototype.toJSON = function() {
  const json = {};
  for (const key in this)
    json[key] = (typeof this[key].toJSON === "function") ? this[key].toJSON() : this[key];
  return json;
}

InterfaceTarget.prototype.toString = function() {
  return "${" + this[NAME] + "}";
}

module.exports = {
  InterfaceTarget,
};
