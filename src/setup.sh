#! /bin/bash

BUILD_DIR="build"
GTEST_DIR="build/libs"
mkdir -p $GTEST_DIR

if [ "$(ls -A $GTEST_DIR)" ]; then
    echo "Google Test already installed!"
else
    cd $GTEST_DIR && wget https://github.com/google/googletest/archive/refs/tags/release-1.10.0.tar.gz && tar -xf release-1.10.0.tar.gz && mv googletest* googletest && rm -r *.tar.gz
fi