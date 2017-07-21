/* sfd_libid3.c - This file is part of Project Sandford, a New Operating System.
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

typedef struct {
    short year, track;
    char *title, *artist, *album, *comment, *genre;
} ID3V1;

ID3V1 *extract_id3v1(char*);

ID3V1 *extract_id3v1(char *fname) {
    FILE *file = fopen(fname, "rb");
    if (file) {
        char *s = malloc(4);
        fseek(f, -128, SEEK_END);
        fgets(s, 4, f);
        if (strcmp("TAG", s) == 0) {
            free(s);
            ID3V1 *id3v1 = malloc(sizeof(ID3V1));
            fclose(f);
            return id3v1;
        } else {
            free(s);
            fclose(f);
        }
    }
    return NULL;
}

void free_id3v1(ID3V1 *id3v1) {
    free(id3v1);
}
