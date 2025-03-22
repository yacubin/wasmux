import base from "./webcallesx.js";

export const ARGS = {
  SIDE: {
    type: "string",
    name: "side",
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

export default async function(ctx, params)
{
  base(params);
}
