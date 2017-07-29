#!/bin/bash

if [ ! -e './programs' ]
then
    mkdir "programs"
fi

if [ ! -e './programs/utilities' ]
then
    mkdir "./programs/utilities"
fi

if [ ! -e './documentation' ]
then
    mkdir "./documentation"
fi

gcc buildtest.c -o buildtest
gcc ./source/programs/utilities/sfd_cat.c -o ./programs/utilities/sfd_cat
gcc ./source/programs/utilities/sfd_echo.c -o ./programs/utilities/sfd_echo
gcc ./source/programs/utilities/sfd_false.c -o ./programs/utilities/sfd_false
gcc ./source/programs/utilities/sfd_id3view.c -o ./programs/utilities/sfd_id3view
gcc ./source/programs/utilities/sfd_true.c -o ./programs/utilities/sfd_true
gcc ./source/programs/utilities/sfd_yes.c -o ./programs/utilities/sfd_yes

pdflatex -output-directory="./documentation" ./source/documentation/sfd_manual.tex
rm ./documentation/sfd_manual.aux
rm ./documentation/sfd_manual.log
rm ./documentation/sfd_manual.toc
