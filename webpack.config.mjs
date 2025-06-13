/*
 * MIT License
 *
 * Copyright (c) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 * Permission is granted to use, copy, modify, and distribute this software
 * under the MIT License. See LICENSE file for details.
 */

import path from "node:path";
import fs from "node:fs";
import url from "node:url";

import webpack from "webpack";

const __filename = url.fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

async function readJSON(filename) {
  const content = await fs.promises.readFile(filename, "utf8");
  return JSON.parse(content);
}

function objectValuesStringify(o) {
  const result = {};
  for (const [key, val] of Object.entries(o))
    result[key] = JSON.stringify(val);
  return result;
}

export default async (env, argv) => {
  const isDevelopment = (argv.mode === "development");
  const tsconfig = isDevelopment ? "tsconfig.dev.json" : "tsconfig.json";

  const pkg = await readJSON(path.join(__dirname, "package.json"));

  const PROJECT_NAME = pkg.name || "";
  const PROJECT_VERSION = pkg.version || "";
  const PROJECT_DESCRIPTION = pkg.description || "";
  const PROJECT_HOMEPAGE_URL = pkg.homepage || "";

  const globalVariables = objectValuesStringify({
    PROJECT_NAME,
    PROJECT_VERSION,
    PROJECT_DESCRIPTION,
    PROJECT_HOMEPAGE_URL,
  });

  const filenameUrl = path.posix.join(path.dirname(import.meta.url), pkg.exports["."]);
  const filename = url.fileURLToPath(filenameUrl);

  return {
    mode: isDevelopment ? "development" : "production",
    devtool: isDevelopment ? "inline-source-map" : undefined,
    entry: "./loader/index.ts",
    resolve: {
      extensions: [ ".ts", ".tsx", ".mjs", ".js" ],
      alias: {
        "@": path.resolve(__dirname, "src"),
      },
    },
    module: {
      rules: [
        {
          test: /\.tsx?$/,
          exclude: /node_modules/,
          use: [
            {
              loader: "ts-loader",
              options: {
                configFile: path.join(__dirname, tsconfig),
              }
            }
          ],
        },
      ],
    },
    output: {
      path: path.dirname(filename),
      filename: path.basename(filename),
      library: {
        name: PROJECT_NAME,
        type: "commonjs2",
      },
      libraryTarget: "umd",
      libraryExport: "default",
    },
    externals: {},
    plugins: [
      new webpack.DefinePlugin(globalVariables),
    ],
  };
}
