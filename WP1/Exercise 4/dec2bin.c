#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_binary(unsigned long decimal) {
    if (decimal == 0) {
        return;
    }
    print_binary(decimal >> 1);
    printf("%ld", decimal & 1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: No input provided.\n");
        printf("Usage: dec2bin [decimal number]\n");
        return 2;
    }
    if (!strcmp(argv[1], "-h")) {
        printf("Usage: dec2bin [decimal number]\n");
        printf("Converts a decimal number to binary.\n");
        return 0;
    }
    char *end;
    unsigned long decimal = strtoul(argv[1], &end, 10);
    if (*end) {
        printf("Error: Invalid input.\n");
        printf("Usage: dec2bin [decimal number]\n");
        return 2;
    }
    print_binary(decimal);
    printf("\n");
    return 0;
}
