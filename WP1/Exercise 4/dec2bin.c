//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 1
//Submission number: 2763534813
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printbin(unsigned char val)
{
    for(unsigned char i = 0x80; i; i >>= 1)
        printf("%c", val & i ? '1' : '0');
    printf("\n");
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
    printbin(decimal);
    printf("\n");
    return 0;
}
