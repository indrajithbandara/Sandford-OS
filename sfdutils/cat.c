#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *input;
    int i = 1;
    for (; i < argc; i++) {
        f = fopen(argv[i], "r");
        char curr = fgetc(f);
        while(curr != EOF) {
            putchar(curr);
            curr = fgetc(input);
        }
        fclose(f);
    }
    return 0;
}
