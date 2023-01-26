//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 1
//Submission number: 2763534813
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //Initialise variables.
    int randomNum;
    int input;
    char opinion;
    int numOfGuess = 0;
    //Generate a random number with every iteration.
    srand(time(NULL));
    randomNum = rand() % 100;
    //Program execution.
    do {
        printf("Would you like to start a round of the game? You have up to 10 tries. Type Y if you want to start a round or F if you want to exit the program: ");
        scanf("%c", &opinion); //Reading the users input. 
        if (opinion == 'Y') {
            do {
                printf("Please give a guess between 1 and 100: ");
                scanf("%d", &input); //Reading the users guess.
                if (input > randomNum) { //If the guess of the user is higher than the correct number.
                    numOfGuess++;
                    printf("Your guess is too high, please give another guess! You have %d more attempts:) \n", 10 - numOfGuess);
                } else if (randomNum > input) { //If the guess of the user is lower tham the correct number.
                    numOfGuess++;
                    printf("Your guess is too low, please give another guess! You have %d more attempts:) \n ", 10 - numOfGuess);
                }
                else { //If the guess of the user is correct.
                    numOfGuess++;
                    printf("You have guessed %d times and your guess is correct!", numOfGuess);
                }
                if(input > 100 || input < 1){ //If the input of the user is out of bounds.
                    printf("Out of bounds! Please give a number from 1-100\n");
                } 
                if (numOfGuess >= 10){ //If the user runs out of guesses.
                    printf("Out of guesses, the correct number was %d \n", randomNum);
                }
            } while (input != randomNum);
        } else if (opinion == 'F') { //If the users presses F after the first round or at the very beggining, the program ends.
            return 0;
        }
    }while(1);
}