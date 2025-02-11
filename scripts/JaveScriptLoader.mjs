import url from 'node:url';
import { filepathToMacroCIdentifier } from "###/utils/CXXHelper.js"

function toCIdentifier(key) {
  let result = "";
  console.log(">>>", filepathToMacroCIdentifier("SASDAS-sdsa"))

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

async function runScript()
{
  const scriptUrl = url.pathToFileURL(process.argv[2]);
  const argMap = toArgMap(process.argv.slice(3));
  
  const module = await import(scriptUrl);
  const func = module.default;
  
  const result = func(argMap);
  if (result instanceof Promise) {
    await result;
  }
}

runScript().then(() => process.exit(0)).catch((e) => {
  console.error(e);
  process.exit(1);
});
