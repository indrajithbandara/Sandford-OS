#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    if (f != NULL) {
        int count = 0;
        char curr = fgetc(f);
        while (curr != EOF) {
            if (curr == '\n')
                count++;
            curr = fgetc(f);
        }
        printf("%d\n", count);
        fclose(f);
    }
    return 0;
}
