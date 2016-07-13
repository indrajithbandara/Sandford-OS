#!/bin/bash

rm -rf ./sfdassm
rm -rf ./sfdcc
rm -rf ./sfddrivers
rm -rf ./sfdgames
rm -rf ./sfdlibc
rm -rf ./sfdshell
rm -rf ./sfdutils

cp -r ../sfdassm  ./
cp -r ../sfdcc    ./
cp -r ../sfddrivers ./
cp -r ../sfdgames ./
cp -r ../sfdlibc  ./
cp -r ../sfdshell ./
cp -r ../sfdutils ./

rm -rf ./sfdassm/.git
rm -rf ./sfdcc/.git
rm -rf ./sfddrivers/.git
rm -rf ./sfdgames/.git
rm -rf ./sfdlibc/.git
rm -rf ./sfdshell/.git
rm -rf ./sfdutils/.git
