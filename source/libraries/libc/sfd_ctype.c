/* sfd_ctype.c - This file is part of Project Sandford, a New Operating System.
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

int sfd_isalnum(const char);
int sfd_isalpha(const char);
int sfd_isdigit(const char);
int sfd_islower(const char);
int sfd_isprint(const char);
int sfd_ispunct(const char);
int sfd_isspace(const char);
int sfd_isupper(const char);

char sfd_tolower(const char);
char sfd_toupper(const char);


int sfd_isalnum(const char c) {
    return (isalpha(c) || isdigit(c));
}

int sfd_isalpha(const char c) {
    return (islower(c) || isupper(c));
}

int sfd_isdigit(const char c) {
    return (c >= '0' && c <= '9');
}

int sfd_islower(const char c) {
    return (c >= 'a' && c <= 'z');
}

int sfd_isprint(const char c) {
    return (c >= 32 && c <= 126);
}

int sfd_ispunct(const char c) {
    return (((c >= 33)  && (c <= 47)) ||
            ((c >= 58)  && (c <= 64)) ||
            ((c >= 91)  && (c <= 96)) ||
            ((c >= 123) && (c <= 126)));
}

int sfd_isspace(const char c) {
    return (c == ' ' || ((c >= 9) && (c <= 13)));
}

int sfd_isupper(const char c) {
    return (c >= 'A' && c <= 'Z');
}

char sfd_tolower(const char c) {
    return (isupper(c)) ? (c + 32) : c;
}

char sfd_toupper(const char c) {
    return (islower(c)) ? (c - 32) : c;
}
