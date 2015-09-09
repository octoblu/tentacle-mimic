#!/bin/sh

[ ! -d build ] && mkdir build
cd build && \
cmake .. && \
cd tentacle-pseudopod/src/tentacle-pseudopod &&
./build.sh && \
cd ../../../ && \
make VERBOSE=1 && \
ctest -VV
