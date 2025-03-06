"use strict";

const NAME = Symbol("NAME");

function RefTarget(name) {
  this[NAME] = name;
}

RefTarget.prototype = Object.create(Object.prototype, {
  constructor: {
    value: RefTarget,
    enumerable: false,
  },
  NAME: {
    get () { return this[NAME]; },
    enumerable: true,
  },
});

RefTarget.prototype.toJSON = function() {
  const json = {};
  for (const key in this)
    json[key] = this[key];
  return json;
}

RefTarget.prototype.toString = function() {
  return "${" + this[NAME] + "}";
}

RefTarget.create = (name) => {
  return Object.seal(new RefTarget(name));
}

module.exports = {
  RefTarget,
};
