#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        int i, j;
        j = argc - 1;
        for (i = 1; i < j; i++) {
            fputs(argv[i], stdout);
            fputc(' ', stdout);
        }
        puts(argv[j]);
    }
    return 0;
}
