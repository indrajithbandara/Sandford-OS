/* string.c - This file is part of Project Sandford, a New Operating System.
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

int streql(const char*, const char*);
int streql_ct(const char*, const char*);
int strlen(const char*);

char *strdup(const char*);
char *strcat(const char*, const char*);
char *strlow(const char*);
char *strtok(char*, const char*);
char *strupp(const char*);

char *strltrim(const char*);
char *strrtrim(const char*);
char *strtrim(const char*);


int streql(const char *s1, const char *s2) {
    int i, l = strlen(s1);
    if (l != strlen(s2))
        return 0;
    for (i = 0; i < l; i++)
        if (s1[i] != s2[i])
            return 0;
    return 1;
}

int streql_ct(const char *s1, const char *s2) {
    int i,
        eql = 1,
        l1  = strlen(s1),
        l2  = strlen(s2),
        l   = (l1 > l2) ? l1 : l2;
    for (i = 0; i < l; i++)
        if (s1[i] != s2[i])
            eql = 0;
    return eql;
}

int strlen(const char *s) {
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

char *strdup(const char *s) {
    int i, sl = strlen(s);
    char *s2 = malloc((unsigned long)(sl + 1));
    for (i = 0; i <= sl; i++)
        s2[i] = s[i];
    return s2;
}

char *strcat(const char *s1, const char *s2) {
    int l1 = strlen(s1);
    char *s3 = malloc((unsigned long)(l1 + strlen(s2) + 1));
    char c;
    int i = 0;
    while ((c = s1[i]) != '\0')
        s3[i++] = c;
    while ((c = s2[i - l1]) != '\0')
        s3[i++] = c;
    s3[i] = '\0';
    return s3;
}

char *strlow(const char *s) {
    int i, l = strlen(s);
    char *s1 = malloc(l + 1);
    for (i = 0; i < l; i++)
        s1[i] = tolower(s[i]);
    s1[i + 1] = '\0';
    return s1;
}

char *strtok(char *s, const char *d) {
    /* To Be Implemented */
    int i = strlen(d);
    i += 2;
    return s;
}

char *strupp(const char *s) {
    int i, l = strlen(s);
    char *s1 = malloc(l + 1);
    for (i = 0; i < l; i++)
        s1[i] = toupper(s[i]);
    s1[i + 1] = '\0';
    return s1;
}

char *strltrim(const char *s){
    int i = 0, sp = 0, l = strlen(s);
    char *buffer;
    while (i < l && s[i++] == ' ')
        sp++;
    buffer = malloc((l + 1) - sp);
    for (i = sp; i < l; i++)
        buffer[i - sp] = s[i];
    buffer[l - sp] = '\0';
    return buffer;
}

char *strrtrim(const char *s) {
    int sp = 0, l = strlen(s);
    int i = l - 1;
    char *buffer;
    while (i >= 0 && s[i--] == ' ')
        sp++;
    buffer = malloc((l + 1) - sp);
    for (i = 0; i < l - sp; i++)
        buffer[i] = s[i];
    buffer[l - sp] = '\0';
    return buffer;
}

char *strtrim(const char *s) {
    char *b1 = strltrim(s),
         *b2 = strrtrim(b1);
    free(b1);
    return b2;
}
