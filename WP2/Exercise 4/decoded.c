//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 2
//Submission number: 0267702620

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


 //function that converts hexadecimal value to decimal
int hex2dec (char *hexadec){
    int decimal = 0;
    
    for (int i = 0; i < strlen(hexadec); i++){ //loops through the provided hexadecimal characters
    int dec = 0;                                //initialzing variable dec
    if (hexadec[i] >= '0' && hexadec[i] <= '9'){ //checks if the hexadec char is greater than or equal to zero or less than or equal to 9
        dec = hexadec[i] - '0';                  //compares to 0
    }
    else if (hexadec[i] >= 'A' && hexadec[i] <= 'F'){ //checks if the hexadec char is greater than or equal to A or less than or equal to F
        dec = hexadec[i] - 'A' + 10;                 // compares to A and adds 10
    }
                                                        //comparisions to lower case hexadecimal values
    else if (hexadec[i] >= 'a' && hexadec[i] <= 'f'){ //checks if the hexadec char is greater than or equal to a or less than or equal to f
        dec = hexadec[i] - 'a' + 10;                 //comares to a and adds 10
    }
                                                    //otherwise the hexadecimal is invalid and the program is existed
    else{ 
        printf("Error: please give a valid hexadecimal value!");
        return 1;
    }
    
    decimal += dec * pow(16, strlen(hexadec) - i - 1); //multiply the dec value retained from the above if statements and power to 16
    }

    return decimal;                                   //return the converted hexadecimal (ie. the decimal value)
}
//main
int main(int argc, char *argv[]) 
{
    //to check if the argument is exactly 1
    if(argc != 2){
        printf("Error: You need to give exactly 1 input, specifically a hexadecimal value!");
        return 1;
    }

    char* hexadec = argv[1]; //make the arguement equal to hexadec

    int decimal = hex2dec(hexadec); //use the hexadec variable to give as a parameter for the hex2dec function and call the function

    //takes byte and converts back to the correct values using bitwise operator (&) and (>>)
    int engine_on = (decimal & 128) >> 7; //compares to 128 because it is bit 7, shifts right 7 positions (because it is the 8th bit)
    int gear_pos = (decimal & 56) >> 4; //compares to 56 because it is bits 6-4, shifts right 4 positions (because it is the 4th bit)
    int key_pos = (decimal & 12) >> 2; //compares to 12 because it is bits 3-2, shifts right 2 positions (because it is the 3rd bit)
    int brake1 = (decimal & 2) >> 1; //compares to 2 because it is bit 1, shifts right 1 position (because it is the 2nd bit)
    int brake2 = (decimal & 1); //compares to 1 because it is bit 0, no shifting (because its the last bit)


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