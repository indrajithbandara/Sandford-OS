/* libcode.c - This file is part of Project Sandford, a New Operating System.
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

int fix_line_endings(char*);
int fix_indentation(char*);
int remove_trailing_spaces(char*);
int fix_code_style(char*);

int fix_line_endings(char *fname) {
    FILE *f = fopen(fname, "rb");
    if (f != NULL) {
        char c, *buffer;
        int i = 0, size = sfd_filesize(f);
        buffer = malloc(size + 1);
        while ((c = fgetc(f)) != EOF)
            if (c != '\r')
                buffer[i++] = c;
        buffer[i] = '\0';
        fclose(f);
        remove(fname);
        if ((f = fopen(fname, "w+")) != NULL) {
            fprintf(f, "%s", buffer);
            free(buffer);
            fclose(f);
            return 0;
        }
    }
    return -1;
}

int fix_indentation(char *fname) {
    FILE *f = fopen(fname, "rb");
    if (f != NULL) {
        char c, *buffer;
        int i = 0, tabs = 0, size = sfd_filesize(f);
        while ((c = fgetc(f)) != EOF)
            if (c == '\t')
                tabs++;
        buffer = malloc(size + (tabs * 4) + 1);
        rewind(f);
        while ((c = fgetc(f)) != EOF) {
            if (c == '\t') {
                buffer[i++] = ' ';
                buffer[i++] = ' ';
                buffer[i++] = ' ';
                buffer[i++] = ' ';
            } else
                buffer[i++] = c;
        }
        buffer[i] = '\0';
        fclose(f);
        remove(fname);
        if ((f = fopen(fname, "w+")) != NULL) {
            fprintf(f, "%s", buffer);
            free(buffer);
            fclose(f);
            return 0;
        }
    }
    return -1;
}

int remove_trailing_spaces(char *fname) {
    /* TODO */
    printf("%s", fname);
    return 0;
}

int fix_code_style(char *fname) {
    return !((sfd_fix_line_endings(fname)       == 0) &&
             (sfd_fix_indentation(fname)        == 0)/* &&
             (sfd_remove_trailing_spaces(fname) == 0)*/);
}
