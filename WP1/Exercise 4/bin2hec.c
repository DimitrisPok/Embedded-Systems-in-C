//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 1
//Submission number: 2763534813
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char val[16];            
    
    if (argc < 2) {             //if arguemnts provided are less than 2 or null.
        scanf("%s", val);       //save in 'val' array from stdout.
    }
    else if (argc == 2) {            //arguments not null.
        sscanf(argv[1], "%s", val); //saves arg as string in array.
    }
    
    if (strcmp(val, "-h") == 0) {   //prints help information for the program.
        printf("Usage: bin2hex [binary number]\n");
        printf("Converts a binary number to hexadecimal.\n");
        return 0;
    }
    else {
        for (int i = 0; i < strlen(val); i++) {   //for loop, strlen() to determine length of string.
            if (val[i] != '0' && val[i] != '1') { //checks if every char is a '1' or '0'
                printf("Error: Invalid input.\n");
                printf("Usage: bin2hex [binary number]\n");
                return 2;
            }
        }
    }
    unsigned long decimal = strtoul(val, NULL, 2); //string to unsigned long with base 2.
    printf("%02X\n", decimal);                     //prints hexadecimal using %02X identifier.
    printf("\n");                                  //prints an empty line for better readability.
    return 0;                                      //success code.
}
