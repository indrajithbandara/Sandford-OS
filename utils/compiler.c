#include <stdio.h>

int main(int argc, char *argv[]) {
    puts("Sandford Compiler");
    if (argv[1] != NULL && argv[2] != NULL) {
        puts("Reading Source File");
        FILE *input  = fopen(argv[1], "r");
        FILE *output = fopen(argv[2], "w");
    } else {
        puts("No Source File or No Output Name");
        return 1;
    }
    return 0;
}
