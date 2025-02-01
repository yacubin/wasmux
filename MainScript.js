const path = require('node:path');
const fs = require('node:fs');
const os = require('node:os');

async function runScript({output})
{
  let lines = [];

  lines.push(`message(STATUS "OS arch ${os.arch()}")`);
  lines.push(`message(STATUS "OS type ${os.type()}")`);
  lines.push(`message(STATUS "OS version ${os.version()}")`);
  lines.push(`message(STATUS "OS platform ${os.platform()}")`);

  await fs.promises.mkdir(path.dirname(output), { recursive: true });
  await fs.promises.writeFile(output, lines.join('\n'), { encoding: "utf8" });
}

function toCIdentifier(key) {
  let result = "";

  let pos = 0;
  while (pos < key.length) {
    let end = key.indexOf("-", pos);
    if (end === -1) {
      end = key.length;
    }
    result += result ? key.charAt(pos).toUpperCase() + key.substring(pos + 1, end) : key.substring(pos, end);
    pos = end + 1;
  }

  return result;
}

function toArgMap(args)
{
  const params = {};
  args.forEach(iter => {
    if (iter.startsWith("--")) {
      const pos = iter.indexOf("=");
      const key = (pos === -1) ? iter.substring(2) : iter.substring(2, pos);
      const val = (pos === -1) ? null : iter.substring(pos + 1);
      params[toCIdentifier(key)] = val;
    }
  });
  return params;
}

function currentArgMap()
{
  return toArgMap(process.argv.slice(2));
}

runScript(currentArgMap()).then(() => process.exit(0)).catch((e) => {
  console.error(e);
  process.exit(1);
});
