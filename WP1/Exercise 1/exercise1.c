//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 1
//Submission number: 2763534813
#include <stdio.h>
// Exercise 1

int main() {
    //Initialising variables.
    int point = 1;
    int num;
    while(point==1) {
            printf("Please type a integer from 1 to 5: \n");
            scanf("%d", &num); //Reading user input.
                    if (num <= 5 || num >0) { //Reading user input.
                        if(num == 1){
                            printf("Oh wow you have typed number 1!! \n");}
                        else if (num ==2){
                            printf("I am pretty sure the number you chose is 2.\n");}
                        else if (num ==3) {
                            printf("This has to be number 3!\n");}
                        else if (num ==4){
                            printf("You chose option 4.\n");}
                        else if (num ==5){
                            printf("Five is one of my favourite numbers!\n");
                            
                    } else { //If the input doesnt match any of the gives options above.
                        printf("You did not give a integer from 1 to 5 as input." );
                        point = 0;
                        }
                    }
                }
                return 0;
            }
