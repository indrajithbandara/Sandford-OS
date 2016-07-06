#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

static char game[] = "123456789";

int hasWon(const char c);
int validCell(const char c, const char c2);
void aiMove(int diff);
void drawGame(void);
void declareWinner(const int winner);

int main() {
    char c, diff;
    extern char game[];

    printf("Select Difficulty:\n\t1. ez game ez win\n\t2. hurt me plenty ;)\n");
    diff = (char)getchar();
    
    while (!hasWon('O')) {
        drawGame();
        while (!validCell(c = (char)getchar(), 'X'))
            ;
        if (!hasWon('X'))
            aiMove(diff);
        else
            declareWinner(0);
    }
    declareWinner(1);
    return 0;
}

int hasWon(const char c) {

    extern char game[];

    if ((game[4] == c) && (((game[3] == c) && (game[5] == c)) ||
                           ((game[0] == c) && (game[8] == c)) ||
                           ((game[2] == c) && (game[6] == c)) ||
                           ((game[1] == c) && (game[7] == c))))
        return 1;
    if ((game[0] == c) && (((game[3] == c) && (game[6] == c)) ||
                           ((game[1] == c) && (game[2] == c))))
        return 1;
    if ((game[8] == c) && (((game[6] == c) && (game[7] == c)) ||
                           ((game[2] == c) && (game[5] == c))))
        return 1;
    return 0;
}

int validCell(const char c, const char c2) {
    extern char game[];
    char c3 = c - '0';
    if (!isdigit(c) || c3 == 0 || !isdigit(game[c3 - 1]))
        return 0;
    game[c3 - 1] = c2;
    return 1;
}

void aiMove(int diff) {
    extern char game[];

    if (diff == '1') {
        char i = '1';
        while (!validCell(i++, 'O'))
            ;
    } else {
        /* super hard ai */
    }
}

void drawGame(void) {
    extern char game[];
    printf("\n%c|%c|%c\n%c|%c|%c\n%c|%c|%c\nChoose a Cell: ", game[0],
                                                              game[1],
                                                              game[2],
                                                              game[3],
                                                              game[4],
                                                              game[5],
                                                              game[6],
                                                              game[7],
                                                              game[8]);
}

void declareWinner(const int winner) {
    drawGame();
    if (winner)
        puts("Computer Wins!");
    else
        puts("Player Wins!");
    exit(0);
}
