const fs = require('fs');
const path = require('path');

const { generatedScriptNameComment } = require('../utils/CXXHelper.js');

module.exports = async function({output})
{
  const now = new Date();
  const year = now.getUTCFullYear();
  const date = now.getUTCDate();
  const day = now.getUTCDay();
  const month = now.getUTCMonth();
  const hours = now.getUTCHours();
  const minutes = now.getUTCMinutes();
  const seconds = now.getUTCSeconds();

  const buildNumber = 1;
  const dayNames = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"];
  const monthNames = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"];

  const UTS_VERSION = `#${buildNumber} ${dayNames[day]} ${monthNames[month]} ${date} ${hours}:${minutes}:${seconds} UTC ${year}`;

  let lines = [
    generatedScriptNameComment(process.argv[1]),
    `#define UTS_VERSION "${UTS_VERSION}"`,
    ``,
  ];

  await fs.promises.mkdir(path.dirname(output), { recursive: true });
  await fs.promises.writeFile(output, lines.join('\n'), { encoding: "utf8" });
}
