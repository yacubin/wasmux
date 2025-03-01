function copyObject(o) {
  if (!o || typeof o !== 'object')
    return o;
  if (Array.isArray(o)) {
    const result = [];
    for (const iter of o)
      result.push(copyObject(iter));
    return result;
  }
  else {
    const result = {};
    for (const [key,val] of Object.entries(o))
      result[key] = copyObject(val);
    return result;
  }
}

function assignObject(target, source) {
  if (Array.isArray(target) && Array.isArray(source)) {
    for (const iter of source)
      target.push(iter);
  }
  else {
    for (const key of Object.keys(source)) {
      const a = target[key], b = source[key];
      if (a && typeof a === "object" && b && typeof b === "object")
        assignObject(a, b);
      else
        target[key] = copyObject(b);
    }
  }
}

function arrayWrapper(value) {
  if (value === undefined || Array.isArray(value))
    return value;
  return [ value ];
}

module.exports = {
  copyObject,
  assignObject,
  arrayWrapper,
};
