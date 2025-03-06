import base from "./errno.h.js";

export const ARGS = {
  INPUT: {
    type: "string",
    name: "input",
  },
  OUTPUT: {
    type: "string",
    name: "output",
  },
};

export default async function(ctx, {input, output})
{
  if (!input) {
    throw "Not pass the binary dir";
  }

  if (!output) {
    throw "Not pass the output";
  }

  base({ depends: input, output });
}
