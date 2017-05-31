/* compile.c - This file is part of sfdcc, the C Compiler of the Sandford
 * Operating System.
 * Copyright 2016, 2017 Brian Millar <brianmillar@protonmail.ch>
 *
 * sfdcc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * sfdcc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with sfdcc.  If not, see <http://www.gnu.org/licenses/>.
 */

FILE* sfd_compile(FILE*, char*);

FILE* sfd_compile(FILE *in, char *name) {
    FILE *out;
    remove(name);
    out = fopen(name, "w");
    fclose(in);
    return out;
}
