#!/bin/bash
echo "Compiling Games..."
gcc -O3 -ansi -pedantic-errors -fno-builtin -Wall -Wextra -Wshadow -Werror -Wfatal-errors ./src/progs/games/tictactoe.c -o ./progs/games/tictactoe
