#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void copyString(char input[20]) // Method to copy the given string to another array
{
char stringToCpyTo[20] = input; // Copy the string
printf("%s", stringToCpyTo);    // Print it
}

int main(){
char stringToRead[20];          // Variable initialization
char stringCopy[20];

FILE *E6;
E6 = fopen("myfile.txt", "w"); // Create file and open it

printf(" \n Please type a string: \n");
scanf("%s", &stringToRead);     // Scan the string given by the user
copyString(stringToRead);       // Copy it using the method above
fprintf(E6,"%s", stringToRead); // Add the original string to the file

strcpy(stringToRead, stringCopy); // Copy using strcpy method

printf("The copied string is: ");
puts(stringCopy);                 // Print the copied string
    return 0;
}