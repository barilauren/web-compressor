var Module = {
  'preRun' : function() {
    console.log('prerun');
    // TODO: check is bundle exist
    // FS.createDataFile('/', 'bundle.min.js', 'Hello webassembly', true, true, true);
  },
  'noInitialRun': true,
};