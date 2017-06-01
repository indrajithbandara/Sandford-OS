#!/bin/bash
echo "Compiling Utilities..."
gcc -O3 -ansi -pedantic-errors -fno-builtin -Wall -Wextra -Wshadow -Werror -Wfatal-errors ./src/progs/utils/echo.c -o ./progs/utils/echo
gcc -O3 -ansi -pedantic-errors -fno-builtin -Wall -Wextra -Wshadow -Werror -Wfatal-errors ./src/progs/utils/cat.c -o ./progs/utils/cat
gcc -O3 -ansi -pedantic-errors -fno-builtin -Wall -Wextra -Wshadow -Werror -Wfatal-errors ./src/progs/utils/yes.c -o ./progs/utils/yes
gcc -O3 -ansi -pedantic-errors -fno-builtin -Wall -Wextra -Wshadow -Werror -Wfatal-errors ./src/progs/utils/true.c -o ./progs/utils/true
gcc -O3 -ansi -pedantic-errors -fno-builtin -Wall -Wextra -Wshadow -Werror -Wfatal-errors ./src/progs/utils/false.c -o ./progs/utils/false
