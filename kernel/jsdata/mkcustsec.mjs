import base from "./mkcustsec.js";

export const ARGS = {
  CPU:     { type: "string", name: "cpu"     },
  SECTION: { type: "string", name: "section" },
  INPUT:   { type: "string", name: "input"   },
  OUTPUT:  { type: "string", name: "output"  },
};

export default async function(ctx, params)
{
  base(params);
}
