//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 1
//Submission number: 2763534813
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: No input provided.\n");
        printf("Usage: bin2hex [binary number]\n");
        return 2;
    }
    if (!strcmp(argv[1], "-h")) {
        printf("Usage: bin2hex [binary number]\n");
        printf("Converts a binary number to hexadecimal.\n");
        return 0;
    }
    size_t len = strlen(argv[1]);
    for (int i = 0; i < len; i++) {
        if (argv[1][i] != '0' && argv[1][i] != '1') {
            printf("Error: Invalid input.\n");
            printf("Usage: bin2hex [binary number]\n");
            return 2;
        }
    }
    unsigned long decimal = strtoul(argv[1], NULL, 2);
    printf("%lX\n", decimal);
    return 0;
}
