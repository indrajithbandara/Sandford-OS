/* ctype.c - This file is part of Project Sandford, a New Operating System.
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

int isalnum(const char);
int isalpha(const char);
int isdigit(const char);
int islower(const char);
int isprint(const char);
int ispunct(const char);
int isspace(const char);
int isupper(const char);

char tolower(const char);
char toupper(const char);


int isalnum(const char c) {
    return (isalpha(c) || isdigit(c));
}

int isalpha(const char c) {
    return (islower(c) || isupper(c));
}

int isdigit(const char c) {
    return (c >= '0' && c <= '9');
}

int islower(const char c) {
    return (c >= 'a' && c <= 'z');
}

int isprint(const char c) {
    return (c >= 32 && c <= 126);
}

int ispunct(const char c) {
    return (((c >= 33)  && (c <= 47)) ||
            ((c >= 58)  && (c <= 64)) ||
            ((c >= 91)  && (c <= 96)) ||
            ((c >= 123) && (c <= 126)));
}

int isspace(const char c) {
    return (c == ' ' || ((c >= 9) && (c <= 13)));
}

int isupper(const char c) {
    return (c >= 'A' && c <= 'Z');
}

char tolower(const char c) {
    return (isupper(c)) ? (c + 32) : c;
}

char toupper(const char c) {
    return (islower(c)) ? (c - 32) : c;
}
