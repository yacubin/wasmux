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
  base({ input, output });
}
