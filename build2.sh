#!/bin/bash

rm -rf build dist
mkdir dist
emcc src/main.cpp -s WASM=1 -o dist/index.html -v --embed-file /Users/ivankalagin/Documents/GitHub/web-compressor/src/text.txt --std=c++11
