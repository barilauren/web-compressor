#!/bin/bash

rm -rf build
mkdir build
source /Users/ivankalagin/Documents/tmp/emsdk/emsdk_env.sh
emcc decompressor.cpp minilzo.c -o build/index.html -O3 -s WASM=1 -s EXPORTED_FUNCTIONS='["_main"]' --shell-file template.html --preload-file bundle/target.compressed.js
