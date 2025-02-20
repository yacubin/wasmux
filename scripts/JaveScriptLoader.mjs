import url from 'node:url';
import { InjectContext } from "###/inject/InjectContext.mjs";

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
      const val = (pos === -1) ? true : iter.substring(pos + 1);
      params[toCIdentifier(key)] = val;
    }
  });
  return params;
}

async function runScript()
{
  const argsMain = process.argv.slice(2);
  const indexOfUserArgs = argsMain.findIndex((i) => i === "--");
  const argsMap = toArgMap(indexOfUserArgs === -1 ? argsMain : argsMain.slice(0, indexOfUserArgs));
  const entryScript = argsMap.script;
  const scriptUrl = url.pathToFileURL(entryScript);
  
  const module = await import(scriptUrl);
  const func = module.default;

  let args = {};
  if (argsMap.type === "add_custom_script" || argsMap.type === "execute_script") {
    const desc = {
      SCRIPT: {
        type: "string",
      },
      WORK_DIR: {
        type: "string",
        optional: true,
      },
      ...module.ARGS,
    };

    const argsUser = indexOfUserArgs === -1 ? [] : argsMain.slice(indexOfUserArgs + 1);
    let key;
    const vals = {};
    for (const iter of argsUser) {
      if (desc.hasOwnProperty(iter)) {
        key = iter;
        continue;
      }
      if (!key) {
        throw `Unknown argument ${iter}`;
      }
      switch (desc[key].type) {
      case "string":
        if (vals[key])
          throw `Argument ${key} support only one value`;
        vals[key] = iter;
        break;
      default:
        throw `Unknown type ${desc[key].type} for ${key}`;
      }
    }

    for (const [ key, {name, optional} ] of Object.entries(desc)) {
      if (!vals.hasOwnProperty(key)) {
        if (optional)
          continue;
        throw `Missing argument ${key}`;
      }
      if (!name)
        continue;
      if (args[name])
        throw `Duplicate name ${name} of ${key}`;
      args[name] = vals[key];
    }
  }
  else {
    args = argsMap;
  }

  const ctx = new InjectContext(entryScript, args);

  if (argsMap.pluginList) {
    for (const filename of argsMap.pluginList.split(";")) {
      await ctx.loadPlugin(filename);
    }
  }

  await ctx.initPlugins();

  if (ctx.configScript) {
    await ctx.loadConfig(ctx.configScript);
  }

  const result = func(ctx, args);
  if (result instanceof Promise) {
    await result;
  }
}

runScript().then(() => process.exit(0)).catch((e) => {
  console.error(e);
  process.exit(1);
});
