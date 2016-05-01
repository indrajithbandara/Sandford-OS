#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), i;
    for (i = 1; i <= n; i++)
        printf("%d\n", i);
    return 0;
}
