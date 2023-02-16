//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 4
//Submission code: 8370587912
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//method to search for a number in the array
int search_number(int number, int tab[], int size){
    int found; //variable "found" to use for comparision
    int i=0; //index variable declaration
    for(i=0; i<size; i++){ //for loop through the array
        if(tab[i] == number){ //check if the number the user inputs is equal to the element in the array 
            found = 1; //then found = 1
            break; //and break
        }
    }
    if(found == 1){ //if found = 1 (ie. the element in the array is equal to the number the user inputs)
        printf("%d is found at position %d", number, i); //then print the number and its position in the array
        return 0; //and return 0
    } else { //otherwise..
        printf("%d was not found in the array", number); //print a message telling the user that the number was not in the array
        return -1; //and return -1
    }
}

//method to sort the array using bubble sort algorithm
void sort(int number, int tab[]){
    int x, y, temp; //variable declarations
    //loop through the array twice
    for(x = 0; x < number - 1; x++){ 
        for(y = 0; y < number - x - 1; y++){    
            if(tab[y] > tab[y + 1]){ //if the element is greater than the element after it
                //swap them by: 
                temp = tab[y]; //making "temp" equal to that element
                tab[y] = tab[y + 1]; //making the element equal the element after it
                tab[y + 1] = temp; //make that element equal to "temp"
            }
        }
    }
    //print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < number; i++){ //loop through the array
        printf("%d ", tab[i]); //and print each element
    }
    printf("\n"); //print a new line for aesthetics
}

//main function
int main(){
    //variable declarations 
    int toSearch; //user's input
    char choice; //user's choice
    int test[] = {1,2,34,5,67,3,23,12,13,10}; //array to test the methods
    int number = sizeof(test) / sizeof(test[0]); //size of the array
    
    printf("What would you like to do: 1. search 2. sort \n"); //ask the user if they want to search or sort the array
    scanf(" %c", &choice); //scan the user's input
    printf("------------------\n"); //print a line for a aesthetics
    if (choice == '1'){ //if the user gives 1 search for the number the user inputs
        printf("Enter an element to search: ");
        scanf("%d", &toSearch);
        search_number(toSearch, test, number);
    } else if(choice == '2'){ //if the user gives 2 sort the array
        sort(number, test);
    } else{ //error handling, if the user gives anything other than 1 or 2
        printf("Error: Please enter 1 (for search) or 2 (for sort).");
    }
    return 0; //return 0
}