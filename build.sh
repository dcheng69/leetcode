#!/bin/bash

if [ $# -eq 0 ]; then
  echo "Usage: $0 <folder>"
  exit 1
fi

folder=$1

cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -S . -B "$folder"
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON --build "$folder"
cp "$folder/compile_commands.json" .

# Uncomment the following line if you want to run tests using ctest
# cd "$folder/build" && ctest
