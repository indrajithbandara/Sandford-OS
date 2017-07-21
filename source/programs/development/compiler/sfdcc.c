/* sfdcc.c - This file is part of sfdcc, the C Compiler of the Sandford
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sfdlibc/sfdlibc.c"
#include "sfdlibs/sfdlib_file.c"
#include "sfdlibs/sfdlib_code.c"
#include "modules/preproc.c"
#include "modules/compile.c"
#include "modules/assemble.c"

int main(int argc, char *argv[]) {
    if (argc < 2)
        fputs("No Input File(s)\n", stderr);
    else {
        int i;
        for (i = 1; i < argc; i++) {
            FILE *in;
            int l = sfd_strlen(argv[i]);
            char *out = malloc(l + 1);
            strcpy(out, argv[i]); /* Switch to sfd_strcpy Once Implemented */
            if (l < 2 || out[l - 2] != '.' || (out[l - 1] != 'c' && out[l - 1] != 'C'))
                fprintf(stderr, "File \"%s\" is Not a C Source File\n", argv[i]);
            else {
                printf("Fixing Formatting and Style in %s\n", argv[i]);
                if (sfd_fix_code_style(argv[i]) == 0) {
                    int result = -1;
                    in = fopen(argv[i], "r");
                    out[l - 1] = 'i';
                    in = sfd_preproc(in, out);
                    out[l - 1] = 's';
                    in = sfd_compile(in, out);
                    out[l - 2] = '\0';
                    result = sfd_assemble(in, out);
                    printf("%s File \"%s\"\n", (result == 0) ? "Successfully Compiled" : "Failed to Compile", argv[i]);
                    free(out);
                } else
                    fprintf(stderr, "File \"%s\" Could Not be Opened or Does Not Exist\n", argv[i]);
            }
        }
    }
    return -1;
}
