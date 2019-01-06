#!/bin/bash

rm -rf build
mkdir build
source /Users/ivankalagin/Documents/tmp/emsdk/emsdk_env.sh
emcc -o build/index.html uclpack.c -O3 -s WASM=1 -s NO_EXIT_RUNTIME=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0 --shell-file template.html --preload-file bundle/target.compressed.js -I /usr/local/include
