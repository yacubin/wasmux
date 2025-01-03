const fs = require('fs');

async function fileExists(path)
{
  try {
    return !!await fs.promises.stat(path);
  } catch {
    return false;
  }
}

module.exports = {
  fileExists,
};
