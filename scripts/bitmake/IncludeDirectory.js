"use strict";

const { cloneBoolean } = require("###/bitmake/StrictType.js");

const NAME         = Symbol("NAME");
const PATH         = Symbol("PATH");
const PUBLIC_ONLY  = Symbol("PUBLIC_ONLY");

function IncludeDirectory(scope, dir, publicOnly) {
  this[NAME] = dir.toString();
  this[PATH] = scope.SOURCE_DIR.resolve(dir);
  this[PUBLIC_ONLY] = cloneBoolean(publicOnly);
}

IncludeDirectory.createPublic = function(scope, dir) {
  return Object.seal(new IncludeDirectory(scope, dir, true));
}

IncludeDirectory.createPrivate = function(scope, dir) {
  return Object.seal(new IncludeDirectory(scope, dir, false));
}

IncludeDirectory.prototype = Object.create(Object.prototype, {
  constructor: {
    value: IncludeDirectory,
    enumerable: false,
  },
  NAME: {
    get() { return this[NAME]; },
    enumerable: true,
  },
  PATH: {
    get() { return this[PATH]; },
    enumerable: true,
  },
  PUBLIC_ONLY: {
    get () { return this[PUBLIC_ONLY]; },
    set(value) { this[PUBLIC_ONLY] = cloneBoolean(value); },
    enumerable: true,
  },
});

IncludeDirectory.prototype.toString = function() {
  return this[PATH].toString();
}

IncludeDirectory.prototype.toJSON = function() {
  const json = {};
  for (const key in this)
    json[key] = this[key];
  return json;
}

module.exports = {
  IncludeDirectory,
};
