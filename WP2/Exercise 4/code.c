//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 2
//Submission number:

#include <stdio.h>
#include <stdlib.h>

//main
int main(int argc, char *argv[]) 
{
    //to check if the arguments are exactly 5 values
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

    //ensure the user does not give more bits than the range specified for each name
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
    unsigned char byte;
    byte =  engine_on << 7 | gear_pos << 4 | key_pos << 2 | brake1 << 1 | brake2; 
            //engine_on: shifts left 7 positions (because it is the 8th bit)
            //gear_pos: shifts left 4 positions (because it is the 4th bit)
            //key_pos: shifts left 2 positions (because it is the 3rd bit)
            //brake1: shifts left 1 position (because it is the 2nd bit)
            //brake2: no shifting (because its the last bit)

    //convert byte to hexadecimal
    printf("%02x", byte);

    return 0;
}