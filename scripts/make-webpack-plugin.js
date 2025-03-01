const path = require('path');
const wasmux = require('./Context.js');
const defaultHandler = require('./DefaultHandler.js');

const pluginName = 'MakeWebpackPlugin';

class MakeWebpackPlugin {
  _options;

  constructor(options = {})
  {
    this._options = options;
  }

  apply(compiler)
  {
    const options = {
      handler: "default",
      nodeExecutable: null,
      currentScript: null,
      scriptDir: __dirname,
      rootDir: path.dirname(__dirname),
      workDir: compiler.context,
      env: {},
      userConfig: this._options,
    };

    compiler.hooks.done.tapAsync(pluginName, async (stats) => {
      const context = wasmux(options);
      await defaultHandler(context);
    });
  }
}

module.exports = MakeWebpackPlugin;
