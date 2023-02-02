//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 2
//Submission number: 

#include <stdio.h>
#include <stdlib.h>

//main
int main(int argc, char *argv[]) 
{
    //to check if the argument is exactly 1
    if(argc != 2){
        printf("Error: You need to give 1 input, specifically a hexadecimal value!");
        return 1;
    }

    //scans the user's input and saves it to hex (unsigned char)
    unsigned char hex = 0;
    sscanf(argv[1], "%x", &hex);

    //unpacks values by...
    //unshifting all of the values (so cancels the left shifts by using right shifts) 
    //uses bitwise & operator to convert the hex back to binary
    int engine_on = (hex >> 7) & 1; //shifts right 7 positions (because it is the 8th bit) and compares to 1 (because it is 1 bit)
    int gear_pos = (hex >> 4) & 3; //shifts right 4 positions (because it is the 4th bit) and compares to 7 (because it is 3 bits)
    int key_pos = (hex >> 2) & 2; //shifts right 2 positions (because it is the 3rd bit) and compares to 2 (because it is 2 bits)
    int brake1 = (hex >> 1) & 1; //shifts right 1 position (because it is the 2nd bit) and compares to 1 (because it is 1 bit)
    int brake2 = hex & 1; //no shifting (because its the last bit) and compares to 1 (because it is 1 bit)

    //prints values into the table
    printf("Name          Value     \n");
    printf("-----------------------\n");
    printf("engine_on   |   %d\n", engine_on);
    printf("gear_pos    |   %d\n", gear_pos);
    printf("key_pos     |   %d\n", key_pos);
    printf("brake1      |   %d\n", brake1);
    printf("brake2      |   %d\n", brake2);

}