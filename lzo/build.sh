#!/bin/bash

rm -rf build
mkdir build
source /Users/ivankalagin/Documents/tmp/emsdk/emsdk_env.sh
emcc -o build/index.html testmini.c minilzo.c -O3 -s WASM=1 -s NO_EXIT_RUNTIME=1 --shell-file template.html
