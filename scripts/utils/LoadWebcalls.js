const url = require('url');

const NOT_IMPLEMENTED = 'NotImplemented';
const BOTH = 'both';

async function loadWebcalls(input, side)
{
  if (side !== BOTH && side !== 'main' && side !== 'worker')
    throw `Unknown '${side}' side name`;

  const module = await import(url.pathToFileURL(input));
  const arr = module.default;
  
  const result = [];
  for (const iter of arr) {
    const name = (side === BOTH || iter.side === BOTH || iter.side === side) ? iter.name : NOT_IMPLEMENTED;
    result.push(name);
  }

  return result;
}

module.exports = {
  loadWebcalls,
};
