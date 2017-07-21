#!/bin/bash

cp -r ../sfdlibc ./

rm ./sfdlibc/build.sh
rm ./sfdlibc/README.md
rm ./sfdlibc/COPYING
rm ./sfdlibc/test_suite.c
rm ./sfdlibc/test_suite
rm -rf ./sfdlibc/.git

cp ../sfdlibs/sfdlib_code.c ./sfdlibs/sfdlib_code.c
cp ../sfdlibs/sfdlib_file.c ./sfdlibs/sfdlib_file.c
