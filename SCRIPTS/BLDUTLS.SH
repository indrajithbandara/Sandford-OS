#!/bin/bash
echo "Compiling Utilities..."
gcc -O3 -ansi -pedantic-errors -fno-builtin -Wall -Wextra -Wshadow -Werror -Wfatal-errors SRC/PROG/UTIL/ECHO.C -o PROG/UTIL/ECHO
gcc -O3 -ansi -pedantic-errors -fno-builtin -Wall -Wextra -Wshadow -Werror -Wfatal-errors SRC/PROG/UTIL/CAT.C -o PROG/UTIL/CAT
gcc -O3 -ansi -pedantic-errors -fno-builtin -Wall -Wextra -Wshadow -Werror -Wfatal-errors SRC/PROG/UTIL/YES.C -o PROG/UTIL/YES
gcc -O3 -ansi -pedantic-errors -fno-builtin -Wall -Wextra -Wshadow -Werror -Wfatal-errors SRC/PROG/UTIL/TRUE.C -o PROG/UTIL/TRUE
gcc -O3 -ansi -pedantic-errors -fno-builtin -Wall -Wextra -Wshadow -Werror -Wfatal-errors SRC/PROG/UTIL/FALSE.C -o PROG/UTIL/FALSE
