#include <stdio.h>

int main(int argc, char *argv[]) {
    int i, c;
    for (i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        if (f) {
            while((c = fgetc(f)) != EOF)
                putchar(c);
            fclose(f);
        }
    }
    return 0;
}
