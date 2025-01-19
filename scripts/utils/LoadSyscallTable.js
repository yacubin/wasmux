const fs = require('fs');

// x84: <number> <abi> <name> <entry point> <compat entry point>
// x64_84: <number> <abi> <name> <entry point>

async function loadSyscallTable(filename, abis)
{
  if (typeof abis === 'string')
    abis = abis.split(',');

  const content = await fs.promises.readFile(filename, 'utf8');

  const result = [];
  const numSet = new Set;
  for (let line of content.split('\n')) {
    line = line.replace(/#.*/, '').trim();
    if (!line.length)
      continue;

    const items = line.split(/[ \t]+/);
    if (items.length < 3)
      throw `Unknow line: ${line}`;
    const [number, abi, name] = items;
    
    if (!/^\d+$/.test(number))
      throw `First is not a number of line ${line}`;

    if (!abis.includes(abi))
      continue;

    if (numSet.has(number))
      throw `The number ${number} is already there for line ${line}`;

    const item = { number: parseInt(number), abi, name };

    if (items.length > 3) {
      item.entryPoint = items[3];
      if (items.length > 4)
        item.compatEntryPoint = items[4];
    }

    result.push(item);
  }

  return result.sort((a, b) => a.number - b.number);
}

module.exports = {
  loadSyscallTable,
};
