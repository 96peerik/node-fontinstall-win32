var addon = require('./build/Debug/node-fontinstall-win32');
var font = 'peter.ttf';

function runSync() {
  var result = addon.installSync(font);
}

function runAsync() {
  addon.install(font, (err) => {
    console.log('done', err);
  });
}

runAsync();
