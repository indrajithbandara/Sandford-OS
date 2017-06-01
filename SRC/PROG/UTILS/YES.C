#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        int i;
        while (1)
            for (i = 1; i < argc; i++)
                printf("%s%s", argv[i], (i == argc - 1) ? "\n" : " ");
    } else
        while (1)
            puts("y");
    return 0;
}
