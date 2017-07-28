/* sfd_libbmp.c - This file is part of Project Sandford, a New Operating System.
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
    int width, height;
    short depth;
    unsigned char **pix_data;
} BMP;

BMP *sfd_import_bmp(char *fname) {
    FILE *file = fopen(fname, "rb");
    if (file) {
        BMP *bmp = malloc(sizeof(BMP));
        char *s = malloc(3);
        fgets(s, 3, file);
        if (strcmp("BM", s) == 0) {
            int offset, i;
            free(s);
            fseek(file, 8, SEEK_CUR);
            fread(&offset, 4, 1, file);
            fseek(file, 4, SEEK_CUR);
            fread(&(bmp->width), 4, 1, file);
            fread(&(bmp->height), 4, 1, file);
            fseek(file, 2, SEEK_CUR);
            fread(&(bmp->depth), 2, 1, file);
            fread(&i, 4, 1, file);
            if (bmp->depth == 24 && i == 0) {
                int row_size;
                fseek(file, offset, SEEK_SET);
                bmp->pix_data = malloc(bmp->height * sizeof(unsigned char*));
                row_size = (((bmp->depth * bmp->width) + 31) / 32) * 4;
                for (i = bmp->height - 1; i >= 0; i--) {
                    unsigned char *row = malloc(bmp->width * 3);
                    fread(row, 1, bmp->width * 3, file);
                    fseek(file, row_size - (bmp->width * 3), SEEK_CUR);
                    bmp->pix_data[i] = row;
                }
                fclose(file);
                return bmp;
            } else
                fprintf(stderr, "sfdlib_bmp: Not 24-bit Uncompressed BMP\n");
        } else
            fprintf(stderr, "sfdlib_bmp: Invalid BMP Header\n");
        free(s);
        fclose(file);
    }
    return NULL;
}

void sfd_free_bmp(BMP *bmp) {
    int i;
    for (i = 0; i < bmp->height; i++)
        free(bmp->pix_data[i]);
    free(bmp->pix_data);
    free(bmp);
}
