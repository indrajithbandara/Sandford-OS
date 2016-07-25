#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct tm origin = {.tm_mday = atoi(argv[1]), .tm_mon  = atoi(argv[2]) - 1, .tm_year = atoi(argv[3]) - 1900};
    printf("%d\n", (int)(difftime(time(NULL), mktime(&origin)) / 60 / 60 / 24));
    return 0;
}
