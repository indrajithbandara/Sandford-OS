#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *input = fopen(argv[1], "r");
    if (input != NULL) {
        int count = 0;
        char curr = fgetc(input);
        while (curr != EOF) {
            if (curr == '\n')
                count++;
            curr = fgetc(input);
        }
        printf("%d\n", count);
    }
    return 0;
}
