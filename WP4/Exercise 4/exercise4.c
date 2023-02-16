#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int search_number(int number, int tab[], int size){
    int found;
    int i=0;
    for(i=0; i<size; i++){
        if(tab[i] == number){
            found = 1;
            break;
        }
    }
    if(found == 1){
        printf("%d is found at position %d", number, i);
        return 0;
    } else {
        printf("%d was not found in the array", number);
        return -1;
    }
}


void sort(int number, int tab[]){
    int x, y, temp;
    for(x = 0; x < number - 1; x++){
        for(y = 0; y < number - x - 1; y++){    
            if(tab[y] > tab[y + 1]){
                temp = tab[y];
                tab[y] = tab[y + 1];
                tab[y + 1] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for (int i = 0; i < number; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
}
int main(){
    int toSearch;
    int test[] = {1,2,34,5,67,3,23,12,13,10}; 
    int number = sizeof(test) / sizeof(test[0]);
    char choice;
    printf("What would you like to do: 1. search 2. sort \n");
    scanf(" %c", &choice);
    printf("------------------\n");
    if (choice == '1'){
        printf("Enter an element to search: ");
        scanf("%d", &toSearch);
        search_number(toSearch, test, sizeof(test));
    } else if(choice == '2'){
        sort(number, test);
    } else{
        printf("Error: Please enter 1 (for search) or 2 (for sort).");
    }
    return 0;
}