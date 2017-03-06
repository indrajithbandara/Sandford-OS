#!/bin/bash
echo
echo "Welcome to Sandford OS"
echo "======================"
echo
echo "Cleaning..."
echo
if [ -d bin ]; then
    rm -rf bin
fi
echo
if [ -d libs ]; then
    rm -rf libs
fi
echo
if [ -d source ]; then
    rm -rf source
fi
echo
echo "Creating Directories..."
echo
echo
mkdir libs
mkdir bin
mkdir bin/sys
mkdir bin/sys/tools
mkdir bin/sys/games
mkdir source
mkdir source/userland
echo
cd source/
echo
echo
echo "Downloading Kernel..."
git clone https://github.com/brianmillar/sfdkernel.git
mv sfdkernel kernel
echo
echo
echo "Downloading Drivers..."
git clone https://github.com/brianmillar/sfddrvs.git
mv sfddrvs drivers
echo
echo
echo "Downloading Userland Components..."
cd userland
git clone https://github.com/brianmillar/arigen.git
echo
git clone https://github.com/brianmillar/sfdassm.git
echo
git clone https://github.com/brianmillar/sfdav.git
echo
git clone https://github.com/brianmillar/sfdbtl.git
echo
git clone https://github.com/brianmillar/sfdcc.git
echo
git clone https://github.com/brianmillar/sfdfs.git
echo
git clone https://github.com/brianmillar/sfdgames.git
echo
git clone https://github.com/brianmillar/sfdgfx.git
echo
git clone https://github.com/brianmillar/sfdinit.git
echo
git clone https://github.com/brianmillar/sfdlibs.git
echo
git clone https://github.com/brianmillar/sfdpack.git
echo
git clone https://github.com/brianmillar/sfdsh.git
echo
git clone https://github.com/brianmillar/sfdutils.git
echo
echo
echo "Cleaning Unneeded Git Files..."

cd ../kernel
if [ -d .git ]; then
    rm -rf .git
fi
if [ -e .gitignore ]; then
    rm .gitignore
fi

cd ../drivers
if [ -d .git ]; then
    rm -rf .git
fi
if [ -e .gitignore ]; then
    rm .gitignore
fi

cd ../userland

cd arigen

if [ -d .git ]; then
    rm -rf .git
fi
if [ -e .gitignore ]; then
    rm .gitignore
fi

cd ../sfdassm

if [ -d .git ]; then
    rm -rf .git
fi
if [ -e .gitignore ]; then
    rm .gitignore
fi

cd ../sfdav

if [ -d .git ]; then
    rm -rf .git
fi
if [ -e .gitignore ]; then
    rm .gitignore
fi

cd ../sfdbtl

if [ -d .git ]; then
    rm -rf .git
fi
if [ -e .gitignore ]; then
    rm .gitignore
fi

cd ../sfdcc

if [ -d .git ]; then
    rm -rf .git
fi
if [ -e .gitignore ]; then
    rm .gitignore
fi

cd ../sfdfs

if [ -d .git ]; then
    rm -rf .git
fi
if [ -e .gitignore ]; then
    rm .gitignore
fi

cd ../sfdgames

if [ -d .git ]; then
    rm -rf .git
fi
if [ -e .gitignore ]; then
    rm .gitignore
fi

cd ../sfdgfx

if [ -d .git ]; then
    rm -rf .git
fi
if [ -e .gitignore ]; then
    rm .gitignore
fi

cd ../sfdinit

if [ -d .git ]; then
    rm -rf .git
fi
if [ -e .gitignore ]; then
    rm .gitignore
fi

cd ../sfdlibs

if [ -d .git ]; then
    rm -rf .git
fi
if [ -e .gitignore ]; then
    rm .gitignore
fi

cd ../sfdpack

if [ -d .git ]; then
    rm -rf .git
fi
if [ -e .gitignore ]; then
    rm .gitignore
fi

cd ../sfdsh

if [ -d .git ]; then
    rm -rf .git
fi
if [ -e .gitignore ]; then
    rm .gitignore
fi

cd ../sfdutils

if [ -d .git ]; then
    rm -rf .git
fi
if [ -e .gitignore ]; then
    rm .gitignore
fi

