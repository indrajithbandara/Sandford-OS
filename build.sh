#!/bin/bash
echo
echo "Welcome to Sandford OS"
echo "======================"
echo
echo "Cleaning..."
echo "==========="
echo
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
echo "======================="
mkdir libs
mkdir bin
mkdir bin/sys
mkdir bin/sys/tools
mkdir bin/sys/games
mkdir source
mkdir source/userland
echo
cd source/
echo "Downloading Kernel..."
echo "====================="
git clone https://github.com/brianmillar/sfdkernel.git
mv sfdkernel kernel
echo
echo "Downloading Drivers..."
echo "======================"
git clone https://github.com/brianmillar/sfddrvs.git
mv sfddrvs drivers
echo
echo "Downloading Userland Components..."
echo "=================================="
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
echo "=========================="
echo "***ALL FILES DOWNLOADED***"
echo
echo -n "Cleaning Unneeded Git Files... "

function git_cleanup {
    if [ -d .git ]; then
        rm -rf .git
    fi
    if [ -e .gitignore ]; then
        rm .gitignore
    fi
}

cd ../kernel
git_cleanup
cd ../drivers
git_cleanup
cd ../userland
cd arigen
git_cleanup
cd ../sfdassm
git_cleanup
cd ../sfdav
git_cleanup
cd ../sfdbtl
git_cleanup
cd ../sfdcc
git_cleanup
cd ../sfdfs
git_cleanup
cd ../sfdgames
git_cleanup
cd ../sfdgfx
git_cleanup
cd ../sfdinit
git_cleanup
cd ../sfdlibs
git_cleanup
cd ../sfdpack
git_cleanup
cd ../sfdsh
git_cleanup
cd ../sfdutils
git_cleanup

echo "Done."
echo
echo
echo "BEGINNING COMPILATION PHASE"
echo "==========================="
echo
