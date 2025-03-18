"use strict";

const { InterfaceIncludes } = require("###/bitmake/InterfaceIncludes.js");
const { InterfaceObjects } = require("###/bitmake/InterfaceObjects.js");

const NAME     = Symbol("NAME");
const INCLUDES = Symbol("INCLUDES");
const SOURCES  = Symbol("SOURCES");

function InterfaceTarget(name) {
  this[NAME] = name;
  this[SOURCES] = [];
  this[INCLUDES] = [];
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
  SOURCES: {
    get () { return this[SOURCES]; },
    enumerable: false,
  },
});

InterfaceTarget.prototype.toJSON = function() {
  const json = {};
  for (const key in this)
    json[key] = this[key];
  return json;
}

InterfaceTarget.prototype.toString = function() {
  return "${" + this[NAME] + "}";
}

InterfaceTarget.prototype.addSource = function(...sources) {
  for (const iter of sources.flat(1))
    this[SOURCES].push(iter);
}

InterfaceTarget.prototype.addIncludes = function(...includes) {
  for (const iter of includes.flat(1))
    this[INCLUDES].push({ VALUE: iter, PUBLIC_ONLY: false });
}

InterfaceTarget.prototype.addPublicIncludes = function(...includes) {
  for (const iter of includes.flat(1))
    this[INCLUDES].push({ VALUE: iter, PUBLIC_ONLY: true });
}

InterfaceTarget.prototype.includes = function() {
  return InterfaceIncludes.create(this[NAME]);
}

InterfaceTarget.prototype.objects = function() {
  return InterfaceObjects.create(this[NAME]);
}

module.exports = {
  InterfaceTarget,
};
