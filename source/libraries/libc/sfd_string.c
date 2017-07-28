/* sfd_string.c - This file is part of Project Sandford, a New Operating System.
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

int sfd_streql(const char*, const char*);
int sfd_streql_ct(const char*, const char*);
int sfd_strlen(const char*);

char *sfd_strdup(const char*);
char *sfd_strcat(const char*, const char*);
char *sfd_strlow(const char*);
char *sfd_strtok(char*, const char*);
char *sfd_strupp(const char*);

char *sfd_strltrim(const char*);
char *sfd_strrtrim(const char*);
char *sfd_strtrim(const char*);


int sfd_streql(const char *s1, const char *s2) {
    int i, l = sfd_strlen(s1);
    if (l != sfd_strlen(s2))
        return 0;
    for (i = 0; i < l; i++)
        if (s1[i] != s2[i])
            return 0;
    return 1;
}

int sfd_streql_ct(const char *s1, const char *s2) {
    int i,
        eql = 1,
        l1  = sfd_strlen(s1),
        l2  = sfd_strlen(s2),
        l   = (l1 > l2) ? l1 : l2;
    for (i = 0; i < l; i++)
        if (s1[i] != s2[i])
            eql = 0;
    return eql;
}

int sfd_strlen(const char *s) {
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

char *sfd_strdup(const char *s) {
    int i, sl = sfd_strlen(s);
    char *s2 = malloc((unsigned long)(sl + 1));
    for (i = 0; i <= sl; i++)
        s2[i] = s[i];
    return s2;
}

char *sfd_strcat(const char *s1, const char *s2) {
    int l1 = sfd_strlen(s1);
    char *s3 = malloc((unsigned long)(l1 + sfd_strlen(s2) + 1));
    char c;
    int i = 0;
    while ((c = s1[i]) != '\0')
        s3[i++] = c;
    while ((c = s2[i - l1]) != '\0')
        s3[i++] = c;
    s3[i] = '\0';
    return s3;
}

char *sfd_strlow(const char *s) {
    int i, l = sfd_strlen(s);
    char *s1 = malloc(l + 1);
    for (i = 0; i < l; i++)
        s1[i] = sfd_tolower(s[i]);
    s1[i + 1] = '\0';
    return s1;
}

char *sfd_strtok(char *s, const char *d) {
    /* To Be Implemented */
    int i = sfd_strlen(d);
    i += 2;
    return s;
}

char *sfd_strupp(const char *s) {
    int i, l = sfd_strlen(s);
    char *s1 = malloc(l + 1);
    for (i = 0; i < l; i++)
        s1[i] = sfd_toupper(s[i]);
    s1[i + 1] = '\0';
    return s1;
}

char *sfd_strltrim(const char *s){
    int i = 0, sp = 0, l = sfd_strlen(s);
    char *buffer;
    while (i < l && s[i++] == ' ')
        sp++;
    buffer = malloc((l + 1) - sp);
    for (i = sp; i < l; i++)
        buffer[i - sp] = s[i];
    buffer[l - sp] = '\0';
    return buffer;
}

char *sfd_strrtrim(const char *s) {
    int sp = 0, l = sfd_strlen(s);
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

char *sfd_strtrim(const char *s) {
    char *b1 = sfd_strltrim(s),
         *b2 = sfd_strrtrim(b1);
    free(b1);
    return b2;
}
