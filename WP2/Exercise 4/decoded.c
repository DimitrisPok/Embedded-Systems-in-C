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

    //unpacks values
    int engine_on = (hex >> 7) & 1;
    int gear_pos = (hex >> 4) & 7;
    int key_pos = (hex >> 2) & 2;
    int brake1 = (hex >> 1) & 1;
    int brake2 = hex & 1;

    //prints values into the table
    printf("Name          Value     \n");
    printf("-----------------------\n");
    printf("engine_on   |   %d\n", engine_on);
    printf("gear_pos    |   %d\n", gear_pos);
    printf("key_pos     |   %d\n", key_pos);
    printf("brake1      |   %d\n", brake1);
    printf("brake2      |   %d\n", brake2);

}