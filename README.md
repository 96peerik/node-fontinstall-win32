# node-fontinstall-win32
Windows-only font installation module

### Install
npm install node-fontinstall-win32

--

To build this library, following components are needed:

* Visual Studio 2015 with c++ installed

* Python 2.7

* Python environment variable PYTHON={python-dir including exe}


### Example code

```javascript

const Installer = require('node-fontinstall-win32').FontInstaller;
let installer = new Installer();
installer.install('font.ttf', (err) => {
  console.log('done', err);
});
