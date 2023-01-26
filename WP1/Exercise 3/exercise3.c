//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 1
//Submission number: 2763534813
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randomNum;
    int input;
    char opinion;
    int numOfGuess = 0;
    srand(time(NULL));
    randomNum = rand() % 100;
    // Generate a random number
    do {
        printf("Would you like to start a round of the game? You have up to 10 tries. Type Y if you want to start a round or F if you want to exit the program: ");
        scanf("%c", &opinion);
        if (opinion == 'Y') {
            do {
                printf("Please give a guess between 1 and 100: ");
                scanf("%d", &input);
                if (input > randomNum) {
                    printf("Your guess is too high, please give another guess! You have %d attempts left :) \n", 9 - numOfGuess);
                    numOfGuess++;
                } else if (randomNum > input) {
                    printf("Your guess is too low, please give another guess! You have %d attempts left :) \n ", 9 - numOfGuess);
                    numOfGuess++;
                }
                else {
                    numOfGuess++;
                    printf("You have guessed %d times and your guess is correct!", numOfGuess);
                }
                if(input > 100 || input < 1){
                    printf("Out of bounds! Please give a number from 1-100\n");
                } 
                if (numOfGuess >= 10){
                    printf("Out of guesses, the correct number was %d \n", randomNum);
                }
            } while (input != randomNum);
        } else if (opinion == 'F') {
            return 0;
        }
    }while(1);
}