const path = require("node:path");
const webpack = require("webpack");

module.exports = async function({ input, buildType, buildDirectory, settings, output })
{
  const isDebug = (buildType === 'Debug');

  const defineParams = {};
  if (settings) {
    for (const key of Object.keys(settings)) {
      const name = "process.env." + key;
      defineParams[name] = JSON.stringify(settings[key]);
    }
  }

  const params = {
    mode: isDebug ? 'development' : 'production',
    devtool: isDebug ? 'inline-source-map' : 'source-map',
    context: __dirname,
    resolve: {
      alias: {
        generated: path.resolve(buildDirectory, 'generated/'),
        src: path.resolve(__dirname, 'src/'),
      },
    },
    entry: "./src/WorkerThreadContext.mjs",
    output: {
      filename: 'worker.js',
      path: path.resolve(buildDirectory, 'dist'),
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
