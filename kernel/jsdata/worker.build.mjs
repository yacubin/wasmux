import path from "node:path";
import url from "node:url";
import webpack from 'webpack';

const __filename = url.fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

export default async function(mk) {
  const isDebug = (mk.BUILD_TYPE === "Debug");

  const defineParams = {};
  for (const key in mk) {
    const name = "process.env." + key;
    defineParams[name] = JSON.stringify(mk[key]);
  }

  const params = {
    mode: isDebug ? 'development' : 'production',
    devtool: isDebug ? 'inline-source-map' : 'source-map',
    context: __dirname,
    resolve: {
      alias: {
        generated: mk.BINARY_DIR.join("generated/").toString(),
        src: path.resolve(__dirname, 'src/'),
      },
    },
    entry: "./src/WorkerThreadContext.mjs",
    output: {
      filename: 'worker.js',
      path: mk.BINARY_DIR.join("dist").toString(),
      library: {
        type: 'module',
      },
    },
    plugins: [
      new webpack.DefinePlugin(defineParams),
    ],
    experiments: {
      outputModule: true,
    },
  };

  const compiler = webpack(params);
  await new Promise((resolve, reject) => {
    compiler.run((err, stats) => {
      if (!err && stats.hasErrors()) {
        switch (stats.compilation.errors.length) {
        case 0: err = stats; break;
        case 1: err = stats.compilation.errors[0]; break;
        default: err = stats.compilation.errors; break;
        }
      }
      err ? reject(err) : resolve(stats);
    });
  });
}
