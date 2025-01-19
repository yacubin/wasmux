const fs = require('fs');

async function loadLinuxVersion(filepath)
{
  const params = {};
  const content = await fs.promises.readFile(filepath, 'utf8');
  const names = {
    VERSION: false,
    PATCHLEVEL: false,
    SUBLEVEL: false,
    EXTRAVERSION: true,
  };

  for (const line of content.split('\n')) {
    for (const [name, opt] of Object.entries(names)) {
      const pattern = new RegExp(`${name} *= *(.*) *`);
      let match = line.match(pattern);
      if (match) {
        let value = match[1];
        if (opt && !value)
          value = null;
        else if (/^\d+$/.test(value))
          value = Number.parseInt(value);
        else
           throw `The ${name} does not contain the version`;
        params[name] = value;
        delete names[name];
        break;
      }
    }
    if (Object.keys(names).length == 0) {
      break;
    }
  }

  return params;
}

module.exports = {
  loadLinuxVersion,
};
