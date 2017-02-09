{
  "targets": [
    {
      "target_name": "node-fontinstall-win32",
      "sources": [
        "node-fontinstall-win32.cc",
        "fontinstaller.cc",
        "sync.cc",
        "async.cc",
        "V8Utils.cc" 
      ],
      "include_dirs": ["<!(node -e \"require('nan')\")"]
    }
  ]
}
