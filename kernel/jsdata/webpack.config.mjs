import path from "node:path";
import url from "node:url";
import webpack from 'webpack';

const __filename = url.fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

export default async (env, argv) => {
  const config = {
    mode: 'production',
    devtool: 'source-map',
    buildDirectory: env.buildDirectory || __dirname,
  };

  if (env.buildType === 'Debug') {
    config.mode = 'development';
    config.devtool = 'inline-source-map';
  }

  const envDefineMap = {};
  if (env.settings) {
    const module = await import(url.pathToFileURL(env.settings));
    const settings = module.default;
    for (const key of Object.keys(settings)) {
      const name = "process.env." + key;
      envDefineMap[name] = JSON.stringify(settings[key].value);
    }
  }

  const baseConfig = {
    context: __dirname,
    mode: config.mode,
    devtool: config.devtool,
    resolve: {
      alias: {
        generated: path.resolve(config.buildDirectory, 'generated/'),
        src: path.resolve(__dirname, 'src/'),
      },
    },
  };

  const loaderConfig = {
    ...baseConfig,
    entry: "./src/MainThreadContext.mjs",
    output: {
      filename: 'loader.js',
      path: path.resolve(config.buildDirectory, 'dist'),
      library: {
        type: 'module',
      },
    },
    plugins: [
      new webpack.DefinePlugin(envDefineMap),
    ],
    experiments: {
      outputModule: true,
    },
  };

  const workerConfig = {
    ...baseConfig,
    entry: "./src/WorkerThreadContext.mjs",
    output: {
      filename: 'worker.js',
      path: path.resolve(config.buildDirectory, 'dist'),
    },
    plugins: [
      new webpack.DefinePlugin(envDefineMap),
    ],
  };

  return [ loaderConfig, workerConfig ];
};
