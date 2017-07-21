/* shell.c - This file is part of Project Sandford, a New Operating System.
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include "../sfdlibc/sfd_globals.h"

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

static int builtin(const int opt) {
    switch (opt) {
        case 0 :
            exit(0);
        case 1 :
            printf("Sandford Version: %s\n", SFD_VERSION);
    }
}

static int prompt() {
    char buffer[100];
    int c, i;
    i = 0;
    fflush(stdout);
    printf("\n%s$ %s", RED, CYAN);
    while ((c = getchar()) != '\n')
        buffer[i++] = c;
    printf("%s", GREEN);
    fflush(stdout);
    if (buffer[0] != NULL) {
        if (!strcmp(buffer, "exit"))
            builtin(0);
        else if (!strcmp(buffer, "version"))
            builtin(1);
        else {
            buffer[i] = '\0';
            char *argv[100];
            i = 1;
            argv[0] = strtok(buffer, " ");
            while ((argv[i++] = strtok(NULL, " ")))
                ;
            if (!fork()) {
                if (execvp(argv[0], argv))
                    puts("Command Not Found");
            } else
                wait(NULL);
        }
    }
    return 0;
}

int main() {
    printf("%s^____________________________________________________________________________^\n"
           "|============================================================================|\n"
           "|=============================={-WELCOME-TO-}================================|\n"
           "|============================================================================|\n"
           "||                                                                          ||\n"
           "||       mmmm  mmmmmm mmmm           mmmm  m    m mmmmmm m      m           ||\n"
           "||      m'   ' m      m   'm        m'   ' m    m m      m      m           ||\n"
           "||      'mmmm  'mmmmm m    m         'mmm. mmmmmm mmmmmm m      m           ||\n"
           "||          'm m      m    m             m m    m m      m      m           ||\n"
           "||      'mmmm' m      mmmm'         'mmmm' m    m mmmmmm mmmmmm mmmmmm      ||\n"
           "||                                                                          ||\n"
           "|============================================================================|\n"
           "|======================={-COMMAND-LINE-INTERPRETER-}=========================|\n"
           "|============================================================================|\n"
           "|____________________________________________________________________________|\n"
           "v                                                                            v\n\n", BLUE);
    while (1)
        prompt();
    puts("\nGoodbye");
    return 0;
}
