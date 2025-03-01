const fs = require('fs');

const { fileExists } = require('./utils/FileSystem.js');
const { DEFAULT_PRESET } = require('./Constants.js');

module.exports = async function(wasmux)
{
  const preset = wasmux.env.preset || DEFAULT_PRESET;
  const presetPath = wasmux.getPresetPath(preset);
  if (!await fileExists(presetPath))
    throw `Preset '${preset}' is not available`;

  if (await fileExists(wasmux.userConfigPath))
    await fs.promises.rm(wasmux.userConfigPath);

  await fs.promises.copyFile(presetPath, wasmux.userConfigPath);
  console.log(`Preset '${preset}' installed successfully`);
}
