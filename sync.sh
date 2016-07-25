#!/bin/bash

rm -rf ./sfdassm
rm -rf ./sfdcc
rm -rf ./sfddrvs
rm -rf ./sfdgames
rm -rf ./sfdlibc
rm -rf ./sfdsh
rm -rf ./sfdutls

cp -r ../sfdassm  ./
cp -r ../sfdcc    ./
cp -r ../sfddrvs  ./
cp -r ../sfdgames ./
cp -r ../sfdlibc  ./
cp -r ../sfdsh    ./
cp -r ../sfdutls  ./

rm -rf ./sfdassm/.git
rm -rf ./sfdcc/.git
rm -rf ./sfddrvs/.git
rm -rf ./sfdgames/.git
rm -rf ./sfdlibc/.git
rm -rf ./sfdsh/.git
rm -rf ./sfdutls/.git
