const http = require('http');
const https = require('https');

function httpRequest(url, options, callback) {
  if (url.startsWith("http://")) {
    return http.request(url, options, callback);
  }
  if (url.startsWith("https://")) {
    return https.request(url, options, callback);
  }
  return null;
};

function requestGet(url) {
  return new Promise((resolve, reject) => {
    const options = {
      method: 'GET'
    };

    const onError = (err) => {
      const message = "Encountered an error trying to make a request: " + err.message;
      console.error(message, err);
      reject(message);
    };

    const callback = (response) => {
      if (response.statusCode === 301 || response.statusCode === 302) {
        console.log(`Redirect to ${response.headers.location}`);
        const request = httpRequest(response.headers.location, options, callback);
        if (!request) {
          const message = "Url scheme not supported for " + url;
          console.error(message);
          reject(message);
          return;
        }
        request.on('error', onError);
        request.end();
        return;
      }

      if (response.statusCode !== 200) {
        response.resume();
        const message = "Did not get an OK from the server. Code: " + response.statusCode;
        console.error(message);
        reject(message);
        return;
      }

      const chunks = [];

      response.on("data", chunk => {
        chunks.push(chunk);
      });

      response.on("end", () => {
        resolve(Buffer.concat(chunks));
      });

      response.on('close', () => {
        console.log('  Close');
      });
    };

    console.log(`wget ${url}`);
    const request = httpRequest(url, options, callback);
    if (!request) {
      const message = "Url scheme not supported for " + url;
      console.error(message);
      reject(message);
      return;
    }

    request.on('error', onError);
    request.end();
  });
};

module.exports = {
  requestGet,
};
