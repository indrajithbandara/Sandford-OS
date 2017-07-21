/* sfd_libfile.c - This file is part of Project Sandford, a New Operating System.
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

int sfd_files_filesize(FILE*);

char *sfd_files_filetype(FILE*);
char *sfd_files_ffilesize(FILE*);

static char *types[] = {
    "Unknown File            ",
    "Empty File              ",
    "PE Windows Executable   ",
    "dosZMXP Executable      ",
    "ZIP Archive             ",
    "PostScript File         ",
    "JPEG Image File         ",
    "JAVA Bytecode           ",
    "JAVA Bytecode (Pack200) "
};

char *sfd_files_filetype(FILE *f) {
    fseek(f, 0, SEEK_END);
    if (ftell(f) == 0)
        return types[1];
    if (ftell(f) > 8) {
        unsigned char magic[4];
        rewind(f);
        magic[0] = fgetc(f);
        magic[1] = fgetc(f);
        magic[2] = fgetc(f);
        magic[3] = fgetc(f);
        if (magic[0] == 'M' && magic[1] == 'Z') {
            return types[2];
        } else if (magic[0] == 'Z' && magic[1] == 'M') {
            return types[3];
        } else if (magic[0] == 'P' && magic[1] == 'K') {
            return types[4];
        } else if (magic[0] == '%' && magic[1] == '!') {
            return types[5];
        } else if (magic[0] == 255 && magic[1] == 216) {
            return types[6];
        } else if (magic[0] == 202 && magic[1] == 254) {
            if (magic[2] == 186 && magic[3] == 190) /* CAFEBABE */
                return types[7];
            else if (magic[2] == 208 && magic[3] == 13) /* CAFED00D */
                return types[8];
        }
    }
    return types[0];
}

int sfd_files_filesize(FILE *file) {
    int size, pos = ftell(file);
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, pos);
    return size;
}

char *sfd_files_ffilesize(FILE *file) {
    double size = (double)sfd_files_filesize(file);
    char *s = malloc(13), *u;
    fseek(file, 0, SEEK_END);
    if (size >= 1073741824) {
        u = "GB";
        size /= 1073741824.0;
    } else if (size >= 1048576) {
        u = "MB";
        size /= 1048576.0;
    } else if (size >= 1024) {
        u = "KB";
        size /= 1024.0;
    } else
        u = "B ";
    sprintf(s, "%8.2f %s", size, u);
    return s;
}
