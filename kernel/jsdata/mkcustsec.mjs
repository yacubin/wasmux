import { generatedScriptNameComment } from "###/utils/CXX.js";

export const ARGS = {
  CPU: {
    type: "string",
    name: "cpu",
  },
  SECTION: {
    type: "string",
    name: "section",
  },
  INPUT: {
    type: "string",
    name: "input",
  },
  OUTPUT: {
    type: "string",
    name: "output",
  },
};

export default async function(ctx, {cpu, section, input, output})
{
  const lines = [];

  lines.push(generatedScriptNameComment(ctx.entryScript));
  switch (cpu) {
  case 'wasm32':
  case 'wasm64':
    lines.push(`.section  .custom_section.${section},"",@`);
    break;
  case 'i686':
    lines.push(`.section  ${section},""`);
    break;
  default:
    throw `Unknown '${cpu}' cpu name`;
  }

  const buffer = await ctx.fs.readFile(input);

  let line = '';
  for (let i = 0; i < buffer.length; i++) {
    let prefix = '0x';
    if ((i % 16) === 0) {
      line && lines.push(line);
      line = '';
    }
    else if ((i % 8) === 0) {
      prefix = " " + prefix;
    }
    prefix = (line ? ',' : '  .byte  ') + prefix;
    line += prefix + buffer[i].toString(16).toLowerCase().padStart(2, '0');
  }
  line && lines.push(line);
  lines.push('');

  await ctx.fs.linesSaveTo(output, lines);
}
