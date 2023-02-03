//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 2
//Submission number: 0267702620

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//main
int main(int argc, char *argv[]) 
{
    const char hex[] = "0123456789ABCDEF"; //array of chars that could be in a hexadecimal
    unsigned char hexadec[2]; //hexadecimal input (up to two chars)
    int correctHex = 0; //variable to ease the validation of hexadecimal input

    //to check if the argument is exactly 1
    if(argc != 2){
        printf("Error: You need to give exactly 1 input, specifically a hexadecimal value!");
        return 1;
    }

    sscanf(argv[1], "%s", hexadec);

    
    for(int i = 0; i < strlen(hexadec); i++){ //loops through each char in the hexadec input
        for(int j = 0; j < strlen(hex); j++){ //loops through each char in the hex array
            if(hexadec[i]==hex[j]){          //checks if the hexadec is in the hex array
                correctHex = 1;
                break;
            }
        }
        //checks if the hexadec is valid, if not the program is exited
        if(!correctHex){
            printf("Error: please give a valid hexadecimal value!");
            return 1;
        }
    }

/*
    //scans the user's input and saves it to hex (unsigned char)
    unsigned char hex = 0;
    sscanf(argv[1], "%x", &hex);

    //converts the hexadecimal back to the correct values values using bitwise operator (&) and (>>)
    int engine_on = (hex >> 7) & 1; //shifts right 7 positions (because it is the 8th bit) and compares to 1 (because it is 1 bit)
    int gear_pos = (hex >> 4) & 3; //shifts right 4 positions (because it is the 4th bit) and compares to 7 (because it is 3 bits)
    int key_pos = (hex >> 2) & 2; //shifts right 2 positions (because it is the 3rd bit) and compares to 2 (because it is 2 bits)
    int brake1 = (hex >> 1) & 1; //shifts right 1 position (because it is the 2nd bit) and compares to 1 (because it is 1 bit)
    int brake2 = hex & 1;       //no shifting (because its the last bit) and compares to 1 (because it is 1 bit)
    
*/
   //The above is a program that also works however we are unsure which approach you expect us to have
    //uncomment the above to test out our first approach to this exercise


    //converts the hexadecimal value to decimal
     unsigned char byte = (unsigned char) strtol(hexadec, NULL, 16);

    //takes byte and converts back to the correct values using bitwise operator (&) and (>>)
    int engine_on = (byte & 128) >> 7; //compares to 128 because it is bit 7, shifts right 7 positions (because it is the 8th bit)
    int gear_pos = (byte & 56) >> 4; //compares to 56 because it is bits 6-4, shifts right 4 positions (because it is the 4th bit)
    int key_pos = (byte & 12) >> 2; //compares to 12 because it is bits 3-2, shifts right 2 positions (because it is the 3rd bit)
    int brake1 = (byte & 2) >> 1; //compares to 2 because it is bit 1, shifts right 1 position (because it is the 2nd bit)
    int brake2 = (byte & 1); //compares to 1 because it is bit 0, no shifting (because its the last bit)


    //prints error message if the user inputs a hexadecimal the converts to values not in the correct range
    if(engine_on < 0 || engine_on > 1 || 
    gear_pos < 0 || gear_pos > 4 || 
    key_pos < 0 || key_pos > 2 || 
    brake1 < 0 || brake1 > 1 || 
    brake2 < 0 || brake2 > 1)
    {
        printf("Error: the hexadecimal input is out of bounds!");
        return 1;
    }
    else {
    //prints values into the table
    printf("Name        |  Value     \n");
    printf("-----------------------\n");
    printf("engine_on   |   %d\n", engine_on);
    printf("gear_pos    |   %d\n", gear_pos);
    printf("key_pos     |   %d\n", key_pos);
    printf("brake1      |   %d\n", brake1);
    printf("brake2      |   %d\n", brake2);

    return 0;
    }
    
}