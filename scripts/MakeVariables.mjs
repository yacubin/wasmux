import fs from 'node:fs';
import path from 'node:path';
import url from 'node:url';

import { generatedScriptNameComment } from "###/utils/CXXHelper.js";
import { fileExists } from "###/utils/FileSystem.js";

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

async function linesSaveTo(filename, lines)
{
  await saveIfDifferent(filename, lines.join('\n'));
}

async function generateCmake(script, settings, filename, print)
{
  let maxLength = 0;
  for (const name of Object.keys(settings))
    maxLength = Math.max(maxLength, name.length);
  const leader = " .".repeat((maxLength + 4) / 2);

  const lines = [];

  for (const [name, entry] of Object.entries(settings)) {
    const space = entry.depends ? "  " : "";
    if (entry.depends) {
      lines.push(`if (${entry.depends})`);
    }
    const description = entry.description || "";
    if (typeof entry.value === "boolean") {
      lines.push(`${space}option(${name} "${description}" ${entry.value ? "ON" : "OFF"})`);
    }
    else if (typeof entry.value === "number") {
      lines.push(`${space}set(${name} ${entry.value} CACHE STRING "${description}")`);
    }
    else if (typeof entry.value === "string") {
      lines.push(`${space}set(${name} "${entry.value}" CACHE STRING "${description}")`);
      if (Array.isArray(entry.type)) {
        const strings = entry.type.map((i) => '"' + i + '"').join(' ');
        lines.push(`${space}set_property(CACHE ${name} PROPERTY STRINGS ${strings})`);
      }
    }
    else {
      throw `Not supported value of ${entry.value}`;
    }
    if (print) {
      lines.push(`${space}message(STATUS "${name}:${leader.substring(name.length)} \${${name}}")`);
    }
    if (entry.depends) {
      lines.push("endif ()");
    }
    lines.push("");
  }

  await linesSaveTo(filename, lines);
}

async function generateHeader(script, settings, filename, print)
{
  const lines = [];

  lines.push(generatedScriptNameComment(script));
  lines.push("");

  for (const [name, entry] of Object.entries(settings)) {
    if (entry.description) {
      lines.push(`/* ${entry.description} */`);
    }
    if (typeof entry.value === "boolean") {
      lines.push(`#cmakedefine01 ${name}`);
    }
    else if (typeof entry.value === "number") {
      lines.push(`#define ${name} @${name}@`);
    }
    else if (typeof entry.value === "string") {
      lines.push(`#define ${name} "@${name}@"`);
    }
    else {
      throw `Not supported value of ${entry.value}`;
    }
    lines.push("");
  }

  await linesSaveTo(filename, lines);
}

async function generateObject(script, settings, filename, print)
{
  const lines = [];

  lines.push("export default {");

  for (const [name, entry] of Object.entries(settings)) {
    let val;
    if (typeof entry.value === "boolean") {
      val = `"@${name}@" === "ON"`;
    }
    else if (typeof entry.value === "number") {
      val = `@${name}@`;
    }
    else if (typeof entry.value === "string") {
      val = `"@${name}@"`;
    }
    else {
      throw `Not supported value of ${entry.value}`;
    }
    lines.push(`  ${name}: ${val},`);
  }

  lines.push("};");
  lines.push("");

  await linesSaveTo(filename, lines);
}

export default async function({script, input, outputHeader, outputObject, outputScript, print})
{
  if (!input) {
    throw "Not pass the input filename to the program";
  }

  const inputUrl = url.pathToFileURL(input);
  const module = await import(inputUrl);

  const settings = module.default;
  
  if (outputScript) {
    await generateCmake(script, settings, outputScript, print);
  }
  
  if (outputHeader) {
    await generateHeader(script, settings, outputHeader, print);
  }
  
  if (outputObject) {
    await generateObject(script, settings, outputObject, print);
  }
}
