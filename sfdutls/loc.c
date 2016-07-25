#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argv[1]) {
        FILE *f = fopen(argv[1], "r");
        if (f) {
            int c, cnt = 0;
            while ((c = fgetc(f)) != EOF)
                if (c == '\n')
                    cnt++;
            printf("%d\n", cnt);
            fclose(f);
            return 0;
        }
    }
    return -1;
}
