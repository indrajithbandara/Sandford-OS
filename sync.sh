#!/bin/bash

rm -rf ./sfdassm
rm -rf ./sfdcc
rm -rf ./sfdgames
rm -rf ./sfdlibc
rm -rf ./sfdutils

cp -r ../sfdassm  ./
cp -r ../sfdcc    ./
cp -r ../sfdgames ./
cp -r ../sfdlibc  ./
cp -r ../sfdutils ./

rm -rf ./sfdassm/.git
rm -rf ./sfdcc/.git
rm -rf ./sfdgames/.git
rm -rf ./sfdlibc/.git
rm -rf ./sfdutils/.git
