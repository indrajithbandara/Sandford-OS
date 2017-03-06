#!/bin/bash

echo "Welcome to Sandford OS"
echo "======================"
echo
echo "Cleaning..."

if [ -d bin ]; then
    rm -rf bin
fi

if [ -d libs ]; then
    rm -rf libs
fi

if [ -d source ]; then
    rm -rf source
fi

echo "Creating Directories..."
echo

mkdir libs
mkdir bin
mkdir bin/sys
mkdir bin/sys/tools
mkdir bin/sys/games
mkdir source
mkdir source/userland

cd source/

echo
echo "Downloading Kernel..."
git clone https://github.com/brianmillar/sfdkernel.git
mv sfdkernel kernel

echo
echo "Downloading Drivers..."
git clone https://github.com/brianmillar/sfddrvs.git
mv sfddrvs drivers

echo
echo "Downloading Userland Components..."
cd userland
git clone https://github.com/brianmillar/arigen.git
git clone https://github.com/brianmillar/sfdassm.git
git clone https://github.com/brianmillar/sfdav.git
git clone https://github.com/brianmillar/sfdbtl.git
git clone https://github.com/brianmillar/sfdcc.git
git clone https://github.com/brianmillar/sfdfs.git
git clone https://github.com/brianmillar/sfdgames.git
git clone https://github.com/brianmillar/sfdgfx.git
git clone https://github.com/brianmillar/sfdinit.git
git clone https://github.com/brianmillar/sfdlibs.git
git clone https://github.com/brianmillar/sfdpack.git
git clone https://github.com/brianmillar/sfdsh.git
git clone https://github.com/brianmillar/sfdutils.git
