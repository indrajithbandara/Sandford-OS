#!/bin/bash
echo "Compiling System Userspace Components..."
gcc -O3 -ansi -pedantic-errors -fno-builtin -Wall -Wextra -Wshadow -Werror -Wfatal-errors SRC/PROG/SYS/SHELL.C -o PROG/SYS/SHELL
