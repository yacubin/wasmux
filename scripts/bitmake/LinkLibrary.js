"use strict";

const NAME      = Symbol("NAME");
const PUBLIC_ONLY = Symbol("PUBLIC_ONLY");

function LinkLibrary(scope, name, publicOnly) {
  this[NAME] = name;
  this[PUBLIC_ONLY] = publicOnly;
}

LinkLibrary.createPrivate = (scope, name) => {
  return Object.seal(new LinkLibrary(scope, name, false));
}

LinkLibrary.createPublic = (scope, name) => {
  return Object.seal(new LinkLibrary(scope, name, true));
}

LinkLibrary.prototype = Object.create(Object.prototype, {
  constructor: {
    value: LinkLibrary,
    enumerable: false,
  },
  NAME: {
    get () { return this[NAME]; },
    enumerable: true,
  },
  PUBLIC_ONLY: {
    get () { return this[PUBLIC_ONLY]; },
    set(value) { this[PUBLIC_ONLY] = cloneBoolean(value); },
    enumerable: true,
  },
});

LinkLibrary.prototype.toJSON = function() {
  const json = {};
  for (const key in this)
    json[key] = this[key];
  return json;
}

LinkLibrary.prototype.toString = function() {
  return "${" + this[NAME] + "}";
}

module.exports = {
  LinkLibrary,
};
