/* sfd_libwav.c - This file is part of Project Sandford, a New Operating System.
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
    int fsize, size, freq;
    short channels, bits;
    void *data;
} WAV;

WAV *sfd_files_wav_load(char*);

WAV *sfd_files_wav_load(char *fname) {
    FILE *file = fopen(fname, "rb");
    if (file) {
        char *s1 = malloc(5);
        char *s2 = malloc(8);
        int fsize;
        fgets(s1, 5, file);
        fread(&fsize, 1, 4, file);
        fgets(s2, 8, file);
        if (strcmp("RIFF", s1) == 0 && strcmp("WAVEfmt", s2) == 0) {
            WAV *wav;
            free(s1);
            free(s2);
            wav = malloc(sizeof(WAV));
            wav->fsize = fsize;
            fseek(file, 7, SEEK_CUR);
            fread(&(wav->channels), 1, 2, file);
            fread(&(wav->freq), 1, 4, file);
            fseek(file, 6, SEEK_CUR);
            fread(&(wav->bits), 1, 2, file);
            fseek(file, 4, SEEK_CUR);
            fread(&(wav->size), 1, 4, file);
            wav->data = malloc((unsigned long)wav->size - 44);
            fread(wav->data, 1, (size_t)wav->size - 44, file);
            fclose(file);
            return wav;
        } else {
            free(s1);
            free(s2);
            fclose(file);
            puts("sfdlib_wav: Invalid WAV Header");
        }
    }
    return NULL;
}

void sfd_files_wav_free(WAV *wav) {
    free(wav->data);
    free(wav);
}
