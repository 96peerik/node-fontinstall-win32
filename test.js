const path = require('path');
console.log(path.join(__dirname, './node-dirwatch-win32-debug.js'));
const DW = require(path.join(__dirname, './node-dirwatch-win32-debug.js')).DirectoryWatcher;
const events = require('events');
const fs = require('fs');


setTimeout(() => {
setInterval(() => {
   writefile();
}, 100);
}, 1000);

setInterval(() => {
   writefile2();
}, 2000);


const watcher = new DW(path.join(__dirname, 'tmp'));
watcher.on('change', function(file) {
  console.log('changed 1');
});


const watcher2 = new DW(path.join(__dirname, 'tmp2'));
watcher2.on('change', function(file) {
  console.log('changed 2');
});

watcher.on('error', err => console.log(err));
watcher2.on('error', err => console.log(err));

function writefile() {
  fs.writeFile(path.join(__dirname, 'tmp', 'afile.txt'), new Date().toString(), function(err) {
    console.log('written');
  });
}

function writefile2() {
  fs.writeFile(path.join(__dirname, 'tmp2', 'afile.txt'), new Date().toString(), function(err) {
    console.log('written 2');
  });
}

var profiler = require('gc-profiler');
profiler.on('gc', function (info) {
  console.log(info);
});
