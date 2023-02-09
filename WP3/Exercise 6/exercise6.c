//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 3
//Submission code: 8777169671
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//defining the max number of characters in the string array
#define MAX 20

//function to copy the given character array to another array
void copyString(char input[MAX], char stringToCpyTo[MAX]) 
{
    int i; 
    //iterate through each element in the given string while the string is ongoing
    for(i=0; input[i] != '\0'; i++){
        //make the copy of the string equal to the given string (ie. the user's input)
        stringToCpyTo[i] = input[i];
    }
    stringToCpyTo[i] = '\0';   //end of string character
}

//main function
int main(int argc, char *argv[]){
//variable declaration
char stringToRead[MAX + 1];   //user's input string
char stringCopy1[MAX + 1];    //copied string using copyString()
char stringCopy2[MAX + 1];   //copied string user strcpy()

//if 2 arguments are given (ie. the text file), since the user is not prompted to do anything
 if (argc == 2) { //argument 2 is the text file that the user inputs
        //reading from text file
        strncpy(stringToRead, argv[1], 20);
        stringToRead [MAX] = '\0';
    } else {
        //reading from keyboard
        printf(" \nPlease type a string: \n"); //ask the user to input a string
        printf("\n");
        fgets(stringToRead, 20, stdin);     //get the string from the user's input
        stringToRead[strcspn(stringToRead, "\r\n")] = 0; //ensure no empty lines are printed
    }
copyString(stringToRead, stringCopy1);  //copy the string using copyString()
strcpy(stringCopy2, stringToRead); //copy the string using strcopy()


printf("The copied string using copyString() is: %s \n", stringCopy1);    //print stringCopy1
printf("The copied string using strcpy() is: %s \n", stringCopy2);        //print stringCopy2

return 0;
}