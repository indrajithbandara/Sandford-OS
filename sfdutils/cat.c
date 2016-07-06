#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *f;
    int i = 1;
    for (; i < argc; i++) {
        f = fopen(argv[i], "r");
        int curr = fgetc(f);
        while(curr != EOF) {
            putchar(curr);
            curr = fgetc(f);
        }
        fclose(f);
    }
    return 0;
}
