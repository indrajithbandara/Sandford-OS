#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argv[1] != NULL) {
        int n = atoi(argv[1]), i;
        for (i = 1; i <= n; i++)
            printf("%d\n", i);
        return 0;
    }
    return 1;
}
