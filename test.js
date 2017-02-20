const path = require('path');
const fi = require(path.join(__dirname, './node-fontinstall-win32.js'));

const font = 'c:\\hego\\ravie.ttf'
fi.install(font, (err) => {
    console.log('done', err);
});
