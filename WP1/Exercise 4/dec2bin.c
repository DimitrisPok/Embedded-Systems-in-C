//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 1
//Submission number: 2763534813
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toBinary(unsigned char val) {          //prints binary representation of an unsigned char var.
    for(unsigned char i = 0x80; i; i >>= 1) //for loop, i is set to 0x80 or 128, val is shifted right by 1.
        printf("%c", val & i ? '1' : '0');  //alternate if else, prints '1' or '0' depending on whether the bit is set.
        printf("\n");                       //prints an empty line.
}

int main(int argc, char *argv[]) {

    if (argc < 2) {                          //fail safe, if no arguments are given.
        printf("Error: Argument Count 0.\n");
        printf("How to?: ./dec2bin [decimal number]\n");
        return 2;
    }

    if (!strcmp(argv[1], "-h")) {            //prints help information for the program.
        printf("How to?: dec2bin [decimal number]\n");
        printf("What?: Converts a decimal number to binary.\n");
        return 0;
    }
    else {
        char *end;                                          //variable.
        unsigned long decimal = strtoul(argv[1], &end, 10); //string to unsigned long.

        if (*end) {                          //check if the value of 'end' is not a null pointer.
            printf("Error: Invalid input.\n");
            printf("Enter a decimal number\n");
            return 2;
        }

        toBinary(decimal);                  //uses declared and defined 'toBinary' function.
        printf("\n");                       //prints an empty line for better readability.
        return 0;                           //success code.
    }
}
