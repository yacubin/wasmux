const path = require('node:path');
const fs = require('node:fs');
const variables = require("./scripts/variables.js");
const { fileExists } = require("./scripts/utils/FileSystem.js");

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

async function saveIfDifferent(filename, content)
{
  if (await fileExists(filename)) {
    const oldContent = await fs.promises.readFile(filename, { encoding: "utf8" });
    if (content == oldContent)
      return;
  }

  await fs.promises.mkdir(path.dirname(filename), { recursive: true });
  await fs.promises.writeFile(filename, content, { encoding: "utf8" });
}

class MainContext {
  _package;
  get package() { return this._package; }
  set package(value) { this._package = value; }

  _variables;
  get variables() { return this._variables; }
  set variables(value) { this._variables = value; }
};

async function runScript({output})
{
  const ctx = new MainContext;

  const packageFilepath = path.resolve(__dirname, "package.json");
  const packageContent = await fs.promises.readFile(packageFilepath, "utf-8");
  ctx.package = JSON.parse(packageContent);
  ctx.variables = variables;

  let lines = [];

  lines.push('list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")');
  lines.push('');
  lines.push('set(WASMUX_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")');
  lines.push('');
  lines.push('include(WxMacros)');
  lines.push('include(GenScript)');
  lines.push('');

  for (const [key,val] of Object.entries(ctx.variables)) {
    const space = val.dependency ? "  " : "";
    if (val.dependency) {
      lines.push(`if (${val.dependency})`);
    }
    if (Array.isArray(val.type)) {
      const strings = val.type.map((i) => '"' + i + '"').join(' ');
      lines.push(`${space}set(${key} "${val.value}" CACHE STRING "${val.description}")`);
      lines.push(`${space}set_property(CACHE ${key} PROPERTY STRINGS ${strings})`);
    }
    else if (val.type === "boolean" || (val.type === undefined && typeof val.value === "boolean")) {
      lines.push(`${space}option(${key} "${val.description}" ${val.value ? "ON" : "OFF"})`);
    }
    else if (val.type === "number" || (val.type === undefined && typeof val.value === "number")) {
      lines.push(`${space}set(${key} ${val.value} CACHE STRING "${val.description}")`);
    }
    else if (val.type === "string" || (val.type === undefined && typeof val.value === "string")) {
      lines.push(`${space}set(${key} "${val.value}" CACHE STRING "${val.description}")`);
    }
    else {
      throw `Unknown variable type: ${val.type}`;
    }
    if (val.dependency) {
      lines.push(`endif ()`);
    }
  }

  lines.push('');
  lines.push('set(WASMUX_INSTALL_BINDIR "bin")');
  lines.push('set(WASMUX_INSTALL_LIBDIR "lib")');
  lines.push('set(WASMUX_INSTALL_INCLUDEDIR "include")');
  lines.push('');
  lines.push('if (CONFIG_TARGET_SYSTEM MATCHES "-wasi$")');
  lines.push('  set(WASMUX_INSTALL_LIBDIR "${WASMUX_INSTALL_LIBDIR}/${CMAKE_SYSTEM_PROCESSOR}-wasi")');
  lines.push('endif ()');
  lines.push('');
  lines.push('set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -D__ASSEMBLY__")');
  lines.push('');
  lines.push('configure_file(config.h.cmake "${CMAKE_CURRENT_BINARY_DIR}/config.h" @ONLY)');
  lines.push('include_directories("${CMAKE_CURRENT_BINARY_DIR}")');
  lines.push('');
  lines.push('add_subdirectory(waf)');
  lines.push('add_subdirectory(uapi)');
  lines.push('add_subdirectory(kernel)');
  lines.push('add_subdirectory(tools)');
  lines.push('');

  await saveIfDifferent(output, lines.join('\n'));
}

runScript(currentArgMap()).then(() => process.exit(0)).catch((e) => {
  console.error(e);
  process.exit(1);
});
