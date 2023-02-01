/*
So in the first program they just want you to store the five numbers in an unsigned char variable 
and then convert that and print it out as hecadecimal

In the second program you convert the hexadecimal back to those 5 values and fill the table with the values
To store the values in the unsigned char you should use bitwise operators
*/

#include <stdio.h>
#include <stdlib.h>

//typedef byte
//typedef unsigned char byte;

//main
int main(int argc, char *argv[]) 
{
    unsigned char byte;
    //to check if the user gave exactly 5 values or not
    if(argc != 6){
        printf("Error: You need to give 5 values!");
        return 1;
    }
    //convert arguments to integers for comparision and bitwise operation
    int engine_on = atoi(argv[1]);
    int gear_pos = atoi(argv[2]);
    int key_pos = atoi(argv[3]);
    int brake1 = atoi(argv[4]);
    int brake2 = atoi(argv[5]);

    //ensures the user does not give more bits than the range specified for each name
    if(engine_on < 0 || engine_on > 1 || 
    gear_pos < 0 || gear_pos > 4 || 
    key_pos < 0 || key_pos > 2 || 
    brake1 < 0 || brake1 > 1 || 
    brake2 < 0 || brake2 > 1)
    {
        printf("Error: too high value \nengine_on range from 0-1 bits \ngear_pos range from 0-4 bits \nkey_pos range from 0-2 bits \nbrake1 range from 0-1 bits \nbrake2 range from 0-1 bits ");
        return 1;
    }

    //pack values into byte (unsigned char)
    byte =  engine_on << 7 | gear_pos << 4 | key_pos << 2 | brake1 << 1 | brake2;

    //convert byte to hexadecimal
    printf("%02x", byte);

    return 0;
}