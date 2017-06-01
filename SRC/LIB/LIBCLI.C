/* libcli.c - This file is part of Project Sandford, a New Operating System.
 * Copyright 2016, 2017 Brian Millar <brianmillar@protonmail.ch>
 *
 * Project Sandford is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Project Sandford is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Project Sandford.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>

int cli_pprog(int, int);

int cli_pprog(int val, int max) {
    float j = (float)val / (float)max;
    int i, p = (int)(j * 100.0);
    printf("%3d%% |", p);
    for (i = 0; i < 10; i++)
        putchar((i < (int)(j * 10.0)) ? '=' : ' ');
    putchar('|');
    putchar(' ');
    fflush(stdout);
    for (i = 0; i < 18; i++)
        putchar('\b');
    return p;
}
