//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 0
//Submission code: 8986832838

#include <stdio.h>
#include <string.h>

//Main function in the program, no program arguments supported
int main(int argument, char* arg[]) {
   //exericise 1
   //print a string to the console
   printf("%s", "Hello World!\n");
   //exercise 3
   if (argument != 2 ){
    //print an error string if user gives no input or more than one
    printf("%s", "Error, type -h for more information!");
   } 
   //comparing the string to the argument with index 1
   else if (strcmp(arg[1], "-h")==0){
    //print a string if user gives input -h
    printf("%s", "Please give a valid argument");
   }
   else{
    //exercise 2
    //print a string with argument to the console
    printf("Hello World! - I'm %s!", arg[1]);
   }
   return 0;
}

