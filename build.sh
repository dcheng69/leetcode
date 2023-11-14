#!/bin/bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -S . -B build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON --build build
cp ./build/compile_commands.json ./
# cd build && ctest
