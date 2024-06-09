#!/bin/bash
# cmake -S . -DCMAKE_TOOLCHAIN_FILE=./toolchains/Toolchain-x86_64-w64-mingw32.cmake -B out/build_windows
cmake -S . -B out/build_linux
