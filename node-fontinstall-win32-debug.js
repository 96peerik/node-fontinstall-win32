var addon = require('./build/Debug/node-fontinstall-win32');
var path = require('path');

var font = 'c:/hego/papyrus.ttf';
font = path.join(font);

function runSync() {
  var result = addon.installSync(font);
}

function runAsync() {
  addon.install(font, (err) => {
    console.log('done', err);
  });
}

runAsync();
