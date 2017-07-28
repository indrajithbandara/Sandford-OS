/*
 * sfdav.c - This file is part of Sandford AV, a simple anti-virus and
 * anti-malware tool for Sandford OS.
 * Copyright 2016, 2017 Brian Millar <brianmillar@protonmail.ch>
 *
 * Sandford AV is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Sandford AV is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Sandford AV.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../libraries/files/sfd_libfile.c"
#include "modules/filetypes/jpeg.c"
#include "modules/threats.c"

#define VERSION  "0.0.8"

static int found = 0, empty = 0;

int scan(char *name) {
    FILE *file = fopen(name, "r+b");
    if (file) {
        char *type   = sfd_files_filetype(file),
             *fsize  = sfd_files_ffilesize(file),
             *threat = NULL;
        if (strcmp(type, "Empty File              "))
            threat = detect_threat(file, type);
        else
            empty++;
        fclose(file);
        printf(" %s | %s | %s | %s \n", (!threat) ? "    [OKAY]" : "[DETECTED]", type, fsize, name);
        free(fsize);
        if (threat) {
            found++;
            printf(" |----> Details of Detected Threat: %s\n\n", threat);
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    printf("\n  Sandford AntiVirus Version %s\n--------------------------------------------------------------------------------\n            |\n", VERSION);
    if (argc <= 1) {
        puts("            | No Files to Scan\n            |\n");
        exit(0);
    } else {
        int i;
        for (i = 1; i < argc; i++)
            scan(argv[i]);
        printf("            |\n--------------------------------------------------------------------------------\n [COMPLETE] | %d THREATS DETECTED | %d EMPTY FILES\n\n", found, empty);
    }
    return 0;
}
