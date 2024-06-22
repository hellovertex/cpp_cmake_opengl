#!/bin/bash
# on windows: cmake --build out/build_windows --config Debug
#  the above should work on Linux too (replacing build_windows with build_linux)
cd out/build_linux && make && cd ../..
